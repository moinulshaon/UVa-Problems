#include <stdio.h>
#include <string.h>


char A[5000][21];
int L[26];


int main ()
{
     char  Temp[21];
     int I = 0, Len, N, J; 
     while (scanf("%s", Temp))
     { 
         if (Temp [0] == '#')                       
             break;
         Len = strlen (Temp);
         for (J = 0; J < Len; J++) 
            A [I] [J] = Temp [J];

         I++;
     }

    for (J = 0; J < 21; J++)
    {
        for (N = 0; N < I; N++)
       {
            if (A [N] [J])
                L [ (A [N] [J] - 65) ]++;
            if (L [ ( A [N] [J] - 65) ] == 1)
                printf("%c", A [N] [J]); 
        }
    }

    printf("\n");
    return 0;
}