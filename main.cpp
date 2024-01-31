#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stack>
#include <unordered_map>
using namespace std;
void printChoices();
void printNewAccount_Details();

class acountProfile
{
private:
    struct Address
    {
        string city, country, house, road, area;
        int zipCode;
    };
    struct Transaction
    {
        string type;
        double amount;
        time_t timestamp;
    };
    string name;
    string number;
    string nid;
    string creationDate;
    string accountType;

    int year, month, day;
    long long int accountId;
    double balance = 0.0;
    stack<Transaction> history;
    Address location;

public:
    void setName(const string &Identity);
    void setNumber(const string &Contact);
    void setNID(const string &Citizen);
    void setCreationDate();
    void setAccountType(const string &Type);
    void setYear(const int &Annum);
    void setMonth(const int &MoonCycle);
    void setDay(const int &SunUpToSundown);
    void setAccountId();
    void setLocation(const string &Town, const string &Nation, const string &Residence,
                     const string &Street, const string &Region, int &Postcode);
    void setDeposit(int &Add);
    void setWithdrawal(int &Subtract);
};

signed main()
{
    while (true)
    {
        printChoices();
        int choice;
        cin >> choice;
        if (choice >= 1 and choice <= 8)
        {
            if (choice == 1)
            {
                // Create a new account
                printNewAccount_Details();
            }
            else if (choice == 2)
            {
                // Display all accounts
            }
            else if (choice == 3)
            {
                // Update an account
            }
            else if (choice == 4)
            {
                // Delete an account
            }
            else if (choice == 5)
            {
                // Deposit an amount into your account
            }
            else if (choice == 6)
            {
                // Withdraw an amount from your account
            }
            else if (choice == 7)
            {
                // Search for account
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "Invalid Action Choice, Try Again!\n";
        }
    }
}

void printNewAccount_Details()
{
}

void printChoices()
{

    cout << "1. Create a new account\n"
         << "2. Display all accounts\n"
         << "3. Update an account\n"
         << "4. Delete an account\n"
         << "5. Deposit an amount into your account\n"
         << "6. Withdraw an amount from your account\n"
         << "7. Search for account\n"
         << "8. Exit\n"
         << "Choose Your Action ->>";
}