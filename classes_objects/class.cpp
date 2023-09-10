// Creating and manipulating an Account object

#include <iostream>
#include <string>

using namespace std;

class Account
{
public:
    Account(string name, int initial_amount = 0) : account_owner{name}
    {
        if (initial_amount > 0)
            balance = initial_amount;
    };

    void deposit(int deposit)
    {
        if (deposit > 0)
        {
            balance += deposit;
        }
    }

    int getBalance()
    {
        return balance;
    }
    void setName(string name = "John Doe")
    {
        account_owner = name;
    }
    string getName() const { return account_owner; }

private:
    string account_owner;
    int balance;
};

// class Account
// {
// public:
//     explicit Account(string accountName = "John Doe")
//     {
//         name = accountName; // set the initial name
//     };

//     void setName(string accountName)
//     {
//         name = accountName;
//     };

//     string getName() const
//     {
//         return name;
//     };

// private:
//     string name;
// };

int main()
{
    //     Account myAccount(""); // create Account object myAccount
    //     cout << "initial acoount name is " << myAccount.getName() << endl;
    //     cout << "\nPlease enter the account name ";
    //     string theName;
    //     getline(cin, theName);
    //     myAccount.setName(theName);
    //     cout << "Name in object myAccount is: " << myAccount.getName() << endl;

    string theName;
    int deposit;
    char condition;
    cout << "Please enter the account name: ";
    getline(cin, theName);
    Account myAccount(theName);

    cout << "Do you want to make a deposit? y->Yes, n->No: ";
    condition = getchar();
    if (condition == 'y')
    {
        cout
            << "Make your your first deposit please: ";
        cin >> deposit;
        myAccount.deposit(deposit);
    };

    cout << "Account created successfully: \nYou details is: " << endl;
    cout << "Account name: "
         << myAccount.getName();
    cout << "\nBalance is: "
         << myAccount.getBalance() << endl;

    return 0;
}