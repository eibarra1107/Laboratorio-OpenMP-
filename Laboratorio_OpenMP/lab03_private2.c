/******************************************************************************
*	* FECHA: 06/11/2025 
*	* AUTOR: ELIER IBARRA
*	* MATERIA: SISTEMAS OPERATIVOS - PONTIFICIA UNIVERSIDAD JAVERIANA
*	* DOCENTE: JOHN CORREDOR
*	* TEMA: VARIABLES PRIVADAS EN OPENMP
*	* DESCRIPCIÓN: Este programa demuestra el efecto de hacer la variable b privada,
*	*              asegurando que el valor externo de b no cambie tras la ejecución paralela.
*	* INSTRUCCIONES DE COMPILACIÓN: gcc -std=c11 -Wall -Wextra -O2 -fopenmp lab03_private2.c -o lab03_private2
*	* INSTRUCCIONES DE EJECUCIÓN: export OMP_NUM_THREADS=4; ./lab03_private2
******************************************************************************/
#include <stdio.h>        // Incluye la biblioteca estándar para entrada/salida
#include <omp.h>          // Incluye la biblioteca OpenMP para soporte de paralelismo
#include <stdlib.h>       // Incluye la biblioteca estándar para funciones generales

int main(void) {          // Función principal sin argumentos
    int i;                // Declara variable de contador para el bucle
    const int N = 1000;   // Define el número total de iteraciones como constante
    int a = 50;           // Inicializa variable a con valor 50
    int b = 0;            // Inicializa variable b con valor 0

    #pragma omp parallel for private(i) private(a) private(b)  // Directiva OpenMP para bucle paralelo, todas las variables son privadas
    for (i = 0; i < N; ++i) {                                 // Bucle que itera N veces
        b = a + i;                                            // Asigna a b la suma de a e i (b es privada por hilo)
    }                                                         // Fin del bucle paralelo

    printf("a = %d  b = %d  (Se espera a = 50, b = 0)\n", a, b);  // Imprime los valores finales de a y b
    return 0;                                                     // Retorna 0 indicando éxito
}
