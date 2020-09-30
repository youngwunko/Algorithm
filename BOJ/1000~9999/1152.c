#include <stdio.h>

int main(void)
{
	int num = 0;
	char alphabet = 0, prev_alphabet;

	alphabet = getchar();
	if (alphabet != '\n')
	{
		if (alphabet == ' ')
			num--;

		do {
			prev_alphabet = alphabet;

			if (alphabet == ' ')
				num++;
		} while ((alphabet = getchar()) != '\n');

		if (prev_alphabet != ' ')
			num++;
	}

	printf("%d\n", num);
	return 0;
}
