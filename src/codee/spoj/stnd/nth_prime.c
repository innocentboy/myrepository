#define MAX 18028130
long long a[19000000];int main(){long long i,j,num,inc=2,m=0,q,k;for(i=0;i<sqrt(MAX)+1;i++)arr[i]=i;for(i=2;i<=sqrt(MAX);i++){
if(a[i]>0){for(j=inc*i;j<=MAX;j+=i)a[j]=-1;inc++;}}for(i=0;i<MAX;i++)if(arr[i]>1)arr[m++]=i;while(scanf("%lld",&q)&&q!=-1){printf("%lld\n",arr[q-1]);}return 0;}
