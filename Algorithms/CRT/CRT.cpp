#include<iostream>
#include<iomanip>

using namespace std;
// This function returns modular inverse of b with respect to n
//Using extended Euclidean Algorithm
int fun(int mod,int num)
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
int main()
{
	int k,product=1;
	cout<<"Enter value of k :";
	cin>>k;

	int num[k],rem[k],pp[k],inverse[k];
    cout << "Enter element in num[]:";
	for(int i=0;i<k;i++)
	{
		cin>>num[i];
		//Finds product
		product*=num[i];
	}
    cout << "Enter element in rem[]";
    for(int i=0;i<k;i++)
		cin>>rem[i];
	int sum=0;

	for(int i=0;i<k;i++)
	{
		pp[i]=product/num[i];//product of all the elements in the array but num[i]

		inverse[i]=fun(num[i],pp[i]);//Finding modular inverse of each pp[i] w.r.t num[i] such that pp[i]*inverse[i]%num[i] = 1

		sum+=(rem[i]*pp[i]*inverse[i]);//Formula
	}

	int ans=sum%product;

	cout<<" Minimum value of x="<<ans << endl;

	cout <<"Possible values are:";

	for(int i=0;i<10;i++)
        cout<<(ans=ans+product) << " ";
    cout << ".....";
}
