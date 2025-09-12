#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;

int n,k;
vi a;
int dp[100100];
int rec(int k){
    if(k==0)return 0;
    if(dp[k]!=-1)return dp[k];
    bool ans=0;
    for(int i=0;i<n;i++){
        if(k-a[i]>=0 and rec(k-a[i])==0){
            ans=1;
            break;
        }
    }
    return dp[k]=ans;
}
void solve(){
    cin>>n>>k;
    a=vi(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans=rec(k);
    if(ans)cout<<"First\n";
    else cout<<"Second\n";
}

int32_t main(){
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
