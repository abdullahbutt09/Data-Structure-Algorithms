#include<iostream>
#include "ClassOfProductsStores.h"
#include "HeaderFilesUsed.h"
using namespace std;

class ClassOfAdmin : protected Functions_Of_Stores_Related_Products
{
protected:
    string cnic, message;
    int choice;
    string AdminPassword = "admin";
    string AdminUserName = "admin";

public:
    void Menu()
    {
        string password, username;
        char ch;
        cout << "Enter Admin Username: ";
        cin >> username;
        cout << "Enter Admin Password: ";
        while (true)
        {
            ch = _getch();

            if (ch == '\r')
            {
                cout << endl;
                break;
            }
            else if (ch == '\b')
            {
                if (!password.empty())
                {
                    password.pop_back();
                    cout << "\b \b";
                }
            }

            else
            {
                password.push_back(ch);
                cout << "*";
            }
        }

        if (AdminUserName != username || password != AdminPassword)
        {
            system("cls");
            cout << "Invalid Username or Password! Access Denied.\n";
            return;
        }
        system("cls");
        cout << "Access Granted! Welcome Admin."<<endl;
        cout << endl;
        do
        {
            cout << "Admin Menu\n";
            cout << endl;
            cout << "1. Add Store\n";
            cout << "2. View All Stores\n";
            cout << "3. Delete a Store\n";
            cout << "4. Delete all Stores\n";
            cout << "5. Send message to a store\n";
            cout << "0. Logout\n";
            cout << endl;
            cout << "Enter your choice: ";

            choice = _getch() - '0'; // Convert char to int

            switch (choice)
            {
            case 1:
                cin.ignore();
                RegisterStore();
                break;
            case 2:
                system("cls");
                DisplayStores();
                break;
            case 3:
                system("cls");
                if (!DisplayStores())
                {
                    break;
                }
                cout << endl;
                cout << "Enter CNIC of the store to be deleted: ";
                cin >> cnic;
                deleteStore(cnic);
                break;
            case 4:
                system("cls");
                deleteAllStores();
                break;
            case 5:
                system("cls");
                if (!DisplayStores())
                {
                    break;
                }
                system("cls");
                sendMessageToSeller();
                break;
            case 0:
                system("cls");
                cout << "Logging out..." << endl;
                return;
            default:
                system("cls");
                cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 0);
    }

    void sendMessageToSeller()
    {
        cout << "Enter Store CNIC to view the stats of the store : ";
        cin >> cnic;

        // Check if the store exists
        if (stores.find(cnic) == stores.end())
        {
            cout << "Store not found with CNIC " << cnic << "!\n";
            return;
        }
        cout << endl;
        displayProducts(cnic);
        cout << endl;
        displaySalesAndEarnings(cnic);
        cout << endl;

        cout << "Enter message to send: ";
        cin.ignore();          // Clear input buffer
        getline(cin, message); // Allow multi-word message

        // Push the message onto the store's message stack
        stores[cnic].messages.push(message);
        cout << endl;
        cout << "\033[31mMessage sent successfully to store -> \033[0m" << stores[cnic].storeName << endl;
    }
};

#pragma once