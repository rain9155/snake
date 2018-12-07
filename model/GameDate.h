#ifndef GAMEDATE_H_INCLUDED
#define GAMEDATE_H_INCLUDED

/**
*描述：预处理游戏数据
*作者：陈健宇
*时间：2018-2-8  21:49
*/

#include "../common/WinApiHelp.h"
#include "../view/ControlPanel.h"
#include "../view/GamePanel.h"
#include "../view/KeyHandle.h"
#include "../view/SettingPanel.h"


/**
 * 小蛇移动的方向枚举结构
 */
typedef enum _snake_direction
{
    s_up = 'w',// 上方向
    s_down = 's',// 下方向
    s_left = 'd',// 左方向
    s_right = 'a',// 右方向
}SnakeDirection;

/**
 * 蛇节点的结构
 */
typedef struct _snake_node
{
    int x;// 本节身体的x坐标
    int y;// 本节身体的y坐标
    int color;// 本节身体的颜色
    struct _snake_node* next;// 下一节身体的位置
    struct _snake_node* prev;// 上一节身体的位置
}SnakeNode;

/**
 * 食物的结构
 */
typedef struct _food
{
    int x;// 食物的x坐标
    int y;// 食物的y坐标
    int color;// 食物的颜色
}Food;

/**
 * 游戏数据结构
 */
typedef struct _game_date
{
    int score;// 当前的得分
    int len;// 当前的小蛇长度
    int map_width;// 地图的宽度
    int map_height;// 地图的高度
    double speed;// 当前的小蛇速度
    SnakeDirection direction;// 小蛇的默认方向
    SnakeNode* snake;// 小蛇
    SnakeNode* snake_tial;// 小蛇的尾巴
    Food* food;// 食物
}GameDate;

/**
 * 设置的基本信息结构
 */
typedef struct _setting_date
{
    int snake_x;// 小蛇的x坐标
    int snake_y;// 小蛇的y坐标
    int snake_color;// 小蛇的颜色
    double snake_speed;// 小蛇的速度
    int snake_len;// 小蛇的初始长度
    int map_width;// 地图的宽度
    int map_height;// 地图的高度
    SnakeDirection direction;// 小蛇默认的移动方向
}SettingDate;

/**
 * 设置信息的初始化函数
 */
SettingDate* setting_dateInit();

/**
 * 游戏数据的初始化
 */
void game_dateInit();

/**
 * 小蛇的移动函数
 */
void snake_move();

/**
 * 重新设置游戏数据
 */
void reset_game_date();

#endif // GAMEDATE_H_INCLUDED
