#include<stdio.h>
#include <ctype.h>
int main()
{
    const char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char input;
	int i;
    while( (input = tolower(getchar())) != EOF )
    {
        if( input == ' ' || input == '\n' )
        {
            putchar( input );
            continue;
        }
        for( i = 0 ; input != keyboard[i] ; i++ );
        putchar( keyboard[i-2] );
    }
    return 0;
}