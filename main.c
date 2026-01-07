#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(void) {
    int fd[2];          // 0 per lettura e 1 per scrittura
    pid_t ritorno_fork; // contiene il risultato del fork
    pipe(fd);
    int regali;

    //creazione della pipe e controlla che sia creata

    if (pipe(fd) == -1)
        {
        perror("errore nella creazione della pipe");
        exit(-1);
        }
    ritorno_fork = fork(); // se > 0, ritorna il padre se == 0, ritorna il figlio, -1 == errore

    //controllo creazione del fork
    if (ritorno_fork == -1) {
        perror("errore nella esecuzione del fork");
        exit(-1);
    }

    if (ritorno_fork == 0) {
        //eventuale codice del figlio
        close(fd[1]);       //il figlio non scrive

        int scatole;
        read(fd[0], &regali, sizeof(regali));       //legge n regali dalla pipe
        close(fd[0]);

        scatole = (regali + 2) / 3;

        printf("scatole = %d \n regali:%d\n", scatole, regali);
    }
    else {
        //eventuale codice del padre
        close(fd[0]);

        printf("Quanti regali deve fare Babbo?");
        scanf("%d",&regali);

        //invia n regali all'elfo
        write(fd[1], &regali, sizeof(regali));      //scrive il numero dei regali nella pipe
        close(fd[1]);       //chiude la scrittura della pipe

        wait(NULL);         //aspetta il figlio che deve finire
    }

    return 0;
}