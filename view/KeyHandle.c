#include "KeyHandle.h"

extern control_text;
extern len_text;
extern control_panel;

int len_mapping = 0;// Ҫ�����ӳ�������ĳ���
settingAndgame* print_set_game = NULL;// Ҫչʾ��Ϸ�����ý���ָ��

/// �ڲ�չʾ��Ϸ����
/// �ڲ�չʾ���ý���
/// �ڲ�չʾ��Ϸ�����ý��溯����ʵ��
void relize_settingAndgame()
{
    int Index = return_selected_Index(control_text,len_text,0X0);// �ҵ���ǰ��ѡ����ѡ��
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

/// �ڲ��Ϸ��������
void* up_fun(char ch)
{
    setPosition(13,14);
    change_text(control_text,0x0,0xF,len_text,0);// �л�ѡ��
    print_Game_control_Panel();// �������
    relize_settingAndgame();// չʾ��Ϸ�����ý���

}

/// �ڲ��ҷ��������
void* right_fun(char ch)
{
    setPosition(13,17);
}

/// �ڲ��·��������
void* down_fun(char ch)
{
    setPosition(13,17);
    change_text(control_text,0X0,0xF,len_text,1);// �л�ѡ��
    print_Game_control_Panel();// �������
    relize_settingAndgame();// չʾ��Ϸ�����ý���

}

/// �ڲ����������
void* left_fun(char ch)
{
    setPosition(13,17);
}

/// �ڲ�ӳ��� ��enter��������Ϸ
void* mappingkey_enter_game(char ch)
{
    int Index = return_selected_Index(control_text,len_text,0X0);// �ҵ���ǰ��ѡ����ѡ��
    if(print_set_game!=NULL&&print_set_game->enter_game()!=NULL)
    {
        if(Index>-1&&Index==4)
        {
            print_set_game->enter_game();
        }
    }
}

/**
 * ����������ʵ�֣�����+ӳ�䣩
 * direction_key ���������ṹ
 * mapping_key ӳ����������飩����ṹ
 * len ӳ������ĳ���
 */
void key_handle(directionKey* direction_key,mappingKey* mapping_key,int len)
{
    char receive_key = getChar();// �Ӽ��̻�ȡһ���ַ�
    if(receive_key!=0)
    {
        if(receive_key==-32)
        {
            receive_key = getChar();
        }
        /** ������� */
        if(direction_key!=NULL)
        {
            /** ����Ƿ���� */
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
        /** ����ӳ��� */
        if(mapping_key!=NULL&&len>0)
        {
            int i;
            for(i=0;i<len;i++)
            {
                mappingKey* mapping = mapping_key+i;
                /** �����ӳ��� */
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
 * ���ر�ѡ�еĲ˵�ѡ�����ֵ��±�ĺ�����ʵ��
 * text ��Ϸ�˵���������
 * len ��Ϸ�˵��������鳤��
 * forecolor ��ѡ�е����ֵ�ǰ��ɫ
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
 * ʵ���л���Ϸ�˵����ֵĺ�����ʵ��
 * text ��Ϸ�˵�ѡ������
 * forecolor ��ѡ�е�ѡ���ǰ��ɫ
 * backcolor ��ѡ�е�ѡ��ı���ɫ
 * len ����ĳ���
 * upordown ���ϻ����� ������
 */
void change_text(Text* text,int forecolor,int backcolor,int len,int upordown)
{
    int Index = return_selected_Index(text,len,forecolor);
    Index = Index>0?Index:0;
    /** ��ǰ����һ����ѡ�� */
    Text* v = text+Index;
    /** �޸ĵ�ǰ��ѡ�е�ѡ�����ɫ */
    v->backcolor = forecolor;
    v->forecolor = backcolor;
    /** ������һ��Ҫ��ѡ�е�ѡ�� */
    Text* nextText = NULL;
    if(upordown)// ��
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
    else// ��
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
    /** �޸���һ����ѡ�е�ѡ�� */
    nextText->backcolor = backcolor;
    nextText->forecolor = forecolor;
}

/**
 * ���ð����������ĺ���ʵ��
 */
void print_key_handle()
 {
    directionKey direction_key = {up_fun,right_fun,down_fun,left_fun};// ������ṹ��ʼ��
    mappingKey mapping_key[] = {{13,mappingkey_enter_game}};// ӳ����ṹ��ʼ��
    len_mapping = sizeof(mapping_key)/sizeof(mappingKey);// ӳ�������ĳ���
    key_handle(&direction_key,&mapping_key,len_mapping);// ������
 }

