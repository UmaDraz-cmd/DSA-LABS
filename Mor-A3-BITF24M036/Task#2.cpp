#include<iostream>
using namespace std;

// Node for Circular Doubly Linked List
class DNode
{
    friend class CDLLD;   // Allow CDLLD to access private members
    int data;             // Data stored in node
    DNode* next;          // Pointer to next node
    DNode* prev;          // Pointer to previous node
};

class CDLLD
{
private:
    DNode head;   // Dummy header node (circular list)

    // Static helper function to swap two adjacent nodes
    static bool swapAdjacent(DNode* n1, DNode* n2)
    {
        // Check if nodes are adjacent
        if (n1->next != n2 || n2->prev != n1)
            return false;

        // Re-link surrounding nodes
        n1->prev->next = n2;
        n2->next->prev = n1;

        // Swap internal pointers
        n1->next = n2->next;
        n2->prev = n1->prev;

        n2->next = n1;
        n1->prev = n2;

        return true;
    }

public:
    // Constructor → initialize circular structure
    CDLLD()
    {
        head.next = &head;   // Initially points to itself
        head.prev = &head;
    }

    // Destructor → free all dynamically allocated nodes
    ~CDLLD()
    {
        DNode* curr = head.next;

        // Traverse and delete nodes
        while (curr != &head)
        {
            DNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // Insert node at the beginning (O(1))
    bool insertAtStart(int val)
    {
        DNode* temp = new DNode;
        temp->data = val;

        // Link new node with existing first node
        temp->next = head.next;
        temp->prev = &head;

        // Fix previous pointer of old first node
        head.next->prev = temp;

        // Update head to point to new node
        head.next = temp;

        return true;
    }

    // Insert node at the end (O(1))
    bool insertAtEnd(int val)
    {
        DNode* temp = new DNode;
        temp->data = val;

        // Link new node with last node
        temp->next = &head;
        temp->prev = head.prev;

        // Fix pointers of existing last node
        head.prev->next = temp;
        head.prev = temp;

        return true;
    }

    // Display all elements in list
    void display()
    {
        // Check if list is empty
        if (head.next == &head)
        {
            cout << "List is empty!\n";
            return;
        }

        DNode* curr = head.next;

        // Traverse and print elements
        while (curr != &head)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Count total number of nodes
    int countNodes()
    {
        DNode* curr = head.next;
        int count = 0;

        while (curr != &head)
        {
            curr = curr->next;
            count++;
        }
        return count;
    }

    // Search for a value in the list
    bool search(int val)
    {
        DNode* curr = head.next;

        while (curr != &head)
        {
            if (curr->data == val)
                return true;

            curr = curr->next;
        }
        return false;
    }

    // Remove first occurrence of a value
    bool unsortedRemove(int val)
    {
        DNode* curr = head.next;

        // Traverse to find the node
        while (curr != &head && curr->data != val)
        {
            curr = curr->next;
        }

        // If node found
        if (curr != &head)
        {
            // Bypass the node
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            delete curr;
            return true;
        }
        else
        {
            return false;   // Value not found
        }
    }

    // Bubble sort using node swapping (no data swapping)
    void bubbleSort()
    {
        // If list is empty or has one node
        if (head.next == &head || head.next->next == &head)
            return;

        bool swapped;

        do
        {
            swapped = false;
            DNode* curr = head.next;

            while (curr->next != &head)
            {
                DNode* nextNode = curr->next;

                // Compare adjacent nodes
                if (curr->data > nextNode->data)
                {
                    // Swap nodes using pointer manipulation
                    swapAdjacent(curr, nextNode);

                    swapped = true;

                    // Move pointer correctly after swap
                    curr = nextNode;
                }

                curr = curr->next;
            }

        } while (swapped);

        cout << "The list has been sorted!" << endl;
    }
};

// Main menu-driven program
int main()
{
    CDLLD list;
    int choice, value;

    do
    {
        cout << "\n===== Circular Doubly Linked List Menu =====\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Remove a value\n";
        cout << "4. Search a value\n";
        cout << "5. Display List\n";
        cout << "6. Count Nodes\n";
        cout << "7. Sort (Bubble Sort)\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at start: ";
            cin >> value;
            list.insertAtStart(value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to remove: ";
            cin >> value;
            if (list.unsortedRemove(value))
                cout << value << " removed.\n";
            else
                cout << "Value not found.\n";
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value))
                cout << "Found!\n";
            else
                cout << "Not found!\n";
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Total nodes: " << list.countNodes() << endl;
            break;

        case 7:
            list.bubbleSort();
            break;

        case 8:
            cout << "Bye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}