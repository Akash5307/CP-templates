#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;

int N,W;
vi wt,val;
int dp[101][100100];
int rec(int i,int curr_w){
    if(curr_w<0)return -1e18;
    if(i==N){
        return 0;
    }
    if(dp[i][curr_w]!=-1)return dp[i][curr_w];
    int dontTake=rec(i+1,curr_w);
    int take=val[i]+rec(i+1,curr_w-wt[i]);
    return dp[i][curr_w]=max(take,dontTake);
}
void solve(){
    cin>>N>>W;
    wt=vi(N);
    val=vi(N);
    for(int i=0;i<N;i++){
        cin>>wt[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W);
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
