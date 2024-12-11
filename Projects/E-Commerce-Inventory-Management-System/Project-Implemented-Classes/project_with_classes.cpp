#include <iostream>
#include <iomanip> // For setting width and setting precision
#include <unordered_map>
#include <stack>
#include <cstdlib> //for adding colors to the font!
#include <string>
using namespace std;

class ClassOfUsers
{
protected:
    bool virtual Register() = 0;
    bool virtual Login() = 0;
    void virtual Menu() = 0;
};

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
};

class Functions_Of_Stores_Related_Products : virtual protected ClassOfProducts
{
protected:
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
    unordered_map<string, Store> stores; // Keyed by Store CNIC

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
        cout << "Enter Quantity: ";
        cin >> quantity;

        // Add product to the inventory
        store.inventory[id] = {id, name, category, price, quantity, 0};

        cout << "Product added successfully!\n";
    }

    void UpdateProductsQuantity(string storeCNIC)
    {
        int id, quantity;

        // Check if store exists
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << "Store not found.\n";
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

    void deleteProduct(string storeCNIC)
    {
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
        int productID;
        cout << "Please Enter product id : ";
        cin >> productID;

        // Check if product exists in the inventory
        if (store.inventory.find(productID) == store.inventory.end())
        {
            cout << "Product not found in the store's inventory.\n";
            return;
        }

        // Remove the product from the inventory
        store.inventory.erase(productID);
        cout << "Product with ID " << productID << " deleted successfully from the store '" << store.storeName << "'.\n";
    }

    bool displayProducts(string storeCNIC)
    {
        // Check if store exists
        if (stores.find(storeCNIC) == stores.end())
        {
            cout << "Store not found!\n";
            return false;
        }

        const Store &store = stores[storeCNIC];

        if (store.inventory.empty())
        {
            cout << "No products available in the store.\n";
            return false;
        }

        // Display all products
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

class Functions_Of_Stores_Related_Stores : virtual protected ClassOfProducts, virtual protected Functions_Of_Stores_Related_Products
{
    protected:
        string storeName, ownerName, cnic, password;
public:
    bool Register()
    {
        cout << "Enter Store Name: ";
        cin >> storeName;
        cout << "Enter Owner Name: ";
        cin >> ownerName;
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
        cin >> password;

        // Add the new store to the unordered_map
        Store newStore = {storeName, ownerName, cnic, password}; // Initialize explicitly
        stores[cnic] = newStore;
        cout << "Store registered successfully!\n";
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
            cout << "Store with CNIC " << storeCNIC << " not found.\n";
            return;
        }

        // Get the store
        Store &store = stores[storeCNIC];

        // Clear the store's inventory
        store.inventory.clear();

        // Erase the store from the unordered_map
        stores.erase(storeCNIC);

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

class ClassOfBuyer : protected Functions_Of_Stores_Related_Stores, virtual protected ClassOfUsers
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
    void Menu() 
    {
        string storeCNIC, buyerCNIC = "";

        int choice;
        do
        {
            cout << "\nBuyer Menu\n";
            cout << "1. Register as Buyer\n";
            cout << "2. Login as Buyer\n";
            cout << "0. Return\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                Register();
                break;
            case 2:
                if (!Login())
                {
                    break;
                }
                cout << endl;
                int subChoice;
                do
                {
                    cout << "1. View Stores\n";
                    cout << "2. Rate a Store\n";
                    cout << "3. Check Account Balance\n";
                    cout << "0. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice)
                    {
                    case 1:
                        if (!DisplayStores())
                        {
                            break;
                        }
                        cout << "Enter Store CNIC to view products: ";
                        cin >> storeCNIC;
                        if (!displayProducts(storeCNIC))
                        {
                            break;
                        }
                        cout << "Enter your CNIC to proceed: ";
                        cin >> buyerCNIC;
                        purchaseProduct(buyerCNIC);
                        break;
                    case 2:
                        // giveRatingToStore(buyerCNIC);
                        break;
                    case 3:
                        cout << "Enter your CNIC of your Buyer account: ";
                        cin >> buyerCNIC;
                        displayBuyerBalance(buyerCNIC);
                        break;
                    case 0:
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

    bool Register()
    {
        string name, cnic, password;
        float balance;

        // Input buyer details
        cout << "Enter Buyer Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        cout << "Enter Buyer CNIC: ";
        cin >> cnic;
        cout << "Enter Your Password: ";
        cin >> password;
        cout << "Enter Initial Balance: ";
        cin >> balance;

        // Check if buyer with the same CNIC already exists
        if (buyers.find(cnic) != buyers.end())
        {
            cout << "Buyer with CNIC " << cnic << " already exists!\n";
            return false;
        }

        // Add the new buyer to the unordered_map
        buyers[cnic] = {name, cnic, password, balance};

        cout << "Buyer registered successfully!\n";
        return true;
    }

    bool Login()
    {
        string cnic, password;

        // Input CNIC
        cout << "Enter your CNIC to login: ";
        cin >> cnic;

        // Search for the buyer
        if (buyers.find(cnic) != buyers.end())
        {
            // Buyer found, ask for password
            Buyer &buyer = buyers[cnic];
            cout << "Enter your password: ";
            cin >> password;

            if (buyer.password == password)
            {
                cout << "Login successful! Welcome, " << buyer.name << ".\n";
                return true; // Exit on successful login
            }
            else
            {
                cout << "Incorrect password! Login failed.\n";
                return false;
            }
        }

        // If buyer not found
        cout << "Login failed! No buyer found with CNIC " << cnic << ".\n";
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
        cout << "Available Stores:\n";
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

        // Input Product Details
        cout << "Products in Store:\n";
        cout << endl;
        displayProducts(storeCNIC);
        cout << endl;

        cout << "Enter the Product ID: ";
        cin >> productID;
        cout << "Enter the quantity you want to purchase: ";
        cin >> quantity;

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

        cout << "Purchase successful! Total cost: " << totalCost << ". Remaining balance: " << buyer.balance << ".\n";
    }

    void displayBuyerBalance(const string &cnic)
    {
        // Check if buyer exists in the unordered_map
        if (buyers.find(cnic) != buyers.end())
        {
            const Buyer &buyer = buyers[cnic];
            cout << "Hello, " << buyer.name << "!" << endl;
            cout << "Your current balance is: $" << fixed << setprecision(2) << buyer.balance << endl;
        }
        else
        {
            cout << "Error: Buyer with CNIC " << cnic << " not found!" << endl;
        }
    }
};

class ClassOfAdmin : protected Functions_Of_Stores_Related_Stores
{
protected:
        string cnic;
        int choice;
public:
    void Menu() 
    {
        do
        {
            cout << "\nAdmin Menu\n";
            cout << "1. Add Store\n";
            cout << "2. View All Stores\n";
            cout << "3. Delete a Store\n";
            cout << "4. Delete all Stores\n";
            cout << "5. Send message to a store\n";
            cout << "0. Logout\n";
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                Register();
                break;
            case 2:
                DisplayStores();
                break;
            case 3:
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
                deleteAllStores();
                break;
            case 5:
                if (!DisplayStores())
                {
                    break;
                }
                sendMessageToSeller();
                break;
            case 0:
                cout << "Logging out..." << endl;
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 0);
    }

    void sendMessageToSeller()
    {
        string cnic, message;
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

class ClassOfSeller : virtual Functions_Of_Stores_Related_Products, protected Functions_Of_Stores_Related_Stores
{
public:
    void Menu() 
    {
        int choice;
        do
        {
            cout << "\nSeller Menu\n";
            cout << "1. Register a Store\n";
            cout << "2. Login to Store\n";
            cout << "0. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                Register();
                break;
            }
            case 2:
            {
                string storeCNIC, storePassword;
                bool isLoggedIn = false;
                Store *store = nullptr;

                do
                {
                    cout << "Enter Store CNIC: ";
                    cin >> storeCNIC;

                    // Search for the store in unordered_map
                    auto storeIt = stores.find(storeCNIC);
                    if (storeIt == stores.end())
                    {
                        cout << "Store not found! Please check your CNIC.\n";
                        break;
                    }

                    store = &storeIt->second;

                    cout << "Enter Store Password: ";
                    cin >> storePassword;

                    if (store->password != storePassword)
                    {
                        cout << "Incorrect password! Please try again.\n";
                    }
                    else
                    {
                        cout << "Login Successful!\n";
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
                        cout << "1. Add Product\n";
                        cout << "2. View Products\n";
                        cout << "3. Delete a Product\n";
                        cout << "4. View Earnings\n";
                        cout << "5. View Messages from Admin\n";
                        cout << "0. Logout\n";
                        cout << "Enter your choice: ";
                        cin >> storeChoice;

                        switch (storeChoice)
                        {
                        case 1:
                            addProduct(storeCNIC);
                            break;
                        case 2:
                            displayProducts(storeCNIC);
                            break;
                        case 3:
                            deleteProduct(storeCNIC);
                            break;
                        case 4:
                            cout << "Store Earnings: $" << store->earnings << endl;
                            break;
                        case 5:
                            viewMessagesForSeller(storeCNIC);
                            break;
                        case 0:
                            cout << "Logging out...\n";
                            break;
                        default:
                            cout << "Invalid choice! Please try again.\n";
                        }
                    } while (storeChoice != 0);
                }
                break;
            }
            case 0:
                cout << "Returning to main menu...\n";
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

int main()
{
    ClassOfBuyer *NewBuyer = new ClassOfBuyer();    
    ClassOfAdmin *NewAdmin = new ClassOfAdmin();
    ClassOfSeller *NewSeller = new ClassOfSeller();
    int choice;
    do
    {
        cout << "\n\033[36mE-Commerce Inventory Management System\033[0m\n"; // Cyan for heading
        cout << endl;
        cout << "\033[32m1. Admin\033[0m\n";  // Green
        cout << "\033[35m2. Seller\033[0m\n"; // Magenta
        cout << "\033[33m3. Buyer\033[0m\n";  // Yellow
        cout << "\033[31m0. Exit\033[0m\n";   // Red for exit
        cout << endl;
        cout << "\033[96mEnter your choice: \033[0m"; // Bright Cyan
        cin >> choice;

        switch (choice)
        {
        case 1:

            NewAdmin->Menu();
            break;
        case 2:
            NewSeller->Menu();
            break;
        case 3:
            NewBuyer->Menu();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << endl;
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}