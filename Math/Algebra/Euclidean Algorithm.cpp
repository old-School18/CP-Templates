// Time Complexity => O(log(min(a,b)))
// Memory Complexity => Recursive: O(log(min(a,b))) | Iterative: O(1)
// gcd(a,b)

// Recursive
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

-------------------------------------

// Iterative
ll gcd(ll a, ll b)
{
    while (b)
    {
        a = a%b;
        swap(a, b);
    }
    return a;
}
