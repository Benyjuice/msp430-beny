#ifndef LCD12864_H
#define LCD12864_H

#include "global_define.h"

#define com 0 
#define dat 1

#define cs   BIT3
#define sid  BIT4
#define sclk BIT5
#define lcdport P6OUT
#define lcddir P6DIR
#define lcdin P6IN
#define sid_out lcddir |= sid
#define sid_in lcddir &= ~sid
#define sid_1  lcdport |= sid
#define sid_0  lcdport &= ~sid
#define sclk_1 lcdport |= sclk
#define sclk_0 lcdport &= ~sclk
#define cs_1   lcdport |= cs
#define cs_0   lcdport &= ~cs

void write_byte(uchar byte);		//д�ֽں���
uchar read_byte();		//���ֽں���
void lcd_busy();	//���æ����
void write(uchar dat_com,uchar byt); //д�뺯��(��дcom��dat����д����ָ�������)

/*���¸�����Ϊ��������������ú���*/
void lcd_init();		//��ʼ������
void lcd_clear();	//��������
void write_zi(uchar x,uchar y,uchar *buff);		//�������������������������ַ�����������

#endif