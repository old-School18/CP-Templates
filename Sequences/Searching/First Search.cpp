// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify the first occurence of a given element in a sorted sequence by discarding half of the search space in each
// step

// Recursive
ll first_search_recurse(ll a[], ll target, ll &result, ll left, ll right)
{
    if (left > right)
    {
        return result;
    }

    ll mid = left + (right - left) / 2;

    if (a[mid] < target)
    {
        return first_search_recurse(a, target, result, mid + 1, right);
    }
    else if (a[mid] == target)
    {
        return first_search_recurse(a, target, mid, left, mid - 1);
    }
    else
    {
        return first_search_recurse(a, target, result, left, mid - 1);
    }
}

ll first_search(ll a[], ll n, ll target)
{
    ll result = -1;
    return first_search_recurse(a, target, result, 0, n - 1);
}

-----------------------------
    
// Iterative
ll first_search(ll a[], ll n, ll target)
{
    ll left = 0, right = n - 1;
    ll result = -1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] < target)
        {
            left = mid + 1;
        }
        else if (a[mid] == target)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}
