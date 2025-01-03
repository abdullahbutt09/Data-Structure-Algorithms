#include <iostream>
#include <conio.h> // For _getch() (Windows-specific)
#include <cctype>  // For isalpha
#include <string>  // For string manipulation

using namespace std;

int main()
{
    char ch;
    string input; // To store the current input

    cout << "Start typing numbers. The program will terminate if you enter an alphabet. Press Enter to finalize input:\n";

    while (true)
    {
        ch = _getch(); // Get a single character without requiring Enter

        if (ch == '\b')
        { // Backspace key (ASCII 8)
            if (!input.empty())
            {
                input.pop_back(); // Remove the last character from the string
                cout << "\b \b";  // Move back, print a space to overwrite, then move back again
            }
        }
        else if (ch == '\r')
        { // Enter key (ASCII 13)
            if (input.length() != 9)
            {
                cout << "\nYour Password Length cannot be " << input.length() << endl;
                cout << "Please enter an 9 digit length number : ";
                input.clear();
            }

            else
            {
                break;
            }
        }
        else if (isalpha(ch))
        { // Check if the character is an alphabet
            cout << "\nYour CNIC Cannot Include Alphabets!"<<endl;
            cout << "Kindly Enter Only Numbers!"<<endl;
            cout << endl;
            cout << "Please Enter Valid CNIC : ";
            input.clear(); // Clear the input buffer
        }
        else if (input.length() == 9)
        {
            cout << "\nYour CNIC cannot Greater than 9 numbers!" << endl;
            cout << "Kindly Only Enter Only 9 Digit CNIC Number : ";
            input.clear();
        }
        else
        {
            input += ch; // Append character to the input
            cout << ch;  // Echo the character
        }
    }

    cout << "\nFinal Ouput: " << input << endl;

    return 0;
}
