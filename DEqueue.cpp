#include<iostream>
// #include<dequeue>

using namespace std;

class dequeue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;

    }

    void pushRear(int data)
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

    void pushFront(int data)
    {
        if((front == 0 && rear == size-1) || rear == front - 1)
        {
           cout<<"q is full"<<endl; 
        }
        else if(front == -1)
        {
            front = rear = 0;
            arr[front] = data;
        }
        else if(rear != size  -1 && front == 0)
        {
            front == size - 1;
            arr[front] = data;
        }
        else
        {
            front--;
            arr[front] = data;
        }
    }

    void popFront()
    {
        if(front == -1)
        {
            cout<<"q is empty"<<endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;  
        }
        else if(front == size-1)
        {
            arr[front] = -1;
            front = 0;
        }
        else 
        {
            arr[front] = -1;
            front++;
        }
    }

    void popRear()
    {
        if(front == -1)
        {
            cout<<"q is empty"<<endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;  
        }
        else if(front == 0)
        {
            arr[rear] = -1;
            rear = size-1;
        }
        else{
            arr[rear] = -1;
            rear--;
        }
    }

    void print()
    {
        for(int i = 0 ;i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    

};

int main()
{
//     deque<int> dq;

//   dq.push_front(5);
//   dq.push_front(10);
//   dq.push_back(20);
//   dq.push_back(30);

//   cout << "Size: " << dq.size() << endl;
//   dq.pop_front();
//   cout << "Size: " << dq.size() << endl;
//   dq.pop_back();
//   cout << "Size: " << dq.size() << endl;

//   cout << "Front:  " << dq.front() << endl;
//   cout << "back: " << dq.back() << endl;

//   if(dq.empty() ) {
//           cout << "DQ is empty" << endl;
//   }
//   else{
//           cout << "DQ is not empty" << endl;
//   }


dequeue dq(10);

  dq.pushRear(10);
  dq.pushRear(20);
  dq.pushRear(30);
  dq.pushRear(40);
  dq.pushRear(50);
  dq.pushRear(60);
  dq.pushRear(70);
  dq.pushRear(80);
  dq.print();

//   dq.print();
  cout<<endl;
  dq.popRear();
  dq.print();
 cout<<endl;
  dq.popRear();
  dq.print();
 cout<<endl;
  dq.popFront();
  dq.print();

//     dq.popFront();
//   dq.print();

//     dq.popFront();
//   dq.print();

//   dq.pushFront(101);
//   dq.print();

//   dq.pushFront(102);
//   dq.print();

//   dq.pushFront(103);
//   dq.print();

//     dq.pushFront(104);
//   dq.print();

//   dq.popFront();
//   dq.print();

//   dq.popFront();
//   dq.print();

//   dq.pushRear(201);
//   dq.print();

//     dq.pushRear(202);
//   dq.print();

//     dq.pushRear(203);
//   dq.print();
//     dq.pushRear(204);
//   dq.print();

//     dq.pushRear(205);
//   dq.print();



}