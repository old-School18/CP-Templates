// Time Complexity: O(V^3)
// Memory Complexity: O(1)
// All pairs shortest paths. Works with negative edges. Detects negative cycles

bool floydWarshall(vector<vector<ll>> &adjMatrix, ll n)
{
    for (ll k = 1; k <= n; k++)
    {
        for (ll u = 1; u <= n; u++)
        {
            for (ll v = 1; v <= n; v++)
            {
                if (adjMatrix[u][k] == -1 || adjMatrix[k][v] == -1)
                {
                    continue;
                }
                if (adjMatrix[u][v] == -1)
                {
                    adjMatrix[u][v] = adjMatrix[u][k] + adjMatrix[k][v];
                }
                else
                {
                    adjMatrix[u][v] = min(adjMatrix[u][v], adjMatrix[u][k] + adjMatrix[k][v]);
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        if (adjMatrix[i][i] < 0)
        {
            return false; // negative cycle
        }
    }

    return true;
}
