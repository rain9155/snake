#include "SettingPanel.h"

extern game_panel;

Panel* setting_panel = NULL;// Ҫ��ӡ���������ָ��
int len_setting = 0;// ��������ѡ������ĳ���
Text* setting_text = NULL;// Ҫ��ӡ����������ѡ���ָ��

/**
 * �������ָ���ʼ������
 */
Panel* setting_panelInit()
{
    Panel* panel = (Panel*)malloc(sizeof(Panel));

    panel->x = 22;
    panel->y = 2;
    panel->width = 36;
    panel->height = 20;
    panel->hline = '-';
    panel->sline = '|';
    panel->backcolor = 0x0;
    panel->forecolor = 0xF;

    return(panel);
}

/**
 * ��������ѡ���ʼ������
 */
Text* setting_textInit()
{
    static Text draw_setting[] ={
                {26,4,20,"�������֣���/�أ�����",0x0,0xF,},
                {26,7,20,"��    �֣���/�أ�����",0x0,0xF,},
                {26,10,20,"��    �ȣ��񣩣�Ĭ��",0x0,0xF,},
                {26,13,20,"��    �ȣ���/�룩��5",0x0,0xF,},
                {26,16,20,"��    ������ɫ",0x0,0xF,},
                {26,19,20,"ʳ    ��Զ����",0x0,0xF,},

                                };

    len_setting = sizeof(draw_setting)/sizeof(Text);

    return(draw_setting);
}

/**
 * �����Ϸ������庯��
 */
void print_Game_setting_panel()
{
    setting_panel = setting_panelInit();// �������ָ���ʼ��
    draw_control_panel(setting_panel);// ����������

    setting_text = setting_textInit();// ���ò˵�����ѡ��ָ���ʼ��
    fillGamePart(23,2,0x0,34,20,' ');// ����
    draw_control_text(setting_text,len_setting);// ��ӡ���ò˵�
}

/**
 * ������Ϣ�ĳ�ʼ������
 */
SettingDate* setting_dateInit()
{
    /** Ϊ������Ϣ��ָ������ڴ� */
    SettingDate* setting = (SettingDate*)malloc(sizeof(SettingDate));
    memset(setting,0,sizeof(SettingDate));
    /** �������ݳ�ʼ�� */
    setting->map_width = 17;
    setting->map_height = 20;
    setting->snake_color = 0xF4;
    setting->snake_speed = 0.3;// ��
    setting->snake_len = 3;
    setting->snake_x = 2;
    setting->snake_y = 10;
    setting->direction = s_right;
    return(setting);
}
