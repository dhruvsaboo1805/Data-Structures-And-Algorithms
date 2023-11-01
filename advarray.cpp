#include <iostream>
#include <vector>
#include <limits.h>
#include<algorithm>

using namespace std;

// find an unique element in an array

// int findunique(vector<int>arr)
// {
//     int ans = 0;
//     for(int i = 0; i<arr.size(); i++)
//     {
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }

int main()
{
  // unique element in an array

  // int n;
  // cin>>n;

  // vector<int>arr(n);

  // for(int i = 0; i<arr.size(); i++)
  // {
  //     cin>>arr[i];
  // }

  // int Uniqueelement = findunique(arr);

  // cout<<"unique element in an array is "<<Uniqueelement<<endl;

  // for each loop ka kamal

  // int n;
  // cin>>n;
  // vector<int> arr(n);

  // for(auto val: arr)
  // {
  //     cin>>arr[val];
  // }

  // union of two arrays

  // int arr[4] = {10,20,30,40};
  // int brr[3] = {50,60,70};
  // vector<int> crr;

  // for(int i = 0; i<4; i++)
  // {
  //     crr.push_back(arr[i]);
  // }

  // for(int j = 0; j<3; j++)
  // {
  //     crr.push_back(brr[j]);
  // }

  // // print the array

  // for(int i = 0; i<crr.size(); i++)
  // {
  //     cout<<crr[i]<<" "<<endl;
  // }

  // intersection of two arrays

  // vector<int> arr{1,2,3,4,5};
  // vector<int> brr{1,7,5,9};

  // vector<int> ans;

  // for(int i= 0; i<arr.size(); i++)
  // {
  //     int element  = arr[i];
  //     for(int j = 0; j<brr.size(); j++)
  //     {
  //         if(element == brr[j])
  //         {
  //               brr[j] = INT_MIN;
  //               ans.push_back(element);
  //         }
  //     }
  // }
  // for(int i = 0; i<ans.size(); i++)
  // {
  //     cout<<ans[i]<<" ";
  // }

  // duplicates removal in union of two arrays question  (DOUBT)

    // vector<int> arr{1,3,5,7,9};
    // vector<int> brr{1,2,4,6,9};

    // vector<int>ans;

    // for(int i = 0; i<arr.size(); i++)
    // {
    //     ans.push_back(arr[i]);
    // }

    // for(int j = 0; j<ans.size(); j++)
    // {
    //     int element = ans[j];
    //     for(int k = 0; k<brr.size(); k++)
    //     {
    //         if(element != brr[k])
    //         {
    //           ans.push_back(brr[k]);
    //         }

    //     }
    // }

    // for(int i = 0; i<ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

  // pair sum

  // vector<int> arr{1,2,3,4,5,6};
  // int sum = 9;

  // // vector<int>ans;

  // for(int i = 0; i<arr.size(); i++)
  // {
  //     int element = arr[i];

  //     for(int j = i+1; j<arr.size(); j++)
  //     {
  //         if(element + arr[j] == sum)
  //         {
  //             // ans.push_back(element);
  //             // ans.push_back(arr[j]);
  //             cout<<"pair found "<<element<<" "<<arr[j]<<endl;
  //         }
  //     }
  // }

  // for(int i = 0; i<ans.size(); i++)
  // {
  //   cout<<ans[i]<<" ";
  // }

  // triplet sum

  //   vector<int> arr{2,1,6,5,3,8};
  //   int sum = 9;

  //  for(int i = 0; i<arr.size(); i++)
  //   {
  //       int element = arr[i];
  //       // cout<<" i = "<<" "<<"element = "<<" "<<endl;

  //       for(int j = i+1; j<arr.size(); j++)
  //       {
  //         int element2 = arr[j];
  //       //  cout<<" j = "<<" "<<"element2 = " <<" "<<endl;

  //         for(int k = j+1; k<arr.size(); k++)
  //         {

  //           if(element + element2 + arr[k] == sum)
  //           {
  //             cout<<"pair found "<<element<<" "<<element2<<" "<<arr[k]<<endl;
  //           }
  //         }
  //       }
  //   }

  // sort 0's and 1's without using any ssorting technique
  // 2 pointer approach

  //  vector<int> arr{0,0,1,0,1,1,0,1,0};
  //  int start = 0;
  //  int end = arr.size() - 1;
  //  int i = 0;

  //  while(i<=end)
  //  {
  //   if(arr[i] == 0)
  //   {
  //     swap(arr[i], arr[start]);
  //     start++;
  //     i++;
  //   }
  //   else{
  //     swap(arr[i],arr[end]);
  //     end--;

  //   }
  //  }

  //  for(int i = 0; i<arr.size(); i++)
  //  {
  //   cout<<arr[i]<<" ";
  //  }

  // left rotate an element in an array

  //  int n;
  //  cout<<"enter the size of the array : "<<endl;

  //  cin>>n;
  //   vector<int> arr(n);

  //  for(int i = 0; i<arr.size(); i++)
  //  {
  //   cin>>arr[i];
  //  }
  //   int save = arr[0];

  //   for(int i = 0; i<arr.size(); i++)
  //   {
  //     arr[i] = arr[i+1];
  //   }

  //   arr[arr.size() - 1] = save;

  //   for(int i = 0; i<arr.size(); i++)
  //   {
  //     cout<<arr[i]<<" ";
  //   }

  // sort 0's , 1's and 2's without using any sorting

  // vector<int> arr{0,0,2,1,2,1,2,1,0,0,1,2};
  // int start = 0;
  // int end = arr.size() - 1;
  // int i = 0;

  // while (i <= end)
  // {
  //   if (arr[i] == 0)
  //   {
  //     swap(arr[i], arr[start]);
  //     start++;
  //     i++;
  //   }

  //   else if (arr[i] == 1)
  //   {
  //     i++;
  //   }

  //   else
  //   {
  //     swap(arr[i], arr[end]);
  //     end--;
  //   }
  // }

  // for (int i = 0; i < arr.size(); i++)
  // {
  //   cout << arr[i] << " ";
  // }

  // move all negetive numbers to left side and all positive numbers to right side

  // int n;
  // cout << "the size of the array is : " << endl;

  // cin >> n;

  // vector<int> arr(n);

  // for (int i = 0; i < arr.size(); i++)
  // {
  //   cin >> arr[i];
  // }

  // int start = 0;
  // int end = arr.size() - 1;

  // int i = 0;

  // while(i<=end)
  // {
  //   if(arr[i]< 0)
  //   {
  //     swap(arr[i], arr[start]);
  //     start++;
  //     i++;
  //   }

  //   else{
  //     swap(arr[i], arr[end]);
  //     end--;
  //   }
  // }

  // for(int i = 0; i<arr.size(); i++)
  // {
  //   cout<<arr[i]<<" ";
  // }


// find a duplicate element in array




// vector<int> arr{1,2,3,4,6,1,7,8};

// int ans = 0;

// for(int i = 0; i<arr.size(); i++)
// {
//   int element = arr[i];
//   for(int j = i+1;j < arr.size(); j++)
//   {
//     if((element ^ arr[j]) == 0)
//     {
//       ans = arr[j];
//     }
//   }
// }
// cout<<ans<<endl;




  vector<int> arr{1,3,5,3,4};
  sort(arr.begin() , arr.end());
  int i = 0;

 for(int i = 0; i < arr.size(); i++)
 {
   if(arr[i] != i+1)
    cout << i+1 <<endl;
 }
  return 0;
}