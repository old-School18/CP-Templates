// Time Complexity => O(1)
// Memory Complexity => O(1)
// Check if a number is a power of 2

bool isPowerOfTwo(ll n)
{
    return (!(n & (n - 1ll)));
}
