// Time Complexity => O(log y)
// Memory Complexity => Recursive: O(log y) | Iterative: O(1)
// (x^y) % M

ll mod(ll a, ll M)
{
    return a%M;
}

// Recursive
ll mod_exponent(ll x, ll y, ll M)
{
    if (!y)
        return 1ll;
    else if (!(y % 2ll))
        return mod(mod_exponent(mod(x * x, M), y / 2ll, M), M);
    else
        return mod(x * mod_exponent(mod(x * x, M), y / 2ll, M), M);
}

------------------------
    
// Iterative
ll mod_exponent(ll x, ll y, ll M)
{
    ll result = 1ll;
    while (y)
    {
        if (y & 1ll)
            result = mod(result * x, M);
        x = mod(x * x, M);
        y >>= 1ll;
    }
    return result;
}
