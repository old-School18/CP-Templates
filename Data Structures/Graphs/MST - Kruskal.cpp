// Time Complexity: O(ElogE)
// Memory Complexity: O(V+E)
// Minimum spanning tree

// MST weight
class Dsu
{
  public:
    vector<ll> rank, parent;
    Dsu(ll n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (ll i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    ll findParent(ll x)
    {
        if (parent[x] != x)
            parent[x] = findParent(parent[x]);
        return parent[x];
    }

    void unionByRank(ll x, ll y)
    {
        ll xPar = findParent(x);
        ll yPar = findParent(y);
        if (xPar == yPar)
            return;
        if (rank[xPar] < rank[yPar])
        {
            parent[xPar] = yPar;
        }
        else if (rank[xPar] > rank[yPar])
        {
            parent[yPar] = xPar;
        }
        else
        {
            parent[yPar] = xPar;
            rank[xPar]++;
        }
    }
};

class EdgeComparator
{
  public:
    bool operator()(const vector<ll> &a, const vector<ll> &b)
    {
        return a[2] < b[2];
    }
};

ll mstKruskal(vector<vector<ll>> &edges, ll n)
{
    Dsu dsu(n);
    sort(edges.begin(), edges.end(), EdgeComparator());
    ll edgesUsed = 0;
    ll mstWeight = 0;
    for (auto &e : edges)
    {
        ll u = e[0], v = e[1], w = e[2];

        if (dsu.findParent(u) != dsu.findParent(v))
        {
            edgesUsed++;
            mstWeight += w;
            dsu.unionByRank(u, v);
        }
    }

    return (edgesUsed == n - 1 ? mstWeight : -1);
}

// MST edges
class Dsu
{
  public:
    vector<ll> rank, parent;
    Dsu(ll n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (ll i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    ll findParent(ll x)
    {
        if (parent[x] != x)
            parent[x] = findParent(parent[x]);
        return parent[x];
    }

    void unionByRank(ll x, ll y)
    {
        ll xPar = findParent(x);
        ll yPar = findParent(y);
        if (xPar == yPar)
            return;
        if (rank[xPar] < rank[yPar])
        {
            parent[xPar] = yPar;
        }
        else if (rank[xPar] > rank[yPar])
        {
            parent[yPar] = xPar;
        }
        else
        {
            parent[yPar] = xPar;
            rank[xPar]++;
        }
    }
};

class EdgeComparator
{
  public:
    bool operator()(const vector<ll> &a, const vector<ll> &b)
    {
        return a[2] < b[2];
    }
};

vector<pair<ll, ll>> mstKruskalEdges(vector<vector<ll>> &edges, ll n)
{
    Dsu dsu(n);
    sort(edges.begin(), edges.end(), EdgeComparator());
    ll edgesUsed = 0;
    vector<pair<ll, ll>> mstEdges;
    for (auto &e : edges)
    {
        ll u = e[0], v = e[1], w = e[2];

        if (dsu.findParent(u) != dsu.findParent(v))
        {
            edgesUsed++;
            mstEdges.push_back({u, v});
            dsu.unionByRank(u, v);
        }
    }

    return (edgesUsed == n - 1 ? mstEdges : {});
}
