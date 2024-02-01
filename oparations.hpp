#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <stack>
#include <unordered_map>
// #include "dataStore.hpp"
// #include "accountProfile.hpp"

void updateInfoUnsaved(infoAccountUser &user)
{
    int needToChange = -1;
    bool out = false;
    while (true)
    {
        printInfoUnsaved();
        int it;
        cin >> it;
        cout << "If you want to quit Press -1\n";
        if (it == 1)
        {
            cout << "Enter Name: ";
            cin >> user.name;
            cout << endl;
            if (user.name == "-1")
            {
                break;
            }
            if (user.name.size() == 0)
            {
                cout << "Please Provide a Valid Name\n";
            }
        }
        else if (it == 2)
        {
            cout << "Enter Contact Number(+880): ";
            cin >> user.number;
            cout << endl;
            if (user.number == "-1")
            {
                break;
            }
            if (user.number.size() != 10)
            {
                cout << "Please Provide a Valid Phone number of 10 Digits\n";
            }
        }
        else if (it == 3)
        {
            cout << "\nEnter Account Type\n";
            cout << "1.Current Account \t 2.Saving Account \t 3.Salary Account \t 4.Student Account\n";
            cout << "Account Type Id no: ";
            cin >> user.type;
            cout << endl;
            if (user.type == -1)
            {
                break;
            }
            if (user.type < 0 or user.type > 4)
            {
                cout << "Please Provide Type Of Account in the range of [1,4]\n";
            }
        }
        else if (it == 4)
        {
            cout << "\nEnter Account ID Type\n";
            cout << "1.Enter NID/Driver Licence \t 2.Student ID(Age Under 18)";
            cout << "\n ID type: ";
            cin >> user.idType;
            cout << endl;
            if (user.type == -1)
            {
                break;
            }
            if (user.idType < 1 and user.idType > 2)
            {
                cout << "Please Provide a valid ID Type\n";
            }
        }
        else if (it == 5)
        {
            cout << "ID: ";
            cin >> user.id;
            cout << endl;
            if (user.id == "-1")
            {
                break;
            }
            if (user.id.empty())
            {
                cout << "Please Provide a valid ID\n";
            }
        }
        else if (it == 6)
        {
            cout << "House No: ";
            cin >> user.house;
            cout << endl;
            if (user.house == "-1")
            {
                break;
            }
            if (user.house.empty())
            {
                cout << "Please Provide Valid House Number\n";
            }
        }
        else if (it == 7)
        {
            cout << "Road No: ";
            cin >> user.road;
            cout << endl;
            if (user.road == "-1")
            {
                break;
            }
            if (user.road.empty())
            {
                cout << "Please Provide Valid Road Number\n";
            }
        }
        else if (it == 8)
        {
            cout << "Area: ";
            cin >> user.area;
            cout << endl;
            if (user.area == "-1")
            {
                break;
            }
            if (user.area.empty())
            {
                cout << "Please Provide Valid Area\n";
            }
        }
        else if (it == 9)
        {
            cout << "City: ";
            cin >> user.city;
            cout << endl;
            if (user.city == "-1")
            {
                break;
            }
            if (user.city.empty())
            {
                cout << "Please Provide Valid City\n";
            }
        }
        else if (it == 10)
        {
            cout << "Country: ";
            cin >> user.country;
            cout << endl;
            if (user.country == "-1")
            {
                break;
            }
            if (user.country.empty())
            {
                cout << "Please Provide Valid Country\n";
            }
        }
        else if (it == 11)
        {
            cout << "Zip Code: ";
            cin >> user.zip;
            cout << endl;
            if (user.zip == "-1")
            {
                break;
            }
            if (user.zip.empty())
            {
                cout << "Please Provide Valid Zip Code\n";
            }
        }
        else if (it == 12)
        {
            cout << "Year: ";
            cin >> user.year;
            cout << endl;
            if (user.year == -1)
            {
                break;
            }
            if (user.year < 1900)
            {
                cout << "Year Must Be greater Then 1900\n";
            }
        }
        else if (it == 13)
        {
            cout << "Month: ";
            cout << user.month;
            cout << endl;
            if (user.month == -1)
            {
                break;
            }
            if (user.month < 1 || user.month > 12)
            {
                cout << "Month must be in between 1-12\n";
            }
        }
        else if (it == 14)
        {
            cout << "Day: ";
            cout << user.day;
            cout << endl;
            if (user.day == -1)
            {
                break;
            }
            if (user.month > 0 and user.month < 13)
            {
                int daysInMonth[] = {31, 28 + ((user.year % 4 == 0 && user.year % 100 != 0) || (user.year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                if (user.day < 1 || user.day > daysInMonth[user.month - 1])
                {
                    cout << "Make sure you provide valid Year and Month beforehand and provide valid day between 1-31 days based on month\n";
                }
            }
            else
            {
                cout << "First Provide Month and Year!";
            }
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        vector<pair<int, string>> tag = userInfoCheck(user);

        if (tag.empty())
        {
            cout << "All Done, Congratulations!" << endl;

            while (true)
            {
                cout << "Would You Like To Change Any Information?\n1.Yes \t 2.No" << endl;
                int x;
                cin >> x;
                if (x == 1)
                {
                    needToChange = 1;
                    break;
                }
                else if (x == 2)
                {
                    cout << "Thank You!!!" << endl;
                    break;
                }
                else
                {
                    cout << "Invalid Option, Try again ->[1,2]" << endl;
                }
            }

            break;
        }

        for (auto &it : tag)
        {
            cout << "If you want to quit creating account Press -1\n";
            if (it.first == 1)
            {
                cout << it.second << endl;
                cout << "Enter Name: ";
                cin >> user.name;
                cout << endl;
                if (user.name == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 2)
            {
                cout << it.second << endl;
                cout << "Enter Contact Number(+880): ";
                cin >> user.number;
                cout << endl;
                if (user.number == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 3)
            {
                cout << it.second << endl;
                cout << "ID: ";
                cin >> user.id;
                cout << endl;
                if (user.id == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 4)
            {
                cout << it.second << endl;
                cout << "\nEnter Account Type\n";
                cout << "1.Current Account \t 2.Saving Account \t 3.Salary Account \t 4.Student Account\n";
                cout << "Account Type Id no: ";
                cin >> user.type;
                cout << endl;
                if (user.type == -1)
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 5)
            {
                cout << it.second << endl;
                cout << "House No: ";
                cin >> user.house;
                cout << endl;
                if (user.house == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 6)
            {
                cout << it.second << endl;
                cout << "Road No: ";
                cin >> user.road;
                cout << endl;
                if (user.road == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 7)
            {
                cout << it.second << endl;
                cout << "Area: ";
                cin >> user.area;
                cout << endl;
                if (user.area == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 8)
            {
                cout << it.second << endl;
                cout << "City: ";
                cin >> user.city;
                cout << endl;
                if (user.city == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 9)
            {
                cout << it.second << endl;
                cout << "Country: ";
                cin >> user.country;
                cout << endl;
                if (user.country == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 10)
            {
                cout << it.second << endl;
                cout << "Zip Code: ";
                cin >> user.zip;
                cout << endl;
                if (user.zip == "-1")
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 11)
            {
                cout << it.second << endl;
                cout << "Year: ";
                cin >> user.year;
                cout << endl;
                if (user.year == -1)
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 12)
            {
                cout << it.second << endl;
                cout << "Month: ";
                cout << user.month;
                cout << endl;
                if (user.month == -1)
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else if (it.first == 13)
            {
                cout << it.second << endl;
                cout << "Day: ";
                cout << user.day;
                cout << endl;
                if (user.day == -1)
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
            else
            {
                cout << it.second << endl;
                cout << "Enter Account Type\n";
                cout << "1.Enter NID/Driver Licence \t 2.Student ID(Age Under 18)";
                cout << "\n ID type: ";
                cin >> user.idType;
                cout << endl;
                if (user.idType == -1)
                {
                    user = infoAccountUser{};
                    out = true;
                    break;
                }
            }
        }
    }

    if (out)
    {
        return;
    }
}

void updateInfo()
{
    cout << "Enter User Account Number: ";
    long long int id;
    cin >> id;
    accountProfile obj;
    if (allAccounts.find(id) != allAccounts.end())
    {
        obj = allAccounts[id];
    }
    else
    {
        cout << "No Such Account Found!" << endl;
        return;
    }
    infoAccountUser user;
    while (true)
    {

        printUpdateChoices();
        int it;
        cin >> it;
        cout << "If you want to quit Press -1\n";
        if (it == 1)
        {
            cout << "Enter Contact Number(+880): ";
            cin >> user.number;
            cout << endl;
            if (user.number == "-1")
            {
                return;
            }
            if (user.number.size() != 10)
            {
                cout << "Please Provide a Valid Phone number of 10 Digits\n";
            }
            else
            {
                obj.setNumber(user.number);
            }
        }
        else if (it == 2)
        {
            cout << "House No: ";
            cin >> user.house;
            cout << endl;
            if (user.house == "-1")
            {
                return;
            }
            if (user.house.empty())
            {
                cout << "Please Provide Valid House Number\n";
                continue;
            }

            cout << "Road No: ";
            cin >> user.road;
            cout << endl;
            if (user.road == "-1")
            {
                return;
            }
            if (user.road.empty())
            {
                cout << "Please Provide Valid Road Number\n";
                continue;
            }

            cout << "Area: ";
            cin >> user.area;
            cout << endl;
            if (user.area == "-1")
            {
                return;
            }
            if (user.area.empty())
            {
                cout << "Please Provide Valid Area\n";
                continue;
            }

            cout << "City: ";
            cin >> user.city;
            cout << endl;
            if (user.city == "-1")
            {
                return;
            }
            if (user.city.empty())
            {
                cout << "Please Provide Valid City\n";
                continue;
            }

            cout << "Country: ";
            cin >> user.country;
            cout << endl;
            if (user.country == "-1")
            {
                return;
            }
            if (user.country.empty())
            {
                cout << "Please Provide Valid Country\n";
                continue;
            }

            cout << "Zip Code: ";
            cin >> user.zip;
            cout << endl;
            if (user.zip == "-1")
            {
                return;
            }
            if (user.zip.empty() == false)
            {
                cout << "Please Provide Valid Zip Code\n";
                continue;
            }
            obj.setLocation(user.area, user.country, user.house, user.road, user.city, user.zip);
        }
        else if (it == 3)
        {
            cout << "Year: ";
            cin >> user.year;
            cout << endl;
            if (user.year == -1)
            {
                return;
            }
            if (user.year < 1900)
            {
                cout << "Year Must Be greater Then 1900\n";
                continue;
            }

            cout << "Month: ";
            cin >> user.month;
            cout << endl;
            if (user.month == -1)
            {
                return;
            }
            if (user.month < 1 || user.month > 12)
            {
                cout << "Month must be in between 1-12\n";
                continue;
            }

            cout << "Day: ";
            cin >> user.day;
            cout << endl;
            if (user.day == -1)
            {
                return;
            }
            int daysInMonth[] = {31, 28 + ((user.year % 4 == 0 && user.year % 100 != 0) || (user.year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (user.day < 1 || user.day > daysInMonth[user.month - 1])
            {
                cout << "Make sure you provide valid Year and Month beforehand and provide valid day between 1-31 days based on month\n";
                continue;
            }

            obj.setDay(user.day);
            obj.setMonth(user.month);
            obj.setYear(user.year);
        }
        else if (it == 4)
        {
            break;
        }
    }

    allAccounts[id] = obj;
    return;
}

void displayUsers()
{
    if (allAccounts.empty())
    {
        cout << "No Account!\n";
        return;
    }
    for (auto &entry : allAccounts)
    {
        cout << "Account ID: " << entry.first << endl;
        cout << "Name: " << entry.second.getName() << endl;
        cout << "Contact Number: " << entry.second.getNumber() << endl;
        cout << "ID: " << entry.second.getID() << endl;
        cout << "Creation Date: " << entry.second.getCreationDate() << endl;
        cout << "Account Type: " << entry.second.getAccountType() << endl;
        cout << "Birth Date: " << entry.second.getBirthTime() << endl;
        cout << "Balance: " << entry.second.getBalance() << endl;
    }
}

void deleteUser()
{
    cout << "Enter User Account Number: ";
    long long int id;
    cin >> id;
    if (allAccounts.find(id) != allAccounts.end())
    {
        allAccounts.erase(id);
        cout << "Erased Successfully!\n";
    }
    else
    {
        cout << "No Such Account Found!" << endl;
    }
}

void addMoney()
{
    cout << "Enter User Account Number: ";
    long long int id;
    cin >> id;
    if (allAccounts.find(id) != allAccounts.end())
    {
        double money;
        cout << "Enter Amount: ";
        cin >> money;
        allAccounts[id].setDeposit(money);
        cout << "Deposit Successfully!\n";
    }
    else
    {
        cout << "No Such Account Found!" << endl;
    }
}

void withDraw()
{
    cout << "Enter User Account Number: ";
    long long int id;
    cin >> id;
    if (allAccounts.find(id) != allAccounts.end())
    {
        double money;
        cout << "Enter Amount: ";
        cin >> money;
        double save = allAccounts[id].getBalance();
        if (save - money >= 500)
        {
            allAccounts[id].setWithdrawal(money);
            cout << "WithDrawn Successfully!\n";
        }
        else
        {
            cout << "Not Sufficent Balance! Account Balance Must Have at least 500 Taka\n";
        }
    }
    else
    {
        cout << "No Such Account Found!" << endl;
    }
}

void searchAccount()
{
    cout << "Enter User Account Number: ";
    long long int id;
    cin >> id;
    if (allAccounts.find(id) != allAccounts.end())
    {
        accountProfile entry = allAccounts[id];
        cout << "Account ID: " << id << endl;
        cout << "Name: " << entry.getName() << endl;
        cout << "Contact Number: " << entry.getNumber() << endl;
        cout << "ID: " << entry.getID() << endl;
        cout << "Creation Date: " << entry.getCreationDate() << endl;
        cout << "Account Type: " << entry.getAccountType() << endl;
        cout << "Birth Date: " << entry.getBirthTime() << endl;
        cout << "Balance: " << entry.getBalance() << endl;
        entry.getHistory();
    }
    else
    {
        cout << "No Such Account Found!" << endl;
    }
}