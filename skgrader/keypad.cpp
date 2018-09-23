#include<bits/stdc++.h>
int numx[20];
int num[20];
char str[200];
int main()
{
    int a=11,b=11;
    int n;
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        scanf("%d",&numx[i]);
        num[numx[i]]=i;
    }
    scanf("%s",str);
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        switch (str[i])
        {
        case 'c':case 'b':case 'a':a=2;break;
        case 'd':case 'e':case 'f':a=3;break;
        case 'g':case 'h':case 'i':a=4;break;
        case 'l':case 'k':case 'j':a=5;break;
        case 'm':case 'n':case 'o':a=6;break;
        case 'p':case 'q':case 'r':case 's':a=7;break;
        case 't':case 'u':case 'v':a=8;break;
        case 'w':case 'x':case 'y':case 'z':a=9;break;
        }
        if(b==a)
        {
            printf("#");
        }
        b=a;
        switch (str[i])
        {
        case 'c':
            printf("%d",num[2]);a=2;
        case 'b':
            printf("%d",num[2]);a=2;
        case 'a':
            printf("%d",num[2]);a=2;
            break;
        case 'f':
            printf("%d",num[3]);a=3;
        case 'e':
            printf("%d",num[3]);a=3;
        case 'd':
            printf("%d",num[3]);a=3;
            break;
        case 'i':
            printf("%d",num[4]);a=4;
        case 'h':
            printf("%d",num[4]);a=4;
        case 'g':
            printf("%d",num[4]);a=4;
            break;
        case 'l':
            printf("%d",num[5]);a=5;
        case 'k':
            printf("%d",num[5]);a=5;
        case 'j':
            printf("%d",num[5]);a=5;
            break;
        case 'o':
            printf("%d",num[6]);a=6;
        case 'n':
            printf("%d",num[6]);a=6;
        case 'm':
            printf("%d",num[6]);a=6;
            break;
        case 's':
            printf("%d",num[7]);a=7;
        case 'r':
            printf("%d",num[7]);a=7;
        case 'q':
            printf("%d",num[7]);a=7;
        case 'p':
            printf("%d",num[7]);a=7;
            break;
        case 'v':
            printf("%d",num[8]);a=8;
        case 'u':
            printf("%d",num[8]);a=8;
        case 't':
            printf("%d",num[8]);a=8;
            break;
        case 'z':
            printf("%d",num[9]);a=9;
        case 'y':
            printf("%d",num[9]);a=9;
        case 'x':
            printf("%d",num[9]);a=9;
        case 'w':
            printf("%d",num[9]);a=9;
            break;
        }

    }
}
