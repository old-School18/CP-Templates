// Time Complexity: O(n)
// Memory Complexity: O(1)
// Largest product subarray of size > 0


ll kadaneProduct(ll a[], ll n)
{
    ll maxNow = 1, maxTotal = a[0];
    for (ll i = 0; i < n; i++)
    {
        maxNow *= a[i];
        maxTotal = max(maxTotal, maxNow);
        if (!maxNow)
        {
            maxNow = 1;
        }
    }

    maxNow = 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        maxNow *= a[i];
        maxTotal = max(maxTotal, maxNow);
        if (!maxNow)
        {
            maxNow = 1;
        }
    }
    return maxTotal;
}
