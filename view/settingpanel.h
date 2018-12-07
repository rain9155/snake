#ifndef SETTINGPANEL_H_INCLUDED
#define SETTINGPANEL_H_INCLUDED

/**
*描述：描绘游戏设置面板头文件
*作者：陈健宇
*时间：2018-2-8  21:49
*/

#include "../model/GameDate.h"
#include "../common/WinApiHelp.h"
#include "ControlPanel.h"
#include "KeyHandle.h"

/**
 * 设置面板指针初始化函数
 */
Panel* setting_panelInit();

/**
 * 设置文字选项初始化函数
 */
Text* setting_textInit();

/**
 * 描绘设置面板函数
 */
void print_Game_setting_panel();

#endif // SETTINGPANEL_H_INCLUDED
