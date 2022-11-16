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

void PrintVect(float vect[N], int from, int numel) // al ser void, no retorna res
{
    for (int i = from; i < numel; i++) // recorre tots els elements des de from fins numel introduïts al programa principal
    {
        printf("%f \n", vect[i]);
    }
}

void PrintRow(float Mat[N][N], int row, int from, int numel)
{
    for (int i = from; i < numel; i++)
    {
        printf("%f \n", Mat[row][0]); // considerem la columna sempre 0: només ens interessa la fila (i)
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
        scalar += vect1[i] * vect2[i]; // sumatori del producte dos vectors diferents
    }
    return scalar;
}

float Magnitude(float vect[N])
{
    float longitud = 0;
    for (int i = 0; i < N; i++)
    {
        longitud += vect[i] * vect[i]; // sumatori del producte del mateix vector
    }
    return longitud;
}

int Ortogonal(float vect[N], float vect2[N])
{
    for (int i = 0; i < N; i++)
    {
        if (vect[i] * vect2[i] == 0) // si es compleix el producte de dos vectors igual a 0
        {
            return 1; // ortogonal
        }
        else
        {
            return 0; // no ortogonal
        }
    }
}

float Projection(float vect1[N], float vect2[N], float vectres[N])
{
    // cridem a les funcions necessaries i les assignem a les variables
    float scalar = Scalar(vect1, vect2);
    float magnitud = Magnitude(vect2);
    vectres[N] = (scalar / magnitud) * (vect2[N]);
    return vectres[N];
}

float Infininorm(float Mat[N][N])
{
    int i, llista[N], suma = 0;

    for (i = 0; i < N; i++)
    {
        suma += Mat[(fabs), i][0]; // valor absolut de cada element de la fila
        llista[suma];
    }
    for (i = 0; i < N; i++)
    {
        if (llista[0] < llista[i]) // busca el màxim
        {
            llista[0] = llista[i];
        }
    }
    return llista[i];
}

float Onenorm(float Mat[N][N])
{
    int j, llista[N], suma = 0;

    for (j = 0; j < N; j++)
    {
        suma += Mat[0][(fabs), j]; // valor absolut de cada element de la columna
        llista[suma];
    }
    for (j = 0; j < N; j++)
    {
        if (llista[0] < llista[j]) // busca el màxim
        {
            llista[0] = llista[j];
        }
    }
    return llista[j];
}

float NormFrobenius(float Mat[N][N]) // incloure -lm al compilar per l'arrel quadrada
{
    int suma = 0, resultat;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            suma += Mat[i ^ 2][j ^ 2];
        }
    }
    return resultat = sqrt(suma);
}

int DiagonalDom(float Mat[N][N])
{
    int suma = 0, x;
    int element = 0, diagonal = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                int x = fabs(Mat[i][j]);
                element++;
            }
            else
            {
                suma += fabs(Mat[i][j]);
            }
        }
        if (x > suma)
        {
            diagonal++;
        }
    }
    if (diagonal == element)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    InitData();

    // Visualització dels diferents vectors
    printf("El vector V1 de 0 a 9 és: \n");
    PrintVect(V1, 0, 9);
    printf("El vector V1 de 256 a 265 és: \n");
    PrintVect(V1, 256, 265);

    printf("El vector V2 de 0 a 9 és: \n");
    PrintVect(V2, 0, 9);
    printf("El vector V2 de 256 a 265 és: \n");
    PrintVect(V2, 256, 265);

    printf("El vector V3 de 0 a 9 és: \n");
    PrintVect(V3, 0, 9);
    printf("El vector V3 de 256 a 265 és: \n");
    PrintVect(V3, 256, 265);

    // Visualització de les dues matrius
    printf("La matriu Mat de la fila 0 és:\n");
    PrintRow(Mat, 0, 0, 9);

    printf("La matriu Mat de la fila 100 és:\n");
    PrintRow(Mat, 100, 0, 9);

    printf("La matriu MatDD de la fila 0 és:\n");
    PrintRow(MatDD, 0, 0, 9);
    printf("La matriu MatDD de la fila 100 és:\n");
    PrintRow(MatDD, 100, 90, 99);

    // Pas B: INFININORMA de Mat i MatDD
    int res_infini = Infininorm(Mat);
    printf("La infininorm de Mat és: %i \n", res_infini);
    int res_infini2 = Infininorm(MatDD);
    printf("La infininorm de MatDD és: %i \n", res_infini2);

    // Pas B: NORMA-Ú Mat i MatDD
    int res_onenorm = Onenorm(Mat);
    printf("La norma-ú de Mat és: %i \n", res_onenorm);
    int res_onenorm2 = Onenorm(MatDD);
    printf("La norma-ú de MatDD és: %i \n", res_onenorm2);

    // Pas B: NORMA FROBENIUS Mat i MatDD
    int res_frobenius = NormFrobenius(Mat);
    printf("La norma Frobenius de Mat és: %i \n", res_frobenius);
    int res_frobenius2 = NormFrobenius(MatDD);
    printf("La norma Frobenius de MatDD és: %i \n", res_frobenius2);

    // Pas B: DIAGONAL Mat i MatDD
    int res_diagonal = DiagonalDom(Mat);
    if (res_diagonal == 1)
    {
        printf("Mat és diagonal dominant \n");
    }
    else
    {
        printf("Mat NO és diagonal dominant \n");
    }

    int res_diagonal2 = DiagonalDom(MatDD);
    if (res_diagonal2 == 1)
    {
        printf("MattDD és diagonal dominant \n");
    }
    else
    {
        printf("MatDD NO és diagonal dominant \n");
    }

    // Pas C: PRODUCTES ESCALARS
    float res_scalar = Scalar(V1, V2);
    printf("El producte escalar de V1 i V2 és: %f \n", res_scalar);
    float res_scalar2 = Scalar(V1, V3);
    printf("El producte escalar de V1 i V3 és: %f \n", res_scalar2);
    float res_scalar3 = Scalar(V2, V3);
    printf("El producte escalar de V2 i V3 és: %f \n", res_scalar3);

    // Pas D: MAGNITUD AMB TOTS ELS VECTORS
    float res_magnitud = Magnitude(V1);
    printf("La funció magnitud V1 és: %f \n", res_magnitud);
    float res_magnitud2 = Magnitude(V2);
    printf("La funció magnitud V2 és: %f \n", res_magnitud2);
    float res_magnitud3 = Magnitude(V3);
    printf("La funció magnitud V3 és: %f \n", res_magnitud3);

    // Pas E: ORTOGONAL
    float res_ortogonal = Ortogonal(V1, V2);
    if (res_ortogonal == 0)
    {
        printf("V1 i V2 No és ortogonal \n");
    }
    else
    {
        printf("V1 i V2 És ortogonal \n");
    }

    float res_ortogonal2 = Ortogonal(V1, V3);
    if (res_ortogonal2 == 0)
    {
        printf("V1 i V3 No és ortogonal \n");
    }
    else
    {
        printf("V1 i V3 És ortogonal \n");
    }

    float res_ortogonal3 = Ortogonal(V2, V3);
    if (res_ortogonal3 == 0)
    {
        printf("V2 i V3 No és ortogonal \n");
    }
    else
    {
        printf("V2 i V3 És ortogonal \n");
    }

    // Pas F: MULTIPLICACIÓ VECTORS
    MultEscalar(V3, V4, 2.0);
    printf("El vector resultant del MultEscalar de 0 a 9 és:\n");
    PrintVect(V4, 0, 9);
    printf("El vector resultant del MultEscalar de 256 a 265 és:\n");
    PrintVect(V4, 256, 265);

    // Pas G: PROJECCIÓ
    for (int i = 0; i < 10; i++)
    {
        float res_projection = Projection(V2, V3, V4);
        printf("La projecció V2 i V3 és: %f \n", res_projection);
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        float res_projection2 = Projection(V1, V2, V4);
        printf("La projecció V1 i V2 és: %f \n", res_projection2);
    }
}
