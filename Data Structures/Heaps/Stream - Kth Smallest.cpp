// Time Complexity => O(nlogk)
// Memory Complexity => O(k)
// Kth Smallest Element in a stream

class KthSmallest
{
  public:
    priority_queue<ll> pq;
    ll k;

    KthSmallest(ll k)
    {
        this->k = k;
    }

    void add(ll val)
    {
        pq.push(val);
        if ((ll) pq.size() > k)
        {
            pq.pop();
        }
    }

    ll kthSmallest()
    {
        return pq.empty() ? -1 : pq.top();
    }
};
