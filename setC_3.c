#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void sentenceGenerator(const char *const art[],  const char *const noun[],
                       const char *const verb[], const char *const prep[])
{
   int i;
   for ( i = 0; i < 20; i++ )
   {
      printf( "%s %s %s %s %s.\n",
              art  [rand() % SIZE],
              noun [rand() % SIZE],
              verb [rand() % SIZE],
              prep [rand() % SIZE],
              noun [rand() % SIZE]);
   }
}

int main()
{
   const char *art [SIZE] = { "The", "A", "One", "Some", "Any",};
   const char *noun[SIZE] = { "boy", "girl", "dog", "town", "car",};
   const char *verb[SIZE] = { "drove","jumped", "ran", "walked", "skipped",};
   const char *prep[SIZE] = { "to", "from", "over", "under", "on",};
   srand(time(0));
   sentenceGenerator( art, noun, verb, prep );
   return 0;
}
