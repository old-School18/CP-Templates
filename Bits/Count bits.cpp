// Time Complexity => O(1)
// Memory Complexity => O(1)
// Brian Kernighan's algorithm
// Count set bits in a number

ll countBits(ll n)
{
    ll count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
