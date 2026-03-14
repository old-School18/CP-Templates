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
