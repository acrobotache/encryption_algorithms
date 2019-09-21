#include<bits/stdc++.h>
using namespace std;
int FindMinX(int *num,int *rem,int n)
{
    int x=1,j=0;
    while(true)
    {
        for(j=0;j<n;j++)
            if(x%num[j]!=rem[j])
                break;
        if(j == n)
            return x;// if found return here itself
        x++;
    }
    return x;
}
int main()
{
    int n;
    cout << "Enter number of elements :";
    cin >> n;

    int *num = (int *)malloc(n*sizeof(int));
    int *rem = (int *)malloc(n*sizeof(int));

    cout << "Enter elements :";
    for(int i=0;i<n;i++)
        cin >> num[i];

    cout << "Enter remainders:";
    for(int i=0;i<n;i++)
        cin >> rem[i];

    cout << "Minimum value of x is :" << FindMinX(num,rem,n) << endl;
    return 0;
}
