// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Median of a stream of elements

class StreamMedian
{
  public:
    priority_queue<ll> left; // max-heap (lower half)
    priority_queue<ll, vector<ll>, greater<ll>> right; // min-heap (upper half)

    void add(ll num)
    {
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        // rebalance
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
    }

    ld getMedian()
    {
        if (left.size() == right.size())
            return (ld)(left.top() + right.top()) / 2.0;

        return (left.size() > right.size()) ? left.top() : right.top();
    }
};
