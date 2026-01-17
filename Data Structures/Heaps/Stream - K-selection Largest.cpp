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
