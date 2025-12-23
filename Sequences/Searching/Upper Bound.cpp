// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify the first > give element in a sorted sequence by discarding half of the search space in each step


// Recursive
ll greater_than_recurse(ll a[], ll n, ll target, ll &result, ll left, ll right)
{
    if (left > right)
    {
        return result;
    }

    ll mid = left + (right - left) / 2;

    if (a[mid] <= target)
    {
        return greater_than_recurse(a, n, target, result, mid + 1, right);
    }
    else
    {
        return greater_than_recurse(a, n, target, mid, left, mid - 1);
    }
}

ll greater_than(ll a[], ll n, ll target)
{
    ll result = n;
    return greater_than_recurse(a, n, target, result, 0, n - 1);
}

-------------------------------

// Iterative
ll greater_than(ll a[], ll n, ll target)
{
    ll result = n;
    ll left = 0, right = n - 1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            result = mid;
            right = mid - 1;
        }
    }

    return result;
}
