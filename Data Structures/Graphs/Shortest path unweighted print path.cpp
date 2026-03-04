// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Print the shortest path from a given source node to a given destination node in an unweighted graph

vector<ll> shortestPathUnweighted(vector<vector<ll>> &adj, ll n, ll src, ll dest)
{
    vector<ll> dist(n + 1, -1);
    vector<ll> pred(n + 1, -1);
    queue<ll> qe;
    qe.push(src);
    dist[src] = 0;

    while (!qe.empty())
    {
        ll u = qe.front();
        qe.pop();
        for (auto &v : adj[u])
        {
            if (dist[v] == -1)
            {
                qe.push(v);
                dist[v] = dist[u] + 1;
                pred[v] = u;
                if (v == dest)
                    return pred;
            }
        }
    }

    return pred;
}

vector<ll> printShortestPathUnweighted(vector<ll> &pred, ll src, ll dest)
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

vector<ll> printShortestPathUnweighted(vector<vector<ll>> &adj, ll n, ll src, ll dest)
{
    vector<ll> pred = shortestPathUnweighted(adj, n, src, dest);
    return printShortestPathUnweighted(pred, src, dest);
}
