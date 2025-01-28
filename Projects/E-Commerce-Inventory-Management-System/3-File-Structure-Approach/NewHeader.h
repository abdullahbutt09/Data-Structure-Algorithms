#include <iostream>
// #include <conio.h>
// #include <string>
#include "HeaderFilesUsed.h"
using namespace std;

// Template function to handle different types (int, float, double)
template <typename T>
T ValidatePriceIdQuantity()
{
    char ch;
    string id;
    T result;

    while (true)
    {
        ch = _getch();
        if (ch == '\b')
        { // Backspace key (ASCII 8)
            if (!id.empty())
            {
                id.pop_back();   // Remove the last character from the string
                cout << "\b \b"; // Move back, print a space to overwrite, then move back again
            }
        }

        else if (ch == '\r')
        { // Enter key (ASCII 13)
            if (id.length() == 0)
            {
                cout << endl;
                cout << "\nLength cannot be " << id.length() << endl;
                cout << "Please enter an 1-10 number!" << endl;
                cout << endl;
                cout << "Please Enter Valid (Buyer Balance) (Product ID/Price/Quantity) : ";
                id.clear();
            }
            else
            {
                break;
            }
        }

        else if (isalpha(ch))
        { // Check if the character is an alphabet
            cout << endl;
            cout << "\nYour input cannot include alphabets!" << endl;
            cout << "Kindly enter only numbers!" << endl;
            cout << endl;
            cout << "Please Enter Valid (Buyer Balance) (Product ID/Price/Quantity) : ";
            id.clear(); // Clear the buffer
        }

        else if (!isdigit(ch))
        { // Check if the character is not a digit or decimal point
            cout << endl;
            cout << "\nYour input cannot include special symbols!" << endl;
            cout << "Kindly enter only numbers!" << endl;
            cout << endl;
            cout << "Please Enter Valid (Buyer Balance) (Product ID/Price/Quantity) : ";
            id.clear(); // Clear the buffer
        }

        else if (id.length() == 9)
        {
            cout << endl;
            cout << "\nInteger Double Float limit reached!" << endl;
            cout << "Kindly Only 10 Digit Number : "<<endl;
            cout << endl;
            cout << "Please Enter Valid (Buyer Balance) (Product ID/Price/Quantity) : ";
            id.clear();
        }
        else
        {
            id += ch;   // Append the character to the id
            cout << ch; // Echo the character
        }
    }
    cout << endl;

    // Convert to the appropriate type based on T (either int, float, or double)
    if constexpr (is_integral<T>::value)
    {
        result = stoi(id); // For integral types (int)
    }
    else if constexpr (is_floating_point<T>::value)
    {
        result = stod(id); // For floating-point types (float, double)
    }

    return result;
}