#ifndef KEYHANDLE_H_INCLUDED
#define KEYHANDLE_H_INCLUDED

/**
*��������������ͷ�ļ�
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
*/

#include "../common/WinApiHelp.h"
#include "ControlPanel.h"

/**
 * ���������ṹ����
 */
typedef struct _direction_key
{
    void* (*up)(char );// ��
    void* (*right)(char );// ��
    void* (*down)(char );// ��
    void* (*left)(char );// ��
}directionKey;
/**
 * ����ӳ���������
 */
typedef struct _mapping_key
{
    char key;// ����ӳ���
    void* (*mappingkey)(char );
}mappingKey;
/**
 * ��Ϸ���棬���ý��棬enter�ṹ����
 */
typedef struct _settingAndgame
{
    void* (*setting)();// ��������
    void* (*game)();// ������Ϸ
    void* (*enter_game)();// ��enter��������Ϸ
}settingAndgame;
/**
 * ��������������������+ӳ�䣩
 */
void key_handle(directionKey* ,mappingKey* ,int );
/**
 * ���ð����������ĺ�������
 */
void print_key_handle();
/**
 * ���ر�ѡ�еĲ˵�ѡ�����ֵ��±�ĺ�������
 */
int return_selected_Index(Text* ,int ,int );
/**
 * ʵ���л���Ϸ�˵����ֵĺ���������
 */
void change_text(Text* ,int ,int ,int ,int );

#endif // KEYHANDLE_H_INCLUDED
