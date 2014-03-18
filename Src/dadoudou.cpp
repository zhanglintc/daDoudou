/********************************************************************************************
																							*
	This is the core Algorithm of the game DaDouDou's Plug-In gernerated by Lane.			*
	For now, it is written by C language and can only show what I'm thinking about.			*
	It can be compiled but doesn't make any sense. At last, it will be realized by			*
	Quick Macro by using this Algorithm. 													*
																							*
	The Algorithm is to scan each row and each line. If there is no DouDou in current		*
	box, then search up,right,down and left to get the four directions' color information.	*
	If among the four directions, there are 2 or 4 directions are have the same color,		*
	then, Single Left Click to eliminate the DouDous. Repeatedly do the works above till	*
	the game is over.																		*
																	--by Lane 2013/06/11	*
*********************************************************************************************/

#include "stdafx.h"
#include "headers.h"

//Macro defines
#define COLOR_NONE					10									//no doudou
#define COLOR_TYPE_MAX				10									//types of doudou's color
#define COLOR_VISIBLE				1									//visible means show it in screen -- 2014.03.13 zhanglin (change number to defines)
#define COLOR_INVISIBLE				0									//invisible means not show in screen -- 2014.03.13 zhangllin (change number to defines)
#define ROW_MAX 					17									//row max, horizontal --
#define LINE_MAX 					23									//line max, vertical  |

//Functions declaration
void DaDouDou(void);
bool GameOverCheck(void);
bool ClickCheck(int row,int line);
int upSearch(int row,int line);
int rightSearch(int row,int line);
int downSearch(int row,int line);
int leftSearch(int row,int line);
void Click(int row,int line);
int GetColor(int row,int line);
bool ColorCount(int color_up,int color_right,int color_down,int color_left);
extern void douProcess(int,int);

extern MAIN_GRID grid[17][23];
extern int score;

//Main functions begin
void DaDouDou()										//plug-in Main process
{
	int color=0;									//store the color data
	int row=0;
	int line=0;
	int cnt=0;
	
	while(GameOverCheck())							//while not GameOverCheck, process
	{	
		for(row=0;row<ROW_MAX;row++)				//row scan    ¡ý
		{
			for(line=0;line<LINE_MAX;line++)		//line scan   ¡ú
			{
				color=GetColor(row,line);					//get the state information
				if(color==COLOR_NONE)				//if no Doudou here, then judge Click or not
				{
					//printf("Click or Not:No!\n");
					if(ClickCheck(row,line))			//Click check
					{
						system("cls");
						printf("current posistion: (%d,%d)\n",row+1,line+1);
						printf("current score:%d\n\n",score);
						douProcess(row,line);
						Click(row,line);															//just do it !!!
						getchar();
					}
					if(391*10==cnt++)
					{
						cnt=0;
						system("cls");
						printf("current posistion: (%d,%d)\n",row+1,line+1);
						printf("current score:%d\n\n",score);
						douProcess(row,line);
						getchar();
					}
				}
			}
		}
	}
}

bool GameOverCheck()										//GameOverCheck function
{
	/*
	here is main body,
	TRUE means GAMEing
	FALSE means GAME OVER
	*/
	return true;											//default return
}

bool ClickCheck(int row,int line)											//ClickCheck function
{																			//clockwise search. up rihgt down left.
	int color_up=COLOR_NONE;
	int color_right=COLOR_NONE;
	int color_down=COLOR_NONE;
	int color_left=COLOR_NONE;
	
	color_up=upSearch(row,line);													//up
	color_right=rightSearch(row,line);												//ritht
	color_down=downSearch(row,line);												//down
	color_left=leftSearch(row,line);												//left
	if(ColorCount(color_up,color_right,color_down,color_left)==true)				//meet the condition, then Click
	{
		return true;
	}
	return false;
}

/****************************************************************************************/
int upSearch(int row,int line)
{
	int i=0;

	for(row;row>=0;row--)											//up search, to the first line
	{
		if(GetColor(row,line)!=COLOR_NONE)									//if there is doudou
		{
			return GetColor(row,line);										//return the color and back
		}
	}
	return COLOR_NONE;												//nothing found
}
/****************************************************************************************/
int rightSearch(int row,int line)
{
	int i=0;

	for(line;line<LINE_MAX;line++)										//right search, to the first line
	{
		if(GetColor(row,line)!=COLOR_NONE)									//if there is doudou
		{
			return GetColor(row,line);										//return the color and back
		}
	}
	return COLOR_NONE;												//nothing found
}
/****************************************************************************************/
int downSearch(int row,int line)
{
	int i=0;

	for(row;row<ROW_MAX;row++)										//down search, to the first line
	{
		if(GetColor(row,line)!=COLOR_NONE)									//if there is doudou
		{
			return GetColor(row,line);										//return the color and back
		}
	}
	return COLOR_NONE;												//nothing found
}
/****************************************************************************************/
int leftSearch(int row,int line)
{
	int i=0;

	for(line;line>=0;line--)											//down search, to the first line
	{
		if(GetColor(row,line)!=COLOR_NONE)									//if there is doudou
		{
			return GetColor(row,line);										//return the color and back
		}
	}
	return COLOR_NONE;												//nothing found
}
/****************************************************************************************/
void Click(int row,int line)
{
	/*
	here is main body,
	Single Left Click*/
	douClick(row,line);
}

int GetColor(int row,int line)
{
	/*
	here is main body,
	if there is doudou,
	return the color data.
	*/
	if(grid[row][line].isDisplay==COLOR_INVISIBLE)
	{
		return COLOR_NONE;
	}
	else
	{
	
		return grid[row][line].color;
	}
	//return 0;
}

bool ColorCount(int color_up,int color_right,int color_down,int color_left)		//count the colors and judge CLICK or NOT
{
	int color_data[COLOR_TYPE_MAX];
	int this_color;
	int i=0;
	int j=0;

	memset(color_data,0x00,sizeof(color_data));
	
	for(i=1;i<=4;i++)															//four directions cover
	{
		switch(i)																//get this color
		{
		case 1:
			this_color=color_up;	break;
		case 2:
			this_color=color_right;	break;
		case 3:
			this_color=color_down;	break;
		case 4:
			this_color=color_left;	break;
		}
		for(j=0;j<COLOR_TYPE_MAX;j++)											//all color cover
		{
			if(this_color==j)													//if this color equals the color in the array
			{
				color_data[j]+=1;												//array count ++
			}
		}
	}
	
	for(i=0;i<COLOR_TYPE_MAX;i++)												//scan the color_data[] data
	{
		if(color_data[i]==4)return true;										//two doudous are the same color, CLICK
		if(color_data[i]==2)return true;										//all doudous are the same color, CLICK
	}
	return false;																//default return false
}


/*
line¡ú		LINE_MAX
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õrow
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡ý
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ
¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õROW_MAX
*/

