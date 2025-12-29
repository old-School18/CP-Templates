// Time Complexity => O(log n)
// Memory Complexity => O(log n)
// Decimal number to Binary conversion

vector<ll> decimalToBinary(ll n)
{
    vector<ll> binary;

    while (n)
    {
        binary.push_back(n % 2);
        n /= 2;
    }

    reverse(binary.begin(), binary.end());
    return binary;
}
