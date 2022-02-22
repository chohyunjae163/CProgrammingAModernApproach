/*
 * Name : main.c
 * Purpose : practice C programs
 * Author : Jay Cho
*/
#include <stdio.h>

/*
Write a program that uses printf to display the following picture on the screen
        *
       *
*     *
 *   *
  * *
   *
*/
void project_one() 
{
  printf("         *\n");
  printf("        *\n");
  printf("       *\n");
  printf("*     *\n");
  printf(" *   *\n");
  printf("  * *\n");
  printf("   *\n  ");
}
        
/*
   Write a program that computes the volume of a sphere with a 10-meter
   radius, using the formula v = 4/3(pi)r^3. Write the fraction 4/3 as
   4.0f / 3.0f. Hint: C doesn't have an exponentiation operator, so you'll
   need to multiply r by itself twice to compute r^3
*/

#define PI 3.141592

int pow(base, exp)
{
  if ( exp == 1)
  {
    return base;
  }
  else
  {
    return base * pow(base, exp -1);
  }
}

float project_two()
{
  float volume = ((4.0f)/(3.0f)) * (PI) * (pow(10,3));
  printf("volume: %3f\n", volume);
}

/*
  Modify the program of Project 2 so that it prompts the user to enter the daius of the sphere.
*/

float project_three()
{
  float r;
  printf("what is the radius?");
  scanf("%f", &r);
  float volume = ((4.0f)/(3.0f)) * (PI) * (pow(r,3));
  printf("volume: %3f\n", volume);
}

//write a program that asks the user to enter a dollars-and-cents amount, then displays the
//amount with 5% tax added
//W
float project_four()
{
  printf("Enter an amount: ");
  float amount = 0.0f;
  scanf("%f",&amount);
  float tax = amount * 0.05f;
  printf("With tax added: %.2f\n",amount + tax);
}

//¹²³⁴⁵⁶⁷⁸⁹⁰
// Write a program that asks the user to enter a value for x and then displays the value of 
// the following polynomial
// 3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6

float project_five()
{
  printf("enter a value: ");
  float x = 0;
  scanf("%f", &x);
  printf("3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6 = %f\n", ((3 * (pow(x,5))) + ( 2 * (pow(x,4))) - (5*(pow(x,3))) - (pow(x,2)) + (7*x) - 6));
}