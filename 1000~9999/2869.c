#include <stdio.h>
#include <math.h>

int main(void)
{
	double A, B, V;
	int day;
	scanf("%lf%lf%lf", &A, &B, &V);

	day = (int)ceil((V - A) / (A - B)) + 1;
	printf("%d\n", day);
	return 0;
}
