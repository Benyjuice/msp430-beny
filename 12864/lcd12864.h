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

void write_byte(uchar byte);		//写字节函数
uchar read_byte();		//读字节函数
void lcd_busy();	//检测忙函数
void write(uchar dat_com,uchar byt); //写入函数(先写com活dat，再写所需指令或数据)

/*以下各函数为主函数中所需调用函数*/
void lcd_init();		//初始化函数
void lcd_clear();	//清屏函数
void write_zi(uchar x,uchar y,uchar *buff);		//括号中依次填行数，列数，字符串数组名称

#endif