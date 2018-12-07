#ifndef GAMEPANEL_H_INCLUDED
#define GAMEPANEL_H_INCLUDED

/**
*描述：描绘游戏面板头文件
*作者：陈健宇
*时间：2018-2-8  21:49
*/

#include "../model/GameDate.h"
#include "../control/Gamecontrol.h"
#include "../common/WinApiHelp.h"
#include "ControlPanel.h"
#include "KeyHandle.h"

/**
 * 初始化游戏面板,并返回一个游戏面板指针
 */
Panel* game_panelInit();

/**
 * 填充游戏面板
 */
void fill_Game_panel();

/**
 * 游戏数据的绘制函数
 */
void draw_game_date();

#endif // GAMEPANEL_H_INCLUDED
