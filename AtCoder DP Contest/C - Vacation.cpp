#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;

int n;
vi a,b,c;
int dp[101010][4];
int rec(int i,int last){
    if(i==n){
        return 0;
    }
    if(dp[i][last]!=-1)return dp[i][last];
    int op1,op2;
    if(last==1){
        op1=b[i]+rec(i+1,2);   
        op2=c[i]+rec(i+1,3);
    }else if(last==2){
        op1=a[i]+rec(i+1,1);
        op2=c[i]+rec(i+1,3);
    }else if(last==3){
        op1=a[i]+rec(i+1,1);
        op2=b[i]+rec(i+1,2);
    }
    return dp[i][last]=max(op1,op2);
}
void solve(){
    cin>>n;
    a=vi(n);
    b=vi(n);
    c=vi(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int ans=-1e18;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=3;i++){
        ans=max(ans,rec(0,i));
    }
    cout<<ans<<"\n";
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
