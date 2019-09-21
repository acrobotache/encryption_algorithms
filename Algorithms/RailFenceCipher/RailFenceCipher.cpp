#include<bits/stdc++.h>
using namespace std;
string EnCipher(string plain,int key)
{
    string cipher="";
    int A[key][plain.length()];
    for(int i=0;i<key;i++)
        for(int j=0;j<plain.length();j++)
            A[i][j]=0;
    int row=0,col=0;
    bool flag=false;
    for(int i=0;i<plain.length();i++)
    {
        if(!flag)
        {
            A[row][col]=plain[i];
            row++;
            col++;
            if(row == key)
            {
                row-=2;
                flag=true;
            }
        }
        else if(flag)
        {
            A[row][col]=plain[i];
            row--;
            col++;
            if(row == -1)
            {
                row+=2;
                flag=false;
            }
        }
    }
    for(int i=0;i<key;i++)
        for(int j=0;j<plain.length();j++)
            if(A[i][j])
                cipher+=(char)(A[i][j]);
    return cipher;
}
string DeCipher(string cipher,int key)
{
    string plain="";
    int A[key][cipher.length()];
    for(int i=0;i<key;i++)
        for(int j=0;j<cipher.length();j++)
            A[i][j]=0;
    int row=0,col=0;
    bool flag=false;
    for(int i=0;i<cipher.length();i++)
    {
        if(!flag)
        {
            A[row][col]=-1;//marker
            row++;
            col++;
            if(row == key)
            {
                row-=2;
                flag=true;
            }
        }
        else if(flag)
        {
            A[row][col]=-1;//marker
            row--;
            col++;
            if(row == -1)
            {
                row+=2;
                flag=false;
            }
        }
    }
    int in=0;
    for(int i=0;i<key;i++)
        for(int j=0;j<cipher.length();j++)
            if(A[i][j]==-1 &&in < cipher.length())
                A[i][j] = cipher[in++];
    row=0;
    col=0;
    for(int i=0;i<cipher.length();i++)
    {
        if(!flag)
        {
            //get the character at marker place
            plain+=(char)(A[row][col]);
            row++;
            col++;
            if(row == key)
            {
                row-=2;
                flag=true;
            }
        }
        else if(flag)
        {
            plain+=(char)(A[row][col]);
            row--;
            col++;
            if(row == -1)
            {
                row+=2;
                flag=false;
            }
        }
    }
    return plain;
}
int main()
{
    string cipher,plain;
    int key;
    cout << "Enter key:";
    cin >> key;
    cout << "Enter plain text:";
    cin >> plain;
    cipher = EnCipher(plain,key);
    cout << "Encrypted data:" << cipher << endl;
    cout << "Original data:" << DeCipher(cipher,key) << endl;
    return 0;
}
