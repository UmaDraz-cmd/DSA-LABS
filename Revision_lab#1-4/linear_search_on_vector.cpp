#include<iostream>
#include<vector>
using namespace std;
int linearsearch(vector<int> &vec, int key) {
    for(int i=0; i<vec.size(); i++) {
        if(vec[i] == key) {
            return i;
        }
    }
    return -1;

}
int main() {
    int size, key;
    cout << "Enter the size of the vector: ";
    cin >> size;
    vector<int> vec(size);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < size; i++) {
        cin >> vec[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    int idx = linearsearch(vec, key);
    if(idx != -1) {
        cout << "The key " << key << " appears at idx: " << idx << " in the vector." << endl;
    }
    else {
        cout << "The key " << key << " is not found in the vector." << endl;
    }
}