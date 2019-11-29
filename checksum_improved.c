
#include <stdio.h>
#include <math.h>

long divide_by_hundred(long number);
int get_digit(long number);

int main()
{
	long entry = 5506920809243667;
	long odd_rest, even_rest;
	int odd_digit, odd_total;
	int even_digit, even_total;

	//first odd digit has to be extracted outside of the loop because entry is divided by 10 - in all other cases it's with 100//

	odd_rest = entry / 10;
	odd_digit = get_digit(odd_rest);
	odd_digit *= 2;
	if (odd_digit >= 10)
		{odd_digit -= 9;}
	odd_total = odd_digit;

	even_digit = get_digit(entry);
	even_total = even_digit;
	even_rest = entry;

	for (int i = 0; i <= 7; i++)
	{
		//digits are being extracted 7 times which is maximal number of loops needed for a 16-digit number//
		//In case when number of digits is lower a zero will be extracted which does not change the calculation//

		//getting odd digits, and applying Luhn's algorithm//

		odd_rest = divide_by_hundred(odd_rest);
		odd_digit = get_digit(odd_rest);
		odd_digit *= 2;
		if (odd_digit >= 10)
		{
			odd_digit -= 9;
		}
		odd_total += odd_digit;

		//getting even digits, and applying Luhn's algorithm//

		even_rest = divide_by_hundred(even_rest);
	    even_digit = get_digit(even_rest);
	    even_total = even_total + even_digit;
	}
	printf("First sum is %i, second sum is %i and overall sum is %i\n", odd_total, even_total, odd_total + even_total);
}

long divide_by_hundred(long number)
{
	//this function is doing a division by 100//

	long new_number;
	new_number = number / 100;
	return new_number;
}

int get_digit(long number)
{
	//this function is doing modulo with 10//

	int digit = number % 10;
	return digit;
}




