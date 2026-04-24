#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify standard function calls.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the range.
//   - To:   The upper bound of the range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // rand() % (To - From + 1) gives a value between 0 and (To - From),
    // adding From shifts it into the range [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an integer array with random numbers between 1 and 100.
// Parameters:
//   - arr: An array of integers (with capacity 100) to be filled.
//   - arrLength: A reference variable to store the number of elements the user wants.
// The function prompts the user for the number of elements and then fills the array.
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the desired number of elements.

    // Loop through each index from 0 to arrLength - 1.
    // Fill each array element with a random number between 1 and 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   - arr: The array whose elements will be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through each element in the array and output it with a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: AddArrayElement
// Purpose: Adds a new element to the end of an array, updating its length.
// Parameters:
//   - Number: The number to add to the array.
//   - arr: The array in which to add the new element.
//   - arrLength: A reference to the variable tracking the current number of elements in the array.
// Behavior: Increments arrLength by 1 and places the new element at the end of the array.
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    arrLength++;                   // Increment the array length to account for the new element.
    arr[arrLength - 1] = Number;     // Store the new element at the new last index.
}

// Function: CopyArrayUsingAddArrayElement
// Purpose: Copies elements from a source array to a destination array using AddArrayElement,
//          which automatically updates the destination array's length.
// Parameters:
//   - arrSource: The source array containing the original elements.
//   - arrDestination: The destination array where elements will be copied.
//   - arrLength: The number of elements in the source array.
//   - arrDestinationLength: A reference variable to hold the number of elements in the destination array after copying.
void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    // Loop through each element of the source array.
    for (int i = 0; i < arrLength; i++)
        // Use AddArrayElement to copy the element to the destination array and update its length.
        AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
}

// Main function: Program entry point.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that different sequences of random numbers are generated each time the program runs.
    srand((unsigned)time(NULL));

    int arr[100];         // Declare the source array with capacity for 100 integers.
    int arrLength = 0;      // Variable to store the number of elements in the source array.
    
    // Fill the source array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];        // Declare the destination array for the copied elements.
    int arr2Length = 0;     // Initialize the destination array length to 0.

    // Copy elements from the source array into the destination array using AddArrayElement.
    CopyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);

    // Print the source array elements.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Print the destination array elements after copying.
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arr2Length);

    return 0;  // Return 0 to indicate successful program execution.
}
