#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <stdexcept>

using namespace std;

struct Transaction
{
    string type; // "Deposit" or "Withdraw"
    double amount;
    string timestamp;
    Transaction *next; // Pointer for a linked list of transactions
};

struct Account
{
    string AccountNumber;
    string AccountName;
    double AccountBalance;
    bool isFrozen;
    string Password;
    Transaction *transactionHead = nullptr;
    double LoanAmount = 0.0;
    double LoanLimit = 50000.0;
    Account *next;
};

class BankManagementSystem
{
protected:
    Account *head;
    string DataFile;
    char ch;         // used for password input
    string Password; // used for password input
    double balance;
    string AccountNumber;

public: // Constructor
    string ConfirmAccountNumber();
    string ConfirmPassword();
    BankManagementSystem() : head(NULL), DataFile("AccountsInfo.txt") {}

    void AddTransaction(Account *account, const string &type, double amount)
    {
        Transaction *newTransaction = new Transaction();
        newTransaction->type = type;
        newTransaction->amount = amount;

        // Generate a simple timestamp (for simplicity)
        time_t now = time(0);
        newTransaction->timestamp = ctime(&now);
        newTransaction->timestamp.pop_back(); // Remove newline character

        newTransaction->next = nullptr;

        if (account->transactionHead == nullptr)
        {
            account->transactionHead = newTransaction;
        }
        else
        {
            Transaction *temp = account->transactionHead;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newTransaction;
        }
    }

    void SeeTransactionHistory()
    {
        string AccountNumber;
        string Password;

        AccountNumber = ConfirmAccountNumber();
        cout << endl;
        Password = ConfirmPassword();

        Account *account = FindAccountUser(AccountNumber, Password);
        if (account != nullptr)
        {
            cout << endl;
            cout << "Transaction History for Account Number: " << account->AccountNumber << endl;
            cout << "--------------------------------" << endl;

            Transaction *current = account->transactionHead;
            if (current == nullptr)
            {
                cout << "No transactions available!" << endl;
            }
            else
            {
                while (current != nullptr)
                {
                    cout << "--------------------------------" << endl;
                    cout << "Type: " << current->type << endl;
                    cout << "Amount: " << current->amount << endl;
                    cout << "Date: " << current->timestamp << endl;
                    cout << "--------------------------------" << endl;
                    current = current->next;
                }
            }
        }
        else
        {
            cout << "Account not found or invalid password!" << endl;
        }
    }

    void AddAccount()
    {
        Account *newAccount = new Account();

        AccountNumber = ConfirmAccountNumber();

        newAccount->AccountNumber = AccountNumber;

        if (IsAccountNumberUnique(newAccount->AccountNumber))
        {
            cout << "\nEnter Account Name: ";
            cin.ignore();
            getline(cin, newAccount->AccountName);

            Password = ConfirmPassword();

            newAccount->Password = Password;

            cout << "Enter Balance: ";
            cin >> balance;

            while (balance <= 0)
            {
                cout << "Balance cannot be negative!" << endl;
                cout << "Enter Balance: ";
                cin >> balance;
            }
            newAccount->AccountBalance = balance;

            newAccount->next = nullptr;

            if (head == nullptr)
            {
                head = newAccount;
            }

            else
            {
                Account *temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newAccount;
            }
            cout << endl;
            cout << "Account Added Successfully!" << endl;
            cout << endl;
            SaveAccountsToFile();
        }
        else
        {
            cout << endl;
            cout << "\nAccount Number already exists!" << endl;
            cout << endl;
            delete newAccount; // memory deallocation
        }
    }

    bool IsAccountNumberUnique(const string &AccountNumber)
    {
        Account *current = head;
        while (current != nullptr)
        {
            if (current->AccountNumber == AccountNumber)
            {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    Account *FindAccountUser(const string &AccountNumber, const string &Password)
    {
        Account *current = head;
        while (current != nullptr)
        {
            if (current->AccountNumber == AccountNumber && current->Password == Password)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void SearchAccount()
    {
        string AccountNumber;
        string Password;

        AccountNumber = ConfirmAccountNumber();
        Password = ConfirmPassword();

        Account *account = FindAccountUser(AccountNumber, Password);

        if (account != nullptr)
        {
            cout << endl;
            cout << "Account Found!" << endl;
            cout << endl;
            cout << "---------------------------------" << endl;
            cout << "Account Number: " << account->AccountNumber << endl;
            cout << "Account Name: " << account->AccountName << endl;
            cout << "Account Balance: " << account->AccountBalance << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "Account not found!" << endl;
            cout << endl;
        }
    }

    void DepositFunds()
    {
        string AccountNumber;
        string Password;
        double Amount;

        AccountNumber = ConfirmAccountNumber();
        cout << endl;
        Password = ConfirmPassword();

        Account *account = FindAccountUser(AccountNumber, Password);
        if (account->isFrozen)
        {
            cout << "This account is frozen. No transactions allowed." << endl;
            return;
        }

        if (account != nullptr)
        {
            cout << "Enter Amount to Deposit: ";
            cin >> Amount;

            while (Amount <= 0)
            {
                cout << "Amount cannot be negative!" << endl;
                cout << "Enter Amount to Deposit: ";
                cin >> Amount;
            }

            account->AccountBalance += Amount;
            AddTransaction(account, "Deposit", Amount);
            cout << endl;
            cout << "Amount Deposited Successfully!" << endl;
            cout << endl;
            SaveAccountsToFile();
        }
        else
        {
            cout << "Account not found or invalid password!" << endl;
        }
    }

    void WithDrawAmountFromAccount()
    {
        string AccountNumber;
        string Password;
        double Amount;

        AccountNumber = ConfirmAccountNumber();
        cout << endl;
        Password = ConfirmPassword();

        Account *account = FindAccountUser(AccountNumber, Password);
        if (account->isFrozen)
        {
            cout << "This account is frozen. No transactions allowed." << endl;
            return;
        }

        if (account != nullptr)
        {
            cout << endl;
            cout << "Current Balance: " << account->AccountBalance << endl;
            cout << endl;
            cout << "Enter Amount to Withdraw: ";
            cin >> Amount;

            while (Amount <= 0)
            {
                cout << "Amount cannot be negative!" << endl;
                cout << "Enter Amount to Withdraw: ";
                cin >> Amount;
            }

            if (account->AccountBalance >= Amount)
            {
                account->AccountBalance -= Amount;
                AddTransaction(account, "Withdraw", Amount); // Add transaction
                cout << "Amount Withdrawn Successfully!" << endl;
                SaveAccountsToFile();
            }
            else
            {
                cout << "Insufficient Balance!" << endl;
            }
        }
        else
        {
            cout << "Account not found or invalid password!" << endl;
        }
    }

    void DisplayAccounts()
    {
        Account *current = head;
        cout << endl;
        cout << "All Registered Accounts Information " << endl;
        cout << endl;

        if (current == nullptr)
        {
            cout << "No accounts found!" << endl;
            return;
        }
        while (current != nullptr)
        {
            cout << "--------------------------------" << endl;
            cout << "Account Number: " << current->AccountNumber << endl;
            cout << "Account Name: " << current->AccountName << endl;
            cout << "Account Balance: " << current->AccountBalance << endl;
            cout << "Status: " << (current->isFrozen ? "Frozen" : "Active") << endl;
            cout << "Loan Amount: " << current->LoanAmount << endl;
            cout << "Loan Limit: " << current->LoanLimit << endl;
            cout << "--------------------------------" << endl;
            current = current->next;
        }
        cout << endl;
    }

    void SaveAccountsToFile()
    {
        ofstream OutputFile(DataFile.c_str());

        if (OutputFile.is_open())
        {
            Account *current = head;
            while (current != nullptr)
            {
                // Save account details
                OutputFile << current->AccountNumber << "," << current->AccountName << ","
                           << current->Password << "," << current->AccountBalance << "," << current->isFrozen << "," << current->LoanAmount << "," << current->LoanLimit;

                // Save transactions
                Transaction *transaction = current->transactionHead;
                if (transaction != nullptr)
                {
                    OutputFile << ",[";
                    while (transaction != nullptr)
                    {
                        OutputFile << transaction->type << ";" << transaction->amount << ";" << transaction->timestamp;
                        if (transaction->next != nullptr)
                        {
                            OutputFile << "|"; // Delimiter for transactions
                        }
                        transaction = transaction->next;
                    }
                    OutputFile << "]";
                }

                OutputFile << endl; // End of account line
                current = current->next;
            }
            OutputFile.close();
            cout << "Accounts and Transactions Saved Successfully!" << endl;
        }
        else
        {
            cout << "Error: Unable to save accounts and transactions!" << endl;
        }
    }

    void LoadAccountsFromFile()
    {
        ifstream InputFile(DataFile.c_str());

        if (InputFile.is_open())
        {
            string line;

            while (getline(InputFile, line))
            {
                stringstream ss(line);
                string AccountNumber, AccountName, Password, BalanceString, IsFrozenString, LoanAmountString, LoanLimitString;
                string TransactionsString;

                // Extract account details
                getline(ss, AccountNumber, ',');
                getline(ss, AccountName, ',');
                getline(ss, Password, ',');
                getline(ss, BalanceString, ',');
                getline(ss, IsFrozenString, ',');
                getline(ss, LoanAmountString, ',');
                getline(ss, LoanLimitString, ',');

                try
                {
                    double AccountBalance = stod(BalanceString);
                    bool IsFrozen = (IsFrozenString == "1"); // Convert "1" to true, "0" to false
                    double LoanAmount = stod(LoanAmountString);
                    double LoanLimit = stod(LoanLimitString);

                    // Check if account already exists
                    if (accountExists(AccountNumber))
                    {
                        cout << "Account " << AccountNumber << " already exists. Skipping load." << endl;
                        continue; // Skip this account if it already exists
                    }

                    // Create a new account object
                    Account *newAccount = new Account();
                    newAccount->AccountNumber = AccountNumber;
                    newAccount->AccountName = AccountName;
                    newAccount->Password = Password;
                    newAccount->AccountBalance = AccountBalance;
                    newAccount->isFrozen = IsFrozen;
                    newAccount->LoanAmount = LoanAmount;
                    newAccount->LoanLimit = LoanLimit;
                    newAccount->transactionHead = nullptr;

                    // Load transaction history if present
                    size_t transactionStart = line.find('[');
                    size_t transactionEnd = line.find(']');
                    if (transactionStart != string::npos && transactionEnd != string::npos)
                    {
                        string transactionsData = line.substr(transactionStart + 1, transactionEnd - transactionStart - 1);

                        stringstream ts(transactionsData);
                        string transaction;

                        // Parse each transaction
                        while (getline(ts, transaction, '|'))
                        {
                            stringstream transactionDetails(transaction);
                            string type, amountString, timestamp;

                            getline(transactionDetails, type, ';');
                            getline(transactionDetails, amountString, ';');
                            getline(transactionDetails, timestamp, ';');

                            // Create a new transaction object
                            Transaction *newTransaction = new Transaction();
                            newTransaction->type = type;
                            newTransaction->amount = stod(amountString);
                            newTransaction->timestamp = timestamp;
                            newTransaction->next = nullptr;

                            // Add transaction to the linked list
                            if (newAccount->transactionHead == nullptr)
                            {
                                newAccount->transactionHead = newTransaction;
                            }
                            else
                            {
                                Transaction *temp = newAccount->transactionHead;
                                while (temp->next != nullptr)
                                {
                                    temp = temp->next;
                                }
                                temp->next = newTransaction;
                            }
                        }
                    }

                    // Add account to the linked list
                    if (head == nullptr)
                    {
                        head = newAccount;
                    }
                    else
                    {
                        Account *temp = head;
                        while (temp->next != nullptr)
                        {
                            temp = temp->next;
                        }
                        temp->next = newAccount;
                    }
                }
                catch (const invalid_argument &e)
                {
                    cout << "Error: Invalid data format in file: " << e.what() << endl;
                    continue; // Skip to the next line
                }
                catch (const out_of_range &e)
                {
                    cout << "Error: Data out of range in file: " << e.what() << endl;
                    continue; // Skip to the next line
                }
            }

            InputFile.close();
            cout << "Accounts and Transactions Loaded Successfully!" << endl;
        }
        else
        {
            cout << "Error: Unable to load accounts and transactions!" << endl;
        }
    }

    // Function to check if account already exists based on AccountNumber
    bool accountExists(const string &AccountNumber)
    {
        Account *temp = head;
        while (temp != nullptr)
        {
            if (temp->AccountNumber == AccountNumber)
            {
                return true; // Account already exists
            }
            temp = temp->next;
        }
        return false; // Account does not exist
    }

    // Then use this check in the LoadAccountsFromFile() function
};

string BankManagementSystem ::ConfirmAccountNumber()
{
    string AccountNumber;
    char ch;
    cout << "Enter Account Number: ";

    while (true)
    {
        ch = _getch(); // Get a single character without requiring Enter

        if (ch == '\b')
        { // Backspace key (ASCII 8)
            if (!AccountNumber.empty())
            {
                AccountNumber.pop_back(); // Remove the last character from the string
                cout << "\b \b";          // Move back, print a space to overwrite, then move back again
            }
        }
        else if (ch == '\r')
        { // Enter key (ASCII 13)
            if (AccountNumber.length() != 9)
            {
                cout << endl;
                cout << "\nYour Account Number Length cannot be " << AccountNumber.length() << endl;
                cout << "Please enter an 9 digit AccountNumber number!" << endl;
                cout << endl;
                cout << "Enter Account Number : ";
                AccountNumber.clear();
            }

            else if (AccountNumber > "999999999" || AccountNumber < "100000000")
            {
                cout << endl;
                cout << "\nYour AccountNumber cannot be less than 100000000 or greater than 999999999!" << endl;
                cout << endl;
                cout << "Kindly Enter 9 Digit AccountNumber Number : ";
                AccountNumber.clear();
            }

            else
            {
                break;
            }
        }
        else if (isalpha(ch))
        { // Check if the character is an alphabet
            cout << endl;
            cout << "\nYour Account Number Cannot Include Alphabets!" << endl;
            cout << "Kindly Enter Only Numbers!" << endl;
            cout << endl;
            cout << "Please Enter Valid AccountNumber : ";
            AccountNumber.clear(); // Clear the AccountNumber buffer
        }
        else if (AccountNumber.length() == 9)
        {
            cout << endl;
            cout << "\nYour AccountNumber cannot Greater than 9 numbers!" << endl;
            cout << "Kindly Only 9 Digit AccountNumber Number " << endl;
            cout << endl;
            cout << "Enter Account Number: ";
            AccountNumber.clear();
        }
        else
        {
            AccountNumber += ch; // Append character to the AccountNumber
            cout << ch;          // Echo the character
        }
    }
    return AccountNumber;
}

string BankManagementSystem ::ConfirmPassword()
{
    string Password;
    char ch;
    cout << "Enter Password: ";
    while (true)
    {
        ch = _getch();

        if (ch == '\r')
        {
            if (Password.length() < 8)
            {
                cout << endl;
                cout << "\nYour password length cannot be " << Password.length() << "!" << endl;
                cout << "Sir your password length should be 8 or more than 8 characters!" << endl;
                cout << endl;
                cout << "Enter Password : ";
                Password.clear();
            }

            else
            {
                cout << endl;
                break;
            }
        }
        else if (ch == '\b')
        {
            if (!Password.empty())
            {
                Password.pop_back();
                cout << "\b \b";
            }
        }

        else
        {
            Password.push_back(ch);
            cout << "*";
        }
    }
    return Password;
}

class Admin : public BankManagementSystem
{
private:
public:
    void AdminPanel()
    {
        LoadAccountsFromFile();
        DisplayAccounts();
        string accountNumber;
        int choice;

        cout << "1. Freeze Account" << endl;
        cout << "2. Activate Account" << endl;
        cout << "3. return" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 3)
        {
            cout << "Exiting admin panel." << endl;
            return;
        }

        cout << "Enter Account Number to manage: ";
        cin >> accountNumber;
        Account *account = FindAccount(accountNumber);

        if (account == nullptr)
        {
            cout << "Account not found!" << endl;
            return;
        }

        switch (choice)
        {
        case 1:
            FreezeAccount(account);
            break;
        case 2:
            ActivateAccount(account);
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
            ;
        }
        SaveAccountsToFile();
    }

    void FreezeAccount(Account *account)
    {
        if (account != nullptr && !account->isFrozen)
        {
            account->isFrozen = true;
            cout << "Account " << account->AccountNumber << " is now frozen." << endl;
        }
        else
        {
            cout << "Account is already frozen or not found." << endl;
        }
    }

    void ActivateAccount(Account *account)
    {
        if (account != nullptr && account->isFrozen)
        {
            account->isFrozen = false;
            cout << "Account " << account->AccountNumber << " is now active." << endl;
        }
        else
        {
            cout << "Account is already active or not found." << endl;
        }
    }

    Account *FindAccount(const string &AccountNumber)
    {
        Account *current = head;
        while (current != nullptr)
        {
            if (current->AccountNumber == AccountNumber)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void TakeLoan()
    {
        string AccountNumber;
        AccountNumber = ConfirmAccountNumber();
        cout << endl;
        string Password;
        Password = ConfirmPassword();

        //check if frozen

        Account *account = FindAccountUser(AccountNumber, Password);

        if (account->isFrozen)
        {
            cout << "This account is frozen. No transactions allowed." << endl;
            return;
        }

        if (account == nullptr)
        {
            cout << "Account not found!" << endl;
            return;
        }

        if (account->isFrozen)
        {
            cout << "Loan cannot be taken as the account is frozen!" << endl;
            return;
        }

        cout << "Current Loan Amount: " << account->LoanAmount << endl;
        cout << "Maximum Loan Limit: " << account->LoanLimit << endl;

        double loanRequest;
        cout << "Enter loan amount to request: ";
        cin >> loanRequest;

        if (loanRequest <= 0)
        {
            cout << "Invalid loan amount!" << endl;
            return;
        }

        if (account->LoanAmount + loanRequest > account->LoanLimit)
        {
            cout << "Loan request exceeds the maximum loan limit!" << endl;
            return;
        }

        account->LoanAmount += loanRequest;
        account->AccountBalance += loanRequest;

        cout << "Loan approved! Your account has been credited with " << loanRequest << endl;
        cout << "Updated Loan Amount: " << account->LoanAmount << endl;
        cout << "Updated Account Balance: " << account->AccountBalance << endl;

        SaveAccountsToFile(); // Save updated data to file
    }

    void RepayLoan()
    {
        string AccountNumber;
        AccountNumber = ConfirmAccountNumber();
        cout << endl;
        string Password;
        Password = ConfirmPassword();

        Account *account = FindAccountUser(AccountNumber, Password);

        if (account->isFrozen)
        {
            cout << "This account is frozen. No transactions allowed." << endl;
            return;
        }

        if (account == nullptr)
        {
            cout << "Account not found!" << endl;
            return;
        }

        if (account->LoanAmount <= 0)
        {
            cout << "You currently have no loan to repay!" << endl;
            return;
        }

        // Show the current loan details
        cout << "-----------------------------------" << endl;
        cout << "Your Current Loan Amount: " << account->LoanAmount << endl;
        cout << "Your Account Balance: " << account->AccountBalance << endl;
        cout << "-----------------------------------" << endl;

        double repaymentAmount;
        cout << "Enter the amount you wish to repay: ";
        cin >> repaymentAmount;

        // Validate repayment amount
        if (repaymentAmount <= 0)
        {
            cout << "Invalid repayment amount! It must be greater than zero." << endl;
            return;
        }

        if (repaymentAmount > account->AccountBalance)
        {
            cout << "Insufficient balance! Your current balance is: " << account->AccountBalance << endl;
            return;
        }

        if (repaymentAmount > account->LoanAmount)
        {
            repaymentAmount = account->LoanAmount; // Cap repayment to the outstanding loan amount
            cout << "Repayment amount exceeds your outstanding loan. Adjusted to: " << repaymentAmount << endl;
        }

        // Process repayment
        account->LoanAmount -= repaymentAmount;
        account->AccountBalance -= repaymentAmount;

        // Display updated loan and balance information
        cout << "-----------------------------------" << endl;
        cout << "Repayment Successful!" << endl;
        cout << "Remaining Loan Amount: " << account->LoanAmount << endl;
        cout << "Updated Account Balance: " << account->AccountBalance << endl;
        cout << "-----------------------------------" << endl;

        SaveAccountsToFile(); // Save updated account data to the file
    }

    void Menu()
    {
        LoadAccountsFromFile();

        int choice;
        while (true)
        {
            cout << endl;
            cout << "1. Add Account" << endl;
            cout << "2. Search Account" << endl;
            cout << "3. Deposit Funds" << endl;
            cout << "4. Withdraw Funds" << endl;
            cout << "5. Display All Accounts" << endl;
            cout << "6. See Transaction History" << endl;
            cout << "7. Take Loan" << endl;
            cout << "8. Repay Loan" << endl;
            cout << "9. Exit" << endl;
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                AddAccount();
                break;
            case 2:
                SearchAccount();
                break;
            case 3:
                DepositFunds();
                break;
            case 4:
                WithDrawAmountFromAccount();
                break;
            case 5:
                DisplayAccounts();
                break;
            case 6:
                SeeTransactionHistory();
                break;
            case 7:
                TakeLoan();
                break;
            case 8:
                RepayLoan();
                break;
            case 9:
                SaveAccountsToFile();
                cout << "Thank you for using Bank Management System!" << endl;
                cout << endl;
                return;
            default:
                cout << "Invalid choice! Please enter a valid choice: ";
                break;
            }
        }
    }
};

int main()
{
    cout << "Welcome to Bank Management System" << endl;
    cout << endl;

    Admin *admin = new Admin();

    int choice;
    while (true)
    {
        cout << "1. User Panel" << endl;
        cout << "2. Admin Panel" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl;
            admin->Menu();
            break;
        case 2:
            cout << endl;
            admin->AdminPanel();
            break;
        case 3:
            cout << "Thank you for using Bank Management System!" << endl;
            cout << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice! Please enter a valid choice: ";
            break;
        }
    }
    return 0;
}