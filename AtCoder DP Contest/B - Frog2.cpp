#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;

vi a;
int n,k;
int dp[100100];
int rec(int i){
    if(i==n-1){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    int ans=LLONG_MAX;
    for(int j=1;j<=k;j++){
        if(i+j<n)
            ans=min(ans,abs(a[i+j]-a[i])+rec(i+j));
    }
    return dp[i]=ans;
}
int32_t main() {
    cin>>n>>k;
    a=vi(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0);

}
