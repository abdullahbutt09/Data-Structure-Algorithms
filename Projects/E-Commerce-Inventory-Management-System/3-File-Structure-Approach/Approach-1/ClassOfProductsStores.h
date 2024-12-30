#include<iostream>
#include "HeaderFilesUsed.h"
using namespace std;

class Functions_Of_Stores_Related_Products
{
protected:
    struct Product
    {
        int id;
        string name;
        string category;
        float price;
        int quantity;
        int sold;
    };
    struct Store
    {
        string storeName;
        string ownerName;
        string cnic;
        string password;
        float earnings;
        unordered_map<int, Product> inventory; // Products mapped by Product ID
        float totalRatings;                    // Cumulative total of all ratings
        int ratingCount;
        stack<string> messages;
    };

    static unordered_map<string, Store> stores;

public:
    void addProduct(string storeCNIC)
    {
        string name, category;
        int id, quantity;
        float price;

        // Check if store exists
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << "Store not found!\n";
            return;
        }

        Store &store = stores[storeCNIC];
        cout << "Enter Product ID: ";
        cin >> id;

        // Check if product ID already exists in the inventory
        while (store.inventory.find(id) != store.inventory.end())
        {
            cout << "Product with ID " << id << " already exists in the inventory!\n";
            cout << "Please Enter a unique id : ";
            cin >> id;
            // return;
        }
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Category: ";
        cin >> category;
        cout << "Enter Price: ";
        cin >> price;

        while (price <= 0)
        {
            cout << endl;
            cout << "Price cannot be negative , or 0." << endl;
            cout << endl;
            cout << "Enter Price: ";
            cin >> price;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;

        while (quantity <= 0)
        {
            cout << endl;
            cout << "Quanity cannot be negative , or 0." << endl;
            cout << endl;
            cout << "Enter Quantity: ";
            cin >> quantity;
        }

        // Add product to the inventory
        store.inventory[id] = {id, name, category, price, quantity, 0};
        cout << endl;
        system("cls");
        cout << "\033[31mProduct Added Successfully.\033[0m\n";
    }

    void UpdateProductsQuantity(string storeCNIC)
    {
        int id, quantity;

        // Check if store exists
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << endl;
            cout << "\033[31mStore not found!.\033[0m\n";
            return;
        }

        Store &store = stores[storeCNIC];

        // Display products
        if (!displayProducts(storeCNIC))
            return;

        // Input product ID to update
        cout << "\nEnter Product ID to update quantity: ";
        cin >> id;

        // Check if product exists in the inventory
        if (store.inventory.find(id) == store.inventory.end())
        {
            cout << "Product not found!\n";
            return;
        }

        // Show current quantity and update it
        Product &product = store.inventory[id];
        cout << "Current Quantity: " << product.quantity << endl;
        cout << "Enter New Quantity: ";
        cin >> quantity;

        if (quantity < 0)
        {
            cout << "Quantity cannot be negative. Update failed.\n";
            return;
        }

        product.quantity = quantity;
        cout << "Product quantity updated successfully.\n";
    }

    void deleteProduct(string &storeCNIC)
    {
        int productID;
        // Check if store exists
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << "Store not found!\n";
            return;
        }

        Store &store = stores[storeCNIC];
        if (!displayProducts(storeCNIC))
        {
            return;
        }
        cout << endl;
        cout << "Please Enter product id : ";
        cin >> productID;

        // Check if product exists in the inventory
        if (store.inventory.find(productID) == store.inventory.end())
        {
            cout << "Product not found in the store's inventory.\n";
            return;
        }

        int choice, quantity = 0;
        Product &product = store.inventory[productID];
        cout << endl;
        cout << "1. Remove Product By Quantity Wise." << endl;
        cout << "2. Remove Full Product." << endl;
        cout << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the quantity you want to remove : ";
            cin >> quantity;

            if (quantity <= 0)
            {
                cout << endl;
                cout << "Kindly Enter a Valid Quantity To Remove From 1 to " << product.quantity << " for product " << product.name << endl;
                return;
            }

            if (quantity > product.quantity)
            {
                cout << "Requested quantity exceeds available stock.\n";
                return;
            }
            // Remove the product from the inventory by quantity
            product.quantity -= quantity;
            cout << endl;
            cout << "Product with ID " << productID << " and quantity " << quantity << " has been successfully removed!" << endl;
            break;
        case 2:
            // Remove the product from the inventory
            store.inventory.erase(productID);
            cout << endl;
            cout << "Product with ID " << productID << " deleted successfully from the store '" << store.storeName << "'.\n";
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    bool displayProducts(string storeCNIC)
    {
        // Check if store exists
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << endl;
            cout << "Store not found!\n";
            return false;
        }

        const Store &store = stores[storeCNIC];

        if (store.inventory.empty())
        {
            cout << endl;
            cout << "No products available in the store.\n";
            return false;
        }

        // Display all products
        cout << endl;
        cout << left
             << setw(15) << "ID"
             << setw(25) << "Product Name"
             << setw(20) << "Category"
             << setw(15) << "Price"
             << setw(15) << "Quantity"
             << endl;

        cout << string(84, '~') << endl;

        for (const auto &pair : store.inventory)
        {
            const Product &product = pair.second;

            cout << setw(15) << product.id
                 << setw(25) << product.name
                 << setw(20) << product.category
                 << "$" << setw(14) << fixed << setprecision(2) << product.price
                 << setw(15) << product.quantity << endl;
        }
        return true;
    }

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
        cin >> cnic;

        while (stores.find(cnic) != stores.end())
        {
            cout << "Store with this CNIC already exists!\n";
            cout << "Please use a different CNIC for registration\n";
            cout << "Enter CNIC: ";
            cin >> cnic;
        }

        cout << "Enter Password: ";

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

unordered_map<string, Functions_Of_Stores_Related_Products::Store>
    Functions_Of_Stores_Related_Products::stores;

#pragma once