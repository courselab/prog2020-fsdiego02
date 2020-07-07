/* m009.c - Sort vector.

   This program reads N<=100 numbers passed as command line
   arguments and ouputs them in ascending order. Choose the
   sorting algorithm of your preference (see bellow).

   E.g.

      command line    : m009 3 2 5 4 2
      expected output : 2 2 3 4 5

   Directions:

      Please, edit function sort();
      do no not edit function main().

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int vec_len (int *vec)
{
  int k = -1;
  while (*(vec++))
    k++;
  return k;
}

/* Sort the first 'n' integers values in 'vector'. */

void sort (int* vector, int s)
{
  if (s < 1)
  {
    return;
  }
  int counter = 0;
  int r = 0; 
  int rr = 0;
  int value = MAX;
  int siz = vec_len (vector); 
  int newvec [siz + 1];

  if (siz != 1)
  {
    while(r != siz - 2)
    {
      if (value != MAX)
      {
        value = MAX;
      }
      for(rr = 0; rr <siz - 1; rr++)
      {
        if(value >= vector [rr])
        {
          value = vector [rr]; 
        }
      }
      for(rr = 0; rr < siz - 1; rr++)
      { 
        if(value == vector [rr] && counter !=1)
        {
          vector[rr] = 101;
          counter = 1;
        }
      } 
      counter = 0; 
      newvec [r] = value; 
      r++;
    }
    for (r = 0; r <siz - 1; r++)
    {
      vector [r] = 0;
      vector [r] = newvec [r];
    }
  }
}

#define USAGE "m009 <num1> <nun2> ... \n"

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int values[MAX];
  int i;

  /* Read command line arguments into vector. */
  
  for (i=1; i<argc; i++)
    values[i-1] = atoi(argv[i]);


  /* Sort vector. */
  
  sort (values, argc-1);


  /* Output sorted vector. */
  
  for (i=0; i<argc-1; i++)
    printf ("%d ", values[i]);

  printf ("\n");
  
  return 0;
}

/* Tip: check these sorting methods

   Selection sort: https://en.wikipedia.org/wiki/Selection_sort
   Bubble sort: https://en.wikipedia.org/wiki/Bubble_sort
   Insertion sort: https://en.wikipedia.org/wiki/Insertion_sort
  
 */
