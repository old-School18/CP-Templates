// Time Complexity => O(n.4^n) 
// Memory Complexity => O(n^2)
// Determine if +/-/* operations can be inserted at different places in a string so that it gets transformed into a math expression which upon evaluation equals given value

// Iterative strategy
void mathExpressionBacktrack(string &num, ll target, vector<string> &results, string current_expression, ll current_value,
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
            mathExpressionBacktrack(num, target, results, expression, expression_value, expression_value, i + 1);
            continue;
        }
        mathExpressionBacktrack(num, target, results, current_expression + "+" + expression, current_value + expression_value,
                  expression_value, i + 1);
        mathExpressionBacktrack(num, target, results, current_expression + "-" + expression, current_value - expression_value,
                  -expression_value, i + 1);
        mathExpressionBacktrack(num, target, results, current_expression + "*" + expression,
                  current_value - last_operand + last_operand * expression_value, last_operand * expression_value,
                  i + 1);
    }
}

vector<string> mathExpression(string num, int target)
{
    vector<string> results;
    mathExpressionBacktrack(num, target, results, "", 0, 0, 0);
    return results;
}
