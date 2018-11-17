#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
vector<vector<int>> graph;
vector<bool> vis;
void BFS(int a,int b){
	queue<pair<int,int>> q;
	q.push(mp(a,0));
	vis[a] = true;
	while(!q.empty()){
		pair<int,int> p = q.front();q.pop();
		int cur = p.first;
		int w = p.second;
		if(cur==b){
			printf("%d\n",w);
			return ;
		}
		for(int i=0;i<graph[cur].size();i++){
			if(!vis[graph[cur][i]]){
				vis[graph[cur][i]] = true;
				q.push(mp(graph[cur][i],w+1));
			}
		}
	}
	printf("No Path\n");
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,a,b;
		scanf("%d%d%d%d",&n,&m,&a,&b);

		graph.clear();
		graph.resize(n+5);
		vis.clear();
		vis.resize(n+5);

		while(m--){
			int x,y;
			cin >> x >> y;
			graph[x].push_back(y);
		}
		BFS(a,b);
		if(t){
			printf("--\n");
		}
	}

}