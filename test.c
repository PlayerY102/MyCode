#include "stdio.h" 
#include "stdlib.h" 
#include "windows.h"
#define SIZE 16384 
#define N 128

typedef struct
{
    int real_part;
    int imag_part;
} complex;

complex matrix_1[N][N];
complex matrix_2[N][N];

void init()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrix_1[i][j].real_part = rand() % 1721;
            matrix_1[i][j].imag_part = rand() % 1721;
        }
    }
}

void rotate()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N-1; j+=2)
        {
            matrix_2[j][i] = matrix_1[i][j];
            matrix_2[j+1] [i] = matrix_1[i][j+1];
        }
    }
    if(j<N){
        matrix_2[j][i] = matrix_1[i][j];
    }
}

void accumulate_sum(complex *sum, complex p)
{
    sum->real_part += p.real_part;
    sum->imag_part += p.imag_part;
}

complex average(int i, int j, complex matrix[][N])
{
    int ii, jj;
    complex sum;
    complex sum2;
    sum.imag_part = 0;
    sum.real_part = 0;
    sum2.imag_part = 0;
    sum2.real_part = 0;
    int edge1=min(i + 1, N - 1);
    int edge2=min(j + 1, N - 1);
    for (ii = max(i - 1, 0); ii <= edge1; ii++)
    {
        for (jj = max(j - 1, 0); jj < edge2; jj+=2)
        {
            accumulate_sum(&sum, matrix[ii][jj]);
            accumulate_sum(&sum2,matrix[ii][jj+1]);
        }
    }
    if(jj<=edge2){
        accumulate_sum(&sum,matrix[ii][jj]);
    }
    sum.real_part=(sum.real_part+sum2.real_part)/2;
    sum.imag_part=(sum.imag_part+sum2.imag_part)/2;
    return sum;
}

void smooth()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N-1; j+=2)
        {
            matrix_1[i][j] = average(i, j,matrix_2);
            matrix_1[i][j+1] = average(i, j+1,matrix_2);
        }
    }
    if(j<N){
        matrix_1[i][j] = average(i, j,matrix_2);
    }
}

int main()
{
    init(); /* To set time counter */
    double run_time;
    LARGE_INTEGER time_start;
    LARGE_INTEGER time_over;
    double dqFreq;
    LARGE_INTEGER f;
    QueryPerformanceFrequency(&f);
    dqFreq = (double)f.QuadPart;
    QueryPerformanceCounter(&time_start); // Time counter starts

    rotate();
    smooth();
    QueryPerformanceCounter(&time_over);                                      // Time counter ends
    run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq; // To calculate running time

    printf("run_time:%fus\n", run_time);
    return 0;
}