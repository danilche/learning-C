
#include <stdio.h>
#include <math.h>

int main()
{
	long entry = 5506920809243667;
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
		//declaring some variables to check whether CC is of a certain//
		//type or invalid//
	{
		double amex, mc, visa1, visa2;
		int amex_x, mc_x, visa1_x, visa2_x;
		amex = pow(10, 13);
		mc = pow(10, 14);
		visa1 = pow(10, 12);
		visa2 = pow(10, 15);
		amex_x = entry / amex;
		mc_x = entry / mc;
		visa1_x = entry / visa1;
		visa2_x = entry / visa2;
		
		if (amex_x == 34 || amex_x == 37)
		{
			printf("AMEX\n");
		}
		else if (mc_x >= 51 || mc_x <= 55)
		{
			printf("MASTERCARD\n");
		}
		else if (visa1_x == 4 || visa2_x == 4)	
		{
			printf("VISA\n");
		}
		else
		{
			printf("INVALID\n");
		}
	}	
}



