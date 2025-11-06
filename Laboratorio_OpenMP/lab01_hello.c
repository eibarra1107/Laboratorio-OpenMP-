/******************************************************************************
*	* FECHA: 06/11/2025 
*	* AUTOR: ELIER IBARRA
*	* MATERIA: SISTEMAS OPERATIVOS - PONTIFICIA UNIVERSIDAD JAVERIANA
*	* DOCENTE: JOHN CORREDOR
*	* TEMA: INTRODUCCIÓN A OPENMP
*	* DESCRIPCIÓN: Este programa demuestra el uso básico de OpenMP creando un equipo de hilos
*	*              que imprimen un mensaje "Hello World" junto con su ID de hilo.
*	* INSTRUCCIONES DE COMPILACIÓN: gcc -std=c11 -Wall -Wextra -O2 -fopenmp lab01_hello.c -o lab01_hello
*	* INSTRUCCIONES DE EJECUCIÓN: ./lab01_hello
******************************************************************************/
#include <stdio.h>        // Incluye la biblioteca estándar para entrada/salida
#include <omp.h>          // Incluye la biblioteca OpenMP para soporte de paralelismo

int main(void) {          // Función principal sin argumentos
    printf("OpenMP ejecutando (máximo) con %d hilos\n", omp_get_max_threads());  // Imprime el número máximo de hilos disponibles
    #pragma omp parallel    // Directiva OpenMP para crear hilos paralelos
    {
        printf("Hello World desde el thread %d\n", omp_get_thread_num());  // Cada hilo imprime su identificador lógico
    }                                                                         // Fin del bloque paralelo
    return 0;                                                                 // Retorna 0 indicando éxito
}
