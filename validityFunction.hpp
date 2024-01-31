#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <regex>
#include <chrono>
#include "printFunction.hpp"
using namespace std;

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
    try
    {
        chrono::year_month_day date(chrono::year(year), chrono::month(month), std::chrono::day(day));
        return date.ok();
    }
    catch (const exception &e)
    {
        return false;
    }
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

vector<pair<int, string>> userInfoCheck(infoAccountUser &user)
{
    vector<pair<int, string>> store;
    bool birth = isValidDate(user.year, user.month, user.day);
    checkAddress(store, user);
    int age = calculateAge(user.year, user.month, user.day);
    if (user.type < 0 or user.type > 4)
    {
        store.push_back({4, "Please Provide Type Of Account in the range of [1,4]"});
    }
    if (number.size() != 10)
    {
        store.push_back({2, "Please Provide a Valid Phone number of 10 Digits"});
    }
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