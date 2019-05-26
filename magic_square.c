#include<stdio.h>
#include<stdlib.h>

void solveMagicSquare(int square[6][6])
{
 int i, j, sum= 0, counter1, innersum, flag = 0;

 for (i = 0; i < 6; i++)
 {
     sum = 0;

     for (j = 0; j < 6; j++)
     {
         if (square[i][j] == -1)
         {
             break;
         }
         else
         {
             sum = sum + square[i][j];
         }
     } break;
 }

 if (sum == 0)
 {
     sum = 0;

     for (j = 0; j < 6; j++)
     {
         if (square[j][i] == -1)
         {
             break;
         }
         else
         {
             sum = sum + square[j][i];
         }
         
     }
 }

 while (flag != 1)
 {
     for (i = 0; i < 6; i++) // find index of unknown places and complete them (rows)
     {
         counter1 = 0;
         
         for (j = 0; j < 6; j++) // index finder
         {
             if (square[i][j] == -1)
             {
                 counter1++;
             }
         }
         
         if (counter1 == 1)
         {
             innersum = 0;
             
             for (j = 0; j < 6; j++) // sum of row
             {
                 if (square[i][j] != -1)
                 {
                     innersum = innersum + square[i][j];
                 }
             }

             for (j = 0; j < 6; j++) // solving the unknown
             {
                 if (square[i][j] == -1)
                 {
                     square[i][j] = sum - innersum;
                 }
             }
         }
     }
     
     for (j = 0; j < 6; j++) // find index of unknown places and complete them (columns)
     {
         counter1 = 0;
         
         for (i = 0; i < 6; i++) // index finder
         {
             if (square[i][j] == -1)
             {
                 counter1++;
             }
         }
         
         if (counter1 == 1)
         {
             innersum = 0;
             
             for (i = 0; i < 6; i++) // sum of column
             {
                 if (square[i][j] != -1)
                 {
                     innersum = innersum + square[i][j];
                 }
             }
             
             for (i = 0; i < 6; i++) // solving the unknown
             {
                 if (square[i][j] == -1)
                 {
                     square[i][j] = sum - innersum;
                 }
             }
         }
     }

     flag = 1;

     for (i = 0; i < 6; i++)
     {
         for (j = 0; j < 6; j++)
         {
             if (square[i][j] == -1)
             {
                 flag = 0;
                 break;
             }
         }
     }
 }
}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
