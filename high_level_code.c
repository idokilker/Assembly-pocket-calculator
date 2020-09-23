#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char op;
int num1, num2;

void PutSingedInt(int Number);
int GetString(void);
int diving(int a, int b);
void errList(int x);
int multipication(int multiplicand, int multiplier);
int adding(int num1, int num2);
int subtraction(int num1, int num2);


void PutSingedInt(int Number) {
	int stripped = 0, count = 0, It_count = 4, digit = 0;
	int powerTen[4] = { 10000,1000,100,10 };
	int temp = 0;

	if (Number < 0) {
		stripped = -Number;
		printf("%c", '-');
	}
	else {
		stripped = Number;
	}

	for (temp = stripped; count < It_count; count = count + 1)
	{
		digit = 0;
		while (temp - powerTen[count] > 0)
		{
			temp = temp - powerTen[count];
			digit++;
		};
		stripped = stripped - (powerTen[count] * digit);
		printf("%d", digit); // print the 10,000's 1000's 100's 10's
	};
	printf("%d\n", stripped); // print the 1's	
}

int GetString(void)
{
	int TempNum = 0;
	int FLAG = 0, NumFlag = 0, BreakFlag = 0;
	char CC;
start:
	CC = fgetc(stdin);
	if (CC == '\n')
		goto EndTwo;
	if (CC == '-')
	{
		if (BreakFlag > 0)
		{
			BreakFlag = 0;
		OPadd:
			op = CC;
			++NumFlag;
			goto EndOne;
		}
		else
		{
			++FLAG;
			++BreakFlag;
			goto start;
		}
	}
	if (CC == 'x' || CC == 'X')
	{
		printf("Bye\n");
		return 1;
	}
	if (CC == '+')
		goto OPadd;
	if (CC == '*')
		goto OPadd;
	if (CC == '/')
		goto OPadd;
	if (CC < 0x30 || CC>0x39)
	{
		errList(1);
		FLAG = 0, NumFlag = 0, BreakFlag = 0, TempNum = 0;
		while (CC != '\n')
			CC = fgetc(stdin);
		goto start;
	}
	TempNum = TempNum * 10 + (CC - 0x30);
	++BreakFlag;
	goto start;
EndOne:
	if (FLAG > 0)
	{
		num1 = -TempNum;
		FLAG = 0;
		TempNum = 0;
		BreakFlag = 0;
		goto start;
	}
	else
	{
		num1 = TempNum;
		FLAG = 0;
		TempNum = 0;
		BreakFlag = 0;
		goto start;
	}
EndTwo:
	if (FLAG > 0)
	{
		num2 = -TempNum;
		printf("%d     %c     %d\n", num1, op, num2);
		return 0;
	}
	else
	{
		num2 = TempNum;
		printf("%d     %c     %d\n", num1, op, num2);
		return 0;
	}
}

int diving(int a, int b)
{
	int diff = 0;
	int i = a, j = b;
	if (j == 0)
	{
		errList(2);
		return 0;
	}
	if (j < 0 && i>0)
	{
		printf("-");
		j = -j;
	}
	else
	{
		if (j > 0 && i < 0)
		{
			printf("-");
			i = -i;
		}
	}
	while (i >= j)
	{
		i = i - j;
		++diff;
	}
	printf("%d  Diff: %d", diff, i);
	return diff;
	//if (b > a)
	//return 0; //remain is x

}

void errList(int x)
{
	switch (x)
	{
	case 1:
	{
		printf("> ERROR: Bad input\n");
		return;
	}
	case 2:
	{
		printf(">division by 0!\n");
		return;
	}
	}
	return;
}

int multipication(int multiplicand, int multiplier)
{
	int DigitCount = 0;
	int MultResult = 0;
	int E = 0;
	while (DigitCount < 8)
	{
		E = multiplier >> 1;
		if (E == 1)
		{
			MultResult = MultResult + multiplicand;
		}
		multiplicand = multiplicand << 1;
		++DigitCount;
	}
	return DigitCount;
}

int adding(int num1, int num2) {
	return (num1 + num2);
}

int subtraction(int num1, int num2) {
	return (num1 - num2);
}

void main(void)
{
	int result = 0, End_prog = 0;
	start:
	End_prog = GetString();
	if (End_prog == 0) {
		switch (op)
		{
		case ('*'):
			{
				printf("= ");
				PutSingedInt(result = (multipication(num1, num2)));
				goto start;
			}
		case ('+'):
			{
				printf("= ");
				PutSingedInt(result = (adding(num1, num2)));
				goto start;
			}
		case ('-'):
			{
				printf("= ");
				PutSingedInt(result = (subtraction(num1, num2)));
				goto start;
			}
		case ('/'):
			{
				printf("= ");
				PutSingedInt(result = diving(num1, num2));
				goto start;
			}
			goto start;
		}

		printf("Bye");
		return;
	}

}