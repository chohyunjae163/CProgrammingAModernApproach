/******************************************************************************

Welcome to GDB Online
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>


static int codepoint_len = 0;

const int HEX = 16;


char* decoder(char* encoded);
char* encoder(char* codepoint);
int calcUtfBytes(char* codepoint);
int power(int base, int n);
char* hexToBinary(char c);
char binaryToHex(char binary[]);
char* unicodeToBinary(char* codepoint);
int unicodeToDecimal(char* codepoint);
int hexToDecimal(char c);
int compareBinary(char a[4] , char b[4] );

int main()
{
    
    //input hex Code
    //I have to decide how many bytes are needed to encode in UTF-8
    
    /*
    ===========================
    First code point	Last code point	    Byte 1	    Byte 2	    Byte 3	    Byte 4
    U+0000              U+007F              0xxxxxxx
    U+0080	            U+07FF	            110xxxxx	10xxxxxx	
    U+0800	            U+FFFF              1110xxxx	10xxxxxx	10xxxxxx
    U+10000	            U+10FFFF            11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
    */
    
    //0041 -> 65 -> 01000001 ->
    printf("\n=================\n");
    printf("encoding starts!\n");
    char* codepoint = "0024";
    printf("codepoint : %s\n", codepoint);
    int index = 0 ;
    while(codepoint[index] != '\0') 
    {
        index++;
        codepoint_len++;
    }
    char* UTF8encoded = encoder(codepoint);
    printf("UTF8encoded : ");
    int i = 0 ;
    while(UTF8encoded[i] != '\0')
    {
        printf("%c",UTF8encoded[i]);
        ++i;
        if(i % 2 == 0)
        {
            printf(" ");
        }
    }
    
    printf("\n=================\n");
    printf("decoding starts!\n");
    printf("encoded : %s\n", UTF8encoded);
    char* decoded_codepoint = decoder(UTF8encoded);
    printf("decoded_codepoint : %s", decoded_codepoint);
    
    
    return 0;
}

char* decoder(char* encoded)
{
    int index = 0;
    while(encoded[index] != '\0')
    {
        ++index; 
    }
    int encoded_len = index;
    index = 0;
    static char decoded[6] = {'0','0','0','0','0','0'};
    char binary[32];
    memset(binary,0,32);
    int binary_len_index = 31;
    while(encoded[index] != '\0')
    {
        char* b;
        b = hexToBinary(encoded[index]);
        binary[binary_len_index - (index * 4)] = b[0];
        binary[binary_len_index - (index * 4) - 1] = b[1];
        binary[binary_len_index - (index * 4) - 2] = b[2];
        binary[binary_len_index - (index * 4) - 3] = b[3];
        index++;
    }
    
    switch(encoded_len)
    {
        case 2:
        {
            decoded[2] = binaryToHex((char[]){binary[31],binary[30],binary[29],binary[28]});
            decoded[3] = binaryToHex((char[]){binary[27],binary[26],binary[25],binary[24]});
            decoded[4] = '\0';
        }
        break;
        case 4:
        {
            //needs masking 
            //110xxxxx	10xxxxxx
            //11000010  10100011
            //-----------------
            
            for(int i = 0; i < 4; ++i)
            {
                decoded[i] = binaryToHex((char[]){binary[i],binary[(i * 4) + 1],binary[(i * 4) + 2],binary[(i * 4) + 3]});
            }
            decoded[4] = '\0';
        }
        break;
    }
    return decoded;
}

char* encoder(char* codepoint)
{
    static char encoding[9];
    memset(encoding,0,9);
    
    //convert unicode codepoint to binary.
    char* binary = unicodeToBinary(codepoint);
    int binaryIndex = 0;
    while(binary[binaryIndex + 1] != '\0')
    {
        ++binaryIndex;
    }
    //get needed bytes 
    int bytes = calcUtfBytes(codepoint);
    switch(bytes)
    {
        case 1:
        {
            encoding[0] = codepoint[2];
            encoding[1] = codepoint[3];
            return encoding;
        }
        case 2:
        {
            //110xxxxx	10xxxxxx
            //11 bits.
            char binaryUTF[16] = {
                '1','1','0','0','0','0','0','0',
                '1','0','0','0','0','0','0','0'
                
            };
            for(int i = 15; i >= 10;--i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
           
            for(int i = 7; i >= 3; --i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
            
            for(int i = 0; i < 4; ++i)
            {
                char hex = binaryToHex((char[]) { binaryUTF[i * 4],  binaryUTF[i * 4 + 1] ,  binaryUTF[i * 4 + 2],  binaryUTF[i * 4 + 3]});
                encoding[i] = hex;
            }
            return encoding;
        }
        case 3:
        {
            //1110xxxx	10xxxxxx	10xxxxxx
            char binaryUTF[24] = {
                '1','1','1','0','0','0','0','0',
                '1','0','0','0','0','0','0','0',
                '1','0','0','0','0','0','0','0'
            };
            for(int i = 23; i >= 18; -- i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
            for(int i = 15; i >= 10;--i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
           
            for(int i = 7; i >= 4; --i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
            for(int i = 0; i < 6; ++i)
            {
                char hex = binaryToHex((char[]) { binaryUTF[i * 4],  binaryUTF[i * 4 + 1] ,  binaryUTF[i * 4 + 2],  binaryUTF[i * 4 + 3]});
                encoding[i] = hex;                
            }
            return encoding;
        }
        case 4:
        {
            //11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
            char binaryUTF[32] = {
                '1','1','1','1','0','0','0','0',
                '1','0','0','0','0','0','0','0',
                '1','0','0','0','0','0','0','0',
                '1','0','0','0','0','0','0','0'
            };
            for(int i = 31; i >=26; -- i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
            for(int i = 23; i >= 18; -- i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
            for(int i = 15; i >= 10;--i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
            for(int i = 7; i >= 6; --i)
            {
                binaryUTF[i] = binary[binaryIndex];
                --binaryIndex;
            }
            for(int i = 0; i < 8; ++i)
            {
                char b[4] = { binaryUTF[i * 4],  binaryUTF[i * 4 + 1] ,  binaryUTF[i * 4 + 2],  binaryUTF[i * 4 + 3]};
                char hex = binaryToHex(b);
                encoding[i] = hex;                
            }
            
            return encoding;
        }
    }
}

char* unicodeToBinary(char* codepoint)
{
    static char binary[20];
    memset(binary,0,20);
    for(int i = 0; i < codepoint_len;++i)
    {
        for(int j = 0; j < 4;++j)
        {
            char* bits = hexToBinary(codepoint[i]);
            binary[j + (i * 4)] = bits[j];
        }
    }
    int index = 0;
    return binary;
}

int calcUtfBytes(char* codepoint)
{
    int input = unicodeToDecimal(codepoint);
    if(input < power(2,7)) // 7bits
    {
        return 1;
    }
    else if(input < power(2,11)) // 11 bits
    {
        return 2;
    }
    else if(input < power(2,16)) // 16bits
    {
        return 3;
    }
    else
    {
        return 4;
    }
    
}

char* hexToBinary(char c)
{
    //Hexadecimal to Binary Conversion Table
    switch(c)
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

char binaryToHex(char binary[4])
{
    //Hexadecimal to Binary Conversion Table
    if(compareBinary(binary,"0000")) return '0';
    else if(compareBinary(binary , "0001")) return '1';
    else if(compareBinary(binary , "0010")) return '2';
    else if(compareBinary(binary , "0011")) return '3';
    else if(compareBinary(binary , "0100")) return '4';
    else if(compareBinary(binary , "0101")) return '5';
    else if(compareBinary(binary , "0110")) return '6';
    else if(compareBinary(binary , "0111")) return '7';
    else if(compareBinary(binary , "1000")) return '8';
    else if(compareBinary(binary , "1001")) return '9';
    else if(compareBinary(binary , "1010")) return 'A';
    else if(compareBinary(binary , "1011")) return 'B';
    else if(compareBinary(binary , "1100")) return 'C';
    else if(compareBinary(binary , "1101")) return 'D';
    else if(compareBinary(binary , "1110")) return 'E';
    else if(compareBinary(binary , "1111")) return 'F';
}

int compareBinary(char a[4] , char b[4] )
{
    for(int i =0; i < 4;++i)
    {
        if( a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}



int unicodeToDecimal(char* codepoint)
{
    
    int decimal = 0;
    for(int i = 0; i < codepoint_len; ++i)
    {
        int n = hexToDecimal(codepoint[i]);
        if(n == 0)
        {
            continue;
        }
        decimal += (n * power(HEX,codepoint_len - i - 1));
    }
    return decimal;
}

int power(int base, int n)
{
    int p = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        p = p * base;
    }
    
    return p;
}

int hexToDecimal(char c)
{
    if(c >='A' && c <= 'F')
    {
        return c - 'A' + 10;
    }
    else
    {
        return c - '0';
    }
}

