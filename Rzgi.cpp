#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define sc second
using namespace std;
// b x t
vector<pair<int,pair<int,int>>> vc[5000];
double ar[5000];
double DFS(int a){
    double res = 0;
    if(vc[a].size() == 0){
        return ar[a];
    }
    for(int i=0;i<vc[a].size();i++){
        double deger = DFS(vc[a][i].fi);
        int perc = vc[a][i].sc.fi;
        int super = vc[a][i].sc.sc;
        if(super){
            deger = sqrt(deger);
        }
        res = max(res,deger*100/perc);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b,x,t;
        cin >> a>> b>> x >>t;
        vc[a].push_back(mp(b,mp(x,t)));
    }
    for(int i=1;i<=n;i++){
    	cin >> ar[i];
    }
    double res = DFS(1);
    printf("%lf",res);
}
