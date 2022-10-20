#include <stdio.h>


void quicksort(int numbers[], int low, int high)
{
	int len = high - low;
	//no need to sort when the length is zero.
	if(len < 1)
	{
		return;
	}
	int left = low;
	int right = high;
	
	//Choose the first element of the array to be the pivot.
	int pivot = left;
	while(left < right)
	{
		//when pivot is left, find a small element from the right and swap.
		if(left == pivot)
		{
			while(numbers[pivot] < numbers[right])
			{
				--right;
			}
			
			//swap
			int temp = numbers[right];
			numbers[right] = numbers[pivot];
			numbers[pivot] = temp;
			pivot = right;
		}

		if(right == pivot)
		{
			while(numbers[pivot] > numbers[left])
			{
				++left;
			}
			
			//swap
			int temp = numbers[left];
			numbers[left] = numbers[pivot];
			numbers[pivot] = temp;
			pivot = left;
		}
	}
	
	printf("\n================== sorting...\n");
	for (int  i = 0; i < 7; ++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
	quicksort(numbers,0,pivot - 1);
	quicksort(numbers,pivot + 1, high);

}

int main()
{
	int numbers[7] = { 1,8,3,9,4,5,7};
	printf("\n================== unsorted:\n");
	for (int  i = 0; i < 7; ++i)
	{
		printf("%d ",numbers[i]);
	}
	quicksort(numbers,0,6);
	printf("\n================== sorted:\n");
	for (int  i = 0; i < 7; ++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
	return 0;
}
