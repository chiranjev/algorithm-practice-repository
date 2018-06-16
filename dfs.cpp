#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;


void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
}

void dfs(vector<int> adj[],vector<bool> &visited,int V,int u){

	
	visited[u]=true;
	
	cout << u << " -> ";

	for(int i=0;i<adj[u].size();i++){
		if(!visited[adj[u][i]]){
			dfs(adj,visited,V,adj[u][i]);
		}
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

	int V=9;
	vector<int> adj[V];
	vector<bool> visited(V,false);
	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,4,3);
	addEdge(adj,1,4);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,1,3);
	addEdge(adj,5,7);
	addEdge(adj,8,6);
	addEdge(adj,7,8);

	for(int i=0;i<V;i++){
		if(!visited[i]){
			dfs(adj,visited,V,i);	
			cout << endl;				
		}
	}

	return 0;
}
