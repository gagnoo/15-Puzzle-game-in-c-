#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "15Puzzle.h"

void Instructions(void)
{
	printf("1. New Game.\n");
	printf("2. Instructions.\n");
	printf("3. Exit.\n");
}

int main(void)
{
	srand((unsigned int)time(NULL));
	int Board[NROW][NCOL];
	int CountOfMove = 0;
	char MainChoice = ' ', GameChoice = ' ';

	Instructions();
	printf("Enter Choice: ");
	while ((MainChoice = _getch()) != '4')
	{
		switch (MainChoice)
		{
		case '1':
		{
			int IfWon;
			Logo();
			Help();
			Init(Board);
			Print(Board);
			TmpShuffle(Board);
			Sleep(1);
			system("cls");
			while (1)
			{
				Print(Board);
				GameChoice = _getch();
				switch (GameChoice)
				{
				case 'a':
				case 'A':
					Left(Board);
					CountOfMove++;
					break;

				case 'd':
				case 'D':
					Right(Board);
					CountOfMove++;
					break;

				case 'w':
				case 'W':
					Up(Board);
					CountOfMove++;
					break;

				case 's':
				case 'S':
					Down(Board);
					CountOfMove++;
					break;

				case 'q':
				case 'Q':
				{
					char tmpChoice = ' ';
					printf("Are you sure to exit? (Y/n) ");
					tmpChoice = _getch();
					if (tmpChoice == 'y' || tmpChoice == 'Y')
					{
						printf("\nExiting...\n");
						Sleep(1);
						exit(0);
					}
				}break;

				default:
					printf("Unknown Move!!!\n");
					Sleep(1);
					break;
				}

				system("cls");
				Print(Board);
				IfWon = Check(Board);
				if (IfWon == 16)
				{
					printf("Congratulations...\nYou are winner!!\nYou have won about %d moves\n", CountOfMove);
					(void)getchar();
					return 0;
				}
				system("cls");
			}
		}break;

		case '2':
			Help();
			(void)getchar();
			system("cls");
			main();
			break;

		case '3':
			printf("\nExiting...\n");
			Sleep(1);
			exit(0);
			break;

		default:
			printf("Unknown Move!!!\n");
			Sleep(1);
			break;
		}
	}
	system("pause");
	return 0;
}
