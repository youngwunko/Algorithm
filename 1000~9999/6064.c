#include <stdio.h>

int main(void)
{
	int test_case, M, N, x, y, i;
	int flag, p, q;

	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++)
	{
		scanf("%d%d%d%d", &M, &N, &x, &y);

		p = 0; flag = 0;

		for (q = 0; q < ((M >= N) ? M : N); q++)
		{
			while (1)
			{
				if (q*N + y <= p*M + x)
					break;
				p++;
			}
			if (q*N + y == p*M + x)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			printf("%d\n", q*N + y);
		else
			printf("-1\n");
	}
	return 0;
}
