#include <cs50.h>
#include <stdio.h>

int main(void)
{
      int height,row, columns,space;
      do{
      height = get_int("Enter height here:");
      }
      while(height<1 || height>8);

      for(row=0; row<height; row++)
      {
            for(space=0; space<height-row-1; space++)
            {
                  printf(" ");
            }
            for(columns=0; columns<=row; columns++)
            {
            printf("#");
            }
            printf("\n");
      }
}