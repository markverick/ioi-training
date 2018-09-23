#include<stdio.h>
int x[250][250],mi[250],mj[250];
int main(){
    int i,j,k;

    int n;
    int a=0,b=0;
    char ch='A';
    scanf("%d",&n);
    for(i=1;i<=150;i++){
        x[i][75]='*';
    }
    for(i=1;i<=150;i++){
        a=0;
        if(i%2==0){

            for(j=1;j<=150;j++){
                if((x[i][j]=='*'||x[i][j+1]>='A')&&a<i&&b<n){
                    x[i][j]=ch;
                    ch++;
                    a++;
                    b++;
                    if(ch>'Z'){
                        ch-=26;
                    }
                }
                else{
                    x[i][j]='.';
                }
            }
        }
        else{
            for(j=150;j>=1;j--){
                if((x[i][j]=='*'||x[i][j-1]>='A')&&a<i&&b<n){
                    x[i][j]=ch;
                    ch++;
                    a++;
                    b++;
                    if(ch>'Z'){
                        ch-=26;
                    }
                }
                else(x[i][j]='.');
            }
        }
    }
    for(i=1;i<=150;i++){
        for(j=1;j<=150;j++){
            if(x[i][j]>='A'){
                mi[i]=1;

            }
        }
    }

    for(i=1;i<=150;i++){
        for(j=150;j<=1;j--){
            if(x[i][j]>='A'){
                mj[j]=1;
            }
        }
    }

    b=i;
    for(i=1;i<=150;i++){
        for(j=1;j<=150;j++){
            if(mi[i]==1&&mj[j]==1){
                printf("%c",x[i][j]);
            }
        }
        if(mi[i]!=1){
            break;

        }
        printf("\n");
    }


}
