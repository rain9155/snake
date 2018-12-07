#include "SettingPanel.h"

extern game_panel;

Panel* setting_panel = NULL;// 要打印的设置面板指针
int len_setting = 0;// 设置文字选项数组的长度
Text* setting_text = NULL;// 要打印的设置文字选项的指针

/**
 * 设置面板指针初始化函数
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
 * 设置文字选项初始化函数
 */
Text* setting_textInit()
{
    static Text draw_setting[] ={
                {26,4,20,"背景音乐（开/关）：开",0x0,0xF,},
                {26,7,20,"背    乐（开/关）：开",0x0,0xF,},
                {26,10,20,"速    度（格）：默认",0x0,0xF,},
                {26,13,20,"速    度（格/秒）：5",0x0,0xF,},
                {26,16,20,"背    景：单色",0x0,0xF,},
                {26,19,20,"食    物：自定义符",0x0,0xF,},

                                };

    len_setting = sizeof(draw_setting)/sizeof(Text);

    return(draw_setting);
}

/**
 * 描绘游戏设置面板函数
 */
void print_Game_setting_panel()
{
    setting_panel = setting_panelInit();// 设置面板指针初始化
    draw_control_panel(setting_panel);// 描绘设置面板

    setting_text = setting_textInit();// 设置菜单文字选项指针初始化
    fillGamePart(23,2,0x0,34,20,' ');// 清屏
    draw_control_text(setting_text,len_setting);// 打印设置菜单
}

/**
 * 设置信息的初始化函数
 */
SettingDate* setting_dateInit()
{
    /** 为设置信息的指针分配内存 */
    SettingDate* setting = (SettingDate*)malloc(sizeof(SettingDate));
    memset(setting,0,sizeof(SettingDate));
    /** 其他数据初始化 */
    setting->map_width = 17;
    setting->map_height = 20;
    setting->snake_color = 0xF4;
    setting->snake_speed = 0.3;// 秒
    setting->snake_len = 3;
    setting->snake_x = 2;
    setting->snake_y = 10;
    setting->direction = s_right;
    return(setting);
}
