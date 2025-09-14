#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;
const int mod=1e9+7;

int n;
vi a,h;
// int rec(int i){
//     int ans=a[i];
//     for(int j=i+1;j<n;j++){
//         if(h[j]>h[i]){
//             ans=max(ans,a[i]+rec(j));
//         }
//     }
//     return ans;
// }

//::::::Optimization:::::
//h[i] are distinct in [1, N] → we can use them as indices
//for each i, we can find max dp(j) in range [i,j) 
//so we will try to find max in h[i]-1 so that h[j]<h[i] condition is satisfied
struct fenwick{
    int n;
    vi bit;
    fenwick(int n):n(n),bit(n+1,0){}
    void update(int ind,int x){
        for(;ind<=n;ind+=(ind&-ind)){
            bit[ind]=max(bit[ind],x);
        }
    }
    int query(int ind){
        int ans=0;
        for(;ind>0;ind-=(ind&-ind)){
            ans=max(ans,bit[ind]);
        }
        return ans;
    }
};
void solve(){
    cin>>n;
    a=vi(n);
    h=vi(n);
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    // for(int i=0;i<n;i++){
    //     ans=max(ans,rec(i));
    // }
    // cout<<ans;
    
    fenwick ft(n);
    for (int i=0;i<n;i++){
        int best=ft.query(h[i]-1);
        int cur=best+a[i];
        ft.update(h[i],cur);
        ans=max(ans,cur);
    }
    cout<<ans;
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

}
