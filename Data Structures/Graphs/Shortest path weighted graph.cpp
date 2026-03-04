// Time Complexity: O((V+E)log V) Dijkstra | O(V+E) Toposort
// Memory Complexity: O(V)
// Shortest path weighted graph


// Dijkstra
vector<ll> shortestPathWeighted(vector<vector<pair<ll, ll>>> &adj, ll n, ll src)
{
    vector<ll> dist(n + 1, LLONG_MAX);
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
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

-------------------------------

// Topological Sort (only works for DAG in case of directed graphs)
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

vector<ll> shortestPathWeighted(vector<vector<pair<ll, ll>>> &adj, ll n, ll src)
{
    vector<ll> dist(n + 1, LLONG_MAX);
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
                }
            }
        }
    }
    
    return dist;
}
