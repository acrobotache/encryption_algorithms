#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//global parameters
LL public_Ya,P,alpha;

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
int inv(int mod,int num)
{
	int r1=mod,r2=num,r,t1=0,t2=1,t,q;
	while(r2 > 0)
	{
		q=r1/r2;

		r=r1-q*r2;
		r1=r2;
		r2=r;

		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	if(t1<0)
        t1+=mod;
	return t1;
}
pair<int,int> enCipher(LL M,LL private_Xa)
{
    LL k,c1,c2,K;
    cout << "Enter global parameters" << endl;
    cout << endl;
    cout << "Enter any prime number:";
    cin >> P;
    cout << "Enter a primitive root of P from..." << endl << endl;
    findPrimitiveRootsOf(P);
    cout << endl << ":";
    cin >> alpha;
    public_Ya=pow(alpha,private_Xa,P);
    cout << "Select any random value from 1 to P-1";
    cin >> k;
    cout << endl;
    K=pow(public_Ya,k,P);
    c1=pow(alpha,k,P);
    c2=(K*M)%P;
    return make_pair(c1,c2);
}
int deCipher(pair<int,int>p,LL private_Xa)
{
    LL K,M,Kinv;
    K=pow(p.first,private_Xa,P);
    Kinv = inv(P,K);
    M=(p.second*Kinv)%P;
    return M;
}
int main()
{
    LL private_Xa,M;
    cout << "Enter input value:";
    cin >> M;
    cout << "Enter private key from Alice :";
    cin >> private_Xa;
    pair<int,int>p=enCipher(M,private_Xa);
    cout << "Cipher values : ";
    cout << p.first << " "<< p.second << endl << endl;

    cout << "Original value:" << deCipher(p,private_Xa);
    return 0;
}
