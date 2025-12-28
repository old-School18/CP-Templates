// Time Complexity => O(log y)
// Memory Complexity => Recursive: O(log y) | Iterative: O(1) 
// x^y — works for all y

// Recursive
ld negativeExponent(ld x, ll y)
{
    if (!y)
        return 1.0;
    else if (y < 0)
        return negativeExponent(1.0 / x, -y);
    else if (!(y % 2ll))
        return negativeExponent(x * x, y / 2ll);
    else
        return (x * negativeExponent(x * x, y / 2ll));
}

------------------------------------

// Iterative
ld negativeExponent(ld x, ll y)
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
