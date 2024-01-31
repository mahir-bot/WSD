#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stack>
using namespace std;
void printChoices();
struct transaction
{
    string type;
    double amount;
    time_t timestamp;
};

class acountProfile
{
private:
    string name;
    string number;
    string nid;
    string creationDate;
    string accountType;
    string accountStatus;
    int year, month, day;
    long long int accountId;
    double balance = 0.0;
    stack<transaction> history;

public:
};

signed main()
{
    while (true)
    {
    }
}


void printChoices()
{
    
}