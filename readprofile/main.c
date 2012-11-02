/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月09日 11时59分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define BUFFSIZE 100
int 
read_cfg(const char *file_name,const char *key,char *value)
{
    
FILE *fd;

fd=fopen(file_name,"r");

if (fd==NULL) return 1;

char item[BUFFSIZE];

memset(item,0,BUFFSIZE);

int index=0;

while(fgets(item,BUFFSIZE,fd)!=EOF)
{
   
   char *temp=item;

   char *analyze=temp;

   if (*temp=='#') continue;
   

   int key_start=0,key_end=0,val_start=0,val_end=0,parse=0,parse_locate=0;

   int flag=1; 
   
   while(temp!=EOF&&*temp!='\0'&&*temp!='\n')

   { 
   
     char find_char=*(temp++);
   
     if   (find_char=='=') 
     {
    parse++;
    
    if (parse==1) parse_locate=flag;
     }
   
     if (find_char!=' '&&!parse) 
     
     {
        if (key_start==0)
       { 
       
     key_start=flag;
       
     if (*temp=='=') key_end=key_start;
       
       } 
     } 
     
     if (find_char!=' '&&!parse&&key_start) 
     
     
     {
    
        key_end=flag;
    

     }

    if (find_char!=' '&&parse==1&&parse_locate!=flag&&!val_start) 
    val_start=flag;   
    
    if (find_char!=' '&&val_start)   
    val_end=flag;

    flag++;

      
   }
       
if (key_start*key_end*val_start*val_end)

{
   int index_tmp;
      
   char * key_tmp,*val_tmp,*key_result,*val_result;

   int key_len=key_end-key_start+1;

   int val_len=val_end-val_start+1;

   key_tmp=(char *)malloc(key_len);

   val_tmp=(char *)malloc(val_len);

   memset(key_tmp,0,key_len); 

   memset(val_tmp,0,val_len); 
    
   key_result=key_tmp;
   
   val_result=val_tmp;
   
   
      
   for(index_tmp=1;(analyze!=NULL)&&*(analyze)!='\n'&&*(analyze)!='\0';index_tmp++)
    {

     if (index_tmp>=key_start&&index_tmp<=key_end)
        *(key_tmp++)=*analyze;
     
     if (index_tmp>=val_start&&index_tmp<=val_end)
        *(val_tmp++)=*analyze;
     
     analyze++;
    }

    if (!strcmp(key,key_result)) 
    { 
    while(val_len--) *(value++)=*(val_result++) ;
   
    *val_result='\0';
         
    fclose(fd);
   
    return 0;
    }
    
    
    
}

}


close(fd);

return 3;
}

int main(int argc,char *argv[])
{
char *key="w";
char *value=(char *)malloc(20);

    memset(value,0,20);
     
   int flag=read_cfg("cfg.txt",key,value);

   if (flag==1) printf("open file error");
   
printf(" filename=%s key=%s, value=%s \n","cfg.txt","test",value);

}
