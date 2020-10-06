#ifndef DIO_REG_H         /*including DI/O RIGSTERS ADRESSES*/
#define DIO_REG_H

/*PORTA*/
#define PA7     7
#define PA6     6
#define PA5     5
#define PA4     4
#define PA3     3
#define PA2     2
#define PA1     1
#define PA0     0
/*PINA*/
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0
/*PINP*/
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0
/*PORTB*/
#define PB7     7
#define PB6     6
#define PB5     5
#define PB4     4
#define PB3     3
#define PB2     2
#define PB1     1
#define PB0     0
/*PORTC*/
#define PC7     7
#define PC6     6
#define PC5     5
#define PC4     4
#define PC3     3
#define PC2     2
#define PC1     1
#define PC0     0

/*PINC*/
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

/*PINC*/
#define PIND7   7
#define PIND6   6
#define PIND5   5
#define PIND4   4
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0


/*PORTD*/
#define PD7     7
#define PD6     6
#define PD5     5
#define PD4     4
#define PD3     3
#define PD2     2
#define PD1     1
#define PD0     0

#define PORTA_REG            (*(volatile uint8*)(0x3B))
#define DDRA_REG             (*(volatile uint8*)(0x3A))
#define PINA_REG             (*(volatile uint8*)(0x39))

#define PORTB_REG            (*(volatile uint8*)(0x38))
#define DDRB_REG             (*(volatile uint8*)(0x37))
#define PINB_REG             (*(volatile uint8*)(0x36))

#define PORTC_REG            (*(volatile uint8*)(0x35))
#define DDRC_REG             (*(volatile uint8*)(0x34))
#define PINC_REG             (*(volatile uint8*)(0x33))

#define PORTD_REG            (*(volatile uint8*)(0x32))
#define DDRD_REG             (*(volatile uint8*)(0x31))
#define PIND_REG             (*(volatile uint8*)(0x30))


#endif /*DIO_REG_H*/