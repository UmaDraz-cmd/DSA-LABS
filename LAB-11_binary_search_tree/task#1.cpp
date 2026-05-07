
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


// void levelOrderTraversal()
// {
//     if(root == nullptr)
//     {
//         return;
//     }

//     queue<BSTNode*> q;

//     q.push(root);

//     while(!q.empty())
//     {
//         BSTNode* curr = q.front();
//         q.pop();
//         //this is the the best possible optionl which we can write here is the the of the 

//         cout << curr->data << " ";

//         if(curr->left != nullptr)
//         {
//             q.push(curr->left);
//         }

//         if(curr->right != nullptr)
//         {
//             q.push(curr->right);
//         }
//     }

//     cout << endl;
// }
    

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

            if(val == curr->data)
            {
                delete newNode;
                return false;
            }
            else if(val < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        // When tree is empty
        if(prnt == nullptr)
        {
            root = newNode;
            return true;
        }

        if(val > prnt->data)
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
//     int countLeaves(){
//         return countLeaves(root);
//     }
//     int countLeaves(BSTNode* curr){
//         if(curr == nullptr){
//             return 0;
//         }
//         if(curr->left == nullptr && curr->right == nullptr){
//             return 1;
//         }
//         int leftSideLeaves = countLeaves(curr->left);
//         int rightSideLeaves = countLeaves(curr->right);
//         return leftSideLeaves + rightSideLeaves;
//     }
//     int getHeight(){

//     }
//     int getHeight(BSTNode* curr){
//         if(curr == nullptr){
//             return 0;
//         }
//         int leftHeight = getHeight(curr->left);
//         int rightHeight = getHeight(curr->right);
//         if(leftHeight> rightHeight){
//             return leftHeight +1 ;
//         }
//         else{
//             return rightHeight + 1;
//         }
//     }

// int countNodes(BSTNode* curr)
// {
//     if(curr == nullptr)
//     {
//         return 0;
//     }

//     return 1 + countNodes(curr->left)
//              + countNodes(curr->right);
// }

// int countNodes()
// {
//     return countNodes(root);
// }

// int BST::countLeafNodes(BSTNode* curr)
// {
//     if(curr == nullptr)
//     {
//         return 0;
//     }

//     if(curr->left == nullptr &&
//        curr->right == nullptr)
//     {
//         return 1;
//     }

//     return countLeafNodes(curr->left)
//          + countLeafNodes(curr->right);
// }

// int BST::countLeafNodes()
// {
//     return countLeafNodes(root);
// }

// int BST::countNonLeafNodes(BSTNode* curr)
// {
//     if(curr == nullptr)
//     {
//         return 0;
//     }

//     if(curr->left == nullptr &&
//        curr->right == nullptr)
//     {
//         return 0;
//     }

//     return 1 + countNonLeafNodes(curr->left)
//              + countNonLeafNodes(curr->right);
// }

// int BST::countNonLeafNodes()
// {
//     return countNonLeafNodes(root);
// }

// int BST::countNodesWithOneChild(BSTNode* curr)
// {
//     if(curr == nullptr)
//     {
//         return 0;
//     }

//     int count = 0;

//     if( (curr->left == nullptr && curr->right != nullptr) ||
//         (curr->left != nullptr && curr->right == nullptr) )
//     {
//         count = 1;
//     }

//     return count
//          + countNodesWithOneChild(curr->left)
//          + countNodesWithOneChild(curr->right);
// }

// int BST::countNodesWithOneChild()
// {
//     return countNodesWithOneChild(root);
// }




// int BST::countNodesWithTwoChildren(BSTNode* curr)
// {
//     if(curr == nullptr)
//     {
//         return 0;
//     }

//     int count= 1;

//     if(curr->left != nullptr &&
//        curr->right != nullptr)
//     {
//         count= 1;
//     }

//     return count
//          + countNodesWithTwoChildren(curr->left)
//          + countNodesWithTwoChildren(curr->right);
// }

// int BST::countNodesWithTwoChildren()
// {
//     return countNodesWithTwoChildren(root);
// }
// //====================================================
// // FIND MINIMUM VALUE
// //====================================================

// int findMin()
// {
//     if(root == nullptr)
//     {
//         return -1;
//     }

//     BSTNode* curr = root;

//     while(curr->left != nullptr)
//     {
//         curr = curr->left;
//     }

//     return curr->data;
// }
// int findmax() {
//     if(root== nullptr) {
//         return -1;
//     }
//     BSTNode * curr= root;
//     while(curr!= nullptr) {
//         curr= curr->right;
//     }
//     return curr->data;
// // }
// // isBST()
// // isEmpty()
// // isFullBinaryTree()
// // isCompleteBinaryTree()
// // isPerfectBinaryTree()
// // // isBalanced()
// // sumNodes()
// // sumLeafNodes()
// // countEvenNodes()
// // countOddNodes()
// // findLargestEven()
// // findSmallestOdd()
// // findParent(int val)
// // findSibling(int val)
// // findAncestor(int val)
// // // lowestCommonAncestor(int a, int b)
// // printRootToLeafPaths()
// // sumRootToLeafPaths()
// //====================================================
// // PRINT ROOT TO LEAF PATHS
// //====================================================

// // void BST::printRootToLeafPaths(BSTNode* curr, int path[], int pathLen)
// // {
// //     if(curr == nullptr)
// //     {
// //         return;
// //     }

// //     path[pathLen] = curr->data;
// //     pathLen++;

// //     // Leaf node
// //     if(curr->left == nullptr &&
// //        curr->right == nullptr)
// //     {
// //         for(int i = 0; i < pathLen; i++)
// //         {
// //             cout << path[i] << " ";
// //         }

// //         cout << endl;
// //         return;
// //     }

// //     printRootToLeafPaths(curr->left, path, pathLen);
// //     printRootToLeafPaths(curr->right, path, pathLen);
// // }

// // void printRootToLeafPaths()
// // {
// //     int path[100];
// //     printRootToLeafPaths(root, path, 0);
// // }
// //====================================================
// // SUM OF ROOT TO LEAF PATHS
// //====================================================

// int sumRootToLeafPaths(BSTNode* curr, int sum)
// {
//     if(curr == nullptr)
//     {
//         return 0;
//     }

//     sum = sum + curr->data;

//     // Leaf node
//     if(curr->left == nullptr &&
//        curr->right == nullptr)
//     {
//         return sum;
//     }

//     return sumRootToLeafPaths(curr->left, sum)
//          + sumRootToLeafPaths(curr->right, sum);
// }

// int sumRootToLeafPaths()
// {
//     return sumRootToLeafPaths(root, 0);
// }
// //====================================================
// // FIND SMALLEST ODD VALUE
// //====================================================

// // int findSmallestOdd(BSTNode* curr)
// // {
// //     if(curr == nullptr)
// //     {
// //         return 99999;
// //     }

// //     int left = findSmallestOdd(curr->left);
// //     int right = findSmallestOdd(curr->right);

// //     int smallest = 99999;

// //     if(curr->data % 2 != 0)
// //     {
// //         smallest = curr->data;
// //     }

// //     if(left < smallest)
// //     {
// //         smallest = left;
// //     }

// //     if(right < smallest)
// //     {
// //         smallest = right;
// //     }

// //     return smallest;
// // }
// // int findSmallestOdd()
// // {
// //     return findSmallestOdd(root);
// // }
// void invert_tree(Bstnode * node)
// {
//     if(node==nullptr)
//     {
//         return;
//     }
//     Bstnode *temp=node->left; 
//     node->left=node->right;
//     node->right=temp;
//     invert_tree(node->left);
//     invert_tree(node->right);
// }
//====================================================
// FIND SIBLING OF A NODE
//====================================================

int BST::findSibling(int val)
{
    if(root == nullptr || root->data == val)
    {
        return -1;
    }

    BSTNode* curr = root;

    while(curr != nullptr)
    {
        // left child check
        if(curr->left != nullptr &&
           curr->left->data == val)
        {
            if(curr->right != nullptr)
            {
                return curr->right->data;
            }

            return -1;
        }

        // right child check
        if(curr->right != nullptr &&
           curr->right->data == val)
        {
            if(curr->left != nullptr)
            {
                return curr->left->data;
            }

            return -1;
        }

        if(val < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    return -1;
}

//====================================================
// FIND PARENT OF A NODE
//====================================================

int BST::findParent(int val)
{
    if(root == nullptr || root->data == val)
    {
        return -1;
    }

    BSTNode* curr = root;
    BSTNode* parent = nullptr;

    while(curr != nullptr)
    {
        if(curr->data == val)
        {
            return parent->data;
        }

        parent = curr;

        if(val < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    return -1;
}
//====================================================
// FIND ANCESTORS OF A NODE
//====================================================

void BST::findAncestor(int val)
{
    BSTNode* curr = root;

    while(curr != nullptr)
    {
        if(curr->data == val)
        {
            return;
        }

        cout << curr->data << " ";

        if(val < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    cout << "Value not found";
}
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

    //========================================
    // SEARCH FUNCTION
    //========================================

    int value;

    cout << "Enter value to search: ";
    cin >> value;

    if(tree.Search(value))
    {
        cout << value << " found in BST.\n";
    }
    else
    {
        cout << value << " not found in BST.\n";
    }

    cout << endl;

    //========================================
    // REMOVE FUNCTION
    //========================================

    cout << "Enter value to remove: ";
    cin >> value;

    if(tree.remove(value))
    {
        cout << value << " deleted successfully.\n";
    }
    else
    {
        cout << value << " not found.\n";
    }

    cout << endl;

    //========================================
    // DISPLAY AFTER DELETION
    //========================================

    cout << "Inorder Traversal After Deletion: ";
    tree.displayInOrder();

    return 0;
}
