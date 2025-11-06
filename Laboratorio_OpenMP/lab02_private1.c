/******************************************************************************
*	* FECHA: 06/11/2025 
*	* AUTOR: ELIER IBARRA
*	* MATERIA: SISTEMAS OPERATIVOS - PONTIFICIA UNIVERSIDAD JAVERIANA
*	* DOCENTE: JOHN CORREDOR
*	* TEMA: VARIABLES PRIVADAS EN OPENMP
*	* DESCRIPCIÓN: Este programa ilustra el uso de variables privadas (i y a) en OpenMP,
*	*              dejando b como compartida, lo que genera una condición de carrera.
*	* INSTRUCCIONES DE COMPILACIÓN: gcc -std=c11 -Wall -Wextra -O2 -fopenmp lab02_private1.c -o lab02_private1
*	* INSTRUCCIONES DE EJECUCIÓN: export OMP_NUM_THREADS=4; ./lab02_private1
******************************************************************************/
#include <stdio.h>        // Incluye la biblioteca estándar para entrada/salida
#include <omp.h>          // Incluye la biblioteca OpenMP para soporte de paralelismo
#include <stdlib.h>       // Incluye la biblioteca estándar para funciones generales

int main(void) {          // Función principal sin argumentos
    int i;                // Declara variable de contador para el bucle
    const int N = 1000;   // Define el número total de iteraciones como constante
    int a = 50;           // Inicializa variable a con valor 50
    int b = 0;            // Inicializa variable b con valor 0

    #pragma omp parallel for private(i) private(a)  // Directiva OpenMP para bucle paralelo, i y a son privadas
    for (i = 0; i < N; ++i) {                      // Bucle que itera N veces
        b = a + i;                                 // Asigna a b la suma de a e i (condición de carrera por b compartida)
    }                                              // Fin del bucle paralelo

    printf("a = %d  b = %d  (Se espera a = 50, b ≈ 1049)\n", a, b);  // Imprime los valores finales de a y b
    return 0;                                                             // Retorna 0 indicando éxito
}
