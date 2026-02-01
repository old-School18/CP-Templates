// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Schedule maximum meetings possible when only one meeting is possible at a time

// Activity Selection approach – Maximum non-overlapping identification
class Comparator
{
  public:
    bool operator()(const pair<pair<ll, ll>, ll> &x, const pair<pair<ll, ll>, ll> &y)
    {
        return x.first.second < y.first.second;
    }
};

vector<ll> meetingScheduler(vector<ll> &start, vector<ll> &end)
{
    ll n = start.size();
    vector<ll> scheduledOrder;
    vector<pair<pair<ll, ll>, ll>> scheduler;

    for (ll i = 0; i < n; i++)
    {
        scheduler.push_back({{start[i], end[i]}, i});
    }

    sort(scheduler.begin(), scheduler.end(), Comparator());

    for (auto &p : scheduler)
    {
        if (scheduledOrder.empty() || end[scheduledOrder.back()] <= p.first.first)
        {
            scheduledOrder.push_back(p.second);
        }
    }

    return scheduledOrder;
}

---------------------------------
Reference:
https://takeuforward.org/data-structure/n-meetings-in-one-room
