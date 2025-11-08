// Time Complexity: O(log(min(a,b)))
// gcd(a,b)

ll mod(ll a, ll M)
{
    ll absoluteM = abs(M);
    return (a % absoluteM + absoluteM) % absoluteM;
}

// Recursive
ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll g = extended_euclid(b, mod(a, b), x, y);
    tie(x, y) = make_tuple(y, x - (a / b) * y);
    return g;
}

// Looping
ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    ll ca1 = 1, ca2 = 0;
    ll cb1 = 0, cb2 = 1;
    while (b)
    {
        ll q = a / b;

        tie(ca1, cb1) = make_tuple(cb1, ca1 - q * cb1);
        tie(ca2, cb2) = make_tuple(cb2, ca2 - q * cb2);
        tie(a, b) = make_tuple(b, a - q * b);
    }

    x = ca1, y = ca2;
    return a;
}

-------------------------------------------------------------------------


Derivation for Looping Algorithm:

We have: ax+by=g

As a & b keep decomposing with each progressive step in Euclidean algorithm, let's consider a1 and b1 as the values of  a and b in one of the intermediary steps in the algorithm. We can express a1 & b1 as:

a1 = a.ca1 + b.ca2
b1 = a.cb1 + b.cb2

where ca1 & ca2 are coefficients of a and cb1 & cb2 are coefficients of b

Let's denote the next step value with ' symbol. That is, a will be come a' and b will become b' in one step of euclidean algorithm. Now, we know:
a' = b
b' = a - (a/b)*b 

So,
a.ca1' + b.ca2' = a1' = b1


But, b1 = a.cb1+b.cb2 
=> a.ca1' + b.ca2' = a.cb1 + b.cb2 

Which means, 
ca1' = cb1  -> (1)
and 
ca2' = cb2  -> (2)



And,
a.cb1' + b.cb2' = b1'
=> a.cb1' + b.cb2' = a1 - (a1/b1)*b1 
=> a.cb1' + b.cb2' = a.ca1 + b.ca2 - (a1/b1)*(a.cb1 + b.cb2)
=> a.cb1' + b.cb2' = (ca1 - (a1/b1)*cb1)*a + (ca2 - (a1/b1)*cb2)*b
=> 
cb1' = ca1 - (a1/b1)*cb1 -> (3)
and 
cb2' = ca2 - (a1/b1)*cb2 -> (4)


So, we have:
ca1' = cb1
ca2' = cb2
cb1' = ca1 - (a1/b1)*cb1
cb2' = ca2 - (a1/b1)*cb2

And, 
a1 = a.ca1 + b.ca2
b1 = a.cb1 + b.cb2

In the start, 
a1=a which means ca1=1 & ca2=0
b1=b which means cb1=0 & cb2=1

So we can start with these values of coefficients of a and b and perform the Euclidean algorithm step by step. As we know that the algorithm stops when b1=0 which means the value of a1 will be the gcd(a,b). This means that, ca1 will be x and ca2 will be y because:
a1 = a.ca1 + b.ca2 
gcd(a,b) = a.x + b.y

Therefore, the final values of ca1 & ca2 are x & y respectively
