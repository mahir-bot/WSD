#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <stack>
#include <utility>
#include <unordered_map>
#include "accountTemplate.hpp"
#include "printFunction.hpp"
#include "newAccountFunction.hpp"
#include "dataStore.hpp"
#include "oparations.hpp"

using namespace std;

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
                pair<infoAccountUser, int> obj = printNewAccount_Details();

                if (obj.second == -1)
                {
                    continue;
                }
                else
                {
                    if (obj.second == 1)
                        updateInfoUnsaved(obj.first);

                    saveInfo(obj.first);
                    accountProfile temp;
                    temp.setName(obj.first.name);
                    temp.setID(obj.first.id);
                    if (obj.first.type == 1)
                        temp.setAccountType("Current Account");
                    else if (obj.first.type == 2)
                        temp.setAccountType("Saving Account");
                    else if (obj.first.type == 3)
                        temp.setAccountType("Salary Account");
                    else
                        temp.setAccountType("Student Account");

                    long long int accountID = temp.getAccountId();
                }
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
