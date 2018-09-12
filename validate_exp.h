int validate(char **,int);

int validate(char **t_exp,int cnt)
{
 int i,type,chk;
 for(i=0;i<cnt-1;i++)
 {
  if(i==0)
   type=get_type(t_exp[i]); 
  else 
   type=chk;
  chk=get_type(t_exp[i+1]);
  if(chk==5)
   { return 0;}
  
  if(((type==1 || type==3) && i==0 ) || ((chk==1 || chk==2) && i==cnt-2))
     {  return 0;}
  switch(type)
  {
   case 1: 
          if(chk != 2 && chk !=4 )
            { return 0;}break;
   case 2: 
	  if(chk != 4 && chk!=2)
           { return 0;}break;
   case 3: 
 	  if(chk!= 1 && chk!=3)
           { return 0;}break;
   case 4:
  	  if(chk !=3 && chk!=1)
           { return 0;}
   }
 } 
 return 1;
}

