const int N = 5 * 1e4 + 10;
vector<ll> g[N];
vector<ll> rg[N];
vector<ll> cg[N];
void dfs(int v, vector<ll> &vis, vector<ll> &vec)
{
    vis[v] = 1;
    for (auto child : g[v])
    {
        if (!vis[child])
        {
            dfs(child, vis, vec);
        }
    }
    vec.pb(v);
}
void dfs2(ll v, ll cnt, vector<ll> &comp)
{
    comp[v] = cnt;
    for (auto child : rg[v])
    {
        if (comp[child] == -1)
            dfs2(child, cnt, comp);
    }
}
void dfs3(int v, vector<ll> &vis, vector<ll> &vec)
{
    vis[v] = 1;
    for (auto child : cg[v])
    {
        if (!vis[child])
        {
            dfs3(child, vis, vec);
        }
    }
    vec.pb(v);
}
void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<bitset<50005>> ors(n + 1);
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        rg[y].pb(x);
    }
    vector<ll> vec;
    vector<ll> vis(n + 1);
    vector<ll> comp(n + 1, -1);
    ll cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, vec);
        }
    }
    // condensing SCCs;
    for (int j = vec.size() - 1; j >= 0; j--)
    {
        if (comp[vec[j]] == -1)
        {
            dfs2(vec[j], cnt, comp);
            cnt++;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << comp[i] << " ";
    // }
    // condensed graph
    for (int i = 1; i <= n; i++)
    {
        for (auto child : g[i])
        {
            if (comp[i] != comp[child])
            {
                cg[comp[i]].pb(comp[child]);
            }
        }
    }

    vis = vector<ll>(n + 1, 0);
    vec.clear();
    // total cnt-1 SCCs possible
    for (int i = 1; i <= cnt - 1; i++)
    {
        if (!vis[i])
        {
            dfs3(i, vis, vec);
            for (auto v : vec)
            {
                ors[v][v] = 1;
                for (auto child : cg[v])
                {
                    ors[v] |= ors[child];
                }
            }
            vec.clear();
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if (ors[comp[a]][comp[b]])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}