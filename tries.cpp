#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for(int i = 0; i< 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }

};

void InsertWord(TrieNode* root,string word)
{
    // cout<<"inserting new word with the string "<<word<<endl;
    // base case
    if(word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    //  1 case solve karna hain jo copy me hain
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;


    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // baaki rec sambhaal lenga

    InsertWord(child,word.substr(1));


    
}

bool SerachWord(TrieNode* root, string word)
{
    // base case
    if(word.length() == 0)
    {
        return root->isTerminal;
    }

    // 1 case solve karna hain
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else{
        return false;
    }

    // baaki rec sambhal lenga
    return SerachWord(child,word.substr(1));

}

void DeleteWord(TrieNode* root, string word)
{
    // base case
    if(word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

     // 1 case solve karna hain
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return;
    }

    // baaki rec sambhal lenga
    DeleteWord(child,word.substr(1));




}

int main()
{
    TrieNode * root = new TrieNode('-');

    InsertWord(root,"coding");
    InsertWord(root,"code");
    InsertWord(root,"dhruv");

    DeleteWord(root,"coding");
    DeleteWord(root,"dhruv");

    if(SerachWord(root,"code"))
    {
        cout<<"present"<<endl;
    }
    else
    {
        cout<<"not present"<<endl;
    }


    return 0;
}