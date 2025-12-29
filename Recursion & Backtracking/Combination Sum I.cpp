// Time Complexity => O(2T/M) where T - Target and M - Minimum candidate value 
// Memory Complexity => O(T/M)
// Given an array of DISTINCT integers, determine all the unique combinations of the integers that sum up to a given value. An integer can be used multiple times.

// Inclusion-Exclusion strategy
void subset_sum_backtrack(vector<ll> &candidates, ll target, vector<vector<ll>> &results, vector<ll> &temp, ll idx)
{
    if (target < 0 || idx == (ll) candidates.size())
    {
        return;
    }
    else if (target == 0)
    {
        results.push_back(temp);
        return;
    }

    temp.push_back(candidates[idx]);
    subset_sum_backtrack(candidates, target - candidates[idx], results, temp, idx);
    temp.pop_back();

    subset_sum_backtrack(candidates, target, results, temp, idx + 1);
    return;
}

vector<vector<ll>> subset_sum(vector<ll> &candidates, ll target)
{
    vector<vector<ll>> results;
    vector<ll> temp;
    subset_sum_backtrack(candidates, target, results, temp, 0);
    return results;
}
