#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

using namespace std;
//a yuzde kare
vector<pair<int,pair<int,int>>> vc[5000];
double ar[5000];
double DFS(int k){
    double ans = 0;
    if(vc[k].size()==0)
        return ar[k];
    for(int i=0;i<vc[k].size();i++){
        double yuzde= vc[k][i].sc.fi;
        int kare = vc[k][i].sc.sc;
        double deger = DFS(vc[k][i].fi);
        if(kare){
            deger = sqrt(deger);
        }
        ans = max(ans, deger*100/yuzde);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int o1,o2,o3,o4;
        cin >> o1 >> o2 >> o3 >> o4 ;
        vc[o1].pb(mp(o2,mp(o3,o4)));
    }
    for(int i=0;i<n;i++){
        cin>> ar[i+1];
    }
    double res;
    res = DFS(1);
    printf("%lf",res);
    
}
