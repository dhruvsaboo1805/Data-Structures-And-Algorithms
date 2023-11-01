#include<bits/stdc++.h>

using namespace std;

void PrintPermutations(string &str, int i)
{
    // base case
    if(i >= str.length())
    {
        cout<<str<<" ";
        return;
    }

    for(int j = i; j < str.length(); j++)
    {
        swap(str[i] , str[j]);

        PrintPermutations(str,i+1);

        // backtracking call

        swap(str[i] , str[j]);


    }
}

bool IsSafe(int i,int j,int row,int col,int arr[][3],vector<vector<bool>> &visited)
{
    if((i >= 0 && i < row) && (j >= 0 && j< col) && (arr[i][j] == 1) && (visited[i][j] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SolveMaze(int arr[][3], int row,int col,int i,int j,vector<vector<bool>> &visited,vector<string> &path, string output)
{
    //base case
    if(i == row-1 && j == col-1)
    {
        path.push_back(output);
        return;
    }

    // 1 case solve karo baaki recursion sambhal lenga
    // down (i+1,j)

    if(IsSafe(i+1,j,row,col,arr,visited))
    {
    visited[i+1][j] = true;

    SolveMaze(arr,row,col,i+1,j,visited,path,output + 'D');

    // backtrack
    visited[i+1][j] = false;
    }



    // left(i,j-1)

    if(IsSafe(i,j-1,row,col,arr,visited))
    {
    visited[i][j-1] = true;
    
    SolveMaze(arr,row,col,i,j-1,visited,path,output + 'L');

    // backtrack
    visited[i][j-1] = false;
    }

    //right(i,j+1)

    if(IsSafe(i,j+1,row,col,arr,visited))
    {
    visited[i][j+1] = true;
    
    SolveMaze(arr,row,col,i,j+1,visited,path,output + 'R');

    // backtrack
    visited[i][j+1] = false;
    }


    //up(i-1,j)

    if(IsSafe(i-1,j,row,col,arr,visited))
    {
    visited[i-1][j] = true;
    
    SolveMaze(arr,row,col,i-1,j,visited,path,output + 'U');

    // backtrack
    visited[i-1][j] = false;
    }

}

void PrintVectorArray(vector<vector<char> >&board,int n)
{
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
}

bool IsSafeForNQueens(int row,int col,vector<vector<char> >&board,int n)
{
    int i =row;
    int j = col;

    // check right side if any queeen is present or not
    while(j >= 0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    // check upper left diagonal

    i = row;
    j = col;

    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    // check bottom left diagonal
   i = row;
   j = col;


    while(i < n && j >= 0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }

    return true;

}

void SolveForNQuuens(vector<vector<char> >&board,int n,int col)
{
    // base case
    if(col >= n)
    {
        PrintVectorArray(board,n);
        return;
    }

    // 1 case solve karna hain baaki recursion sambhal lenga
    
    for(int row = 0; row < n ;row++)
    {
        if(IsSafeForNQueens(row,col,board,n))
        {
          board[row][col] = 'Q';
          SolveForNQuuens(board,n,col+1);
          // backtrack
          board[row][col] = '.';
        }


    }

}

void GenerateParenthesis(string &output,int used_open,int used_close,int remain_open, int remain_close,vector<string> &ans)
{
    // base case

    if(used_open > n && used_close > n)
    {
         ans.push_back(output);
         return;
    }

    // 1case solve karna hain baki rec sambhal lenga

    // include open bracket
    if(remain_open > 0)
    {
        output.push_back('(');
        GenerateParenthesis(output,used_open + 1,used_close,remain_open-1,remain_close,ans);

        output.pop_back('(');
    }
  
  // include<closed bracket

  if(used_open > used_close)
  {
      output.push_back(')');
      GenerateParenthesis(output,used_open,used_close + 1,remain_open,remain_close - 1,ans);

      output.pop_back(')');
  }
}

int main()
{
    // string str = "abcde";
    // int i = 0;

    // PrintPermutations(str,i);




    // IMPORTANT QUESTION RAT IN A MAZE



    // int maze[3][3] = {{1,0,0},{0,0,0},{0,0,1}};
    // int row = 3;
    // int col = 3;
    // if(maze[0][0] == 0 || maze[row][col] == 0)
    // {
    //     cout<<"not possible"<<endl;
    // }

    // vector<vector<bool> > visited(row, vector<bool>(col,false));

    // visited[0][0] = true;

    // vector<string> path;
    // string output = "";

    // SolveMaze(maze,row,col,0,0,visited,path,output); // 0 0 indicates rat is on  0 0 position

    // for(auto i: path)
    // {
    //     cout<<i<<" ";
    // }
    // // cout<<endl;

    // if(path.size() == 0)
    // {
    //     cout<<"kuch to gadbad hain"<<endl;
    // }





    // important question n- queen problem


    // int n = 5;
    // vector<vector<char> >board(n,vector<char>(n,'.'));

    // int col = 0;

    // SolveForNQuuens(board,n,col);




///   generate parenthesis
     int n = 3;
    string output = "";
    int used_open = 0;
    int used_close = 0;
    int remain_open = n;
    int remain_close = n;
    vector<string>ans;

    GenerateParenthesis(output,used_open,used_close,remain_open,remain_close,ans);



    return 0;
}