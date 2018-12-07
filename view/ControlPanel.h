#ifndef CONTROLPANEL_H_INCLUDED
#define CONTROLPANEL_H_INCLUDED

/**
*���������������ͷ�ļ�
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
*/

#include "../common/WinApiHelp.h"
#include <string.h>

/**
 * ����������ṹ
 */
typedef struct  _base_panel
{
    int x;// ��ʼx����
    int y;// ��ʼy����
    int width;// ���Ŀ��
    int height;// ���ĸ߶�
    char hline;// ���ߵ���ĸ
    char sline;// ���ߵ���ĸ
    int  backcolor;// ����ɫ
    int  forecolor;// ǰ��ɫ
}Panel;

/**
 * ������Ϸ���ֽṹ
 */
typedef struct _base_text
{
    int x;// ����
    int y;// ����
    int len;// ���ֳ���
    char text[30];// ����
    int backcolor;// ����ɫ
    int forecolor;// ǰ��ɫ
    int setchoice;//�Ƿ���Ա�ѡ��(0�����ԣ�1����)
}Text;

/**
 * �������ĳ�ʼ����������
 */
Panel* control_panelInit();

/**
 * ��������庯������
 */
void draw_control_panel(Panel* );

/**
 * ��Ϸ�˵����ֳ�ʼ������
 */
Text* control_textInit();

/**
 * �����Ϸ�˵�����
 */
void draw_control_text(Text* ,int );

/**
 * ��ӡ��Ϸ������庯������
 */
void print_Game_control_Panel();

/**
 * �޸���Ϸ����
 * score Ҫ�޸ĵķ���
 * len Ҫ�޸ĵ�С�߳���
 * sleep Ҫ�޸ĵ�С���ٶ�
 */
void modify_game_date(int score,int len,double sleep);

#endif // CONTROLPANEL_H_INCLUDED
