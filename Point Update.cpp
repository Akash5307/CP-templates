struct Tree {
    typedef long long T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }
    
    vector<T> s;
    int n;
 
    Tree(int n = 0, T def = unit) : s(4*n, def), n(n) {}
 
    void build(int si, int ss, int se, const vector<T>& a) {
        if (ss == se) {
            s[si] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(2*si, ss, mid, a);
        build(2*si+1, mid+1, se, a);
        s[si] = f(s[2*si], s[2*si+1]);
    }
 
    void update(int si, int ss, int se, int pos, T val) {
        if (ss == se) {
            s[si] = val;
            return;
        }
        int mid = (ss + se) / 2;
        if (pos <= mid)
            update(2*si, ss, mid, pos, val);
        else
            update(2*si+1, mid+1, se, pos, val);
        s[si] = f(s[2*si], s[2*si+1]);
    }
 
    T query(int si, int ss, int se, int qs, int qe) {
        if (ss > qe || se < qs) return unit;
        if (ss >= qs && se <= qe) return s[si];
        int mid = (ss + se) / 2;
        return f(query(2*si, ss, mid, qs, qe),
                 query(2*si+1, mid+1, se, qs, qe));
    }
 
    void updatePoint(int k, T val) {
        update(1, 0, n-1, k, val);
    }
 
    T queryRange(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};
