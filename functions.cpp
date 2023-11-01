#include<iostream>

using namespace std;

// int getmax(int a, int b,int c)
// {
//     if(a>b && a>c)
//     {
//         // cout<<"a is greater"<<endl;
//         return a;
//     }
//     else if(b>a && b>c)
//     {
//         // cout<<"b is greater"<<endl;
//         return b;
//     }
//     else{
//         // cout<<"c is greater"<<endl;
//         return c;
//     }
//     return -1;
// }
// double getCircleArea(int r)
// {
//     return (3.14*r*r);
// }

bool prime(int n)
{
    for(int i = 2; i<n; i++)
    {
        if(n%i == 0)
        return false;
    }
    return true;
}

int main()
{
    // int a;
    // cin>>a;
    // int b;
    // cin>>b;
    // int c;
    // cin>>c;

    // int sum = getmax(a,b,c);

    // cout<<sum<<endl;

    // int r;
    // cout<<"enter the radius"<<endl;
    // cin>>r;

    // cout<<"the area of  circle is"<<endl;
    // cout<<getCircleArea(r);

    // int n;
    // cout<<"the number is"<<endl;
    // cin>>n;

    // cout<<prime(n);
    // int n;
    // cin>>n;

    // while(n!= 0)
    // {
    //     int rem = n%10;
    //     cout<<rem<<endl;
    //     n = n/10;
    // }

    // int n;
    // cout<<"the number is"<<endl;
    // cin>>n;

    // int count  = 0;

    // while(n!= 0)
    // {
    //     if(n&1)
    //     {
    //         count++;
    //     }

    //     n = n>>1;
    // }
    // cout<<count;

    char ch = -96;

    cout<< (ch<<1) <<endl;

    return 0;
}