// Time Complexity => O(2n)
// Memory Complexity => O(n2)
// Partition a string such that every substring is a palindrome

// Substring Slicing Strategy
bool isPalindrome(string &s)
{
    ll left = 0, right = s.size();
    right--;
    while (left < right)
    {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

void palindromePartitioningBacktrack(string s, vector<vector<string>> &results, vector<string> &temp, ll idx)
{
    if (idx == (ll) s.size())
    {
        results.push_back(temp);
        return;
    }
    for (ll i = idx; i < (ll) s.size(); i++)
    {
        string t = s.substr(idx, i - idx + 1);
        if (isPalindrome(t))
        {
            temp.push_back(t);
            palindromePartitioningBacktrack(s, results, temp, i + 1);
            temp.pop_back();
        }
    }

    return;
}
