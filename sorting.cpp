#include<bits/stdc++.h>


using namespace std;

int Partition(int arr[], int s, int e)
{
    // step 1 to find the pivot element
    int PivotIndex = s;
    int PivotElement = arr[s];

    // step 2 to find right position of pivot
    int count = 0;
    for(int i = s + 1; i <= e; i++)
    {
        if(arr[i] <= PivotElement)
        count++;
    }
    int RightIndex = s + count;
    swap(arr[PivotIndex],arr[RightIndex]);
    PivotIndex = RightIndex;

    // step 3 sorting left and right side

    int i = s;
    int j = e;

    while(i < PivotIndex && j > PivotIndex)
    {
        while(arr[i] <= PivotElement)
        {
            i++;
        }
        while(arr[j] > PivotElement)
        {
            j--;
        }
    }

    // 2 case left if 
    // if i side have larger element and j side have lower element then pivot
    // if no change

    if(i < PivotIndex && j > PivotIndex)
    {
        swap(arr[i],arr[j]);
    }

    return PivotIndex;
}

void MergeArray(int *arr,int s,int e)
{
    int mid  = s + (e-s)/2;

    int len1 = mid - s + 1;    // length of array 1 to be used for sorting
    int len2 = e - mid;        // length of array 2 to be used for sorting

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k  = 0;                       // 3rd array pointer

    // copy the values from original  array
    k = s;
    for(int i = 0; i< len1; i++)
    {
        arr1[i] = arr[k];
        k++;
    } 

    k = mid + 1;
    for(int i = 0; i<len2; i++)
    {
        arr2[i] = arr[k];
        k++;
    }

    // merging the array by sorting it

    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;

    while(leftIndex < len1 && rightIndex < len2)
    {
        if(arr1[leftIndex] < arr2[rightIndex])
        {
            arr[mainIndex++] = arr1[leftIndex++];
        }
        else{
            arr[mainIndex++] = arr2[rightIndex++];
        }
    }

    // if one array gets empty then

    while(leftIndex < len1)
    {
        arr[mainIndex++] = arr1[leftIndex++];
    }
    while(rightIndex < len2)
    {
        arr[mainIndex++] = arr2[rightIndex++];
    }
}
// void SelectionSort(int arr[])
// {
//     for(int i = 0; i<5 ;i++)
//     {
//         int min = arr[i];
//         for(int j = 0; j<=5; j++)
//         {
//             if(arr[j] < min)
//             {
//                 min = arr[j];
//             }
//         }
//         swap(arr[i],arr[min]);
//     }
// }

void MergeSort(int *arr,int s,int e)
{
    // base case

    if(s >= e)
    {
        return;
    }
    int mid = s + (e-s)/2;

    // sort left side
    MergeSort(arr,s,mid);

    // sort right side
    MergeSort(arr,mid+1,e);

    //merge two sorted arrays
    MergeArray(arr,s,e);
}

void QuickSort(int arr[], int s, int e)
{
    // base case
    if(s >= e)
    {
        return;
    }

    // partition logic

    int p = Partition(arr,s,e);

    // left
    QuickSort(arr,s,p-1);

    //right
    QuickSort(arr,p+1,e);


}
int main()
{

    // selection sort


    // int arr[6] = {5,4,2,1,7,6};

    // for(int i = 0; i<5 ;i++)
    // {
    //     int min = i;
    //     for(int j = i+1; j<=5; j++)
    //     {
    //         if(arr[j] < arr[min])
    //         {
    //             min = j;
    //         }
    //     }
    //     swap(arr[i],arr[min]);
    // }


    // for(int i = 0; i<6; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    



    // bubble sort



    // vector<int> arr{5,4,3,2,1};

    // int n = arr.size();

    // for(int i = 0; i< n-1; i++)
    // {
    //     for(int j=0; j < n- i -1; j++)
    //     {
    //         if(arr[j] > arr[j + 1])
    //         {
    //             swap(arr[j], arr[j+1]);
    //         }
    //     }
    // }

    // for(int i = 0; i< n; i++)
    // {
    //     cout<< arr[i] << " ";    
    // }



    // insertion sort 



//   vector<int> arr{10,1,7,6,14,9};
//   int n = arr.size();

//   //insertion sort
//   for(int round = 1; round < n; round++) {
//       //Step 1 - fetch
//       int val = arr[round];
//       //Step 2: Compare
//       int j=round-1;
//       for(; j>=0; j--) {
//           if(arr[j] > val) {
//               // Step 3: shift
//               arr[j+1] = arr[j];
//           }
//           else {
//               //rukna hai
//               break;
//           }

//       }
//       //step 4: Copy
//       arr[j+1] = val;
//   }

//   //printinhg
//   for(int i=0; i<n; i++) {
//       cout << arr[i] << " ";
//   }
//   cout << endl;



// merge sort 

    
    // int arr[12] = {7,4,8,2,9,8,7,15,13,12,10,1};
    // int s = 0;
    // int e = 11;
    // // int mid = s + (e-s)/2;

    // MergeSort(arr,s,e);

    // for(auto i: arr)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;




   // quick sort

   int arr[] = {6,5,1,5,10,20,50,12};
   int n = 8;
   int s = 0;
   int e = n-1;

   QuickSort(arr,s,e);

   for(auto i: arr)
   {
       cout<<i<<" ";
   }

    return 0;
}