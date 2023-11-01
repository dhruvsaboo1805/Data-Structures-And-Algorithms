#include<iostream>
#include<queue>
#include<limits.h>

using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


class Node
{
    public:
    int size;
    int MaxVal;
    int MinVal;
    bool ValidBst;

    Node(int size,int max, int min,int Valid)
    {
        this->size = size;
        MaxVal = max;
        MinVal = min;
        ValidBst = Valid;
    }
};
void LevelOrderTraversal(TreeNode* &root)
{
    queue<TreeNode*> qt;
    //step 1 temp me store karo
    qt.push(root);
    qt.push(NULL);
    
    while(!qt.empty())
    {
        TreeNode* temp = qt.front();
        qt.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!qt.empty())
            {
                qt.push(NULL);
            }
        }
        else
        {
        cout<<temp->data<<" ";
        if(temp->left)
        {
            qt.push(temp->left);
        }
        if(temp->right)
        {
            qt.push(temp->right);
        }
        }
    }
}
  TreeNode* CreateBST(TreeNode* &root,int data)
  {
    if(root == NULL)
    {
        TreeNode * root = new TreeNode(data);
        return root;
    }

    // 1 case solve karte hain
    if(root->data > data)
    {
        root->left = CreateBST(root->left,data);
    }
    else{
        root->right = CreateBST(root->right,data);
    }

    return root;
  }

  void takeInput(TreeNode* &root) {
        int data;
        cin >> data;

        while(data != -1) {
                root = CreateBST(root, data);
                cin >> data;
        }
}

TreeNode* SearchInBST(TreeNode* &root,int target)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == target)
    {
        return root;
    }

    if(root->data > target)
    {
        return  SearchInBST(root->left,target);
    }
    if(root->data < target)
    {
        return SearchInBST(root->right,target);
    }

    
}

void BSTtoDLL(TreeNode* root, TreeNode* &head)
{
    if(root == NULL)
    {
        return;
    }

    // solve right part
    BSTtoDLL(root->right, head);
    root->right = head;

    if(head != NULL)
    head -> left = root;


    head = root;

    //left ka call
    BSTtoDLL(root->left, head);
}

TreeNode *DLLTOBST(TreeNode* &head,int n)
{
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode* leftsubtree = DLLTOBST(head,(n-1-n/2));
    TreeNode* root=  head;
    root->left = leftsubtree;

    head == head->right;

    root->right = DLLTOBST(head,n/2);
    return root;

    
}
void PrintDLL(TreeNode* head)
{
    TreeNode* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

// very very very imp question find max bst from a binary tree

TreeNode* BTtoLargestBST(TreeNode* root,int &ans)
{
    if(root == NULL)
    {
        Node* temp = new Node(0,INT_MIN,INT_MAX,true);
        return temp;
    }

    int leftkanas = BTtoLargestBST(root->left,ans);
    int rightkaans = BTtoLargestBST(root->right,ans);

    Node* CurrNode = new Node();
    CurrNode->size = leftkanas->size + rightkaans->size + 1;
    CurrNode->MaxVal = max(root->data, rightkaans->MaxVal);
    CurrNode->MinVal = min(root->data,leftkanas->MinVal);

    if(leftkanas->ValidBst && rightkaans->ValidBst && root->data > leftkanas.MaxVal && root->data < rightkaans->MinVal)
    {
        CurrNode->ValidBst = true;
    }
    else{
        CurrNode->ValidBst = false;
    }

    if(CurrNode->ValidBst)
    {
        ans = max(ans,CurrNode->size);
    }

    return CurrNode;
}
int main()
{
    TreeNode* root = NULL;
    TreeNode*head = NULL;
    int data;
    cout<<"enter the data for the tree"<<endl;
    takeInput(root);
    DLLTOBST(head,8);

    cout<<"the tree formation of the anove taken data is "<<endl;
    // cout<<"printing the tree"<<endl;
    LevelOrderTraversal(root);

    // cout<<"tell us about the target value in the tree"<<endl;
    // cout<<SearchInBST(root,30)<<endl;

    // BSTtoDLL(root,head);
    // PrintDLL(head);



    return 0;

}