/******************************************************************************
*	* FECHA: 06/11/2025 
*	* AUTOR: ELIER IBARRA
*	* MATERIA: SISTEMAS OPERATIVOS - PONTIFICIA UNIVERSIDAD JAVERIANA
*	* DOCENTE: JOHN CORREDOR
*	* TEMA: CÁLCULO DE SUMATORIAS CON OPENMP
*	* DESCRIPCIÓN: Este programa calcula la sumatoria de sin(a + k) en paralelo usando OpenMP,
*	*              permitiendo configurar el número de hilos y repeticiones, y midiendo el tiempo de ejecución.
*	* INSTRUCCIONES DE COMPILACIÓN: gcc -std=c11 -Wall -Wextra -O2 -fopenmp sum_sin.c -o sum_sin -lm
*	* INSTRUCCIONES DE EJECUCIÓN: ./sum_sin 8 30000
******************************************************************************/
#include <stdio.h>        // Incluye la biblioteca estándar para entrada/salida
#include <stdlib.h>       // Incluye la biblioteca estándar para conversión de argumentos
#include <math.h>         // Incluye la biblioteca matemática para la función seno
#include <omp.h>          // Incluye la biblioteca OpenMP para soporte de paralelismo

#define MIN(x, y) ((x) < (y) ? (x) : (y))  // Define una macro para obtener el mínimo de dos valores

double f(int start, int finish) {  // Función que calcula la sumatoria parcial de sin(a + j)
    double return_val = 0.0;      // Inicializa el valor de retorno
    int a = 50;                   // Valor inicial de 'a' como en las diapositivas
    for (int j = start; j < finish; j++) {  // Itera desde start hasta finish
        return_val += sin((double)(a + j));  // Acumula el valor de sin(a + j)
    }
    return return_val;  // Retorna la sumatoria parcial
}

int main(int argc, char **argv) {  // Función principal con argumentos de línea de comandos
    int threads = 0;               // Variable para el número de hilos (0 usa el valor por defecto)
    long reps = 30000;             // Valor inicial de repeticiones
    int a = 50;                    // Valor inicial de 'a'

    if (argc < 2) {                // Verifica si se pasó al menos un argumento
        printf("Error\n%s <numHilos> [numRepeticiones]\n", argv[0]);  // Muestra mensaje de error
        exit(1);  // Termina el programa con error
    }

    threads = atoi(argv[1]);      // Convierte el primer argumento a entero (número de hilos)
    if (argc >= 3) reps = atol(argv[2]);  // Convierte el segundo argumento a long (repeticiones)

    if (threads <= 0) {           // Valida que el número de hilos sea positivo
        printf("Número de hilos debe ser positivo. Usando valor por defecto.\n");
        threads = omp_get_max_threads();  // Usa el máximo disponible si inválido
    }
    if (reps <= 0) reps = 30000;  // Asegura que las repeticiones sean positivas

    omp_set_num_threads(threads);  // Fija el número de hilos

    double t0 = omp_get_wtime();  // Registra el tiempo inicial
    double sum = 0.0;             // Inicializa la sumatoria

    #pragma omp parallel    // Directiva OpenMP para crear hilos paralelos
    {
        int num_threads = omp_get_num_threads();  // Obtiene el número de hilos
        #pragma omp master  // Solo el hilo maestro ejecuta este bloque
        printf("Número de Hilos: %d\n", num_threads);  // Imprime el número de hilos

        #pragma omp for reduction(+:sum)  // Bucle paralelo con reducción de sum
        for (long i = 0; i < reps; i++) {  // Itera sobre las repeticiones
            sum += f(i, MIN(i + 1, reps));  // Acumula la sumatoria parcial
        }
    }

    double t1 = omp_get_wtime();  // Registra el tiempo final
    printf("La sumatoria es: %.15f\n", sum);  // Imprime la sumatoria
    printf("Tiempo total = %.6f s\n", (t1 - t0));  // Imprime el tiempo total
    printf("Repeticiones = %ld\n", reps);  // Imprime el número de repeticiones
    printf("Hilos usados = %d\n", omp_get_max_threads());  // Imprime el máximo de hilos disponibles (referencia)
    return 0;  // Retorna 0 indicando éxito
}
