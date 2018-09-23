#include<stdio.h>
int bs(long long kill[1200000], int key, int fst, int lst){
  if (lst < fst){
    return 0;
  }
  else{
      int mid = (fst+lst)/2;
      if (kill[mid] > key){
        return bs(kill, key, fst, mid-1);
      }
      else if (kill[mid] < key){
        return bs(kill, key, mid+1, lst);
      }
      else{
        return mid;
      }
    }
}
long long sum[1200000];
int main(){
    int i,j;
    int n,k,c;
    int hi=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&c);
        sum[i]=sum[i-1]+c;
        if(hi<c)hi=c;
        //printf("\nSUM = %d\n",sum[i]);
    }
    int d;

    for(i=1;i<=k;i++){
        scanf("%d",&c);
        printf("%d ",bs(sum,c,0,hi));
        //printf("%d\n",d);
    }

}
