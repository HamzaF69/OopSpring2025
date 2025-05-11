#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
using namespace std;

class FileException:public exception{
    protected:
    string message;
    public:
    FileException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class PermissionDeniedException:public FileException{
    public:
    PermissionDeniedException(string file):FileException("PermissionDeniedException - "+ file){}
   
};

class FileNotFoundException:public FileException{
    public:
    FileNotFoundException(string file):FileException("FileNotFoundException - "+file){}

};

void readFile(string f){
    if (f=="confidential.txt"){
        throw PermissionDeniedException(f);
    } else if(f=="notfound.txt"){
        throw FileNotFoundException(f);
    } else{
        cout<<"reading "<<f<<"\n";
    }
}

int main (){
    string file="confidential.txt";
    try {
        readFile(file);
    }
    catch (PermissionDeniedException e){
        cout<<"error: "<<e.what()<<endl; 
    }
    catch(FileNotFoundException e){
        cout<<"error: "<<e.what()<<endl;
    }
    catch(FileException e){
        cout<<e.what()<<endl;
    }
}

