// Time Complexity => O(n)
// Memory Complexity => O(256)
// Longest subarray with atmost k distinct characters

// Slow-fast pointer Lazy
ll longestKDistinct(string s, ll k)
{
    ll n = s.size();
    ll tracker[256] = {0};
    ll ans = 0, ck = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        tracker[s[fast]]++;
        if (tracker[s[fast]] == 1)
            ck++;

        if (ck > k)
        {
            if (tracker[s[slow]] == 1)
                ck--;
            tracker[s[slow++]]--;
        }
        ans = max(ans, fast - slow + 1);
    }
    return ans;
}

-----------------------
// Slow-fast pointer Instant
ll longestKDistinct(string s, ll k)
{
    ll n = s.size();
    ll tracker[256] = {0};
    ll ans = 0, ck = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        tracker[s[fast]]++;
        if (tracker[s[fast]] == 1)
            ck++;

        while (ck > k)
        {
            if (tracker[s[slow]] == 1)
                ck--;
            tracker[s[slow++]]--;
        }
        ans = max(ans, fast - slow + 1);
    }
    return ans;
}


-----------------------
Reference:
https://takeuforward.org/data-structure/longest-substring-with-at-most-k-distinct-characters
