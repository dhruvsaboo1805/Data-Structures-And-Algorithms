#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// class stack{
//     public:
//      int* arr;
//      int top;
//      int size;

//      stack(int size)
//      {
//          arr = new int[size];
//          this->size = size;
//          top = -1;

//      }

//      void push(int data)
//      {
//           if((size-top) > 1)
//           {
//              top++;
//              arr[top] = data;
//           }
//           else
//           {
//             cout<<"stack overflow"<<endl;
//           }
//      }

//      void pop()
//      {
//          if(top == -1)
//          {
//             cout<<"stack is empty their is no need to delete"<<endl;
//          }
//          else
//          {
//             top--;
//          }
//      }
     
//      int GetTop()
//      {
//          if(top == -1)
//          {
//              cout<<"their is no element present"<<endl;
//          }
//          else
//          {
//              return arr[top];
//          }
//      }

//      int Size()
//      {
//          return top+1;
//      }

//      bool isEmpty()
//      {
//         if(top == -1)
//         return true;
//         else
//         return false;
//      }

// };

// // IMPLEMENTING MULTIPLE STACK THAT IS 2 SATCK IN ONE ARRAY

// class Stack{
//         public:
//         int *arr;
//         int size;
//         int top1;
//         int top2;

//         Stack(int size) {
//                 arr = new int[size];
//                 this->size = size;
//                 top1 = -1;
//                 top2 = size;
//         }

//         //functions
//         void push1(int data) {
//                 if(top2 - top1 == 1) {
//                         //space not available
//                         cout << "OVERFLOW int stack 1" << endl;
//                 }
//                 else {
//                         //space available
//                         top1++;
//                         arr[top1] = data;
//                 }
//         }

//         void pop1() {
//                 if(top1 == -1) {
//                         //stack empty
//                         cout << "UNDERFLOW in stack 1" << endl;
//                 }
//                 else {
//                         //stack not empty
//                         arr[top1] = 0;
//                         top1--;
//                 }

//         }

//         void push2(int data) {
//                 if(top2 - top1 == 1) {
//                         //space not available
//                         cout << "OVERFLOW in stack 2" << endl;
//                 }
//                 else {
//                         top2--;
//                         arr[top2] = data;
//                 }
//         }

//         void pop2() {
//                 if(top2 == size) {
//                         //stack 2 is empty
//                         cout << "UNDERFLOW in stack 2" << endl;
//                 }
//                 else {
//                         //stack 2 is not empty
//                         arr[top2] = 0;
//                         top2++;
//                 }      
//         }

//         void print() {
//                 cout << endl;
//                 cout << "top1: " << top1 << endl;
//                 cout << "top2: "<< top2 << endl;
//                 for(int i=0; i<size; i++) {
//                         cout << arr[i] << " ";
//                 }cout << endl;
//         }
// };

void FindMiddle(stack<int> &s, int &totalsize)
{
    // base case
    if((totalsize/2)+1 == s.size())
    {
        cout<<"the middle element is "<<s.top()<<endl;
        return;
    }

    int temp = s.top();
    s.pop();

    FindMiddle(s,totalsize);
    //backtrack
    s.push(temp);
}

void InsertAtBottom(stack<int> &s,int target)
{
   
    // baae case
    if(s.empty())
    {
        s.push(target);
        return;
    }

    // 1case solve karna hain
    int temp = s.top();
    s.pop();
    InsertAtBottom(s,target);
    // backtrack
    s.push(temp);
}

void ReverseStack(stack<int> &s)
{
    // base case()
    if(s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    ReverseStack(s);

    InsertAtBottom(s,target);
    

}

void InsertSorted(stack<int> &s,int target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }
    // base case
    if(s.top() <= target)
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();
    InsertSorted(s,target);
    // backtrack
    s.push(temp);
}

void SortStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    SortStack(s);

    InsertSorted(s,target);
}

vector<int> NextSmallElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    for(int i = input.size()-1; i>= 0; i--)
    {
        int curr = input[i];

        while(s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> PreviousSmallElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    for(int i = 0; i<input.size(); i++)
    {
        int curr = input[i];

        while(s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main()
{

    // WITH USING THE STACK LIBRARY DIRECTLY
//     stack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);

//    cout<<s.top()<<endl;
//    s.pop();
//    cout<<s.top()<<endl;
//    cout<<s.size()<<endl;

//    while(!s.empty())
//    {
//        cout<<s.top()<<" ";
//        s.pop();
//    }



//   CREATED A OWN STACK WITHOUT THE LIBRARY
//    stack s(4);
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    s.push(40);

// //    while(!s.isEmpty())
// //    {
// //        cout<<s.GetTop()<<" ";
// //        s.pop();
// //    }
//    cout<<endl;
//    cout<<s.Size()<<endl;


//  IMPORTANT QUESTION AND PATTERN OF FINDING THE MIDDLE ELEMNT IN STACK
    // stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);
    // s.push(70);

    // int size = s.size();
    // FindMiddle(s,size);




    // INSERT AT BOTTOM OF THE STACK

    // stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // // s.push(50);

    // int target = s.top();   
    //  when we are taking top element their should be the garanty that stack is not empty
    // s.pop();
    
    // InsertAtBottom(s,target);

    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }cout<<endl;



    // REVERSE THE STACK
    
    // stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);

    

    // ReverseStack(s);


    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }cout<<endl;




    // SORT THE STACK


    // stack<int> s;
    // s.push(9);
    // s.push(11);
    // s.push(5);
    // s.push(45);
    // s.push(1);

    // SortStack(s);

    //  while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }cout<<endl;

   

   // find the largest area of histogram leetcode

    // stack<int> s;
    // s.push(2);
    // s.push(1);
    // s.push(4);
    // s.push(3);
    // s.push(1);
    vector<int> input{2,1,4,3};

    vector<int> ans1 = NextSmallElement(input);
    for(int i = 0; i< ans1.size(); i++)
    {
        cout<<ans1[i]<<" ";
    }

    cout<<endl;
    cout<<endl;

    vector<int> ans2 = PreviousSmallElement(input);
    for(int i = 0; i< ans2.size(); i++)
    {
        cout<<ans2[i]<<" ";
    }

   




    return 0;
}