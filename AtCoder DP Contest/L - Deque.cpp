#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;

int n;
vi a;
// int dp[3001][3001][2];
// int rec(int i,int j,int turn){
//     if(i>j)return 0;
//     if(dp[i][j][turn]!=-1)return dp[i][j][turn];
//     if(turn==0){
//         int ans=-1e18;
//         ans=max(ans,a[i]+rec(i+1,j,1));
//         ans=max(ans,a[j]+rec(i,j-1,1));
//         return dp[i][j][turn]=ans;
//     }else if(turn==1){
//         int ans=1e18;
//         ans=min(ans,rec(i+1,j,0)-a[i]);
//         ans=min(ans,rec(i,j-1,0)-a[j]);
//         return dp[i][j][turn]=ans;
//     }
//     return 0;//never reach
// }

int dp[3001][3001];
int rec(int i,int j){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=-1e18;
    ans=max(ans,a[i]-rec(i+1,j));
    ans=max(ans,a[j]-rec(i,j-1));
    return dp[i][j]=ans;
}
void solve(){
    cin>>n;
    a=vi(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<"\n";
    
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

}
