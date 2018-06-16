#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
}

void bfs(vector<int> adj[],int V,int u){

	vector<bool> visited(V,false);
	vector<int> dist(V);
	vector<int> parent(V);
	queue<int> q;

	visited[u]=true;
	parent[u]=-1;
	dist[u]=0;
	q.push(u);

	while(!q.empty()){
		u=q.front();
		q.pop();
		cout << u << " -> ";
		for(int i=0;i<adj[u].size();i++){
			if(!visited[adj[u][i]]){
				visited[adj[u][i]]=true;
				dist[adj[u][i]]=dist[u]+1;
				parent[adj[u][i]]=u;
				q.push(adj[u][i]);
			}
		}
	}

	cout << endl;
	for (int i = 0; i < V; ++i)
	{
		cout << dist[i] << " ";
	}

	cout << endl;
	for (int i = 0; i < V; ++i)
	{
		cout << parent[i] << " ";
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int v=5;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,4,3);
	addEdge(adj,1,4);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,1,3);

	bfs(adj,v,0);

	return 0;
}
