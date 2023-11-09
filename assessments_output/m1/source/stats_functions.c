/********************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *******************************************************************************/
 
/**
 * @file   stats_functions.c
 * @brief  Module for the required functions used in stats.c 
 *
 * @author Kyl Justin Perez
 * @date   November 7, 2023
 *
 **/

/********************************************************************************/
/********************************** Include Files *******************************/
/********************************************************************************/

#include "../include/stats_functions.h"

/********************************************************************************/
/***************************** Stats Functions Program **************************/
/********************************************************************************/

/********************************************************************************
 * Function:
 *
 * Description:
 * 
 * Parameters:
 * 
 * Return:
 *
 *******************************************************************************/

void print_array(unsigned char *array, int counter)
{
	printf("Printing all data...\n");
	printf("[");
	for (int loop_count = 0; loop_count < counter; loop_count++)
	{
		printf(" %d ", array[loop_count]);
	}
	printf("]\n\n");
}

/********************************************************************************
 * Function:
 *
 * Description:
 * 
 * Parameters:
 * 
 * Return:
 *
 *******************************************************************************/

float find_median(unsigned char *array, int element_count)
{
	float median = 0;

	if (0 == element_count % 2)
	{
		median = ((array[element_count / 2]) + (array[(element_count / 2) + 1]) / 2);
	}

	else
	{
		median = array[(element_count + 1) / 2];
	}

	return median;

}

/********************************************************************************
 * Function:
 *
 * Description:
 * 
 * Parameters:
 * 
 * Return:
 *
 *******************************************************************************/

float find_mean(unsigned char *array, int counter)
{
	/* Initialize variables */
	int sum = 0;
	float mean = 0;

	for (int loop_count = 0; loop_count < counter; loop_count++)
	{
		sum += array[loop_count];
	}

	/* Calculate for the array's mean */
	mean = sum / ((float)SIZE);

	return mean;
}

/********************************************************************************
 * Function:
 *
 * Description:
 * 
 * Parameters:
 * 
 * Return:
 *
 *******************************************************************************/

unsigned int find_maximum(unsigned char *array, int element_count)
{
	return array[INITIAL_INDEX];
}

/********************************************************************************
 * Function:
 *
 * Description:
 * 
 * Parameters:
 * 
 * Return:
 *
 *******************************************************************************/

unsigned int find_minimum(unsigned char *array, int element_count)
{
	return array[element_count - 1];
}

/********************************************************************************
 * Function:
 *
 * Description:
 * 
 * Parameters:
 * 
 * Return:
 *
 *******************************************************************************/

void sort_array(unsigned char *array, int counter)
{
	/* Initialize variables */
	int flag = 0; 
	unsigned char temp_val = 0;

	do {
		flag = 0; // set flag to default at every new 'do' operation
		for (int loop_counter = 0; loop_counter < counter; loop_counter++){
			if (array[loop_counter] > array[loop_counter + 1] 
				|| array[loop_counter] == array[loop_counter + 1])
			{
				continue;
			}
			else if (array[loop_counter] < array[loop_counter + 1])
			{
				temp_val = array[loop_counter];
				array[loop_counter] = array[loop_counter + 1];
				array[loop_counter + 1] = temp_val;

				flag = 1; 
			}
		}
	}
	while (flag == 1); 
}

/*** End of File ***/