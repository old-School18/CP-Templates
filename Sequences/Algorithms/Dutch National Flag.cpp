// Time Complexity: O(n)
// Memory Complexity: O(1)
// Algos to sort binary (0,1) and ternary arrays (0,1,2) in a single traversal

void dutch_flag_2_way(ll a[], ll n)
{
    ll left = 0, right = n - 1;
    while (left < right)
    {
        if (!a[left])
        {
            left++;
        }
        else
        {
            swap(a[left], a[right--]);
        }
    }
    return;
}

void dutch_flag_3_way(ll a[], ll n)
{
    ll left = 0, mid = 0, right = n - 1;
    while (mid <= right)
    {
        if (!a[mid])
        {
            swap(a[left++], a[mid++]);
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[right--]);
        }
    }
}
