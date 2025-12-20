// Time Complexity: O(n)
// Memory Complexity: O(1)
// Largest sum subarray of size > 0


ll kadane(ll a[], ll n)
{
    ll max_now = 0, max_total = a[0];
    for (ll i = 0; i < n; i++)
    {
        max_now += a[i];
        max_total = max(max_total, max_now);
        max_now = max(0, max_now);
    }
    return max_total;
}
