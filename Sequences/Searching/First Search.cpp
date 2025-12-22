// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify the first occurence of a given element in a sorted sequence by discarding half of the search space in each step


// Recursive
ll first_search_recurse(ll a[], ll target, ll left, ll right)
{
    if (left > right)
    {
        return -1;
    }
    if (left == right)
    {
        return ((a[left] == target) ? left : -1);
    }

    ll mid = left + (right - left) / 2;

    if (a[mid] < target)
    {
        return first_search_recurse(a, target, mid + 1, right);
    }
    else if (a[mid] == target)
    {
        return first_search_recurse(a, target, left, mid);
    }
    else
    {
        return first_search_recurse(a, target, left, mid - 1);
    }
}

ll first_search(ll a[], ll n, ll target)
{
    return first_search_recurse(a, target, 0, n - 1);
}

// Iterative
ll first_search(ll a[], ll n, ll target)
{
    ll left = 0, right = n - 1;
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] < target)
        {
            left = mid + 1;
        }
        else if (a[mid] == target)
        {
            right = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ((a[left] == target) ? left : -1);
}
