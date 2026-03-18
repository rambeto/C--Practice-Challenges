#include <iostream>   // Include the iostream library for input/output operations
using namespace std;  // Use the standard namespace to avoid using the "std::" prefix

// Function: PrintTableHeader
// Purpose: Prints the header of the multiplication table, including the title and column labels.
void PrintTableHeader()
{
    // Print the title of the table with some formatting (new lines and tab spaces)
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
    
    // Print a tab to align the column headers correctly
    cout << "\t";
    
    // Loop from 1 to 10 to print the column numbers for the header
    for (int i = 1; i <= 10; i++)
    {
        // Print the current number followed by a tab for spacing
        cout << i << "\t";
    }
    
    // Print a separator line to visually divide the header from the rest of the table
    cout << "\n___________________________________________________________________________________\n";
}

// Function: ColumSperator
// Purpose: Returns a string that acts as a separator between the row number and the multiplication values.
//          The spacing is adjusted based on whether the row number is a single-digit (less than 10) or not.
string ColumSperator(int i)
{
    // If the row number is less than 10, return a separator with three spaces before the pipe symbol
    if (i < 10)
        return "   |";
    else
        // For numbers 10 or greater, return a separator with two spaces before the pipe symbol
        return "  |";
}

// Function: PrintMultiplicationTable
// Purpose: Combines the header and the multiplication logic to print the full multiplication table.
void PrintMultiplicationTable()
{
    // First, print the header with the title and column numbers
    PrintTableHeader();

    // Loop through the rows of the multiplication table (from 1 to 10)
    for (int i = 1; i <= 10; i++)
    {
        // Print the row number, then a formatted column separator, and a tab for spacing
        cout << " " << i << ColumSperator(i) << "\t";
        
        // Inner loop to calculate and print the product for each column (from 1 to 10)
        for (int j = 1; j <= 10; j++)
        {
            // Calculate the product of the current row and column, then print it with a tab for spacing
            cout << i * j << "\t";
        }
        // After finishing one row, move to the next line
        cout << endl;
    }
}

// Main function: Program entry point
int main()
{
    // Call the function to print the multiplication table
    PrintMultiplicationTable();
    
    // Return 0 to indicate successful program execution
    return 0;
}
