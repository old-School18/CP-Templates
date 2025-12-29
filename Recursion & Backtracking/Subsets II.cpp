// Time Complexity => O(n.2^n)
// Memory Complexity => O(n)
// Given an array of NON-DISTINCT integers, determine all subsets.

// Iterative strategy
void subsetsWithDuplicatesBacktrack(vector<ll> &nums, vector<vector<ll>> &results, vector<ll> &temp, ll idx)
{
    results.push_back(temp);

    for (ll i = idx; i < (ll) nums.size(); i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        subsetsWithDuplicatesBacktrack(nums, results, temp, i + 1);
        temp.pop_back();
    }
    return;
}

vector<vector<ll>> subsetsWithDuplicates(vector<ll> &nums)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    sort(nums.begin(), nums.end());
    subsetsWithDuplicatesBacktrack(nums, results, temp, 0);
    return results;
}

--------------------------

// Inclusion-Exclusion strategy
void subsetsWithDuplicatesBacktrack(vector<ll> &nums, vector<vector<ll>> &results, vector<ll> &temp,
                                    bool previousSelected, ll idx)
{
    if (idx == (ll) nums.size())
    {
        results.push_back(temp);
        return;
    }

    if (idx == 0 || nums[idx] != nums[idx - 1] || previousSelected)
    {
        temp.push_back(nums[idx]);
        subsetsWithDuplicatesBacktrack(nums, results, temp, true, idx + 1);
        temp.pop_back();
    }
    subsetsWithDuplicatesBacktrack(nums, results, temp, false, idx + 1);
    return;
}

vector<vector<ll>> subsetsWithDuplicates(vector<ll> &nums)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    sort(nums.begin(), nums.end());
    subsetsWithDuplicatesBacktrack(nums, results, temp, false, 0);
    return results;
}

-------------------------
Reference:
https://leetcode.com/problems/subsets-ii/
