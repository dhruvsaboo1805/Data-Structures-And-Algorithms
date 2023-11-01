/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// #include <iostream>
// #include<limits.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    
    // int min = INT_MAX;
    
    // int arr[6] = {1 ,3 ,5 ,7,9,11};
    // int i = 0;
    // int j = 5;
    
    
    
    // // for(int i = 0; i<5; i++)
    // // {
    // //     // if(arr[i]<min)
    // //     // {
    // //     //     min = arr[i];
    // //     // }
        
    // // }
    // while(i<=j)
    // {
    //     if(i == j)
    //     {
            
    //     cout<<arr[i]<<endl;
    //     }
    //     else
    //     {
    //     cout<<arr[i]<<endl;
    //     cout<<arr[j]<<endl;
    //     }
    //     i++;
    //     j--;
    // }
    
    // cout<<min<<endl;
    int n;
    cout<<"the size of the array is"<<endl;
    cin>>n;
    
    int arr[n];
    int i = 0;
    int j = n-1;
    
    cout<<"enter the array elements"<<endl;
    
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    while(i<=j)
    {
        // int temp = arr[i];
        // arr[i] = arr[j];
        // arr[j] = temp;
        // swap(arr[i],arr[j]);
        // arr[i] = arr[i] ^ arr[j];
        // arr[j] = arr[i] ^ arr[j];
        // arr[i] = arr[i] ^ arr[j];
        
        i++;
        j--;
    }
    
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
