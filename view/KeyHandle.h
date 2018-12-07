#ifndef KEYHANDLE_H_INCLUDED
#define KEYHANDLE_H_INCLUDED

/**
*描述：按键处理头文件
*作者：陈健宇
*时间：2018-2-8  21:49
*/

#include "../common/WinApiHelp.h"
#include "ControlPanel.h"

/**
 * 方向键处理结构定义
 */
typedef struct _direction_key
{
    void* (*up)(char );// 上
    void* (*right)(char );// 右
    void* (*down)(char );// 下
    void* (*left)(char );// 左
}directionKey;
/**
 * 特殊映射键处理定义
 */
typedef struct _mapping_key
{
    char key;// 特殊映射键
    void* (*mappingkey)(char );
}mappingKey;
/**
 * 游戏界面，设置界面，enter结构定义
 */
typedef struct _settingAndgame
{
    void* (*setting)();// 进入设置
    void* (*game)();// 进入游戏
    void* (*enter_game)();// 按enter键进入游戏
}settingAndgame;
/**
 * 按键处理函数声明（方向+映射）
 */
void key_handle(directionKey* ,mappingKey* ,int );
/**
 * 调用按键处理函数的函数声明
 */
void print_key_handle();
/**
 * 返回被选中的菜单选项文字的下标的函数声明
 */
int return_selected_Index(Text* ,int ,int );
/**
 * 实现切换游戏菜单文字的函数的声明
 */
void change_text(Text* ,int ,int ,int ,int );

#endif // KEYHANDLE_H_INCLUDED
