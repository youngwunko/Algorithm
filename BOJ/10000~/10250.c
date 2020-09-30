int main(void)
{
	int test_case, H, W, N, i;
	int x, y;

	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++)
	{
		scanf("%d%d%d", &H, &W, &N);
		x = N % H;
		y = N / H;

		if (x == 0)
		{
			x = H;
			y--;
		}
		printf("%d\n", x * 100 +  y+1);
	}
	return 0;
}
