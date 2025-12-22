// Time Complexity: O(n)
// Memory Complexity: O(1)
// Largest product subarray of size > 0


ll kadane_product(ll a[], ll n)
{
    ll max_now = 1, max_total = a[0];
    for (ll i = 0; i < n; i++)
    {
        max_now *= a[i];
        max_total = max(max_total, max_now);
        if (!max_now)
        {
            max_now = 1;
        }
    }

    max_now = 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        max_now *= a[i];
        max_total = max(max_total, max_now);
        if (!max_now)
        {
            max_now = 1;
        }
    }
    return max_total;
}
