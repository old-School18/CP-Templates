// Sequence Breaking/Partitioning Strategy


// Word search problem
// Determine if a string can be broken into words present in a given dictionary
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

---------------------------------------

// Math expression problem
// Determine if +/-/* can be inserted at different places in a string so that it gets transformed to a math expression which upon evaluation equals given value
void backtrack(string &num, ll target, vector<string> &results, string current_expression, ll current_value,
               ll last_operand, ll idx)
{
    if (idx == (ll) num.size())
    {
        if (current_value == target)
        {
            results.push_back(current_expression);
        }
        return;
    }
    for (ll i = idx; i < (ll) num.size(); i++)
    {
        // to avoid numbers starting with 0 like: 012*3+5 etc.
        if (i > idx && num[idx] == '0')
            return;

        string expression = num.substr(idx, i - idx + 1);
        ll expression_value = stoll(expression);

        if (idx == 0)
        {
            backtrack(num, target, results, expression, expression_value, expression_value, i + 1);
            continue;
        }
        backtrack(num, target, results, current_expression + "+" + expression, current_value + expression_value,
                  expression_value, i + 1);
        backtrack(num, target, results, current_expression + "-" + expression, current_value - expression_value,
                  -expression_value, i + 1);
        backtrack(num, target, results, current_expression + "*" + expression,
                  current_value - last_operand + last_operand * expression_value, last_operand * expression_value,
                  i + 1);
    }
}

------------------------------------
References:
Word Search problem: https://leetcode.com/problems/word-search/
Math Expression problem: https://leetcode.com/problems/expression-add-operators/
