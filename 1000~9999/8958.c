#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int test_case, score = 0, correct = 0;
	char answer;
	int i, *arr;

	scanf("%d", &test_case);
	arr = (int*)malloc(sizeof(int) * test_case);
	getchar();

	for (i = 0; i < test_case; i++)
	{
		while ((answer = getchar()) != '\n')
		{
			if (answer != 'X')
			{
				correct++;
			}
			else
			{
				score += correct * (correct + 1) / 2;
				correct = 0;
			}
		}
        score += correct * (correct + 1) / 2;
	    correct = 0;
		arr[i] = score;
		score = 0;
	}

	for (i = 0; i < test_case; i++)
	{
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}
