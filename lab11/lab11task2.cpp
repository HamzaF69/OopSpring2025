#include <iostream>
#include <exception>
using namespace std;
class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template<typename T>
class Stack {
private:
    T* data;
    int top;
    int capacity;

public:
    Stack(int size) : capacity(size), top(-1) {
        data = new T[capacity];
    }
    ~Stack() {
        delete[] data;
    }
    void push(T value) {
        if (top >= capacity - 1) {
            throw StackOverflowException();
        }
        data[++top] = value;
    }
    T pop() {
        if (top < 0) {
            throw StackUnderflowException();
        }
        return data[top--];
    }
};
int main() {
    Stack<int> stack(3);
    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40); 
    }
    catch (const StackOverflowException& e) {
        cout << "Pushing to a full stack: " << e.what() << endl;
    }
    try {
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
    }
    catch (const StackUnderflowException& e) {
        cout << "Popping from an empty stack: " << e.what() << endl;
    }
    return 0;
}
