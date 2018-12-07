#ifndef SETTINGPANEL_H_INCLUDED
#define SETTINGPANEL_H_INCLUDED

/**
*�����������Ϸ�������ͷ�ļ�
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
*/

#include "../model/GameDate.h"
#include "../common/WinApiHelp.h"
#include "ControlPanel.h"
#include "KeyHandle.h"

/**
 * �������ָ���ʼ������
 */
Panel* setting_panelInit();

/**
 * ��������ѡ���ʼ������
 */
Text* setting_textInit();

/**
 * ���������庯��
 */
void print_Game_setting_panel();

#endif // SETTINGPANEL_H_INCLUDED
