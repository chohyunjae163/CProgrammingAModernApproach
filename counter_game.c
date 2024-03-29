#define LOUISE "Louise"
#define RICHARD "Richard"
#define POWER_OF_TWO(n) (n & (n - 1)) == 0 ? EBOOL_TRUE : EBOOL_FALSE;  
#define ENUM_TO_STR(e) e == ETURN_LOUISE ? LOUISE : RICHARD 
#define DIV_BY_TWO(n) n >> 1 //divide by 2
#define MUL_BY_TWO(n) n << 1 //multiply by 2
 enum ETURN 
 {
    ETURN_LOUISE,
    ETURN_RICHARD,
 };
 enum EBOOL
 {
    EBOOL_FALSE,
    EBOOL_TRUE,
 };
 
char* counterGame(long n) 
{
    //check a number if it is a power of 2.
    //if it is, divide it by 2.
    //if not, reduce it by the next lower number which is a power of 2.
    enum ETURN turn = ETURN_LOUISE;
    while(n >= 1)
    {
        enum EBOOL power_of_two = POWER_OF_TWO(n);
        switch(power_of_two)
        {
            case EBOOL_TRUE:
                n = DIV_BY_TWO(n);
            break;
            case EBOOL_FALSE:
            {
                long t = 2;
                while(MUL_BY_TWO(t) < n)
                {
                    t = MUL_BY_TWO(t);
                }
                n -= t;
            }
            break;
        }       
        turn = !turn;
    }
    return ENUM_TO_STR(turn);
}
