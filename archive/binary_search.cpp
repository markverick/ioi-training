#include<stdio.h>
int str[120000];
int bs(int kill[200000], int key, int fst, int lst){
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
        return 1;
      }
    }
}
int main(){
    int n,m;
    int i,j,k;
    int b;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&str[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&b);
        printf("\t%d\n",bs(str,b,0,n));
    }

}
