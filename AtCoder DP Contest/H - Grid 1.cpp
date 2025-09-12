#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;
using vi=vector<int>;

int n,m;
vector<vector<char>>grid;
int dp[1001][1001];
int rec(int i,int j){
    if(i==n or j==m)return 0;
    if(i==n-1 and j==m-1){
        if(grid[i][j]=='#')return 0;
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(grid[i][j]=='#'){
        return 0;
    }
    int ans=rec(i+1,j);
    ans+=rec(i,j+1);
    ans%=mod;
    return dp[i][j]=ans;
}
void solve(){
    cin>>n>>m;
    grid=vector<vector<char>>(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
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
