/*
Generate the doudou Game
*/

#include "stdafx.h"
#include "headers.h"

#define COLOR_GEN_NONE				10									//doudou color from 0 to 9. 10 means no color. different from dadoudou.cpp
#define COLOR_TYPE_MAX				10									//types of doudou's color
#define COLOR_VISIBLE				1									//visible means show it in screen
#define COLOR_INVISIBLE				0									//invisible means not show in screen
#define ROW_MAX 					17									//row max, horizontal --
#define LINE_MAX 					23									//line max, vertical  |


void DataGen();
void doudouGenMain();
void doudouInit();
void douClick(int row, int line);
int upSe(int *row,int *line);
int rightSe(int *row,int *line);
int downSe(int *row,int *line);
int leftSe(int *row,int *line);
void douProcess(int rowIn,int lineIn);

MAIN_GRID grid[17][23];
int score=0;

void doudouGenMain()												//main function of the game, generate and deal with the click
{
	doudouInit();
	//here only init the display
	//you should call Dadoudou function to continue the whole thing
}

void douProcess(int rowIn, int lineIn)	//this is used to handle things after Dadoudou plug-in is called
{	int row,line;

	//while(true)
	{
		printf("      ");											//space to adjust the display form
		for(line=1;line<=23;line++)									//show the line number
		{
			printf(" %2d",line);
		}
		printf("\n");
		printf("      ");											//space to adjust
		for(line=1;line<=23;line++)									//show the up arrow
		{
			printf(" ¡ü");
		}
		printf("\n\n");
//---------------------------------------------------------------
		for(row=0;row<17;row++)										//row from up to down
		{
			printf("%2d¡û  |",row+1);								//print the row number
			for(line=0;line<23;line++)								//line from left to right
			{
				if(row==rowIn&&line==lineIn)
				{
					printf("¡ö|");
					continue;
				}
				if(grid[row][line].isDisplay==COLOR_INVISIBLE)					//if undiplay, print space
				{
					printf("  |");									//space
					continue;
				}
				printf(" %d|",grid[row][line].color);				//end of each line
			}
			printf("\n");
		}
		//getchar();												//pause
		//system("cls");											//clear the screen
	}
}//end of douProcess(int, int)

void douClick(int row, int line)
{
	int counted=0;													//flag of score counted or not
	
	int rowUp,lineUp;												//store the four directions' data
	int rowRi,lineRi;												//store the four directions' data
	int rowDo,lineDo;												//store the four directions' data
	int rowLe,lineLe;												//store the four directions' data

	int colorUp;													//store the four directions' color
	int colorRi;													//store the four directions' color
	int colorDo;													//store the four directions' color
	int colorLe;													//store the four directions' color

	rowUp=row;	lineUp=line;										//get the current position
	rowRi=row;	lineRi=line;										//get the current position
	rowDo=row;	lineDo=line;										//get the current position
	rowLe=row;	lineLe=line;										//get the current position

	colorUp=upSe(&rowUp,&lineUp);									//up
	colorRi=rightSe(&rowRi,&lineRi);								//right
	colorDo=downSe(&rowDo,&lineDo);									//down
	colorLe=leftSe(&rowLe,&lineLe);									//left
//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------4 points gain¡ý
	if(colorUp==colorRi && colorRi==colorDo && colorDo==colorLe && colorUp!=COLOR_GEN_NONE)
	{
		grid[rowUp][lineUp].isDisplay=COLOR_INVISIBLE;
		grid[rowRi][lineRi].isDisplay=COLOR_INVISIBLE;
		grid[rowDo][lineDo].isDisplay=COLOR_INVISIBLE;
		grid[rowLe][lineLe].isDisplay=COLOR_INVISIBLE;
		score+=4;
		counted=1;
	}
//----------------------------------------------------------------4 points gain¡ü
	if(counted==1)return;//if this click gain 4 points, there is no possibility to gain 3 or 2 points
//----------------------------------------------------------------3 points gain¡ý
	if(colorUp==colorRi && colorRi==colorDo && colorUp!=COLOR_GEN_NONE)
	{
		grid[rowUp][lineUp].isDisplay=COLOR_INVISIBLE;
		grid[rowRi][lineRi].isDisplay=COLOR_INVISIBLE;
		grid[rowDo][lineDo].isDisplay=COLOR_INVISIBLE;
		score+=3;
		counted=1;
	}
	if(colorUp==colorDo && colorDo==colorLe && colorUp!=COLOR_GEN_NONE)
	{
		grid[rowUp][lineUp].isDisplay=COLOR_INVISIBLE;
		grid[rowDo][lineDo].isDisplay=COLOR_INVISIBLE;
		grid[rowLe][lineLe].isDisplay=COLOR_INVISIBLE;
		score+=3;
		counted=1;
	}
	if(colorRi==colorDo && colorDo==colorLe && colorRi!=COLOR_GEN_NONE)
	{
		grid[rowRi][lineRi].isDisplay=COLOR_INVISIBLE;
		grid[rowDo][lineDo].isDisplay=COLOR_INVISIBLE;
		grid[rowLe][lineLe].isDisplay=COLOR_INVISIBLE;
		score+=3;
		counted=1;
	}
//----------------------------------------------------------------3 points gain¡ü
	if(counted==1)return;//if this click gain 3 points, there is no possibility to gain 2 points
//----------------------------------------------------------------2 points gain¡ý
	if(colorUp==colorRi && colorUp!=COLOR_GEN_NONE)
	{
		grid[rowUp][lineUp].isDisplay=COLOR_INVISIBLE;
		grid[rowRi][lineRi].isDisplay=COLOR_INVISIBLE;
		score+=2;
		counted=1;
	}
	if(colorUp==colorDo && colorUp!=COLOR_GEN_NONE)
	{
		grid[rowUp][lineUp].isDisplay=COLOR_INVISIBLE;
		grid[rowDo][lineDo].isDisplay=COLOR_INVISIBLE;
		score+=2;
		counted=1;
	}
	if(colorUp==colorLe && colorUp!=COLOR_GEN_NONE)
	{
		grid[rowUp][lineUp].isDisplay=COLOR_INVISIBLE;
		grid[rowLe][lineLe].isDisplay=COLOR_INVISIBLE;
		score+=2;
		counted=1;
	}
	if(colorRi==colorDo && colorRi!=COLOR_GEN_NONE)
	{
		grid[rowRi][lineRi].isDisplay=COLOR_INVISIBLE;
		grid[rowDo][lineDo].isDisplay=COLOR_INVISIBLE;
		score+=2;
		counted=1;
	}
	if(colorRi==colorLe && colorRi!=COLOR_GEN_NONE)
	{
		grid[rowRi][lineRi].isDisplay=COLOR_INVISIBLE;
		grid[rowLe][lineLe].isDisplay=COLOR_INVISIBLE;
		score+=2;
		counted=1;
	}
	if(colorDo==colorLe && colorDo!=COLOR_GEN_NONE)
	{
		grid[rowDo][lineDo].isDisplay=COLOR_INVISIBLE;
		grid[rowLe][lineLe].isDisplay=COLOR_INVISIBLE;
		score+=2;
		counted=1;
	}
//----------------------------------------------------------------2 points gain¡ü
	//if(counted==1)return;		//return		//2014.03.13 ˆ÷ë Ÿo„¿¤Ë¤Ê¤ë
	return;										//2014.03.13 ˆ÷ë ÐÂÒŽ¡¢return anyway


	/*					
	4					
	¡ü¡ú¡ý¡û			
						
	3					
	¡ü¡ú¡ý				
	¡ü¡ú¡û				
	¡ü¡ý¡û				
	¡ú¡ý¡û				
						
	2					
	¡ü¡ú				
	¡ü¡ý				
	¡ü¡û				
	¡ú¡ý				
	¡ú¡û				
	¡ý¡û				
						
	*/					
}

/****************************************************************************************/
int upSe(int *row,int *line)
{
	for(*row;*row>=0;*row-=1)											//up search, to the first line
	{
		if(grid[*row][*line].isDisplay!=COLOR_INVISIBLE)								//if there is doudou
		{
			return grid[*row][*line].color;								//return the color and back
		}
	}
	return COLOR_GEN_NONE;												//nothing found
}
/****************************************************************************************/
int rightSe(int *row,int *line)
{
	for(*line;*line<LINE_MAX;*line+=1)									//right search, to the first line
	{
		if(grid[*row][*line].isDisplay!=COLOR_INVISIBLE)								//if there is doudou
		{
			return grid[*row][*line].color;								//return the color and back
		}
	}
	return COLOR_GEN_NONE;												//nothing found
}
/****************************************************************************************/
int downSe(int *row,int *line)
{
	for(*row;*row<ROW_MAX;*row+=1)										//down search, to the first line
	{
		if(grid[*row][*line].isDisplay!=COLOR_INVISIBLE)								//if there is doudou
		{
			return grid[*row][*line].color;								//return the color and back
		}
	}
	return COLOR_GEN_NONE;												//nothing found
}
/****************************************************************************************/
int leftSe(int *row,int *line)
{

	for(*line;*line>=0;*line-=1)										//down search, to the first line
	{
		if(grid[*row][*line].isDisplay!=COLOR_INVISIBLE)								//if there is doudou
		{
			return grid[*row][*line].color;								//return the color and back
		}
	}
	return COLOR_GEN_NONE;												//nothing found
}
/****************************************************************************************/

void DataGen(int randnum_list[345])					//generate the data, return the randnum list
{	
	int valid_count=0;
	int tmp=0;
	
	while(true)
	{
		tmp=randnum(1,1500);						//required num from 0 to 9. but the randnum() function is not real rand. so the max is 15. larger than reguired.
		
		if(    1<=tmp&&tmp<= 100)tmp= 0;
		if(  101<=tmp&&tmp<= 200)tmp= 1;
		if(  201<=tmp&&tmp<= 300)tmp= 2;
		if(  301<=tmp&&tmp<= 400)tmp= 3;
		if(  401<=tmp&&tmp<= 500)tmp= 4;
		if(  501<=tmp&&tmp<= 600)tmp= 5;
		if(  601<=tmp&&tmp<= 700)tmp= 6;
		if(  701<=tmp&&tmp<= 800)tmp= 7;
		if(  801<=tmp&&tmp<= 900)tmp= 8;
		if(  901<=tmp&&tmp<=1000)tmp= 9;
		if( 1001<=tmp&&tmp<=1500)tmp=10;
		
		if(!CheckColor(tmp))continue;				//check the random number. if it is full, then continue.
		if(tmp>9)tmp=10;							//if tmp is larger than 9, set it as 10
		randnum_list[valid_count++]=tmp;			//put tmp into randnum_list
		if(valid_count>344)break;					//if randnum_list if full, then break
	}
}//end of DataGen(int)

void doudouInit()									//initial the game. show the first screen
{
	int row,line;
	int randnum_list[345];

	memset(randnum_list,0x00,sizeof(randnum_list));
	
	printf("current posistion: (#,#)\n");
	printf("current score:%d\n\n",score);
//initial the grid, all can be seen, 
//except the first and the last row
	for(row=0;row<17;row++)											//row from up to down
	{
		for(line=0;line<23;line++)									//line from left to right
		{
			grid[row][line].isDisplay=COLOR_VISIBLE;				//All can be seen
		}
	}

	DataGen(randnum_list);											//get the randnum_list

//set the data into the grid
	for(row=0;row<17;row++)											//row from up to down
	{
		for(line=0;line<23;line++)									//line from left to right
		{
			if(row==0||row==16)
			{
				grid[row][line].isDisplay=COLOR_INVISIBLE;
				continue;
			}
			grid[row][line].color=randnum_list[23*(row-1)+line];		//set grid data
			if(randnum_list[23*(row-1)+line]==COLOR_GEN_NONE)			//if data is 10, then set it as undisplay
			{
				//grid[row][line].color=0;							//useless. only for debug
				grid[row][line].isDisplay=COLOR_INVISIBLE;						//undisplay
			}
		}
	}

//display the gird data on the screen
	while(true)
	{
		printf("      ");											//space to adjust the display form
		for(line=1;line<=23;line++)									//show the line number
		{
			printf(" %2d",line);
		}
		printf("\n");
		printf("      ");											//space to adjust
		for(line=1;line<=23;line++)									//show the up arrow
		{
			printf(" ¡ü");
		}
		printf("\n\n");
//---------------------------------------------------------------first row¡ü
//---------------------------------------------------------------other row¡ý
		for(row=0;row<17;row++)										//row from up to down
		{
			printf("%2d¡û  |",row+1);								//print the row number
			for(line=0;line<23;line++)								//line from left to right
			{
				if(grid[row][line].isDisplay==COLOR_INVISIBLE)					//if undiplay, print space
				{
					printf("  |");									//space
					continue;
				}
				printf(" %d|",grid[row][line].color);				//end of each line
			}
			printf("\n");
		}
		//getchar();												//pause
		system("cls");												//clear the screen
		break;														//break this while. this while() is useless now. it is useful only when debug
	}
}//end of doudouInit()

bool CheckColor(int color)									//check if the required color number is full
{
	static int color_count[11];
	switch(color)
	{
	case 0:													//case of color 0
		color_count[0]++;
		if(color_count[0]>20)return false;
		break;
	case 1:													//case of color 1
		color_count[1]++;
		if(color_count[1]>20)return false;
		break;
	case 2:													//case of color 2
		color_count[2]++;
		if(color_count[2]>20)return false;
		break;
	case 3:													//case of color 3
		color_count[3]++;
		if(color_count[3]>20)return false;
		break;
	case 4:													//case of color 4
		color_count[4]++;
		if(color_count[4]>20)return false;
		break;
	case 5:													//case of color 5
		color_count[5]++;
		if(color_count[5]>20)return false;
		break;
	case 6:													//case of color 6
		color_count[6]++;
		if(color_count[6]>20)return false;
		break;
	case 7:													//case of color 7
		color_count[7]++;
		if(color_count[7]>20)return false;
		break;
	case 8:													//case of color 8
		color_count[8]++;
		if(color_count[8]>20)return false;
		break;
	case 9:													//case of color 9
		color_count[9]++;
		if(color_count[9]>20)return false;
		break;
	}
	if(color>9)												//case of not display
	{
		color_count[10]++;
		if(color_count[10]>145)return false;
	}
	return true;
}//end of CheckColor(int color)


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


