
char* alphabetize(char* s)
{
    int s_len = 0;
    while(s[s_len] != '\0')
    {
        s_len = s_len + 1;
    }

    int alphabets[26] = { 0 };

    for( int i = 0; i < s_len; ++i)
    {
        alphabets[s[i] - 'a'] += 1;
    }

    s_len = 0;
    for(int i = 0; i < 26; ++i)
    {
        for(int j = 0; j < alphabets[i]; ++j)
        {
            char c = (char)(i + 'a');
            *(s + s_len) = c;
            s_len++;
        }
    }

    return s;
}

int compare(char* s1, char* s2)
{
    int index = 0;
    while(s1[index] != '\0' || s2[index] != '\0')
    {
        if(s1[index] != s2[index])
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
int isAnagram(char* s1, char* s2)
{
    char* new_s1 = alphabetize(s1);
    char* new_s2 = alphabetize(s2);

    int bAnagram = compare(new_s1,new_s2);

    return bAnagram;
}

int sherlockAndAnagrams(char* s) {
    int s_len = 0;
    while(s[s_len] != '\0')
    {
        s_len = s_len + 1;
    }

    int anagram_count = 0;
    for(int i = 0; i < s_len - 1; ++i)
    {
        int sub_s_len = i + 1;
        for(int j = 0; j < s_len;++j)
        {
            char sub_s1[sub_s_len + 1];
            memset(sub_s1,0,sub_s_len + 1);
            memcpy(sub_s1,s + j,sub_s_len);
            for(int k = j + 1; k < s_len - i;++k)
            {
                char sub_s2[sub_s_len + 1];
                memset(sub_s2,0,sub_s_len + 1);
                memcpy(sub_s2,s + k,sub_s_len);
                anagram_count += isAnagram(sub_s1, sub_s2);
            }
            memset(sub_s1,0,sub_s_len);
        }
    }


    return anagram_count;
}
