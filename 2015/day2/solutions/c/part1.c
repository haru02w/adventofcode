#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int box[3];
	int total_area = 0;
	FILE *fp = fopen("../../input.txt", "r");

	while (!feof(fp)) {
		if (fscanf(fp, "%dx%dx%d", &box[0], &box[1], &box[2]) != 3)
			break;

		//that's really gross, but it works. I should had split in 'ifs' statements
		int smallest_side = box[0] * box[1] < box[1] * box[2] ?
					    (box[0] * box[1] < box[2] * box[0] ?
						     box[0] * box[1] :
						     box[2] * box[0]) :
					    (box[1] * box[2] < box[2] * box[0] ?
						     box[1] * box[2] :
						     box[2] * box[0]);

		total_area += 2 * (box[0] * box[1] + box[1] * box[2] +
				   box[2] * box[0]) +
			      smallest_side;
	}

	printf("total: %d\n", total_area);
	fclose(fp);
	return EXIT_SUCCESS;
}
