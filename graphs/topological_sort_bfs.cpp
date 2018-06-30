#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

vector<int> ts;

void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
}

void bfs(vector<int> adj[],vector<bool> &visited,int V,int u){
	
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int V=8;
	ts.clear();
	vector<int> adj[V];
	vector<bool> visited(V,false);
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,2,5);
	addEdge(adj,3,4);
	addEdge(adj,7,6);
	for(int i=0;i<V;i++){
		if(!visited[i]){
			bfs(adj,visited,V,i);	
		}
	}

	return 0;
}
