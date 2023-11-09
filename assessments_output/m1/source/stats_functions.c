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

void print_statistics(unsigned int minimum, unsigned int maximum, 
						float mean, float median)
{
	printf("Printing array's statistics...\n");
	printf("Minimum: %d\n", minimum);
	printf("Maximum: %d\n", maximum);
	printf("Mean: %f\n", mean);
	printf("Median: %f\n\n", median);
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

	if (EVEN_REMAINDER == element_count % EVEN_OR_ODD_DIVISOR)
	{
		median = ((array[element_count / SPLIT_AT_MIDDLE]) + 
					(array[(element_count / SPLIT_AT_MIDDLE) + NEXT_INDEX]) 
					/ SPLIT_AT_MIDDLE);
	}

	else
	{
		median = array[(element_count + 1) / SPLIT_AT_MIDDLE];
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
	return array[element_count - NEXT_INDEX];
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
			if (array[loop_counter] > array[loop_counter + NEXT_INDEX] 
				|| array[loop_counter] == array[loop_counter + NEXT_INDEX])
			{
				continue;
			}
			else if (array[loop_counter] < array[loop_counter + NEXT_INDEX])
			{
				temp_val = array[loop_counter];
				array[loop_counter] = array[loop_counter + NEXT_INDEX];
				array[loop_counter + NEXT_INDEX] = temp_val;

				flag = CHANGED_FLAG; 
			}
		}
	}
	while (CHANGED_FLAG == flag); 
}

/*** End of File ***/