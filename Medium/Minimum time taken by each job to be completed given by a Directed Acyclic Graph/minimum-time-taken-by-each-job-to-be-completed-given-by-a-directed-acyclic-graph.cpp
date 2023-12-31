//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        //the tasks can never be completed if cycle exits in the graph
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {//converting into ajacency list
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        //form indegree
         vector<int> indegree(n+1,0);
         for(int i=1;i<=n;i++){
           for(auto it : adj[i]){
             indegree[it]++;
         }}
         
         vector<int> jobs(n,0);
         queue<int> q;
         for(int i=1;i<=n;i++){
             if(indegree[i]==0){
                 jobs[i-1]=1;
                 q.push(i);
             }
         }
         
         while(!q.empty()){
             int curr=q.front();
             q.pop();
             for(auto neigh : adj[curr]){
                    indegree[neigh]--;
                    if(indegree[neigh]==0){
                     jobs[neigh-1] = jobs[curr-1] + 1;
                     q.push(neigh);}
             }
             
         }
         return jobs;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends