/*Fecha: 08/02/2022
* Autor: Juan Camilo Márquez
* Subject: Parallel and Distributed Computing.
* Topic: Construction of the first Benchmark
* Description: Application that allows evaluating the performance
  of a specific aspect of the computer using matrix multiplication
  with the calssical algorithm (rows x columns)
*/

#ifndef MODULO_C_H_INCLUDE
#define MODULO_C_H_INCLUDE

struct arg_struct { 
     int N;
     int Nthreads;
     double **Ma;
     double **Mb;
     double **Mc;
     int idThread;
    };

void sampleStart();
void sampleEnd();
double randNumber();
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr);
void printMatrix(int SZ, double *M);
void matrixMultiplyMM1c(int size, double *Ma, double *Mb, double *Mr);
void matrixMultiplyMM1f(int size, double *Ma, double *Mb, double *Mr);
double ** memReserve (int size);
void initMatrix_DoublePointers (double **MA, double **MB, double **MC, int size);
void printMatrix_DoublePointers (double **M, int size);
void *multMM(void *arg);
#endif
