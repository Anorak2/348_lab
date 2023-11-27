#include <iostream>
#include <string.h>
using namespace std;

class Account {
protected:
    char accountNumber[6]{};
    char accountHolder[50]{};
    virtual void details(){
        cout << "Holder: " << accountHolder << endl;
        cout << "Balance: $" <<  balance << endl;
    }
public:
    double balance{};
    Account()= default;
    Account(char acc[6], char hold[50], double bal){
        strcpy(accountNumber, acc);
        strcpy(accountHolder, hold);
        balance = bal;
    }
    void deposit(double amt){
        balance += amt;
    }
    void withdraw(double amt){
        balance -= amt;
    }
};

class SavingsAccount : public Account{
private:
    double interestRate;
public:
    SavingsAccount()=default;
    SavingsAccount(char acc[6], char hold[50], double bal, double inter) : Account(acc, hold, bal){
        interestRate = inter;
    }
    void displayDetails(){
        cout << "Account Details for Savings Account (ID: " << accountNumber << "):" << endl;
        details();
        cout << "Interest Rate: " <<  interestRate*100 << "%" << endl << endl;
    }
    SavingsAccount operator+(Account obj){
        SavingsAccount res;
        strcpy(res.accountNumber, accountNumber);
        strcpy(res.accountHolder, accountHolder);
        res.balance = balance + 300;
        obj.withdraw(300);
        res.interestRate = interestRate;
        return res;
    };
    friend std::ostream& operator<<(std::ostream& os, SavingsAccount& obj){
        obj.displayDetails();
        return os;
    }
};

class CurrentAccount : public Account{
private:
    double overdraftlimit{};
public:
    CurrentAccount()=default;
    CurrentAccount(char acc[6], char hold[50], double bal, double draftLimit) : Account(acc, hold, bal) {
        overdraftlimit = draftLimit;
    };
    void displayDetails(){
        cout << "Account Details for Savings Account (ID: " << accountNumber << "):" << endl;
        details();
        cout << "Overdraft Limit: $" <<  overdraftlimit << endl << endl;
    };
    CurrentAccount operator+(Account& obj){
        CurrentAccount res;
        strcpy(res.accountNumber, accountNumber);
        strcpy(res.accountHolder, accountHolder);
        res.balance = balance + 300;
        obj.withdraw(300);
        res.overdraftlimit = overdraftlimit;
        return res;
    };
    friend std::ostream& operator<<(std::ostream& os, CurrentAccount& obj){
        obj.displayDetails();
        return os;
    }
};