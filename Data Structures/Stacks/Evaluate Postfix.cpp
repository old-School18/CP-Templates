// Time Complexity => O(n)
// Memory Complexity => O(n)
// Evaluate postfix mathematical expressions

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

ld evaluateSubExpression(stack<ld> &operands, char opr)
{
    ld value2 = operands.top();
    operands.pop();
    ld value1 = operands.top();
    operands.pop();

    return applyOperation(value1, value2, opr);
}

ld evaluatePostfix(string expression)
{
    ll n = expression.size();
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
            ld value = evaluateSubExpression(operands, expression[i]);
            operands.push(value);
        }
    }

    return operands.top();
}
