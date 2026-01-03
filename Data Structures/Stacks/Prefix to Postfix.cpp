// Time Complexity => O(n)
// Memory Complexity => O(n)
// Convert prefix to postfix

string getNumberBackward(string &expression, ll &k)
{
    string value = "";
    while (k >= 0 && isdigit(expression[k]))
    {
        value += expression[k--];
    }

    return value;
}

string deduceSubExpression(stack<string> &operands, char opr)
{
    string value2 = operands.top();
    operands.pop();
    string value1 = operands.top();
    operands.pop();
    return string(1, opr) + " " + value1 + " " + value2;
}

string prefixToPostFix(string &expression)
{
    ll n = expression.size();
    stack<string> operands;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            string value = getNumberBackward(expression, i);
            operands.push(value);
            i++;
        }
        else if (isalpha(expression[i]))
        {
            operands.push(string(1, expression[i]));
        }
        else if (expression[i] != ' ')
        {
            string value = deduceSubExpression(operands, expression[i]);
            operands.push(value);
        }
    }

    string prefix = operands.top();
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
