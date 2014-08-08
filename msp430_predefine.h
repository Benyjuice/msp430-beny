#ifndef __MSP430_PREDEFINE_H
#define __MSP430_PREDEFINE_H

*
*               MSP430 Port Function defination
*       使用说明：
*               1.定义信号 #define IO_XXXX(m) m(port,bit,Y/N)
*               2.IO_SET(XXXX) 置位 IO_CLR(XXXX) 清零
*                 IO_DIR_I(XXXX) 设置输入
*                 IO_DIR_O(XXXX) 设置输出
*
*/
#define IO_SET(name)                            IO_##name(IO_SET_) 
#define IO_SET_(port, bit, inv)                 IO_SET_##inv(port, bit) 
#define IO_SET_Y(port, bit)                     P##port##OUT &= ~(1<<bit) 
#define IO_SET_N(port, bit)                     P##port##OUT |= (1<<bit) 

#define IO_CLR(name)                            IO_##name(IO_CLR_) 
#define IO_CLR_(port, bit, inv)                 IO_CLR_##inv(port, bit) 
#define IO_CLR_Y(port, bit)                     P##port##OUT |= (1<<bit) 
#define IO_CLR_N(port, bit)                     P##port##OUT &= ~(1<<bit) 

#define IO_DIR_O(name)                          IO_##name(IO_DIR_O_) 
#define IO_DIR_I(name)                          IO_##name(DIR_I_) 
#define IO_DIR_O_(port, bit, inv)               P##port##DIR |= (1<<bit) 
#define IO_DIR_I_(port, bit, inv)               P##port##DIR &=~ (1<<bit) 

#define IO_TEST(name)                           IO_#name(IO_TEST_) 
#define IO_TEST_(port, bit, inv)                IO_TEST_##inv(port, bit) 
#define IO_TEST_Y(port, bit)                    ((P##port##IN & (1<<bit)) == 0) 
#define IO_TEST_N(port, bit)                    ((P##port##IN & (1<<bit)) != 0) 

#define IO_PORT(name)                           IO_##name(IO_PORT_) 
#define IO_PORT_(port, bit, inv)                port 

#define IO_BIT(name)                            IO_##name(IO_BIT_) 
#define IO_BIT_(port, bit, inv)                 (1<<bit)

/*
*     MSP430 time delay function
*     Usage:
*           Modify  CPU_F to your cpu frequency 
*
*/
//CPU frequency scaled by Hz
#define CPU_F ((double)4000000)

#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))
