#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n,m;
    cout<<"Enter number of cities and roads: ";
    cin>>n>>m;
    vector<vector<pii>> adj(n);
    cout<<"Enter roads (u v wt):"<<endl;

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    int src,dest;
    cout<<"Enter source and destination: ";
    cin>>src>>dest;
    vector<int> dist(n,INT_MAX);
    vector<int> parent(n);

    for(int i=0;i<n;i++) parent[i]=i;

    priority_queue<
        pii,
        vector<pii>,
        greater<pii>
    > pq;

    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto it=pq.top();
        int d=it.first;
        int node=it.second;
        pq.pop();
        for(auto it:adj[node]){
            int nxt=it.first;
            int wt=it.second;
            if(d+wt < dist[nxt]){
                dist[nxt]=d+wt;
                parent[nxt]=node;
                pq.push({dist[nxt],nxt});
            }
        }
    }

    if(dist[dest]==INT_MAX){
        cout<<"No Path Exists";
        return 0;
    }

    cout<<"\nShortest Distance = "<<dist[dest]<<endl;
    vector<int> path;
    int node=dest;

    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(src);
    reverse(path.begin(),path.end());

    cout<<"Shortest Path: ";

    for(auto x:path){
        cout<<x<<" ";
    }
}