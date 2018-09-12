int pri(char);
void postfix(char **,int);


int pri(char op)
{
 if(op=='^')
  return 1;
 else if(op=='/' || op=='*' || op=='%')
  return 2;
 else if(op=='+' || op=='-')
  return 3;
}

void postfix(char **t_exp,int cnt)
{
  list *new;
  char ch;
  int i,p,type;
 for(i=0;i<cnt;i++)
 {  
    type=get_type(t_exp[i]);
    switch(type)
    {
  
     case 2:   
              push('(');
              break;
   
     case 3:  
              while((ch=pop())!='(')
              { 
               new=(list*)malloc(sizeof(list));
               (new->tok)=(char*)malloc(sizeof(char)*2);
               new->tok[0]=ch;
               new->tok[1]='\0';
               new->next=NULL;
               new->prev=tmp;
               tmp->next=new;
               
               tmp=new;
       	      }break;
     
     case 1:  
               p=pri(t_exp[i][0]);
    
               if(isempty())
                push(t_exp[i][0]);
     
               else if(top->no=='(')
                push(t_exp[i][0]);

               else if(pri(top->no)>p)
                 push(t_exp[i][0]);
     
               else
               {
                while(pri(top->no)<=p || top->no!='(')
                { 
                ch=pop();
               new=(list*)malloc(sizeof(list));
               (new->tok)=(char*)malloc(sizeof(char)*2);
               new->tok[0]=ch;
               new->tok[1]='\0';
               new->next=NULL;
               new->prev=tmp;
               tmp->next=new;
               tmp=new;
               
               if(!isempty())
                 continue;
               else break;
                }
                push(t_exp[i][0]);
              }break;
    
    case 4: 
    
               new=(list*)malloc(sizeof(list));
               (new->tok)=(char*)malloc(sizeof(char)*strlen(t_exp[i]));
               strcpy(new->tok,t_exp[i]);
               new->next=new->prev=NULL;
               if(head==NULL)
                head=tmp=new;
               else
               {
               new->prev=tmp;
               tmp->next=new;
               tmp=new;
               } 
   
    }
 }
 while(!isempty())
  {
    ch=pop();
    new=(list*)malloc(sizeof(list));
    (new->tok)=(char*)malloc(sizeof(char)*2);
    new->tok[0]=ch;
    new->tok[1]='\0';
    new->next=NULL;
    new->prev=tmp;
    tmp->next=new;
    tmp=new;
  }
}

