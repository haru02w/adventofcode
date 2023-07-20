#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int box[3];
	int ribbon_length = 0;
	FILE *fp = fopen("../../input.txt", "r");

	while (!feof(fp)) {
		if (fscanf(fp, "%dx%dx%d", &box[0], &box[1], &box[2]) != 3)
			break;

		int last_change_index = -1;
		int smallest[2] = { INT_MAX, INT_MAX };
		for (int j = 0; j < 3; j++) {
			if (box[j] < smallest[0]) {
				last_change_index = j;
				smallest[0] = box[j];
			}
		}
		for (int j = 0; j < 3; j++) {
			if (last_change_index == j)
				continue;

			smallest[1] = box[j] < smallest[1] ? box[j] :
							     smallest[1];
		}

		int wrap_length = 2 * smallest[0] + 2 * smallest[1];
		ribbon_length += box[0] * box[1] * box[2] + wrap_length;
	}

	printf("total: %d\n", ribbon_length);
	fclose(fp);
	return EXIT_SUCCESS;
}
