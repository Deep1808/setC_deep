#include<stdio.h>

void add(double a,double b)
{
	printf("Addition: %lf", a+b);
}

void sub(double a,double b)
{
	printf("Subtraction: %lf", a-b);
}

void mul(double a,double b)
{
	printf("Multiplucation: %lf", a*b);
}

void div(double a,double b)
{
	printf("Division: %lf",a/b);
}

int main()
{
	double a,b;
	int ch;
	void (*ptr[])(double,double) = {add, sub, mul, div};
	printf("Enter any 2 numbers of your choice:\n");
	scanf("%lf %lf",&a,&b);

	printf("Arthimatic Operation\nFor Addition - 0\nFor Subtraction - 1\nFor Nultiplication - 2\nFor Division - 3\nEnter Choice:");
	scanf("%d",&ch);

	(*ptr[ch])(a,b);
	return 0;
}

	

