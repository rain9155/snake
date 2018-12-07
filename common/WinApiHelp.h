#ifndef WINAPIHELP_H_INCLUDED
#define WINAPIHELP_H_INCLUDED

/**
*描述：windowsApi头文件
*作者：陈健宇
*时间：2018-2-8  21:49
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
/**
 * 设置控制台标题
 */
void setTitle(char* );

/**
 * 设置句柄
 */
void setWinHandle();

/**
 * 设置控制台窗体的大小
 */
void setConsoleSize(int ,int );

/**
 * 设置光标的位置
 */
void setPosition(int ,int );

/**
 * 设置窗体文字的颜色
 */
void setColor(int );

/**
 * 描绘游戏窗体横线
 */
void drawhLine(int ,int ,int ,char ,int );

/**
 * 描绘游戏窗体竖线
 */
void drawsline(int ,int ,int ,char ,int );

/**
 * 打印菜单文字
 */
void printText(int ,int ,int ,char* ,int );

/**
 * 填充游戏区
 */
void fillGamePart(int ,int ,int ,int ,int ,int );

/**
 * 从键盘获取字符
 */
char getChar();

/**
 * 隐藏光标
 */
void hideCursor();
#endif // WINAPIHELP_H_INCLUDED
