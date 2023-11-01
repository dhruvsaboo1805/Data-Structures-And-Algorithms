#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node()
    {
        this-> data = 0;
        this -> next = NULL;

    }
    Node(int data)
    {
        this-> data = data;
        this-> next = NULL;
    }
};

void PrintLinkedList(Node *&head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int GetLength(Node *&head)
{
   int len = 0;
   Node*temp = head;
   while(temp != NULL)
   {
       temp = temp->next;
       len++;
   }
   return len;
}

void InsertAtHead(Node*&head,Node *&tail,int data)
{
    // when linkedlist is empty
    if(head == NULL)
    {
        Node*newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // linked list in not empty
    //step 1
    Node *newnode = new Node(data);
    //step 2
    newnode->next = head;
    // step 3
    head = newnode;

}

void InsertAtTail(Node* &head,Node* &tail,int data)
{
    // if linkedlist is empty
    if(head == NULL)
    {
        Node*newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    //if linkedlist is not empty
    // step 1
    Node *newnode = new Node(data);
    //step 2
    tail->next = newnode;
    //step 3
    newnode->next = NULL;
    //step 4
    tail = newnode;

}

void InsertAtPosition(Node* &head,Node* &tail,int data, int position)
{
    //if linked list is empty
    if(head == NULL)
    {
        Node*newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    // if insert at head
    if(position == 1)
    {
        InsertAtHead(head,tail,data);
        return;
    }

    int len = GetLength(head);
    // at last postion
    if(position == len)
    {
        InsertAtTail(head,tail,data);
        return;
    }
    if(position > len)
    {
        cout<<"invalid position"<<endl;
    }

        // step 1
        int i = 1;
        Node *prev = head;
        while(i < position-1)
        {
            prev = prev->next;
            i++;
        }
        Node *curr = prev->next;
        // step 2
        Node *newnode = new Node(data);
        //step 3
        newnode->next = curr;
        //step 4
        prev->next = newnode;
    

}

void deleteNode(int position, Node* &head, Node* &tail) {
        if(head == NULL || position <= 0) {
                cout << "Cannot delete, LL is empty"<<endl;
                return;
        }

        //deleting first node
        if(position == 1) {
                Node* temp = head;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
                return;
        }
        int len  = GetLength(head);


        //deleting last node
        if(position == len) {
                //find prev
                int i = 1;
                Node* prev = head;
                while(i < position - 1) {
                        prev = prev->next;
                        i++;
                }
                //step2:
                prev->next = NULL;
                //step3:
                Node* temp = tail;
                //step4:
                tail = prev;
                //step5:
                delete temp;
                return;
        }

        //deleting middle node

        //step  : find prev and curr
        int i =1;
        Node* prev = head;
        while( i < position-1) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2:
        prev -> next = curr -> next;
        //step3:
        curr -> next = NULL;
        //step4:
        delete curr;

}

Node* ReverseLLRE(Node *& prev, Node*& curr)
{
    // base case
    if(curr == NULL)
    {
        return prev;
    }

    // 1case solve karna hain 
    Node * forward = curr->next;
    curr->next = prev;

    // baaki recursion dekh lenga
    return ReverseLLRE(curr,forward);

}

Node* ReverseLLIT(Node *& prev, Node*& curr)
{
    // Node *forward = curr->next;
    while(curr != NULL)
    {
       Node * forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward;

    }
     return prev;

}

Node * MiddleNode(Node* &head)
{
    // Node* temp = head;
    // int pointer = 1;
    // while(pointer < pos)
    // {
    //     temp = temp->next;
    //     pointer++;
    // }
    // return temp->data;
   
    if(head == NULL)
    {
        cout<<"list is empty"<<endl;
        return head;
    }
    if(head->next == NULL)
    {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
    

}

Node *reverseknodes(Node* &head, int k)
{
    if(head == NULL)
    {
        cout<<"no nodes to be reversed"<<endl;
        return NULL;
    }
    int len = GetLength(head);
    if(k > len)
    {
        return head;
    }
    int count = 0;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    while(count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // step b recursive call
    if(forward != NULL)
    {
        Node* ReverseKNodesKaHead = reverseknodes(forward,k);
        head->next = ReverseKNodesKaHead;
    }

    return prev;
}
int main()
{
// desi tarika of forming a linked list
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third= new Node(30);
    Node *fourth = new Node(40);
    Node *tail = new Node(50);

    head->next = second;
    second-> next = third;
    third-> next = fourth;
    fourth-> next = tail;
    tail->next = NULL;



    // PrintLinkedList(head);
    // int length = GetLength(head);
    // cout<<endl;
    // cout<<length<<endl;


// best way to form the linked list using insertion at head
    // Node *head = NULL;
    // Node *tail = NULL;
    // InsertAtHead(head,tail,50);
    // InsertAtHead(head,tail,40);
    // InsertAtHead(head,tail,30);
    // InsertAtHead(head,tail,20);
    // InsertAtHead(head,tail,10);

    // // InsertAtTail(head,tail,60);
    // // InsertAtTail(head,tail,70);
    // // InsertAtPosition(head,tail,70,8);
    // deleteNode(5,head,tail);
    // cout<<GetLength(head)<<endl;

    // PrintLinkedList(head);
    

    // QUESTION 1 REVERSE THE LINKED LIST USING RECURSION


    // Node *head = NULL;
    // Node *tail = NULL;
    // InsertAtHead(head,tail,50);
    // InsertAtHead(head,tail,40);
    // InsertAtHead(head,tail,30);
    // InsertAtHead(head,tail,20);
    // InsertAtHead(head,tail,10);
    // InsertAtHead(head,tail,5);

    PrintLinkedList(head);
    // Node* prev = NULL;
    // Node*curr = head;

    // // head = ReverseLLRE(prev,curr);
    // // cout<<endl;

    // // cout<<"after reversing the linked list through recursion"<<endl;
    // // PrintLinkedList(head);

    // head = ReverseLLIT(prev,curr);
    // cout<<endl;

    // cout<<"after reversing the linked list through iteration"<<endl;
    // PrintLinkedList(head);



    // FINDING THE MIDDLE NODE OF LL



//    cout<<endl;
//    int n;
//    cout<<"the value of the position is "<<endl;
//    cin>>n;

//    if(n % 2 == 0)
//    {
//        cout<<MiddleNode(head,n/2)<<endl;
//    }
//    else{
//        cout<<MiddleNode(head,n/2+1)<<endl;
//    }

    // cout<<endl;
    // head = MiddleNode(head);
    // cout<<head->data<<endl;



    // REVERSE K NODES VERY VERY IMP QUESTION
    cout<<endl;
    head = reverseknodes(head,3);
    PrintLinkedList(head);



    
    

     


}