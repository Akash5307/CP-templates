#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;

int n,m;
string s,t;
int dp[3001][3001];
int back[3001][3001];
int rec(int i,int j){
    if(i==n or j==m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        back[i][j]=0;
        return dp[i][j]=1+rec(i+1,j+1);
    }else{
        int op1=rec(i+1,j);
        int op2=rec(i,j+1);
        if(op1>=op2){
            back[i][j]=1;
            return dp[i][j]=op1;
        }else{
            back[i][j]=2;
            return dp[i][j]=op2;
        }
    }
}
void print(int i,int j){
    if(i==n or j==m)return ;
    int op=back[i][j];
    if(op==0){
        cout<<s[i];
        print(i+1,j+1);
    }else if(op==1){
        print(i+1,j);
    }else if(op==2){
        print(i,j+1);
    }
}
void solve(){
    cin>>s>>t;
    n=s.size();
    m=t.size();
    memset(dp,-1,sizeof(dp));
    int len=rec(0,0);
    if(len>0){
        print(0,0);
    }
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
