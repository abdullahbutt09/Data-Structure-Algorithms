#include<iostream>
#include "HeaderFilesUsed.h"
#include "NewHeader.h"
using namespace std;

class ClassOfProducts
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
        id =  ValidatePriceIdQuantity<int>(); 

        // Check if product ID already exists in the inventory
        while (store.inventory.find(id) != store.inventory.end())
        {
            cout << "Product with ID " << id << " already exists in the inventory!\n";
            cout << "Please Enter a unique id : ";
            id =  ValidatePriceIdQuantity<int>(); 
        }
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Category: ";
        cin >> category;
        cout << "Enter Price: ";
        price = ValidatePriceIdQuantity<float>();

        while (price <= 0)
        {
            cout << "Price cannot be zero!"<<endl;
            cout << "Enter Price: ";
            price = ValidatePriceIdQuantity<float>();
        }
        
        cout << "Enter Quantity: ";
        quantity = ValidatePriceIdQuantity<int>();

        while (quantity <= 0)
        {
            cout << "Quantity cannnot be zero!"<<endl;
            cout << "Enter Quantity: ";
            quantity = ValidatePriceIdQuantity<int>();
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
};

#pragma once