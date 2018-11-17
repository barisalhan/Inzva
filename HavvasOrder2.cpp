#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > tree;

void preorder(int root){
	printf("%d ",root);
	sort(tree[root].begin(),tree[root].end());
	for(int i=0;i<(int)tree[root].size();i++){
		preorder(tree[root][i]);
	}
}
void postorder(int root){
	sort(tree[root].begin(),tree[root].end());
	for(int i=0;i<(int)tree[root].size();i++){
		postorder(tree[root][i]);
	}
	printf("%d ",root);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		tree.clear();
		tree.resize(n+5);

		for(int i=0;i<n-1;i++){
			int a,b;
			cin >> a >> b;
			tree[a].push_back(b);
		}

		preorder(tree[1][0]);
		printf("1 ");
		postorder(tree[1][1]);
		printf("\n");
	}	
}