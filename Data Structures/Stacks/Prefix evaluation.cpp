// Time Complexity => O(n)
// Memory Complexity => O(n)
// Evaluate prefix mathematical expressions

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

ll getNumber(string &expression, ll n, ll &k)
{
    ll value = 0;
    while (k < n && isdigit(expression[k]))
    {
        value = value * 10 + (expression[k++] - '0');
    }
    return value;
}

ld applyOperation(ld x, ld y, char op)
{
    switch (op)
    {
        case '^':
            return pow(x, y);
        case '/':
            return x / y;
        case '*':
            return x * y;
        case '%':
            return fmod(x, y);
        case '+':
            return x + y;
        case '-':
            return x - y;
    }

    return 0.0;
}

ld evaluateLogic(stack<ld> &operands, char opr)
{
    ld value1 = operands.top();
    operands.pop();
    ld value2 = operands.top();
    operands.pop();

    return applyOperation(value1, value2, opr);
}

ld evaluatePrefix(string expression)
{
    ll n = expression.size();
    expression = reverseMathExpression(expression);
    stack<ld> operands;

    for (ll i = 0; i < n; i++)
    {
        if (isdigit(expression[i]))
        {
            ld value = 1.0 * getNumber(expression, n, i);
            operands.push(value);
            i--;
        }
        else if (expression[i] != ' ')
        {
            ld value = evaluateLogic(operands, expression[i]);
            operands.push(value);
        }
    }

    return operands.top();
}
