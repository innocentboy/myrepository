char word[20];int main(){int i,no,t=10;while(t-->0){no=0;scanf("%s",word);for(i=0;i<strlen(word);i++){if(word[i]=='F'||word[i]=='L')no++;else if(word[i]=='D')no++;
else if(word[i]=='T')no++;}printf("\n%d",(int)pow(2,no));}return 0;}
