#include<bits/stdc++.h>
using namespace std;
string key="HACK";
map<int,int> keyMap;
void PermutateKeyOrder()
{
    for(int i=0;i<key.length();i++)
    {
        keyMap[key[i]] = i;
    }
}
void UpdateKeyOrder()
{
    int in = 0;
    map<int,int>::iterator it;
    for(it=keyMap.begin(); it!=keyMap.end(); ++it)
        it->second = in++;
}
string enCipher(string plainText)
{
    string cipherText="";
    map<int,int>::iterator it;
    int row=plainText.length()/key.length();
    if(plainText.length()%key.length())
        row+=1;
    int col=key.length();
    char Cell[row][col];
    int c=0,j=0;
    PermutateKeyOrder();
    for(int i=0;i<row;i++)
    {
        for(j=0;j<col;)
        {
            if(plainText[c] == '\0')
            {
                Cell[i][j]='_';
                j++;
            }
            else if(isalpha(plainText[c]) || plainText[c] == ' ')
            {
                Cell[i][j]=plainText[c];
                j++;
            }
            c++;
        }
    }
    for(it=keyMap.begin();it!=keyMap.end();it++)
    {
        j=it->second;
        for(int i=0;i<row;i++)
        {
            cipherText+=Cell[i][j];
        }
    }
    return cipherText;
}
string deCipher(string cipherText)
{
    string plainText="";
    map<int,int>::iterator it;
    int col=key.length();
    int row = cipherText.length()/key.length();
    char outCell[row][col];
    int c=0;
    int j=0;
    for(it=keyMap.begin();it!=keyMap.end();it++)
    {
        j=it->second;
        for(int i=0;i<row;i++)
        {
            outCell[i][j]=cipherText[c++];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
                if(isalpha(outCell[i][j]))
                    plainText+=outCell[i][j];
                else
                    plainText+=' ';
        }
    }
    return plainText;
}
int main()
{
    string plainText="PRASADDESHMUKH";
    string cipher=enCipher(plainText);
    cout << cipher << endl;
    cout << deCipher(cipher);
    return 0;
}
