#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int floor = 0;
	FILE *fp = fopen("../../input.txt", "r");
	while ((c = fgetc(fp)) != EOF) {
		if (c == '(')
			++floor;
		else if (c == ')')
			--floor;
	}
	fclose(fp);
	printf("%d\n",floor);
	return EXIT_SUCCESS;
}
