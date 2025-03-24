#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    string accountHolderName, accountType;
    float balance;
    float *transaction;
    int transactionCount = 0;

public:
    Account(string n, int num, string type, float bal) : accountNumber(num), accountHolderName(n), accountType(type), balance(bal), transaction(nullptr), transactionCount(0) {}

    virtual ~Account() {
        delete[] transaction;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            float *temp = new float[transactionCount + 1];
            for (int i = 0; i < transactionCount; i++) {
                temp[i] = transaction[i];
            }
            temp[transactionCount] = amount;
            delete[] transaction;
            transaction = temp;
            transactionCount++;
            cout << "Deposited: " << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            float *temp = new float[transactionCount + 1];
            for (int i = 0; i < transactionCount; i++) {
                temp[i] = transaction[i];
            }
            temp[transactionCount] = -amount;
            delete[] transaction;
            transaction = temp;
            transactionCount++;
            cout << "Withdrawn: " << amount << "\nRemaining balance: " << balance << "\n";
        } else {
            cout << "Invalid or insufficient funds.\n";
        }
    }

    void getAccountInfo() {
        cout << "account number: " << accountNumber << "\nholders name: " << accountHolderName << "\naccount type: " << accountType << "\nBalance: " << balance << "\n";
    }

    void printStatement() {
        cout << "transaction history for account " << accountNumber << ":\n";
        for (int i = 0; i < transactionCount; i++) {
            if (transaction[i] > 0) {
                cout << "deposit: "<< +transaction[i] << "\n";
            } else {
                cout << "withdrawal: " << -transaction[i] << "\n";
            }
        }
    }

    virtual float calculateInterest() {
        return 0.1f * balance;
    }
};

class SavingsAccount : public Account {
    float interestRate;
    float minimumBalance;

public:
    SavingsAccount(string n, int num, float bal, float ir, float mb)
        : Account(n, num, "Savings", bal), interestRate(ir), minimumBalance(mb) {}

    float calculateInterest() override {
        if (balance >= minimumBalance) {
            return interestRate * balance;
        }
        return 0;
    }

    void withdraw(float amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw minimum balance required\n";
        }
    }
};
class CheckingAccount : public Account {
public:
    CheckingAccount(string n, int num, float bal) : Account(n, num, "Checking", bal) {}

    float calculateInterest() override {
        return 0.0f;
    }
};
class FixedDepositAccount : public Account {
    float fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(string n, int num, float bal, float ir, int md)
        : Account(n, num, "Fixed Deposit", bal), fixedInterestRate(ir), maturityDate(md) {}

    float calculateInterest() override {
        return fixedInterestRate * balance;
    }
    void withdraw(float amount) override {
        cout << "Cant withdraw from fixed deposit before maturity\n";
    }
};
int main() {
    SavingsAccount s("hamza", 12345, 5000.0, 0.05, 1000.0f);
    CheckingAccount c("zaid", 67890, 3000.0);
    FixedDepositAccount f("rayyan", 11111, 10000.0, 0.07, 12);

    cout << "\nSavings Account\n";
    s.getAccountInfo();
    s.deposit(2000);
    s.withdraw(4000);
    cout << "Interest: " << s.calculateInterest() << "\n";
    s.getAccountInfo();
    s.printStatement();

    cout << "\nChecking Account\n";
    c.getAccountInfo();
    c.deposit(1000);
    c.withdraw(500);
    cout << "Interest: " << c.calculateInterest() << "\n";
    c.printStatement();

    cout << "\nFixed Deposit Account\n";
    f.getAccountInfo();
    cout << "Interest: " << f.calculateInterest() << "\n";
    f.withdraw(1000);
    f.printStatement();

}
