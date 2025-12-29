// Time Complexity => O(2^n.n)
// Memory Complexity => O(n)
// Given an array of NON-DISTINCT integers, determine all the unique combinations of the integers that sum up to a given value. An integer can be used only once.

// Iterative strategy
void combinationSum2Backtrack(vector<ll> &candidates, ll target, vector<vector<ll>> &results, vector<ll> &temp, ll idx)
{
    if (target == 0)
    {
        results.push_back(temp);
        return;
    }
    else if (target < 0)
    {
        return;
    }

    for (ll i = idx; i < (ll) candidates.size(); i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;
        temp.push_back(candidates[i]);
        combinationSum2Backtrack(candidates, target - candidates[i], results, temp, i + 1);
        temp.pop_back();
    }

     return;
}

vector<vector<ll>> combinationSum2(vector<ll> &candidates, ll target)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    sort(candidates.begin(), candidates.end());
    combinationSum2Backtrack(candidates, target, results, temp, 0);
    return results;
}

------------------------------

// Inclusion-Exclusion strategy
void combinationSum2Backtrack(vector<ll> &candidates, ll target, vector<vector<ll>> &results, vector<ll> &temp,
                                bool previousSelected, ll idx)
{
    if (target == 0)
    {
        results.push_back(temp);
        return;
    }
    else if (target < 0 || idx == (ll) candidates.size())
    {
        return;
    }

    if (idx == 0 || candidates[idx] != candidates[idx - 1] || previousSelected)
    {
        temp.push_back(candidates[idx]);
        combinationSum2Backtrack(candidates, target - candidates[idx], results, temp, true, idx + 1);
        temp.pop_back();
    }
    combinationSum2Backtrack(candidates, target, results, temp, false, idx + 1);
    return;
}
vector<vector<ll>> combinationSum2(vector<ll> &candidates, ll target)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    sort(candidates.begin(), candidates.end());
    combinationSum2Backtrack(candidates, target, results, temp, false, 0);
    return results;
}

---------------------------
Reference:
https://leetcode.com/problems/combination-sum-ii/
