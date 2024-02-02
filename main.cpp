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
        string s;
        cin >> s;
        if (isValidInteger(s) == false)
        {
            cout << "Invalid Input\n";
            continue;
        }
        option = stoi(s);
        cout << endl;
        // system("cls");

        if (option >= 1 and option <= 8)
        {
            if (option == 1)
            {
                // Create a new account
                pair<infoAccountUser, int> obj = printNewAccount_Details();

                if (obj.second == -1)
                {
                    system("cls");
                    cout << "\nAccount Creation Terminated!\n";
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
                system("cls");
                displayUsers();
            }
            else if (option == 3)
            {
                // Update an account
                system("cls");
                updateInfo();
            }
            else if (option == 4)
            {
                // Delete an account
                system("cls");
                deleteUser();
            }
            else if (option == 5)
            {
                // Deposit an amount into your account
                system("cls");
                addMoney();
            }
            else if (option == 6)
            {
                // Withdraw an amount from your account
                system("cls");
                withDraw();
            }
            else if (option == 7)
            {
                // Search for account
                system("cls");
                searchAccount();
            }
            else
            {
                break;
            }
        }
        else
        {
            system("cls");
            cout << "Invalid Action Choice, Try Again!\n";
        }
    }
}
