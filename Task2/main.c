#include<stdio.h>
#include<math.h>



double eulNum(double euler) {
	double result = 1;
	double fac = 1;
	double euler_x = 1;
	double resultEuler = 1;
	for (int i = 1; i < 10; i++)
	{	
			fac *= i;
			euler_x *= euler;
			resultEuler = euler_x/fac;
		
		result += resultEuler;
	}
	return result;
}
double diff(double euler) {

	double difference = exp(euler) - eulNum(euler);
	return (difference / exp(euler)) * 100;
}

int main(void) {

	double euler;
	do {
		printf("Geben Sie bitte eine Zahl ein, von der der Expotentialwert bestimmt werden soll!\n");
		scanf_s("%lf", &euler);
		if (euler != 0) {
			printf("%lf\n", eulNum(euler));
			printf("Der Unterschied zwischen der richtigen und der errechneten Zahl betr%cgt %lf%%\n", 132, diff(euler));
			printf("Um das Programm zu beenden, geben Sie bitte eine %d ein.\n", 0);
		}
		else
		{
			break;
		}
	} while (1 == 1);
	return 0;
}