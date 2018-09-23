#include<bits/stdc++.h>
int out[100];
int main()
{

    char a[100];

    int n;
    int i,j,k;
    scanf("%s",a);
    int len=strlen(a);
    for(i=0;i<len;i++)
    {
        switch (a[i])
        {
        case '1':case 'Q':case 'A':case 'Z':out[0]++;
        break;
        case '2':case 'W':case 'S':case 'X':out[1]++;
        break;
        case '3':case 'E':case 'D':case 'C':out[2]++;
        break;
        case '4':case 'R':case 'F':case 'V':case '5':case 'T':case 'G':case 'B':out[3]++;
        break;
        case '6':case 'Y':case 'H':case 'N':case '7':case 'U':case 'J':case 'M':out[4]++;
        break;
        case '8':case 'I':case 'K':case ',':out[5]++;
        break;
        case '9':case 'O':case 'L':case '.':out[6]++;
        break;
        case '0':case '-':case '=':case 'P':case '[':case ']':case ';':case '\'':case '/':out[7]++;
        break;
        }

    }
    for(i=0;i<8;i++)
    {
        printf("%d\n",out[i]);
    }
}
