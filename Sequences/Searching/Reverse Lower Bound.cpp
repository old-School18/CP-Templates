// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify the first <= give element in a sorted sequence by discarding half of the search space in each step


// Recursive
ll lower_than_equal_to_recurse(ll a[], ll n, ll target, ll left, ll right)
{
    if (left > right)
    {
        return -1;
    }
    if (left == right)
    {
        if (left >= 0 && a[left] > target)
        {
            left--;
        }
        return left;
    }

    ll mid = left + (right - left + 1) / 2;

    if (a[mid] <= target)
    {
        return lower_than_equal_to_recurse(a, n, target, mid, right);
    }
    else
    {
        return lower_than_equal_to_recurse(a, n, target, left, mid - 1);
    }
}

ll lower_than_equal_to(ll a[], ll n, ll target)
{
    return lower_than_equal_to_recurse(a, n, target, 0, n - 1);
}

-------------------------------

// Iterative
ll lower_than_equal_to(ll a[], ll n, ll target)
{
    ll left = 0, right = n - 1;
    while (left < right)
    {
        ll mid = left + (right - left + 1) / 2;
        if (a[mid] <= target)
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (left >= 0 && a[left] > target)
    {
        left--;
    }
    return left;
}
