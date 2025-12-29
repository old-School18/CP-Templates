// Time Complexity => O(1)
// Memory Complexity => O(1)
// Check if ith bit is set in an integer

bool isSet(ll n, ll i)
{
    return (n & (1ll << i));
}
