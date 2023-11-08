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

void print_array(unsigned char *array)
{
	printf("--------------Printing all data---------------\n");
	printf("[");
	for (int loop_count = 0; loop_count < SIZE; loop_count++)
	{
		printf(" %d ", array[loop_count]);
	}
	printf("]\n");
	printf("-------------------------------------------\n\n");
}

/*** End of File ***/