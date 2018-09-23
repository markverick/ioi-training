#include<bits/stdc++.h>
using namespace std;
int maps[10][10];
int main()
{
    int n,i,j,k;
    for(i=1;i<=4;i++)
        for(j=1;j<=6;j++)
            cin >> maps[i][j];
    for(j=1;j<=6;j++)
    {
        int sum=0;
        for(i=1;i<=4;i++)
        {
            sum*=2;
            sum+=maps[i][j];
        }
        1-j%2&&j<6?cout << sum << ":": cout << sum;
    }
}
