//https://www.hackerrank.com/challenges/cipher/problem?isFullScreen=true\
//timeout solution...TT


char* cipher(int k, char* s, int n) {
    char* encoded = s;
    int shifted = k - 1;
    int encodedlength = 0;
    while (encoded[encodedlength] != '\0')
    {
        ++encodedlength;
    }
    int decodedLength = encodedlength - (k - 1);
    char* decoded = (char*)calloc(decodedLength, sizeof(char));
    decoded[0] = s[0];  //the fist digit case
    
    //the digits with shifting zeros.
    int decodingProgress = 1;
    int decodingXored = decoded[0] - '0';
    for (int i = decodingProgress; i < k - 1; ++i)
    {
        int value = (encoded[i] - '0') ^ decodingXored;
        decoded[i] = value + '0';
        decodingXored ^= (decoded[i] - '0');
        decodingProgress++;
    }
    
    //the digits after the shifting zeros.
    //go up the shifting ladder, xor operations.
    for (int i = decodingProgress; i < decodedLength; ++i)
    {
        int unshift = 0;
        int xored = (encoded[i] - '0');
        while (unshift < shifted) //shifting unwinding
        {
            int decodedIndex = (i - shifted + unshift);
            xored ^= (decoded[decodedIndex] - '0');
            ++unshift;
        }
        decoded[i] = xored + '0';
    }
    return decoded;
}
