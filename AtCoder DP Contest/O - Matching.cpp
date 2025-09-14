#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;
const int mod=1e9+7;
int n;
vector<vi>a;
int dp[22][(1<<22)];
int rec(int i,int mask){
    if(mask==(1<<n)-1)return 1;
    if(i==n)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=0;
    for(int j=0;j<n;j++){
        if((mask&(1<<j))==0 and a[i][j]){
            ans+=rec(i+1,(mask|(1<<j)));
            ans%=mod;
        }
    }
    return dp[i][mask]=ans;
}
void solve(){
    cin>>n;
    a=vector<vi>(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

}
