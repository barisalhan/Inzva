#include <bits/stdc++.h>

using namespace std;
vector<int> rootVec;

int unionFind(int a){
	vector<int> temp;
	while(rootVec[a] != a){
		temp.push_back(a);
		a = rootVec[a];
	}
	for(int i=0;i<(int)temp.size();i++){
		rootVec[temp[i]] = a;
	}
	
	return a;
}
int main(){
	int n,m;
	cin >> n >> m;
	rootVec.resize(n+5);
	for(int i=1;i<=n;i++){
		rootVec[i] = i;
	}
	while(m--){
		int t,a,b;
		scanf("%d %d %d", &t ,&a ,&b);

		int ra = unionFind(a);
		int rb = unionFind(b);

		if(t==1){
			rootVec[rb] = ra;
		}else{
			if(ra==rb){
				printf("Connect\n");
			}
			else{
				printf("Not Connect\n");
			}
		}

	}
}