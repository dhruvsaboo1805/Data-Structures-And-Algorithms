#include<iostream>

using namespace std;

int GetIthBit(int n , int i)
{
    int mask = 1 << i;

    if(n & mask == 0)
    return 0;
    else
    return 1;

  
}

int SetIthBit(int n , int i)
{
    int mask = 1 << i;
    int ans = n | mask;
    return ans;
}

int ClearIthBit(int n , int i)
{
    int mask = ~(1 << i);
    int ans = n & mask;
    return ans;
}

// if i == 0 clear bit will not change anything
// if i == 1 clear bit will change 1 to 0 kyunki vha agar binal clear bit ke fas rha tha
int updateIthBit(int &n , int i, int target)
{
    int maskClear = ~(1 << i);
    n = n & maskClear;

    int mask = target << i;
    n = n | mask;
    return n;
}

int ClearLastIBits(int n , int i)
{
    int mask = (-1 << i);
    int ans = n & mask;
    // cout<<"after shifting i bits "<<ans<<endl;
    return ans;
}

void PowerOf2(int n)
{
    if((n & (n-1)) == 0)
    {
        cout<<"yes power of 2"<<endl;
    }
    else
    {
        cout<<" not power of two"<<endl;
    }
}
int main()
{
    // int a = 0;
    // cout<<(~a)<<endl;

    // int n = 50;
    // if(n & 1)
    // {
    //     cout<<"odd"<<endl;
    // }
    // else
    // {
    //     cout<<"even"<<endl;
    // }

    // cout<<GetIthBit(10 , 3)<<endl;
    // cout<<SetIthBit(10 , 3)<<endl;

    // cout<<ClearIthBit(10 , 1)<<endl;
    int n = 2048;
    // cout<< updateIthBit(n , 1 , 0) << endl;
    // cout<< ClearLastIBits(n , 2) <<endl;
    PowerOf2(n);
} 