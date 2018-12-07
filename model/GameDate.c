#include "GameDate.h"
#include <time.h>

SettingDate* setting_date = NULL;// 全局设置信息指针
GameDate* game_date = NULL;// 全局游戏信息指针

/**
 * 小蛇的移动函数
 */
void snake_move()
{
    //获取最新坐标
    int x = game_date->snake->x;
    int y = game_date->snake->y;
    switch(game_date->direction)
    {
    case s_up:
        y--;
        if(y==1)
            y=game_date->map_height-1;
        break;
    case s_down:
        y++;
        if(y>game_date->map_height)
            y = 2;
        break;
    case s_left:
        x--;
        if(x<0)
            x = game_date->map_width-1;
        break;
    case s_right:
        x++;
        if(x>game_date->map_width-1)
            x = 0;
        break;
    }
    // 从最后一节开始，依次取前一节身体（第一节身体坐标不变）
    SnakeNode* loop;
    for(loop = game_date->snake_tial;loop->prev!=NULL;loop = loop->prev)
    {
        loop->x = loop->prev->x;
        loop->y = loop->prev->y;
    }
    // 将最新的坐标给最新的身体
    game_date->snake->x = x;
    game_date->snake->y = y;
}
/**
 * 小蛇的初始化
 */
void snake_dateInit(SettingDate* setting_date)
{
    int i;
    for(i=setting_date->snake_len-1;i>=0;i--)
    {
        SnakeNode* node = (SnakeNode*)malloc(sizeof(SnakeNode));
        memset(node,0,sizeof(SnakeNode));

        node->x = i;
        node->y = setting_date->snake_y;
        node->color = setting_date->snake_color;
        node->next = NULL;
        node->prev = NULL;
        /** 创建第一节身体 */
        if(game_date->snake==NULL)
        {
            game_date->snake=node;
            game_date->snake_tial=node;
        }
        else
        {
            /** 尾巴的下一节（snake_tial—>next）连接在当前节点（node） */
            game_date->snake_tial->next = node;
            /** 当前节点的上一节（node->prev）连接在尾巴上（snake_tial） */
            node->prev = game_date->snake_tial;
            /** 更新尾巴 */
            game_date->snake_tial = node;
        }
    }
}

/**
 * 游戏数据的初始化
 */
void game_dateInit()
{
    /** 设置随机数种子 */
    srand(time(NULL));
    /** 获得设置信息的指针 */
    setting_date = setting_dateInit();
    /** 为游戏信息指针分配内存 */
    game_date = (GameDate*)malloc(sizeof(GameDate));
    memset(game_date,0,sizeof(GameDate));
    /** 其他数据初始化 */
    game_date->map_height = setting_date->map_height;
    game_date->map_width = setting_date->map_width;
    game_date->score = 0;
    game_date->speed = setting_date->snake_speed;
    game_date->len = setting_date->snake_len;
    game_date->direction = setting_date->direction;
    game_date->food = NULL;
    game_date->snake = NULL;
    game_date->snake_tial = NULL;
    /** 小蛇初始化 */
    if(NULL==game_date->snake)
    {
        snake_dateInit(setting_date);
    }
    /** 食物初始化 */
    if(NULL==game_date->food)
    {
        game_date->food = (Food*)malloc(sizeof(Food));
        game_date->food->color = 0xF<<4|rand()%0xF;
        game_date->food->x = rand()%game_date->map_width;
        game_date->food->y = rand()%game_date->map_height;
    }
}

/**
 * 重新设置游戏数据
 */
void reset_game_date()
{
    // 释放小蛇
    SnakeNode* loop = NULL;
    for(loop=game_date->snake_tial->prev;loop!=NULL;loop=loop->prev)
    {
        free(loop->next);
        loop->next = NULL;
    }
    free(game_date->snake);
    game_date->snake = NULL;
    game_date->snake_tial = NULL;

    SettingDate* setting = setting_dateInit();
    game_date->direction = setting->direction;
    game_date->len = setting->snake_len;
    game_date->score = 0;
    game_date->speed = setting->snake_speed;

    snake_dateInit(setting);

    game_date->food = (Food*)malloc(sizeof(Food));
    game_date->food->color = 0xF<<4|rand()%0xF;
    game_date->food->x = rand()%game_date->map_width;
    game_date->food->y = rand()%game_date->map_height;

}
