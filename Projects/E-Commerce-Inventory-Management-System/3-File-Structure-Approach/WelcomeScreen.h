#include <iostream>
#include "HeaderFilesUsed.h"
using namespace std;

void DrawWelcomeScreen()
{
    // ASCII art for welcome screen
    vector<string> welcomeArt = {
        "                          __        __   _                              ",
        "                          \\ \\      / /__| | ___ ___  _ __ ___   ___    ",
        "                           \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   ",
        "                            \\ V  V /  __/ | (_| (_) | | | | | |  __/    ",
        "                             \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|     "};

vector<string> colors = {
    "\033[31m",  // Red
    "\033[32m",  // Green
    "\033[34m",  // Blue
    "\033[33m",  // Yellow
    "\033[35m",  // Purple
    "\033[38;5;214m",  // Orange (using 256-color code)
    "\033[36m",  // Cyan
    "\033[37m",  // White
    "\033[90m",  // Bright Black (Gray)
    "\033[91m",  // Light Red
    "\033[92m",  // Light Green
};


    system("cls");

    // Number of blinking cycles (this can be changed)
    const int blinkCycles = 6;

    for (int cycle = 0; cycle < blinkCycles; ++cycle)
    {
        // Select a color for the whole text during this cycle
        string color = colors[cycle % colors.size()];

        // Clear the screen at the start of each cycle
        system("cls");

        // Print the entire welcome message with the selected color
        cout << color;

        // Loop through the ASCII art lines and print them with the same color
        for (size_t i = 0; i < welcomeArt.size(); ++i)
        {
            cout << welcomeArt[i] << endl;
        }
        Sleep(500); // Adjust the delay for the blink speed (milliseconds)
    }
    cout << "\033[33m\n\n\t\t\tWelcome to E-commerce Inventory Management System!\033[0m" << endl;

    cout << "\033[32m\n\t\t\t\tSubmitted By: Abdullah Bin Mughira\033[0m" << endl;

    cout << "\033[91m\n\t\t\t\t    Roll #: 2023-BS-SE-082\033[0m" << endl;

    cout << "\033[34m\n\t\t\tDepartment: Computer Science / Software Engineering!\033[0m" << endl;

    cout << "\033[35m\n\nPress any key to Continue.\033[0m" << endl;
    // Wait for a key press to start the program
    system("pause>nul");
}