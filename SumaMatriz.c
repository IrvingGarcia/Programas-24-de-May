/* Alumno: Irving Efren Garcia Ramos */
/* E-mail: irvin.16@outlook.es       */
/* Fecha de Creación: 14/05/2018     */
/* Fecha de actualizacion:           */
/* Descripción: Suma de matrices     */


#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

bool ValidarSumaMatriz(int filaA,int colA, int filaB, int colB);
void leerDatosMatriz(int matriz[ROW][COL], int fila, int col);
void ImprimirMatriz(int matriz[ROW][COL], int fila, int col);
void SumarMatriz(int matrizA[ROW][COL], int matrizB[ROW][COL], int matrizresultado[ROW][COL], int fila, int col);

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

  if(ValidarSumaMatriz(filaA, colA, filaB,colB))
  {
    leerDatosMatriz(matrizA,filaA,colA);
    leerDatosMatriz(matrizB, filaB, colB);

    ImprimirMatriz(matrizA,filaA,colA);
    ImprimirMatriz(matrizB, filaB, colB);

    SumarMatriz(matrizA, matrizB, matrizresultado, filaA, colA);
    printf("\nEl resultado de la suma es: \n");


    ImprimirMatriz(matrizresultado, filaA, colB);

  }
  else
  {
    printf("\nNo se puede realizar la suma de matrices\n");
  }


  return 0;
}

void SumarMatriz(int matrizA[ROW][COL], int matrizB[ROW][COL], int matrizresultado[ROW][COL], int fila, int col)
{
  for (int i = 0; i < fila; i++ )
  {
      for (int j = 0; j < col; j++)
      {
        matrizresultado[i][j] = matrizA[i][j] + matrizB[i][j];
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

bool ValidarSumaMatriz(int filaA, int colA, int filaB, int colB)
{
  if ((filaA == filaB) && (colA == colB))
  {
    return true;
  }
    return false;
}
