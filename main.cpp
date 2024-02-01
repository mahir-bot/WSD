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
                }
            }
            else if (choice == 2)
            {
                // Display all accounts
                displayUsers();
            }
            else if (choice == 3)
            {
                // Update an account
                updateInfo();
            }
            else if (choice == 4)
            {
                // Delete an account
                deleteUser();
            }
            else if (choice == 5)
            {
                // Deposit an amount into your account
                addMoney();
            }
            else if (choice == 6)
            {
                // Withdraw an amount from your account
                withDraw();
            }
            else if (choice == 7)
            {
                // Search for account
                searchAccount();
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
