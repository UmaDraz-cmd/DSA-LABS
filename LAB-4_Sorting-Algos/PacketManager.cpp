//Name=      Umar Draz
//Roll=     BITF24M033 
//Section=  Morning 
#include "PacketManager.h"
#include <iostream>
#include <cstring>
using namespace std;

PacketManager::PacketManager(ifstream &fin)
{
    fin >> numPackets;
    packets = new Packet[numPackets];
    message = nullptr;
    msgLength = 0;
    for (int i = 0; i < numPackets; i++)
    {
        fin >> packets[i].position;
        fin.ignore();
        fin.getline(packets[i].body, PACKET_SIZE + 1);
    }
}
PacketManager::~PacketManager()
{
    if (packets != nullptr)
    {
        delete[] packets;
        packets = nullptr;
    }
    if (message != nullptr)
    {
        delete[] message;
        message = nullptr;
    }
}
void PacketManager::displayPackets() const
{
    for (int i = 0; i < numPackets; i++)
    {
        cout << packets[i].position << " ";
        cout << packets[i].body << endl;
    }
}
void PacketManager::sortPacketsBubbleSort()
{
    for (int i = numPackets - 1; i > 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (packets[j].position > packets[j + 1].position)
            {
                Packet temp = packets[j];
                packets[j] = packets[j + 1];
                packets[j + 1] = temp;
            }
        }
    }
}
void PacketManager::sortPacketsSelectionSort()
{
    for (int i = 0; i < numPackets - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < numPackets; j++)
        {
            if (packets[j].position < packets[min].position)
            {
                min = j;
            }
        }

        Packet temp = packets[i];
        packets[i] = packets[min];
        packets[min] = temp;
    }
}
void PacketManager::extractMessage()
{
    char choice;
    cout << "\nWhich sorting algorithm do you want to use?\n";
    cout << "Enter 'B' or 'b' for Bubble sort\n";
    cout << "Enter 'S' or 's' for Selection sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 'B' || choice == 'b')
        sortPacketsBubbleSort();
    else
        sortPacketsSelectionSort();

    msgLength = 0;
    for (int i = 0; i < numPackets; i++)
        msgLength += strlen(packets[i].body);

    message = new char[msgLength + 1];

    int k = 0;
    for (int i = 0; i < numPackets; i++)
    {
        for (int j = 0; j < strlen(packets[i].body); j++)
        {
            message[k++] = packets[i].body[j];
        }
    }
    message[k] = '\0';
}
void PacketManager::displayMessage() const
{
    if (message == NULL)
        cout << "ERROR: Message has not been extracted yet.\n";
    else
    {
        cout << "\nThe extracted message is:\n";
        cout << message << endl;
    }
}
