#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Queue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        // when queue is full
        if(rear == size && front == 0)
        {
            cout<<"q is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if(rear == front)
        {
            cout<<"q is emepty"<<endl;
        }
        else
        {
            front++;
            if(rear == front)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getsize()
    {
        return rear - front;
    }

    bool empty()
    {
        if(front == rear)
        return true;
        else
        return false;
    }

    int getfront()
    {
        if(rear == front)
        {
            cout<<"q is emepty"<<endl;
        }
        else
        return arr[front];
    }
};

void reverseQueue(queue<int> &qt)
{
    // step 1 craete stack
    stack<int> st;
    // steap 2 put all elements of queue in to stack
    while(!qt.empty())
    {
        int element = qt.front();
        qt.pop();

        st.push(element);
    }

    // step 3
    while(!st.empty())
    {
        int element = st.top();
        st.pop();

        qt.push(element);
    }
}

void reverseRec(queue<int> &qt)
{
    // base case
    if(qt.empty())
    {
        return;
    }
    // 1 case baaaki rec
    int temp = qt.front();
    qt.pop();

    reverseRec(qt);
    // backtarck
    qt.push(temp);
}

void ReverseK(queue<int> &qt, int k)
{
    stack<int> st;
    int count = 0;
    // step 2 insert k elements in the stack
    while(!qt.empty())
    {
        int element = qt.front();
        qt.pop();
        st.push(element);
        count++;
        if(count == k)
        {
            break;
        }
    }
    while(!st.empty())
    {
        int element = st.top();
        st.pop();

        qt.push(element);
    }
    count =0;
    int n = qt.size();

    while(!qt.empty())
    {
        int element = qt.front();
        qt.pop();
        qt.push(element);
        count++;
        
        if(count == (n-k))
        {
            break;
        }
    }

}

void Interleave(queue<int> &qt)
{
    queue<int> q2;
    int count = 0;
    int k = qt.size()/2;
    if(qt.empty())
    cout<<"ohhhhh!!!"<<endl;

    // step 1 making two halfs
    while(!qt.empty())
    {
        int temp = qt.front();
        qt.pop();

        q2.push(temp);
        count++;
        if(count == k)
        break;
    }
    
    // interleaving starts
    while(!qt.empty() && !q2.empty())
    {
        int first = q2.front();
        q2.pop();

        qt.push(first);

        int second = qt.front();
        qt.pop();

        qt.push(second);
    }

    if(qt.size() &1)
    {
        int temp = qt.front();
        qt.pop();
        qt.push(temp);
    }

}


void Solve(int arr[], int size,int k)
{
    queue<int> q;
    // processing k elements first
    for(int i = 0 ; i<k; i++)
    {
        if(arr[i] < 0)
        {
            q.push(i);
        }
    }

    // ab bacche hue element ka kaam karna hain
    for(int i = k; i<size; i++)
    {
        //checking if queue is empty or not
        if(q.empty())
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<arr[q.front()]<<endl;
        }
        // deleting old element in window and processing new eleemnt 
        while((!q.empty()) && (i-q.front() >= k))                         // dhruv beta tum ye hi bhulonge joblesss addmey
        {
            q.pop();
        }

        if(arr[i] < 0)
        {
            q.push(i);
        }
    }

    if(q.empty())
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<arr[q.front()]<<endl;
        }
}
int main()
{
    // queue<int> qt;
    // qt.push(2);
    // qt.push(3);
    // qt.push(4);
    // qt.push(5);

    // cout<<qt.size()<<endl;
    // qt.pop();
    // cout<<qt.size()<<endl;
    // if(qt.empty())
    // {
    //     cout<<"goood"<<endl;
    // }
    // else
    // cout<<"bad"<<endl;




    // Queue q(4);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);

    // cout<<q.getsize()<<endl;

    // q.pop();
    // q.pop();

    // cout<<q.getsize()<<endl;

    // cout<<q.getfront()<<endl;
    // q.pop();
    // q.pop();

    // if(q.empty())
    // {
    //     cout<<"good"<<endl;
    // }
    // else
    // {
    //     cout<<"bad"<<endl;

    // }




    // reverse the queue using stack




    // queue<int> qt;

    // qt.push(10);
    // qt.push(20);
    // qt.push(30);
    // qt.push(40);
    // qt.push(50);


// // cout<<"without recursion"<<endl;
// //     reverseQueue(qt);
// //     while(!qt.empty())
// //     {
// //         cout<<qt.front()<<" ";
// //         qt.pop();
// //     }cout<<endl;


//   cout<<"with recursion"<<endl;

//     reverseRec(qt);
    // while(!qt.empty())
    // {
    //     cout<<qt.front()<<" ";
    //     qt.pop();
    // }cout<<endl;



// REVERSE FIRST K ELEMENTS IN THE QUEUE

    // queue<int> qt;

    // qt.push(10);
    // qt.push(20);
    // qt.push(30);
    // qt.push(40);
    // qt.push(50);

    // ReverseK(qt,1);

    // while(!qt.empty())
    // {
    //     cout<<qt.front()<<" ";
    //     qt.pop();
    // }cout<<endl;



    // interleaving two queues



    // queue<int> qt;

    // qt.push(10);
    // qt.push(20);
    // qt.push(30);
    // qt.push(40);
    // qt.push(50);
    // qt.push(60);
    // qt.push(70);
    // // qt.push(80);

    // Interleave(qt);

    // while(!qt.empty())
    // {
    //     cout<<qt.front()<<" ";
    //     qt.pop();
    // }cout<<endl;



    // FIRST -VE INTEGER IN EVERY WINDOW OF SIZE K

    int arr[] = {-8,2,3,-6,10};
    int size = 5;
    int k = 2;

    Solve(arr,size,k);

    // for(int i = 0; i <size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }cout<<endl;



    

}