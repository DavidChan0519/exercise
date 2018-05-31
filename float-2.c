#include <stdio.h>      
void main()             
{                       
     double d,f;          
     char    *p;        
     int      i;        
     d=655269.871;      
     f=-655269.871;     

    p=(char*) (&d);              
    for (i=0; i<sizeof(d); i++){ 
       printf("%02x ",*(p+i));   
    }                            
    printf("  %03ld\n",sizeof(d));
                                 
    p=(char*) (&f);              
    for (i=0; i<sizeof(f); i++){ 
       printf("%02x ",*(p+i));   
    }                            
    printf("  %03ld\n",sizeof(f));
}
