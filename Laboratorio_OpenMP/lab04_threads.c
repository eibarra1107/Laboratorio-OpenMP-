/******************************************************************************
*	* FECHA: 06/11/2025 
*	* AUTOR: ELIER IBARRA
*	* MATERIA: SISTEMAS OPERATIVOS - PONTIFICIA UNIVERSIDAD JAVERIANA
*	* DOCENTE: JOHN CORREDOR
*	* TEMA: CONFIGURACIÓN DE HILOS EN OPENMP
*	* DESCRIPCIÓN: Este programa permite configurar el número de hilos mediante un argumento
*	*              de línea de comandos y muestra el número total de hilos creados.
*	* INSTRUCCIONES DE COMPILACIÓN: gcc -std=c11 -Wall -Wextra -O2 -fopenmp lab04_threads.c -o lab04_threads
*	* INSTRUCCIONES DE EJECUCIÓN: ./lab04_threads 8
******************************************************************************/
#include <stdio.h>        // Incluye la biblioteca estándar para entrada/salida
#include <stdlib.h>       // Incluye la biblioteca estándar para conversión de argumentos
#include <omp.h>          // Incluye la biblioteca OpenMP para soporte de paralelismo

int main(int argc, char **argv) {  // Función principal con argumentos de línea de comandos
    if (argc > 1) {                // Verifica si se pasó un argumento
        int n = atoi(argv[1]);     // Convierte el argumento a entero
        if (n > 0 && n <= omp_get_max_threads()) omp_set_num_threads(n);  // Fija el número de hilos si es válido
    }

    printf("Máximo de hilos reportado: %d\n", omp_get_max_threads());  // Imprime el máximo de hilos disponibles

    #pragma omp parallel    // Directiva OpenMP para crear hilos paralelos
    {
        if (omp_get_thread_num() == 0) {  // Solo el hilo maestro (0) imprime
            printf("Se crearon %d hilos en total\n", omp_get_num_threads());  // Imprime el número total de hilos
        }
        printf("Hola desde el hilo %d\n", omp_get_thread_num());  // Cada hilo imprime su ID
    }
    return 0;  // Retorna 0 indicando éxito
}
