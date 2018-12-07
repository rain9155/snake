#include "ControlPanel.h"

Panel* control_panel = NULL;// 要打印的控制面板指针
Text* control_text = NULL;// 要打印的菜单文字选项指针
int len_text = 0;// 菜单选项文字数组长度

/**
 * 控制面板指针的初始化函数实现，并返回一个控制面板指针
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
 * 描绘控制面板函数实现
 * draw_panel 控制面板指针
 */
void draw_control_panel(Panel* draw_panel)
{
    /** 打印横线 */
    drawhLine(draw_panel->x,draw_panel->y,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->hline,draw_panel->width);
    drawhLine(draw_panel->x,draw_panel->y+draw_panel->height+1,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->hline,draw_panel->width);
    /** 打印竖线 */
    drawsline(draw_panel->x,draw_panel->y+1,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->sline,draw_panel->height);
    drawsline(draw_panel->x+draw_panel->width-1,draw_panel->y+1,draw_panel->backcolor<<4|draw_panel->forecolor,draw_panel->sline,draw_panel->height);

}

/**
 * 游戏菜单文字初始化函数实现
 */
Text* control_textInit()
{
    static Text draw_text[] ={
                {4,4,8,"分数：0",0x0,0xF,},
                {4,8,8,"长度：0",0x0,0xF,},
                {4,12,8,"秒/格：0.3",0x0,0xF,},
                {4,16,8,"游戏",0xF,0x0,1},
                {4,20,8,"设置",0x0,0xF,1},
                            };
    len_text = sizeof(draw_text)/sizeof(Text);
    return(draw_text);
}

/**
 * 描绘游戏菜单文字
 * draw_text 游戏菜单文字选项指针
 * len 游戏菜单文字选项数组长度
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
 * 打印游戏控制面板函数声明
 */
void print_Game_control_Panel()
{
    control_panel = control_panelInit();// 控制面板初始化
    draw_control_panel(control_panel);// 描绘控制面板
    control_text = control_textInit();// 游戏菜单选项初始化
    draw_control_text(control_text,len_text);// 描绘游戏菜单
}


/**
 * 修改游戏数据
 * score 要修改的分数
 * len 要修改的小蛇长度
 * sleep 要修改的小蛇速度
 */
void modify_game_date(int score,int len,double sleep)
{
    /** 修改分数 */
    char text1[30];
    sprintf(text1,"分数：%d",score);
    strcpy(control_text->text,text1);

    /** 修改长度 */
    char text2[30];
    sprintf(text2,"长度：%d",len);
    strcpy((control_text+1)->text,text2);

    /** 修改速度 */
    char text3[30];
    sprintf(text3,"秒/格：%.2lf",sleep);
    strcpy((control_text+2)->text,text3);

    draw_control_text(control_text,len_text);
}


