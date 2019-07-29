#include <stdio.h>
#include <unistd.h>

/*
gcc -Wall example2.c -o example2.out
*/
int main (void){
  char rol;
  int x = 10;
  int i;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
    // Codigo hijo
    rol = 'Hijo';
    printf("Hello %d\n", getpid()); 
     
   }
   else {
     // Codigo padre
    rol = 'Padre';
    sleep(1);
    printf("goodbye: %d\n", x);
   }
   // Codijo ejecutado por ambos (para el caso)
   printf("%c -> i = %d\n",rol ,i);
   printf("analizando proceso %d\n", getpid());
   return 0;
}