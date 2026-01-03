// Time Complexity => O(n)
// Memory Complexity => O(n)
// Convert prefix to postfix

string getNumber(string &expression, ll n, ll &k)
{
    string value = "";
    while (k < n && isdigit(expression[k]))
    {
        value += expression[k++];
    }
    return value;
}

string getNumberBackward(string &expression, ll &k)
{
    string value = "";
    while (k >= 0 && isdigit(expression[k]))
    {
        value += expression[k--];
    }

    reverse(value.begin(), value.end());
    return value;
}

string reverseMathExpression(string expression)
{
    string reversedExpression = "";
    ll n = expression.size();
    for (ll i = n - 1; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            string value = getNumberBackward(expression, i);
            reversedExpression += value;
            i++;
        }
        else if (isalpha(expression[i]))
        {
            reversedExpression += expression[i];
        }
        else if (expression[i] == '(')
        {
            reversedExpression += ')';
        }
        else if (expression[i] == ')')
        {
            reversedExpression += '(';
        }
        else
        {
            reversedExpression += expression[i];
        }
    }
    return reversedExpression;
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

string prefixToPostFix(string &expression)
{
    expression = reverseMathExpression(expression);
    string prefix = postfixToPrefix(expression);
    prefix = reverseMathExpression(prefix);
    return prefix;
}
