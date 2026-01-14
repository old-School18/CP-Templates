// Time Complexity => O(n)
// Memory Complexity => O(256)
// Longest subarray without repeating characters

// Slow-fast pointer Lazy
ll longestWithoutRepeats(string s)
{
    ll n = s.size();
    ll tracker[256];
    for (ll i = 0; i < 256; i++)
        tracker[i] = -1;
    ll ans = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        if (tracker[s[fast]] != -1)
        {
            slow = max(slow, tracker[s[fast]] + 1);
        }
        tracker[s[fast]] = fast;
        ans = max(ans, fast - slow + 1);
    }
    return ans;
}


--------------------------
Reference:
https://leetcode.com/problems/longest-substring-without-repeating-characters/
