// Time Complexity => O(1)
// Memory Complexity => O(1)
// Swap two numbers

void swapNumbers(ll &n, ll &m)
{
    n = n ^ m;
    m = n ^ m;
    n = n ^ m;
    return;
}
