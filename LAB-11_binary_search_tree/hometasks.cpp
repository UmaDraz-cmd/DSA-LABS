#include <iostream>

using namespace std;

class BST;

class BSTNode
{
    friend class BST;

private:
    int data;
    BSTNode* left;
    BSTNode* right;

public:
    BSTNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    BSTNode* root;
    bool recSearch (BSTNode* b, int key){
        if(b == nullptr){
            return false;
        }
        if(b->data == key){
            return true;
        }
        else if(b->data < key){
            return recSearch(b->right,key);
        }
        else{
            return recSearch(b->left,key);
        }
    }
    // private (workhorse function) 

    void displayInOrder(BSTNode* curr)
    {
        if(curr == nullptr)
        {
            return;
        }

        displayInOrder(curr->left);
        cout << curr->data << " ";
        displayInOrder(curr->right);
    }

    void displayPreOrder(BSTNode* curr)
    {
        if(curr == nullptr)
        {
            return;
        }

        cout << curr->data << " ";
        displayPreOrder(curr->left);
        displayPreOrder(curr->right);
    }

    void displayPostOrder(BSTNode* curr)
    {
        if(curr == nullptr)
        {
            return;
        }

        displayPostOrder(curr->left);
        displayPostOrder(curr->right);
        cout << curr->data << " ";
    }
    public:

    BST()
    {
        root = nullptr;
    }

    bool Search(int val)
    {
        BSTNode* temp = root;

        while(temp != nullptr)
        {
            if(temp->data == val)
            {
                return true;
            }
            else if(temp->data > val)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        return false;
    }
    bool recSearch(int key) {
        return recSearch(root, key);
    }

    void displayInOrder()
    {
        displayInOrder(root);
        cout << endl;
    }

    void displayPreOrder()
    {
        displayPreOrder(root);
        cout << endl;
    }

    void displayPostOrder()
    {
        displayPostOrder(root);
        cout << endl;
    }

    bool insert(int val)
    {
        BSTNode* newNode = new BSTNode;
        newNode->data = val;

        BSTNode* curr = root;
        BSTNode* prnt = nullptr;

        while(curr != nullptr)
        {
            prnt = curr;

            if(val == curr->data) // No duplicate values allowed
            {
                delete newNode;
                return false;
            }
            else if(val < curr->data) // Go to left subtree
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right; // Go to right subtree
            }
        }

        // When tree is empty
        if(prnt == nullptr) //
        {
            root = newNode; // New node becomes the root
            return true;
        }

        if(val > prnt->data) //
        {
            prnt->right = newNode;
        }
        else
        {
            prnt->left = newNode;
        }

        return true;
    }

    bool remove(int val)
    {
        BSTNode* curr = root;
        BSTNode* prnt = nullptr;

        while(curr != nullptr && curr->data != val)
        {
            prnt = curr;

            if(val < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if(curr == nullptr)
        {
            return false;
        }

        // Conversion of Degree 2 to Degree 1
        if(curr->left != nullptr && curr->right != nullptr)
        {
            BSTNode* successor = curr->right;
            BSTNode* prntSuc = curr;

            while(successor->left != nullptr)
            {
                prntSuc = successor;
                successor = successor->left;
            }

            curr->data = successor->data;
            curr = successor;
            prnt = prntSuc;
        }

        // Deletion of Degree 1 or 0
        BSTNode* child;

        if(curr->left != nullptr)
        {
            child = curr->left;
        }
        else
        {
            child = curr->right;
        }

        if(prnt == nullptr)
        {
            root = child;
        }
        else if(curr == prnt->left)
        {
            prnt->left = child;
        }
        else
        {
            prnt->right = child;
        }

        delete curr;
        curr = nullptr;

        return true;
    }
    // int getHeight() {
    //     BSTNode* curr= root;
    //     if(curr != nullptr) {
    //         return 0;
    //     }
    //     else {
    //         return 1+getHeight(curr->left);
    //     }
    // }
    int getHeight() {
        getHeight(root);
        
    } 
int getHeight(BSTNode* curr){
        if(curr == nullptr){
            return 0;
        }
        int leftHeight = getHeight(curr->left);
        int rightHeight = getHeight(curr->right);
        if(leftHeight> rightHeight){
            return leftHeight +1 ;
        }
        else{
            return rightHeight + 1;
        }
    }
    //count Nodes of treee 
int countNodes(BSTNode* curr)
{
    if(curr == nullptr)
    {
        return 0;
    }

    return 1 + countNodes(curr->left)
             + countNodes(curr->right);
}

int countNodes()
{
    return countNodes(root);
 }
//  int findMin() {
//     BSTNode *curr= root;
//     if(root==nullptr) {
//         return 0;
//     }
//     while(curr!= nullptr) {
//         curr= curr->left;
//     }
//     return curr->data;
//  }
 int findMin()
{
    if(root == nullptr)
    {
        return -1;
    }

    BSTNode* curr = root;

    while(curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr->data;
}
int findMax()
{
    if(root == nullptr)
    {
        return -1;
    }

    BSTNode* curr = root;

    while(curr->right != nullptr)
    {
        curr = curr->right;
    }

    return curr->data;
}
int findMaxrec() {
    findMaxrec(root);
}
int findMaxrec(BSTNode *curr) {
    if(curr== nullptr) {
      return -1;
    }
    
    if( curr->right == nullptr) {
        return curr->data;
    }
    return findMaxrec(curr->right);
}

int findMinrec() {
    findMinrec(root);
}
int findMinrec(BSTNode *curr) {
    if(curr== nullptr) {
      return -1;
    }
    
    if( curr->right == nullptr) {
        return curr->data;
    }
    return findMinrec(curr->right);
}
// void createBalancedTree(int arr, int start, int end) {
//     root= createBalancedTree(arr, start, end);
// }
// void createBalancedTree (int* arr, int start, int end) {
//     if(start>end) {

//     }
//     int mid= (start+end)/2;
//     BSTNode *curr = new BSTNode(arr[mid]) ;
//     curr->right = createBalancedTree(arr, start, mid-1);
//     curr->left= createBalancedTree(arr,mid+1,end);
//     return curr;

// }
//  
};
int main()
{
    BST tree;

    //========================================
    // INSERTION
    //========================================

    tree.insert(50);
    tree.insert(30);
    tree.insert(80);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(90);

    cout << "Tree created successfully.\n\n";

    //========================================
    // INORDER TRAVERSAL
    //========================================

    cout << "Inorder Traversal: ";
    tree.displayInOrder();

    //========================================
    // PREORDER TRAVERSAL
    //========================================

    cout << "Preorder Traversal: ";
    tree.displayPreOrder();

    //========================================
    // POSTORDER TRAVERSAL
    //========================================

    cout << "Postorder Traversal: ";
    tree.displayPostOrder();

    cout << endl;

    // //========================================
    // // SEARCH FUNCTION
    // //========================================

    // int value;

    // cout << "Enter value to search: ";
    // cin >> value;

    // if(tree.Search(value))
    // {
    //     cout << value << " found in BST.\n";
    // }
    // else
    // {
    //     cout << value << " not found in BST.\n";
    // }

    // cout << endl;

    // //========================================
    // // REMOVE FUNCTION
    // //========================================

    // cout << "Enter value to remove: ";
    // cin >> value;

    // if(tree.remove(value))
    // {
    //     cout << value << " deleted successfully.\n";
    // }
    // else
    // {
    //     cout << value << " not found.\n";
    // }

    // cout << endl;

    //========================================
    // DISPLAY AFTER DELETION
    //========================================

    cout << "Inorder Traversal After Deletion: ";
    tree.displayInOrder();
    cout<<endl<<"Height of the tree is: "<<tree.getHeight()<<endl;
    cout<<"Total Nodes are: "<<tree.countNodes()<<endl;
    cout<<"Min Node iteratively: "<<tree.findMin()<<endl;
    cout<<"Max Node iteratively: "<<tree.findMax()<<endl;
    cout<<"Min Node recursively: "<<tree.findMin()<<endl;

    cout<<"Max Node recursively: "<<tree.findMaxrec()<<endl;


    return 0;
}
