// Time Complexity => O(n)
// Memory Complexity => O(n)
// Convert prefix to infix

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
    return ")" + value1 + " " + opr + " " + value2 + "(";
}

string prefixToInfix(string &expression)
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

    string infix = operands.top();
    reverse(infix.begin(), infix.end());
    return infix;
}
