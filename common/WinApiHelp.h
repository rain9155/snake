#ifndef WINAPIHELP_H_INCLUDED
#define WINAPIHELP_H_INCLUDED

/**
*������windowsApiͷ�ļ�
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
/**
 * ���ÿ���̨����
 */
void setTitle(char* );

/**
 * ���þ��
 */
void setWinHandle();

/**
 * ���ÿ���̨����Ĵ�С
 */
void setConsoleSize(int ,int );

/**
 * ���ù���λ��
 */
void setPosition(int ,int );

/**
 * ���ô������ֵ���ɫ
 */
void setColor(int );

/**
 * �����Ϸ�������
 */
void drawhLine(int ,int ,int ,char ,int );

/**
 * �����Ϸ��������
 */
void drawsline(int ,int ,int ,char ,int );

/**
 * ��ӡ�˵�����
 */
void printText(int ,int ,int ,char* ,int );

/**
 * �����Ϸ��
 */
void fillGamePart(int ,int ,int ,int ,int ,int );

/**
 * �Ӽ��̻�ȡ�ַ�
 */
char getChar();

/**
 * ���ع��
 */
void hideCursor();
#endif // WINAPIHELP_H_INCLUDED
