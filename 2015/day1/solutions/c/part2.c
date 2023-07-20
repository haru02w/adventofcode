#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int floor = 0;
	int char_pos = 0;
	FILE *fp = fopen("../../input.txt", "r");
	while ((c = fgetc(fp)) != EOF) {
		++char_pos;
		if (c == '(')
			++floor;
		else if (c == ')')
			--floor;
		if (floor == -1)
			break;
	}
	fclose(fp);
	printf("%d\n", char_pos);
	return EXIT_SUCCESS;
}
