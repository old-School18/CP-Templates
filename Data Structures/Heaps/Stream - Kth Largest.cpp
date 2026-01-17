// Time Complexity => O(nlogk)
// Memory Complexity => O(k)
// Kth Largest Element in a stream

class KthLargest
{
  public:
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll k;

    KthLargest(ll k)
    {
        this->k = k;
    }

    void add(ll val)
    {
        pq.push(val);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    ll kthLargest()
    {
        return pq.empty() ? -1 : pq.top();
    }
};
