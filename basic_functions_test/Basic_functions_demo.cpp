// basic_functions_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int atoi(const char* str) 
{ 
    int sign = 0,num = 0; 
    //assert(NULL != str); 
    while (*str == ' ') 
    { 
        str++; 
    } 
    if ('-' == *str) 
    { 
        sign = 1; str++; 
    } 
    while ((*str >= '0') && (*str <= '9')) 
    { 
        num = num*10 + (*str - '0'); //就是这一行，将对应字符转化为数字

        str++; 
    } 
    if(sign == 1) 
        return -num; 
    else 
        return num; 
}

#define LONG_MAX 2147483647L  
#define LONG_MIN (-2147483647L-1L)

long int _strtol_internal (const char *nptr, char **endptr, int base, int group)
{
  unsigned long int result = 0;
  long int sign = 1;
  
  while (*nptr == ' ' || *nptr == '/t')
    ++nptr;
  
  if (*nptr == '-')
    {
      sign = -1;
      ++nptr;
    }
  else if (*nptr == '+')
    ++nptr;

  if (*nptr < '0' || *nptr > '9')
    {
      if (endptr != NULL)
	  *endptr = (char *) nptr;
      return 0L;
    }
 // assert (base == 0);
  base = 10;


  if (*nptr == '0')
    {
      if (nptr[1] == 'x' || nptr[1] == 'X')
		{
		base = 16;
		nptr += 2;
		}
      else
		base = 8;
    }

  while (*nptr >= '0' && *nptr <= '9')
    {
      unsigned long int digval = *nptr - '0';
		if (result > LONG_MAX / 10
			|| (sign > 0 ? result == LONG_MAX / 10 && digval > LONG_MAX % 10
			: (result == ((unsigned long int) LONG_MAX + 1) / 10
			&& digval > ((unsigned long int) LONG_MAX + 1) % 10)))
			{
			//errno = ERANGE;
			return sign > 0 ? LONG_MAX : LONG_MIN;
			}
      result *= base;
      result += digval;
      ++nptr;
    }

  return (long int) result * sign;
}


int _tmain(int argc, _TCHAR* argv[])
{

	int a =  _strtol_internal("0xFF", 0, 16, 0);

	//int a = atoi("-123");
	return 0;
}

