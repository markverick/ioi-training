#include<stdio.h>
int main(){
    int n,m,p;
    int i,j,k,fu=0;
    int check=0,check2=0,check3=0,shit=0;
    int mc=0,dc=0,mc2=0,dcl=0,mcl=0,dcx=0;
    scanf("%d",&n);
    m=1;
    for(i=1;m*3<=n;i++){
        if(m*3==n){
            check=1;
            break;
        }
        else{
            m=m*3;
        }
    }
    //printf("I'M HERE");
    mc=check==1?i:i-1;
    p=m;

    while(check3==0){
        p=p/2;
        dcx++;
        for(i=1;check3==0&&p*3/2<=n;i++){
            if(p*3/2==n){
                check3=1;
                p=p*3/2;
                break;
            }
            else{
                p=p*3/2;
                printf("KUAYFUCKYOUBITCH");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPPPP is %d",p);
            }

        }
        mcl++;
        dcl+=2;

        printf("MC = %d, DC = %d,MC2 = %d\n,NOW = %d,MCL = %d,DCL = %d,DCX = %d",mc,dc,mc2,p,mcl,dcl,dcx);
    }
    if(p*3/2-n!=0)shit=1;
    mc2=check2==1?i:i-1;
    dc+=check2==1?i:i-1;
    printf("MC = %d, DC = %d,MC2 = %d\n,NOW = %d,MCL = %d,DCL = %d,DCX = %d",mc,dc,mc2,p,mcl,dcl,dcx);

}
