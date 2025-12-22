// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify a given element in a sorted sequence by discarding half of the search space at each step


// Recursive
ll bin_search_recurse(ll a[], ll target, ll left, ll right)
{
    if (left > right)
    {
        return -1;
    }

    ll mid = left + (right - left) / 2;

    if (a[mid] < target)
    {
        return bin_search_recurse(a, target, mid + 1, right);
    }
    else if (a[mid] == target)
    {
        return mid;
    }
    else
    {
        return bin_search_recurse(a, target, left, mid - 1);
    }
}

ll bin_search(ll a[], ll n, ll target)
{
    return bin_search_recurse(a, target, 0, n - 1);
}

-------------------------------

// Iterative
ll bin_search(ll a[], ll n, ll target)
{
    ll left = 0, right = n - 1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] < target)
        {
            left = mid + 1;
        }
        else if (a[mid] == target)
        {
            return mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
