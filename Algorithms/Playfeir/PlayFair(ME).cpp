#include<bits/stdc++.h>
using namespace std;
int main()
{
    char KeyArr[5][5]={
        {'P','J','S','A','B'},
        {'C','D','F','E','T'},
        {'Y','X','W','V','U'},
        {'Z','G','H','K','L'},
        {'I','R','O','M','N'}
    };
    int X[26],Y[26];
    int c=0,x1,x2,y1,y2;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            X[KeyArr[i][j]-65]=i;
            Y[KeyArr[i][j]-65]=j;
        }
    }
    string plainText="",cipherText="";
    cin >> plainText;
    cout << "PlainText:" << plainText << endl << endl;
    bool f=0;
    if(plainText.length()%2)
        {
            plainText+='Z';
            f=1;
        }
    for(int i=0;i<plainText.length();)
    {
         x1=X[plainText[i]-65];
         y1=Y[plainText[i]-65];
         x2=X[plainText[i+1]-65];
         y2=Y[plainText[i+1]-65];
        if(x1 == x2)
            {
                y1++;
                y2++;
                cipherText+=KeyArr[x1][y1];
                cipherText+=KeyArr[x2][y2];
            }
            else if(y1 == y2)
            {
                x1++;
                x2++;
                cipherText+=KeyArr[x1][y1];
                cipherText+=KeyArr[x2][y2];
            }
            else
            {
                cipherText+=KeyArr[x1][y2];
                cipherText+=KeyArr[x2][y1];
            }
        i+=2;
    }
    cout << "cipherText:" << cipherText << endl << endl;
    plainText="";
    for(int i=0;i<cipherText.length();)
    {
         x1=X[cipherText[i]-65];
         y1=Y[cipherText[i]-65];
         x2=X[cipherText[i+1]-65];
         y2=Y[cipherText[i+1]-65];

            if(x1 == x2)
            {
                y1--;
                y2--;
                plainText+=KeyArr[x1][y1];
                plainText+=KeyArr[x2][y2];
            }
            else if(y1 == y2)
            {
                x1--;
                x2--;
                plainText+=KeyArr[x1][y1];
                plainText+=KeyArr[x2][y2];
            }
            else
            {
                plainText+=KeyArr[x1][y2];
                plainText+=KeyArr[x2][y1];
            }
        i+=2;
    }
    if(f==1)
        plainText=plainText.substr(0,plainText.length()-1);
    cout <<"Original Text"<<plainText << endl << endl;
    return 0;
}
