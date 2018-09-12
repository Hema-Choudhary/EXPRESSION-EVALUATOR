
void push(char ch)
{
 stk *new;
 new = (stk*)malloc(sizeof(stk));
 new->no=ch;
 new->down=NULL;
 if(top==NULL)
 {
  top=new; 
 }
 else
 {
  new->down=top;
  top=new;
 } 
}

int isempty()
{
 if(top==NULL)
  return 1;
 else 
  return 0;
}

char pop()
{
 char x;
 stk *tmp;
 tmp=top;
 x=top->no;
 top=top->down;
 free(tmp); 
 return x;
}

int peek()
{
 if(!isempty())
  return (top->no);
 else 
  return -100;
}
