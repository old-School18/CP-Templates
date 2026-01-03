// Time Complexity => O(n)
// Memory Complexity => O(n)
// Convert postfix to prefix

string getNumber(string &expression, ll n, ll &k)
{
    string value = "";
    while (k < n && isdigit(expression[k]))
    {
        value += expression[k++];
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

string postfixToPrefix(string &expression)
{
    ll n = expression.size();
    stack<string> operands;
    for (ll i = 0; i < n; i++)
    {
        if (isdigit(expression[i]))
        {
            string value = getNumber(expression, n, i);
            operands.push(value);
            i--;
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

    return operands.top();
}
