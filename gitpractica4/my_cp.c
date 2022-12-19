#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define N 512

int main()
{
    char file_name[N];
    int new_file_name;
    char buf[N];

    printf("Introdueix el nom de l'arxiu: ");
    scanf("%s", file_name);

    int fd = open(file_name, O_RDWR); // obrir l'arxiu per llegir i escriure

    if (fd == -1)
    {
        printf("ERROR: L'arxiu no existeix \n");
    }

    else
    {
        int bytes_read = read(fd, buf, N); // equivalent a la longitud del fitxer
        if (bytes_read == -1)
        {
            printf("ERROR en el procés de lectura \n");
        }
        else
        {
            new_file_name = open("copia.fi", O_CREAT | O_WRONLY | O_TRUNC, 00700);
            // 00700 es el codi dels permisos d'execució de S_IRWXU
            int bytes_write = write(new_file_name, buf, bytes_read);
        }
    }

    close(fd);
}
