#include "ControlPanel.h"

Panel* control_panel = NULL;// Ҫ��ӡ�Ŀ������ָ��
Text* control_text = NULL;// Ҫ��ӡ�Ĳ˵�����ѡ��ָ��
int len_text = 0;// �˵�ѡ���������鳤��

/**
 * �������ָ��ĳ�ʼ������ʵ�֣�������һ���������ָ��
 */
Panel* control_panelInit()
{
    Panel* panel = (Panel*)malloc(sizeof(Panel));
    panel->x = 3;
    panel->y = 2;
    panel->width = 20;
    panel->height = 20;
    panel->hline = '-';
    panel->sline = '|';
    panel->backcolor = 0x0;
    panel->forecolor = 0xF;
    return(panel);
}

/**
 * ��������庯��ʵ��
 * draw_panel �������ָ��
 */
void draw_control_panel(Panel* draw_panel)
{
    /** ��ӡ���� */
    drawhLine(draw_panel->x,draw_panel->y,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->hline,draw_panel->width);
    drawhLine(draw_panel->x,draw_panel->y+draw_panel->height+1,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->hline,draw_panel->width);
    /** ��ӡ���� */
    drawsline(draw_panel->x,draw_panel->y+1,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->sline,draw_panel->height);
    drawsline(draw_panel->x+draw_panel->width-1,draw_panel->y+1,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->sline,draw_panel->height);

}

/**
 * ��Ϸ�˵����ֳ�ʼ������ʵ��
 */
Text* control_textInit()
{
    static Text draw_text[] ={
                {4,4,8,"������0",0x0,0xF,},
                {4,8,8,"���ȣ�0",0x0,0xF,},
                {4,12,8,"��/��0.3",0x0,0xF,},
                {4,16,8,"��Ϸ",0xF,0x0,1},
                {4,20,8,"����",0x0,0xF,1},
                            };
    len_text = sizeof(draw_text)/sizeof(Text);
    return(draw_text);
}

/**
 * �����Ϸ�˵�����
 * draw_text ��Ϸ�˵�����ѡ��ָ��
 * len ��Ϸ�˵�����ѡ�����鳤��
 */
void draw_control_text(Text* draw_text,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printText((draw_text+i)->x,(draw_text+i)->y,(draw_text+i)->backcolor<<4|(draw_text+i)->forecolor,(draw_text+i)->text,(draw_text+i)->len);
    }
}

/**
 * ��ӡ��Ϸ������庯������
 */
void print_Game_control_Panel()
{
    control_panel = control_panelInit();// ��������ʼ��
    draw_control_panel(control_panel);// ���������
    control_text = control_textInit();// ��Ϸ�˵�ѡ���ʼ��
    draw_control_text(control_text,len_text);// �����Ϸ�˵�
}


/**
 * �޸���Ϸ����
 * score Ҫ�޸ĵķ���
 * len Ҫ�޸ĵ�С�߳���
 * sleep Ҫ�޸ĵ�С���ٶ�
 */
void modify_game_date(int score,int len,double sleep)
{
    /** �޸ķ��� */
    char text1[30];
    sprintf(text1,"������%d",score);
    strcpy(control_text->text,text1);

    /** �޸ĳ��� */
    char text2[30];
    sprintf(text2,"���ȣ�%d",len);
    strcpy((control_text+1)->text,text2);

    /** �޸��ٶ� */
    char text3[30];
    sprintf(text3,"��/��%.2lf",sleep);
    strcpy((control_text+2)->text,text3);

    draw_control_text(control_text,len_text);
}


