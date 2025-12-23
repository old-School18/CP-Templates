// Time Complexity: O(log min(n,m))
// Memory Complexity: Recursive: O(log min(n,m)) | Iterative: O(1)
// Identify the kth smallest element of two sorted arrays


// Recursive
ll kth_order_statistic_recurse(ll a[], ll b[], ll n, ll m, ll k, ll left, ll right)
{
    if (left > right)
    {
        return -1;
    }

    ll partition_a = left + (right - left) / 2;
    ll partition_b = k - partition_a;

    ll max_left_a = (!partition_a) ? LLONG_MIN : a[partition_a - 1];
    ll min_right_a = (partition_a == n) ? LLONG_MAX : a[partition_a];
    ll max_left_b = (!partition_b) ? LLONG_MIN : a[partition_b - 1];
    ll min_right_b = (partition_b == m) ? LLONG_MAX : b[partition_b];

    if (max_left_a <= min_right_b && max_left_b <= min_right_a)
    {
        return max(max_left_a, max_left_b);
    }
    else if (max_left_a > min_right_b)
    {
        return kth_order_statistic_recurse(a, b, n, m, k, left, partition_a - 1);
    }
    else
    {
        return kth_order_statistic_recurse(a, b, n, m, k, partition_a + 1, right);
    }
}
ll kth_order_statistic(ll a[], ll b[], ll n, ll m, ll k)
{
    if (n > m)
    {
        return kth_order_statistic(b, a, m, n, k);
    }
    return kth_order_statistic_recurse(a, b, n, m, k, max(0ll, k - m), min(k, n));
}

-------------------------------

// Iterative
ll kth_order_statistic(ll a[], ll b[], ll n, ll m, ll k)
{
    if (n > m)
    {
        return kth_order_statistic(b, a, m, n, k);
    }

    ll left = max(0ll, k - m), right = min(k, n);
    while (left <= right)
    {
        ll partition_a = left + (right - left) / 2;
        ll partition_b = k - partition_a;

        ll max_left_a = (!partition_a) ? LLONG_MIN : a[partition_a - 1];
        ll min_right_a = (partition_a == n) ? LLONG_MAX : a[partition_a];
        ll max_left_b = (!partition_b) ? LLONG_MIN : b[partition_b - 1];
        ll min_right_b = (partition_b == m) ? LLONG_MAX : b[partition_b];

        if (max_left_a <= min_right_b && max_left_b <= min_right_a)
        {
            return max(max_left_a, max_left_b);
        }
        else if (max_left_a > min_right_b)
        {
            right = partition_a - 1;
        }
        else
        {
            left = partition_a + 1;
        }
    }

    return -1;
}
