#include<bits/stdc++.h>
using namespace std;
char str[135],len,x,y,i;
int main()
{
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        switch(str[i])
        {
        case 'N':
            y++;break;
        case 'S':
            y--;break;
        case 'E':
            x++;break;
        case 'W':
            x--;break;
        case 'Z':
            x=0;y=0;break;
        }
    }
    printf("%d %d",x,y);
}
