#include<bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;
int N,W;
vi wt,profit;

int dp[101][100100];
//min wt I will need to take in [i..n-1] to make p profit
int rec(int i,int p){
    if(p<0)return 1e9;
    if(i==N){
        if(p==0)return 0;
        return 1e9;
    }
    if(dp[i][p]!=-1)return dp[i][p];
    int dontTake=rec(i+1,p);
    int take=wt[i]+rec(i+1,p-profit[i]);
    return dp[i][p]=min(take,dontTake);
}
void solve(){
    cin>>N>>W;
    wt=vi(N);
    profit=vi(N);
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>wt[i]>>profit[i];
        sum+=profit[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=sum;i++){
        if(rec(0,i)<=W){
            ans=i;
        }
    }
    cout<<ans<<"\n";
}
int32_t main(){
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}