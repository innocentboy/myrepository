#include<stdio.h>

int main(){
  int i,j,a;
  int size;

  scanf("%d",&size);
  while(size--){
    int N, K;
    double P[40];
    double opt_prob, tmp, add;
    int res[40], ind[40], now[40];
    
    scanf("%d%d",&N,&K);
    for(i=0; i<N; i++){
      scanf("%d",&j);
      P[i] = j / 100.0;
    }

    /* sort */
    for(i=0; i<N; i++) ind[i] = i;
    for(i=0; i<N; i++) for(j=1; j<N; j++) if(P[j-1] > P[j]){
      tmp = P[j-1]; P[j-1] = P[j]; P[j] = tmp;
      a = ind[j-1]; ind[j-1] = ind[j]; ind[j] = a;
    }

    opt_prob = -1;

    for(a=0; a<=K; a++){
      for(i=0; i<a; i++) now[i] = i;
      for(i=0; i<K-a; i++) now[a+i] = N-1-i;

      tmp = 0;
      for(i=0; i<K; i++){
        add = 1 - P[now[i]];
        for(j=0; j<K; j++) if(i!=j) add *= P[now[j]];
        tmp += add;
      }

      if(opt_prob < tmp){
        opt_prob = tmp;
        for(i=0; i<K; i++) res[i] = ind[now[i]];
      }
    }

/*    printf("%.17f\n",opt_prob);*/
    
    for(i=0; i<K; i++){
      if(i) putchar(' ');
      printf("%d",res[i]+1);
    }
    puts("");
  }
getch();
  return 0;
}
