

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>


void mul_matrix(float **matrix1, float **matrix2, float **result_mul_matrix, unsigned int links1, unsigned int colums2, unsigned int links2)
{
	for (unsigned int i = 0; i < links1; i++) {
		for (unsigned int j = 0; j < colums2; j++) {
			
			*(*(result_mul_matrix + i) + j) = 0;
			
			for (unsigned int f = 0; f < links2; f++) {
				*(*(result_mul_matrix + i) + j) += *(*(matrix1 + i) + f) * *(*(matrix2 + f) + j);
			}
		}
	}

}
