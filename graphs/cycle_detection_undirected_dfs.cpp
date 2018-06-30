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

bool isCyclicDfs(vector<int> adj[],vector<bool> &visited,int V,int u,int parent){

	
	visited[u]=true;
	
	for(int i=0;i<adj[u].size();i++){
		if(visited[adj[u][i]]&&adj[u][i]!=parent){
			return true;
		}
		else if(!visited[adj[u][i]]){
			return isCyclicDfs(adj,visited,V,adj[u][i],u);
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

	int V=4;
	vector<int> adj[V];
	vector<bool> visited(V,false);
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,3,0);

	for(int i=0;i<V;i++){
		if(!visited[i]){
			if(isCyclicDfs(adj,visited,V,i,-1)){
				cout << "Graph is cyclic";
				return 0;
			}
		}	
	}
	cout << "Graph is not cyclic";
	return 0;
}
