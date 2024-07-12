struct Tree {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
void solve()
{
    int n,q;
    cin>>n>>q;
    Tree seg(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        seg.update(i,x);
    }
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            seg.update(b-1,c);
        }else if(a==2){
            cout<<seg.query(b-1,c)<<"\n";
        }
    }
}
