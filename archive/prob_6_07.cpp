#include<stdio.h>
#include<string.h>
int main(){
    int n,len;
    int i,j,k;
    char *p;
    char x[1000];
    scanf("%s",x);
    len = strlen(x);
    p=&x[0];
    for(i=0;i<len;i++,p++){
        if(*p!=*(p+1)){
            printf("%c",*p);
        }
        else{
            printf("%c",*p);
            printf("x");
        }
    }
}
