#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL pow(LL A,LL B,LL MOD)
{
    LL ans=1;
    for(int i=1;i<=B;i++)
        ans=(ans%MOD*A%MOD)%MOD;
    return ans;
}
bool IsPrimitiveRoot(int p,int q)
{
    set<int>val;
    for(int i=1;i<q;i++)
    {
        val.insert(pow(p,i,q));
    }
    if(val.size() == q-1)
        return true;
    return false;
}
void findPrimitiveRootsOf(int p)
{
    int j=0;
    for(int i=1;i<p;i++)
    {
        if(IsPrimitiveRoot(i,p))
        {
            if(j && j%5==0)
                cout << endl;
            cout << i << " ";
            j++;
        }
    }
}
int main()
{
    LL P,alpha;

    LL private_Xa,public_Ya;
    LL private_Xb,public_Yb;

    LL AliceSecretKey,BobSecretKey;
    cout << "Enter global parameters" << endl;
    cout << endl;

    cout << "Enter any prime number:";
    cin >> P;
    cout << "Enter a primitive root of P from..." << endl;
    findPrimitiveRootsOf(P);
    cout << endl << ":";
    cin >> alpha;

    cout << "Enter private key from Alice :";
    cin >> private_Xa;
    public_Ya=pow(alpha,private_Xa,P);
    cout << "Alice's public key :"<<public_Ya<< endl;

    cout << "Enter private key from Bob :";
    cin >> private_Xb;
    public_Yb=pow(alpha,private_Xb,P);
    cout << "Bob's public key :"<<public_Yb<< endl;

    AliceSecretKey=pow(public_Yb,private_Xa,P);
    BobSecretKey=pow(public_Ya,private_Xb,P);

    if(AliceSecretKey == BobSecretKey)
        cout << "Correct value selection." << endl;
    else
        cout << "Wrong values provided." << endl;
    cout << "Secret key becomes :"<<AliceSecretKey << endl;
    return 0;
}
