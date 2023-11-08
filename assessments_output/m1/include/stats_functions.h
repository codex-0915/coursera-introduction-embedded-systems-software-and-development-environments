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
 * @file   stats_function.h
 * @brief  This is the header file for stats_function.c file 
 *
 * @author Kyl Justin Perez
 * @date   November 7, 2023
 *
 **/

#ifndef __STATS_FUNCTIONS_H__
#define __STATS_FUNCTIONS_H__

/********************************************************************************/
/********************************** Include Files *******************************/
/********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/********************************************************************************/
/************************************ Definitions *******************************/
/********************************************************************************/

/* Macros */
#define SIZE (40)  /* Size of the Data Set */

/********************************************************************************/
/************************************* Prototypes *******************************/
/********************************************************************************/

void print_array(unsigned char *array, int counter);
float find_mean(unsigned char *array, int counter);
unsigned int find_median(unsigned char *array, int counter);
void sort_array(unsigned char *array, int counter);

#endif /* __STATS_FUNCTIONS_H__ */

/*** End of File ***/