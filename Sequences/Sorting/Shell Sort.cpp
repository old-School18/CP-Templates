// Time Complexity: O(n2) Worst | O(nlog2n) Average | O(nlogn) Best 
// Memory Complexity: O(1)
// Stable: No
// Mechanism to sort sequences by performing sort in an exponentially decreasing SHELL gap size


void shellSort(ll a[], ll n)
{
    for (ll gap = n / 2; gap > 0; gap /= 2)
    {
        for (ll i = gap; i < n; i++)
        {
            ll curr = a[i];
            ll j = i - gap;
            while (j >= 0 && a[j] > curr)
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = curr;
        }
    }
    return;
}


---------------------------------------
Note: 
The time complexity is entirely dependent on the shell gap. 
The worst case time complexity is for the above documented original shell algorithm (n/2,n/4,n/8....1). 
There are better gap configurations that help us achieve better complexity but it’s out of scope.
