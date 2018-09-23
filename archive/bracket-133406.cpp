#include<stdio.h>
int main(){
    int n;
    int i,j,k;
    char s[10100];
    int counter=0;
    int chck=0;
    scanf("%d ",&n);
    for(i=0;i<n;i++){
        counter=0;
        chck = 0;
        gets(s);

        //printf("%s",s);
        for(j=0;s[j]!='\0';j++){
            if(s[j]=='('){
                counter+=1;
               }
            else if(s[j]==')'){
                counter-=1;
            }
            else if(s[j]==' '){
                //noting here
            }
            else{
                chck = 1;
            }

            if(counter<0){
                chck = 1;
            }

        }

        if(chck==0&&counter==0){
            printf("TRUE");
        }
        else{
            printf("FALSE");
        }
        printf("\n");
    }





}
