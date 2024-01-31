#include <iostream>
#include <string>
#include <unordered_map>
#include "validityFunction.hpp"
using namespace std;

unordered_map<int, string> userTag;

struct infoAccountUser
{
    string name, number, id, house, road, area, city, country;
    int type, zip, year, month, day;
    double balance = 500.00;
};
void printNewAccount_Details()
{
    userTag[1] = "name";
    userTag[2] = "number";
    userTag[3] = "id";
    userTag[4] = "type";
    userTag[5] = "house";
    userTag[6] = "road";
    userTag[7] = "area";
    userTag[8] = "city";
    userTag[9] = "country";
    userTag[10] = "zip";
    userTag[11] = "year";
    userTag[12] = "month";
    userTag[13] = "day";
    infoAccountUser user;
    cout << "Please Provide Necessary Information For Completion Of Your Account" << endl;
    cout << "Enter Name: ";
    cin >> user.name;
    cout << "\nEnter Contact Number(+880): ";
    cin >> user.number;

    cout << "Enter NID/Driver Licence/Student ID(Age Under 18): ";
    cin >> user.id;

    cout << "\nEnter Account Type\n";
    cout << "1.Current Account \t 2.Saving Account \t 3.Salary Account \t 4.Student Account\n";
    cout << "Account Type Id no: ";
    cin >> user.type;

    cout << "\nProvide Current Address";
    cout << "\nHouse No: ";
    cin >> user.house;
    cout << "\nRoad No: ";
    cin >> user.road;
    cout << "\nArea: ";
    cin >> user.area;
    cout << "\nCity: ";
    cin >> user.city;
    cout << "Country: ";
    cin >> user.country;
    cout << "\nZip Code: ";
    cin >> user.zip;

    cout << "Date Of Birth";
    cout << "\nYear: ";
    cin >> user.year;
    cout << "\nMonth: ";
    cout << user.month;
    cout << "\nDay: ";
    cout << user.day;

    while(true)
    {
        vector<int> tag = userInfoCheck(user);
        
    }
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