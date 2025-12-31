// Time Complexity => Push Heavy — O(n) push | O(1) pop | O(1) pop | O(1) isEmpty
					  Pop Heavy  — O(1) push | O(n) pop | O(n) pop | O(1) isEmpty
// Memory Complexity => O(n)
// Implement stack using two queues


// Push Heavy
class MyStack
{
  public:
    queue<ll> qe, tempQe;
    MyStack()
    {
    }

    void push(ll x)
    {
        tempQe.push(x);
        while (!qe.empty())
        {
            tempQe.push(qe.front());
            qe.pop();
        }
        while (!tempQe.empty())
        {
            qe.push(tempQe.front());
            tempQe.pop();
        }
        return;
    }

    ll pop()
    {
        ll topElement = qe.front();
        qe.pop();
        return topElement;
    }

    ll top()
    {
        return qe.front();
    }

    bool empty()
    {
        return qe.empty();
    }
};

-------------------------

// Pop Heavy
class MyStack
{
  public:
    queue<ll> qe, tempQe;
    MyStack()
    {
    }

    void push(ll x)
    {
        qe.push(x);
    }

    ll pop()
    {
        ll topElement;
        while (!qe.empty())
        {
            topElement = qe.front();
            qe.pop();
            if (!qe.empty())
                tempQe.push(topElement);
        }
        while (!tempQe.empty())
        {
            qe.push(tempQe.front());
            tempQe.pop();
        }
        return topElement;
    }

    ll top()
    {
        ll topElement;
        while (!qe.empty())
        {
            topElement = qe.front();
            qe.pop();
            tempQe.push(topElement);
        }
        while (!tempQe.empty())
        {
            qe.push(tempQe.front());
            tempQe.pop();
        }
        return topElement;
    }

    bool empty()
    {
        return qe.empty();
    }
};
