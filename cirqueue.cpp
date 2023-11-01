#include<iostream>

using namespace std;

class CirQueue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;

    }

    void push(int data)
    {
        if((front == 0 && rear == size-1) || rear == front - 1)
        {
            cout<<"q is full"<<endl;
        }
        else if(front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size  -1 && front !=0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        if(front == -1)
        {
            cout<<"q is empty"<<endl;
        }
        else if (front == rear)
        {
            // arr[front] = -1;
            front = -1;
            rear = -1;  
        }
        else if(rear == 0)
        {
            front = 0;
        }
        else 
        {
            front++;
        }

    }

    int Size()
    {
        return rear - front + 1;
    }

    int Front()
    {
        return arr[front];
    }
};

int main()
{
    CirQueue qt(5);

    qt.push(10);
    qt.push(20);
    qt.push(30);
    qt.push(40);
    qt.push(50);

    cout<<qt.Size()<<endl;

    qt.pop();
    qt.pop();
    qt.pop();
    
    cout<<qt.Size()<<endl;
    cout<<qt.Front()<<endl;


    
}