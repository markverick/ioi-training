#include<stdio.h>
void space(int p){
    int o;
    for(o=1;o<=p;o++){
        printf(" ");
    }
}
void del(int n){
    int i;
    for(i=1;i<=n;i++)
        printf("\b");
}
int main(){
    int n;
    char chm[10000];
    int i,j,k;
    int layer;
    int cot=0;
    char chr;
    int ex=0;
    int rhi=0,hi;
    char ch = 'A';
    scanf("%d",&n);
    for(layer=1;layer*(layer+1)/2<n;layer++){;}
    hi = layer*(layer+1)/2;

    if(layer%2==1){
        rhi = layer-2;
    }
    else{
        rhi=layer-1;
    }
    if(layer%2==1){
        ex=hi-n;

        if(hi-n>=2)ex=0;
        if(hi-n==0)ex=2;
    }
    for(i=1;i<layer;i++){
        space(ex);
        space(rhi-1);
        if(i%2==1){
            del(i-1);
            chr=ch+i-1;
            chm[i]=ch;
            for(j=1;j<=i;j++){
                if(chr>'Z')chr-=26;
                if(chr<'A')chr+=26;

                printf("%c",chr);
                chr--;
                ch++;
                cot++;
            }
        }
        if(i%2==0){
            chm[i]=ch;
            for(j=1;j<=i;j++){
                if(ch>'Z')ch-=26;
                if(ch<'A')ch+=26;
                printf("%c",ch);
                ch++;
                cot++;
            }
        }
    printf("\n");
    }

    if(layer%2==1){
        space(rhi - (layer-(hi-n)));
        chr=ch+i-1;
        for(i=1;true;i++){
            if(cot>=n)break;
            if(chr>'Z')chr-=26;
            if(chr<'A')chr+=26;

            printf("%c",chr);
            chm[layer]=chr;
            chr--;

            ch++;
            cot++;
        }
    }
    else{
        space(rhi-1);
        chm[layer]=ch;
        for(i=1;true;i++){
            if(cot>=n)break;
            if(ch>'Z')ch-=26;
            if(ch<'A')ch+=26;
            printf("%c",ch);

            ch++;
            cot++;

        }
    }
    printf("\nWords in the middle is ");
    for(i=1;i<=layer;i++){
        if(chm[i]>'Z')chm[i]-=26;
        printf("%c ",chm[i]);
    }
   // if(layer%2==1)
//printf("\n EX = %d, Layer = %d, N = %d, HI = %d, RHI = %d\n",ex,layer,n,hi,rhi);
}
