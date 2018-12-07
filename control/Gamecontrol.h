#ifndef GAMECONTROL_H_INCLUDED
#define GAMECONTROL_H_INCLUDED

/**
*��������Ϸ����̨
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
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
 * ׼����Ϸ
 */
void read_game();

/**
 * С���ƶ����򰴼��󶨺���
 */
void snake_direction_key();

/**
 * �ж�С���Ƿ�����
 */
int judge_snake_ifdead();

/**
 * С�߳�ʳ��
 */
void eatFood();

#endif // GAMECONTROL_H_INCLUDED
