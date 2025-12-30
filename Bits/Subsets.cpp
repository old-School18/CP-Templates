// Time Complexity => O(2^n.n)
// Memory Complexity => O(2^n.n)
// Subsets of an array


vector<vector<ll>> subsets(vector<ll> &a)
{
    vector<vector<ll>> subsets;
    ll n = a.size();
    for (ll i = 0; i < (1ll << n); i++)
    {
        vector<ll> subset;
        for (int j = 0; j < n; j++)
        {
            if (i & (1ll << j))
            {
                subset.push_back(a[j]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}
