#include <iostream>
#include "HeaderFilesUsed.h"
#include "ClassOfProducts.h"

class ClassOfStores : virtual protected ClassOfProducts
{
public:
    bool RegisterStore()
    {
        system("cls");
        string storeName, ownerName, cnic, password;
        char ch;
        cout << "Enter Store Name: ";
        getline(cin, storeName);
        cout << "Enter Owner Name: ";
        getline(cin, ownerName);
        cout << "Enter CNIC: ";

        while (true)
        {
            ch = _getch(); // Get a single character without requiring Enter

            if (ch == '\b')
            { // Backspace key (ASCII 8)
                if (!cnic.empty())
                {
                    cnic.pop_back(); // Remove the last character from the string
                    cout << "\b \b"; // Move back, print a space to overwrite, then move back again
                }
            }
            else if (ch == '\r')
            { // Enter key (ASCII 13)
                if (cnic.length() != 9)
                {
                    cout << endl;
                    cout << "\nYour CNIC Length cannot be " << cnic.length() << endl;
                    cout << "Please enter an 9 digit CNIC number!" << endl;
                    cout << "Enter CNIC : ";
                    cnic.clear();
                }

                else
                {
                    break;
                }
            }
            else if (isalpha(ch))
            { // Check if the character is an alphabet
                cout << endl;
                cout << "\nYour CNIC Cannot Include Alphabets!" << endl;
                cout << "Kindly Enter Only Numbers!" << endl;
                cout << endl;
                cout << "Please Enter Valid CNIC : ";
                cnic.clear(); // Clear the cnic buffer
            }
            else if (cnic.length() == 9)
            {
                cout << endl;
                cout << "\nYour CNIC cannot Greater than 9 numbers!" << endl;
                cout << "Kindly Only 9 Digit CNIC Number : ";
                cout << endl;
                cnic.clear();
            }
            else
            {
                cnic += ch; // Append character to the cnic
                cout << ch; // Echo the character
            }

            if (stores.find(cnic) != stores.end())
            {
                cout << endl;
                cout << "\nStore with this CNIC already exists!\n";
                cout << "Please use a different CNIC for registration\n";
                cout << endl;
                cnic.clear();
                cout << "Enter CNIC: ";
            }
        }

        cout << "\nEnter Password: ";

        while (true)
        {
            ch = _getch();

            if (ch == '\r')
            {
                if (password.length() < 8)
                {
                    cout << endl;
                    cout << "\nYour password length cannot be " << password.length() << "!" << endl;
                    cout << "Sir your password length should be 8 or more than 8 characters!" << endl;
                    cout << endl;
                    cout << "Enter Password : ";
                    password.clear();
                }

                else
                {
                    cout << endl;
                    break;
                }
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

        // Add the new store to the unordered_map
        Store newStore = {storeName, ownerName, cnic, password}; // Initialize explicitly
        stores[cnic] = newStore;
        system("cls");
        cout << "Store registered successfully!\n";
        cout << endl;
        return true;
    }

    void displaySalesAndEarnings(const string &storeCNIC)
    {
        // Find the store
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << "Store not found.\n";
            return;
        }
        const Store &store = stores[storeCNIC];

        float totalEarnings = 0;
        bool hasSales = false;

        // Print Header
        cout << left << setw(10) << "ID"
             << setw(20) << "Product Name"
             << setw(15) << "Quantity Sold"
             << setw(15) << "Earnings" << endl;

        cout << string(60, '~') << endl;

        // Iterate through the inventory
        for (const auto &pair : store.inventory)
        {
            const Product &product = pair.second;

            if (product.sold > 0) // Only display sold products
            {
                hasSales = true;
                float earnings = product.sold * product.price;
                totalEarnings += earnings;

                cout << setw(10) << product.id
                     << setw(20) << product.name
                     << setw(15) << product.sold
                     << setw(15) << fixed << setprecision(2) << earnings << endl;
            }
        }

        if (!hasSales)
        {
            cout << "No products have been sold yet.\n";
            return;
        }

        cout << string(60, '-') << endl;
        cout << "Total Earnings: " << fixed << setprecision(2) << totalEarnings << endl;
    }

    void deleteStore(string storeCNIC)
    {
        // Check if the store exists in the unordered_map
        if (stores.find(storeCNIC) == stores.end())
        {
            system("cls");
            cout << "Store with CNIC " << storeCNIC << " not found.\n";
            return;
        }

        // Get the store
        Store &store = stores[storeCNIC];

        // Clear the store's inventory
        store.inventory.clear();

        // Erase the store from the unordered_map
        stores.erase(storeCNIC);

        system("cls");
        cout << "Store with CNIC " << storeCNIC << " has been successfully deleted.\n";
    }

    void deleteAllStores()
    {
        // Check if the map is empty
        if (stores.empty())
        {
            cout << "No stores available to delete!" << endl;
            return;
        }

        // Iterate through the unordered_map to delete all store resources
        for (auto &storePair : stores)
        {
            Store &currentStore = storePair.second;

            // No need to manually delete products since inventory is now an unordered_map
            // Clear the inventory (products map)
            currentStore.inventory.clear();

            // Reset store ratings (optional cleanup)
            currentStore.totalRatings = 0;
            currentStore.ratingCount = 0;

            // Reset earnings to 0 (optional)
            currentStore.earnings = 0;
        }

        // Finally, clear the entire map of stores
        stores.clear();

        cout << "All stores have been successfully deleted!" << endl;
    }

    bool DisplayStores()
    {
        if (stores.empty())
        {
            cout << "No stores available.\n";
            return false;
        }

        cout << endl;
        cout << left
             << setw(25) << "Store Name"
             << setw(20) << "Owner Name"
             << setw(20) << "CNIC"
             << setw(15) << "Earnings" << endl;

        cout << string(80, '~') << endl;

        // Iterate through the unordered_map to display all stores
        for (const auto &pair : stores)
        {
            const Store &store = pair.second;
            cout << setw(25) << store.storeName
                 << setw(20) << store.ownerName
                 << setw(20) << store.cnic
                 << "$" << setw(14) << fixed << setprecision(2) << store.earnings << endl;
        }
        return true;
    }
};

unordered_map<string, ClassOfProducts::Store>
    ClassOfProducts::stores;

#pragma once