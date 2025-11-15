// Time Complexity => O(log(min(a,b)))
// Memory Complexity => Recursive: O(log(min(a,b))) | Iterative: O(1)
// gcd(a,b)

ll mod(ll a, ll M)
{
    ll absoluteM = abs(M);
    return (a % absoluteM + absoluteM) % absoluteM;
}

// Recursive
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, mod(a, b));
}

-------------------------------------

// Iterative
ll gcd(ll a, ll b)
{
    while (b)
    {
        a = mod(a, b);
        swap(a, b);
    }
    return a;
}
