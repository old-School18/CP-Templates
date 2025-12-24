// Time Complexity: O(log n)
// Memory Complexity: Recursive: O(log n)) | Iterative: O(1)
// Determines the largest element of a sorted rotated array. Binary searching a sorted rotated array always breaks the array into sorted and unsorted halves. The pivot exists on the unsorted half so eliminate the sorted half at each step


// Recursive
ll find_pivot_recurse(ll a[], ll n, ll left, ll right)
{
    if (left > right)
    {
        return n - 1;
    }

    ll mid = left + (right - left) / 2;
    if (mid == right || a[mid] > a[mid + 1])
    {
        return mid;
    }
    else if (a[left] == a[mid] && a[mid] == a[right])
    {
        return find_pivot_recurse(a, n, left + 1, right - 1);
    }
    else if (a[left] <= a[mid])   // left half is sorted half so pivot will be on right half
    {
        return find_pivot_recurse(a, n, mid + 1, right);
    }
    else  // right half is sorted half so pivot will be on left half
    {
        return find_pivot_recurse(a, n, left, mid - 1);
    }
}

ll find_pivot(ll a[], ll n)
{
    return find_pivot_recurse(a, n, 0, n - 1);
}

--------------------------------
    
// Iterative
ll find_pivot(ll a[], ll n)
{
    ll left = 0, right = n - 1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (mid == right || a[mid] > a[mid + 1])
        {
            return mid;
        }
        else if (a[left] == a[mid] && a[mid] == a[right])
        {
            left++, right--;
        }
        else if (a[left] <= a[mid])   // left half is sorted half so pivot will be on right half
        {
            left = mid + 1;
        }
        else  // right half is sorted half so pivot will be on left half
        {
            right = mid - 1;
        }
    }
}
