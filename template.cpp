#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
const int Mod = 1e9 + 7;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

//-----------------------------||||||||||||||||||||......................------
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key(). 
//The first returns an iterator to the k-th largest element (counting from zero), 
//the second — the number of items in a set that are strictly smaller than our item.
//------------------------||||||||||||||||||||||||||------------------------------

vector<int> factors(int x) {vector<int> d;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			if (x / i != i) {
				d.push_back(i);
				d.push_back(x / i);
			} else
			d.push_back(i);
		}
	}return d;
}

int binExpItr(ll a,ll b,ll M){ a %=M; int res =1; while (b){ if(b&1) res = (res *1ll *a)%M; a = (a* 1ll* a)%M;b >>=1;}  return res;}
ll ModInvr(ll x){return (binExpItr(x,Mod-2,Mod));}
vector<ll> fact; void factorial(int n){fact.resize(n+1); fact[0]=1; for(int i=1; i<=n ;i++) fact[i] = (fact[i-1]*i)%Mod;}
ll Ncr(ll n, ll r) {return fact[n] * ModInvr(fact[r] * fact[n - r] % Mod) % Mod;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, ModInvr(b), m) + m) % m;}
//-----------------------|||||||||||||||||||||||||-------------------------------
ll phi(ll n){
    ll ans=n;set<ll>st;
    while (n % 2 == 0)st.insert(2),n = n/2; 
    for (int i = 3; i*i <=n ; i = i + 2) 
        while (n % i == 0){ 
            st.insert(i);
            n = n/i; 
        } 
    if (n > 2) st.insert(n);
    for(auto x:st)
        ans=(x-1)*ans/x;
    return ans;
}

//Fenwick Tree
void update(int idx, int delta,vi &a){
    int n=a.size();
    for(int i = idx;i<n; i+=(i&(-i)))   
        a[i] += delta;
}
int query(int idx,vi &a){
    int cnt = 0;
    for(int i = idx; i > 0; i -=(i&(-i)))
        cnt += a[i];
    return cnt;
}
//----------------------|||||||||||||||||||||--------------------
//..............Matrix Exponentiation.. ...........
vector<vector<ll>>matMul(vector<vector<ll>>&a,vector<vector<ll>>&b){
    ll n=a.size(),m=b[0].size();
    vector<vector<ll>>c(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<a[0].size();k++){
                c[i][j]+=(a[i][k]*b[k][j])%Mod;
                c[i][j]%=Mod;
            }
        }
    }
    return c;
}
vector<vector<ll>>matPow(vector<vector<ll>>&a,ll n){
    vector<vector<ll>>result(a.size(),vector<ll>(a[0].size(),0));
    for(int i=0;i<a.size();i++){
        result[i][i]=1;
    }
    while(n){
        if(n&1){
            result=matMul(result,a);
        }
        a=matMul(a,a);
        n/=2;
    }
    return result;
}
//----------------------------MatExp ends here-------------------------
void solve(){
    
}
int main() {
    int T=1;
    // cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}