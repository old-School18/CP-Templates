// Time Complexity: O(log y)
// (x^y) % M

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

// Looping
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
