#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    void unite(int a,int b){
        int para=find(a);
        int parb=find(b);
        if(para==parb) return;
        else if(size[para]>size[parb]){
            size[para]+=size[parb];
            parent[parb]=para;
        }
        else{
            size[parb]+=size[para];
            parent[para]=parb;
        }
    }
};

int main(){
    // kruskal mst algo
    // we will take number of nodes as input, and dist between each pair of nodes as input
    int n;
    int edges;
    cout<<"Enter number of nodes and edges: ";
    cin>>n>>edges;
    DSU d(n);
    vector<pair<int,pair<int,int>>>v; // wt,{from,to}
    cout<<"Enter from,to and their weights: ";
    for(int i=0;i<edges;i++){
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back({w,{a,b}});
    }
    vector<pair<int,int>>mst;
    sort(v.begin(),v.end());
    int mst_weight=0;
    for(auto it:v){
        int w=it.first;
        int a=it.second.first;
        int b=it.second.second;
        if(d.find(a)!=d.find(b)){
            d.unite(a,b);
            mst.push_back({a,b});
            mst_weight+=w;
        }
    }
    cout<<"MST weight: "<<mst_weight<<endl;
    cout<<"Edges in MST: ";
    for(auto it:mst){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}
