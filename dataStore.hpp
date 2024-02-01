#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

unordered_map<long long int, accountProfile> allAccounts;

void saveInfo(infoAccountUser &obj)
{
    accountProfile profile;
    profile.setName(obj.name);
    profile.setNumber(obj.number);
    profile.setID(obj.id);
    profile.setCreationDate();
    if (obj.type == 1)
    {
        profile.setAccountType("Current Account");
    }
    else if (obj.type == 2)
    {
        profile.setAccountType("Saving Account");
    }
    else if (obj.type == 3)
    {
        profile.setAccountType("Salary Account");
    }
    else
    {
        profile.setAccountType("Student Account");
    }
    profile.setAccountId();
    profile.setDay(obj.day);
    profile.setDeposit(obj.balance);
    profile.setMonth(obj.month);
    profile.setYear(obj.year);
    profile.setLocation(obj.area, obj.country, obj.house, obj.road, obj.city, obj.zip);
    allAccounts[profile.getAccountId()] = profile;
}

