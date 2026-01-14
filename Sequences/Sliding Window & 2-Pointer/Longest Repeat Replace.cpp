// Time Complexity => O(n)
// Memory Complexity => O(256)
// Longest subarray with repeating character after replacing at most k characters

// Slow-fast pointer Longest
ll longestRepeatReplace(string s, ll k)
{
    ll n = s.size();
    ll tracker[256] = {0};
    ll ans = 0, maxFreq = 0;
    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        tracker[s[fast]]++;
        maxFreq = max(maxFreq, tracker[s[fast]]);

        if (fast - slow + 1 - maxFreq > k)
        {
            tracker[s[slow++]]--;
        }
        ans = max(ans, fast - slow + 1);
    }
    return ans;
}

-----------------------
Reference:
https://leetcode.com/problems/longest-repeating-character-replacement/
