// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Merge given intervals

// Interval Merging approach
vector<vector<ll>> mergeIntervals(vector<vector<ll>> &intervals)
{
    if (intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end());

    ll writer = 0;
    for (ll i = 1; i < intervals.size(); i++)
    {
        if (intervals[writer][1] >= intervals[i][0])
        {
            intervals[writer][1] = max(intervals[writer][1], intervals[i][1]);
        }
        else
        {
            writer++;
            intervals[writer] = intervals[i];
        }
    }

    intervals.resize(writer + 1);
    return intervals;
}

---------------------------------
Reference:
https://leetcode.com/problems/merge-intervals/
