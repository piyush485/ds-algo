#include <iostream>
#include <algorithm>
using namespace std;

class Queue
{
    int size;
    int *queue;

public:
    Queue(Queue q1, Queue q2)
    {
        size = 0;
        queue1 = q1;
        queue2 = q2;
    }
    Queue operator+(Queue q)
    {
        int s;
        Queue res;
        s = sizeof(q1) + sizeof(q);
        for (int i = 0; i < s; i++)
        {
            if (i < sizeof(q1))
                q3[i] = q1[i];
            else
                q3[i] = q[i];
        }
        return res;
    }
    
    void add(int data)
    {
        queue[size] = data;
        size++;
    }
    void remove()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < size - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            size--;
        }
    }
    void print()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << queue[i] << " <- ";
        }
        cout << endl;
    }
    //your code goes here
};
int main()
{
    Queue q1;
    q1.add(42);
    q1.add(2);
    q1.add(8);
    q1.add(1);
    Queue q2;
    q2.add(3);
    q2.add(66);
    q2.add(128);
    q2.add(5);
    Queue q4(q1, q2);
    Queue q3 = q1 + q2;
    q3.print();
    return 0;
}