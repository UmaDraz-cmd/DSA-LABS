# pragma once
class Deque{
    private:
        int* q;
        int currSize;
        int maxSize;
        int front;
        int back;
    public:
        Deque(int n);
        ~Deque();
        Deque(const Deque& );
        Deque& operator=(const Deque);
        bool isEmpty()const;
        bool isFull()const;
        // bool enqueue(int );
        // bool dequeue(int& );
        void display();
        void  makeEmpty();
        bool insertAtFront(int val);
        bool insertAtBack(int val);
        bool removeFromFront(int& val);
        bool removeFromBack(int& val);
};