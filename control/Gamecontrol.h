#ifndef GAMECONTROL_H_INCLUDED
#define GAMECONTROL_H_INCLUDED

/**
*描述：游戏控制台
*作者：陈健宇
*时间：2018-2-8  21:49
*/

#include "../model/GameDate.h"
#include "../common/WinApiHelp.h"
#include "../view/ControlPanel.h"
#include "../view/GamePanel.h"
#include "../view/KeyHandle.h"
#include "../view/SettingPanel.h"
#include <mmsystem.h>
#pragma

/**
 * 准备游戏
 */
void read_game();

/**
 * 小蛇移动方向按键绑定函数
 */
void snake_direction_key();

/**
 * 判断小蛇是否死亡
 */
int judge_snake_ifdead();

/**
 * 小蛇吃食物
 */
void eatFood();

#endif // GAMECONTROL_H_INCLUDED
