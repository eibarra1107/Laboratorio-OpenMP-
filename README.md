# Laboratorio-OpenMP-
 **Autor:** Elier Ibarra  
> **Docente:** John Corredor  
> **Fecha:** 06/11/2025

## 🎯 Objetivos
- Familiarizarse con directivas básicas de OpenMP (`parallel`, `for`, `private`, `reduction`).
- Entender el alcance de variables privadas/compartidas.
- Medir desempeño con `omp_get_wtime()`.
## 🛠️ Requisitos
- **GCC** con soporte **OpenMP**
- **make**
- Sistema tipo Unix
## 🔬 Descripción de prácticas
-lab01_hello.c — Hola Mundo paralelo
 Crea una región #pragma omp parallel y cada hilo imprime su ID.
 Observa que el orden de impresión no está garantizado (no hay sincronización).
 lab02_private1.c — Variables y condición de carrera
 i y a son privadas, pero b es compartida.
 Todos los hilos escriben en b → condición de carrera y valor final no determinista.
-lab03_private2.c — Arreglo correcto del alcance
 b es privada dentro del for paralelo.
 El b externo permanece sin cambios → comportamiento determinista.
-lab04_threads.c — Control del equipo de hilos
 Acepta N por CLI (./lab04_threads N) y ajusta hilos con omp_set_num_threads.
 Muestra el máximo reportado y el número real de hilos en la región.
-sum_sin.c — Reducción paralela con cronometraje
 Calcula Σ sin(a + k) (con a=50) usando #pragma omp for reduction(+:sum).
 Reporta tiempo total, repeticiones y equipo de hilos.
 Es tu banco de pruebas para escalar y experimentar schedule.

