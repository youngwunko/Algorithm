#include <stdio.h>

int main(void)
{
	int alphabet[26];
	char temp;
	int result = 0;
	int test_case, i, j;
	char word[101];

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++)
	{
		for (j = 0; j < 26; j++)
			alphabet[j] = 0;

		result++;
		scanf("%s", word);
		temp = word[0];
		for (j = 1; word[j] != '\0'; j++)
		{
			if (alphabet[word[j] - 97] == 0)
			{
				if (word[j] != temp)
					alphabet[word[j - 1] - 97] = 1;
			}
			else
			{
				result--;
				break;
			}
			temp = word[j];
		}
	}
	printf("%d\n", result);
	return 0;
}
