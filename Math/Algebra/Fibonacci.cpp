// Time Complexity => O(log n)
// Memory Complexity => Recursive: O(log n) | Iterative: O(1)
// Fibonnaci numbers computation

struct matrix
{
    ll mat[2][2];

    matrix friend operator*(const matrix &a, const matrix &b)
    {
        matrix c;
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                c.mat[i][j] = 0;
                for (ll k = 0; k < 2; k++)
                {
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }
        }
        return c;
    }
};

// Recursive
matrix fibonacciRecurse(matrix ans, matrix base, ll n)
{
    if (n == 0)
    {
        return ans;
    }

    if (n & 1)
    {
        return fibonacciRecurse(ans * base, base * base, n / 2);
    }
    else
    {
        return fibonacciRecurse(ans, base * base, n / 2);
    }
}

ll fibonacci(ll n)
{
    matrix base{{{1, 1}, {1, 0}}};
    matrix ans{{{1, 0}, {0, 1}}};
    ans = fibonacciRecurse(ans, base, n);
    return ans.mat[0][1];
}

----------------------------

// Iterative
ll fibonacci(ll n)
{
    matrix base{{{1, 1}, {1, 0}}};

    matrix ans{{{1, 0}, {0, 1}}};

    while (n)
    {
        if (n & 1)
        {
            ans = ans * base;
        }
        base = base * base;
        n >>= 1;
    }
    return ans.mat[0][1];
}
