#include "Gamecontrol.h"

extern print_set_game;
extern GameDate* game_date;
extern Panel* game_panel;

/**
 * С���ƶ��Ϸ���
 */
void* snake_up()
{
    game_date->direction = s_up;
}

/**
 * С���ƶ��ҷ���
 */
void* snake_right()
{
    game_date->direction = s_right;
}

/**
 * С���ƶ��·���
 */
void* snake_down()
{
    game_date->direction = s_down;
}

/**
 * С���ƶ�����
 */
void* snake_left()
{
    game_date->direction = s_left;
}

/**
 * С���ƶ����򰴼��󶨺���
 */
void snake_direction_key()
{
    directionKey snakeDirection = {snake_up,snake_right,snake_down,snake_left};
    key_handle(&snakeDirection,NULL,0);
}

/**
 * С�߳�ʳ��
 */
void eatFood()
{
    if(game_date->snake->x==game_date->food->x&&game_date->snake->y==game_date->food->y)
    {

        /** ����һ������ */
        SnakeNode* node = (SnakeNode*)malloc(sizeof(SnakeNode));
        memset(node,0,sizeof(SnakeNode));

        node->prev = NULL;
        int x = game_date->snake->x;
        int y = game_date->snake->y;
        switch(game_date->direction)
        {
        case s_up:
            y--;
            if(y<0)
                y=game_date->map_height-1;
            break;
        case s_down:
            y++;
            if(y>game_date->map_height)
                y = 0;
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
        node->x = x;
        node->y = y;
        node->color = game_date->food->color;
        node->next = game_date->snake;
        game_date->snake->prev = node;
        game_date->snake = node;

        /** �޸���Ϸ���� */
        game_date->len++;
        game_date->score+=10;
        if(game_date->score>0&&game_date->score%30==0&&game_date->speed>0.05)
            game_date->speed-=0.01;
        modify_game_date(game_date->score,game_date->len,game_date->speed);

        /** ˢ��ʳ���λ�ú���ɫ */
        game_date->food->color = 0xF<<4|rand()%0xF;
        game_date->food->x = rand()%game_date->map_width;
        game_date->food->y = rand()%game_date->map_height;
    }
}

/**
 * �ж�С���Ƿ�����
 */
int judge_snake_ifdead()
{
    SnakeNode* loop = NULL;
    for(loop=game_date->snake->next;loop!=NULL;loop=loop->next)
    {
        if(loop->x==game_date->snake->x&&loop->y==game_date->snake->y)
            return(1);// С������
    }
    return(0);// С��û��
}

void enter_game()
{
    modify_game_date(game_date->score,game_date->len,game_date->speed);
    for(;judge_snake_ifdead()==0&&game_date->score<500;)
    {
        snake_move();
        snake_direction_key();

        fill_Game_panel();// ��Ϸ�����
        draw_game_date();// ��ӡС�ߺ�ʳ��
        eatFood();
        int sleep = game_date->speed*1000;
        Sleep(sleep);
    }
    if(game_date->score<500)
      printText(35,10,0x04,"С��������",10);
    else
        printText(35,10,0x04,"��ϲ�㣡��Ϸͨ��......",30);
    reset_game_date();
}

/**
 * ׼����Ϸ
 */
void read_game()
{
    setTitle("̰���ߣ���ľ�棩");
    setConsoleSize(60,30);// ���ÿ���̨��С
    hideCursor();// ���ع��

    game_dateInit();// ��Ϸ���ݳ�ʼ��
    print_Game_control_Panel();// ��ӡ�������
    fill_Game_panel();// ��Ϸ�����
    draw_game_date();// ��ӡС�ߺ�ʳ��

    settingAndgame setting_and_game = {print_Game_setting_panel,fill_Game_panel,enter_game};// ����̨�л��ṹ��ʼ��
    print_set_game = &setting_and_game;// Ҫչʾ��Ϸ�����ý���ָ���ʼ��

    for(;;)
    {
        print_key_handle();
        Sleep(100);
    }
}

