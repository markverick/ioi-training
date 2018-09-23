#include<stdio.h>
int mid;
int bs(long long kill[200000], long long key, int fst, int lst){
	if(kill[mid]==key)return mid;
  if (lst == fst+1||lst==fst){
  	if(lst==fst){
 	   return lst;
  	}
  	else if(key>=kill[lst]){
  		return lst;
  	}
  	else{
  		return fst;
  	}
  }
  else{
      mid = (fst+lst)/2;
      if (kill[mid] > key){
        return bs(kill, key, fst, mid-1);
      }
      else if (kill[mid] <= key){
        return bs(kill, key, mid, lst);
      }
    }
}
long long sum[1200000];
int main(){
    int i,j;
    int n,k,c;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&c);
        sum[i]=sum[i-1]+c;
        //printf("\nSUM = %d\n",sum[i]);
    }
    int d,v;
    for(i=1;i<=k;i++){
        scanf("%d",&c);
        v=bs(sum,c,0,n);
        printf("%d\n",v);
    }

}
/*
3 3
10 20 30
15 30 7
*/