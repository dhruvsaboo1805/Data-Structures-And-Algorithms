#include<bits/stdc++.h>
using namespace std;


int getlenth(char ch[])
{
    int i = 0;

    while(ch[i] != '\0')
    {
        i++;
    }
    return i;
}

void ReverseString(char ch[])
{
    int start = 0;
    int end = getlenth(ch) - 1;

    while( start < end)
    {
        swap(ch[start],ch[end]);
        start++;
        end--;
    }
}

bool checkPlaindrome(char ch[])
{
    int i = 0;
    int n = strlen(ch);
    int j = n-1;

    while(i<=j)
    {
        if(ch[i] != ch[j])
        {
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}


void convertIntoUpperCase(char ch[]) {
        int n = strlen(ch);

        for(int i=0; i<n; i++) {
            if(ch[i] == ' ' || ch[i] == '@')
            {
                cout<<" ";
            }
            else{
                 ch[i] = ch[i] -'a' + 'A';
            }

                
        }
}
void convertIntoLowerCase(char ch[]) {
        int n = strlen(ch);

        for(int i=0; i<n; i++) {
            if(ch[i] == ' ' || ch[i] == '@')
            {
                cout<<" ";
            }
            else{
                 ch[i] = ch[i] -'A' + 'a';
            }

                
        }
}


int main()
{
//     char name[1000];
//    cin>>name;

//    cout<<name<<endl;

//    string s;
//    cin>>s;
//    cout<<s<<endl;


// use of getline function;


    // char ch[10000];

    // // cin.getline(ch,2000);
    // getline(cin,ch);
    // cout<<ch<<endl;




    //length of string 




    // char ch[100];

    // cout<<"the string whose length is to be find is "<<endl;

    // cin.getline(ch,100);

    // int ans = getlenth(ch);

    // cout<<"the length of the above string is "<<ans<<endl;

    // cout<<"another method to find the length is "<<strlen(ch)<<endl;



    // reverse a string


    // string ch;

    // getline(cin,ch);


    // ReverseString(ch);
    // cout<<"the reversed string is "<<" "<<ch<<endl;

//    reverse(ch.begin(), ch.end());
//     cout<<ch<<endl;



   // replaces all spaces in the string

//    char ch[100];
   
//    cin.getline(ch,40);
//    int n = getlenth(ch);

//    for(int i = 0; i < n ; i++)
//    {
//        if(ch[i] == ' ')
//        {
//            ch[i] = '#';
//        }
//    }

//    cout<<ch<<endl;



// palindrome in the string 



// char ch[100];

// cin.getline(ch,40);

// if(checkPlaindrome(ch))
// {
//     cout<<"huraeee!!"<<endl;
// }

// else
// {
//     cout<<"hmmmmmm!!"<<endl;
// }


// make all the characters in upper case 

// char ch[100];

// cin.getline(ch,40);

// convertIntoUpperCase(ch);

// cout<<"the upper case converted string is"<<" "<<ch<<endl;


// convertIntoLowerCase(ch);

// cout<<"the lower case converted string is"<<" "<<ch<<endl;









return 0;

}