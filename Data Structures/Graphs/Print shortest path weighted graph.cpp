// Time Complexity: O((V+E)log V) Dijkstra | O(V+E) Toposort
// Memory Complexity: O(V)
// Shortest path weighted graph


// Dijkstra
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &adj, ll n, ll src)
{
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> pred(n + 1, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;
        for (auto &[v, weight] : adj[u])
        {
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pred[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return pred;
}

vector<ll> printShortestPathWeighted(vector<ll> &pred, ll src, ll dest)
{
    if (dest != src && pred[dest] == -1)
    {
        return {}; // unreachable
    }
    vector<ll> path;
    while (dest != -1)
    {
        path.push_back(dest);
        dest = pred[dest];
    }

    reverse(path.begin(), path.end());

    return path;
}

vector<ll> printShortestPathWeighted(vector<vector<pair<ll, ll>>> &adj, ll n, ll src, ll dest)
{
    vector<ll> pred = dijkstra(adj, n, src);
    return printShortestPathWeighted(pred, src, dest);
}

-------------------------------

// Topological Sort – only works for DAG
bool topoSortDfsUtil(vector<vector<pair<ll, ll>>> &adj, vector<ll> &state, vector<ll> &topoSortedNodes, ll u)
{
    state[u] = 1; // visiting

    for (auto &[v, weight] : adj[u])
    {
        if (!state[v] && topoSortDfsUtil(adj, state, topoSortedNodes, v))
        {
            return true; // cycle detected
        }
        else if (state[v] == 1)
        {
            return true; // cycle detected
        }
    }

    state[u] = 2; // visited
    topoSortedNodes.push_back(u);
    return false;
}

vector<ll> topoSort(vector<vector<pair<ll, ll>>> &adj, ll n)
{
    vector<ll> topoSortedNodes;
    vector<ll> state(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        if (!state[i] && topoSortDfsUtil(adj, state, topoSortedNodes, i))
        {
            return {}; // cycle detectd
        }
    }

    reverse(topoSortedNodes.begin(), topoSortedNodes.end());
    return topoSortedNodes;
}

vector<ll> topoSortShortestPath(vector<vector<pair<ll, ll>>> &adj, ll n, ll src)
{
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> pred(n + 1, -1);
    vector<ll> topoSorted = topoSort(adj, n);

    dist[src] = 0;
    for (auto &u : topoSorted)
    {
        if (dist[u] != LLONG_MAX)
        {
            for (auto &[v, weight] : adj[u])
            {
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pred[v] = u;
                }
            }
        }
    }

    return pred;
}

vector<ll> printShortestPathWeighted(vector<ll> &pred, ll src, ll dest)
{
    if (dest != src && pred[dest] == -1)
    {
        return {}; // unreachable
    }
    vector<ll> path;
    while (dest != -1)
    {
        path.push_back(dest);
        dest = pred[dest];
    }

    reverse(path.begin(), path.end());

    return path;
}

vector<ll> printShortestPathWeighted(vector<vector<pair<ll, ll>>> &adj, ll n, ll src, ll dest)
{
    vector<ll> pred = topoSortShortestPath(adj, n, src);
    return printShortestPathWeighted(pred, src, dest);
}
