#include<stdio.h>
#include<string.h>
int main(){
    int n;
    int i,j,k,x=0,y=0;
    char str[150];
    scanf("%s",str);
    for(i=0;i<strlen(str);i++){
        //printf("%c",str[i]);
        if(str[i]=='N')y++;
        if(str[i]=='S')y--;
        if(str[i]=='E')x++;
        if(str[i]=='W')x--;
        if(str[i]=='Z'){x=0;y=0;}


      //kuayraisas  printf("%d %d",x,y);
    }
    printf("%d %d",x,y);
}
