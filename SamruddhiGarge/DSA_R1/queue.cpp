#include <iostream>
#include<conio.h>
using namespace std;

#define MAX 100
class Queue {
    int arr[MAX];
    int front, rear, count;

public:
    Queue() 
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) 
    {
        if (count == MAX) return;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        count++;
    }

    int dequeue() 
    {
        if (count == 0) return -1;
        int val = arr[front];
        front = (front + 1) % MAX;
        count--;
        return val;
    }

    int getFront()
     {
        if (count == 0) return -1;
        return arr[front];
    }

    int size()
     { 
        return count;
    
    }

    void display()
     {
        int i = front;
        for (int j = 0; j < count; j++)
         {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }


    void rotate()
     {
        enqueue(dequeue());
    }


    void reverseFirstK(int k)
     {
        if (k <= 0 || k > count) return;

     
        int temp[MAX];
        for (int i = 0; i < k; i++) 
        {
            temp[i] = dequeue();
        }

    
        for (int i = k - 1; i >= 0; i--) 
        {
            enqueue(temp[i]);
        }

       
        int rem = count - k;
        for (int i = 0; i < rem; i++)
         {
            rotate();
        }
    }
};

int main() 
{
    Queue q;
    int n, k, val;

    cout << "Enter no. of elements in the queue: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Original: ";
    q.display();

    q.reverseFirstK(k);

    cout << "Queue after reversing first " << k << " elements: ";
    q.display();

    return 0;
}
