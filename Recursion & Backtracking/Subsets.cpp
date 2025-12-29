// Time Complexity => O(n.2^n) where T - Target and M - Minimum candidate value 
// Memory Complexity => O(n)
// Given an array of DISTINCT integers, determine all subsets.


// Inclusion-Exclusion strategy
void subsetsBacktrack(vector<ll> &nums, vector<vector<ll>> &results, vector<ll> &temp, ll idx)
{
    if (idx == (ll) nums.size())
    {
        results.push_back(temp);
        return;
    }

    temp.push_back(nums[idx]);
    subsetsBacktrack(nums, results, temp, idx + 1);
    temp.pop_back();
    subsetsBacktrack(nums, results, temp, idx + 1);
}

vector<vector<ll>> subsets(vector<ll> &nums)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    subsetsBacktrack(nums, results, temp, 0);
    return results;
}

--------------------------

// Iterative strategy
void subsetsBacktrack(vector<ll> &nums, vector<vector<ll>> &results, vector<ll> &temp, ll idx)
{
    results.push_back(temp);

    for (ll i = idx; i < (ll) nums.size(); i++)
    {
        temp.push_back(nums[i]);
        subsetsGeneratorBacktrack(nums, results, temp, i + 1);
        temp.pop_back();
    }
    return;
}

vector<vector<ll>> subsets(vector<ll> &nums)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    subsetsBacktrack(nums, results, temp, 0);
    return results;
}

--------------------------
Reference:
https://leetcode.com/problems/subsets/
