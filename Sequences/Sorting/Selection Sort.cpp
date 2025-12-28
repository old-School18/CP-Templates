// Time Complexity: O(n2)
// Memory Complexity: O(1)
// Stable: No 
// Mechanism to sort sequences by SELECTING the appropriate element for the current iterating index


void selectionSort(ll a[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll minIdx = i;
        for (ll j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
    }
    return;
}
