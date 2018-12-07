#include "WinApiHelp.h"

HANDLE winHandle = 0;//句柄

/**
 * 设置句柄
 */
void setWinHandle()
{
    if(winHandle==0)
      winHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台句柄
}

/**
 * 设置控制台标题
 * title 标题
 */
void setTitle(char*title)
{
   SetConsoleTitle(TEXT(title));
}

/**
 * 设置控制台窗口的大小
 * height 窗体的高度
 * width  窗体的宽度
 */
void setConsoleSize(int width,int height)
{
    SMALL_RECT rect = {0,0,width-1,height-1};//窗体的大小区域（起点-终点）
    COORD coord = {width,height};//缓冲区的区域
    setWinHandle();
    SetConsoleScreenBufferSize(winHandle,coord);//设置缓冲区
    SetConsoleWindowInfo(winHandle,TRUE,&rect);//设置窗体的大小
}

/**
 * 设置光标的位置
 * x x轴坐标
 * y y轴坐标
 */
void setPosition(int x,int y)
{
    COORD pos = {x,y};
    setWinHandle();
    SetConsoleCursorPosition(winHandle,pos);
}

/**
 * 设置窗体文字的颜色
 * color 第一个十六进制数控制背景色，第二个十六进制数控制前景色
 */
void setColor(int color)
{
    setWinHandle();
    SetConsoleTextAttribute(winHandle,color);
}

/**
 * 描绘横线
 * x,y 坐标
 * color 颜色
 * letter 描绘横线的字母
 * len 长度
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
 * 描绘竖线
 * x,y 坐标
 * color 颜色
 * letter 描绘竖线的字母
 * len 长度
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
 * 打印菜单文字
 * x,y 坐标
 * color 文字颜色
 * text 菜单文字
 * size 文字宽距
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
 * 填充游戏区
 * x,y 坐标
 * color 填充区域的颜色
 * width 填充的宽度
 * height 填充的高度
 */
void fillGamePart(int x,int y,int color,int width,int height,int letter)
{
   COORD coord = {x,y};//填充开始的位置
   setWinHandle();
   DWORD relen;//返回值
   int i,X,Y;
   X = x+1;
   Y = y+2;
   COORD coord2 = {X,Y};// 填充字符开始的位置
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
 * 从键盘获取字符
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
 * 隐藏光标
 */
void hideCursor()
{
    setWinHandle();
    CONSOLE_CURSOR_INFO cursor_info;
    cursor_info.bVisible = FALSE;
    cursor_info.dwSize = 1;
    SetConsoleCursorInfo(winHandle,&cursor_info);
}
