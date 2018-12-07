#ifndef GAMEPANEL_H_INCLUDED
#define GAMEPANEL_H_INCLUDED

/**
*�����������Ϸ���ͷ�ļ�
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
*/

#include "../model/GameDate.h"
#include "../control/Gamecontrol.h"
#include "../common/WinApiHelp.h"
#include "ControlPanel.h"
#include "KeyHandle.h"

/**
 * ��ʼ����Ϸ���,������һ����Ϸ���ָ��
 */
Panel* game_panelInit();

/**
 * �����Ϸ���
 */
void fill_Game_panel();

/**
 * ��Ϸ���ݵĻ��ƺ���
 */
void draw_game_date();

#endif // GAMEPANEL_H_INCLUDED
