#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define N 512 // mesura per llegir l'arxiu

int main()
{
    char file_name[N];
    int fd, bytes_read;
    char buf[N];

    // DEMANEM EL NOM DE L'ARXIU
    printf("Introdueix el nom d'un arxiu: ");
    scanf("%s", file_name);

    // CRIDA A LA FUNCIÓ OPEN PER OBRIR L'ARXIU INTRODUIT
    fd = open(file_name, O_RDONLY);
    if (fd == -1) //-1 indica que no existeix
    {
        printf("ERROR: L'arxiu no existeix\n");
    }

    else
    { // arxiu existeix --> llegir els continguts de l'arxiu
        bytes_read = read(fd, buf, N);
        if (bytes_read == -1)
        { // error
            printf("ERROR en el procés de lectura\n");
        }

        else
        { // MOSTRAR PER PANTALLA els continguts llegits
            printf("El arxiu diu:\n");
            printf("%s", buf);

            // TANCAR ARXIU
            if (close(fd) == 0)
            {
                printf("\nARXIU TANCAT\n");
            }
            else
            {
                printf("ERROR: no s'ha pogut tancar l'arxiu \n");
            }
        }
    }
}
