// author : cho hyun jae
// date : 2022-09-28
// program : wrap the input text file with html5 template 

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUFF_SIZE 1024 * 1024
#define MAKE_STR(s) #s

extern int errno ;

#define FIRST_HALF_TEMPLATE " \
<!DOCTYPE html>\n \
  <html lang=\"en\">\n \
    <head>\n\
      <meta charset=\"UTF-8\">\n \
      <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n \
      <title>my devlog</title>\n \
      <style>\n \
        a:link { \n \
          color: #F8F8F8;\n \
      	}\n \
      	a:visited {\n \
          color: #F8F8F8;\n \
      	}\n \
	  </style>\n \
	</head>\n \
	<body style =\"color: #F8F8F8; background-color: #1C1C1C\">\n \
      <a href=\"/personal_homepage/index.html\">Home</a>\n \
      <hr />\n \
      <div style=\"text-align: center;\">\n \
        <main style=\"display: inline-block; text-align: left\">\n"   \
		"\n"

#define OTHER_HALF_TEMPLATE " \
		\n \
          </main>\n \
      </div>\n \
  </body>\n \
</html>\n "

const char* wrap_content(char buffer[], const char* content);
void append(char dest[],const char* src);

int main(int argc, char** argv)
{
	//read the text file
	const char* filename = argv[1];
	FILE* file;
	file = fopen(filename,"r");	
	if(file == NULL)
	{
		printf("error - %d : %s \n", errno, strerror(errno));
		printf("please provide a filename.");
	    return 1;
	}
	char content[BUFF_SIZE];
	int index = 0;
	int c;
	while ( ( c = fgetc(file) ) != EOF)
	{
		content[index] = (char)c;
		index += 1;
	}
	content[index] = '\0';
	fclose(file);
	char buffer[BUFF_SIZE];
	const char* wrapped_content = wrap_content(buffer,content);
	printf("%s", wrapped_content);
	return 0;
}

unsigned int char_arr_len(char str[])
{
	unsigned int index = 0;
	while(*str != '\0')
	{
		++str;
		index++;
	}
	return index;
}

void append(char dest[],const char* src)
{
	unsigned int index = 0;
	unsigned int dest_size = char_arr_len(dest);
	char c;
	while( (c = src[index]) != '\0')
	{
		dest[dest_size] = c;
		index++;
		dest_size++;
	}
}

const char* wrap_content(char buffer[], const char* content)
{
	char* ptr_first_half = FIRST_HALF_TEMPLATE;
	char* ptr_other_half  = OTHER_HALF_TEMPLATE;
	append(buffer,ptr_first_half);
	append(buffer,content);
	append(buffer,ptr_other_half);
	return buffer;
	
	// a recurring logic. can be 
	// while( (c = ptr_first_half[index]) != '\0')
	// {
	// 	buffer[buffer_size] = c;
	// 	buffer_size = buffer_size + 1;
	// 	index = index + 1;
	// }
	// index = 0;
	// while((c = content[index]) != '\0')
	// {
	// 	buffer[buffer_size] = c;
	// 	buffer_size = buffer_size + 1;
	// 	index = index + 1;
	// }
	// index = 0;
	
	// while( (c = ptr_other_half[index]) != '\0')
	// {
	// 	buffer[buffer_size] = c;
	// 	index = index +  1;
	// 	buffer_size = buffer_size + 1;
	// }
	

}
