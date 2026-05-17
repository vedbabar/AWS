#include <bits/stdc++.h>
using namespace std;

typedef pair<int,string> pii;

int main(){
    int m;
    cout<<"Enter number of roads: ";
    cin>>m;

    unordered_map<
        string,
        vector<pair<string,int>>
    > adj;

    cout<<"Enter roads (city1 city2 distance):"<<endl;
    for(int i=0;i<m;i++){
        string u,v;
        int wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    string src,dest;
    cout<<"Enter source and destination: ";
    cin>>src>>dest;
    unordered_map<string,int> dist;
    unordered_map<string,string> parent;

    for(auto it : adj){
        dist[it.first] = INT_MAX; // just like vector , fill all places by maxi
    }

    priority_queue<
        pii,
        vector<pii>,
        greater<pii>
    > pq;

    dist[src] = 0;
    parent[src] = src;
    pq.push({0,src});

    while(!pq.empty()){
        auto it= pq.top();
        int d = it.first;
        string node = it.second;
        pq.pop();
        for(auto it : adj[node]){
            string nxt = it.first;
            int wt = it.second;
            if(d + wt < dist[nxt]){
                dist[nxt] = d + wt;
                parent[nxt] = node;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    if(dist[dest] == INT_MAX){
        cout<<"No Path Exists";
        return 0;
    }

    cout<<"\nShortest Distance = "<<dist[dest]<<endl;

    vector<string> path;
    string node = dest;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(src);
    reverse(path.begin(),path.end());
    cout<<"Shortest Path: ";
    for(auto city : path){
        cout<<city<<" ";
    }
}