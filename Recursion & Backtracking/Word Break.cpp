// Time Complexity => O(2ⁿ.n.m) where m – Dictionary size
// Memory Complexity => O(n²)
// Determine if a string can be broken into words present in a given dictionary


// Substring slicing strategy
bool words_in_dict_backtrack(string &candidate, vector<string> &dict, ll idx)
{
    if (idx == (ll) candidate.size())
    {
        return true;
    }
    for (ll i = idx; i < (ll) candidate.size(); i++)
    {
        if (find(dict.begin(), dict.end(), candidate.substr(idx, i - idx + 1)) != dict.end() &&
            words_in_dict_backtrack(candidate, dict, i + 1))
        {
            return true;
        }
    }

    return false;
}

bool words_in_dict(string &candidate, vector<string> &dict)
{
    return words_in_dict_backtrack(candidate, dict, 0, "");
}

---------------------------------
// Inclusion-Exclusion strategy
bool words_in_dict_backtrack(string &candidate, vector<string> &dict, ll idx, string temp)
{
    if (idx == (ll) candidate.size())
    {
        return temp.empty();
    }

    if (find(dict.begin(), dict.end(), temp + candidate[idx]) != dict.end() &&
        words_in_dict_backtrack(candidate, dict, idx + 1, ""))
    {
        return true;
    }
    return words_in_dict_backtrack(candidate, dict, idx + 1, temp + candidate[idx]);
}

bool words_in_dict(string &candidate, vector<string> &dict)
{
    return words_in_dict_backtrack(candidate, dict, 0, "");
}
