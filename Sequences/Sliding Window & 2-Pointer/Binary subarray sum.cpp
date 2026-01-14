// Time Complexity => O(n)
// Memory Complexity => O(1)
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

--------------------------
// Slow-fast pointer Atmost
ll twoPointerAtmost(ll a[], ll n, ll k)
{
    ll ans = 0, ck = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (a[fast])
            ck++;
        while (ck > k)
        {
            ck -= a[slow++];
        }
        ans += fast - slow + 1;
    }
    return ans;
}

ll binarySubArraySum(ll a[], ll n, ll k)
{
    if (!k)
        return twoPointerAtmost(a, n, k);
    return twoPointerAtmost(a, n, k) - twoPointerAtmost(a, n, k - 1);
}



--------------------------
Reference:
https://leetcode.com/problems/binary-subarrays-with-sum/
