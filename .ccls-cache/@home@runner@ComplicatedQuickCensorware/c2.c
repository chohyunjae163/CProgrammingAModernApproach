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

/*
 * Modify the program of Programming Project 5 so that the polynomial is evaluated using hte
 * following fomula
 * ((((3x + 2)x - 5)x -1)x + 7)x -6
*/

float project_six()
{
  printf("enter a value: ");
  float x = 0;
  scanf("%f", &x);
  printf("((((3x + 2)x - 5)x -1)x + 7)x -6 = %f\n",(((((3*x +2)*x -5)*x -1)*x + 7)*x - 6));
}

/*
 * Write a program taht asks the user to enter a U.S. dollar amout and shows how to pay that amount
 * using the smallest number of $20, $10, $5 and $1 bills:
 *
*/

#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1

void project_seven()
{
  printf("enter a value: ");
  int amount = 0;
  scanf("%d", &amount);
  int twenty_dollar_bill = 0;
  int ten_dollar_bill  = 0;
  int five_dollar_bill = 0;
  int one_dollar_bill = 0;
  if( amount >= TWENTY)
  {
    twenty_dollar_bill = amount / TWENTY;
    amount -= (twenty_dollar_bill * TWENTY);
  }

  if(amount >= TEN)
  {
    ten_dollar_bill = amount / TEN;
    amount -= (ten_dollar_bill * TEN);
  }

  if(amount >= FIVE)
  {
    five_dollar_bill = amount / FIVE;
    amount -= (five_dollar_bill * FIVE);
  }

  if(amount >= ONE)
  {
    one_dollar_bill = amount / ONE;
  }

  printf("$20 bills : %d\n", twenty_dollar_bill);
  printf("$10 bills : %d\n", ten_dollar_bill);
  printf("$5 bills : %d\n", five_dollar_bill);
  printf("$1 bills : %d\n", one_dollar_bill);
    
}

/*
 * Write a program that calculates teh remaining balance on a loan after the fisrt, second and
 * third monthly payments.
 * Display each balance with two digists after the decimal point
*/

void project_eight()
{
  float loan = 0;
  scanf("%2f", &loan);
  printf("enter amount of loan: %2f\n",loan);

  float interest = 0;
  scanf("%2f", &interest);
  printf("enter interest rate: %2f\n",interest);
  
  float payment = 0;
  scanf("%2f", &payment);
  printf("enter monthly payment: %2f\n",payment);
  
  
  printf("\n\n");
  
  loan -= payment;
  printf("Balance remaining after first payment: %2f\n",loan);
  loan += (loan * 0.06);
  loan -= payment;
  printf("Balance remaining after second payment: %2f\n",loan);
  loan += (loan * 0.06);
  loan -= payment;
  printf("Balance remaining after third payment: %2f\n",loan);
}