#include "Gamecontrol.h"

extern print_set_game;
extern GameDate* game_date;
extern Panel* game_panel;

/**
 * 小蛇移动上方向
 */
void* snake_up()
{
    game_date->direction = s_up;
}

/**
 * 小蛇移动右方向
 */
void* snake_right()
{
    game_date->direction = s_right;
}

/**
 * 小蛇移动下方向
 */
void* snake_down()
{
    game_date->direction = s_down;
}

/**
 * 小蛇移动左方向
 */
void* snake_left()
{
    game_date->direction = s_left;
}

/**
 * 小蛇移动方向按键绑定函数
 */
void snake_direction_key()
{
    directionKey snakeDirection = {snake_up,snake_right,snake_down,snake_left};
    key_handle(&snakeDirection,NULL,0);
}

/**
 * 小蛇吃食物
 */
void eatFood()
{
    if(game_date->snake->x==game_date->food->x&&game_date->snake->y==game_date->food->y)
    {

        /** 增长一节身体 */
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

        /** 修改游戏数据 */
        game_date->len++;
        game_date->score+=10;
        if(game_date->score>0&&game_date->score%30==0&&game_date->speed>0.05)
            game_date->speed-=0.01;
        modify_game_date(game_date->score,game_date->len,game_date->speed);

        /** 刷新食物的位置和颜色 */
        game_date->food->color = 0xF<<4|rand()%0xF;
        game_date->food->x = rand()%game_date->map_width;
        game_date->food->y = rand()%game_date->map_height;
    }
}

/**
 * 判断小蛇是否死亡
 */
int judge_snake_ifdead()
{
    SnakeNode* loop = NULL;
    for(loop=game_date->snake->next;loop!=NULL;loop=loop->next)
    {
        if(loop->x==game_date->snake->x&&loop->y==game_date->snake->y)
            return(1);// 小蛇死了
    }
    return(0);// 小蛇没死
}

void enter_game()
{
    modify_game_date(game_date->score,game_date->len,game_date->speed);
    for(;judge_snake_ifdead()==0&&game_date->score<500;)
    {
        snake_move();
        snake_direction_key();

        fill_Game_panel();// 游戏区填充
        draw_game_date();// 打印小蛇和食物
        eatFood();
        int sleep = game_date->speed*1000;
        Sleep(sleep);
    }
    if(game_date->score<500)
      printText(35,10,0x04,"小蛇死亡！",10);
    else
        printText(35,10,0x04,"恭喜你！游戏通关......",30);
    reset_game_date();
}

/**
 * 准备游戏
 */
void read_game()
{
    setTitle("贪吃蛇（积木版）");
    setConsoleSize(60,30);// 设置控制台大小
    hideCursor();// 隐藏光标

    game_dateInit();// 游戏数据初始化
    print_Game_control_Panel();// 打印控制面板
    fill_Game_panel();// 游戏区填充
    draw_game_date();// 打印小蛇和食物

    settingAndgame setting_and_game = {print_Game_setting_panel,fill_Game_panel,enter_game};// 控制台切换结构初始化
    print_set_game = &setting_and_game;// 要展示游戏与设置界面指针初始化

    for(;;)
    {
        print_key_handle();
        Sleep(100);
    }
}

