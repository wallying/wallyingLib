#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#define KEY_TABLE_NUM   (100)


struct key_isr_t {
    char key_char;
    void (*dn_cbk)(char key);
    void (*up_cbk)(char key);
    uint8_t triggered_flag;
};

static struct key_isr_t key_table[KEY_TABLE_NUM];


static DWORD WINAPI key_ISR(LPVOID lpParameter)
{
    while (1)
    {
        for (int i = 0; i < KEY_TABLE_NUM; i++) {
            if (key_table[i].key_char == '\0') {
                continue;
            }
            if (GetKeyState(key_table[i].key_char) < 0) {
                if (key_table[i].triggered_flag == 0) {
                    key_table[i].triggered_flag = 1;
                    if (key_table[i].dn_cbk) {
                        key_table[i].dn_cbk(key_table[i].key_char);
                    }
                }
            } else {
                if (key_table[i].triggered_flag == 1) {
                    key_table[i].triggered_flag = 0;
                    if (key_table[i].up_cbk) {
                        key_table[i].up_cbk(key_table[i].key_char);
                    }
                }
            }
        }
        Sleep(10);
    }
    return 0;
}

void key_register(char key, void (*dncbk)(char key), void (*upcbk)(char key))
{
    static uint8_t inited_flag = 0;

    if (key == '\0') {
        return;
    }
    if ((dncbk == NULL) && (upcbk == NULL)) {
        return;
    }

    if (inited_flag == 0)
    {
        memset(key_table, 0x00, sizeof(key_table));

        HANDLE keyThread = CreateThread(0, 0, key_ISR, 0, 0, 0);
        if (keyThread == NULL) {
            return;
        }

        inited_flag = 1;
    }

    for (int i = 0; i < KEY_TABLE_NUM; i++)
    {
        if (key_table[i].key_char == key)
        {
            key_table[i].key_char = key;
            key_table[i].dn_cbk = dncbk;
            key_table[i].up_cbk = upcbk;
            key_table[i].triggered_flag = 0;
            return;
        }
    }

    for (int i = 0; i < KEY_TABLE_NUM; i++)
    {
        if (key_table[i].key_char == '\0')
        {
            key_table[i].key_char = key;
            key_table[i].dn_cbk = dncbk;
            key_table[i].up_cbk = upcbk;
            key_table[i].triggered_flag = 0;
            return;
        }
    }
}

void key_unregister(char key)
{
    if (key == '\0') {
        return;
    }

    for (int i = 0; i < KEY_TABLE_NUM; i++)
    {
        if (key_table[i].key_char == key)
        {
            key_table[i].key_char = '\0';
            key_table[i].dn_cbk = NULL;
            key_table[i].up_cbk = NULL;
            key_table[i].triggered_flag = 0;
            return;
        }
    }
}

