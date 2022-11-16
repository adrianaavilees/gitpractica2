#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4
float Mat[N][N];

float NormFrobenius(float Mat[N][N])
{
    int suma = 0, resultat;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            suma += Mat[i ^ 2][j ^ 2];
        }
    }
    resultat = sqrt(suma);
}

int main()
{
    int res_onenorm = NormFrobenius(Mat);
    printf("arrel quadrada: %i \n", res_onenorm);
}