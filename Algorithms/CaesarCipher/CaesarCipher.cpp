#include<iostream>
#include<iomanip>
using namespace std;
int main()
{

while(1)
{
	cout<<" Select option:\n";
	cout<<"1>  Encrypt text \n";
	cout<<"2> Decrypt text \n";
	cout<<"2> Exit\n";
	cout<<"\nEnter Option : ";
	int opt;
	cin>>opt;
    if(opt >= 3)
        break;
	string plaintext;
	string ciphertext;
	int key;
	cout << "Enter key :" ;
	cin >> key;

	if(opt==1)
	{
		cout<<"\n\nEnter plaintext: ";

		cin>>plaintext;
		string ans="";
		for(int i=0;i<plaintext.length();i++)
		{
			char c=plaintext[i];
			ciphertext  += (c-97+key)%26+97;
		}
		cout<<"\nciphertext: "<<ciphertext << endl;
	}
	else if(opt==2)
	{
		cout<<"\n\nEnter ciphertext: ";
		cin>>ciphertext ;
		for(int i=0;i<ciphertext .length();i++)
		{
			char c=ciphertext[i];
			plaintext += (c-97-key)%26+97;
		}
		cout<<"\nPlain text : "<<plaintext << endl;
	}
}
}
