#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;
const int mod=1e9+7;

int n,k;
vi a;
// int rec(int i,int k){
//     if(i==n){
//         if(k==0)return 1;
//         return 0;
//     }
//     int ans=rec(i+1,k);
//     for(int x=1;x<=a[i];x++){
//         if(k>=x)ans+=rec(i+1,k-x);
//     }
//     return ans;
// }
void solve(){
    cin>>n>>k;
    a=vi(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(k+1));
    for(int i=n;i>=0;i--){
        for(int j=0;j<=k;j++){
            if(i==n){
                if(j==0)dp[i][j]=1;
                else dp[i][j]=0;
                continue;
            }
            // for(int x=0;x<=a[i];x++){
            //     if(j-x>=0){
            //         dp[i][j]+=dp[i+1][j-x];   
            //     }
            // }
            //This can be optimized
            int x=a[i];
            dp[i][j]=dp[i+1][j];
            if(j-x-1>=0)dp[i][j]-=dp[i+1][j-x-1];
            dp[i][j]=(dp[i][j]+mod)%mod;
        }
        for(int j=1;j<=k;j++){
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    int ans=dp[0][k];
    if(k-1>=0){
        ans=(ans-dp[0][k-1]+mod)%mod;
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
//We can further optimize SC 

// void solve(){
//     cin>>n>>k;
//     a=vi(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     vector<vector<int>>dp(2,vector<int>(k+1));
//     for(int i=n;i>=0;i--){
//         for(int j=0;j<=k;j++){
//             if(i==n){
//                 if(j==0)dp[i&1][j]=1;
//                 else dp[i&1][j]=0;
//                 continue;
//             }
//             int x=a[i];
//             dp[i&1][j]=dp[(i+1)&1][j];
//             if(j-x-1>=0)dp[i&1][j]-=dp[(i+1)&1][j-x-1];
//             dp[i&1][j]=(dp[i&1][j]+mod)%mod;
//         }
//         for(int j=1;j<=k;j++){
//             dp[i&1][j]+=dp[i&1][j-1];
//             dp[i&1][j]%=mod;
//         }
//     }
//     int ans=dp[0&1][k];
//     if(k-1>=0){
//         ans=(ans-dp[0&1][k-1]+mod)%mod;
//     }
//     cout<<ans<<"\n";
// }