// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify the first <= give element in a sorted sequence by discarding half of the search space in each step


// Recursive
ll lowerThanEqualToRecurse(ll a[], ll n, ll target, ll &result, ll left, ll right)
{
    if (left > right)
    {
        return result;
    }

    ll mid = left + (right - left) / 2;

    if (a[mid] <= target)
    {
        return lowerThanEqualToRecurse(a, n, target, mid, mid + 1, right);
    }
    else
    {
        return lowerThanEqualToRecurse(a, n, target, result, left, mid - 1);
    }
}

ll lowerThanEqualTo(ll a[], ll n, ll target)
{
    ll result = -1;
    return lowerThanEqualToRecurse(a, n, target, result, 0, n - 1);
}

-------------------------------

// Iterative
ll lowerThanEqualTo(ll a[], ll n, ll target)
{
    ll result = -1;
    ll left = 0, right = n - 1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] <= target)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}
