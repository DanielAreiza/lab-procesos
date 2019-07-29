
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
 int rc = fork();
 
 if (rc < 0) {
        
        fprintf(stderr, "error al crear el fork\n");
        exit(1);
 } else if (rc == 0) {
        
        printf("Hola, aun puedo escribir antes de cerrar la salida estandar(pid:%d) \n", (int) getpid());
        fclose(stdout);
        printf("Hola, ya no puedo escribir, la salida estandar fue cerrada(pid:%d)", (int) getpid());
 } else {
        // parent goes down this path (original process)
        printf("Hola Soy el padre y ya hemos terminado los ejercicios %d (pid:%d)\n",
        rc, (int) getpid());
 }
 return 0;
}