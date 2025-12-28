// Time Complexity: O(n)
// Memory Complexity: O(1)
// Largest sum subarray of size > 0


ll kadane(ll a[], ll n)
{
    ll maxNow = 0, maxTotal = a[0];
    for (ll i = 0; i < n; i++)
    {
        maxNow += a[i];
        maxTotal = max(maxTotal, maxNow);
        maxNow = max(0, maxNow);
    }
    return maxTotal;
}
