// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Identify a given element in a sorted sequence by discarding half of the search space at each step


// Recursive
ll binSearchRecurse(ll a[], ll target, ll left, ll right)
{
    if (left > right)
    {
        return -1;
    }

    ll mid = left + (right - left) / 2;

    if (a[mid] < target)
    {
        return binSearchRecurse(a, target, mid + 1, right);
    }
    else if (a[mid] == target)
    {
        return mid;
    }
    else
    {
        return binSearchRecurse(a, target, left, mid - 1);
    }
}

ll binSearch(ll a[], ll n, ll target)
{
    return binSearchRecurse(a, target, 0, n - 1);
}

-------------------------------

// Iterative
ll binSearch(ll a[], ll n, ll target)
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
