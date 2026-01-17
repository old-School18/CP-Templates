// Time Complexity => O(nlogk)
// Memory Complexity => O(k)
// Top K largest elements in a Stream

class TopKLargest
{
  public:
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll k;

    TopKLargest(ll k)
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
        vector<ll> topK;
        while (!pq.empty())
        {
            topK.push_back(pq.top());
            pq.pop();
        }

        for (auto &p : topK)
        {
            pq.push(p);
        }

        return topK;
    }
};
