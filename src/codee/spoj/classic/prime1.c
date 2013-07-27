#include<stdio.h>
#define N 1000000000
#define N1 100004
#define S 31700
int nprime[S], bl[N1];
int primes[S],cnt;
int main()
{
    
     int i,j,k,t,n,m,result=0,maxk,start,start_idx;
	 int nsqrt =(int)sqrt(N);printf("\nroot:%d\n",nsqrt);
	 for (i=2; i<=nsqrt;++i)
		 if (!nprime[i]) {
			 primes [cnt++]=i;
			 //if (i * 1ll * i <= nsqrt)
			 for (j=i*i;j<=nsqrt;j+=i)
					 nprime[j]=1;
		 }printf("gdfasfhsk\n");
     scanf("%d",&t);
     while(t--){		 
     scanf("%d",&m);scanf("%d",&n);		 
/*	 for(k =0,maxk=n/N1;k<=maxk;++k){
		 memset (bl, 0, sizeof (bl));
		 start =k*N1;
		 for (i=0;i<cnt;++i) {
			 start_idx = (start+primes[i]-1) / primes [i];
			 j = ((start_idx>2)?start_idx:2)*primes[i]-start;
			 for (;j<N1;j+=primes[i])
				 bl[j]=1;
		 }
		 if (k == 0)
			 bl[0]=bl[1]=1;
		 for (i=0;i<N1&&start+i<=n;++i)
			 if (!bl[i])
				 printf("\n%d",n+i);
     }*/
   }
   getch(); 
   return 0;    
}
