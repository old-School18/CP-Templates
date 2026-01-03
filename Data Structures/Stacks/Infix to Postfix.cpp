// Time Complexity => O(n)
// Memory Complexity => O(n)
// Convert infix to postfix

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

string infixToPostfix(string &expression)
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
                   ((getPrecedence(operators.top()) > getPrecedence(expression[i])) ||
                    (getPrecedence(operators.top()) == getPrecedence(expression[i]) &&
                     !isRightAssociative(operators.top()))))
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
