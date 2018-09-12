int get_type(char *);

int get_type(char *str)
{
 int type;

 if(str[0]=='/' || str[0]=='*' || str[0]=='-' || str[0]=='+' || str[0]=='%' || str[0]=='^')
   {
    type=1;
   }
 
else if(str[0]=='(')
   type=2;

 else if(str[0]==')')
   {
    type=3;
   }
 else if(atoi(str)!=0 || (atoi(str)==0 &&  str[0]=='0'))
   {
    type=4;
   }
 else  type=5; 
 return type;
}


