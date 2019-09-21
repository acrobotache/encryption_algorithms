#include <iostream>
using namespace std;

string encrypt(string text, int key)
{
    string result = "";
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]+key-65)%26 +65);
    else
        result += char(int(text[i]+key-97)%26 +97);
    }
    return result;
}
int main()
{
    string text="PrasadSubhashManedeshmukh";
    int key = 4;
    cout << "Plaintext : " << text;
    cout << "\nCiphertext: " << encrypt(text, key);
    return 0;
}
