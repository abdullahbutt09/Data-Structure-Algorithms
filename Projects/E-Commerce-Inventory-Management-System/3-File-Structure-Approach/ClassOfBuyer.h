#include <iostream>
#include "HeaderFilesUsed.h"
#include "ClassOfProducts.h"
#include "ClassOfStores.h"

using namespace std;

class ClassOfBuyer : virtual protected ClassOfProducts, protected ClassOfStores
{
protected:
    struct Buyer
    {
        string name;
        string cnic;
        string password;
        float balance;
    };
    unordered_map<string, Buyer> buyers; // Keyed by CNIC

public:
    virtual void Menu()
    {
        string storeCNIC, buyerCNIC = "";

        int choice, subChoice, subsubChoice;
        do
        {
            cout << "Buyer Menu\n";
            cout << endl;
            cout << "1. Register as Buyer\n";
            cout << "2. Login as Buyer\n";
            cout << "0. Return\n";
            cout << endl;
            cout << "Enter your choice: ";
            choice = _getch() - '0';

            switch (choice)
            {
            case 1:
                RegisterBuyer();
                break;
            case 2:
                system("cls");
                if (!Login())
                {
                    break;
                }
                cout << endl;
                do
                {
                    cout << "1. Purchase Product.\n";
                    cout << "2. Check Account Balance.\n";
                    cout << "0. Logout.\n";
                    cout << endl;
                    cout << "Enter your choice: ";
                    subChoice = _getch() - '0';

                    switch (subChoice)
                    {
                    case 1:
                        system("cls");
                        if (!DisplayStores())
                        {
                            break;
                        }
                        cout << endl;
                        cout << "Enter Store CNIC to view products: ";
                        cin >> storeCNIC;
                        system("cls");
                        if (!displayProducts(storeCNIC))
                        {
                            break;
                        }

                        cout << endl;
                        cout << "1. Input CNIC to proceed." << endl;
                        cout << "0. return." << endl;
                        cout << endl;
                        cout << "Enter your choice : ";
                        subsubChoice = _getch() - '0';
                        switch (subsubChoice)
                        {
                        case 1:
                            system("cls");
                            cout << "Enter your CNIC to proceed: ";
                            cin >> buyerCNIC;
                            purchaseProduct(buyerCNIC);
                            break;
                        case 0:
                            cout << "Returning Back!" << endl;
                            break;
                        default:
                            cout << "Invalid Input!" << endl;
                            break;
                        }

                        break;
                    case 2:
                        system("cls");
                        cout << "Enter your CNIC of your Buyer account: ";
                        cin >> buyerCNIC;
                        displayBuyerBalance(buyerCNIC);
                        break;
                    case 0:
                        system("cls");
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                    }
                } while (subChoice != 0);
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 0);
    }

    bool RegisterBuyer()
    {
        string name, cnic, password;
        float balance;
        char ch;

        // Input buyer details
        system("cls");
        cout << "Enter Buyer Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        cout << "Enter Buyer CNIC: ";

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
            else if (!isdigit(ch))
            { // Check if the character is not a digit
                cout << endl;
                cout << "\nYour CNIC Cannot Include Special Symbols!" << endl;
                cout << "Kindly Enter Only Numbers!" << endl;
                cout << endl;
                cout << "Please Enter Valid CNIC : ";
                cnic.clear(); // Clear the cnic buffer
            }
            else if (cnic.length() == 9)
            {
                cout << endl;
                cout << "\nYour CNIC cannot Greater than 9 numbers!" << endl;
                cout << "Kindly Only 9 Digit CNIC Number!" << endl;
                cout << endl;
                cnic.clear();
                cout << "Enter CNIC: ";
            }
            else
            {
                cnic += ch; // Append character to the cnic
                cout << ch; // Echo the character
            }

            // Check if buyer with the same CNIC already exists
            if (buyers.find(cnic) != buyers.end())
            {
                cout << endl;
                cout << "\nBuyer with CNIC " << cnic << " already exists!\n";
                cout << "Please use a different CNIC for registration.\n";
                cout << endl;
                cnic.clear();
                cout << "Enter CNIC: ";
            }
        }

        cout << "\nEnter Your Password: ";

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
        cout << "Enter Initial Balance: ";
        balance = ValidatePriceIdQuantity<float>();

        while (balance <= 0)
        {
            cout << endl;
            cout << "Initial Balance cannot be negative , or 0" << endl;
            cout << "Kindly Enter a valid Balance" << endl;
            cout << endl;
            cout << "Enter Initial Balance: ";
            balance = ValidatePriceIdQuantity<float>();
        }

        // Add the new buyer to the unordered_map
        buyers[cnic] = {name, cnic, password, balance};
        system("cls");
        cout << "Buyer registered successfully!" << endl;
        return true;
    }

    bool Login()
    {
        string cnic, password;
        char ch;

        // Input CNIC
        cout << "Enter your CNIC to login: ";
        cin >> cnic;

        // Search for the buyer
        if (buyers.find(cnic) != buyers.end())
        {
            // Buyer found, ask for password
            Buyer &buyer = buyers[cnic];
            cout << "Enter your password: ";

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
            if (buyer.password == password)
            {
                cout << endl;
                // cout << "Login successful! Welcome, " << buyer.name << ".\n";
                cout << "\033[31mLogin successful! Welcome, \033[0m" << buyer.name << endl;
                return true; // Exit on successful login
            }
            else
            {
                cout << "\033[31mIncorrect password! Login failed.\033[0m" << endl;
                return false;
            }
        }

        // If buyer not found
        cout << endl;
        cout << "\033[31mLogin failed! No buyer found with CNIC " << cnic << ".\033[0m" << endl;
        cout << endl;
        return false;
    }

    void purchaseProduct(const string &buyerCNIC)
    {
        string storeCNIC;
        int productID, quantity;

        // Validate Buyer
        if (buyers.find(buyerCNIC) == buyers.end())
        {
            cout << "Buyer not found. Please register or login first.\n";
            return;
        }
        Buyer &buyer = buyers[buyerCNIC];

        // Select Store
        cout << endl;
        cout << "Available Stores.\n";
        DisplayStores();
        cout << endl;
        cout << "Enter the CNIC of the store you want to purchase from: ";
        cin >> storeCNIC;

        // Find Store
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << "Store not found.\n";
            return;
        }
        Store &store = stores[storeCNIC];

        system("cls");
        // Input Product Details
        cout << endl;
        cout << "Products in Store.\n";
        displayProducts(storeCNIC);
        cout << endl;

        cout << "Enter the Product ID: ";
        productID = ValidatePriceIdQuantity<int>();

        cout << "Enter the quantity you want to purchase: ";
        quantity = ValidatePriceIdQuantity<int>();

        while (quantity <= 0)
        {
            cout << endl;
            cout << "Purchasing Quanity cannot be negative , or 0." << endl;
            cout << "Kindly enter a valid quantity to purchase." << endl;
            cout << endl;
            cout << "Enter the quantity you want to purchase: ";
            quantity = ValidatePriceIdQuantity<int>();
        }

        // Find Product
        if (store.inventory.find(productID) == store.inventory.end())
        {
            cout << "Product not found.\n";
            return;
        }
        Product &product = store.inventory[productID];

        if (quantity > product.quantity)
        {
            cout << "Requested quantity exceeds available stock.\n";
            return;
        }

        // Calculate Total Cost
        float totalCost = product.price * quantity;

        if (buyer.balance < totalCost)
        {
            cout << "Insufficient balance. Transaction failed.\n";
            return;
        }

        // Update Balances
        buyer.balance -= totalCost;
        store.earnings += totalCost;

        // Update Product Quantity
        product.quantity -= quantity;
        product.sold += quantity;
        system("cls");
        cout << "Purchase successful! Total cost: " << totalCost << ". Remaining balance: " << buyer.balance << ".\n";
    }

    void displayBuyerBalance(const string &cnic)
    {
        float updatedBalance;
        int choice;
        // Check if buyer exists in the unordered_map
        if (buyers.find(cnic) != buyers.end())
        {
            const Buyer &buyer = buyers[cnic];
            cout << endl;
            cout << "Hello, " << buyer.name << "!" << endl;
            cout << endl;
            cout << "Your CNIC is: " << buyer.cnic << endl;
            cout << endl;
            cout << "Your current balance is: $" << fixed << setprecision(2) << buyer.balance << endl;
            cout << endl;
            if (buyer.balance < 50)
            {
                cout << endl;
                cout << "Your balance is Below 50$." << endl;
                cout << "Do you want to update your balance ? " << endl;
                cout << endl;
                cout << "1. Yes" << endl;
                cout << "0. No" << endl;
                cout << endl;
                cout << "Enter your choice: ";
                choice = _getch() - '0';
                switch (choice)
                {
                case 1:
                    system("cls");
                    cout << "Enter the amount you want to add to your balance: ";
                    cin >> updatedBalance;

                    while (updatedBalance < buyer.balance)
                    {
                        cout << endl;
                        cout << "You think you are smart?" << endl;
                        cout << "Your Current Balance is " << buyer.balance << "$" << endl;
                        cout << "You want to add balance of " << updatedBalance << "$" << endl;
                        cout << "Kindly Enter a valid Balance!" << endl;
                        cout << endl;
                        cout << "Enter Initial Balance: ";
                        cin >> updatedBalance;
                    }

                    while (updatedBalance <= 0)
                    {
                        cout << endl;
                        cout << "Balance cannot be negative , or 0" << endl;
                        cout << "Kindly Enter a valid Balance" << endl;
                        cout << endl;
                        cout << "Enter Initial Balance: ";
                        cin >> updatedBalance;
                    }

                    buyers[cnic].balance += updatedBalance;
                    system("cls");
                    cout << endl;
                    cout << "Balance Updated Successfully!" << endl;
                    cout << "Your new balance is: $" << fixed << setprecision(2) << buyers[cnic].balance << endl;
                    cout << endl;
                    break;
                case 0:
                    cout << endl;
                    system("cls");
                    cout << "Returning Back!" << endl;
                    cout << endl;
                    break;
                default:
                    cout << endl;
                    cout << "Invalid Input!" << endl;
                    cout << endl;
                    break;
                }
            }
        }
        else
        {
            cout << endl;
            cout << "Error: Buyer with CNIC " << cnic << " not found!" << endl;
            cout << endl;
        }
    }
};

#pragma once