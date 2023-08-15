#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int>pii;

//range 
const int N=1e3+5;

//infinity range
const int INF=1e9+7;

//adjacency list
vector<pii>adj[N];

//distance array
vector<int>dist(N, INF);

//bool visited array
vector<bool>visited(N);



void dijkstra(int source){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    dist[source]=0;
    pq.push({dist[source], source});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        for(pii vPair: adj[u]){
            int v=vPair.first;
            int w=vPair.second;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    int s, d;
    cin>>s>>d;
    dijkstra(s);
    cout<<dist[d]<<endl;
    
    return 0;
}