// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify the first >= give element in a sorted sequence by discarding half of the search space in each step


// Recursive
ll greater_than_equal_to_recurse(ll a[], ll n, ll target, ll left, ll right)
{
    if (left > right)
    {
        return -1;
    }
    if (left == right)
    {
        if (left < n && a[left] < target)
        {
            left++;
        }
        return left;
    }

    ll mid = left + (right - left) / 2;

    if (a[mid] < target)
    {
        return greater_than_equal_to_recurse(a, n, target, mid + 1, right);
    }
    else
    {
        return greater_than_equal_to_recurse(a, n, target, left, mid);
    }
}

ll greater_than_equal_to(ll a[], ll n, ll target)
{
    return greater_than_equal_to_recurse(a, n, target, 0, n - 1);
}

-------------------------------

// Iterative
ll greater_than_equal_to(ll a[], ll n, ll target)
{
    ll left = 0, right = n - 1;
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    if (left < n && a[left] < target)
    {
        left++;
    }
    return left;
}
