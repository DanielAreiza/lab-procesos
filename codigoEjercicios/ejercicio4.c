
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc, char *argv[]) {
 
  pid_t pid_h1;
  int status;
  
  pid_h1 = fork();
  
  if(pid_h1 == 0) {
   
    // Proceso hijo en donde llamamos exec
    printf("Iniciando subprograma\n");
    execl("./ejercicio1.out","./ejercicio1.out",NULL);
  }
    else {
      
      // Proceso padre

      wait(&status); // wait para esperar al proceso proceso hijo
      
      printf("Fin del programa\n");

    }

  return 0;
}
