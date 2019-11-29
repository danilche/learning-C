//this program checks if entered CC number is valid by applying Luhn's algorithm//

//Luhn’s Algorithm//
//Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm//
//you can determine if a credit card number is (syntactically) valid as follows: //

//Multiply every other digit by 2, starting with the number’s second-to-last digit//
//and then add those products’ digits together. Add the sum to the sum of the digits that weren’t multiplied by 2//
//If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid//

#include <stdio.h>
#include <math.h>

long get_rest(long number);
int get_digit(long numero);
int get_first_sum(long entry);
int get_second_sum(long entry);

int main(void)
{
	//get input//

	long entry = 4012888888881881;

	//variables to help extracting first digit or first two digits for CC type check//

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

	//check if card is AMEX//

	if (amex_x == 34 || amex_x == 37)
	{
		//adding get_first-sum to get_second_sum is the final step of Luhn's algorithm//

		int get_first = get_first_sum(entry);
		int get_second = get_second_sum(entry);
		int total = get_first + get_second;
		if (total % 10 == 0)
		{
			printf("AMEX\n");
	  	}
	  	else
	  	{
			printf("INVALID\n");
		}
	}

	//check if card is MC//

	else if    (mc_x == 51
			 || mc_x == 52
			 || mc_x == 53
			 || mc_x == 54
			 || mc_x == 55)
	{
		int get_first = get_first_sum(entry);
		int get_second = get_second_sum(entry);
		int total = get_first + get_second;
		if (total % 10 == 0)
		{
			printf("MASTERCARD\n");
	  	}
	  	else
	  	{
			printf("INVALID\n");
		}
	}

	//check if card is VISA//

	else if (visa1_x == 4 || visa2_x == 4)
	{
		int get_first = get_first_sum(entry);
		int get_second = get_second_sum(entry);
		int total = get_first + get_second;
		if (total % 10 == 0)
		{
			printf("VISA\n");
	  	}
	  	else
	  	{
			printf("INVALID\n");
		}
	}

	else
	{
	printf("INVALID\n");
	}


}

long get_rest(long number)
{
	//this function is simply doing a division by 10//
	//and returning the rest so the digits can be extracted//

	long new_number = number / 10;
	return new_number;

}

int get_digit(long numero)
{
	//this function is doing modulo with 10 so the last digit can be obtained//

	int digit = numero % 10;
	return digit;
}

int get_first_sum(long entry)
{
		//this function is taking every other digit starting from the second to last//
		//obtained by get_digit and applying first part of Luhn's algorithm for calculating CC checksum//

		long a = get_rest(entry);
		int b = get_digit(a);
		b = b * 2;
		if (b >= 10)
			{b = get_digit(b) + get_rest(b);}

		long a1 = get_rest(get_rest(a));
		int b1 = get_digit(a1);
		b1 = b1 * 2;
			if (b1 >= 10)
				{b1 = get_digit(b1) + get_rest(b1);}

		long a2 = get_rest(get_rest(a1));
		int b2 = get_digit(a2);
		b2 = b2 * 2;
			if (b2 >= 10)
				{b2 = get_digit(b2) + get_rest(b2);}

		long a3 = get_rest(get_rest(a2));
		int b3 = get_digit(a3);
		b3 = b3 * 2;
			if (b3 >= 10)
				{b3 = get_digit(b3) + get_rest(b3);}

		long a4 = get_rest(get_rest(a3));
		int b4 = get_digit(a4);
		b4 = b4 * 2;
			if (b4 >= 10)
				{b4 = get_digit(b4) + get_rest(b4);}

		long a5 = get_rest(get_rest(a4));
		int b5 = get_digit(a5);
		b5 = b5 * 2;
			if (b5 >= 10)
				{b5 = get_digit(b5) + get_rest(b5);}

		long a6 = get_rest(get_rest(a5));
		int b6 = get_digit(a6);
		b6 = b6 * 2;
			if (b6 >= 10)
				{b6 = get_digit(b6) + get_rest(b6);}

		long a7 = get_rest(get_rest(a6));
		int b7 = get_digit(a7);
		b7 = b7 * 2;
			if (b7 >= 10)
				{b7 = get_digit(b7) + get_rest(b7);}


		int digits_sum = b + b1 + b2 + b3 + b4 + b5 + b6 + b7;
		return digits_sum;
}

int get_second_sum(long entry)
{
		//this function is calculating sum of the remaining digits in a CC number//

		int b = get_digit(entry);

		long a1 = get_rest(get_rest(entry));
		int b1 = get_digit(a1);

		long a2 = get_rest(get_rest(a1));
		int b2 = get_digit(a2);

		long a3 = get_rest(get_rest(a2));
		int b3 = get_digit(a3);

		long a4 = get_rest(get_rest(a3));
		int b4 = get_digit(a4);

		long a5 = get_rest(get_rest(a4));
		int b5 = get_digit(a5);

		long a6 = get_rest(get_rest(a5));
		int b6 = get_digit(a6);

		long a7 = get_rest(get_rest(a6));
		int b7 = get_digit(a7);


		int sec_digits_sum = b + b1 + b2 + b3 + b4 + b5 + b6 + b7;
		return sec_digits_sum;
}

