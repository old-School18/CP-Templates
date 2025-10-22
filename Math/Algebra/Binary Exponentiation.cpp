// Time Complexity: O(log y)
// x^y

// Recursive
ll exponent(ll x, ll y)
{
    if (!y)
        return 1ll;
    else if (!(y % 2ll))
        return exponent(x * x, y / 2ll);
    else
        return (x * exponent(x * x, y / 2ll));
}

// Looping
ll exponent(ll x, ll y)
{
    ll result = 1ll;
    while (y)
    {
        if (y & 1ll)
            result *= x;
        x *= x;
        y >>= 1ll;
    }
    return result;
}
