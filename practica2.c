#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512
float Mat[N][N], MatDD[N][N], V1[N], V2[N], V3[N], V4[N];

void InitData()
{
    int i, j;
    srand(8824553);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            Mat[i][j] = (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
            if ((abs(i - j) <= 3) && (i != j))
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (rand() / (1.0 * RAND_MAX));
            else if (i == j)
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (10000.0 * (rand() / (1.0 * RAND_MAX)));
            else
                MatDD[i][j] = 0.0;
        }
    for (i = 0; i < N; i++)
    {
        V1[i] = (i < N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        V2[i] = (i >= N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        V3[i] = (((i * j) % 5) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
    }
}

void PrintVect(float vect[N], int from, int numel)
{
    for (int i = from; i < numel; i++)
    {
        printf("%f \n", vect[i]);
    }
}

void PrintRow(float Mat[N][N], int row, int from, int numel)
{
    for (int i = from; i < numel; i++)
    {
        printf("%f \n", Mat[row][0]);
    }
}

void MultEscalar(float vect[N], float vectres[N], float alfa)
{
    for (int i = 0; i < N; i++)
    {
        vectres[i] = alfa * vect[i];
    }
}

float Scalar(float vect1[N], float vect2[N])
{
    float scalar = 0;
    for (int i = 0; i < N; i++)
    {
        scalar += vect1[i] * vect2[i];
    }
    return scalar;
}

float Magnitude(float vect[N])
{
    float longitud = 0;
    for (int i = 0; i < N; i++)
    {
        longitud += vect[i] * vect[i];
    }
    return longitud;
}

int Ortogonal(float vect[N], float vect2[N])
{
    for (int i = 0; i < N; i++)
    {
        if (vect[i] * vect2[i] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void Projection(float vect1[N], float vect2[N], float vectres[N]) // NO FUNCIONA
{
    float scalar = Scalar(vect1, vect2);
    float magnitud = Magnitude(vect2);
    vectres[N] = (scalar / magnitud) * (vect2);
}

float Infininorm(float Mat[N][N])
{
    int i, llista[N], suma = 0;

    for (i = 0; i < N; i++)
    {
        suma += Mat[(fabs), i][0];
        llista[suma];
    }
    for (i = 0; i < N; i++)
    {
        if (llista[0] < llista[i])
        {
            llista[0] = llista[i];
        }
    }
}

float Onenorm(float Mat[N][N])
{
    int i, llista[N], suma = 0;

    for (i = 0; i < N; i++)
    {
        suma += Mat[0][(fabs), i];
        llista[suma];
    }
    for (i = 0; i < N; i++)
    {
        if (llista[0] < llista[i])
        {
            llista[0] = llista[i];
        }
    }
}

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
    int row, from, numel, s;
    InitData();

    printf("intro posició inicial: ");
    scanf("%d", &from);
    printf("intro posició final: ");
    scanf("%d", &numel);

    PrintVect(V1, from, numel);

    printf("intro fila: ");
    scanf("%d", &row);

    PrintRow(Mat, row, from, numel);

    MultEscalar(V1, V2, 2.0);

    float res_scalar = Scalar(V1, V2);
    printf("El producte escalar dona com a resultat: %f \n", res_scalar);

    float res_magnitud = Magnitude(V1);
    printf("La funció magnitud dona: %f \n", res_magnitud);

    float res_ortogonal = Ortogonal(V1, V2);
    if (res_ortogonal == 0)
    {
        printf("No és ortogonal \n");
    }
    else
    {
        printf("És ortogonal \n");
    }

    float res_projection = Projection(V1, V2, V3);
    printf("La projecció és: %f \n", res_projection);

    int res_infini = Infininorm(Mat);
    printf("La infininorm és: %i \n", res_infini);

    int res_onenorm = Onenorm(Mat);
    printf("La norma-ú és: %i \n", res_onenorm);

    int res_frobenius = NormFrobenius(Mat);
    printf("La norma Frobenius és: %i \n", res_frobenius);
}