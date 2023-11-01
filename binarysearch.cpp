#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;


int BinarySerach(int arr[] , int target,int start,int end)
{
    // start = 0;
    // end = arr.size() - 1;
    int mid = start + (end - start)/2;

    while(start <= end)
    {
        if(arr[mid] == target)
        {
            return mid;
        }

        else if(target > arr[mid])
        {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int FirstOccurannce(vector<int> arr,int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int save = -1;

    while(s<=e)
    {
        if(arr[mid] == target)
        {
            save = mid;
            e = mid - 1;
        }
        else if(arr[mid]> target)
        {
            e = mid-1;
        }
        else{
            s= mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return save;
}

int LastOccurannce(vector<int> arr,int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int save = -1;

    while(s<=e)
    {
        if(arr[mid] == target)
        {
            save = mid;
            s = mid + 1;
        }
        else if(arr[mid]> target)
        {
            e = mid-1;
        }
        else{
            s= mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return save;
}


int PeakIndex(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s<e)
    {
        if(arr[mid]<arr[mid + 1])
        {
            s = mid + 1;
        }

    else{
         e = mid;
        }
        mid = s + (e-s)/2;

    }
    return e;

    
}

int PivotIndex(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        if(arr[mid]>arr[mid + 1])
        {
            return mid;
        }
        else if(arr[mid - 1]> arr[mid])
        {
            return mid-1;
        }
        else if(arr[s]>arr[mid])
        {
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return s;
}


int Sqrt(long long int target)
{
    int start = 0;
    int end = target;
    long long int mid = start + (end - start)/2;
    long long int ans = -1;

    while(start <= end)
    {
        if(mid * mid <= target)
        {
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}


bool BinarySerach2D(int arr[][3],int target,int rows,int col)
{
    
    int s = 0;
    int e = rows*col - 1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        int rowindex = mid/col;
        int colindex = mid%col;
        int element = arr[rowindex][colindex];

        if(element == target)
        {
            return true;
        }
        else if(element > target)
        {
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return false;

}

int BS(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s <= e)
    {
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid - 1] == target)
        {
            return mid - 1;
        }
        else if(arr[mid + 1] == target)
        {
            return mid + 1;
        }

        else if(arr[mid]>target)
        {
            e = mid -2;
        }
        else{
            s = mid + 2;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}


long long int Divide(long long int divident,long long int divisor)
{
    long long int s = 0;
    long long int e = abs(divident);
    long long int mid = s + (e-s)/2;
    long long int save = 0;

    while(s<=e)
    {
        if(abs(mid * divisor) == abs(divident))
        {
            save = mid;
            break;
            // return save;
        }
        else if(abs(mid * divisor) < abs(divident))
        {
            save = mid;
            s = mid + 1;
        }
        else
        {
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    if((divident > 0 && divisor > 0) || (divident < 0 && divisor < 0))
    {

    return save;
    }
    else
    {
    return -save;

    }
    
}

int OddOccuringlement(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s<= e)
    {
        if(s == e)
        {
            return s;
        }
        else if(mid % 2 == 0)
        {
            if(arr[mid] == arr[mid + 1])
            {
                s = mid + 2;
            }
            else{
                e = mid;
            }
        }
        else{
            if(arr[mid] == arr[mid - 1])
            {
                s = mid + 1;
            }
            else{
                e = mid -1;
            }
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

    int ExponentialSearch(int arr[] , int n , int x)
    {
        if(arr[0] == x)
        {
            return 0;
        }
        int i = 1;

        while( i < n && arr[i] <= x)
        {
            i = i * 2;    // multiply by 2
        }

        cout << i/2 <<endl;
        cout << min(i , n-1) <<endl;
        return BinarySerach(arr , x , i/2 , min(i , n-1));
        

    }
int main()
{
    // vector<int> arr{1,3,5,7,9,11,13,15};
    // int target = 1;

    // int ans = BinarySerach(arr,target);

    // cout<<"Binary search done "<<ans<<endl;



    // binary search by using STL


//   if(binary_search(arr.begin(),arr.end(),90))
//   {
//     cout<<"found"<<endl;
//   }
//   else{
//     cout<<"not found"<<endl;
//   }

// vector<int> arr{5,7,7,8,8,10};
// int target = 8;

// int Finalans = FirstOccurannce(arr,target);
// cout<<"Final ans is"<<" "<<Finalans<<endl;

// int Finalans2 = LastOccurannce(arr,target);

// cout<<"final ans 2 is"<<" "<<Finalans2<<endl;

// int totalocc = Finalans2 - Finalans + 1;

// cout<<totalocc<<" "<<endl;





// peak element in the mountain array



// vector<int> arr{1,3,7,9,10,6,2};

// int ans = PeakIndex(arr);

// cout<<"peak index of the elemnt is "<<" "<<ans<<endl;


// pivot element in the array


// vector<int> arr{3,4,5,6,7,8,10,11,1,2};

// int ans = PivotIndex(arr);
// cout<<"pivot index of the array is "<<" "<<ans<<endl;




// search in rotated sorted array



// vector<int> arr{4,5,6,7,0,1,2};
// int target = 0;
// int Pivot = PivotIndex(arr);


// if(target >= arr[0] && target <= arr[Pivot])
// {
//     cout<<"ans is"<<endl;
//     cout<<BinarySerach(arr,target,0,Pivot)<<endl;
// }
// if(Pivot<arr.size() && target >= arr[Pivot + 1] && target <= arr[arr.size()-1])
// {
//     cout<<"ans is the"<<endl;
//     cout<<BinarySerach(arr,target,Pivot + 1,arr.size()-1)<<endl;
// }




// finding square root using binary serach 



// long long int target = 105;

// long long int result = Sqrt(target);

// cout<<"the integer part of given target "<<target<<" "<<"is"<<" "<<result<<endl;

// int precision;
// cout<<"till how much deimal places you want the ans"<<endl;
// cin>>precision;

// double step = 0.1;
// double Finalans = result;

// for(int i = 0; i<precision; i++)
// {
//     for( double j = Finalans; j*j <= target; j = j +  step)
//     {
//         Finalans = j;
//     }
//     step = step / 10;
// }

// cout<<"finally the total ans is"<<" "<<Finalans<<endl;



// binary search in 2 D array



// int arr[5][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
// int target = 7;
// int rows = 5;
// int col = 3;

// if(BinarySerach2D(arr,target,rows,col))
// {
//     cout<<"element found"<<endl;
// }
// else
// {
//     cout<<"element not found"<<endl;
// }




// binary search in nearly sorted array


// vector<int> arr{10,3,40,20,50,80,70};
// int target = 20;

// int ans  = BS(arr,target);

// cout<<ans<<endl;




// divide two number using binary search




// long long int divident = 19;
// long long int divisor = 3;

// // cout<<Divide(divident,divisor)<<endl;

// int precision;
// cout<<"till how much deimal places you want the ans"<<endl;
// cin>>precision;

// double step = 0.1;
// double Finalans = Divide(divident,divisor);

// for(int i = 0; i<precision; i++)
// {
//     for( double j = Finalans; j*divisor <= divident; j = j +  step)
//     {
//         Finalans = j;
//     }
//     step = step / 10;
// }

// cout<<"finally the total ans is"<<" "<<Finalans<<endl;




// find the odd occuring element in an array (INDEX BASED PROBLEM BINARY SEARCH)


// vector<int> arr{1,1,2,2,3,3,600,600,3,3,4};

// int ans = OddOccuringlement(arr);

// cout<<"the final ans is "<<ans<<endl;

// EXPONENTIAL BIUNARY SEARCH AND UNBOUDED ARRAY SEARCHING

    int arr[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27};
    int n = sizeof(arr) / sizeof(int);
    int x = 11;

    cout << ExponentialSearch(arr , n , x) <<endl;



   return 0;
}




                                              // EKO SPOJ QUESTION


// #include <iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// bool isPossibleSolution(vector<long long int> trees , long long int m , long long int mid)
// {
//   long long int woodCollected = 0;

//   for(long long int i = 0; i < trees.size(); i++)
//   {
//     if(trees[i] > mid)
//     woodCollected += trees[i] - mid;
//   }

//   if(woodCollected >= m)
//   return true;
//   else
//   return false;

// }
// long long int MinWoodRequired(vector<long long int> trees , long long n , long long int m)
// {
//   long long int start = 0;
//   long long int end = *max_element(trees.begin() , trees.end());
//   long long int mid = start + (end - start)/2;
//   long long int ans = -1;

//   while(start <= end)
//   {
//     if(isPossibleSolution(trees , m , mid))
//     {
//       ans = mid;
//       start = mid + 1;
//     }
//     else
//     {
//       end = mid - 1;
//     }
//     mid = start + (end - start)/2;
//   } 
//   return ans;
// }
// int main() {
  
//   long long int n,m;
//   cin >> n >> m;

//   vector<long long int> trees;

//   while(n--)
//   {
//     long long int height;
//     cin >> height;
//     trees.push_back(height);
//   }

//   cout << MinWoodRequired(trees , n , m) << endl;
//   return 0;
// }



                                   // PRATA - SPOJ
                                   
// #include <iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;


// bool isPossibleSol(vector<int> Ranks , int nP , int mid)
// {
//   int currParataCount = 0;
//   for(int i = 0; i < Ranks.size(); i++)
//   {
//     int j = 1;
//     int Timetaken = 0;
//     int R = Ranks[i];

//     while(true)
//     {
//       if(Timetaken + R * j <= mid)
//       {
//         currParataCount++;
//         Timetaken += R*j;
//         j++;
//       }
//       else{
//         break;
//       }
//     }
//     if(currParataCount >= nP)
//     return true;
//   }
//   return false;
// }
// int minTimeToMakeOrder(vector<int> Ranks , int nP)
// {
//   int start = 0;
//   // for end the maximum rank of the cook 
//   int MaxRank = *max_element(Ranks.begin() , Ranks.end());
//   int end = MaxRank * (nP * (nP + 1) / 2);

//   int mid = start + (end - start) / 2;
//   int ans = -1;

//   while(start <= end)
//   {
//     if(isPossibleSol(Ranks , nP , mid))
//     {
//       ans = mid;
//       end = mid - 1;
//     }
//     else
//     {
//       start = mid  + 1;
//     }
//     mid = start + (end - start) / 2;
//   }
//   return ans;
// }
// int main() {
//   int t;
//   cin>>t;

//   while(t--)
//   {
//     int nP , nC;
//     cin >> nP >> nC;

//     vector<int> Ranks;
//     while(nC--)
//     {
//       int ranks;
//       cin >> ranks;
//       Ranks.push_back(ranks);
//     } 

//     cout << minTimeToMakeOrder(Ranks , nP) << endl;
//   }
//   return 0;
// }