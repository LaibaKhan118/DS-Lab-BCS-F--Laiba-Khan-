/*Suppose you are developing a bank account management system, and you have defined the BankAccount class with the required constructors.
You need to demonstrate the use of these constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new BankAccount object named account3 using the copy constructor. Deduct $200 from account3 and print out its balance.
Also, print out the balance of account2 to ensure it hasn't been affected by the transaction involving account3.*/

#include <iostream>
using namespace std;

class BankAccount{
private:
    double accBalance;

public:
    BankAccount():accBalance(0.0) { cout << "New account created with default constructor." << endl; }
    BankAccount(double b) : accBalance(b) { cout << "New account created with parameterized constructor." << endl; }
    BankAccount(const BankAccount &ba){
        accBalance = ba.accBalance;
        cout << "New account created with copy constructor." << endl;}

    void deduct(double am){
        if (am <= accBalance){
            accBalance = accBalance - am;
            cout << "An ammount of $" << am << " has been deducted.\nNew balance is: " << accBalance << endl;
        }else{
            cout << "Insufficient Balance." << endl;
        }
    }

    void printBalance(){
        cout << "Balance is: " << accBalance << endl;
    }
};

int main()
{
    BankAccount account1;
    cout << "Account 1: ";
    account1.printBalance();

    BankAccount account2(1000);
    cout << "Account 2: ";
    account2.printBalance();

    BankAccount account3(account2);
    cout << "Account 3: ";
    account3.printBalance();
    account3.deduct(200);

    cout << "Account 2: ";
    account2.printBalance();
    return 0;
}
