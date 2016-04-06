#include <stdio.h>
#include <stdlib.h>

#define ROW		10
#define COL		10

int chessboard[ROW][COL];

void print_chessboard(void)
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", chessboard[i][j]);	
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void init_chessboard(void)
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			chessboard[i][j] = rand() % 2;	
		}
	}
	return;
}

int is_valid(int row, int col)
{
	if (row < 0 || row >= ROW)
		return 0;

	if (col < 0 || col >= COL)
		return 0;
	
	return 1;
}

struct direction
{
	int dr;	//delta row
	int dc;	//delta col
	char name[16];
};

typedef struct direction dir_t;

dir_t dirs[4] = 
{
	{-1, 0,"up"},
	{1, 0, "down"},
	{0, 1, "right"},
	{0, -1, "left"},
};

int main(void)
{
	printf("Is there a way out?\n");

	void print_chessboard(void);
	print_chessboard();

	void init_chessboard(void);
	init_chessboard();
	print_chessboard();

	int row, col;
	while (1)
	{
		int ways = 0;
		printf("please input a postition:");
		scanf("%d %d", &row, &col);
		printf("row = %d, col = %d\n", row, col);

		int is_valid(int row, int col);
		if (!is_valid(row, col))
			continue;

		for (int i = 0; i < 4; i++)
		{
			//int check(row, col, dir);
			//ways += check(row, col, dir);

			int nr, nc;	//next row , next col
			dir_t dir;

			dir = dirs[i];
			nr = row + dir.dr;
			nc = col + dir.dc;

			if (is_valid(nr, nc))
			{
				if (0 == chessboard[nr][nc])
				{
					printf("direction %s is ok!\n", dir.name);
					ways++;
				}
			}
		}
		printf("value = %d\n", chessboard[row][col]);
		printf("ways = %d\n", ways);
	}
	return 0;
}
