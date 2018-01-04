#ifndef __UART_H
#define __UART_H

#include <stdio.h>
#include <stdarg.h>
#include "type.h"

void Uart_Init(uint32 bound);
void Uart_Transmit(unsigned char data);
void Uart_Puts(char *string);
// void Uart_Printf(char *format, ...);

#endif
