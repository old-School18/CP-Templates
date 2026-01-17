// Time Complexity => O(nlogk)
// Memory Complexity => O(k)
// Top K Smallest elements in a Stream

class TopKSmallest
{
  public:
    priority_queue<ll> pq;
    ll k;

    TopKSmallest(ll k)
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

    vector<ll> topK()
    {
        vector<ll> res;
        auto copy = pq;

        while (!copy.empty())
        {
            res.push_back(copy.top());
            copy.pop();
        }

        return res;
    }
};
