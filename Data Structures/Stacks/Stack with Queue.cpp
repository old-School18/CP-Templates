// Time Complexity => Push Heavy — O(n) push | O(1) pop | O(1) pop | O(1) isEmpty
					  Pop Heavy  — O(1) push | O(n) pop | O(n) pop | O(1) isEmpty
// Memory Complexity => O(1)
// Implement stack using two queues


// Push Heavy
class MyStack
{
  public:
    queue<ll> qe;

    void push(ll x)
    {
        qe.push(x);
        ll n = qe.size();
        ll y;
        while (--n)
        {
            y = qe.front();
            qe.pop();
            qe.push(y);
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
    queue<ll> qe;

    void push(ll x)
    {
        qe.push(x);
        return;
    }

    ll pop()
    {
        ll n = qe.size();
        ll topElement;
        while (--n)
        {
            topElement = qe.front();
            qe.pop();
            qe.push(topElement);
        }
        topElement = qe.front();
        qe.pop();
        return topElement;
    }

    ll top()
    {
        ll n = qe.size();
        ll topElement;
        while (--n)
        {
            topElement = qe.front();
            qe.pop();
            qe.push(topElement);
        }
        topElement = qe.front();
        qe.pop();
        qe.push(topElement);
        return topElement;
    }

    bool empty()
    {
        return qe.empty();
    }
};
