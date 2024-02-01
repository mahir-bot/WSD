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
            vector<pair<int, string>> stores;
            bool birth = isValidDate(user.year, user.month, user.day);
            int age = calculateAge(user.year, user.month, user.day);
            if (birth and age >= 18)
            {
                checkId(stores, user.idType, user.id);
            }
            else if (birth and age < 18 and age >= 10)
            {
                checkIdKid(stores, user.idType, user.id);
            }
            for (auto it : stores)
            {
                cout << it.second << endl;
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
            if (isValidZipCode(user.zip) == false)
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
            if (user.year < 1900 or user.year > 2014)
            {
                cout << "Year Must Be greater Then 1900 and Less then 2014\n";
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
            int daysInMonth[] = {31, 28 + ((user.year % 4 == 0 && user.year % 100 != 0) || (user.year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (user.day < 1 || user.day > daysInMonth[user.month - 1])
            {
                cout << "Make sure you provide valid Year and Month beforehand and provide valid day between 1-31 days based on month\n";
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
        cout << tag.size() << endl;

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

void updateInfo(long long int ac)
{
    accountProfile profile = allAccounts[ac];

    while (true)
    {
        printUpdateChoices();
        int option;
        cin >> option;
    }
}
