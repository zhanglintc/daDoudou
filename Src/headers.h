/*******************************************************************************/
//includes
/*******************************************************************************/
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "limits.h"

/*******************************************************************************/
//defines
/*******************************************************************************/
#define MIN_WORD_LENGTH			0
#define INPUT_STRING_LEN		300
#define COMMAND_STR_LEN			100
#define ERROR_MARK				-1


#define ui_8					unsigned char
#define si_8					signed char
#define ui_16					unsigned int
#define si_16					signed int
#define uchar					unsigned char
#define uint					unsigned int
#define byte					unsigned char


/*******************************************************************************/
//typedefs
/*******************************************************************************/

//-------------------------------------------------------------------------------------
typedef struct
{
	int color;					//the color of the doudou
	int isDisplay;				//1 for display, 0 for not display
}MAIN_GRID;
//-------------------------------------------------------------------------------------



/*******************************************************************************/
//externs
/*******************************************************************************/


/*******************************************************************************/
//sturctures
/*******************************************************************************/



/*******************************************************************************/
//functions
/*******************************************************************************/

//void
void CalcDate(int ,int ,int );
void DateCalcMain();
void Sort_Str(char *data[10]);
void Sort_Int(int data[],int length);
void Sort_Int(char data[],int length);
void DataGen();
void doudouGenMain();
void doudouInit();
void douClick(int row, int line);
void douProcess(int rowIn,int lineIn);
void recursion();
void swap(char *a, char *b);
void swap(int *a, int *b);
void Exchange(int *a,int *b);
void Exchange(char *a,char *b);


//int
int GetLength(char []);
int Str2Int(char []);
int Str2Int(char *,int );
int Str2Int(char *,int );
int Factorial(int data);
int randnum(int min,int max);
int roll(char *para);
int CountArrayLength(int arr[]);
int upSe(int *row,int *line);
int rightSe(int *row,int *line);
int downSe(int *row,int *line);
int leftSe(int *row,int *line);

//bool
bool CheckData(char [],char [],int ,int ,int);
bool CheckColor(int );


/*******************************************************************************/
/*******************************************************************************/