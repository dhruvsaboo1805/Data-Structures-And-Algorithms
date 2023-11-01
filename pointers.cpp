#include<bits/stdc++.h>

using namespace std;


// void solve(int arr[]) {
//         cout <<"Size inside solve function " << sizeof(arr) << endl;
//         cout <<"arr: " << arr << endl;
//         cout << "&arr: " << & arr << endl;

//         arr[0] = 50;
// }

// void update(int *p) {
//         cout << "Address stored inside p is: " << p << endl;
//         cout << "Address of p  is:" << &p << endl;
//         *p = *p + 10;
// }

void solve(int** ptr) {
        //ptr = ptr + 1;

        //*ptr = *ptr + 1;

        **ptr = **ptr + 1;
}



int main()
{
    // int a = 5;
    // int b = 5;
    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<&b<<endl;

    // int a = 5;
    // // pointer

    // int *ptr = &a;

    // // exvess the value ptr is pointing too

   
    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<ptr<<endl;
    // cout<<&ptr<<endl;
    // cout<<*ptr<<endl;

    // int a = 10;
    // int *p = &a;
    // int *q = p;

    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<&p<<endl;
    // cout<<q<<endl;
    // cout<<*q<<endl;
    // cout<<&q<<endl;
    // cout<<a + 10<<endl;
    // cout<<(*p) * 2<<endl;
    // cout<<q +2 <<endl;

   // integer array and pointer

//    int arr[5] = {1,2,3,4,5};
   
//    cout<<arr[1]<<endl;
//    cout<<arr<<endl;
//    cout<<&arr<<endl;
//    cout<<&arr[0]<<endl;
//    cout<<*arr<<endl;
//    cout<<*(arr) + 2<<endl;
//    cout<<*(arr + 1)<<endl;
//    cout<<*(1 + arr)<<endl;

      
    //   int arr[5] = {10,20,30,40,50};

    //   int *p = arr;
    //   int *q =  arr + 1;

    //   cout<<arr[1]<<endl;
    //   cout<<arr<<endl;
    //   cout<<&arr<<endl;
    //   cout<<&arr[0]<<endl;
    //   cout<<*arr<<endl;
    //   cout<<*(arr) + 2<<endl;
    //   cout<<*(arr + 1)<<endl;
    //   cout<<*(1 + arr)<<endl;
    //   cout<<endl<<endl<<endl;

    //   cout<<p<<endl;
    //   cout<<&p<<endl;
    //   cout<<*p<<endl;
    //   cout<<p + 1<<endl;
    //   cout<<p + 6<<endl;
    //   cout<<*p + 6<<endl;
    //   cout<<*(p + 3)<<endl;

    //   p = p + 1;
    //   cout<<p<<endl;
    //   cout<<q<<endl;


    // character array as pointers

    
    //   char arr[10] = {'d','h','r','u','v'};

    //   char *p = arr;
    //   char *q =  arr + 1;

    //   cout<<arr[1]<<endl;
    //   cout<<arr<<endl;  // whole string gets in output
    //   cout<<&arr<<endl;
    //   cout<<&arr[0]<<endl;  /// 
    //   cout<<*arr<<endl;
    //   cout<<*(arr) + 2<<endl;
    //   cout<<*(arr + 1)<<endl;
    //   cout<<*(1 + arr)<<endl;
    //   cout<<endl<<endl<<endl;

    //   cout<<p<<endl;
    //   cout<<&p<<endl;
    //   cout<<*p<<endl;
    //   cout<<p + 1<<endl;  // it will leave out 0th character and print rest of the string
    //   cout<<p + 6<<endl;
    //   cout<<*p + 6<<endl;
    //   cout<<*(p + 3)<<endl;

    //   p = p + 1;
    //   cout<<p<<endl;
    //   cout<<q<<endl;


    // pointers with functions

//     int arr[10] = {1,2,3,4};
//     // cout << "Size inside main function. " << sizeof(arr) << endl;

//     // solve(arr);
//         cout << arr << endl;
//         cout << &arr << endl;

//         //printing array inside main
//         for(int i=0; i<10; i++) {
//                 cout << arr[i] << " ";
//         }cout << endl;
//         cout << endl << endl << "Now calling solve function" << endl;

//         solve(arr);

//         cout << "Wapas main function me aagye h " << endl;

//         for(int i=0; i<10; i++) {
//                 cout << arr[i] << " ";
//         }cout << endl;

//         int a = 5;
//         cout << "Address of a is: " << &a << endl;
//         int* ptr = &a;
//         cout << "address stored in ptr is: " << ptr << endl;
//         cout << "Address of ptr is: " << &ptr << endl;
//         update(ptr);
//         cout<<"value of a is: " << a << endl;





     // double pointers 

//      int a = 9;
//      int *p = &a;
//      int **q = &p;

// //      cout<<a<<endl;
// //      cout<<&a<<endl;
// //      cout<<p<<endl;
// //      cout<<&p<<endl;
// //      cout<<*p<<endl;
// //      cout<<q<<endl;
// //      cout<<&q<<endl;
// //      cout<<*q<<endl;
// //      cout<<*p + 1<<endl;
// //      cout<<**q + 0<<endl;
//    solve(q);
//    cout<<a<<endl;



// reference variable



        int a = 5;
        //creating a reference variable
        int& b = a;

        cout << a << endl;
        cout << b << endl;

        a++;
        cout << a << endl;

        cout << b << endl;

        b++;
        cout << a << endl;
        cout << b << endl;

    
  

      
      



   

    
    return 0;
}