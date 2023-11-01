#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
// #include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<set>
// template<Typename T>
using namespace std;



// class Graph
// {
//     public:
//     unordered_map<int , list<int>> adjList;

//     void AddEdge(int src, int dest, bool direction)
//     {
//         // direction = 0 // undirected graph
//         // direction  == 1 directed graph
//         adjList[src].push_back(dest);  // since we have madea list that is neighbours we are pushing neighbours
//         if(direction == 0)
//         {
//             adjList[dest].push_back(src); // since undirected graph
//         }
//     }

//     void PrintAdjList()
//     {
//         for(auto node : adjList)
//         {
//             cout<<node.first<<" -> ";
//             for(auto neighbours : node.second)
//             {
//                 cout<<neighbours<<", ";
//             }
//             cout<<endl;
//         }
//     }

//     void BFS(int src, unordered_map<int,bool> &visited)
//     {
//         queue<int> q;
//         q.push(src);
       
//         visited[src] = true;

//         while(!q.empty())
//         {
//             // step 1
//             int ans = q.front();
//             // step 2
//             q.pop();

//             cout<<ans<<", ";

//             for(auto neighbours : adjList[ans])
//             {
//                 if(visited[neighbours] != true)
//                 q.push(neighbours);

//                 visited[neighbours] = true; 
//             }

//             // step 4
            

//         }
//     }

//     void DFS(int src , unordered_map<int,bool> &visited2)
//     {
//         cout<<src<<", ";
//         visited2[src]  = true;

//         for(auto neighbour: adjList[src])
//         {
//             if(visited2[neighbour] != true)
//             DFS(neighbour,visited2);
//         }
//     }

//     bool CheckCycleBFS(int src , unordered_map<int,bool> &visited)
//     {
//         queue<int> q;
//         q.push(src);

//         unordered_map<int,int> parent;
//         visited[src] = true;
//         parent[src] = -1;

//         while(!q.empty())
//         {
//             int FrontNode = q.front();
//             q.pop();

//             for(auto neighbour : adjList[FrontNode])
//             {
//                 if(!visited[neighbour])
//                 {
//                     q.push(neighbour);
//                     visited[neighbour] = true;
//                     parent[neighbour] = FrontNode;                
//                 }
//                 else
//                 {
//                     // already visited
//                     if(neighbour != parent[FrontNode])
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }

//     bool CheckCycleDFS(int src ,unordered_map<int,bool> &visited, int parent )
//     {
//         visited[src] = true;

//         for(auto nbr: adjList[src])
//         {
//             if(!visited[nbr])
//             {
//                 bool aangekaans = CheckCycleDFS(nbr,visited,src);
//                 if(aangekaans == true)
//                 return true;
//             }
//             else
//             {
//                 if(nbr != parent)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool CheckCycleDirectedDFS(int src , unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsvisited)
//     {
//         visited[src] = true;
//         dfsvisited[src] = true;

//         for(auto nbr : adjList[src])
//         {
//             if(!visited[nbr])
//             {
//                 bool aangeKaAns = CheckCycleDirectedDFS(nbr,visited,dfsvisited);
//                 if(aangeKaAns == true)
//                 {
//                     return true;
//                 }
//             }
//             else
//             {
//                 if(dfsvisited[nbr] == true)
//                 {
//                     return true;
//                 }
//             }
//         }
//         // yha glti hongi backtracking main
//         visited[src] = false;
//         return false;
//     }

    // void TopoLogiaclSortDFS(int src , unordered_map<int,bool> &visited, stack<int> &ans)
    // {
    //     visited[src] = true;

    //     for(auto nbr: adjList[src])
    //     {
    //         if(visited[nbr] != true)
    //         {
    //             TopoLogiaclSortDFS(nbr,visited, ans);
    //         }
    //     }
    //     // while returning we want to push into stack
    //     ans.push(src);
    // }

//     void TopoLogiaclSortBFS(int n , vector<int> &ans)
//     {
//         queue<int> q;
//         unordered_map<int ,int> indegree;

//         // take ou the indegree of eb=very element by adj list only sincxe we khow where is the edge pointing from that only we will take out

//         for(auto i: adjList)
//         {
//             int src = i.first;
//             // us src ke liye mere saare nbr ++ hon jayenge
//             for(auto nbr : i.second)
//             {
//                 indegree[nbr]++;
//             }
//         }

//         for(auto i : indegree)
//         {
//             cout<<i.first<<" - > "<<i.second<<", "<<endl;
//         }cout<<endl;
        
//         // since we have to push all elements having indegree as 0 int o queue
//         for(int i = 0; i < n ;i++)
//         {
//             if(indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         // ab voi bfs waala logic
//         while(!q.empty())
//         {
//             int FNode = q.front();
//             q.pop();

//             ans.push_back(FNode);
//             // after pushing the element we know that the indegree of all the nbr will be decremented
//             for(auto nbr : adjList[FNode])
//             {
//                 indegree[nbr]--;
//                 if(indegree[nbr] == 0)
//                 {
//                     q.push(nbr);
//                 }
//             }

            
//         }

//     }
// };

class Graph
{
    public:
    unordered_map<int , list<pair<int,int> >> adjList;

    void AddEdge(int src, int dest,int weight, bool direction)
    {
        // direction = 0 // undirected graph
        // direction  == 1 directed graph
        adjList[src].push_back({dest,weight});  // since we have madea list that is neighbours we are pushing neighbours
        if(direction == 0)
        {
            adjList[dest].push_back({src,weight}); // since undirected graph
        }
    }

    void PrintAdjList()
    {
        for(auto node : adjList)
        {
            cout<<node.first<<" -> ";
            for(auto neighbours : node.second)
            {
                cout<<"{ "<<neighbours.first<<" , "<<neighbours.second<<" } ";
            }
            cout<<endl;
        }
    }



    // shortest path using BFS in undirected graph

    void ShortestPathBFS(int src , int dest)
    {
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initial cond
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            int Fnode = q.front();
            q.pop();

            // travetse in the nbr array for making visted and parent
            for(auto nbr : adjList[Fnode])
            {
                if(!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = Fnode;
                }
            }
        }

        // printing the parent array and then finally the shortest path
        vector<int> ans;
        int node = dest;
        while(node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" -> ";
        }cout<<endl;

    } 

    void TopoLogiaclSortDFS(int src , unordered_map<int,bool> &visited, stack<int> &ans)
    {
        visited[src] = true;

        for(auto nbr: adjList[src])
        {
            if(visited[nbr.first] != true)
            {
                TopoLogiaclSortDFS(nbr.first,visited, ans);
            }
        }
        // while returning we want to push into stack
        // cout<<src<<endl;
        ans.push(src);
    }

    // dijkaustra algo ki jhalak wala question hain ye
    void ShortestPathTopoOrder(int dest , stack<int> &TopoOrder , int n)
    {
        vector<int> dist(n,INT_MAX);

        int src = TopoOrder.top();
        TopoOrder.pop();

        dist[src] = 0;
        for(auto nbr : adjList[src])
        {
            if(dist[0] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while(!TopoOrder.empty())
        {
            int TopValue = TopoOrder.top();
            TopoOrder.pop();

            if(dist[TopValue] != INT_MAX)
            {
                for(auto nbr : adjList[TopValue])
                {
                    if(dist[TopValue] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[TopValue] + nbr.second;
                    }
                }
            }        
        }

        cout<<" Printing the dist array"<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<i<<"- > "<<dist[i]<<endl;
        }
    }

    void DijkstraAlgo(int src , int n)
    {
        // create set or min heap and dist array
        vector<int> dist(n , INT_MAX);
        set<pair<int,int>> st;

        // initial steps for src node
        dist[src] = 0;
        st.insert(make_pair(0,src));

        // looking for whole set
        while(!st.empty())
        {
            // since its a set we have to return an iterator to find out first eleemnt
            auto TopElement = *(st.begin()); // since its an iterator
            int NodeDist = TopElement.first;
            int Node = TopElement.second;

            // remove the entry from set
            st.erase(st.begin());

            // important step to put into disteance array
            for( auto nbr : adjList[Node])
            {
                // check whether the distance is less to be putted in dist array
                if(NodeDist + nbr.second < dist[nbr.first])
                {
                    // to find whether the dist array would be updating with the elemnt to be find

                    auto Result = st.find(make_pair(dist[nbr.first] , nbr.first));

                    // erase it thet is if found
                    if(Result != st.end())
                    {
                        st.erase(Result);
                    }
                // now after removeing we will put it to dist array and set
                dist[nbr.first] = NodeDist + nbr.second;
                st.insert(make_pair( dist[nbr.first], nbr.first));
                }
            }
        }

        cout<<"printing "<<endl;
        for(int i = 0; i < n ;i++)
        {
            cout<<dist[i]<<" ";
        }cout<<endl;
    }

};

int main()
{


    Graph g;
    int n = 7;
    // stack<int> TopoOrder;
    // unordered_map<int, bool> visited;
    // undirected graph
    g.AddEdge(6,5,9,0);
    g.AddEdge(6,3,2,0);
    g.AddEdge(6,1,14,0);
    g.AddEdge(5,4,1,0);
    g.AddEdge(4,3,11,0);
    g.AddEdge(4,2,15,0);
    g.AddEdge(3,1,9,0);
    g.AddEdge(3,2,10,0);
    g.AddEdge(1,2,7,0);

    cout<<endl;
    g.PrintAdjList();

    // int src = 0;
    // int dest = 4;

    // g.TopoLogiaclSortDFS(src, visited, TopoOrder);
    // cout<<endl;
    // cout<<TopoOrder.size()<<endl;

    // g.ShortestPathTopoOrder(dest , TopoOrder , n);
    g.DijkstraAlgo(6,n);

    

    
    // cout<<endl;
    // g.PrintAdjList();
    // g.AddEdge(0,1,0);
    // g.AddEdge(1,2,0);
    // g.AddEdge(1,3,0);
    // g.AddEdge(2,6,0);
    // g.AddEdge(3,4,0);
    // g.AddEdge(3,5,0);
    // g.AddEdge(5,6,0);
    // g.AddEdge(5,7,0);
    // g.AddEdge(0,1,1);
    // g.AddEdge(1,2,1);
    // g.AddEdge(6,1,1);
    // g.AddEdge(2,3,1);
    // g.AddEdge(3,4,1);
    // g.AddEdge(4,7,1);
    // g.AddEdge(4,8,1);
    // g.AddEdge(5,6,1);
    // g.AddEdge(4,5,1);
    
    // cout<<endl;
    // g.PrintAdjList();

    // cout<<endl;
    // g.TopoLogiaclSortDFS(0,visited,TopoOrder);
    // unordered_map<int,bool> visited;
    // // for disconnected graph always follow this procedure not for disconnected only its a good practise to follow this approach
    // for(int i = 0; i < n; i++)
    // {
    //     // we will be checking for every node to be visited or not or considering every node to be src node
    //     if(!visited[i])
    //     {
    //         g.BFS(0,visited);
            
    //     }
    // } 
    
    // cout<<endl<<endl;
    // unordered_map<int,bool> visited2;
    // for(int i = 0; i < n; i++)
    // {
    //     // we will be checking for every node to be visited or not or considering every node to be src node
    //     if(!visited2[i])
    //     {
    //         g.DFS(0,visited2);
            
    //     }
    // } 
    // bool ans = false;
    // for(int i = 0; i < n ;i++)
    // {
    //     if(!visited[i])
    //     {
    //         ans = g.CheckCycleBFS(0,visited);
    //         if(ans == true)
    //         break;
    //     }
    // }

    // if(ans == true)
    // {
    //     cout<<" present"<<endl;
    // }
    // else
    // {
    //     cout<<" not present"<<endl;
    // }

    // bool ans1 = false;
    // for(int i = 0; i < n ;i++)
    // {
    //     if(!visited[i])
    //     {
    //         ans1 = g.CheckCycleDFS(0,visited,-1);
    //         if(ans1 == true)
    //         break;
    //     }
    // }

    // if(ans1 == true)
    // {
    //     cout<<" present"<<endl;
    // }
    // else
    // {
    //     cout<<" not present"<<endl;
    // }


    // bool ans2 = false;
    // unordered_map<int,bool> dfsvisited;
    // for(int i = 0; i < n ;i++)
    // {
    //     if(!visited[i])
    //     {
    //         ans2 = g.CheckCycleDirectedDFS(0,visited,dfsvisited);
    //         if(ans2 == true)
    //         break;
    //     }
    // }

    // if(ans2 == true)
    // {
    //     cout<<" present"<<endl;
    // }
    // else
    // {
    //     cout<<" not present"<<endl;
    // }



    // unordered_map<int,bool> visited;
    // stack<int> ans;
    // for(int i = 0; i< n; i++)
    // {
    //     if(!visited[i])
    //     {
    //         g.TopoLogiaclSortDFS(0,visited,ans);
    //     }
    // }

    // while(!ans.empty())
    // {
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // }

    // vector<int> ans;
    // g.TopoLogiaclSortBFS(n,ans);

    // for(auto i: ans){
    //     cout<<i << " ";
    // }cout<<endl;

    // if(ans.size() == n)
    // {
    //     cout<<" No Cycle"<<endl;
    // }
    // else
    // {
    //     cout<<"Cycle Present "<<endl;
    // }

    // int src = 1;
    // int dest = 6;

    // cout<<endl;
    // g.ShortestPathBFS(src , dest);

    









    // int n;
    // cout<<"the number of nodes are "<<endl;
    // cin>>n;

    // vector<vector<int>> adj(n, vector<int>(n,0));

    // int e;
    // cout<<"the number of edges is "<<endl;
    // cin>>e;

    // for(int i = 0; i<= e; i++)
    // {
    //     int u,v;
    //     cin>>u>>v;

    //     adj[u][v] = 1;
    // }

    // for(int i = 0; i<n; i++)
    // {
    //     for(int j = 0; j <n ;j++)
    //     {
    //         cout<< adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}