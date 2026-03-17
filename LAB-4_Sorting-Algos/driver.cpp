//Name=      Umar Draz
//Roll=     BITF24M033 
//Section=  Morning 
#include <iostream>
#include "PacketManager.h"
#include "PacketManager.cpp"
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream fin;
    char filename[100];

    cout << "Enter the name of the input file: ";
    cin >> filename;

    fin.open(filename);

    while (!fin)
    {
        cout << "ERROR: The file \"" << filename << "\" does not exist!!\n";
        cout << "Re-enter the input file name: ";
        cin >> filename;
        fin.clear();
        fin.open(filename);
    }

    PacketManager pm(fin);
    cout << "\nPackets originally read from the file are:\n";
    pm.displayPackets();
    pm.extractMessage();
    cout << "\nThe order of packets after extracting the message:\n";
    pm.displayPackets();
    pm.displayMessage();
    fin.close();
}