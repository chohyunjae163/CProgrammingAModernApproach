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
		"\t\t"

#define OTHER_HALF_TEMPLATE " \
		\n \
          </main>\n \
      </div>\n \
  </body>\n \
</html>\n "

const char* wrap_content(char buffer[], const char* content);

int main(int argc, char** argv)
{
	//read the text file
	const char* filename = argv[1];
	FILE* file;
	file = fopen(filename,"r");
	
	if(file == NULL)
	{
		//printf("error - %d : %s \n", errno, strerror(errno));
	    //return 1;
	}
	//1 megabytes
	
	char content[BUFF_SIZE] = {"\nhello this is my c program.\n\0"};
	// int index = 0;
	// int c;
	// while ( ( c = fgetc(file) ) != EOF)
	// {
	// 	content[index] = (char)c;
	// 	index += 1;
	// }
	// content[index] = '\0';
	// fclose(file);
	char buffer[BUFF_SIZE];
	const char* wrapped_content = wrap_content(buffer,content);
	printf("%s", wrapped_content);
	return 0;
}


const char* wrap_content(char buffer[], const char* content)
{
	int buffer_size = 0;
	int index = 0;
	char* ptr_first_half = FIRST_HALF_TEMPLATE;
	char c;
	while( (c = ptr_first_half[index]) != '\0')
	{
		buffer[buffer_size] = c;
		index = index + 1;
		buffer_size = buffer_size + 1;
	}
	index = 0;
	while((c = content[index]) != '\0')
	{
		buffer[buffer_size] = c;
		buffer_size = buffer_size + 1;
		index = index + 1;
	}
	
	
	index = 0;
	char* ptr_other_half  = OTHER_HALF_TEMPLATE;
	while( (c = ptr_other_half[index]) != '\0')
	{
		buffer[buffer_size] = c;
		index = index +  1;
		buffer_size = buffer_size + 1;
	}
	buffer[buffer_size] = '\0';
	return buffer;
}
