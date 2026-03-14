// Time Complexity: O((V+E).logV)
// Memory Complexity: O(V+E)
// Minimum spanning tree

// MST weight
ll mstPrims(vector<vector<pair<ll, ll>>> &adj, ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<bool> vis(n + 1, 0);
    pq.push({0, 1});
    ll mstWeight = 0;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        mstWeight += d;

        for (auto &[v, dv] : adj[u])
        {
            if (!vis[v])
            {
                pq.push({dv, v});
            }
        }
    }

    return mstWeight;
}

// MST edges
vector<pair<ll, ll>> mstPrimsEdges(vector<vector<pair<ll, ll>>> &adj, ll n)
{
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<bool> vis(n + 1, 0);
    vector<pair<ll, ll>> mstEdges;
    pq.push({0, {1, -1}});

    while (!pq.empty())
    {
        auto [d, p] = pq.top();
        auto [u, parent] = p;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;
        if (parent != -1)
			mstEdges.push_back({parent, u});

        for (auto &[v, dv] : adj[u])
        {
            if (!vis[v])
            {
                pq.push({dv, {v, u}});
            }
        }
    }
    return mstEdges;
}
