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
        int option;
        cin >> option;
       
        if (option >= 1 and option <= 8)
        {
            if (option == 1)
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
            else if (option == 2)
            {
                // Display all accounts
                displayUsers();
            }
            else if (option == 3)
            {
                // Update an account
                updateInfo();
            }
            else if (option == 4)
            {
                // Delete an account
                deleteUser();
            }
            else if (option == 5)
            {
                // Deposit an amount into your account
                addMoney();
            }
            else if (option == 6)
            {
                // Withdraw an amount from your account
                withDraw();
            }
            else if (option == 7)
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
