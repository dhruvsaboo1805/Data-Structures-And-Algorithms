#include<iostream>
#include<queue>
#include<map>

using namespace std;

// creation of binary tree

class TreeNode
{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

TreeNode* CreateTree()
{
    int data;
    cout<<"enter the data: "<<endl;
    cin>>data;
    if(data == -1)
    {
        return NULL;
    }

    // step 1 creatre a root node
    TreeNode*root = new TreeNode(data);

    // baaki recursion sabhal lenga
    cout<<"left most data of tree of node "<<data<<endl;
    root->left = CreateTree();
    cout<<"right most data of tree of node "<<data<<endl;
    root->right = CreateTree();

    return root;


}

// level order traversel

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

    void InorderTraverversal(TreeNode* &root)
    {
        if(root == NULL)
        {
            return;
        }

        // LEFT ROOT RIGHT
        // move left
        InorderTraverversal(root->left);
        // move to root and print
        cout<<root->data<<" ";
        // move right
        InorderTraverversal(root->right);

    }

    void PreorderTraverversal(TreeNode* &root)
    {
        if(root == NULL)
        {
            return;
        }

        // ROOT LEFT  RIGHT
        // move to root and print
        cout<<root->data<<" ";
        // move left
        PreorderTraverversal(root->left);
        // move right
        PreorderTraverversal(root->right);

    }

    void PostorderTraverversal(TreeNode* &root)
    {
        if(root == NULL)
        {
            return;
        }

        // LEFT RIGHT ROOT
        // move left
        PostorderTraverversal(root->left);
        // move right
        PostorderTraverversal(root->right);
        // move to root and print
        cout<<root->data<<" ";

    }


    int SumTree(TreeNode* &root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int LeftKaAns = SumTree(root->left);
        int RightKaAns = SumTree(root->right);
        root->data = LeftKaAns + root->data +  RightKaAns;

        return root->data;
    }

    int FindPosition(int inorder[],int size,int element)
    {
        for(int i = 0; i <size; i++)
        {
            if(inorder[i] == element)
            return i;
        }
        return -1;
    }

    TreeNode * BuildInorderPreordertoTree(int inorder[], int preorder[],int size,int InorderStart,int InorderEnd,int &PreorderIndex)
    {
        // base case
        if(PreorderIndex >= size || InorderStart > InorderEnd)     // SECOND CONDITION TELLS ABOUT THE ONE ELEMENT
        {
            return NULL;
        }

        // 1 CASE SOLVE KARNA HAIN
        int element = preorder[PreorderIndex++];
        TreeNode * root = new TreeNode(element);
        int pos =  FindPosition(inorder,size,element);

        // baaki recursion sambhal lenga

        root->left = BuildInorderPreordertoTree(inorder,preorder,size,InorderStart,pos-1,PreorderIndex);
        root->right = BuildInorderPreordertoTree(inorder,preorder,size,pos+1,InorderEnd,PreorderIndex);

        return root;

    }

    void PrintTopView(TreeNode *& root,vector<int> ans)
    {
        if(root == NULL)
        return;
        
        // since we have to map two things horizontal distance and top node->data  
        map<int,int> TopNode;

        // level order
        // we have to make a queue hich will be having a pair of horizontal deistance and frontnode->data
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));

        while(!q.empty())
        {
            pair<TreeNode*,int> temp = q.front();
            q.pop();

            TreeNode* FirstNode = temp.first;
            int hd = temp.second;

            if(TopNode.find(hd) == TopNode.end())
            {
                TopNode[hd] = FirstNode->data;
            }

            if(FirstNode -> left)
            {
                q.push(make_pair(FirstNode->left,hd-1));
            }
            if(FirstNode->right)
            {
                q.push(make_pair(FirstNode->right,hd+1));
            }
        }

        cout<<"the mapping done is"<<endl;
        for(auto i : TopNode)
        {
            ans.push_back(i.second);
        }
    



    }
int main()
{
    TreeNode*root = NULL;

    // root = CreateTree();

    // // LevelOrderTraversal(root);


    // cout<<"inorder traversal of the given tree is "<<endl;
    // InorderTraverversal(root);
    // cout<<endl;

    // cout<<"preorder traversal of the given tree is "<<endl;
    // PreorderTraverversal(root);
    // cout<<endl;

    // cout<<"postorder traversal of the given tree is "<<endl;
    // PostorderTraverversal(root);
    // cout<<endl;


//  convert binary tree into sum tree

//    10                         280 (110 + 160 + 10)
// 20     30     ---->>>       110(20 + 40 + 50)        160(70 + 60 + 30)
//40 50 60 70                40       50             60                70
                        //  0  0     0  0          0     0           0      0

    
    
  
        // CreateTree();
        // // int temp = root->data;
        // int ans = SumTree(root);

        // cout<<ans<<endl;



        // GIVEN INORDER AND PREORDER ARRAY FIND THE TREE LEETCODE 105


        // int inorder[] = {40,20,50,10,60,30,70};
        // int preorder[] = {10,20,40,50,30,60,70};

        // int size = 7;
        // int InorderStart = 0;
        // int InorderEnd = size-1;
        // int PreorderIndex = 0;
        // cout<<"bulid tree"<<endl;
        // root = BuildInorderPreordertoTree(inorder,preorder,size,InorderStart,InorderEnd,PreorderIndex);
        // cout<<"printint the elements of the tree"<<endl;

        // LevelOrderTraversal(root);
         
         vector<int> ans;
         root = CreateTree();
         PrintTopView(root,ans);

        for(auto i: ans)
        {
            cout<<i<<endl;
        }
    



}