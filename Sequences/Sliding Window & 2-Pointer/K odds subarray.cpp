// Time Complexity => O(n)
// Memory Complexity => O(1)
// Number of subarrays with k odd numbers

// Slow-fast pointer Instant
ll kOddsSubarray(ll a[], ll n, ll k)
{
    ll ans = 0, ck = 0, prefixTracker = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (a[fast] % 2)
            ck++;
        while (slow < fast && (!(a[slow] % 2) || ck > k))
        {
            if (a[slow++] % 2)
                ck--, prefixTracker = 0;
            else
                prefixTracker++;
        }
        if (ck == k)
            ans += prefixTracker + 1;
    }
    return ans;
}

-----------------------
// Slow-fast pointer Atmost
ll twoPointerAtmost(ll a[], ll n, ll k)
{
    ll ans = 0, ck = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (a[fast] % 2)
            ck++;
        while (ck > k)
        {
            ck -= a[slow++] % 2;
        }
        ans += fast - slow + 1;
    }
    return ans;
}

ll kOddsSubarray(ll a[], ll n, ll k)
{
    if (!k)
        return twoPointerAtmost(a, n, k);
    return twoPointerAtmost(a, n, k) - twoPointerAtmost(a, n, k - 1);
}


--------------------------
Reference:
https://leetcode.com/problems/count-number-of-nice-subarrays/
