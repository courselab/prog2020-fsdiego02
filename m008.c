/* m008.c - Lastname-Names.

   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lastname();
      do no not change function main().

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */

void lastname (char *s)

{
  int j, pos_ult_esp, tam_vec, aux1 = 0, aux2 = 0;
  char vec_aux [256];
  strcpy (vec_aux, s);
  tam_vec = strlen (vec_aux) - 1;
  
  for(j = tam_vec; vec_aux [j]!=32; j--)
  {
  } 
  pos_ult_esp = j + 1;
  j = 0;
 
  for(j = pos_ult_esp; j!= tam_vec; j++)
  {
    s[aux1] = vec_aux[j];
    aux1++;
  } 
  for (j = 0; j <= aux1 - 1; j++)
  {
  	if(s[j] >= 'a' && s[j] <= 'z')
  	{
  		s[j] = s[j] - 32;
	}
  }
  s[aux1] = ',';
  aux1++;
  s[aux1] = 32;
  aux1++;
  j = 0;
  for (j = aux1; j!= tam_vec + 1; j++)
  {
  	s[j] = vec_aux[aux2];
  	aux2++;
  }
  j = 0;
}



/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
