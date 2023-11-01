#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *prev;
    Node*next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        cout<<"deleting the data is "<<this->data<<endl;
    }

};

void PrintDLL(Node* &head)
{
    Node*temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int GetLengthDLL(Node* &head)
{
    int len = 0;
    Node*temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void InsertionAtHead(Node* &head,Node* &tail, int data)
{
    // if LL is empty
    if(head == NULL)
    {
        Node*newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    // if LL is not empty
    // step 1
    Node *newnode = new Node(data);
    //step 2
    newnode-> next = head;
    //step 3
    head->prev = newnode;
    //step 4
    head = newnode;

}

void InsertAtTail(Node* &head,Node* &tail, int data)
{
    // if LL is empty
    if(head == NULL)
    {
        Node*newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    // if LL is not empty
    // step 1
    Node *newnode = new Node(data);
    //step 2
    newnode->prev = tail;
    //step 3
    tail->next = newnode;
    //step 4
    tail = newnode;
}

void InsertAtPosition(Node* &head,Node* &tail, int data,int pos)
{
    // if LL is empty
    if(head == NULL)
    {
        Node*newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

     // if LL is not empty
     // if at first position
    if(pos == 1)
    {
        InsertionAtHead(head,tail,data);
        return;
    }

    // if at last position
    int len = GetLengthDLL(head);
    if(pos > len)
    {
        InsertAtTail(head,tail,data);
        return;
    }

    //step 1
    Node *newnode = new Node(data);
    //step 2
    int i = 1;
    Node *temp = head;                 // temp is the pointer to the previous to position
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    // step 3
    temp->next->prev = newnode;
    //step 4
    newnode->next = temp->next;
    //step 5
    newnode->prev = temp;
    //step 6
    temp->next = newnode;
}

void deleteFromPos(Node* &head, Node* &tail, int position) {
        if(head == NULL) {
                cout << "Linked list is empty";
                return;
        }
        if(head -> next == NULL) {
                //single node
                Node* temp = head;
                head = NULL;
                tail = NULL;
                delete temp;
                return;
        }
        int len = GetLengthDLL(head);
        if(position > len) {
                cout << "please enter a valid position " << endl;
                return;
        }

        if(position == 1) {
                //want to delete the first node
                Node* temp = head;
                head = head ->next;
                head -> prev = NULL;
                temp ->next = NULL;
                delete temp;
                return;
        }
        
        if(position == len) {
                //delete last node
                Node* temp = tail;
                tail = tail -> prev;
                temp ->prev = NULL;
                tail ->next = NULL;
                delete temp;
                return;
        }

        //delete from middle of linked list

        //step1: find left, curr, right
        int i = 1;
        Node* left = head;
        while( i < position - 1) {
                left = left -> next;
                i++;
        }
        Node* curr = left -> next;
        Node* right = curr -> next;

        //step2:
        left -> next = right;
        //step3:
        right -> prev = left;
        //step4:
        curr -> next = NULL;
        curr ->prev = NULL;
        delete curr;


}


int main()
{
    Node*head = new Node(10);
    Node*second = new Node(20);
    Node*third = new Node(30);
    Node*tail = new Node(40);
    head->next = second;
    second->prev = head;
    head->prev = NULL;
    second->next = third;
    third->prev = second;
    third->next = tail;
    tail->prev = third;
    tail->next = NULL;


    // InsertionAtHead(head,tail,0);
    // InsertAtTail(head,tail,50);

    // InsertAtPosition(head,tail,5,2);
    deleteFromPos(head,tail,3);

    PrintDLL(head);
    cout<<endl;
    cout<<GetLengthDLL(head)<<endl;
}