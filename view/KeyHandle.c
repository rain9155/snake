#include "KeyHandle.h"

extern control_text;
extern len_text;
extern control_panel;

int len_mapping = 0;// 要处理的映射键数组的长度
settingAndgame* print_set_game = NULL;// 要展示游戏与设置界面指针

/// 内部展示游戏界面
/// 内部展示设置界面
/// 内部展示游戏与设置界面函数的实现
void relize_settingAndgame()
{
    int Index = return_selected_Index(control_text,len_text,0X0);// 找到当前被选到的选项
    if(print_set_game!=NULL)
    {
        if(Index>-1)
        {
            Text* v = control_text+Index;
            if(print_set_game->game!=NULL)
            {
                if(Index==3)
                {
                    print_set_game->game();
                }
            }
            if(print_set_game->setting!=NULL)
            {
                if(Index==4)
                {
                    print_set_game->setting();
                }
            }
        }
    }
}

/// 内部上方向键函数
void* up_fun(char ch)
{
    setPosition(13,14);
    change_text(control_text,0x0,0xF,len_text,0);// 切换选项
    print_Game_control_Panel();// 更新面板
    relize_settingAndgame();// 展示游戏与设置界面

}

/// 内部右方向键函数
void* right_fun(char ch)
{
    setPosition(13,17);
}

/// 内部下方向键函数
void* down_fun(char ch)
{
    setPosition(13,17);
    change_text(control_text,0X0,0xF,len_text,1);// 切换选项
    print_Game_control_Panel();// 更新面板
    relize_settingAndgame();// 展示游戏与设置界面

}

/// 内部左方向键函数
void* left_fun(char ch)
{
    setPosition(13,17);
}

/// 内部映射键 按enter键进入游戏
void* mappingkey_enter_game(char ch)
{
    int Index = return_selected_Index(control_text,len_text,0X0);// 找到当前被选到的选项
    if(print_set_game!=NULL&&print_set_game->enter_game()!=NULL)
    {
        if(Index>-1&&Index==4)
        {
            print_set_game->enter_game();
        }
    }
}

/**
 * 按键处理函数实现（方向+映射）
 * direction_key 方向键处理结构
 * mapping_key 映射键集（数组）处理结构
 * len 映射键集的长度
 */
void key_handle(directionKey* direction_key,mappingKey* mapping_key,int len)
{
    char receive_key = getChar();// 从键盘获取一个字符
    if(receive_key!=0)
    {
        if(receive_key==-32)
        {
            receive_key = getChar();
        }
        /** 处理方向键 */
        if(direction_key!=NULL)
        {
            /** 如果是方向键 */
            switch(receive_key)
            {
            case 'w':
            case 72:
                if(direction_key->up!=NULL)
                    direction_key->up(receive_key);
                break;
            case 'd':
            case 77:
                if(direction_key->right!=NULL)
                    direction_key->right(receive_key);
                break;
            case 's':
            case 80:
                if(direction_key->down!=NULL)
                    direction_key->down(receive_key);
                break;
            case 'a':
            case 75:
                if(direction_key->left!=NULL)
                    direction_key->left(receive_key);
                break;
            }
        }
        /** 处理映射键 */
        if(mapping_key!=NULL&&len>0)
        {
            int i;
            for(i=0;i<len;i++)
            {
                mappingKey* mapping = mapping_key+i;
                /** 如果是映射键 */
                if(mapping->key==receive_key)
                {
                    if(mapping->mappingkey!=NULL)
                    {
                        mapping->mappingkey(receive_key);
                    }
                }
            }
        }

    }
}

/**
 * 返回被选中的菜单选项文字的下标的函数的实现
 * text 游戏菜单文字数组
 * len 游戏菜单文字数组长度
 * forecolor 被选中的文字的前景色
 */
int return_selected_Index(Text* text,int len,int forecolor)
{
    int i;
    int re_Index = -1;
    if(text!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if((text+i)->forecolor==forecolor)
            {
                re_Index = i;
                return(re_Index);
            }
        }
    }
    return(re_Index);
}

/**
 * 实现切换游戏菜单文字的函数的实现
 * text 游戏菜单选项数组
 * forecolor 被选中的选项的前景色
 * backcolor 被选中的选项的背景色
 * len 数组的长度
 * upordown 是上还是下 （键）
 */
void change_text(Text* text,int forecolor,int backcolor,int len,int upordown)
{
    int Index = return_selected_Index(text,len,forecolor);
    Index = Index>0?Index:0;
    /** 当前是哪一个被选中 */
    Text* v = text+Index;
    /** 修改当前被选中的选项的颜色 */
    v->backcolor = forecolor;
    v->forecolor = backcolor;
    /** 查找下一个要被选中的选项 */
    Text* nextText = NULL;
    if(upordown)// 下
    {
       int i;
       for(i=Index+1;i<len+Index;i++)
       {
           Text* n = text+(i%len);
           if(n->setchoice)
           {
               nextText = n;
               break;
           }
       }
    }
    else// 上
    {
        int i;
        for(i=Index-1+len;i>0;i--)
        {
            Text* n = text+(i%len);
            if(n->setchoice)
            {
                nextText = n;
                break;
            }
        }
    }
    /** 修改下一个被选中的选项 */
    nextText->backcolor = backcolor;
    nextText->forecolor = forecolor;
}

/**
 * 调用按键处理函数的函数实现
 */
void print_key_handle()
 {
    directionKey direction_key = {up_fun,right_fun,down_fun,left_fun};// 方向键结构初始化
    mappingKey mapping_key[] = {{13,mappingkey_enter_game}};// 映射键结构初始化
    len_mapping = sizeof(mapping_key)/sizeof(mappingKey);// 映射键数组的长度
    key_handle(&direction_key,&mapping_key,len_mapping);// 处理按键
 }

