#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(a == 0)
        return b;
    return gcd(b%a,a);
}
int main()
{
// Two random prime numbers
    ll p = 3;
    ll q = 7;

    // First part of public key:
    ll n = p*q;

    // Finding other part of public key.
    // e stands for encrypt
    ll e = 2;
    ll phi = (p-1)*(q-1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }

    // Private key (d stands for decrypt)
    ll k = 2;  // A constant value
    ll d = (1 + (k*phi))/e;

    // Message to be encrypted
    ll msg = 12;
    printf("Message data = %ld",msg);

    // Encryption c = (msg ^ e) % n
    ll c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted data = %ld", c);

    // Decryption m = (c ^ d) % n
    ll m = pow(c, d);
    m = m%n;
    printf("\nOriginal Message Sent = %ld",m);
     return 0;
}
