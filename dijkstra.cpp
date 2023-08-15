#include<bits/stdc++.h>
using namespace std;

//pair typedef
typedef pair<int , int> pii;
//node and edges
int n,m;

//range 
const int N=1e3+7;

//infinite range
const long long int INF=1e18;

//adjacency list
vector<pair<int, int>>adj[N];

//distance
long long int d[N];

//bool visited array
bool visited[N];

//dijkstra implementation
void dijkstra(int source){
    for(int i=1; i<=n; i++){
        d[i]=INF;
    }
    d[source]=0;
    //priority queue
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({d[source], source});
    while (!pq.empty())
    {
        pii f=pq.top();
        pq.pop();
        int selectedNode=f.second;
        if(visited[selectedNode]) continue;
        visited[selectedNode]=true;
        for(auto child: adj[selectedNode]){
            int edgeCost=child.first;
            int v=child.second;
            if(d[selectedNode]+edgeCost<d[v]){
                d[v]=d[selectedNode]+edgeCost;
                pq.push({d[v], v});
            }
        }
    }
    
    

}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int src=1;
    dijkstra(src);

    //print distance
    for(int i=1; i<=n; i++){
        cout<<d[i]<<" ";
    }
        return 0;
}