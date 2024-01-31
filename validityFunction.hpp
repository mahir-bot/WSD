#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <chrono>
#include "printFunction.hpp"
using namespace std;

int calculateAge(int birthYear, int birthMonth, int birthDay)
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto tm = std::localtime(&time);

    int currentYear = tm->tm_year + 1900;
    int currentMonth = tm->tm_mon + 1;
    int age = currentYear - birthYear;
    if (birthMonth > currentMonth)
    {
        age--;
    }
    else if (birthMonth == currentMonth && birthDay > tm->tm_mday)
    {
        age--;
    }

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

vector<int> userInfoCheck(infoAccountUser &user)
{
    bool number = checkNumber(user.number);
    bool birth = isValidDate(user.year, user.month, user.day);
    int age = calculateAge(user.year, user.month, user.day);
    if (birth and age>=18)
    {

    }
    else if(birth and age<18 and age>=10)
    {

    }
    else if(birth and age<10)
    {

    }
    else
    {
        
    }
}