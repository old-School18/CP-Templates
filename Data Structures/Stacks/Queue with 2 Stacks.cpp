// Time Complexity => Push Heavy — O(n) push | O(1) pop | O(1) pop | O(1) isEmpty
					            Pop Heavy  — O(1) push | O(n) pop | O(n) pop | O(1) isEmpty
// Memory Complexity => O(n)
// Implement queue using two stacks


// Push Heavy
class MyQueue
{
  public:
    stack<ll> stk, tempStk;
    MyQueue()
    {
    }

    void push(ll x)
    {
        while (!stk.empty())
        {
            tempStk.push(stk.top());
            stk.pop();
        }

        stk.push(x);
        while (!tempStk.empty())
        {
            stk.push(tempStk.top());
            tempStk.pop();
        }
        return;
    }

    ll pop()
    {
        ll topElement = stk.top();
        stk.pop();
        return topElement;
    }

    ll peek()
    {
        return stk.top();
    }

    bool empty()
    {
        return stk.empty();
    }
};

-------------------------

// Pop Heavy
class MyQueue {
public:
    stack<ll> stk, tempStk;
    MyQueue() {
        
    }
    
    void push(ll x) {
        stk.push(x);
        return;
    }
    
    ll pop() {
        while(!stk.empty()){
            tempStk.push(stk.top());
            stk.pop();
        }
        ll topElement=tempStk.top();
        tempStk.pop();
        while(!tempStk.empty()){
            stk.push(tempStk.top());
            tempStk.pop();
        }
        return topElement;
    }
    
    ll peek() {
        while(!stk.empty()){
            tempStk.push(stk.top());
            stk.pop();
        }
        ll topElement=tempStk.top();
        while(!tempStk.empty()){
            stk.push(tempStk.top());
            tempStk.pop();
        }
        return topElement;
    }
    
    bool empty() {
        return stk.empty();
    }
};
