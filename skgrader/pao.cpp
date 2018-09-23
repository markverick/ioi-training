#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int num_1,num_2;
    char oper;
    printf("input number1:");
    cin >> num_1;
    printf("input number2:");
    cin >> num_2;
    printf("input Operator:");
    cin >> oper;
    if(oper=='+')
    {
        printf("%d",num_1+num_2);
    }
    else if(oper=='-')
    {
        printf("%d",num_1-num_2);
    }
    else if(oper=='*')
    {
        printf("%d",num_1*num_2);
    }
    else if(oper=='/')
    {
        printf("%d",num_1/num_2);
    }
    else if(oper=='%')
    {
        printf("%d",num_1%num_2);
    }
    getch();
    return 0;
}
