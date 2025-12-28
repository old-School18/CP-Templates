// Time Complexity: O(log min(n,m))
// Memory Complexity: Recursive: O(log min(n,m)) | Iterative: O(1)
// Identify the kth smallest element of two sorted arrays


// Recursive
ll kthOrderStatisticRecurse(ll a[], ll b[], ll n, ll m, ll k, ll left, ll right)
{
    if (left > right)
    {
        return -1;
    }

    ll partitionA = left + (right - left) / 2;
    ll partitionB = k - partitionA;

    ll maxLeftA = (!partitionA) ? LLONG_MIN : a[partitionA - 1];
    ll minRightA = (partitionA == n) ? LLONG_MAX : a[partitionA];
    ll maxLeftB = (!partitionB) ? LLONG_MIN : a[partitionB - 1];
    ll minRightB = (partitionB == m) ? LLONG_MAX : b[partitionB];

    if (maxLeftA <= minRightB && maxLeftB <= minRightA)
    {
        return max(maxLeftA, maxLeftB);
    }
    else if (maxLeftA > minRightB)
    {
        return kthOrderStatisticRecurse(a, b, n, m, k, left, partitionA - 1);
    }
    else
    {
        return kthOrderStatisticRecurse(a, b, n, m, k, partitionA + 1, right);
    }
}
ll kthOrderStatistic(ll a[], ll b[], ll n, ll m, ll k)
{
    if (n > m)
    {
        return kthOrderStatistic(b, a, m, n, k);
    }
    return kthOrderStatisticRecurse(a, b, n, m, k, max(0ll, k - m), min(k, n));
}

-------------------------------

// Iterative
ll kthOrderStatistic(ll a[], ll b[], ll n, ll m, ll k)
{
    if (n > m)
    {
        return kthOrderStatistic(b, a, m, n, k);
    }

    ll left = max(0ll, k - m), right = min(k, n);
    while (left <= right)
    {
        ll partitionA = left + (right - left) / 2;
        ll partitionB = k - partitionA;

        ll maxLeftA = (!partitionA) ? LLONG_MIN : a[partitionA - 1];
        ll minRightA = (partitionA == n) ? LLONG_MAX : a[partitionA];
        ll maxLeftB = (!partitionB) ? LLONG_MIN : b[partitionB - 1];
        ll minRightB = (partitionB == m) ? LLONG_MAX : b[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA)
        {
            return max(maxLeftA, maxLeftB);
        }
        else if (maxLeftA > minRightB)
        {
            right = partitionA - 1;
        }
        else
        {
            left = partitionA + 1;
        }
    }

    return -1;
}
