// Time Complexity => O(n)
// Memory Complexity => O(256)
// Number of subarrays of a binary array whose sum is k

// Slow-fast pointer Instant
ll binarySubArraySum(ll a[], ll n, ll k)
{
    ll ans = 0, ck = 0, prefixTracker = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (a[fast])
            ck++;
        while (slow < fast && (!a[slow] || ck > k))
        {
            if (a[slow++])
                ck--, prefixTracker = 0;
            else
                prefixTracker++;
        }
        if (ck == k)
            ans += prefixTracker + 1;
    }
    return ans;
}
