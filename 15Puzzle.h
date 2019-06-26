#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#define NROW 4
#define NCOL 4

extern void Help(void);
extern void Shuffle(int Board[NROW][NCOL]);
extern void Init(int Board[NROW][NCOL]);
extern void Reset(int Board[NROW][NCOL]);
extern void Left(int Board[NROW][NCOL]);
extern void Right(int Board[NROW][NCOL]);
extern void Up(int Board[NROW][NCOL]);
extern void Down(int Board[NROW][NCOL]);
extern void Print(int Board[NROW][NCOL]);
extern int Check(int Board[NROW][NCOL]);
extern void Logo(void);

extern void TmpShuffle(int Board[NROW][NCOL]);