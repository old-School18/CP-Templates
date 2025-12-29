// Time Complexity => O(1)
// Memory Complexity => O(1)
// Find the rightmost set bit

// Approach #1
ll rightMostSetBit(ll n)
{
    return n ^ (n & (n - 1));
}

------------------

// Approach #2
ll rightMostSetBit(ll n)
{
    return n & (-n);
}
