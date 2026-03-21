/*
Problem: Random Keys Generator
Concepts:
- Random Number Seeding (srand, time).
- ASCII Code manipulation (Converting integers to chars).
- Enums for code readability.
- Reusable functions (GenerateWord, GenerateKey).
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// تعريف أنواع الحروف باستخدام Enum لسهولة القراءة
enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

/*
-----------------------------------------------------------
Function: RandomNumber
Purpose : Generates a random integer within [From, To].
-----------------------------------------------------------
*/
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

/*
-----------------------------------------------------------
Function: GetRandomCharacter
Purpose : Returns a random char based on ASCII table values.
          Example: Capital letters (65-90).
-----------------------------------------------------------
*/
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SamallLetter:
            return char(RandomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
        case enCharType::Digit:
            return char(RandomNumber(48, 57));
        default:
            return '\0';
    }
}

/*
-----------------------------------------------------------
Function: ReadPositiveNumber
Purpose : Standard input validation for positive integers.
-----------------------------------------------------------
*/
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

/*
-----------------------------------------------------------
Function: GenerateWord
Purpose : Creates a random string of a specific length.
-----------------------------------------------------------
*/
string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";
    for (int i = 1; i <= Length; i++)
    {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

/*
-----------------------------------------------------------
Function: GenerateKey
Purpose : Returns a formatted key (XXXX-XXXX-XXXX-XXXX).
-----------------------------------------------------------
*/
string GenerateKey()
{
    string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4);
    
    return Key;
}

/*
-----------------------------------------------------------
Function: GenerateKeys
Purpose : Prints the requested number of keys.
-----------------------------------------------------------
*/
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : " << GenerateKey() << endl;
    }
}

int main()
{
    // تهيئة مولد الأرقام العشوائية بناءً على الوقت الحالي
    srand((unsigned)time(NULL));

    short NumberOfKeys = ReadPositiveNumber("Please enter how many keys to generate?");
    
    cout << "\nGenerated Keys:\n";
    cout << "-----------------------------------\n";
    GenerateKeys(NumberOfKeys);
    cout << "-----------------------------------\n";

    system("pause>0");
    return 0;
}
