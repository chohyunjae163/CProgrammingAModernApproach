// author : hyunjaecho
// date: 2022-11-09
// content: a rosettacode task
// Link : https://rosettacode.org/wiki/Binary_strings

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	unsigned int len;
	char* s;
} String;

//스트링 길이 구하기 함수
size_t get_strlen(const char* s)
{
    const char* p = s;
    while(*s)
    {
        s++;
    }
    return s - p;
}

//String creation and destruction (when needed and if there's no garbage collection or similar mechanism)
String* create_string(int length)
{
	String* newString = (String*)malloc(sizeof(String));
	newString->s = (char*)malloc(length + 1);
	newString->len = 0;
	memset(newString->s,0,length);
	return newString;
}

void delete_string(String* s)
{
	free(s->s);
	free(s);
}

//String assignment
void assign_string(String* s, const char* str)
{
    int length = get_strlen(str);
	if(s->len < length)
	{
		s->s = realloc(s->s, length + 1);
	}
	memcpy(s->s,str,length);
	s->len = length;
}

//String comparison
int compare_string(String* s1, String* s2)
{
	if(s1->len != s2->len)
	{
		return 0;
	}
	int index  = 0;

	while(s1->s[index] || s2->s[index])
	{
		if(s1->s[index] != s2->s[index])
		{
			return 0;
		}
		index++;
	}

	return 1;
}

//String cloning and copying
String* clone_string(String* s)
{
	String* clone = create_string(s->len);
	assign_string(clone,s->s);
	return clone;
}

//Check if a string is empty
int is_empty_string(String* s)
{
	return s->len == 0;
}

//Append a byte to a string
void append_char(String* s, char c)
{
	s->s = realloc(s->s, s->len + 1);
	s->s[s->len] = c;
	s->len += 1;
}

//Extract a substring from a string
String* extract_substring(char* s, int from, int to)
{
	int len = to - from;
	String* slice = create_string(len + 1);
	assign_string(slice,s + from);
	return slice;
}

//Replace every occurrence of a byte (or a string) in a string with another string
String* replace_substring(String* s, const char* old, const char* new)
{

	int old_len = 0, new_len = 0;
	while(old[old_len++]);
	while(new[new_len++]);

	int occurence_count = 0;
	int index = 0;
	//바뀌는 스트링 새로운 길이 구하기
	while(index < s->len)
	{
		int old_index = 0;
		int count = 0;
		while(count < old_len && old[old_index++] == s->s[index])
		{
		    ++index;
			  ++count;
		}
		occurence_count += count == old_len - 1;
		++index;
	}
	int new_str_len = s->len + (occurence_count * (new_len - old_len));

    //새로운 길이의 스트링에다가 chars 바꿔치기
	String* new_str = create_string(new_str_len);
	int new_str_index = 0;
	index = 0;
	while(index < new_str_len)
	{
		int old_index = 0;
		int count = 0;
		while(count < old_len - 1 && old[old_index++]  == s->s[index])
		{
		    ++index;
			  ++count;
		}
		if(count == old_len - 1 )
		{
			for(int i = 0; i < new_len - 1;++i)
			{
				new_str->s[new_str_index++] = new[i];
			}
		}
		new_str->s[new_str_index++] = s->s[index];
		++index;
	}

	return new_str;
}

//Join strings
String* join_strings(char* s1, char* s2)
{
    int s1_len = 0, s2_len = 0;
	while(s1[s1_len++]);
	while(s2[s2_len++]);
	String* joined = create_string(s1_len + s2_len);
	memcpy(joined->s,s1,s1_len);
	memcpy(joined->s + s1_len - 1,s2,s2_len);
	return joined;
}

int main()
{
    String* s = create_string(10);
    assign_string(s,"my name is hyunjae");
    printf("string: %s\n",s->s);
    String* clone = clone_string(s);
    printf("clone: %s\n",clone->s);
    
    if(compare_string(s,clone))
    {
        printf("same strings");
    }
    else
    {
        printf("different strings");
    }
    printf("\n");
    if(is_empty_string(s))
    {
        printf("string is empty");
    }
    else
    {
        printf("string is not empty");
    }
    printf("\n");
        printf("appending z to clone: ");
    append_char(clone,'z');
    printf("%s \n",s->s);
    printf("extracting [1-3] from a string: ");
    String* extracted = extract_substring(s->s, 1,3);
    printf("%s\n", extracted->s);
    printf("joining hyunjae + sooyoung ");
    String* joined =  join_strings("chohyunjae", "sooyoung");
    printf("%s\n",joined->s);
    String* intro = create_string(10);
    assign_string(intro,"my name is hyunjae");
    printf("string: %s\n",intro->s);
    printf("replacing 'h' with 'm': ");
    String* replaced = replace_substring(intro, "hyunjae", "sooyoung");
    printf("%s\n",replaced->s);
    

    
    delete_string(s);
    delete_string(clone);
    delete_string(joined);
    delete_string(extracted);
    delete_string(replaced);
    return 0;
}
