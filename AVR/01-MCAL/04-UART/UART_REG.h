#ifndef UART_REG_H
#define UART_REG_H

#define UDR_REG              (*(volatile uint8*)(0x2C)) 
#define UCSRA_REG            (*(volatile uint8*)(0x2B))
#define UCSRB_REG            (*(volatile uint8*)(0x2A))
#define UCSRC_REG            (*(volatile uint8*)(0x40))
#define UBRRH_REG            (*(volatile uint8*)(0x40))    
#define UBRRL_REG            (*(volatile uint8*)(0x29))


/*UCSRC_REG BITS*/
#define  UCPOL  0
#define  UCSZ0  1
#define  UCSZ1  2
#define  USBS   3
#define  UPM0   4
#define  UPM1   5
#define  UMSEL  6
#define  URSEL  7
     
/*UCSRA_REG BITS*/
#define  MPCM   0
#define  U2X    1
#define  PE     2
#define  DOR    3
#define  FE     4
#define  UDRE   5
#define  TXC    6
#define  RXC    7
       
/*UCSRB_REG BITS*/
#define  TXB8   0
#define  RXB8   1
#define  UCSZ2  2
#define  TXEN   3
#define  RXEN   4
#define  UDRIE  5
#define  TXCIE  6
#define  RXCIE  7

#endif /*UART_REG_H*/