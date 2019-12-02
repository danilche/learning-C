
#include <stdio.h>
#include <math.h>

int main()
{
	long entry = 4012888888881881;
	long odd_rest, even_rest;
	int odd_digit, odd_total;
	int even_digit, even_total;

	//first odd digit has to be extracted outside of the loop because// 
	//entry is divided by 10 - in all other cases it's with 100//

	odd_rest = entry / 10;
	odd_digit = odd_rest % 10;
	odd_digit *= 2;
	if (odd_digit >= 10)
		{odd_digit -= 9;}
	odd_total = odd_digit;

	even_digit = entry % 10;
	even_total = even_digit;
	even_rest = entry;

	for (int i = 0; i <= 7; i++)
	{
	//digits are being extracted 7 times which is maximal number of //
	//loops needed for a 16-digit number. In case when number of digits//
	//is lower a zero will be extracted which does not change the calculation//

		//getting odd digits, and applying Luhn's algorithm//

		odd_rest /= 100;
		odd_digit = odd_rest % 10;
		odd_digit *= 2;
		if (odd_digit >= 10)
		{
			odd_digit -= 9;
		}
		odd_total += odd_digit;

		//getting even digits, and applying Luhn's algorithm//

		even_rest /= 100;
	    even_digit = even_rest % 10;
	    even_total = even_total + even_digit;
	}
	if (((odd_total + even_total) % 10) != 0)
		{
			printf("INVALID\n");
		}
	else
	{
		//these variables will be used to check whether CC is of//
		//a certain type or invalid//
		int amex, mc, visa1, visa2;
		amex = entry / pow(10, 13);
		mc = entry / pow(10, 14);
		visa1 = entry / pow(10, 12);
		visa2 = entry / pow(10, 15);
		
		if (amex == 34 || amex == 37)
		{
			printf("AMEX\n");
		}
		else if (mc >= 51 && mc <= 55)
		{
			printf("MASTERCARD\n");
		}
		else if (visa1 == 4 || visa2 == 4)	
		{
			printf("VISA\n");
		}
		else
		{
			printf("INVALID\n");
		}
	}	
}



