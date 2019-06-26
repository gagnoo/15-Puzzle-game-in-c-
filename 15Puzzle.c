#include "15Puzzle.h"

const char* WhiteSpace = "_";

const int TmpResult[NROW][NCOL] =
{
	{0,  1,  2,  3},
	{4,  5,  6,  7},
	{8,  9,  10, 11},
	{12, 13, 14, 15}
};

void Help(void)
{
	printf("\n---------- Instructions ----------\n");
	printf("\tLeft:  'a' or 'A'\n");
	printf("\tRight: 'd' or 'D'\n");
	printf("\tUp:    'w' or 'W'\n");
	printf("\tDown:  's' or 'S'\n");
	printf("\tQuit:  'q' or 'Q'\n");
	printf("----------------------------------\n");
	printf("\n\n");
}

void Logo(void)
{
	printf("\n==============================================\n");
	printf("        The Board is Designed By Gagnoo        \n");
	printf("==============================================\n\n");
}

void Print(int Board[NROW][NCOL])
{
	int i, j;

	printf("------------------------------------\n");
	for (i = 0; i < NROW; i++)
	{
		for (j = 0; j < NCOL; j++)
		{
			printf("| ");
			if (Board[i][j] == 0) printf(" %3s ", WhiteSpace);
			else printf(" %3d ", Board[i][j]);
			printf(" |");
		}
		printf("\n");
	}
	printf("------------------------------------\n");
}

void Init(int Board[NROW][NCOL])
{
	int i, j, count = 0;

	for (i = 0; i < NROW; i++)
		for (j = 0; j < NCOL; j++)
			Board[i][j] = count++;
}

void Shuffle(int Board[NROW][NCOL])
{
	int i, j, tmp, rRow, rCol;

	for (i = 0; i < NROW; i++)
	{
		rRow = rand() % 4;
		rCol = rand() % 4;
		for (j = 0; j < NCOL; j++)
		{
			tmp = Board[i][j];
			Board[i][j] = Board[rRow][rCol];
			Board[rRow][rCol] = tmp;
		}
	}
}

void Left(int Board[NROW][NCOL])
{
	int i, j, tmp;

	for (i = 0; i < NROW; i++)
	{
		for (j = 0; j < NCOL; j++)
		{
			if (Board[i][j] == 0)
			{
				if (j == 0) return;
				tmp = Board[i][j];
				Board[i][j] = Board[i][j - 1];
				Board[i][j - 1] = tmp;
				return;
			}
		}
	}
}

void Right(int Board[NROW][NCOL])
{
	int i, j, tmp;

	for (i = 0; i < NROW; i++)
	{
		for (j = 0; j < NCOL; j++)
		{
			if (Board[i][j] == 0)
			{
				if (j == 3) return;
				tmp = Board[i][j];
				Board[i][j] = Board[i][j + 1];
				Board[i][j + 1] = tmp;
				return;
			}
		}
	}
}

void Up(int Board[NROW][NCOL])
{
	int i, j, tmp;

	for (i = 0; i < NROW; i++)
	{
		for (j = 0; j < NCOL; j++)
		{
			if (Board[i][j] == 0)
			{
				if (i == 0) return;
				tmp = Board[i][j];
				Board[i][j] = Board[i - 1][j];
				Board[i - 1][j] = tmp;
				return;
			}
		}
	}
}

void Down(int Board[NROW][NCOL])
{
	int i, j, tmp;

	for (i = 0; i < NROW; i++)
	{
		for (j = 0; j < NCOL; j++)
		{
			if (Board[i][j] == 0)
			{
				if (i == 3) return;
				tmp = Board[i][j];
				Board[i][j] = Board[i + 1][j];
				Board[i + 1][j] = tmp;
				return;
			}
		}
	}
}

void TmpShuffle(int Board[NROW][NCOL])
{
	int i, j, tmp;

	for (i = 0; i < NROW; i++)
	{
		for (j = 0; j < NCOL; j++)
		{
			if (Board[i][j] == 0)
			{
				tmp = Board[i][j];
				Board[i][j] = Board[i][j + 1];
				Board[i][j + 1] = tmp;
				return;
			}
		}
	}
}

int Check(int Board[NROW][NCOL])
{
	int i, j, RetVal = 0;

	for (i = 0; i < NROW; i++)
	{
		for (j = 0; j < NCOL; j++)
		{
			if (Board[i][j] == TmpResult[i][j])
				RetVal++;
			else
				RetVal--;
		}
	}
	return RetVal;
}

void Reset(int Board[NROW][NCOL])
{
	Init(Board);
	Shuffle(Board);
}