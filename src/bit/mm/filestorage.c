#include<stdio.h>
#include<conio.h>
struct rec
{
   int regno;
   float salary;
   char name[30];       
};
int main()
{
     int i=0;
     char c='Y';
     struct rec e;
     FILE *fp;
     fp=fopen("C:\\Users\\Administrator\\Desktop\\record.txt","w");
   /*  if( ferror() )
     {
         perror("problem");
         exit(0);            
     } */
     if(fp==NULL)
     {
                 printf("file is not open properly..");
                 return;            
                 
     }
     scanf("%s%f%d",e.name,&e.regno,&e.salary);
   //  printf("\n enter the values of records to be inserted in the file..\n");
     fprintf(fp,"%s::%f::%d",e.name,e.regno,e.salary);
     fclose(fp);
     fp=fopen("C:\\Users\\Administrator\\Desktop\\record.txt","r");
     while(fscanf(fp,"%s::%f::%d",e.name,&e.salary,&e.regno)!=EOF)
     {
            //fscanf(fp,"%s : %f : %d",e.name,e.salary,e.regno)!=EOF
            //fread(&e,sizeof(e),1,fp)==1
            //fscanf(fp,"%d %f %s",&e.regno,&e.salary,e.name)!=EOF
           // printf("\ngajkshkfgkj\n");
         //  printf("\n");
          //scanf(" %d %f",&e.regno,&e.salary);
        // gets(e.name);
         // fwrite(&e,sizeof(e),1,fp);
         
         // fprintf(fp,"%s : %f : %d\n",e.name,e.salary,e.regno);
       printf("%d:%f:%s\n",e.regno,e.salary,e.name);
      // printf("enter either Y/N");
      //fflush(stdin);
    //  c=getche();
           
            
                  
     }
         fclose(fp);
         getch();
}
