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

bool isRightAssociative(char opr)
{
    return opr == '^';
}

string infixToPrefix(string &expression)
{
    ll n = expression.size();
    string prefix = "";
    stack<char> operators;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (isalpha(expression[i]) || isdigit(expression[i]) || expression[i] == ' ')
        {
            prefix += expression[i];
        }
        else if (expression[i] == ')')
        {
            operators.push(expression[i]);
        }
        else if (expression[i] == '(')
        {
            while (!operators.empty() && operators.top() != ')')
            {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            while (
                !operators.empty() && operators.top() != ')' &&
                ((getPrecedence(operators.top()) > getPrecedence(expression[i])) ||
                 (getPrecedence(operators.top()) == getPrecedence(expression[i]) && isRightAssociative(expression[i]))))
            {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty())
    {
        prefix += operators.top();
        operators.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}
