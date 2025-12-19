// Time Complexity: O(n^2) Worst | O(n^2) Average | O(n) Best
// Memory Complexity: O(1)
// Stable: Yes
// Mechanism to sort sequences by INSERTING the current iterating index into its appropriate position

void insertion_sort(ll a[],ll n) {
    for (ll i = 1; i < n; i++)
    {
        ll curr = a[i];
        ll j = i - 1;
        while (j >= 0 && a[j] > curr)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
    return;
}
