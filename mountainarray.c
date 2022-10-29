//Runtime: 28 ms
//Memory Usage: 6.6 MB

int longestMountain(int* arr, int arrSize){
    // return the length of the longest subarray which is a mountain
    // mountain length shoud be at least 3.
    if(arrSize < 3) {
        return 0;
    }
    int max_length = 0;
    int index = 0;
    int i = 0;
    int j = 1;
    
    while(j < arrSize - 1)
    {
        
        //a mountain starts from increasing numbers
        if(arr[i] >= arr[j])
        {
            i++;
            j++;
            continue;
        }
        //increasing number from here
        int mountain_length = 2;
        int increasing = 0;
        int decreasing = 0;
        //ascending
        while(j + 1 < arrSize && arr[j] < arr[j+1])
        {
            increasing++;
            ++j;
        }
        //descending
        while(j + 1 < arrSize && arr[j] > arr[j +1])
        {
            decreasing++;
            ++j;
        }
        // decreasing numbers is required
        if(decreasing > 0)
        {
            mountain_length += increasing + decreasing;
            if(mountain_length > max_length)
            {
                max_length = mountain_length;
            }                        
        }

        i = j;
        j = i + 1;        
    } 
    return max_length;
}
