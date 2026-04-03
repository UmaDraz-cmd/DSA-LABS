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
    LinkedList(const LinkedList& other) {
        head = nullptr;
        if(other.head == nullptr) {
            return;
        }
        head = new Node;
        head->data = other.head->data;
        head->next = nullptr;

        Node* currentOther = other.head->next;
        Node* currentThis = head;

        while(currentOther != nullptr) {
            Node* newNode = new Node;
            newNode->data = currentOther->data;
            newNode->next = nullptr;

            currentThis->next = newNode;
            currentThis = newNode;
            currentOther = currentOther->next;
        }
    }
    LinkedList& operator=(const LinkedList& other) {
        if(this == &other) {
            return *this;
        }
        // Clean up existing list
        Node *p1= head, *p2= nullptr;
        while(p1 != nullptr) {  
            p2 = p1->next;
            delete p1;
            p1 = p2;
        }
        head = nullptr; 
        if(other.head == nullptr) {
            return *this;
        }
        head = new Node;
        head->data = other.head->data;
        head->next = nullptr;   
        Node* currentOther = other.head->next;
        Node* currentThis = head;
        while(currentOther != nullptr) {
            Node* newNode = new Node;
            newNode->data = currentOther->data;
            newNode->next = nullptr;
            currentThis->next = newNode;
            currentThis = newNode;
            currentOther = currentOther->next;
        }
        return *this;
    }
    //display function to display the linked list
    void display()  {
        Node* curr= head;
        //cout<<curr->data<<" ";
        while(curr != nullptr) {
            
            cout<<curr->data<<" ";
            curr= curr->next;
        }
        cout<<endl; 
    }
    //insert at start function to insert a node at the beginning of the linked list
    void insertAtstart(int val) {
        Node *temp = new Node;
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    void insertAtEnd(int val) {
        Node *temp = new Node;
        temp->data = val;
        temp->next = nullptr; // created a new node and stored the value in it and 
                              //made the next of it to null because it is going to be the last node

        Node *curr = head, *prev= nullptr;
        while(curr != nullptr) {
            prev = curr;     // here we are storing the current node in prev before moving to the next node because we need to update the next of the last node to point to the new node
            curr = curr->next;
        }
        if(prev == nullptr) {
            head = temp; // if the list is empty, make the new node the head
        } else {
            prev->next = temp;
        }
    }
    //TASK 1: function to remove the kth node from the linked list and return its value
    bool removeKthNode(int k, int& val) {
        if(k < 1) {
            return false; // Invalid value of k
        }
        Node *curr = head, *prev = nullptr;
        int count = 1;
        while(curr != nullptr && count < k) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr == nullptr) {
            return false; // k is greater than the number of nodes in the list
        }
        val = curr->data; // Store the value of the removed node
        if(prev == nullptr) {
            head = curr->next; // Removing the head node
        } else {
            prev->next = curr->next; // Bypass the current
        }
        delete curr; // Free the memory of the removed node
        return true;
    }
    //Task#2  combine two linked lists into one linked list by alternating the nodes of the two lists
    void combine(LinkedList& list1,LinkedList& list2)
    {
        if(list1.head == nullptr && list2.head == nullptr){
            head = nullptr;
        }
        else if(list1.head == nullptr){
            head= list2.head;
            list2.head= nullptr;


        }
        else if(list2.head== nullptr) {
            head= list1.head;
            list1.head= nullptr;
        }
        else {
            head= list1.head;
            Node *temp= head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next= list2.head;
            list1.head= nullptr;
            list2.head= nullptr;

        }
    } 
    void shuffleMerge(LinkedList& list1, LinkedList& list2) {
    //to check if both lists are of same size 
    int size1 = 0, size2 = 0;

    Node* curr1 = list1.head;   //  fixed semicolon
    Node* curr2 = list2.head;

    while(curr1 != nullptr) {
        size1++;
        curr1 = curr1->next;
    }
    while(curr2 != nullptr) {   
        size2++;
        curr2 = curr2->next;
    }

    if(list1.head == nullptr && list2.head == nullptr && size1 != size2) {
        head = nullptr;
        return;
    }

    //  reset pointers (IMPORTANT fix)
    curr1 = list1.head;
    curr2 = list2.head;

    Node *prev = nullptr;

    while(curr1 != nullptr && curr2 != nullptr) {
        if(prev == nullptr) {
            head = curr1;
            prev = head;
            curr1 = curr1->next;
        } else {
            prev->next = curr2;
            prev = prev->next;
            curr2 = curr2->next;

            if(curr1 != nullptr) {
                prev->next = curr1;
                prev = prev->next;
                curr1 = curr1->next;
            }
        }
    }

    list1.head = nullptr;
    list2.head = nullptr;
}
     


//Task#4 -- functiion to remove the last node 
bool removeLastNode(int &val) {
    if(head == nullptr) {
        return false; // List is empty
    }
    if(head->next == nullptr) {
        val = head->data; // Store the value of the last node
        delete head; // Free the memory of the last node
        head = nullptr; // Update head to nullptr
        return true;
    }
    Node *curr = head, *prev = nullptr;
    while(curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    val = curr->data; // Store the value of the last node
    delete curr; // Free the memory of the last node
    prev->next = nullptr; // Update the next of the second last node to nullptr
    return true;
}
// function to remove the second last node and return its value
bool removesecondLastNode(int &val) {
    if(head == nullptr || head->next == nullptr) {
        return false; // List is empty or has only one node
    }
    Node *curr = head, *prev = nullptr, *secondLast = nullptr;
    while(curr->next != nullptr) {
        secondLast = prev;
        prev = curr;
        curr = curr->next;
    }
    val = prev->data; // Store the value of the second last node
    if(secondLast == nullptr) {
        head = curr; // If there are only two nodes, update head to the last node
    } else {
        secondLast->next = curr; // Bypass the second last node
    }
    delete prev; // Free the memory of the second last node
    return true;
}
//Task#5 -- function to count Nodes in the linked list
int countNodes() {
int count=0; 
Node *curr= head;
while(curr != nullptr) {
    count++;
    curr= curr->next;
}
return count; 

}
//function to find Minimum 
int findMin() {

Node *curr = head;
if(curr == nullptr) {
    return -999;
}
int temp= curr->data;
while(curr!= nullptr) {
    if(curr->data<temp) {
        temp= curr->data;


    }
    
    curr= curr->next;
}
return temp;
}

//function to find Maximum in the linked list
int findMax() {

Node *curr = head;
if(curr == nullptr) {
    return -999;
}
int temp= curr->data;
while(curr!= nullptr) {
    if(curr->data>temp) {
        temp= curr->data;
        


    }
    curr= curr->next;
}
return temp;
}
};



// Assume LinkedList class is already implemented

//  TASK 1 DRIVER
void driverTask1() {
    cout << "\n--- Task 1: removeKthNode ---\n";

    LinkedList list;

    list.insertAtEnd(4);
    list.insertAtEnd(2);
    list.insertAtEnd(8);
    list.insertAtEnd(1);
    list.insertAtEnd(9);

    cout << "Original List: ";
    list.display();

    int val;
    if(list.removeKthNode(3, val)) {
        cout << "Removed value: " << val << endl;
    } else {
        cout << "Removal failed.\n";
    }

    cout << "Updated List: ";
    list.display();
}

//  TASK 2 DRIVER
void driverTask2() {
    cout << "\n--- Task 2: combine ---\n";

    LinkedList list1, list2, list3;

    list1.insertAtEnd(7);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);

    list2.insertAtEnd(5);
    list2.insertAtEnd(9);

    cout << "List1: ";
    list1.display();

    cout << "List2: ";
    list2.display();

    list3.combine(list1, list2);

    cout << "Combined List: ";
    list3.display();
}

//  TASK 3 DRIVER
void driverTask3() {
    cout << "\n--- Task 3: shuffleMerge ---\n";

    LinkedList list1, list2, list3;

    list1.insertAtEnd(2);
    list1.insertAtEnd(6);
    list1.insertAtEnd(4);

    list2.insertAtEnd(8);
    list2.insertAtEnd(1);
    list2.insertAtEnd(3);

    cout << "List1: ";
    list1.display();

    cout << "List2: ";
    list2.display();

    list3.shuffleMerge(list1, list2);

    cout << "Shuffled List: ";
    list3.display();
}

//  TASK 4 DRIVER
void driverTask4() {
    cout << "\n--- Task 4: removeLast & removeSecondLast ---\n";

    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original List: ";
    list.display();

    int val;

    if(list.removeLastNode(val)) {
        cout << "Removed Last Node: " << val << endl;
    }

    cout << "After removing last: ";
    list.display();

    if(list.removesecondLastNode(val)) {
        cout << "Removed Second Last Node: " << val << endl;
    }

    cout << "After removing second last: ";
    list.display();
}

//  TASK 5 DRIVER
void driverTask5() {
    cout << "\n--- Task 5: count, min, max ---\n";

    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(5);
    list.insertAtEnd(20);
    list.insertAtEnd(3);

    cout << "List: ";
    list.display();

    cout << "Count: " << list.countNodes() << endl;
    cout << "Min: " << list.findMin() << endl;
    cout << "Max: " << list.findMax() << endl;
}


//  MAIN FUNCTION
int main() {

    driverTask1();
    driverTask2();
    driverTask3();
    driverTask4();
    driverTask5();

    return 0;
}

