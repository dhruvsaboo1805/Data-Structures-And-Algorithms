#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this-> data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        while(this->next != NULL )
        {
            delete next;
            next = NULL;
        }
        cout<<"the message has been deleted "<<value<<endl;
    }
};

void Insert(Node* &tail,int element, int data)
{
    // element = after which the data to be added

    // list is emepty
    if(tail == NULL)
    {
        Node * newnode = new Node(data);
        tail = newnode;
        newnode ->next = newnode; // since CIRCULAR LL

    }

    else{
        Node *curr = tail;

        while(curr -> data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp ->next = curr->next;
        curr->next = temp;
    }
}

void print(Node * &tail)
{
    if(tail == NULL)
    {
        cout<<"list is empty"<<endl;
    }
    Node *temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
}

// int getlength(Node *& tail)
// {
//     int len = 0;
//     Node*temp = tail;
//     while(temp->next = tail)
//     {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

void Delete(Node* &tail,int element)
{
    // if list is empty
    if(tail == NULL)
    {
        cout<<"invalid not possible"<<endl;
        return;
    }
    else{
        Node *prev = tail;
        Node *curr = prev->next;
        
        while(curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // if linked list has 1 node
        if(curr == prev)
        {
            tail = NULL;
        }

        // if linked list has >= 2 nodes
        else if(tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
   
   Insert(tail ,5,3);
   print(tail);
   cout<<endl;
   Insert(tail ,3,4);
   print(tail);
   cout<<endl;
   Insert(tail ,4,6);
   print(tail);
   cout<<endl;
   Insert(tail ,4,5);
   print(tail);
   cout<<endl;
   Delete(tail,3);
   print(tail);

   return 0;
}