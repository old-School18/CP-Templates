// Time Complexity => O(n)
// Memory Complexity => O(256)
// Minimum window substring of a string that has all characters of another string

// Slow-fast pointer Instant
ll minWindow(string s, string t)
{
    ll n = s.size();
    ll smap[256] = {0}, tmap[256] = {0};
    ll countS = 0, countT = 0;
    ll ans = n + 1;
    string window = "";

    for (auto &p : t)
    {
        tmap[p]++;
    }

    for (ll i = 0; i < 256; i++)
    {
        if (tmap[i])
            countT++;
    }

    for (ll slow = 0, fast = 0; fast < n; fast++)
    {
        smap[s[fast]]++;
        if (smap[s[fast]] == tmap[s[fast]])
            countS++;

        while (slow < fast && (!tmap[s[slow]] || smap[s[slow]] > tmap[s[slow]]))
        {
            smap[s[slow++]]--;
        }

        if (countS == countT && ans > fast - slow + 1)
        {
            ans = fast - slow + 1;
            window = s.substr(slow, fast - slow + 1);
        }
    }
    return window;
}


--------------------------
Reference:
https://leetcode.com/problems/minimum-window-substring/
