#include <fcntl.h> 
#include<stdio.h>
int main() 
{ 
  int f, s; 
  char *c = (char *) calloc(100, sizeof(char)); 
  
  f = open("foo.txt", O_RDONLY); 
  if (f < 0) { perror("r1"); exit(1); } 
  
  s = read(f, c, 100); 
  c[s] = '\0'; 
 //printf("file data: % s\n", c); 
 int w_c=0,l_c=0,i=0;
 int inword;
 for(i=0;i<strlen(c);i++)
 {
         if(c == ' ' || c == '\t' || c == '\n' || c == '\0')
        {
            if(inword)
            {
                inword=0;
                w_c++;
            }
        }
     if(c[i]=='\n')
        l_c++;
    else 
        inword=1;


 }
    printf("\ntotal no lines %d\ntotal no of words %d\ntotal no of characters: %d\n",l_c,w_c,i);
    close(f);
}
