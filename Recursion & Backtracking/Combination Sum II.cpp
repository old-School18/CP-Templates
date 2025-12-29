// Time Complexity => O(2ⁿ.n) where T - Target and M - Minimum candidate value 
// Memory Complexity => O(n)
// Given an array of NON-DISTINCT integers, determine all the unique combinations of the integers that sum up to a given value. An integer can be used only once.

// Iterative strategy
void combination_sum2_backtrack(vector<ll> &candidates, ll target, vector<vector<ll>> &results, vector<ll> &temp, ll idx)
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

    for (ll i = idx; i < (ll) candidates.size(); i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;
        temp.push_back(candidates[i]);
        combination_sum2_backtrack(candidates, target - candidates[i], results, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<ll>> combination_sum2(vector<ll> &candidates, ll target)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    sort(candidates.begin(), candidates.end());
    combination_sum2_backtrack(candidates, target, results, temp, 0);
    return results;
}

------------------------------

// Inclusion-Exclusion strategy
void combination_sum2_backtrack(vector<ll> &candidates, ll target, vector<vector<ll>> &results, vector<ll> &temp,
                                bool previous_selected, ll idx)
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

    if (idx == 0 || candidates[idx] != candidates[idx - 1] || previous_selected)
    {
        temp.push_back(candidates[idx]);
        combination_sum2_backtrack(candidates, target - candidates[idx], results, temp, true, idx + 1);
        temp.pop_back();
    }
    combination_sum2_backtrack(candidates, target, results, temp, false, idx + 1);
    return;
}
vector<vector<ll>> combination_sum2(vector<ll> &candidates, ll target)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    sort(candidates.begin(), candidates.end());
    combination_sum2_backtrack(candidates, target, results, temp, false, 0);
    return results;
}

---------------------------
Reference:
https://leetcode.com/problems/combination-sum-ii/
