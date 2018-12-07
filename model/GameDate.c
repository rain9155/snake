#include "GameDate.h"
#include <time.h>

SettingDate* setting_date = NULL;// ȫ��������Ϣָ��
GameDate* game_date = NULL;// ȫ����Ϸ��Ϣָ��

/**
 * С�ߵ��ƶ�����
 */
void snake_move()
{
    //��ȡ��������
    int x = game_date->snake->x;
    int y = game_date->snake->y;
    switch(game_date->direction)
    {
    case s_up:
        y--;
        if(y==1)
            y=game_date->map_height-1;
        break;
    case s_down:
        y++;
        if(y>game_date->map_height)
            y = 2;
        break;
    case s_left:
        x--;
        if(x<0)
            x = game_date->map_width-1;
        break;
    case s_right:
        x++;
        if(x>game_date->map_width-1)
            x = 0;
        break;
    }
    // �����һ�ڿ�ʼ������ȡǰһ�����壨��һ���������겻�䣩
    SnakeNode* loop;
    for(loop = game_date->snake_tial;loop->prev!=NULL;loop = loop->prev)
    {
        loop->x = loop->prev->x;
        loop->y = loop->prev->y;
    }
    // �����µ���������µ�����
    game_date->snake->x = x;
    game_date->snake->y = y;
}
/**
 * С�ߵĳ�ʼ��
 */
void snake_dateInit(SettingDate* setting_date)
{
    int i;
    for(i=setting_date->snake_len-1;i>=0;i--)
    {
        SnakeNode* node = (SnakeNode*)malloc(sizeof(SnakeNode));
        memset(node,0,sizeof(SnakeNode));

        node->x = i;
        node->y = setting_date->snake_y;
        node->color = setting_date->snake_color;
        node->next = NULL;
        node->prev = NULL;
        /** ������һ������ */
        if(game_date->snake==NULL)
        {
            game_date->snake=node;
            game_date->snake_tial=node;
        }
        else
        {
            /** β�͵���һ�ڣ�snake_tial��>next�������ڵ�ǰ�ڵ㣨node�� */
            game_date->snake_tial->next = node;
            /** ��ǰ�ڵ����һ�ڣ�node->prev��������β���ϣ�snake_tial�� */
            node->prev = game_date->snake_tial;
            /** ����β�� */
            game_date->snake_tial = node;
        }
    }
}

/**
 * ��Ϸ���ݵĳ�ʼ��
 */
void game_dateInit()
{
    /** ������������� */
    srand(time(NULL));
    /** ���������Ϣ��ָ�� */
    setting_date = setting_dateInit();
    /** Ϊ��Ϸ��Ϣָ������ڴ� */
    game_date = (GameDate*)malloc(sizeof(GameDate));
    memset(game_date,0,sizeof(GameDate));
    /** �������ݳ�ʼ�� */
    game_date->map_height = setting_date->map_height;
    game_date->map_width = setting_date->map_width;
    game_date->score = 0;
    game_date->speed = setting_date->snake_speed;
    game_date->len = setting_date->snake_len;
    game_date->direction = setting_date->direction;
    game_date->food = NULL;
    game_date->snake = NULL;
    game_date->snake_tial = NULL;
    /** С�߳�ʼ�� */
    if(NULL==game_date->snake)
    {
        snake_dateInit(setting_date);
    }
    /** ʳ���ʼ�� */
    if(NULL==game_date->food)
    {
        game_date->food = (Food*)malloc(sizeof(Food));
        game_date->food->color = 0xF<<4|rand()%0xF;
        game_date->food->x = rand()%game_date->map_width;
        game_date->food->y = rand()%game_date->map_height;
    }
}

/**
 * ����������Ϸ����
 */
void reset_game_date()
{
    // �ͷ�С��
    SnakeNode* loop = NULL;
    for(loop=game_date->snake_tial->prev;loop!=NULL;loop=loop->prev)
    {
        free(loop->next);
        loop->next = NULL;
    }
    free(game_date->snake);
    game_date->snake = NULL;
    game_date->snake_tial = NULL;

    SettingDate* setting = setting_dateInit();
    game_date->direction = setting->direction;
    game_date->len = setting->snake_len;
    game_date->score = 0;
    game_date->speed = setting->snake_speed;

    snake_dateInit(setting);

    game_date->food = (Food*)malloc(sizeof(Food));
    game_date->food->color = 0xF<<4|rand()%0xF;
    game_date->food->x = rand()%game_date->map_width;
    game_date->food->y = rand()%game_date->map_height;

}
