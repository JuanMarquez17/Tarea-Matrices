/*Fecha: 26/03/2022
* Autor:Juan Camilo Marquez
* Subject: Parallel and Distributed Computing.
* Topic: Poxis implemetation (Library)
* Description: Application for matrix multiplication
  with the classical algorithm (rows x columns) using
  global variables. Also, using the following functions:
    1. Creation of double pointer variables for matrices
    2. Memory reserve for double pointer matrices
    3. Init matrix
    4. Function for the matrix's product:
        4.1.1 The matrix A is divide and those portions 
        will be sent to an individual thread
        4.1.2 The matrix's size will be sent in the 
        execution.
    5. Matrix's size always squared (NxN)
    6.  Print matrix with double pointer.
*/


/*Interfaces*/
#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

/*  @breif main(): Main function
*/
int main(int argc, char* argv[]){



     struct arg_struct args;

    if (argc!=3){
        printf("./MMPosix <matrix size> <# of threads>\n");
        return -1;
    }

    /*Init of global variables*/
    args.N           = atof(argv[1]);    /* Matrix's size.*/
    args.Nthreads    = atof(argv[2]);    /* Number of threads.*/
    
    pthread_t *threads=(pthread_t*)malloc(args.N*sizeof(pthread_t));//Thread reservation
    /*Memory creation and reserce for each matrix*/
    args.Ma = memReserve(args.N); 
    args.Mb = memReserve(args.N);
    args.Mc = memReserve(args.N);
    initMatrix_DoublePointers (args.Ma, args.Mb, args.Mc, args.N);
    if (args.N<4){
        printf("Matriz A\n");
        printMatrix_DoublePointers (args.Ma, args.N);
        printf("Matriz B\n");
        printMatrix_DoublePointers (args.Mb, args.N);
    }
    sampleStart();
    for (int i = 0; i < args.Nthreads; ++i){
        args.idThread=i;
        pthread_create(&threads[i],NULL,&multMM,(void *)&args);
    }
    for (int i = 0; i < args.Nthreads; ++i){
        pthread_join(threads[i],NULL);
    }
    sampleEnd();
    free(threads);
    if (args.N<4){
        printf("Matriz C\n");
        printMatrix_DoublePointers (args.Mc, args.N);
    }

    return 0;
}
