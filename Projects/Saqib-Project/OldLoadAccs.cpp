#include<iostream>
using namespace std;

// void LoadAccountsFromFile()
    // {
    //     ifstream InputFile(DataFile.c_str());

    //     if (InputFile.is_open())
    //     {
    //         string line;

    //         while (getline(InputFile, line))
    //         {
    //             stringstream ss(line);
    //             string AccountNumber;
    //             string AccountName;
    //             string Password;
    //             double AccountBalance;

    //             getline(ss, AccountNumber, ',');
    //             getline(ss, AccountName, ',');
    //             getline(ss, Password, ',');
    //             ss >> AccountBalance;

    //             Account *newAccount = new Account();
    //             newAccount->AccountNumber = AccountNumber;
    //             newAccount->AccountName = AccountName;
    //             newAccount->Password = Password;
    //             newAccount->AccountBalance = AccountBalance;
    //             newAccount->next = nullptr;

    //             if (head == nullptr)
    //             {
    //                 head = newAccount;
    //             }
    //             else
    //             {
    //                 Account *temp = head;
    //                 while (temp->next != nullptr)
    //                 {
    //                     temp = temp->next;
    //                 }
    //                 temp->next = newAccount;
    //             }
    //         }
    //         InputFile.close();

    //         cout << endl;
    //         cout << "\t\t\t Accounts Information Loaded Successfully!" << endl;
    //         cout << endl;
    //         cout << endl;
    //     }
    //     else
    //     {
    //         cout << "Error: Unable to load accounts information!" << endl;
    //     }
    // }

    // void LoadAccountsFromFile()
    // {
    //     ifstream InputFile(DataFile.c_str());

    //     if (InputFile.is_open())
    //     {
    //         string line;

    //         while (getline(InputFile, line))
    //         {
    //             stringstream ss(line);
    //             string AccountNumber, AccountName, Password, BalanceString, TransactionsString , LoanAmountString, LoanLimitString;
    //             bool IsFrozen;
    //             double LoanAmount, LoanLimit;

    //             // Extract account details
    //             getline(ss, AccountNumber, ',');
    //             getline(ss, AccountName, ',');
    //             getline(ss, Password, ',');
    //             getline(ss, BalanceString, ',');

    //             ss >> IsFrozen >> LoanAmount >> LoanLimit;

    //             double AccountBalance = stod(BalanceString);
    //             LoanLimit = stod(LoanLimitString);
    //             LoanAmount = stod(LoanAmountString);

    //             // Create a new account object
    //             Account *newAccount = new Account();
    //             newAccount->AccountNumber = AccountNumber;
    //             newAccount->AccountName = AccountName;
    //             newAccount->Password = Password;
    //             newAccount->AccountBalance = AccountBalance;
    //             newAccount->isFrozen = IsFrozen;
    //             newAccount->LoanAmount = LoanAmount;
    //             newAccount->LoanLimit = LoanLimit;
    //             newAccount->transactionHead = nullptr;

    //             // Load transaction history if present
    //             if (line.find('[') != string::npos)
    //             {
    //                 size_t start = line.find('[') + 1;
    //                 size_t end = line.find(']');
    //                 string transactionsData = line.substr(start, end - start);

    //                 stringstream ts(transactionsData);
    //                 string transaction;

    //                 // Parse each transaction
    //                 while (getline(ts, transaction, '|'))
    //                 {
    //                     stringstream transactionDetails(transaction);
    //                     string type, amountString, timestamp;

    //                     getline(transactionDetails, type, ';');
    //                     getline(transactionDetails, amountString, ';');
    //                     getline(transactionDetails, timestamp, ';');

    //                     // Create a new transaction object
    //                     Transaction *newTransaction = new Transaction();
    //                     newTransaction->type = type;
    //                     newTransaction->amount = stod(amountString);
    //                     newTransaction->timestamp = timestamp;
    //                     newTransaction->next = nullptr;

    //                     // Add transaction to the linked list
    //                     if (newAccount->transactionHead == nullptr)
    //                     {
    //                         newAccount->transactionHead = newTransaction;
    //                     }
    //                     else
    //                     {
    //                         Transaction *temp = newAccount->transactionHead;
    //                         while (temp->next != nullptr)
    //                         {
    //                             temp = temp->next;
    //                         }
    //                         temp->next = newTransaction;
    //                     }
    //                 }
    //             }

    //             // Add account to the linked list
    //             if (head == nullptr)
    //             {
    //                 head = newAccount;
    //             }
    //             else
    //             {
    //                 Account *temp = head;
    //                 while (temp->next != nullptr)
    //                 {
    //                     temp = temp->next;
    //                 }
    //                 temp->next = newAccount;
    //             }
    //         }

    //         InputFile.close();
    //         cout << "Accounts and Transactions Loaded Successfully!" << endl;
    //     }
    //     else
    //     {
    //         cout << "Error: Unable to load accounts and transactions!" << endl;
    //     }
    // }

// void LoadAccountsFromFile()
    // {
    //     ifstream InputFile(DataFile.c_str());

    //     if (InputFile.is_open())
    //     {
    //         string line;

    //         while (getline(InputFile, line))
    //         {
    //             stringstream ss(line);
    //             string AccountNumber, AccountName, Password, BalanceString, IsFrozenString, LoanAmountString, LoanLimitString;
    //             string TransactionsString;

    //             // Extract account details
    //             getline(ss, AccountNumber, ',');
    //             getline(ss, AccountName, ',');
    //             getline(ss, Password, ',');
    //             getline(ss, BalanceString, ',');
    //             getline(ss, IsFrozenString, ',');
    //             getline(ss, LoanAmountString, ',');
    //             getline(ss, LoanLimitString, ',');

    //             try
    //             {
    //                 double AccountBalance = stod(BalanceString);
    //                 bool IsFrozen = (IsFrozenString == "1"); // Convert "1" to true, "0" to false
    //                 double LoanAmount = stod(LoanAmountString);
    //                 double LoanLimit = stod(LoanLimitString);

    //                 // Create a new account object
    //                 Account *newAccount = new Account();
    //                 newAccount->AccountNumber = AccountNumber;
    //                 newAccount->AccountName = AccountName;
    //                 newAccount->Password = Password;
    //                 newAccount->AccountBalance = AccountBalance;
    //                 newAccount->isFrozen = IsFrozen;
    //                 newAccount->LoanAmount = LoanAmount;
    //                 newAccount->LoanLimit = LoanLimit;
    //                 newAccount->transactionHead = nullptr;

    //                 // Load transaction history if present
    //                 size_t transactionStart = line.find('[');
    //                 size_t transactionEnd = line.find(']');
    //                 if (transactionStart != string::npos && transactionEnd != string::npos)
    //                 {
    //                     string transactionsData = line.substr(transactionStart + 1, transactionEnd - transactionStart - 1);

    //                     stringstream ts(transactionsData);
    //                     string transaction;

    //                     // Parse each transaction
    //                     while (getline(ts, transaction, '|'))
    //                     {
    //                         stringstream transactionDetails(transaction);
    //                         string type, amountString, timestamp;

    //                         getline(transactionDetails, type, ';');
    //                         getline(transactionDetails, amountString, ';');
    //                         getline(transactionDetails, timestamp, ';');

    //                         // Create a new transaction object
    //                         Transaction *newTransaction = new Transaction();
    //                         newTransaction->type = type;
    //                         newTransaction->amount = stod(amountString);
    //                         newTransaction->timestamp = timestamp;
    //                         newTransaction->next = nullptr;

    //                         // Add transaction to the linked list
    //                         if (newAccount->transactionHead == nullptr)
    //                         {
    //                             newAccount->transactionHead = newTransaction;
    //                         }
    //                         else
    //                         {
    //                             Transaction *temp = newAccount->transactionHead;
    //                             while (temp->next != nullptr)
    //                             {
    //                                 temp = temp->next;
    //                             }
    //                             temp->next = newTransaction;
    //                         }
    //                     }
    //                 }

    //                 // Add account to the linked list
    //                 if (head == nullptr)
    //                 {
    //                     head = newAccount;
    //                 }
    //                 else
    //                 {
    //                     Account *temp = head;
    //                     while (temp->next != nullptr)
    //                     {
    //                         temp = temp->next;
    //                     }
    //                     temp->next = newAccount;
    //                 }
    //             }
    //             catch (const invalid_argument &e)
    //             {
    //                 cout << "Error: Invalid data format in file: " << e.what() << endl;
    //                 continue; // Skip to the next line
    //             }
    //             catch (const out_of_range &e)
    //             {
    //                 cout << "Error: Data out of range in file: " << e.what() << endl;
    //                 continue; // Skip to the next line
    //             }
    //         }

    //         InputFile.close();
    //         cout << "Accounts and Transactions Loaded Successfully!" << endl;
    //     }
    //     else
    //     {
    //         cout << "Error: Unable to load accounts and transactions!" << endl;
    //     }
    // }
    
int main(){
    
    return 0;
}