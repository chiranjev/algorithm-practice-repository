#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool isCyclicBfs(vector<int> adj[],int V,int u){

	vector<bool> visited(V,false);
	vector<int> parent(V);

	queue<int> q;

	visited[u]=true;
	parent[u]=-1;
	q.push(u);

	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			if(visited[adj[u][i]]&&parent[u]!=adj[u][i]){
				return true;
			}else if(!visited[adj[u][i]]){
				visited[adj[u][i]]=true;
				parent[adj[u][i]]=u;
				q.push(adj[u][i]);
			}
		}
	}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int v=4;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,3,0);

	if(isCyclicBfs(adj,v,0)){
		cout << "Graph is cyclic";
	}else{
		cout << "Graph is not cyclic";
	}

	return 0;
}
