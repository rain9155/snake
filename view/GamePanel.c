#include "GamePanel.h"

extern GameDate* game_date;

Panel* game_panel = NULL;// 要绘制的游戏面板指针

/**
 * 初始化游戏面板,并返回一个游戏面板指针
 */
Panel* game_panelInit()
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
 *填充游戏面板
 */
void fill_Game_panel()
{
    game_panel = game_panelInit();// 游戏面板指针初始化
    draw_control_panel(game_panel);// 描绘游戏面板
    fillGamePart(game_panel->x,game_panel->y-1,game_panel->forecolor<<4|game_panel->backcolor,game_panel->width,game_panel->height+2,' ');// 填充
    draw_game_date();// 打印小蛇和食物
}

/**
 * 游戏数据的绘制函数
 */
void draw_game_date()
{
    /** 食物 */
    int food_x = game_panel->x+game_date->food->x*2+1;
    int food_y = game_panel->y+game_date->food->y;
    printText(food_x,food_y,game_date->food->color,"●",2);
    /** 小蛇 */
    SnakeNode* loop;
    for(loop=game_date->snake;loop!=NULL;loop=loop->next)
    {
        int node_x = game_panel->x+loop->x*2+1;
        int node_y = game_panel->y+loop->y;
        printText(node_x,node_y,game_date->snake->color,"■",2);
    }
}

