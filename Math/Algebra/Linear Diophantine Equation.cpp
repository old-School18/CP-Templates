// Time Complexity => O(log(min(a,b)))
// Memory Complexity => O(log(min(a,b)))
// Any one (x,y) that satisfy ax+by=c

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    ll g = extended_euclid(b, a % b, x, y);
    tie(x, y) = make_tuple(y, x - (a / b) * y);
    return g;
}

bool find_any_solution(ll a, ll b, ll c, ll &x, ll &y)
{
    if (a == 0 && b == 0 && c == 0)
    {
        return true; // infinite solutions
    }
    else if (a == 0 && b == 0)
    {
        return false;
    }
    ll g = extended_euclid(a, b, x, y);
    if (c % g)
    {
        return false;
    }
    x *= (c / g);
    y *= (c / g);

    return true;
}

-------------------------------------------------------------

Derivation:

ax+by=c

If a and b are not co-prime, we should be able to extract the gcd(a,b) from both the terms on the left side of the equation i.e.,

g*((a/g)x + (b/g)y) = c where g= gcd(a,b)

This implies that c must also be divisible by g for the equation to have a solution.

We know that Extended Euclid algorithm gives: ax+by=g

So,
ax1+by1=g

ax1.(c/g)+by1.(c/g) = c

which means, x=x1*(c/g) and y=y1*(c/g)

So just evaluate extended euclidean which gives x1 and y1 and multiply by (c/g) to get a solution for ax+by=c.
