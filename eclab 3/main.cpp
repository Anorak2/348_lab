#include "accounts.cpp";
using namespace std;

int main (){
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    cout << savings;
    cout << current;

    // Transfer 300 from savings to current
    current = current + savings;

    savings.displayDetails();
    current.displayDetails();

    return 0;
}
