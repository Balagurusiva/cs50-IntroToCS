#include <cs50.h>
#include <stdio.h>

int main(void)
{
      int height,row, columns,space;

       //to get the height from the user
      do
      {
      height = get_int("Enter height here:");
      }
      while(height<1 || height>8);

      //loop for the row
      for(row=0; row<height; row++)
      {
            //loop to print the space in row
            for(space=0; space<height-row-1; space++)
            {
                  printf(" ");
            }

            //loop for the columns to print #
            for(columns=0; columns<=row; columns++)
            {
            printf("#");
            }

            //print the space between two primid
            printf("  ");
            //loop for right side #
            for(columns=0; columns<=row; columns++)
            {
               printf("#");
            }

            printf("\n");
      }

}