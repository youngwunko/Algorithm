#pragma warning(disable : 4996)
#include <stdio.h>

int main(void)
{
	int test_case, student, over_avg_stu, i, j;
	int score[1000];
	double average;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {
		over_avg_stu = 0;
		average = 0;
		scanf("%d", &student);
		for (j = 0; j < student; j++) {
			scanf("%d", &score[j]);
			average += (double)score[j];
		}
		average /= (double)student;

		for (j = 0; j < student; j++) {
			if (score[j] > average) {
				over_avg_stu++;
			}
		}
		printf("%.3lf%%\n", (double)over_avg_stu / student * 100);
	}
	return 0;
}
