//Name=      Umar Draz
//Roll=     BITF24M033 
//Section=  Morning 
#pragma once
#include <fstream>
using namespace std;

const int PACKET_SIZE = 5; // Number of characters in a packet
struct Packet
{
    int position;               // Packet’s position within the message
    char body[PACKET_SIZE + 1]; // Characters contained in the packet including NULL terminator
};

class PacketManager
{
private:
    Packet *packets; 
    int numPackets;  
    char *message;   
    int msgLength;   


public:
    PacketManager(ifstream &fin);
    ~PacketManager();
    void displayPackets() const;
    void sortPacketsBubbleSort();
    void sortPacketsSelectionSort();
    void extractMessage();
    void displayMessage() const;
    void Packetsshefling();
};
