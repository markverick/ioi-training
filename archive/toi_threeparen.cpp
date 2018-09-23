#include<stdio.h>
#include<string.h>
char str[120000];
char stck[120000];
int main(){
    int n;
    int i,j,k;
    int idx=0;
    scanf("%d",&n);
    int len;
    for(i=1;i<=n;i++){
        idx=0;
        scanf("%s",str);
        len=strlen(str);
        for(j=0;j<len;j++){
            stck[idx]=str[j];
            if((stck[idx-1]=='('&&stck[idx]==')')||(stck[idx-1]=='{'&&stck[idx]=='}')||(stck[idx-1]=='['&&stck[idx]==']')){
                idx-=2;
                //printf("THIS j[%d] SUCK\n",j);
                //j+=1;

            }
            idx++;



            //printf("J = %d , STRING = %s\n",j,stck);
        }
        if(idx==0){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}
