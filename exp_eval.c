#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"linkedlist.c"
#include"d_stack_s.c"
#include"d_stack_h.c"
#include"d_stack_f.c"
#include"chk_paran.h"
#include"tokenize.h"
#include"get_type.h"
#include"validate_exp.h"
#include"postfix.h"


float exp_eval()
{
 char ch;
 list *tmp1,*tmp2;
 float x,y,z;
 for(tmp=head;tmp!=NULL;tmp=tmp->next)
 {
  ch=tmp->tok[0];
  if((int)ch>=48 && (int)ch<=57)
   continue;
  else
  {
   x=atof(tmp->prev->tok);
   y=atof(tmp->prev->prev->tok);
   if(ch=='+') z=x+y;
   if(ch=='-') z=y-x;
   if(ch=='*') z=x*y;
   if(ch=='/') z=y/x;
   if(ch=='^') z=(float)pow(y,x);
   if(ch=='%') z=(int)y%(int)x;
   tmp->tok=(char*)realloc(tmp->tok,sizeof(char)*15);
   sprintf(tmp->tok,"%f",z);
   tmp1=tmp->prev;
   tmp2=tmp->prev->prev;
   if(tmp->prev->prev->prev==NULL)
   {
    head=tmp;
    tmp->prev=NULL;
   }
   else
    tmp->prev=tmp->prev->prev->prev;
   free(tmp1);
   free(tmp2);   
  } 
 } 
 return atof(head->tok);
}

int main()
{
 int cnt=0;
 char *exp,**t_exp,ch,type;
 
 exp=(char*)malloc(sizeof(char)*100);
 t_exp=(char**)malloc(sizeof(char*)*1);
 printf("\nEnter the string:");
 scanf("%s",exp);
 
 if(chk_p(exp))
 {
  tokens(&exp,&t_exp,&cnt);
  if(validate(t_exp,cnt))
  {
   postfix(t_exp,cnt);
   fprintf(stdout,"ANS : %f",exp_eval());
  }
  else 
   printf("\n Invalid expression");
 }
 else
  printf("brackets not balanced!");
 return 0;
}
