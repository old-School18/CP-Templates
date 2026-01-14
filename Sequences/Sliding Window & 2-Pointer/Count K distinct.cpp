// Time Complexity => O(n)
// Memory Complexity => O(n)
// Number of subarrays of a binary array whose sum is k

// Slow-fast pointer Instant
ll countKDistinct(ll a[], ll n, ll k)
{
    unordered_map<ll, ll> hash;
    ll ans = 0, distinct = 0, prefixTracker = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (!hash[a[fast]])
            distinct++;
        hash[a[fast]]++;

        while (slow < fast && (hash[a[slow]] > 1 || distinct > k))
        {
            if (hash[a[slow]] == 1)
                distinct--, prefixTracker = 0;
            else
                prefixTracker++;
            hash[a[slow++]]--;
        }
        if (distinct == k)
            ans += prefixTracker + 1;
    }
    return ans;
}

-----------------------
// Slow-fast pointer Atmost
ll twoPointerAtmost(ll a[], ll n, ll k)
{
    unordered_map<ll, ll> hash;
    ll ans = 0, distinct = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (!hash[a[fast]])
            distinct++;
        hash[a[fast]]++;

        while (distinct > k)
        {
            if (hash[a[slow]] == 1)
                distinct--;
            hash[a[slow++]]--;
        }
        ans += fast - slow + 1;
    }
    return ans;
}

ll countKDistinct(ll a[], ll n, ll k)
{
    if (!k)
        return twoPointerAtmost(a, n, k);
    return twoPointerAtmost(a, n, k) - twoPointerAtmost(a, n, k - 1);
}


--------------------------
Reference:
https://leetcode.com/problems/subarrays-with-k-different-integers/
