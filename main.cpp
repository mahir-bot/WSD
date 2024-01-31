#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include "accountProfile.hpp"
#include "printFunction.hpp"
using namespace std;
unordered_map<long long int, accountProfile> allAccounts;


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
