#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;

int n;
vi a;
int dp[101010];
int rec(int i){
    if(i==n-1){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    int ans=1e9;
    if(i+1<n)
        ans=min(ans,abs(a[i+1]-a[i])+rec(i+1));
    if(i+2<n)
        ans=min(ans,abs(a[i+2]-a[i])+rec(i+2));
    return dp[i]=ans;
}
void solve(){
    cin>>n;
    a=vi(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0);
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
