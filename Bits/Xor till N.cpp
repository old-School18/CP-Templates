// Time Complexity => O(1)
// Memory Complexity => O(1)
// XOR of 1 to N


ll xorTillN(ll n)
{
    switch (n % 4)
    {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        case 3:
            return 0;
    }
}
