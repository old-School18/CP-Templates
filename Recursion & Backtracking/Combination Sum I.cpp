// Time Complexity => O(2^(T/M)) where T - Target and M - Minimum candidate value 
// Memory Complexity => O(T/M)
// Given an array of DISTINCT integers, determine all the unique combinations of the integers that sum up to a given value. An integer can be used multiple times.

// Inclusion-Exclusion strategy
void combinationSumBacktrack(vector<ll> &candidates, ll target, vector<vector<ll>> &results, vector<ll> &temp, ll idx)
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

    temp.push_back(candidates[idx]);
    combinationSumBacktrack(candidates, target - candidates[idx], results, temp, idx);
    temp.pop_back();

    combinationSumBacktrack(candidates, target, results, temp, idx + 1);
    return;
}

vector<vector<ll>> combinationSum(vector<ll> &candidates, ll target)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    combinationSumBacktrack(candidates, target, results, temp, 0);
    return results;
}

----------------------------
Reference:
https://leetcode.com/problems/combination-sum/
