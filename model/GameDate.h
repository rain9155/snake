#ifndef GAMEDATE_H_INCLUDED
#define GAMEDATE_H_INCLUDED

/**
*������Ԥ������Ϸ����
*���ߣ��½���
*ʱ�䣺2018-2-8  21:49
*/

#include "../common/WinApiHelp.h"
#include "../view/ControlPanel.h"
#include "../view/GamePanel.h"
#include "../view/KeyHandle.h"
#include "../view/SettingPanel.h"


/**
 * С���ƶ��ķ���ö�ٽṹ
 */
typedef enum _snake_direction
{
    s_up = 'w',// �Ϸ���
    s_down = 's',// �·���
    s_left = 'd',// ����
    s_right = 'a',// �ҷ���
}SnakeDirection;

/**
 * �߽ڵ�Ľṹ
 */
typedef struct _snake_node
{
    int x;// ���������x����
    int y;// ���������y����
    int color;// �����������ɫ
    struct _snake_node* next;// ��һ�������λ��
    struct _snake_node* prev;// ��һ�������λ��
}SnakeNode;

/**
 * ʳ��Ľṹ
 */
typedef struct _food
{
    int x;// ʳ���x����
    int y;// ʳ���y����
    int color;// ʳ�����ɫ
}Food;

/**
 * ��Ϸ���ݽṹ
 */
typedef struct _game_date
{
    int score;// ��ǰ�ĵ÷�
    int len;// ��ǰ��С�߳���
    int map_width;// ��ͼ�Ŀ��
    int map_height;// ��ͼ�ĸ߶�
    double speed;// ��ǰ��С���ٶ�
    SnakeDirection direction;// С�ߵ�Ĭ�Ϸ���
    SnakeNode* snake;// С��
    SnakeNode* snake_tial;// С�ߵ�β��
    Food* food;// ʳ��
}GameDate;

/**
 * ���õĻ�����Ϣ�ṹ
 */
typedef struct _setting_date
{
    int snake_x;// С�ߵ�x����
    int snake_y;// С�ߵ�y����
    int snake_color;// С�ߵ���ɫ
    double snake_speed;// С�ߵ��ٶ�
    int snake_len;// С�ߵĳ�ʼ����
    int map_width;// ��ͼ�Ŀ��
    int map_height;// ��ͼ�ĸ߶�
    SnakeDirection direction;// С��Ĭ�ϵ��ƶ�����
}SettingDate;

/**
 * ������Ϣ�ĳ�ʼ������
 */
SettingDate* setting_dateInit();

/**
 * ��Ϸ���ݵĳ�ʼ��
 */
void game_dateInit();

/**
 * С�ߵ��ƶ�����
 */
void snake_move();

/**
 * ����������Ϸ����
 */
void reset_game_date();

#endif // GAMEDATE_H_INCLUDED
