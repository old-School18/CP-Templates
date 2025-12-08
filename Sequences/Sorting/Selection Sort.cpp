// Time Complexity: O(n2)
// Memory Complexity: O(1)
// Stable: No 
// Mechanism to sort sequences by selecting the next smallest element from the unsorted window and swapping it with the current index element


void selection_sort(ll a[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll min_idx = i;
        for (ll j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
    return;
}
