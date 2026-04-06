#include <fstream>
#include "letterinfo.h"
#include <iostream>

using namespace std;

void calculateFrequencies(const char *filename, LetterInfo *freqArray)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Failed to open file." << endl;
        return;
    }

    char c;
    while (file.get(c))
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            int index = (c >= 'a' && c <= 'z') ? c - 'a' : c - 'A';
            freqArray[index].freq++;
        }
    }

    file.close();
}

void displayFrequencies(LetterInfo *freqArray)
{
    cout << "Letter Frequencies (in decreasing order):" << endl;
    for (int i = 0; i < 26; i++)
    {
        if (freqArray[i].freq > 0)
        {
            cout << freqArray[i].letter << ": " << freqArray[i].freq << endl;
        }
    }
}
