// Time Complexity => O(1)
// Memory Complexity => O(1)
// Clear ith bit

ll clearBit(ll n, ll i)
{
    return (n & ~(1ll << i));
}
