// Time Complexity => O(n)
// Memory Complexity => O(1)
// Maximum consecutive ones in a binary array after flipping at most k 0's

// Slow-fast pointer Longest
ll maxConsecutiveOnes(ll a[], ll n, ll k)
{
    ll ans = 0, ck = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (!a[fast])
            ck++;

        if (ck > k)
        {
            if (!a[slow++])
                ck--;
        }

        ans = max(ans, fast - slow + 1);
    }
    return ans;
}
