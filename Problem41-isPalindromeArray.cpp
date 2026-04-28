#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify standard library function calls.

// Function: FillArray
// Purpose: Initializes an array with a fixed set of values.
// Parameters:
//   - arr: An integer array (capacity 100) that will be filled with predefined numbers.
//   - arrLength: A reference variable that will hold the number of elements filled in the array.
void FillArray(int arr[100], int &arrLength)
{
    arrLength = 6;  // Set the number of elements in the array to 6.
    
    // Manually assign values to each element in the array.
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

// Function: PrintArray
// Purpose: Prints the elements of an array, separated by spaces.
// Parameters:
//   - arr: The array to be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through each element in the array and output it followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: IsPalindromeArray
// Purpose: Checks whether the array is a palindrome.
//          An array is considered a palindrome if it reads the same forward and backward.
// Parameters:
//   - arr: The array to check.
//   - Length: The number of elements in the array.
// Returns: true if the array is a palindrome, false otherwise.
bool IsPalindromeArray(int arr[100], int Length)
{
    // Loop through each element of the array.
    // We only need to check up to the middle of the array.
    for (int i = 0; i < Length; i++)
    {
        // Compare the element at position i with its corresponding element from the end.
        if (arr[i] != arr[Length - i - 1])
        {
            return false;  // If any pair doesn't match, the array is not a palindrome.
        }
    }
    
    // If all corresponding pairs match, the array is a palindrome.
    return true;
}

// Main function: Entry point of the program.
int main()
{
    int arr[100];  // Declare an array with capacity for 100 integers.
    int Length = 0; // Initialize the length of the array.
    
    // Fill the array with predefined values.
    FillArray(arr, Length);
    
    // Print the array elements.
    cout << "\nArray Elements:\n";
    PrintArray(arr, Length);
    
    // Check if the array is a palindrome and display the result.
    if (IsPalindromeArray(arr, Length))
        cout << "\nYes array is Palindrome\n";
    else
        cout << "\nNO array is NOT Palindrome\n";
    
    return 0;  // Return 0 to indicate successful program execution.
}
