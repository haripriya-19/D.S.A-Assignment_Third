#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to use time function


int base(long long int); // function to check base

int base(long long int n)
{
  int r, max_base = 0; // variable r to store random no. and max_base for greatest digit of random no.
  while (n > 0)        // loop will work till the random no. become 0
  {
    r = n % 10;       // remainder of no. is stored every time loop works
    if (r > max_base) // to check greatest digit
    {
      max_base = r; // greatest digit is stored here after comparision
    }
    n = n / 10; // n will get shorten ever time loop works
  }

  return max_base + 1; // retrns the base of random no. as base is one more than greatest digit
}


int main()
{
  long long int random_numbers[50]; 
  int large[50], frequency[11] = {0}; // array to store random no.s there base and frequency of each base
  srand(time(NULL));                                        // to generate new random no. every time because time is not constant

  for (size_t i = 0; i < 50; i++) // loop to store random no.s and their base (by calling base funtion) in array
  {
    random_numbers[i] = rand() % 100000000 + 5000000000; // random numbers stored in array
    large[i] = base(random_numbers[i]);         // base function is called

    printf(" The Highest Base of %lld is %d \n", random_numbers[i], large[i]); // prints random number and base
  }

  for (int i = 0; i < 50; i++) // loop for ferquency distribution
  {
    if (large[i] <= 10) // as base is less than equal to 10
    {
      frequency[large[i]]++; // it will increase 1 at the base place
    }
  }

   printf("base_2 base_3 base_4 base_5 base_6 base_7 base_8 base_9 base_10\n");

   for (size_t i = 2; i <= 10; i++)//loop to print frequency of each base
   {
    printf("  %d    ",frequency[i]);
   }
   
}
