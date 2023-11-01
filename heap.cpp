#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Heap{
    public:
       int* arr = new int[50];
       int size;

    Heap()
    {
        size = 0;
    }

    void Insert(int value)
    {
        // uss index per value dalo
        size = size + 1;
        int index = size;
        arr[index] = value;

        // check if the currnode is greater then parent node
        while(index > 1)   // since 1 is the parent node dont check to 0
        {
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex])
            {
                swap(arr[index] , arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }

    }

    void Delete()
    {
        // repacing first element with last element
        arr[1] = arr[size];
        size--;
        int index = 1;
        int largest = index;
        // check for to create heap correctly
        while(index < size)
        {
            int left = 2*index;
            int right = 2*index+1;

            if(left < size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if(right < size && arr[largest] < arr[right])
            {
                largest = right;
            }

            if(largest == index)
            {
                return;
            }
            else
            {
                swap(arr[largest],arr[index]);
                index = largest;
            }
            
        }
    }
};

class Node
{
    public:
    int data;
    int row;
    int col;

    Node(int val, int r,int c)
    {
        data = val;
        row = r;
        col = c;
    }

};



void heapify(int arr[],int n,int i)
{
    int index = i;
    int left = 2*index;
    int right = 2*index+1;
    int largest = index;

    if(left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(index != largest)
    {
        swap(arr[largest], arr[index]);
        index = largest;
        heapify(arr,n,index);
    }

}

void BuildHeap(int arr[],int n)
{
    for(int i = n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }
}

void HeapSort(int arr[], int n)
{
    int index = n;

    while(n != 0)
    {
        swap(arr[index],arr[1]);
        index--;
        n--;

        heapify(arr,n,1);
    }
}

class compare{
    public:
        bool operator()(Node* a, Node*b)
         {
             return a->data > b->data;    // yha pe doubt ho to priority queue cpp refrence me jaake padh lena
         }
};

vector<int> MergeKSortedArray(int arr[][4],int k, int n)
{
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    // all first value of array into heap
    for(int i = 0; i<k; i++)
    {
        Node* temp= new Node(arr[i][0],i,0);
        minHeap.push(temp);
    }

    // minheap khaaali hone tak saare element ki assi tasi karo

    vector<int> ans;
    while(!minHeap.empty())
    {
       Node* temp = minHeap.top();
       int TopElement = temp->data;
       int TopRow = temp->row;
       int TopCol = temp->col;
       minHeap.pop();

       ans.push_back(TopElement);

       if(TopCol+ 1 < n)
       {
           Node* newNode = new Node(arr[TopRow][TopCol  +1],TopRow,TopCol  +1);
           minHeap.push(newNode);
       }
    }

    return ans;         
}
int main()
{
    //   Heap h;
    //  h.arr[0] = -1;
    //  h.arr[1] = 100;
    //  h.arr[2] = 50;

    //  h.arr[3] = 60;
    //  h.arr[4] = 40;
    //  h.arr[5] = 30;
    //  h.size = 5;

    //  for(int i = 0 ;i<=h.size; i++)
    //  {
    //      cout<<h.arr[i]<<" ";
    //  }

    //  cout<<endl;

    //  h.Delete();
    //  h.Delete();

    //   for(int i = 0 ;i<=h.size; i++)
    //  {
    //      cout<<h.arr[i]<<" ";
    //  }


    // int arr[] = {-1,90,80,10,50,100,110,45,60};
    // int n = 8;

    // BuildHeap(arr,n);

    // for(int i = 0;i <=n ;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    // HeapSort(arr,n);

    // for(int i = 0;i <=n ;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    int arr[][4] = {{1,2,3,4},{9,10,11,12},{5,6,7,8}};
    int k = 3;
    int n = 4;
    vector<int> ans;

    ans = MergeKSortedArray(arr,k,n);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
}