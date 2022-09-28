// author : cho hyun jae
// date : 2022-09-28
// program : wrap the input text file with html5 template 

#include <stdio.h>
#define TEST(NAME)  \
	"helllo world" NAME

#define WRAP_HTML(MAIN_CONTENT)	" \
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
		"\t\t" \
		MAIN_CONTENT \
		"\n" \
"         </main>\n \
      </div>\n \
  </body>\n \
</html>\n"



int main()
{
	//read the text file
	//const char* filename = argv[1];
	//FILE* file;
	//file = fopen(filename,"r");
	//if(file == NULL)
	//{
	//    return 1;
	//}
	//fclose(file);
	printf(WRAP_HTML("this is main content"));
	//printf(TEST("hyunjae"));
	return 0;
}
