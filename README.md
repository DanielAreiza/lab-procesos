# PRÁCTICA 1 - PROCESOS #

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades previas al laboratorio ##

Asignadas en la práctica anterior.
Leer el capítulo 5 del libro guía y comprender las diapositivas de clase asociadas a este capitulo.

## 3. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
  R/ En este caso el valor de la variable en el proceso hijo sera el valor inical de x=10 mas 3 que se le sumo al inicio del ciclo if para el hijo por lo tanto la variable tendra un valor de x =13.
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
  R/los valores de la variable x se modifican de manera independiente tanto para el padre como para el hijo.

2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 
  R/Si ambos pueden acceder
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
  R/ Ambos pueden modificar el archivo pero lo haran tomando turnos como lo defina el sitema operativo.

3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
R/Si es posible usando la funcion ```sleep()``` en el padre.

4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. 
* ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?
R/Porque aunque todas realizan la misma accion, se necesitan varias opciones para poder adaptarse a los parametros que requieren las diferentes aplicaciones y asi lograr un uso mas general para exec.

5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. 
* ¿Cuál es el valor de retorno de la función ```wait()```?
  R/La funcion wait retorna un entero que contiene el PID del proceso hijo que finalizó.
* ¿Qué pasa si usted usa la función ```wait``` en el hijo?
  R/Si se usa en el hijo la función ```wait()``` pondra al hijo en espera hasta que el padre haya terminado su ejecucion y luego continuara, esto se puede ver en la imagen que esta en la carpeta con el nombre ejercicio5.png

6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. 
*¿Cuándo podría ser ```waitpid()``` útil?
R/Esto podria ser util cuando se requiere que el padre continue solo despues de que finalice un proceso hijo en especifico, esto puede ser muy util cuando se esta trabajando con multiples fork.

7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
R/. En este caso l hijo no imprimira puesto que al realizar el cierre de la salida estandar con la funcion fclose(stdout), ya no es posible usar printf() para mostrar mensajes en la consola.

8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```

## 4. Para la próxima sesión de laboratorio ##
1. **Entregable**: Pendiente.
