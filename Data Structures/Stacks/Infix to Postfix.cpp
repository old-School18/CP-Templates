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

string getNumber(string &expression, ll n, ll &k)
{
    string value = "";
    while (k < n && (isalpha(expression[k]) || isdigit(expression[k])))
    {
        value += expression[k++];
    }
    return value;
}
string evaluateLogic(stack<string> &operands, stack<char> &operators)
{
    string value2 = operands.top();
    operands.pop();
    string value1 = operands.top();
    operands.pop();
    char opr = operators.top();
    operators.pop();

    return value1 + " " + value2 + " " + opr;
}
string infixToPostfix(string &expression)
{
    ll n = expression.size();
    stack<string> operands;
    stack<char> operators;
    for (ll i = 0; i < n; i++)
    {
        if (isalpha(expression[i]) || isdigit(expression[i]))
        {
            string value = getNumber(expression, n, i);
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
                string value = evaluateLogic(operands, operators);
                operands.push(value);
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
                string value = evaluateLogic(operands, operators);
                operands.push(value);
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty())
    {
        string value = evaluateLogic(operands, operators);
        operands.push(value);
    }

    return operands.top();
}
