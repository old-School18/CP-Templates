// Time Complexity => O(n)
// Memory Complexity => O(n)
// Convert infix to prefix

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

string infixToPostfixWithoutAssociativity(string &expression)
{
    ll n = expression.size();
    string postfix = "";
    stack<char> operators;
    for (ll i = 0; i < n; i++)
    {
        if (isalpha(expression[i]) || isdigit(expression[i]))
        {
            postfix += expression[i];
        }
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else if (expression[i] != ' ')
        {
            while (!operators.empty() && operators.top() != '(' &&
                   getPrecedence(operators.top()) > getPrecedence(expression[i]))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

string infixToPrefix(string &expression)
{
    expression = reverseMathExpression(expression);
    string prefix = infixToPostfixWithoutAssociativity(expression);
    cout << prefix << endl;
    prefix = reverseMathExpression(prefix);
    return prefix;
}
