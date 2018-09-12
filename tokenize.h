
void tokens(char **,char ***,int *);

void tokens(char **e1,char ***e2,int *c)
{
 int i=0,j=-1,k,cnt;
 while(1)
 { 
  cnt=0;
  if((*e1)[i]=='\0')
   break;
  (*c)++; 
  (*e2)=(char**)realloc((*e2),sizeof(char*)*(*c));
  j++;
  if((int)(*e1)[i]>=48 && (int)(*e1)[i]<=57)
  {
   cnt++;
   while(1)
   {
    i++;
    if((*e1)[i]=='\0')
     break;
    else if((int)(*e1)[i]>=48 && (int)(*e1)[i]<=57)
     cnt++;
    else
     break;  
   }
   i=i-cnt;
   (*e2)[j]=(char*)realloc((*e2)[j],sizeof(char)*cnt+1);
   for(k=0;k<cnt;k++)
    (*e2)[j][k]=(*e1)[i++];
   (*e2)[j][k]='\0'; 
  }
  
  else
  {
   (*e2)[j]=(char*)realloc((*e2)[j],sizeof(char)*2);
   (*e2)[j][0]=(*e1)[i];
   (*e2)[j][1]='\0';
   i++;
  }
 }
}

