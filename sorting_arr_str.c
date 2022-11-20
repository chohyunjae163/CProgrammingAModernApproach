// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem
int lexicographic_sort(const char* a, const char* b) {

    int a_len = 0, b_len = 0;
    while(a[a_len++] != '\0');
    while(b[b_len++] != '\0');
    
    int index = 0;
    while(index < a_len  || index < b_len)
    {
        int diff = a[index] - b[index];
        if(diff != 0)
        {
            return diff > 0 ? -1 : 1;
        }
        ++index;
    }
    if(a_len == b_len)
    {
        return 0;
    }
    return a_len > b_len ? 1 : -1;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -1 * lexicographic_sort(a,b);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int a_alphabets[26], b_alphabets[26];
    memset(a_alphabets,0,26 * sizeof(int));
    memset(b_alphabets,0,26 * sizeof(int));
    int a_len = 0, b_len = 0;
    while(a[a_len++] != '\0');
    while(b[b_len++] != '\0');
    
    for(int i = 0; i < a_len;++i)
    {
       a_alphabets[(int)a[i] - 97]++;
    }   
    
    for(int i = 0; i < b_len;++i)
    {
        b_alphabets[(int)b[i] - 97]++;
    }    
    int a_char_count = 0;
    int b_char_count = 0;
    for(int i = 0; i < 26; ++i)
    {
        a_char_count += !!(a_alphabets[i]);
    }
    for(int i = 0; i < 26; ++i)
    {
        b_char_count += !!(b_alphabets[i]);
    }
    
    if(a_char_count == b_char_count)
    {
        return lexicographic_sort(a,b);    
    }
    return a_char_count > b_char_count ? -1 : 1;
}
int sort_by_length(const char* a, const char* b) {
    int a_len = 0, b_len = 0;
    while(a[a_len++] != '\0');
    while(b[b_len++] != '\0');
    
    if( a_len == b_len)
    {
        return lexicographic_sort(a,b);
    }
    
    return a_len > b_len ? -1 : 1;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
    for(int i = 0; i < len - 1; ++i)
    {
        int ret = cmp_func(arr[i],arr[i + 1]);
        int j = i + 1;
        while(ret < 0)
        {
            char* temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            --j;
            if(j == 0)
            {
                break;
            }
            ret = cmp_func(arr[j - 1],arr[j]);
        }
    }
}
