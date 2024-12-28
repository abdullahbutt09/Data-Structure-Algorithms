#include "ClassOfAdmin.h"
#include "ClassOfBuyer.h"
#include "ClassOfSeller.h"

#include <iostream>

using namespace std;

int main()
{
    char choice;
    ClassOfAdmin *Admin = new ClassOfAdmin();
    ClassOfSeller *Seller = new ClassOfSeller();
    ClassOfBuyer *Buyer = new ClassOfBuyer();
    do
    {
        cout << "\n \t \t \t \033[36mE-Commerce Inventory Management System\033[0m\n"; // Cyan for heading
        cout << endl;
        cout << "\033[32m1. Admin\033[0m\n";  // Green
        cout << "\033[35m2. Seller\033[0m\n"; // Magenta
        cout << "\033[33m3. Buyer\033[0m\n";  // Yellow
        cout << "\033[31m0. Exit\033[0m\n";   // Red for exit
        cout << endl;
        cout << "\033[96mEnter your choice: \033[0m"; // Bright Cyan

        choice = _getch() - '0'; // Convert char to int
        switch (choice)
        {
        case 1:
            system("cls");
            Admin->Menu();
            break;
        case 2:
            system("cls");
            Seller->Menu();
            break;
        case 3:
            system("cls");
            Buyer->Menu();
            break;
        case 0:
            system("cls");
            cout << "Exiting program...\n";
            break;
        default:
            cout << endl;
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}