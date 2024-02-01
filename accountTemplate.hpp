#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <stack>
#include <unordered_map>
using namespace std;
class accountProfile
{
private:
    struct Address
    {
        string city, country, house, road, area;
        string zipCode;
    };
    struct Transaction
    {
        string type;
        double amount;
        time_t timestamp;
    };
    string name;
    string number;
    string id;
    string creationDate;
    string accountType;

    int year, month, day;
    long long int accountId;
    double balance = 0.0;
    Address location;
    stack<Transaction> history;

public:
    void setName(const string &Identity);
    void setNumber(const string &Contact);
    void setID(const string &Citizen);
    void setCreationDate();
    void setAccountType(const string &Type);
    void setYear(const int &Annum);
    void setMonth(const int &MoonCycle);
    void setDay(const int &SunUpToSundown);
    void setAccountId();
    void setLocation(const string &Town, const string &Nation, const string &Residence,
                     const string &Street, const string &District, string &Postcode);
    void setDeposit(double &Add);
    void setWithdrawal(double &Subtract);

    string getName() { return name; }
    string getNumber() { return number; }
    string GetID() { return id; }
    string getCreationDate() { return creationDate; }
    string getAccountType() { return accountType; }
    string getBirthTime() { return (to_string(year) + "/" + to_string(month) + "/" + to_string(day)); }
    long long int getAccountId() { return accountId; }
    double getBalance() { return balance; }
    stack<Transaction> getHistory() { return history; }
};

void accountProfile::setName(const string &Identity) { name = Identity; }
void accountProfile::setNumber(const string &Contact) { number = Contact; }
void accountProfile::setID(const string &Citizen) { id = Citizen; }
void accountProfile::setAccountType(const string &Type) { accountType = Type; }
void accountProfile::setYear(const int &Annum) { year = Annum; }
void accountProfile::setMonth(const int &MoonCycle) { month = MoonCycle; }
void accountProfile::setDay(const int &SunUpToSundown) { day = SunUpToSundown; }
void accountProfile::setCreationDate()
{
    time_t createTime = time(nullptr);
    ostringstream oss;
    oss << put_time(localtime(&createTime), "%Y-%m-%d %H:%M:%S");
    creationDate = oss.str();
}

void accountProfile::setAccountId()
{
    int mod = (int)1e9 + 7;
    int key = 998244353;
    long long int hash = 0;
    string pattern = name + id + accountType;
    for (int i = 0; i < pattern.length(); i++)
        hash = ((hash * key) + pattern[i]) % mod;

    accountId = hash;
}
void accountProfile::setLocation(const string &Town, const string &Nation, const string &Residence,
                                 const string &Street, const string &District, string &Postcode)
{
    location.zipCode = Postcode;
    location.road = Street;
    location.house = Residence;
    location.country = Nation;
    location.city = Town;
    location.area = District;
}
void accountProfile::setDeposit(double &Add)
{
    balance += Add;
    Transaction flow;
    flow.amount = Add;
    flow.type = "Deposit";
    flow.timestamp = time(nullptr);
    history.push(flow);
}
void accountProfile::setWithdrawal(double &Subtract)
{
    balance -= Subtract;
    Transaction flow;
    flow.amount = Subtract;
    flow.type = "Withdrawal";
    flow.timestamp = time(nullptr);
    history.push(flow);
}