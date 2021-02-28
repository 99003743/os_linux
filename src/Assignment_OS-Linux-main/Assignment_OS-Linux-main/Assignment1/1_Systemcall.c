#include <fcntl.h> 
#include<string.h>
int main(int arg,char* argc[]) 
{ 
  int f, s; 
  char *c = (char *) calloc(100, sizeof(char)); 
  printf("\n%s\n%s",argc[1],argc[2]);
  f = open(argc[1], O_RDONLY); 
  if (fd < 0) { 
    perror("r1"); 
  exit(1); 
  }
  
  sz = read(f, c, 100); 
  c[s] = '\0'; 
  printf("file data: % s\n", c); 
   
  int f1 = open(argc[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); 
  printf("file created\n");

   int k=write(f1,c,strlen(c));

  // printf("data written\n");
  free(c);
   close(f);
}

