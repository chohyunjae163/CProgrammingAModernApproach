/*
 * Name : main.c
 * Purpose : practice C programs
 * Author : Jay Cho
*/
#include <stdio.h>


/*
 * Computes the dimensional weight of a box from 
 * input provided by the user
 * C Programming A Modern Approach by K.N. King
*/

#define INCHES_PER_POUND 166

int main(void) /*The Beginning of the program*/
{
  int height, length, width, volume, weight;

  printf("Enter height of box:");
  scanf("%d",&height);
  printf("Enter length of box:");
  scanf("%d",&length);
  printf("Enter width of box:");
  scanf("%d",&width);
  volume = height * length * width;
  weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

  printf("Volume (cubic inches) : %d\n",volume);
  printf("Dimensional weight (pounds) : %d\n",weight);

  return 0;
}