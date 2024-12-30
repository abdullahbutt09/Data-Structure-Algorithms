#include<iostream>
#include "HeaderFilesUsed.h"
#include "ClassOfProducts.h"
#include "ClassOfStores.h"
using namespace std;

class ClassOfSeller : virtual protected ClassOfProducts , protected ClassOfStores
{
protected:
    string storeCNIC, storePassword;
    char choice;

public:
    void Menu()
    {
        do
        {
            cout << "Seller Menu" << endl;
            cout << endl;
            cout << "1. Register a Store" << endl;
            cout << "2. Login to Store" << endl;
            cout << "0. Back" << endl;
            cout << endl;
            cout << "Enter your choice: ";
            
            choice = _getch() - '0'; 
            switch (choice)
            {
            case 1:
            {
                RegisterStore();
                break;
            }
            case 2:
            {
                string storeCNIC, storePassword;
                bool isLoggedIn = false;
                char ch;
                Store *store = nullptr;

                do
                {
                    system("cls");
                    cout << "Enter Store CNIC: ";
                    cin >> storeCNIC;

                    // Search for the store in unordered_map
                    auto storeIt = stores.find(storeCNIC);
                    if (storeIt == stores.end())
                    {
                        cout << endl;
                        cout << "\033[31mStore not found! Please check your CNIC.\033[0m\n";
                        return;
                    }

                    store = &storeIt->second;

                    cout << "Enter Store Password: ";
                    // cin >> storePassword;
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
                            if (!storePassword.empty())
                            {
                                storePassword.pop_back();
                                cout << "\b \b";
                            }
                        }

                        else
                        {
                            storePassword.push_back(ch);
                            cout << "*";
                        }
                    }

                    if (store->password != storePassword)
                    {
                        cout << endl;
                        cout << "Incorrect password! Please try again.\n";
                        return;
                    }
                    else
                    {
                        cout << endl;
                        system("cls");
                        cout << "\033[31mLogin Successful , Welcome\033[0m\n";
                        isLoggedIn = true;
                    }
                } while (!isLoggedIn);

                // Store menu
                if (store != nullptr)
                {
                    int storeChoice;
                    do
                    {
                        cout << "\nStore Menu\n";
                        cout << endl;
                        cout << "1. Add Product\n";
                        cout << "2. View Products\n";
                        cout << "3. Delete a Product\n";
                        cout << "4. View Earnings\n";
                        cout << "5. View Messages from Admin\n";
                        cout << "0. Logout\n";
                        cout << endl;
                        cout << "Enter your choice: ";
                        storeChoice = _getch() - '0';

                        switch (storeChoice)
                        {
                        case 1:
                            system("cls");
                            addProduct(storeCNIC);
                            break;
                        case 2:
                            system("cls");
                            displayProducts(storeCNIC);
                            break;
                        case 3:
                            system("cls");
                            deleteProduct(storeCNIC);
                            break;
                        case 4:
                            system("cls");
                            cout << "Store Earnings: $" << store->earnings << endl;
                            break;
                        case 5:
                            system("cls");
                            viewMessagesForSeller(storeCNIC);
                            break;
                        case 0:
                            system("cls");
                            cout << "Logging out...\n";
                            break;
                        default:
                            system("cls");
                            cout << "Invalid choice! Please try again.\n";
                        }
                    } while (storeChoice != 0);
                }
                break;
            }
            case 0:
                cout << "Returning to main menu...\n";
                system("cls");
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 0);
    }

    void viewMessagesForSeller(string cnic)
    {
        // Check if the store exists
        if (stores.find(cnic) == stores.end())
        {
            cout << "Store not found with CNIC " << cnic << "!\n";
            return;
        }

        Store &store = stores[cnic]; // Reference to the store

        // Check if the stack is empty
        if (store.messages.empty())
        {
            cout << endl;
            cout << "\033[31mNo messages available for you.\033[0m\n";
            return;
        }

        cout << "Your Messages (Last In, First Out):\n";
        while (!store.messages.empty())
        {
            cout << endl;
            cout << "\033[31mMESSAGE FROM ADMIN -> \033[0m" << store.messages.top() << endl;
            store.messages.pop(); // Remove the message after showing
        }
    }
};

#pragma once