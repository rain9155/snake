#ifndef CONTROLPANEL_H_INCLUDED
#define CONTROLPANEL_H_INCLUDED

/**
*描述：描绘控制面板头文件
*作者：陈健宇
*时间：2018-2-8  21:49
*/

#include "../common/WinApiHelp.h"
#include <string.h>

/**
 * 定义基础面板结构
 */
typedef struct  _base_panel
{
    int x;// 开始x坐标
    int y;// 开始y坐标
    int width;// 面板的宽度
    int height;// 面板的高度
    char hline;// 横线的字母
    char sline;// 竖线的字母
    int  backcolor;// 背景色
    int  forecolor;// 前景色
}Panel;

/**
 * 定义游戏文字结构
 */
typedef struct _base_text
{
    int x;// 坐标
    int y;// 坐标
    int len;// 文字长度
    char text[30];// 文字
    int backcolor;// 背景色
    int forecolor;// 前景色
    int setchoice;//是否可以被选择(0不可以，1可以)
}Text;

/**
 * 控制面板的初始化函数声明
 */
Panel* control_panelInit();

/**
 * 描绘控制面板函数声明
 */
void draw_control_panel(Panel* );

/**
 * 游戏菜单文字初始化函数
 */
Text* control_textInit();

/**
 * 描绘游戏菜单文字
 */
void draw_control_text(Text* ,int );

/**
 * 打印游戏控制面板函数声明
 */
void print_Game_control_Panel();

/**
 * 修改游戏数据
 * score 要修改的分数
 * len 要修改的小蛇长度
 * sleep 要修改的小蛇速度
 */
void modify_game_date(int score,int len,double sleep);

#endif // CONTROLPANEL_H_INCLUDED
