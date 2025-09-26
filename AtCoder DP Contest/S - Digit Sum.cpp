#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD=1e9+7;

int len;
string L,R;
int D;
int dp[10010][2][2][100];
int rec(int i,int tlo,int thi,int sum){
    if(i==len){
        if(sum==0)return 1;
        return 0;
    }
    if(dp[i][tlo][thi][sum]!=-1)return dp[i][tlo][thi][sum];
    int lo=0;//lower limit of lo
    if(tlo==1){
        lo=L[i]-'0';
    }
    int hi=9;
    if(thi==1){
        hi=R[i]-'0';
    }
    int ans=0;
    for(int curr_digit=lo;curr_digit<=hi;curr_digit++){
        int ntlo=tlo;
        if(curr_digit!=L[i]-'0')ntlo=0;
        int nthi=thi;
        if(curr_digit!=R[i]-'0')nthi=0;
        ans+=rec(i+1,ntlo,nthi,(sum+curr_digit)%D);
        ans%=MOD;
    }
    return dp[i][tlo][thi][sum]=ans;
    
}
void solve(){
    L="";
    L+='1';
    cin>>R;
    cin>>D;
    int diff=R.length()-L.length();
    string tmp="";
    while(diff--){
        tmp+='0';
    }
    L=tmp+L;
    len=R.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0);
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
