#include <stdio.h>
#include <stdlib.h>

struct pos {
	int x;
	int y;
};

int main(void)
{
	char c;
	int flag = 1;
	struct pos santa_pos = { .x = 0, .y = 0 };
	FILE *fp = fopen("../../input.txt", "r");
	struct pos *visited = NULL;
	int visited_count = 0;
	while (flag) {
		int found = 0;
		for (int i = 0; i < visited_count; i++) {
			if (visited[i].x == santa_pos.x &&
			    visited[i].y == santa_pos.y)
				found = 1;
		}

		if (found == 0) {
			visited = realloc(visited,
					  sizeof(struct pos) * ++visited_count);
			visited[visited_count - 1] = (struct pos){
				.x = santa_pos.x,
				.y = santa_pos.y,
			};
		}

		if ((c = fgetc(fp)) == EOF)
			break;
		switch (c) {
		case '^':
			++santa_pos.y;
			break;
		case 'v':
			--santa_pos.y;
			break;
		case '<':
			--santa_pos.x;
			break;
		case '>':
			++santa_pos.x;
			break;
		default:
			flag = 0;
		}
	}

	printf("visited_count: %d\n", visited_count);
	fclose(fp);

	return EXIT_SUCCESS;
}
