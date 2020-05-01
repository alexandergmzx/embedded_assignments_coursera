/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick & Alexander Gómez
 * @date April 1 2017
 *
 */
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

  uint8_t * tmp_dst = (uint8_t *)dst;
  uint8_t * tmp_src = (uint8_t *)src;

  uint8_t * tmp_P = (uint8_t *)malloc(length*sizeof(uint8_t));
  uint8_t * tmp_Ptr = (uint8_t *)tmp_P;

  for(size_t index = length; index > 0; index--){
    *tmp_Ptr++ = *tmp_src++;
  }// Copy the source information to a temporal pointed memory 

  tmp_Ptr = tmp_P;// Pass the temporal pointed information to the allocated memory

  for(size_t index = length; index > 0; index--){
    *tmp_dst++ = *tmp_Ptr++;
  }

  free(tmp_P);
  return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

  uint8_t * tmp_dst = (uint8_t *)dst;

  while(length > 0){
    *tmp_dst++ = *src++;
     length--;
  }

  return dst;

}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

  uint8_t * tmp_src = (uint8_t *)src;

  while(length > 0){
    *tmp_src++ = value;
     length--;
  }

  return src;
}


uint8_t * my_memzero(uint8_t * src, size_t length){

  uint8_t * tmp_src = (uint8_t *)src;

  while(length > 0){
    *tmp_src++ = 0;
    length--;
  }

  return src;
}


uint8_t * my_reverse(uint8_t * src, size_t length){

  uint8_t * tmp_src = (uint8_t *)src;

  uint8_t * tmp_P = (uint8_t *)malloc(length*sizeof(uint8_t));
  uint8_t * tmp_Ptr = (uint8_t *)tmp_P;

  for(size_t index = length; index > 0; index--){
    *tmp_Ptr++ = *tmp_src++;
  }

  tmp_src = (uint8_t *)src;
  tmp_Ptr--;

  for(size_t index = length; index > 0; index--){
    *tmp_src++ = *tmp_Ptr--;
  }

  free(tmp_P);
  return src;
}


int32_t * reserve_words(size_t length){
  return malloc(SIZE_OF_WORD*length);
}


void free_words(uint32_t * src){
  if(src != NULL) {
    free(src);
    src = NULL;
  }
}

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}
