#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

//range
const int N=1e3+7;

//infinity range
const int INF=1e9+7;

//distance array
vector<int>dist(N, INF);

//visited bool array
vector<bool>visited(N);
//vector adjacency
vector<pii>adj[N];

//dijkstra implementation
void dijkstra(int source){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    dist[source]=0;
    pq.push({dist[source], source});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        for(pii vpair:adj[u]){
            int v=vpair.first;
            int w=vpair.second;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m;i++){
        int u,v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    dijkstra(1);

    //print 
    for(int i=1; i<=n;i++){
        cout<<"distance of node "<<i<<": ";
        cout<<dist[i]<<endl;
    }
    return 0;
}