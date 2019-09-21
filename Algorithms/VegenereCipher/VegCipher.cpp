#include<bits/stdc++.h>
using namespace std;
int A[26][26];
void generateTable()
{
    int k=0;
    for(int i=0;i<26;i++)
    {
        k=i;
        for(int j=0;j<26;j++)
        {
            A[i][j]=(k%26);
            k++;
        }
    }
}
void printTable()
{
    cout << "Vegenere table :" << endl;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            cout << (char)(A[i][j]+65) << " ";
        }
        cout << endl;
    }
}
string enCipher(string in,string key)
{
    string out="";
    while(key.length() < in.length())
        key+=key;
    //cout << key << endl;
    for(int i=0;i<in.length();i++)
        out+= (char)((A[key[i]-65][in[i]-65])+65);
    return out;
}

string deCipher(string out,string key)
{
    string in="";
    while(key.length() < out.length())
        key+=key;
//    cout << key << endl;
  //  cout << out << endl;
    for(int i=0;i<out.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if((char)(A[key[i]-65][j]+65) == out[i])
                in+=(char)(j+65);
        }
    }
    return in;
}

int main()
{
    string cipherText="",plainText="",key="";
    generateTable();
    printTable();
    cout <<"Enter plain text: ";
    cin >> plainText;

    cout << "Enter key :";
    cin >> key;

    cipherText = enCipher(plainText,key);
    cout << "Encrypted message :" << cipherText << endl;

    cout <<"Original message :"<<deCipher(cipherText,key) << endl;
    return 0;
}
