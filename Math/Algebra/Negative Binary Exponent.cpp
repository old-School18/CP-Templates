// Time Complexity => O(log y)
// Memory Complexity => Recursive: O(log y) | Iterative: O(1) 
// x^y

// Recursive
ld negative_exponent(ld x, ll y)
{
    if (!y)
        return 1.0;
    else if (y < 0)
        return negative_exponent(1.0 / x, -y);
    else if (!(y % 2ll))
        return negative_exponent(x * x, y / 2ll);
    else
        return (x * negative_exponent(x * x, y / 2ll));
}

------------------------------------

// Iterative
ld negative_exponent(ld x, ll y)
{
    ld result = 1.0;
    if (y < 0)
    {
        y = -y;
        x = 1.0 / x;
    }
    while (y)
    {
        if (y & 1ll)
            result *= x;
        x *= x;
        y >>= 1ll;
    }
    return result;
}
