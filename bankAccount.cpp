#include <bits/stdc++.h>
using namespace std;

class bankAccount
{

private:
    static int nextaccountNo;

    int accountNo;
    string name;
    double balance;
    string password;
    vector<string> transHistory;

public:
    // constructor without name parameter
    bankAccount()
    {
        accountNo = nextaccountNo++;
        balance = 0;
    }

    // constructor with name parameter
    bankAccount(string name, string pass)
    {
        this->name = name;
        this->password = pass;
        accountNo = nextaccountNo++;
        balance = 0;
    }

    int getaccountNo()
    {
        return accountNo;
    }

    string getName()
    {
        return name;
    }

    double getBalance()
    {
        return balance;
    }

    // verify
    bool checkPassword(string password)
    {
        return this->password == password;
    }

    // functions

    void deposit(double amount)
    {
        this->balance = balance + amount;
        cout << "Deposited : " << amount << " Successfully" << endl;
        transHistory.push_back(("Deposited: Rs.") + to_string(amount));
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            this->balance = balance - amount;
            cout << "Withdrawn " << amount << " Successfully " << endl;
            transHistory.push_back("Withdrawn Rs." + to_string(amount));
        }
        else
        {
            cout << "Withdrawal Failed! Insufficient Balance!" << endl;
        }
    }

    void checkBalance()
    {
        cout << "Your Account Balance is Rs. " << balance << endl;
    }

    void getDetails()
    {
        cout << "--------All details--------- " << endl;
        cout << "Account Holder : " << name << endl;
        cout << "User No. " << accountNo << endl;
        cout << "Balance : " << balance << endl;
    }

    void showTransactions()
    {
        cout << "------All transactions by " << name << "------" << endl;
        for (auto i : transHistory)
        {
            cout << i << endl;
        }
    }
};
int bankAccount::nextaccountNo = 1;

int findAccountIndex(vector<bankAccount> &accounts, int accNo)
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getaccountNo() == accNo)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    vector<bankAccount> accounts;
    int choice;

    do
    {

        cout << "Choose Options Below :" << endl;

        cout << "1.Create Account\n";
        cout << "2.Deposit\n";
        cout << "3.withdraw\n";
        cout << "4.check Balance\n";
        cout << "5.Exit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            string name;
            string password;
            cout << "Enter account Holder's name : ";
            cin >> ws;          // clear white space
            getline(cin, name); // take whole line as input (no leading spaces or \n)
            cout << "Enter 4-digit password for Account : ";
            cin >> password;
            bankAccount newAcc(name, password); // created Object -> newAcc(with set name & password)
            accounts.push_back(newAcc);
            cout << "Account Created! Your Acc No. is : " << newAcc.getaccountNo() << endl
                 << endl;
        }
        else if (choice >= 2 && choice <= 4)
        {

            if (accounts.empty())
            {
                cout << "No accounts found! Please create an account first.\n"
                     << endl;
                continue;
            }

            int accNo;
            cout << "Enter account Number\n";
            cin >> accNo;
            int index = findAccountIndex(accounts, accNo);
            if (index == -1)
            {
                cout << "No Account Found ! ...Create New Account\n"
                     << endl;
                continue;
            }

            if (choice == 2)
            { // deposit
                cout << "Enter Deposit Amount : ";
                double amount;
                cin >> amount;
                accounts[index].deposit(amount);
                cout << endl;
            }
            else if (choice == 3)
            { // withdraw
                string password;
                cout << "Enter a Password : ";
                cin >> password;
                if (!accounts[index].checkPassword(password))
                {
                    cout << "Invalid Password" << endl;
                    continue;
                }

                cout << "Enter amount to Withdraw : ";
                double amount;
                cin >> amount;
                accounts[index].withdraw(amount);
                cout << endl;
            }
            else if (choice == 4)
            { // check balance
                string password;
                cout << "Enter a Password : ";
                cin >> password;
                if (!accounts[index].checkPassword(password))
                {
                    cout << "Invalid Password" << endl;
                    continue;
                }

                accounts[index].checkBalance();
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting...Thank You..." << endl
                 << endl;
        }
        else
        {
            cout << "Invalid choice! Try Again " << endl
                 << endl;
            continue;
        }

    } while (choice != 5);

    return 0;
}