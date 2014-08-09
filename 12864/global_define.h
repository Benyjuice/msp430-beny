#ifndef GOLBAL_DEFINE_H
#define GOLBAL_DEFINE_H

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

#define nop asm("nop");

#define CPU_F ((double)8000000)  
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))  
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0)) 

#define ring_shift_left(yiweiqian, yiweishu)    yiweiqian<<yiweishu|yiweiqian>>(8-yiweishu)
#define ring_shift_right(yiweiqian,yiweishu)    yiweiqian<<(8-yiweishu)|yiweiqian>>yiweishu

#endif