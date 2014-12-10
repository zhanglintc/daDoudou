#include "stdafx.h"
#include "stdio.h"
#include "headers.h"


/*******************************************************
Function:
            sort an array from small to large
            
Arguement   :int[], int
Return      :None
*******************************************************/
void Sort_Int(int data[],int length)
{
    int i=0;
    int j=0;
    
    for(i=0;i<length;i++)
    {
        for(j=i;j<length;j++)
        {
            if(data[i]>data[j])
            {
                swap(&data[i],&data[j]);
            }           
        }
    }
}

/*******************************************************
Function:
            sort an array from small to large
            
Arguement   :char[], char[]
Return      :None
*******************************************************/
void Sort_Int(char data[],int length)
{
    int i=0;
    int j=0;
    
    for(i=0;i<length;i++)
    {
        for(j=i;j<length;j++)
        {
            if(data[i]>data[j])
            {
                swap(&data[i],&data[j]);
            }           
        }
    }
}

/*******************************************************
Function:
            Encapsulate strcmp() function for easy use.
            eg: Equal(command,"exit")==true, then exit.
            No need to write as: strcmp(command,"-exit")==0
            
Arguement   :char[], char[]
Return:     equal       :true
            not equal   :false
*******************************************************/
bool Equal(char command_in[], char command_require[])
{
    if(strcmp(command_in,command_require)==0)return true;
    return false;
}

/*******************************************************
Function    :return command and two parameters
Arguement   :char, char, char
Return      :None
Modified:
            1) 2014.03.15 zhanglin
            memset(input,' ',sizeof(input)); to memset(input,'\0',sizeof(input));
            command, parameter load uniformization
*******************************************************/
void GetCommand(char command[COMMAND_STR_LEN], char para_1st[COMMAND_STR_LEN], char para_2nd[COMMAND_STR_LEN])
{
    int     input_loc=0;                                    //cursor of input word
    int     current_loc=0;                                  //cursor of command and parameter
    char    input[INPUT_STRING_LEN];                        //input word string
/*********************************************************************
    
    Eg:
    
    '0' represents '\0'
    Inited:
        input       |0000000000000000000000000|
        cmmand      |0000000000000000000000000|
        1st para    |0000000000000000000000000|

    Entered:
        input(para) |cmd 1stp00000000000000000|
                      |    |
                     cmd   |    ---------   before ' ' is cmd (not ' ')
                      |   1stp  ---------   before ' ' is 1stp
        command     |cmd0000000000000000000000|
        1st para    |1stp000000000000000000000|


        input(nopa) |cmd0000000000000000000000|
                      |
                     cmd        ---------   before 0 is cmd (not 0)
                      |
        command     |cmd0000000000000000000000|

*********************************************************************/
    memset(input,'\0',sizeof(input));                       //initialize input
    memset(command,'\0',COMMAND_STR_LEN);                   //initialize command
    memset(para_1st,'\0',COMMAND_STR_LEN);                  //initialize parameter 1st
    memset(para_2nd,'\0',COMMAND_STR_LEN);                  //initialize parameter 2nd

    gets(input);                                            //get the input
    input[INPUT_STRING_LEN-1]='\0';                         //set the last one as \0 (after input initial ' 'to \0 and uniformization, seems useless 2014.03.15)
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
    /*load command*/
    current_loc=0;                                                                  //current loc clean. clean before load
    while(input[input_loc]!=' '&&input[input_loc]!='\0')                            //load the info to command(all the thing not ' ')
    {
        command[current_loc]=input[input_loc];
        current_loc++;
        input_loc++;
    }
    while(input[input_loc]==' '&&input[input_loc]!='\0')                            //jump over the space(is ' ' and not \0, the end mark)
    {
        input_loc++;
    }
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
    //add the '\0' judge in case of the end of the whole input string
    //from here, it can be the last para

    /*load 1st parameter*/
    current_loc=0;                                                                  //current loc clean. clean before load
    while(input[input_loc]!=' '&&input[input_loc]!='\0')                            //load the inft to para_1st(all the thing not ' ')
    {
        para_1st[current_loc]=input[input_loc];
        current_loc++;
        input_loc++;
    }
    while(input[input_loc]==' '&&input[input_loc]!='\0')                            //jump over the space(is ' ' and not \0, the end mark)
    {
        input_loc++;
    }
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
    //add the '\0' judge in case of the end of the whole input string
    //from here, it can be the last para

    /*load 2nd parameter*/
    current_loc=0;                                                                  //current loc clean. clean before load
    while(input[input_loc]!=' '&&input[input_loc]!='\0')                            //load the inft to para_2nd(all the thing not ' ')
    {
        para_2nd[current_loc]=input[input_loc];
        current_loc++;
        input_loc++;
    }
    //ignore the things after 2nd para
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
}

/*******************************************************
Function:
    Get some bit of a number,
    n1 for the start bit
    n2 for the end bit
Arguement   :int ,char ,char
Return      :None
*******************************************************/
void getbits(int value,char n1,char n2)
{
    //                n1 2 n2    shift to right
    value&=(~(65535<<(n2-n1+1))<<(15-n2));
    value>>=(15-n2);
    printf("%d",value);
}

/*******************************************************
Function    :Get the length of a string
Arguement   :char []
Return      :int
*******************************************************/
//get length of in put string
int GetLength(char data[])
{
    int i=0;
    while(*(data+i)!='\0')
    {
        i++;
    }
    return i;
}

/*******************************************************
Function    :String to Int(with the length you want to change)
Arguement   :char *,int
Return      :int
*******************************************************/
int Str2Int(char *data,int length)
{
    int ret=0;
    //for(int i=0;i<length;i++)
    //{
    //  if(*(data+i)<48||*(data+i)>57)return ERROR_MARK;
    //}
    for(int i=length-1;i>=0;i--)
    {
        ret+=((*(data+length-1-i)-48)*((int)pow(10.0,(int)i)));
    }
    return ret;
}

/*******************************************************
Function    :String to Int(without length)
Arguement   :char []
Return      :int
*******************************************************/
//return value of string,-1 when not valid
int Str2Int(char data[100])
{
    int ret=0;
    int i=0;
    for(i=0;i<GetLength(data);i++)
    {
        if(data[i]<48||data[i]>57)return ERROR_MARK;
    }
    for(i=GetLength(data)-1;i>=0;i--)
    {
        ret+=((data[GetLength(data)-1-i]-48)*((int)pow(10.0,(int)i)));
    }
    return ret;
}

/*******************************************************
Function    :Swap the two data
Arguement   :char *, char *
Return      :None
*******************************************************/
void swap(char *a, char *b) 
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

/*******************************************************
Function    :Swap the two data
Arguement   :int *, int *
Return      :None
*******************************************************/
void swap(int *a, int *b) 
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

/*******************************************************
Function    :Generate a random number
Return      :int
*******************************************************/
int randnum(int min,int max)
{
    if(max<min)Exchange(&min,&max);
    int i=0;
    int randnum=0;
    randnum=rand()%(max-min+1)+min;
    return randnum;
}

/*******************************************************
Function    :Swap two numbers (char)
Arguement   :char char
Return      :None
*******************************************************/
void Exchange(char *a,char *b)
{
    char tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

/*******************************************************
Function    :Swap two numbers (int)
Arguement   :int int
Return      :None
*******************************************************/
void Exchange(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

/*******************************************************
Function    :Calculate the factorial of input number
Arguement   :int
Return      :int
*******************************************************/
int Factorial(int data)
{
    int i,ret=data;
    for(i=data-1;i>0;i--)
    {
        ret*=i;
    }
    return ret;
}

/*******************************************************
Function:
    count length of array. elements of array must 
    be pointer or int or char or something length less 
    than 4. arr is a pointer, point to int, length 4.
    length of pointer is 4, too. thus this function 
    can count an array which elements are pointers.
Arguement:int *
Return:length
*******************************************************/
int CountArrayLength(int *arr)              //point to 4 length datas
{
    int i=0;
    for(i=0;*(arr+i);i++);                  //if arr[i] contains things, i++
    return i;
}
