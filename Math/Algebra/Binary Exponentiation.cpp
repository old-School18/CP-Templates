// Time Complexity: O(log y)
// x^y

// Recursive
ll exponent(ll x, ll y)
{
    if (!y)
        return 1;
    else if (!(y % 2))
        return exponent(x * x, y / 2);
    else
        return (x * exponent(x * x, y / 2));
}

// Looping
ll exponent(ll x, ll y)
{
    ll result = 1;
    while (y)
    {
        if (y & 1)
            result *= x;
        x *= x;
        y >>= 1;
    }
    return result;
}
