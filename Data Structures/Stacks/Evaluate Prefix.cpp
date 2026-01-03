// Time Complexity => O(n)
// Memory Complexity => O(n)
// Evaluate prefix mathematical expressions

ll getNumberBackward(string &expression, ll &k)
{
    string value = "";
    while (k >= 0 && isdigit(expression[k]))
    {
        value += expression[k--];
    }

    reverse(value.begin(), value.end());
    return stoll(value);
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

ld evaluateSubExpression(stack<ld> &operands, char opr)
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
    stack<ld> operands;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            ld value = 1.0 * getNumberBackward(expression, i);
            operands.push(value);
            i++;
        }
        else if (expression[i] != ' ')
        {
            ld value = evaluateSubExpression(operands, expression[i]);
            operands.push(value);
        }
    }

    return operands.top();
}
