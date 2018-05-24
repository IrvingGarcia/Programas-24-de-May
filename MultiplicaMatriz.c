
/* Alumno: Irving Efren Garcia Ramos       */
/* E-mail: irvin.16@outlook.es             */
/* Fecha de Creaci�n: 14/05/2018           */
/* Fecha de actualizaci�n:                 */
/* Descripci�n: Multiplicacion de matrices */
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

bool ValidarMultiplicaMatriz(int colA, int filaB);
void leerDatosMatriz(int matriz[ROW][COL], int fila, int col);
void ImprimirMatriz(int matriz[ROW][COL], int fila, int col);
void MultiplicaMatriz(int matrizA[ROW][COL], int matrizB[ROW][COL], int matrizresultado[ROW][COL], int filaA, int colB);

int main(void)
{
    int filaA, colA;
    int filaB, colB;

    int matrizA[ROW][COL];
    int matrizB[ROW][COL];
    int matrizresultado[ROW][COL];

    printf("\nIntroduzca la fila de la matriz A: ");
    scanf("%d", &filaA);

    printf("\nIntroduzca la fila de la matriz A: ");
    scanf("%d", &colA);

    printf("\nIntroduzca la fila de la matriz B: ");
    scanf("%d", &filaB);

    printf("\nIntroduzca la fila de la matriz B: ");
    scanf("%d", &colB);

    if(ValidarMultiplicaMatriz(colA, filaB))
    {
        leerDatosMatriz(matrizA,filaA,colA);
        leerDatosMatriz(matrizB, filaB, colB);

        ImprimirMatriz(matrizA,filaA,colA);
        ImprimirMatriz(matrizB, filaB, colB);

        MultiplicaMatriz(matrizA, matrizB, matrizresultado, filaB, colA);
        printf("\nEl resultado de la suma es: \n");


        ImprimirMatriz(matrizresultado, filaA, colB);

    }
    else
    {
        printf("\nNo se puede realizar la suma de matrices\n");
    }


    return 0;
}

void MultiplicaMatriz(int matrizA[ROW][COL], int matrizB[ROW][COL], int matrizresultado[ROW][COL], int filaB, int colA)
{
    for (int i = 0; i < filaB; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            int suma = 0;
            for(int k = 0; k < filaB; k++)
            {
                suma = suma + matrizA[i][k] * matrizB[k][i];
            }
            matrizresultado[i][j] = suma;
        }
    }


}

void leerDatosMatriz(int matriz[ROW][COL], int fila, int col)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("\nIntroduce el elemento [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void ImprimirMatriz(int matriz[ROW][COL], int fila, int col)
{
    printf("\n\n");
    for (int i = 0; i < fila; i++)
    {
        printf("|");
        for (int j = 0; j < col; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("| \n");
    }
}

bool ValidarMultiplicaMatriz(int colA, int filaB)
{
    if (colA == filaB)
    {
        return true;
    }
return false;
}
