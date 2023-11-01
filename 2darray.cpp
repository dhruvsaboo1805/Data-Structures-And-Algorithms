#include <iostream>
#include <limits.h>

using namespace std;

void InputArray(int arr[][3], int rows, int col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

bool LinearSearch(int arr[][3], int rows, int col, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (key == arr[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

int MaxElement(int arr[][4], int rows, int col)
{
    int max = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int MinElement(int arr[][4], int rows, int col)
{
    int min = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

void Printarray(int arr[][3], int rows, int col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j];
        }
    }
}
int main()
{
    //     int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    //    cout<<"row wise arrangement"<<endl;

    //     for(int i = 0; i<3; i++)
    //     {
    //         for(int j = 0; j<3; j++)
    //         {
    //             cout<<arr[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //    cout<<"column wise arrangement"<<endl;

    //     for(int i = 0; i<3; i++)
    //     {
    //         for(int j = 0; j<3; j++)
    //         {
    //             cout<<arr[j][i]<<" ";
    //         }
    //         cout<<endl;
    //     }

    // column wise sum

    // int arr[3][3];

    // for(int i = 0; i<3; i++)
    // {
    //     for(int j = 0; j<3; j++)
    //     {
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i = 0; i<3; i++)
    // {
    //     int sum = 0;
    //     for(int j = 0; j<3; j++)
    //     {
    //         sum = sum + arr[j][i];
    //     }
    //     cout<<sum<<endl;
    // }
    //

    // row sum

    // int arr[3][3];

    // for(int i = 0; i<3; i++)
    // {
    //     for(int j = 0; j<3; j++)
    //     {
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i = 0; i<3; i++)
    // {
    //     int sum = 0;
    //     for(int j = 0; j<3; j++)
    //     {
    //         sum = sum + arr[i][j];
    //     }
    //     cout<<sum<<endl;
    // }

    // linear search in 2d array

    //   int arr[3][3];

    //   InputArray(arr,3,3);

    //   cout<<LinearSearch(arr,3,3,6)<<endl;




    // max element in 2d array




    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // cout << "max element in the array is " << MaxElement(arr, 3, 4) << endl;
    // cout << "min element in the array is " << MinElement(arr, 3, 4) << endl;

    // PRINTING THE WAVE PRINT OF THE ARRAY

    // LOGIC EVEN COL PE TOP TO DOWN PRINT KARNA HAIN BOTTOM TO TOP PE ODD ME PRINT KARENGA ULTA 

    for(int j = 0; j < 4; j++)
    {
        if((j & 1) == 0)
        {
            for(int i = 0; i < 3; i++)
            {
                cout << arr[i][j] <<" ";
            }
            // cout<<endl;
        }
        else
        {
            for(int i = 2; i >= 0; i--)
            {
                cout << arr[i][j]<< " ";
            }
            // cout<<endl;
        }
    }

    for(int i  =0; i < 3; i++)
    {
        for(int j = 0; j  < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        // cout<<endl;
    }








}