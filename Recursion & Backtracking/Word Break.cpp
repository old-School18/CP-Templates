// Time Complexity => O(2ⁿ · (n + m)) where m – Dictionary size
// Memory Complexity => O(n²)
// Determine if a string can be broken into words present in a given dictionary


// Sequence Breaking/ Partitioning strategy
bool words_in_dictionary(string candidate, vector<string> &dict, ll idx)
{
    if (idx == (ll) candidate.size())
    {
        return true;
    }
    for (ll i = idx; i < (ll) candidate.size(); i++)
    {
        if (find(dict.begin(), dict.end(), candidate.substr(idx, i - idx + 1)) != dict.end() &&
            words_in_dictionary(candidate, dict, i + 1))
        {
            return true;
        }
    }

    return false;
}
