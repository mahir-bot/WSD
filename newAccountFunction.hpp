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
    string type, year, month, day, idType;
    double balance;
};
bool isValidInteger(const std::string &input)
{
    try
    {

        int result = std::stoi(input);
        if (input.find_first_not_of("0123456789") != std::string::npos)
        {
            return false;
        }
        return true; // Input is a valid integer
    }
    catch (const std::invalid_argument &)
    {
        return false; // Input cannot be converted to an integer
    }
    catch (const std::out_of_range &)
    {
        return false; // Input is out of the range of representable values for int
    }
}
bool isValidDouble(const string &str)
{
    try
    {
        stod(str);
        return true;
    }
    catch (const invalid_argument &)
    {
        return false;
    }
    catch (const out_of_range &)
    {
        return false;
    }
}
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
    if (id.length() == 0)
        store.push_back({3, "Can't Leave empty, Provide valid Id"});
}

vector<pair<int, string>> userInfoCheck(infoAccountUser user)
{
    vector<pair<int, string>> store;
    if (isValidInteger(user.type))
    {
        if (stoi(user.type) < 0 or stoi(user.type) > 4)
        {
            store.push_back({4, "Please Provide Type Of Account in the range of [1,4]"});
        }
    }
    else
    {
        store.push_back({4, "Please Provide Type Of Account in the range of [1,4]"});
    }

    if (isValidInteger(user.number))
    {
        if (user.number.size() != 10)
        {
            store.push_back({2, "Please Provide a Valid Phone number of 10 Digits"});
        }
    }
    else
    {
        store.push_back({2, "Please Provide a Valid Phone number of 10 Digits"});
    }

    bool birth = false;
    if (isValidInteger(user.year) and isValidInteger(user.month) and isValidInteger(user.day))
        birth = isValidDate(stoi(user.year), stoi(user.month), stoi(user.day));

    if (birth == false)
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

    cout << "\nAmount: ";
    string temp;
    cin >> temp;
    bool x = isValidDouble(temp);
    cout << x << endl;

    if (x == false)
    {
        cout << "Can't open Account of Less then 500 Taka\n";
        return {user, -1};
    }
    if (x)
        if (stod(temp) < 500)
        {
            cout << "Can't open Account of Less then 500 Taka\n";
            // exit(0);
            return {user, -1};
        }
        else
        {
            user.balance = stod(temp);
        }

    bool out = false;
    int needToChange = 0;
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
            cout << "If you want to quit Creating Account Press -1\n";
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
                if (user.type == "-1")
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
                if (user.year == "-1")
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
                cin >> user.month;
                cout << endl;
                if (user.month == "-1")
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
                cin >> user.day;
                cout << endl;
                if (user.day == "-1")
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
                if (user.idType == "-1")
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