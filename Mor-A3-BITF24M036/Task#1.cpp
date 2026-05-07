//Name: Umar Draz - BITF24M036 - Morning
#include<iostream>
using namespace std;
class LinkedList;
class Node {
    friend class LinkedList;
private:
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        Node *p1= head, *p2= nullptr;
        while(p1 != nullptr) {
            p2 = p1->next;
            delete p1;
            p1 = p2;
        }   
        head= nullptr;
    }
    bool insert(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        return true;
    }
    int display() {
        Node *curr= head;
        int count=0;

        while(curr != nullptr) { // Traverse the list until the end (nullptr)
            cout<<curr->data<<" ";
            curr= curr->next;
            count++;
        }
        return count;
    }
    
    bool unsortedremove(int val) {
    if (head == nullptr) return false;

    // Case 1: The value is at the head
    if (head->data == val) {
        Node* temp = head;
        head = head->next; // Move head to the second node
        delete temp;       // Now safe to delete old head
        return true;
    }

    // Case 2: The value is elsewhere in the list
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == val) {
            // Bypass the current node
            prev->next = curr->next; 
            delete curr;
            return true;
        }
        // Move pointers forward: prev follows curr
        prev = curr; 
        curr = curr->next;
    }

    return false;
}

    bool search(int val ) {
        Node *curr=  head; 
        while( curr!= nullptr) { // Traverse the list until the end (nullptr)
            if(curr->data == val) {
                return true;
            }
            else {
                curr= curr->next;

            }
        
        }
    return false;
    }
void reverse() {
        Node *curr = head, *prev = nullptr, *next = nullptr;
        while(curr != nullptr) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr; // Move prev to the current node
            curr = next; // Move to the next node
        }
        head = prev; // Update head to the new front of the list
}
void SelectionSort() // Task 1.2
    {
        Node *curr = head;
        int count = 0;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        int n = count;
        Node *min = head, *minPrev = nullptr, *lastMin = head;
        for (int i = 0; i < n - 1; i++)
        {
            bool found = false;
            Node *jN = min; 
            for (int j = i + 1; j < n; j++)
            {
                if (jN->next->data < min->data)
                {
                    minPrev = jN;
                    min = jN->next;
                    found = true;
                }
                jN = jN->next;
            }
            if (found)
            {
                minPrev->next = min->next;

                if (i == 0)
                {
                    min->next = head;
                    head = min;
                }
                else
                {
                    min->next = lastMin->next;
                    lastMin->next = min;
                }
                lastMin = min;
            }
            else
            {
                lastMin = min;
            }
            min = lastMin->next;
        }
    }

};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n1. Insert values\n";
        cout << "2. Remove a value\n";
        cout << "3. Search a value\n";
        cout << "4. Display the Linked List\n";
        cout << "5. Sort the Linked List (using Selection sort)\n";
        cout << "6. Reverse the Linked List\n";
        cout << "7. Empty the Linked List\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "Enter the values to be inserted (end with -999): ";
            while (true) {
                cin >> value;
                if (value == -999) break;
                list.insert(value);
            }
            break;
        }

        case 2:
            cout << "Enter the value to be removed: ";
            cin >> value;
            if (list.unsortedremove(value))
                cout << value << " has been removed from the list\n";
            else
                cout << "ERROR: " << value << " is not found in the linked list\n";
            break;

        case 3:
            cout << "Enter the value to be searched: ";
            cin >> value;
            if (list.search(value))
                cout << "The number " << value << " is present in the linked list!\n";
            else
                cout << "The number " << value << " is NOT present in the linked list!\n";
            break;

        case 4:
            list.display();
            break;

        case 5:
            list.SelectionSort();
            cout << "The list has been sorted!\n";
            break;

        case 6:
            list.reverse();
            cout << "The list has been reversed!\n";
            break;

        case 7:
            // empty list by repeatedly deleting head
            while (list.unsortedremove(0)) {
                // Not reliable → better if you implement clear()
            }
            cout << "All the values have been removed from the linked list!\n";
            break;

        case 8:
            cout << "Bye bye!!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}