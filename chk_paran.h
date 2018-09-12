
int chk_p(char *);


int chk_p(char *e)
{
 int i;
 for(i=0;e[i]!='\0';i++)
  {
   if(e[i]=='(')
    push('(');
   if(e[i]==')')
    pop();
  }   
 if(top==NULL)
  return 1;
 else return 0;
}

