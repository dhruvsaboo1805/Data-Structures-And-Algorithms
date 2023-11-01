#include<bits/stdc++.h>

using namespace std;

void PrintCountRev(int n)
{
    // base condition
    if(n == 0)
    {
        return;
    }

    cout<<n<<endl;
    return PrintCountRev(n-1);
}

void PrintCount(int n)
{
    // base condition
    if(n == 0)
    {
        return;
    }

    PrintCount(n-1);
    cout<<n<<endl;
}

int Factorial(int n)
{
    if(n == 1)
    {
        return 1;

    }
    int ans = n * Factorial(n-1);
    return ans;
}

int Fibonnaci(int n)
{
    if(n == 0)
    {
        return 0;

    }
    if(n == 1)
    {
        return 1;
    }

    int ans = Fibonnaci(n-1) + Fibonnaci(n-2);
    return ans;
}

int PowerOfTwo(int n)
{
    // base condition
    if(n == 0)
    {
        return 1;
    }

     // i case khud karo baki recursion me chod do

    return 2 * PowerOfTwo(n-1);
}

int ClimbStairs(int n)
{
    // base case
    if(n == 0 || n == 1)
    return 1;

    int save = ClimbStairs(n-1) + ClimbStairs(n-2);
    return save;
}


void ElementsOfArray(vector<int> &arr,int n, int i)
{
    // base case
    if(i >= n)
    {
        return;
    }
    ElementsOfArray(arr,n,i + 1);
    cout<<arr[i]<<" ";
}

void MAX(vector<int> &arr,int &n,int i,int &maxi)
{
    // base case
    if(i >= n)
    {
        return ;
    }

    if(arr[i] > maxi)
    maxi = arr[i];

    return MAX(arr,n,i + 1,maxi);
    // cout<<maxi<<" ";
}

void MIN(vector<int> &arr,int &n,int i,int &mini)
{
    // base case
    if(i >= n)
    {
        return ;
    }

    if(arr[i] < mini)
    mini = arr[i];

    return MIN(arr,n,i + 1,mini);
    // cout<<maxi<<" ";
}

/*bool*/int CheckString(string &str, int &i, char &key,vector<int> &arr)
{
    // base case
    if(i >= str.length())
    return -1;

    if(str[i] == key)
    // cout<<"found at "<<i<<endl;
    arr.push_back(i);
    // return i;

    return CheckString(str,++i,key,arr);
}


void PrintDigits(int n)
{
    // base case
    if(n == 0)
    return;


    
    // baaki recursion sambhal lenga
    // int val = n/10;
     PrintDigits(n/10);

    // 1 case chalao
    int rem = n %10;
    cout<<rem<<" ";

}

bool IsSorted(vector<int> &arr, int&i)
{
    // base case
    if(i >= arr.size())
    {
        return true;
    }

    
    // 1 case check karo

    if(arr[i] > arr[i+1])
    return false;

    return IsSorted(arr,++i);

}


int BinarySerachRec(vector<int> &arr,int s,int e,int &key)
{
    // base case
    if(s > e)
    return -1;
    
    int mid = s + (e-s)/2;
    if(arr[mid] == key)
    return mid;
    
    if(arr[mid] > key)
    return BinarySerachRec(arr,s,mid-1,key);

    else
    return BinarySerachRec(arr,mid + 1,e,key);
}


void StringSubSequence(string &str, int n,int i,string output)
{
    // base case
    if(i >= n)
    {
        cout<<output<<endl;
        return;
    }

    // include
    StringSubSequence(str,n,i + 1,output+str[i]);

    //exclude
    StringSubSequence(str,n,i + 1,output);
}

int SolveForCoin(vector<int> &arr,int target)
{
    // base case
    if(target == 0)
    {
        return 0;
    }
    if(target < 0)
    {
        return INT_MAX;
    }

    // 1 case sove karo
    int mini = INT_MAX;
    for(int i = 0; i< arr.size(); i++)
    {
        int ans = SolveForCoin(arr,target - arr[i]);
        if(ans != INT_MAX)
        {
        mini = min(mini,ans + 1);
        }
    }
    return mini;
}

// int SolveForCoin(vector<int> &arr,int target,int &i)    DOUBT!!!!!!!!!!!!??????????
// {
//     // base case
//     if(i == target)
//     {
//         return target;
//     }
//     if(i > target)
//     {
//         return INT_MIN;
//     }

//     // 1 case sove karo
//     int maxi = INT_MIN;
//     for(int j = 0; j< arr.size(); j++)
//     {
//         int val = i + arr[j];
//         int ans = SolveForCoin(arr, target,val);
//         if(ans != INT_MIN)
//         {
//         maxi = max(maxi,ans);
//         }
//     }
//     return maxi;
// }


int CutSegments(int n,int &x,int &y,int &z)
{
    // base case
    if(n == 0)
    return 0;

    if(n < 0)
    return INT_MIN;

    // 1 case solve karo
    int ans1 = CutSegments(n-x,x,y,z) + 1;
    int ans2 = CutSegments(n-y,x,y,z) + 1;
    int ans3 = CutSegments(n-z,x,y,z) + 1;

    int maxi = max(ans1,max(ans2,ans3));

    return maxi;
}

void SolveSum(vector<int> &arr,int i, int sum, int &maxi)
{
    // base case
    if(i >= arr.size())
    {
        maxi = max(sum,maxi);
        return;
    }

    // include
    SolveSum(arr,i + 2,sum  + arr[i],maxi);

    //exclude
    SolveSum(arr, i + 1,sum,maxi);
}


int LastOccurenece(string &str, char key, int i,int &ans)
{
    
    // base case
    if(i >= str.length())
    {
        return ans;
    }

    if(str[i] == key)
    {
        ans = i;
    }

    return LastOccurenece(str,key,i+1,ans);
}


void ReverseStringRec(string &str,int i,int j)
{
    // base acse
    if(i >= j)
    {
        return;
    }

    swap(str[i],str[j]);

    ReverseStringRec(str,i+1,j-1);
}

bool PalindromeCheck(string &str,int i,int j)
{
    // base case
    if(i >= j)
    {
        return true;
    }

    // 1 case solve karna hain
    
    if(str[i] == str[j])
    return true;

    // baaki recursion sambhal lenga
    PalindromeCheck(str,i + 1, j-1);

    return false;

}

void PrintSubarray_ones(vector<int> &arr, int start, int end)
{
    // base case
    if(end == arr.size())
    {
        return;
    }

    // 1case solve karna hain baaki recursion sambhal lenga
    for(int i = start; i<= end; i++)
    {
        cout<<arr[i]<<" "; 
    }
    cout<<endl;

    PrintSubarray_ones(arr,start,end+1);
}

void PrintSubarray(vector<int> &arr)
{
    for(int start = 0; start<arr.size(); start++)
    {
        int end = start;
        PrintSubarray_ones(arr,start,end);
    }
}

int main()
{
    // counting fron n to 1 using recursion



    // int n;
    // cin>>n;
    // // PrintCountRev(n);

    // // cout<<endl;

    // PrintCount(n);
    // cout<<endl;


    // factorial of a number by recursion


    // int n;
    // cin>>n;

    // int save = Factorial(n);

    // cout<<save<<endl;


    // fibbonnaci series using recursion

    // int n;
    // cin>>n;

    // int save = Fibonnaci(n);

    // cout<<save<<endl;


    // power of 2 using iteration and recursion


    // int n;
    // cin>>n;
    // // int ans = 0;

    // // for(int i = 0; i<=n ;i++)
    // // {
    // //     ans = pow(2,i);
    // // }

    // // cout<<ans<<endl;

    // int ans = PowerOfTwo(n);

    // cout<<ans<<endl;

  

   // climb stairs using recursion

//    int n;
//    cout<<"enter the no. of stairs"<<endl;
//    cin>>n;

//    int ans  = ClimbStairs(n);

//    cout<<ans<<endl;


   // traversing all elements of array using recursion

//    vector<int> arr{4,5,6,7,8};

//    int n = arr.size();
//    int i = 0;

//    ElementsOfArray(arr,n,i);
//    cout<<" ";


  // maximum and minimum element using recursion

//   vector<int> arr{23,4,3,6,7};

//   int n = arr.size();

//   int i = 0;
//   int maxi = INT_MIN;
//   int mini = INT_MAX;

//   MAX(arr,n,i,maxi);
//   MIN(arr,n,i,mini);

//   cout<<maxi<<" ";
//   cout<<mini<<" ";

// //   cout<<ans<<endl;


//  linear search in strings 

    // string str = "dhruvsaboo000000000";
    // vector<int> arr;
    
    // char key = '0';
    // int i = 0;

    // CheckString(str,i,key,arr);

    // // cout<<ans<<endl;
    // for(auto i : arr)
    // {
    //     cout<<i<<endl;
    // }
    

    // printing the digits of the number using recursion

    // int n;
    // cout<<"the no. whose digits is to calculated is "<<endl;
    // cin>>n;

    // PrintDigits(n);



    // check whether the given array is sorted or not using recursion


    // vector<int> arr{1,2,3,2,4};

    // int i = 0;

    // cout<<IsSorted(arr,i)<<endl;



    // binary search using recursion

    // vector<int> arr{1,2,3,4,5,6,7,8};
    // int key = 0;
    // int s = 0;
    // int e = arr.size() - 1;
    // // int mid = s + (e-s)/2;

    // cout<<BinarySerachRec(arr,s,e,key)<<endl;





    // question of include exclude pattern    ( VERY VERY IMPORTANT !!!!!)

    // string str = "abc";
    // string output = "";

    // int n = str.length();
    // int i = 0;

    // cout<<"the sub sequence of entered string is"<<endl;
    // StringSubSequence(str,n,i,output);

    // for(auto i: output)
    // {
    //     cout<<i<<endl;
    // }


     
     // COIN EXCHANGE PROBLEM MOST IMPORTANT PROBLEM

    //  vector<int> arr{1,2};
    //  int target = 3;
    // //  int i = 0;

    //  int ans = SolveForCoin(arr,target);

    //  cout<<"Answer is "<<ans<<endl;


 // cut into segments same pattern like coin exchange problem

//  int n = 7;
//  int x = 5;
//  int y = 2;
//  int z = 2;


 
//  int ans = CutSegments(n,x,y,z);
//  if(ans < 0)
//  ans = 0;

//  cout<<"answer is "<<ans<<endl;



// max sum of non adjacent elements (INCLUSION AND EXCLUSION PROBLEM)

// vector<int> arr{2,1,4,9,10};
// int i = 0;
// int sum = 0;
// int maxi = INT_MIN;

// SolveSum(arr,i,sum,maxi);

// cout<<maxi<<endl;



// last occurenece of char in string using recursion

// string str = "abcdbbbbbaaaaabbbbcsbb";
// char key = 'b';
// int i = 0;
// int ans=  0;

// int index = LastOccurenece(str,key,i,ans);

// cout<<index<<endl;



// reverse the string using recursion

// string str = "dhruvq";
// int i = 0;
// int j = str.length() - 1;

// ReverseStringRec(str,i,j);

// cout<<str<<endl;



// palindrome check using recursion

// string str = "raceca";
// int i = 0;
// int j = str.length() - 1;

// bool s = PalindromeCheck(str,i,j);

// cout<<s<<" ";



//  print all the subarrays of the given array using recursion


vector<int> arr{1,2,3,4,5};
PrintSubarray(arr);
   
    return 0;
}