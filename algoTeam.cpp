#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	map<char,int> mp;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		mp[s[0]]++;
	}
	bool flag = false;
	map<char,int>::iterator it = mp.begin();
	for(;it!=mp.end();it++){
		if(it->second >=5 ){
			flag = true;
			 printf("%c",it->first);
		}
	}
	if(!flag) printf("inzva");
	
}
