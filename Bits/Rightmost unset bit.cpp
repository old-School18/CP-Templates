// Time Complexity => O(1)
// Memory Complexity => O(1)
// Find the rightmost unset bit

ll rightMostUnsetBit(ll n)
{
    return (~n) & (n + 1);
}
