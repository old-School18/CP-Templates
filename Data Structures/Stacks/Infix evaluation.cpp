// Time Complexity => O(n)
// Memory Complexity => O(n)
// Evaluate infix mathematical expressions

ll getPrecedence(char opr)
{
    if (opr == '^')
    {
        return 3;
    }
    else if (opr == '/' || opr == '*' || opr == '%')
    {
        return 2;
    }
    else if (opr == '+' || opr == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool isRightAssociative(char opr)
{
    return opr == '^';
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
ld evaluateSubExpression(stack<ld> &operands, stack<char> &operators)
{
    ld value2 = operands.top();
    operands.pop();
    ld value1 = operands.top();
    operands.pop();
    char opr = operators.top();
    operators.pop();

    return applyOperation(value1, value2, opr);
}
ld evaluateInfix(string expression)
{
    ll n = expression.size();
    stack<ld> operands;
    stack<char> operators;

    for (ll i = 0; i < n; i++)
    {
        if (isdigit(expression[i]))
        {
            ld value = 1.0 * getNumber(expression, n, i);
            operands.push(value);
            i--;
        }
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                ld value = evaluateSubExpression(operands, operators);
                operands.push(value);
            }
            operators.pop();
        }
        else if(expression[i] != ' ')
        {
            while (!operators.empty() && operators.top() != '(' &&
                   ((getPrecedence(operators.top()) > getPrecedence(expression[i])) ||
                    (getPrecedence(operators.top()) == getPrecedence(expression[i]) &&
                     !isRightAssociative(expression[i]))))
            {
                ld value = evaluateSubExpression(operands, operators);
                operands.push(value);
            }

            operators.push(expression[i]);
        }
    }

    while (!operators.empty())
    {
        ld value = evaluateSubExpression(operands, operators);
        operands.push(value);
    }

    return operands.top();
}
