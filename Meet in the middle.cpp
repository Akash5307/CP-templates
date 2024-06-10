//In how many ways can you choose a subset of the numbers with sum x?
void gen(ll start,ll curr,vector<ll>&a,unordered_map<ll,ll>&mp){
    mp[curr]++;
    if(start==a.size())return;
    for(int i=start;i<a.size();i++){
        gen(i+1,curr+a[i],a,mp);
    }
}
void solve(){
    ll n,goal;
    cin>>n>>goal;
    vector<ll>a1,a2;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        if(i<=n/2){
            a1.pb(x);
        }else{
            a2.pb(x);
        }
    }
    unordered_map<ll,ll>mp1,mp2;
    gen(0,0,a1,mp1);
    gen(0,0,a2,mp2);
    ll ans=0;
    for(auto [x,y]:mp1){
        ans+=mp2[goal-x]*y;
    }
    cout<<ans;
}