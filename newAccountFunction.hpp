#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <regex>
#include <chrono>

using namespace std;

struct infoAccountUser
{
    string name, number, id, house, road, area, city, country, zip;
    int type = -1, year = -1, month = -1, day = -1, idType = -1;
    double balance = 500.00;
};
int calculateAge(int birthYear, int birthMonth, int birthDay)
{
    auto now = chrono::system_clock::now();
    auto time = chrono::system_clock::to_time_t(now);
    auto tm = localtime(&time);

    int currentYear = tm->tm_year + 1900;
    int currentMonth = tm->tm_mon + 1;
    int age = currentYear - birthYear;
    if (birthMonth > currentMonth)
        age--;
    else if (birthMonth == currentMonth && birthDay > tm->tm_mday)
        age--;

    return age;
}

bool isValidDate(int year, int month, int day)
{
    if (year < 1900)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    int daysInMonth[] = {31, 28 + ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonth[month - 1])
    {
        return false;
    }

    return true;
}

void checkId(vector<pair<int, string>> &store, int idType, string id)
{
    if (idType != 1)
    {
        if (idType == -1)
        {
            store.push_back({14, "Can't Leave Empty! Provide Valid ID Type"});
            if (id.length() > 0)
                store.push_back({3, "ID type wasn't Provided, Give Your ID again"});
            else
                store.push_back({3, "Provide Id type and valid Id"});
        }
        else if (idType == 2)
        {
            store.push_back({14, "Need NID/Driver License, age is above 18"});
            if (id.length() > 0)
                store.push_back({3, "ID type wasn't Provided, Give Your ID again"});
            else
                store.push_back({3, "Provide Id type and valid Id"});
        }
        else
        {
            store.push_back({14, "Invalid Option"});
            if (id.length() > 0)
                store.push_back({3, "ID type wasn't Provided, Give Your ID again"});
            else
                store.push_back({3, "Provide Id type and valid Id"});
        }
    }
    else
    {
        if (id.length() == 0)
            store.push_back({3, "Can't Leave empty, Provide valid Id"});
    }
}

void checkIdKid(vector<pair<int, string>> &store, int idType, string id)
{
    if (idType != 2)
    {
        if (idType == -1)
        {
            store.push_back({14, "Can't Leave Empty! Provide Valid ID Type"});
            if (id.length() > 0)
                store.push_back({3, "ID type wasn't Provided, Give Your ID again"});
            else
                store.push_back({3, "Provide Id type and valid Id"});
        }
        else if (idType == 1)
        {
            store.push_back({14, "Need Student ID, age is bellow 18"});
            if (id.length() > 0)
                store.push_back({3, "ID type wasn't Provided, Give Your ID again"});
            else
                store.push_back({3, "Provide Id type and valid Id"});
        }
        else
        {
            store.push_back({14, "Invalid Option"});
            if (id.length() > 0)
                store.push_back({3, "ID type wasn't Provided, Give Your ID again"});
            else
                store.push_back({3, "Provide Id type and valid Id"});
        }
    }
    else
    {
        if (id.length() == 0)
            store.push_back({3, "Can't Leave empty, Provide valid Id"});
    }
}

bool isValidZipCode(string &zipCode)
{
    regex pattern("\\b\\d{4}\\b");
    return regex_match(zipCode, pattern);
}
void checkAddress(vector<pair<int, string>> &store, infoAccountUser &user)
{
    if (isValidZipCode(user.zip) == false)
    {
        store.push_back({10, "Please Provide Valid Zip Code"});
    }
    if (user.house.empty())
    {
        store.push_back({5, "Please Provide Valid House Number"});
    }
    if (user.road.empty())
    {
        store.push_back({6, "Please Provide Valid Road Number"});
    }
    if (user.area.empty())
    {
        store.push_back({7, "Please Provide Valid Area"});
    }
    if (user.city.empty())
    {
        store.push_back({8, "Please Provide Valid City"});
    }
    if (user.country.empty())
    {
        store.push_back({9, "Please Provide Valid Country"});
    }
}

vector<pair<int, string>> userInfoCheck(infoAccountUser user)
{
    vector<pair<int, string>> store;
    bool birth = isValidDate(user.year, user.month, user.day);
    checkAddress(store, user);
    
    if (user.type < 0 or user.type > 4)
    {
        store.push_back({4, "Please Provide Type Of Account in the range of [1,4]"});
    }
    if (user.number.size() != 10)
    {
        store.push_back({2, "Please Provide a Valid Phone number of 10 Digits"});
    }
    
    int age = calculateAge(user.year, user.month, user.day);
    if (birth and age >= 18)
    {
        checkId(store, user.idType, user.id);
    }
    else if (birth and age < 18 and age >= 10)
    {
        checkIdKid(store, user.idType, user.id);
    }
    else
    {
        store.push_back({11, "Provide Valid Year"});
        store.push_back({12, "Provide Valid Month"});
        store.push_back({13, "Provide Valid Day"});
    }

    return store;
}

pair<infoAccountUser, int> printNewAccount_Details()
{
    // userTag[1] = "name";
    // userTag[2] = "number";
    // userTag[3] = "id";
    // userTag[4] = "type";
    // userTag[5] = "house";
    // userTag[6] = "road";
    // userTag[7] = "area";
    // userTag[8] = "city";
    // userTag[9] = "country";
    // userTag[10] = "zip";
    // userTag[11] = "year";
    // userTag[12] = "month";
    // userTag[13] = "day";
    // userTag[14] = "idType";
    infoAccountUser user;

    cout << "Please Provide Necessary Information For Completion Of Your Account" << endl;
    cout << "Enter Name: ";
    cin >> user.name;

    cout << "\nEnter Contact Number(+880): ";
    cin >> user.number;

    cout << "\nEnter Account Type\n";
    cout << "1.Current Account \t 2.Saving Account \t 3.Salary Account \t 4.Student Account\n";
    cout << "Account Type Id no: ";
    cin >> user.type;


    cout << "\nEnter Account ID Type\n";
    cout << "1.Enter NID/Driver Licence \t 2.Student ID(Age Under 18)";
    cout << "\n ID type: ";
    cin >> user.idType;


    cout << "\nID: ";
    cin >> user.id;

    cout << "\nProvide Current Address";
    cout << "\nHouse No: ";
    cin >> user.house;

    cout << "\nRoad No: ";
    cin >> user.road;

    cout << "\nArea: ";
    cin >> user.area;

    cout << "\nCity: ";
    cin >> user.city;

    cout << "\nCountry: ";
    cin >> user.country;

    cout << "\nZip Code: ";
    cin >> user.zip;

    cout << "\nDate Of Birth";
    cout << "\nYear: ";
    cin >> user.year;

    cout << "\nMonth: ";
    cin >> user.month;

    cout << "\nDay: ";
    cin >> user.day;

    bool out = false;
    int needToChange = 0;
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
            cout << "If you want to quit Press -1\n";
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
        needToChange = -1;
    }
    return {user, needToChange};
}