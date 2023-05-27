
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"



int main()
{
	float **matrix1;
	float **matrix2;
	float **result_mul_matrix;
	unsigned int links1;
	unsigned int colums1;
	unsigned int links2;
	unsigned int colums2;
	int error_input;
	int true_input;
	int leave = 1;
	int true_result = 1;

	printf("\nАвтор:Марков Владислав\nГрупа:КН-922Б\nНомер лабараторної роботи:12\nТема:Взаємодія з користувачем шляхом механізму введення/виведення\n");

	printf("\nМноження матрць\n");
	
	//Цикл для запису розмірів матриць
	while (true_result == 1) {
	
		true_input = 1;
		while (true_input == 1) {
		
			printf("\n\nВведіть кількість строк та кількість стовпців через \":\" для першої матриці:");
			scanf("%d:%d", &links1, &colums1);
			
			printf("\nВведіть кількість строк та кількість стовпців через \":\" для другої матриці:");
			scanf("%d:%d", &links2, &colums2);

			if (colums1 != links2 || getchar() != ' ') {
				while (getchar() != ' ');
					

				printf("\n\nВи ввели незрозуміле значення!!!!");
				printf("\nЯк що ви хочите ввести значення ще раз введіть 1, для завершення операції введіть 0:");
				scanf("%d", &error_input);

				while (error_input < 0 || error_input >= 2) {
					printf("\nЯк що ви хочите ввести значення ще раз введіть 1, для завершення операції введіть 0:");
					scanf("%d", &error_input);
					while (getchar() != ' ');
						
				}

				if (error_input == 0) {
					leave = 0;
					true_input = 0;
				}
			} else
				true_input = 0;

			if (leave == 0)
				return 0;
		}

		
		//Цикл для запису 
		true_input = 1;
		while (true_input == 1) {
		
				//Виділяємо місце для запису елементів матриці
			matrix1 = malloc(sizeof(float *) * links1);
			for (unsigned int i = 0; i < links1; i++)
				*(matrix1 + i) = malloc(sizeof(float) * colums1);

			matrix2 = malloc(sizeof(float *) * links2);
			for (unsigned int i = 0; i < links2; i++)
				*(matrix2 + i) = malloc(sizeof(float) * colums2);
		
			printf("\nВведіть значення першої матриці по строках:");
			for (unsigned int i = 0; i < links1; i++) {
				for (unsigned int j = 0; j < colums1; j++)
					scanf("%f", &*(*(matrix1 + i) + j));
			}

			printf("\nВведіть значення другої матриці по строках:");
			for (unsigned int i = 0; i < links2; i++) {
				for (unsigned int j = 0; j < colums2; j++)
					scanf("%f", &*(*(matrix2 + i) + j));
			}

			if (getchar() != ' ') {
			
				while (getchar() != ' ');
					

				printf("\n\nВи ввели незрозуміле значення, або кількість введених вами значень не відповідає розмірам матриць!!!!");
				printf("\nЯк що ви хочите змінити розмір матриці то введіть 2, як що ще раз записати значення то 1, для завершення операції введіть 0:");
				scanf("%d", &error_input);

				while (error_input < 0 || error_input >= 3) {
					printf("\nЯк що ви хочите змінити розмір матриці то введіть 2, як що ще раз записати значення то 1, для завершення операції введіть 0:");
					scanf("%d", &error_input);
					while (getchar() != ' ');
				}

				if (error_input == 0) {
				
					leave = 0;
					true_input = 0;
					
					for (unsigned int i = 0; i < links1; i++) {
						free(*(matrix1 + i));	
					}
					free(matrix1);
					matrix1 = NULL;

					for (unsigned int i = 0; i < links2; i++) {
						free(*(matrix2 + i));	
					}
					free(matrix2);
					
				} else if (error_input == 2) {
				
					for (unsigned int i = 0; i < links1; i++) {
						free(*(matrix1 + i));
					}
					free(matrix1);
					
					for (unsigned int i = 0; i < links2; i++) {
						free(*(matrix2 + i));	
					}
					free(matrix2);
					
					true_input = 2;
				}

			} else 
				true_input = 0;
			

			if (leave == 0)
				return 0;
		}

		
		// Як що всі дані були введено коректно то множимо матриці і виводимо результат
		if (true_input == 0) {
		
			
			result_mul_matrix = malloc(sizeof(float *) * links1);
			for (unsigned int i = 0; i < links1; i++)
				*(result_mul_matrix + i) = malloc(sizeof(float) * colums2);

			mul_matrix(matrix1, matrix2, result_mul_matrix, links1, colums2, links2);
			
			printf("\n\nРезультат множення матриць");
			for (unsigned int i = 0; i < links1; i++) {
				printf("\n[");
				for (unsigned int j = 0; j < colums2; j++)
					printf(" %.2f\t", *(*(result_mul_matrix + i) + j));

				printf("\b]");
			}

			for (unsigned int i = 0; i < links1; i++) {
				free(*(matrix1 + i));
				free(*(result_mul_matrix + i));
			}
			free(matrix1);
			free(result_mul_matrix);

			for (unsigned int i = 0; i < links2; i++) {
				free(matrix2[i]);
			}
			free(matrix2);

			printf("\n\nЯк що ви хочите повторити операцію то введіть 1, для виходу з програми введіть 0:");
			scanf("%d", &true_result);
		}
	}

	return 0;
}
