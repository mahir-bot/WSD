#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

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

void printUpdateChoices()
{
    cout << "********************\n";
    cout << "   Change Options\n";
    cout << "********************\n";

    cout << "1. Contact Number\n"
         << "2. House\n"
         << "3. Road\n"
         << "4. Area\n"
         << "5. City\n"
         << "6. Country\n"
         << "7. Zip Code\n"
         << "8. Birth Year\n"
         << "9. Birth Month\n"
         << "10. Birth Day\n"
         << "Choose Your Action ->>";
}

void printInfoUnsaved()
{
    cout << "********************\n";
    cout << "   Change Options\n";
    cout << "********************\n";

    cout << "1. Name\n"
         << "2. Contact Number\n"
         << "3. Account Type\n"
         << "4. Account ID Type\n"
         << "5. User ID\n"
         << "6. House\n"
         << "7. Road\n"
         << "8. Area\n"
         << "9. City\n"
         << "10. Country\n"
         << "11. Zip Code\n"
         << "12. Birth Year\n"
         << "13. Birth Month\n"
         << "14. Birth Day\n"
         << "15. Quit\n"
         << "Choose Your Action ->>";
}
