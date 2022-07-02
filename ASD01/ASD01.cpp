#include <stdio.h>
#include <windows.h>
#include <time.h>

struct Date {
	unsigned short int Second : 6;
	unsigned short int Minute : 6;
	unsigned short int Hour : 5;
	unsigned short int WeekDay : 3;
	unsigned short int MonthDay : 5;
	unsigned short int Month : 4;
	unsigned short int Year : 7;
}date;


union SigShort
{
	signed short x;
	struct Bites {
		unsigned short znach : 15;
		unsigned short sign : 1;
	}bites;
}X;

union Float {
	float x;
	struct Bits {
		unsigned int x1 : 1;
		unsigned int x2 : 1;
		unsigned int x3 : 1;
		unsigned int x4 : 1;
		unsigned int x5 : 1;
		unsigned int x6 : 1;
		unsigned int x7 : 1;
		unsigned int x8 : 1;
		unsigned int x9 : 1;
		unsigned int x10 : 1;
		unsigned int x11 : 1;
		unsigned int x12 : 1;
		unsigned int x13 : 1;
		unsigned int x14 : 1;
		unsigned int x15 : 1;
		unsigned int x16 : 1;
		unsigned int x17 : 1;
		unsigned int x18 : 1;
		unsigned int x19 : 1;
		unsigned int x20 : 1;
		unsigned int x21 : 1;
		unsigned int x22 : 1;
		unsigned int x23 : 1;
		unsigned int x24 : 1;
		unsigned int x25 : 1;
		unsigned int x26 : 1;
		unsigned int x27 : 1;
		unsigned int x28 : 1;
		unsigned int x29 : 1;
		unsigned int x30 : 1;
		unsigned int x31 : 1;
		unsigned int x32 : 1;
	}bit;

	struct Bytes {
		unsigned int byte1 : 8;
		unsigned int byte2 : 8;
		unsigned int byte3 : 8;
		unsigned int byte4 : 8;
	}byte;

	struct Evm {
		unsigned int mantissa : 23;
		unsigned int step : 8;
		unsigned int sing : 1;
	}evm;

}fl;

void PrintDate(Date date)
{
	switch (date.WeekDay)
	{
	case 1:
		printf("MON");
		break;
	case 2:
		printf("TUE");
		break;
	case 3:
		printf("WED");
		break;
	case 4:
		printf("THU");
		break;
	case 5:
		printf("FRI");
		break;
	case 6:
		printf("SAT");
		break;
	case 7:
		printf("SUN");
		break;
	}
	printf(" %d.%d.20%d %d:%d:%d\n", date.MonthDay, date.Month, date.Year,
		date.Hour, date.Minute, date.Second);
}


int main()
{
	printf("Amount of bytes that my structure takes - %d\n", sizeof(Date));
	printf("Amount of bytes that tm structure takes - %d\n", sizeof(tm));

	date = { 13, 23, 7, 1, 22 , 5 , 19 };
	PrintDate(date);

	printf("\nEnter a number: "); scanf_s("%d", &X);
	printf("Data struct: ");
	if (X.bites.sign == 1) printf("\n\tnumber is negative\n");
	else if (X.x == 0) printf("\n\tnumber is neutral\n");
	else printf("\n\tnumber is neutral\n");

	printf("Logic operation: ");
	if (X.x < 0) printf("\n\tnumber is negative\n");
	else if (X.x == 0) printf("\n\tnumber is neutral\n");
	else printf("\n\tnumber is positive\n");

	signed char num;
	num = 5 + 127;
	printf("\n5 + 127 = %d\n", num);
	num = 2 - 3;
	printf("2 - 3 = %d\n", num);
	num = -120 - 34;
	printf("-120 - 34 = %d\n", num);
	num = unsigned char(-5);
	printf("unsigned char(-5) = %d\n", num);
	num = 56 & 38;
	printf("56 & 38 = %d\n", num);
	num = 56 | 38;
	printf("56 | 38 = %d\n", num);

	printf("\nEnter a number: "); scanf_s("%f", &fl.x);
	printf("Printing in bits: ");
	printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d",
		fl.bit.x32, fl.bit.x31, fl.bit.x30, fl.bit.x29,
		fl.bit.x28, fl.bit.x27, fl.bit.x26, fl.bit.x25,
		fl.bit.x24, fl.bit.x23, fl.bit.x22, fl.bit.x21,
		fl.bit.x20, fl.bit.x19, fl.bit.x18, fl.bit.x17,
		fl.bit.x16, fl.bit.x15, fl.bit.x14, fl.bit.x13,
		fl.bit.x12, fl.bit.x11, fl.bit.x10, fl.bit.x9,
		fl.bit.x8, fl.bit.x7, fl.bit.x6, fl.bit.x5,
		fl.bit.x4, fl.bit.x3, fl.bit.x2, fl.bit.x1);

	printf("\nPrinting in bytes: ");
	printf("%x %x %x %x", fl.byte.byte4, fl.byte.byte3, fl.byte.byte2, fl.byte.byte1);
	printf("\nSign: %d", fl.evm.sing);
	printf("\nValue order: %d", fl.evm.step);
	printf("\nMantissa: %d", fl.evm.mantissa);
}
