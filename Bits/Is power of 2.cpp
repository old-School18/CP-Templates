// Time Complexity => O(1)
// Memory Complexity => O(1)
// Check if a number is a power of 2

bool isPowerOfTwo(ll x)
{
    return (!(x & (x - 1ll)));
}
