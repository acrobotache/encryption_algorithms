#include<iostream>
#include<iomanip>
using namespace std;
typedef long long LL;

void Euclidian(LL  a, LL  b)
{
	LL  r1,r2,q,r;
	r1=a;
	r2=b;

	cout<<setw(5)<<"q"<<setw(5)<<"r1"<<setw(5)<<"r2"<<setw(5)<<"r"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	while(r2>0)
	{
		q=r1/r2;
		r=r1-q*r2;
		cout<<setw(5)<<q<<setw(5)<<r1<<setw(5)<<r2<<setw(5)<<r<<endl;
		r1=r2;
		r2=r;
	}
	cout<<setw(20)<<r1<<setw(5)<<r2<<endl<<endl;
	cout << "GCD of " << a << " and " << b << " is :" << r << endl;
}

void ExtendedEuclidian(LL  a,LL  b)
{
	LL  r1,r2,q,r,s,t;
	LL  s1=1,s2=0,t1=0,t2=1;
	r1=a;
	r2=b;
	cout<<setw(5)<<"q"<<setw(5)<<"r1"<<setw(5)<<"r2"<<setw(5)<<"r"<<setw(5)<<"s1"<<setw(5)<<"s2"<<setw(5)<<"s"<<setw(5)<<"t1"<<setw(5)<<"t2"<<setw(5)<<"t"<<setw(5)<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	while(r2>0)
	{
		q=r1/r2;
		r=r1-q*r2;
		s=s1-q*s2;
		t=t1-q*t2;
		cout<<setw(5)<<q<<setw(5)<<r1<<setw(5)<<r2<<setw(5)<<r<<setw(5)<<s1<<setw(5)<<s2<<setw(5)<<s<<setw(5)<<t1<<setw(5)<<t2<<setw(5)<<t<<endl;
		s1=s2;
		s2=s;

		t1=t2;
		t2=t;

		r1=r2;
		r2=r;

	}

	cout<<setw(20)<<r1<<setw(5)<<r2<<setw(20)<<s1<<setw(5)<<s2<<setw(20)<<t1<<setw(5)<<t2<<endl<<endl;
    cout << "GCD of " << a << " and " << b << " is :" << r1 << endl;
	cout << s << endl;
	cout << t << endl;
}
int main()
{
	LL  a,b,test_cases;
	while(1)
    {
        cout << "Enter value of a:";
        cin >> a;
        cout << "Enter value of b:";
        cin >> b;

        cout << "1)Euclidean GCD\n2)Extended Euclidean GCD\n3.Exit" << endl;

        int opt;
        cout << "Enter option:";
        cin >> opt;
        if(opt >= 3)
            break;
        switch(opt)
        {
            case 1:
                Euclidian(a,b);
                break;
            case 2:
                ExtendedEuclidian(a,b);
                break;
        }
    }
    return 0;
}

