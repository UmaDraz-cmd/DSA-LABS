//Umar Draz-BITF24M036-MORNING
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Maximum length of player name in team
const int NAME_LENGTH = 25;

// Structure to store bowling information
struct BowlingFigures
{
    char name[NAME_LENGTH + 1];  // Bowler name
    int wickets;                 // Number of wickets taken
    int runs;                    // Runs conceded by the bowlder 
};

// Function prototypes
BowlingFigures* readFromFile(char* fileName, int& count);
void printBowlingFigures(const BowlingFigures* bf, int count);
void sortBowlingFigures1(BowlingFigures* bf, int count);   // Insertion Sort
void sortBowlingFigures2(BowlingFigures* bf, int count);   // Selection Sort
void sortByName(BowlingFigures* bf, int count);            // Bubble Sort


// Function to read bowling figures from file
BowlingFigures* readFromFile(char* fileName, int& count)
{
    ifstream fin;

    // Open the file
    fin.open(fileName);

    // If file opened successfully
    if (fin.is_open())
    {
        // First value in file = number of bowlers
        fin >> count;
        fin.ignore();

        // Dynamically allocate array
        BowlingFigures* bf = new BowlingFigures[count];

        // Read data for each bowler
        for (int i = 0; i < count; i++)
        {
            // Read bowler name
            fin.getline(bf[i].name, NAME_LENGTH + 1);

            // Read wickets and runs from file
            fin >> bf[i].wickets >> bf[i].runs;

            fin.ignore();
        }

        fin.close();  // Close file once opened

        return bf;    // Return pointer to array 
    }
    else
    {
        // If file could not be opened then return NULL
        return NULL;
    }
}


// Function to display bowling figures of all bowlers
void printBowlingFigures(const BowlingFigures* bf, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << bf[i].name << " "
            << bf[i].wickets << "-" << bf[i].runs << endl;
    }
}


// Sort bowling figures using Insertion Sort
// Priority should be more wickets first, if equal wickets have been taken then fewer runs first
void sortBowlingFigures1(BowlingFigures* bf, int count)
{
    for (int i = 1; i < count; i++)
    {
        BowlingFigures key = bf[i];

        int j = i - 1;

        while ((j >= 0) &&
            ((bf[j].wickets < key.wickets) ||
                ((bf[j].wickets == key.wickets) && (bf[j].runs > key.runs))))
        {
            bf[j + 1] = bf[j];

            j = j - 1;
        }

        bf[j + 1] = key; 
    }
}


// Sort bowling figures using Selection Sort
// Same sorting condition: more wickets first, fewer runs second
void sortBowlingFigures2(BowlingFigures* bf, int count)
{
    for (int i = 0; i < (count - 1); i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < count; j++)
        {
            if ((bf[j].wickets > bf[maxIndex].wickets) ||
                ((bf[j].wickets == bf[maxIndex].wickets) &&
                    (bf[j].runs < bf[maxIndex].runs)))
            {
                maxIndex = j;
            }
        }

        // Swap elements
        BowlingFigures temp = bf[i];
        bf[i] = bf[maxIndex];
        bf[maxIndex] = temp;
    }
}


// Sort bowlers alphabetically by name using Bubble Sort
void sortByName(BowlingFigures* bf, int count)
{
    for (int i = 0; i < (count - 1); i++)
    {
        for (int j = 0; j < (count - i - 1); j++)
        {
            // Compare names using strcmp
            if (strcmp(bf[j].name, bf[j + 1].name) > 0)
            {
                BowlingFigures temp = bf[j];

                bf[j] = bf[j + 1];

                bf[j + 1] = temp;
            }
        }
    }
}


// Main function for above functions 
int main()
{
    char fileName[100];
    int count;

    // Ask user for file name
    cout << "Enter the name of input file: ";
    cin >> fileName;

    // Read data from file
    BowlingFigures* bf = readFromFile(fileName, count);

    // If file not found
    if (bf == NULL)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    cout << "\nFollowing " << count << " Bowling figures were read from the file:\n\n";

    // Display original data
    printBowlingFigures(bf, count);

    int choice;

    // Menu loop
    do
    {
        cout << "\n--------\n";
        cout << "Menu\n";
        cout << "--------\n";

        cout << "1. Sort BowlingFigures using Insertion sort\n";
        cout << "2. Sort BowlingFigures using Selection sort\n";
        cout << "3. Sort BowlingFigures by Name (Bubble sort)\n";
        cout << "4. Quit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            sortBowlingFigures1(bf, count);

            cout << "\nThe " << count << " Bowling figures after sorting using Insertion sort are:\n\n";

            printBowlingFigures(bf, count);
        }
        else
        {
            if (choice == 2)
            {
                sortBowlingFigures2(bf, count);

                cout << "\nThe " << count << " Bowling figures after sorting using Selection sort are:\n\n";

                printBowlingFigures(bf, count);
            }
            else
            {
                if (choice == 3)
                {
                    sortByName(bf, count);

                    cout << "\nThe " << count << " Bowling figures after sorting by NAME are:\n\n";

                    printBowlingFigures(bf, count);
                }
            }
        }

    } while (choice != 4);

    // Free dynamically allocated memory
    delete[] bf;

    return 0;
}
// git add .
// git commit -m "Added recursion homework"
// git push
