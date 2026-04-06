//Name: Abdullah
//BITF24M033
//Morning

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int NAME_LENGTH = 25;
struct BowlingFigures
{
    char name[NAME_LENGTH + 1]; // Name of the bowler
    int wickets;                // Wickets taken by the bowler
    int runs;                   // Runs conceded by the bowler
};

BowlingFigures *readFromFile(char *fileName, int &count);
void printBowlingFigures(const BowlingFigures *bf, int count);
void sortBowlingFigures1(BowlingFigures *bf, int count);
void sortBowlingFigures2(BowlingFigures *bf, int count);
void sortByName(BowlingFigures *bf, int count);

BowlingFigures *readFromFile(char *fileName, int &count)
{
    ifstream fin(fileName);

    if (!fin)
        return NULL;

    fin >> count;
    fin.ignore();

    BowlingFigures *bf = new BowlingFigures[count];

    for (int i = 0; i < count; i++)
    {
        fin.getline(bf[i].name, NAME_LENGTH + 1);
        fin >> bf[i].wickets >> bf[i].runs;
        fin.ignore();
    }

    fin.close();

    return bf;
}

void printBowlingFigures(const BowlingFigures *bf, int count)
{
    for (int i = 0; i < count; i++)
    { 
        cout << "\t" << bf[i].name << " "
             << bf[i].wickets << "-"
             << bf[i].runs << endl;
    }
}

void sortBowlingFigures1(BowlingFigures *bf, int count)
{
    for (int i = 1; i < count; i++)
    {
        BowlingFigures key = bf[i];
        int j = i - 1;

        while (j >= 0 &&
               (bf[j].wickets < key.wickets ||
                (bf[j].wickets == key.wickets && bf[j].runs > key.runs)))
        {
            bf[j + 1] = bf[j];
            j--;
        }

        bf[j + 1] = key;
    }
}

void sortBowlingFigures2(BowlingFigures *bf, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        int best = i;

        for (int j = i + 1; j < count; j++)
        {
            if (bf[j].wickets > bf[best].wickets ||
                (bf[j].wickets == bf[best].wickets && bf[j].runs < bf[best].runs))
            {
                best = j;
            }
        }

        BowlingFigures temp = bf[i];
        bf[i] = bf[best];
        bf[best] = temp;
    }
}

void sortByName(BowlingFigures *bf, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(bf[j].name, bf[j + 1].name) > 0)
            {
                BowlingFigures temp = bf[j];
                bf[j] = bf[j + 1];
                bf[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char fileName[50];
    int count;

    cout << "Enter the name of input file: ";
    cin >> fileName;

    BowlingFigures *bf = readFromFile(fileName, count);

    if (bf == NULL)
    {
        cout << "File not found!" << endl;
        return 0;
    }
    cout << endl;
    cout << "Following " << count << " Bowling figures were read from the input file:" << endl;
    cout << endl;

    printBowlingFigures(bf, count);

    int choice;

    do
    {
        cout << endl;
        cout << "           ----------" << endl;
        cout << "              Menu" << endl;
        cout << "           ----------" << endl;
        cout << "1. Sort BowlingFigures using Insertion sort" << endl;
        cout << "2. Sort BowlingFigures using Selection sort" << endl;
        cout << "3. Sort BowlingFigures by Name (using Bubble sort)" << endl;
        cout << "4. Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            sortBowlingFigures1(bf, count);
            cout << "\nThe " << count << " Bowling figures after sorting using Insertion sort are:\n\n";
            printBowlingFigures(bf, count);
        }
        else if (choice == 2)
        {
            sortBowlingFigures2(bf, count);
            cout << "\nThe " << count << " Bowling figures after sorting using Selection sort are:\n\n";
            printBowlingFigures(bf, count);
        }
        else if (choice == 3)
        {
            sortByName(bf, count);
            cout << "\nThe " << count << " Bowling figures after sorting by NAME are:\n\n ";
            printBowlingFigures(bf, count);
        }

    } while (choice != 4);

    delete[] bf;
    bf = nullptr;

    return 0;
}