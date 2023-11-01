#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
         this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        while(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"the message of the given value "<<value<<"is been deleted"<<endl;
    }
};

void Insert(Node* &tail, int element, int data)
{
    // element is the value after which the data is to be inserted
    Node* head;
    if(tail == NULL)
    {
        // if CDLL is empty
        Node* newnode = new Node(data);
        tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;

    }
    

    else
    {
        Node* curr = tail;
        while(curr-> data != element)
        {
            curr = curr->next;
        }
        Node* temp = new Node(data);
        temp->prev = curr;
        curr->next = temp;
        temp->next = head;
        head->prev = temp;
       
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

void Delete(Node* &tail,int element)
{
    // if list is empty
    if(tail == NULL)
    {
        cout<<"invalid"<<endl;
    }
    
}


int main()
{
    Node* tail = NULL;

    Insert(tail,10,20);
    print(tail);
    cout<<endl;
    Insert(tail,20,30);
    print(tail);
    cout<<endl;
    Insert(tail,30,55);
    print(tail);
    cout<<endl;
    Insert(tail,55,40);
    print(tail);
    cout<<endl;
    Insert(tail,40,50);
    print(tail);
    cout<<endl;
    Insert(tail,50,60);
    print(tail);
    cout<<endl;

    return 0;
}