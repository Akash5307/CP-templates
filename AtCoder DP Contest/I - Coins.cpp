#include<bits/stdc++.h>
using namespace std;
#define ll long long int
using vi=vector<int>;
const int mod=1e9+7;

int N;
vector<double> p;
vector<vector<double>> dp;
vector<vector<bool>> vis;

double rec(int i, int heads) {
    if(i<0){
        return (heads==0?1.0:0.0);
    }
    if (heads<0)return 0.0;
    if (vis[i][heads])return dp[i][heads];

    vis[i][heads]=true;
    double prob=rec(i-1,heads)*(1.0-p[i]);
    prob+=rec(i-1,heads-1)*p[i];

    return dp[i][heads]=prob;
}
void solve(){
    cin >> N;
    p.resize(N);
    for (int i=0;i<N;i++)cin>>p[i];

    dp.assign(N,vector<double>(N+1,0.0));
    vis.assign(N,vector<bool>(N+1,false));

    double ans=0.0;
    for (int heads=N/2+1;heads<=N;heads++) {
        ans+=rec(N-1,heads);
    }

    cout<<fixed<<setprecision(10)<<ans<<"\n";
}
int main(){
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}