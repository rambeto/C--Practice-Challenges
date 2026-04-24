#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify code (e.g., using cout instead of std::cout).

// Enumeration to define character types for random character generation.
// Each enum value represents a different category of characters.
enum enCharType { 
    SamallLetter = 1,    // Lowercase letters (ASCII range 97-122)
    CapitalLetter = 2,   // Uppercase letters (ASCII range 65-90)
    SpecialCharacter = 3,// Special characters (ASCII range 33-47)
    Digit = 4            // Digits (ASCII range 48-57)
};

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the range.
//   - To: The upper bound of the range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Calculate a random number using modulus and shifting the range.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: GetRandomCharacter
// Purpose: Returns a random character based on the specified character type.
// Parameters:
//   - CharType: An enCharType value specifying the type of character to generate.
// Returns: A random character from the chosen category.
char GetRandomCharacter(enCharType CharType)
{
    // Use a switch-case to choose the character type.
    switch (CharType)
    {
        case enCharType::SamallLetter:
        {
            // Generate a random lowercase letter (ASCII codes 97 to 122).
            return char(RandomNumber(97, 122));
            break; // break is not needed after return.
        }
        case enCharType::CapitalLetter:
        {
            // Generate a random uppercase letter (ASCII codes 65 to 90).
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            // Generate a random special character (ASCII codes 33 to 47).
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            // Generate a random digit (ASCII codes 48 to 57).
            return char(RandomNumber(48, 57));
            break;
        }
    }
    // If none of the cases match (should not happen), return a null character.
    return '\0';
}

// Function: PrintStringArray
// Purpose: Prints the elements of a string array with index labels.
// Parameters:
//   - arr: A string array of size 100.
//   - arrLength: The number of elements in the array.
void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements:\n\n";
    // Loop through the array and print each element with its index.
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Array[" << i << "] : ";
        cout << arr[i] << "\n";
    }
    cout << "\n"; // Extra newline for formatting.
}

// Function: GenerateWord
// Purpose: Generates a word composed of random characters of a specified type.
// Parameters:
//   - CharType: The type of character to use (e.g., CapitalLetter).
//   - Length: The number of characters in the word.
// Returns: A string containing the generated word.
string GenerateWord(enCharType CharType, short Length)
{
    string Word;  // Initialize an empty string.
    // Append random characters to the word one by one.
    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

// Function: GenerateKey
// Purpose: Generates a key string in the format "XXXX-XXXX-XXXX-XXXX", where each 'X' is a random uppercase letter.
// Returns: A string representing the generated key.
string GenerateKey()
{
    string Key = "";
    // Generate 4 groups of 4 uppercase letters, separated by hyphens.
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
    return Key;
}

// Function: FillArrayWithKeys
// Purpose: Fills a string array with generated keys.
// Parameters:
//   - arr: The string array to be filled (capacity of 100).
//   - arrLength: The number of keys to generate and fill in the array.
void FillArrayWithKeys(string arr[100], int arrLength)
{
    // Loop through the array indices and generate a key for each element.
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

// Function: ReadPositiveNumber
// Purpose: Prompts the user to enter a positive number.
// Parameters:
//   - Message: A string message to prompt the user.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to hold user input.
    do
    {
        cout << Message << endl; // Display the prompt.
        cin >> Number;           // Read the input.
    } while (Number <= 0);       // Repeat until a positive number is entered.
    return Number;
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures a different sequence of random numbers on each program run.
    srand((unsigned)time(NULL));
    
    string arr[100]; // Declare a string array to hold up to 100 keys.
    int arrLength = 0; // Variable to hold the number of keys to generate.
    
    // Prompt the user for the number of keys to generate.
    arrLength = ReadPositiveNumber("How many keys do you want to generate?\n");
    
    // Fill the array with generated keys.
    FillArrayWithKeys(arr, arrLength);
    
    // Print the generated keys.
    PrintStringArray(arr, arrLength);
    
    return 0; // End the program successfully.
}
