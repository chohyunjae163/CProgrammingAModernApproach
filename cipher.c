//https://www.hackerrank.com/challenges/cipher/problem?isFullScreen=true\
//timeout solution...TT
char* cipher(int k, char* s, int n) {
    char* encoded = s;
    int shifted = k - 1;
    int decodedLength = n;
    char* decoded = (char*)calloc(decodedLength,sizeof(char));
    for (int i = 0; i < decodedLength; ++i)
    {
        int unshift = 0;
        int xored = (encoded[i] - '0'); 
        while (unshift < shifted) //shifting unwinding
        {
            int decodedIndex = (i - shifted + unshift);
            xored ^= (decodedIndex < 0 ? 0 : (decoded[decodedIndex] - '0'));
            unshift++;
        }
        decoded[i] = xored + '0';
    }
    return decoded;
}
