#include "WinApiHelp.h"

HANDLE winHandle = 0;//���

/**
 * ���þ��
 */
void setWinHandle()
{
    if(winHandle==0)
      winHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨���
}

/**
 * ���ÿ���̨����
 * title ����
 */
void setTitle(char*title)
{
   SetConsoleTitle(TEXT(title));
}

/**
 * ���ÿ���̨���ڵĴ�С
 * height ����ĸ߶�
 * width  ����Ŀ��
 */
void setConsoleSize(int width,int height)
{
    SMALL_RECT rect = {0,0,width-1,height-1};//����Ĵ�С�������-�յ㣩
    COORD coord = {width,height};//������������
    setWinHandle();
    SetConsoleScreenBufferSize(winHandle,coord);//���û�����
    SetConsoleWindowInfo(winHandle,TRUE,&rect);//���ô���Ĵ�С
}

/**
 * ���ù���λ��
 * x x������
 * y y������
 */
void setPosition(int x,int y)
{
    COORD pos = {x,y};
    setWinHandle();
    SetConsoleCursorPosition(winHandle,pos);
}

/**
 * ���ô������ֵ���ɫ
 * color ��һ��ʮ�����������Ʊ���ɫ���ڶ���ʮ������������ǰ��ɫ
 */
void setColor(int color)
{
    setWinHandle();
    SetConsoleTextAttribute(winHandle,color);
}

/**
 * ������
 * x,y ����
 * color ��ɫ
 * letter �����ߵ���ĸ
 * len ����
 */
void drawhLine(int x,int y,int color,char letter,int len)
{
   int i;
   setColor(color);
   setPosition(x,y);
   for(i=0;i<len;i++)
   {
      printf("%c",letter);
   }
}

/**
 * �������
 * x,y ����
 * color ��ɫ
 * letter ������ߵ���ĸ
 * len ����
 */
void drawsline(int x,int y,int color,char letter,int len)
{
    int i;
    setColor(color);
    for(i=0;i<len;i++)
    {
        setPosition(x,y+i);
        printf("%c",letter);
    }
}

/**
 * ��ӡ�˵�����
 * x,y ����
 * color ������ɫ
 * text �˵�����
 * size ���ֿ��
 */
void printText(int x,int y,int color,char* text,int size)
{
    char format[20] = "%-";
    char sizebuff[5];
    itoa(size,sizebuff,10);
    strcat(format,sizebuff);
    strcat(format,"s");
    setPosition(x,y);
    setColor(color);
    printf(format,text);
}

/**
 * �����Ϸ��
 * x,y ����
 * color ����������ɫ
 * width ���Ŀ��
 * height ���ĸ߶�
 */
void fillGamePart(int x,int y,int color,int width,int height,int letter)
{
   COORD coord = {x,y};//��俪ʼ��λ��
   setWinHandle();
   DWORD relen;//����ֵ
   int i,X,Y;
   X = x+1;
   Y = y+2;
   COORD coord2 = {X,Y};// ����ַ���ʼ��λ��
   for(i=0;i<height;i++)
   {
       coord.Y++;
       FillConsoleOutputAttribute(winHandle,color,width,coord,&relen);
   }
   for(i=0;i<height-3;i++)
   {
       coord2.Y++;
       FillConsoleOutputCharacter(winHandle,letter,width-2,coord2,&relen);
   }
}

/**
 * �Ӽ��̻�ȡ�ַ�
 */
char getChar()
{
    char rechar = 0;
    if(kbhit())
    {
        rechar = getch();
    }
    return rechar;
}

/**
 * ���ع��
 */
void hideCursor()
{
    setWinHandle();
    CONSOLE_CURSOR_INFO cursor_info;
    cursor_info.bVisible = FALSE;
    cursor_info.dwSize = 1;
    SetConsoleCursorInfo(winHandle,&cursor_info);
}
