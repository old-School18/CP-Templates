// Time Complexity => O(log(min(a,b)))
// Memory Complexity => Recursive: O(log(min(a,b,))) | Iterative: O(1)
// Faster than Euclidean as shift operations are cheaper than modulo
// gcd(a,b)

// Recursive
ll gcd_recursive(ll a, ll b)
{
    if (!a)
        return b;
    a >>= __builtin_ctz(a);
    if (a < b)
        swap(a, b);
    a -= b;
    return gcd_recursive(a, b);
}

ll gcd(ll a, ll b)
{
    if (!a || !b)
        return a | b;

    ll common_even_divisor = __builtin_ctz(a | b);
    b >>= __builtin_ctz(b);

    return gcd_recursive(a, b) << common_even_divisor;
}

------------------------------------
    
// Looping
ll gcd(ll a, ll b)
{
    if (!a || !b)
        return a | b;
    ll common_even_divisor = __builtin_ctz(a | b);
    b >>= __builtin_ctz(b);
    while (a)
    {
        a >>= __builtin_ctz(a);
        if (a < b)
            swap(a, b);
        a -= b;
    }
    return b << common_even_divisor;
}
