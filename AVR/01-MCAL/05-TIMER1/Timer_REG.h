/*
 * IncFile1.h
 *
 * Created: 5/9/2020 4:22:44 AM
 *  Author: Mohamed-Sayed
 */ 


#ifndef Timer_REG_H_
#define Timer_REG_H_

/*TIMER interrupt registers*/
#define     TIMSK_REG          (*(volatile uint8*)(0x59))
#define     TIFR_REG           (*(volatile uint8*)(0x58))

/*TIMER0 registers*/
#define     OCR0_REG          (*(volatile uint8*)(0x5C))
#define     TCCR0_REG         (*(volatile uint8*)(0x53))
#define     TCNT0_REG         (*(volatile uint8*)(0x52))

/*TIMER1 registers*/
#define     TCCR1A_REG        (*(volatile uint8*)(0x4F))
#define     TCCR1B_REG        (*(volatile uint8*)(0x4E))
#define     TCNT1H_REG        (*(volatile uint8*)(0x4D))
#define     TCNT1L_REG        (*(volatile uint8*)(0x4C))
#define     OCR1AH_REG        (*(volatile uint8*)(0x4B))
#define     OCR1AL_REG        (*(volatile uint8*)(0x4A))
#define     OCR1BH_REG        (*(volatile uint8*)(0x49))
#define     OCR1BL_REG        (*(volatile uint8*)(0x48))
#define     ICR1H_REG         (*(volatile uint8*)(0x47))
#define     ICR1L_REG         (*(volatile uint8*)(0x46))
#define     TCNT1_REG         (*(volatile uint16*)(0x4C))
#define     ICR1_REG          (*(volatile uint16*)(0x46))
#define     OCR1A_REG         (*(volatile uint16*)(0x4A))
#define     OCR1B_REG         (*(volatile uint16*)(0x48))


/*TIMER2 registers*/
#define     TCCR2_REG         (*(volatile uint8*)(0x45))
#define     TCNT2_REG         (*(volatile uint8*)(0x44))
#define     OCR2_REG          (*(volatile uint8*)(0x43))


/*Watch dog TIMER registers*/
#define     WDTCR_REG             (*(volatile uint16*)(0x41))



/*TIMSK Bits*/
#define OCIE2      7
#define TOIE2      6
#define TICIE1     5
#define OCIE1A     4
#define OCIE1B     3
#define TOIE1      2
#define OCIE0      1
#define TOIE0      0


/*TIFR Bits*/
#define OCF2      7
#define TOV2      6
#define ICF1      5
#define OCF1A     4
#define OCF1B     3
#define TOV1      2
#define OCF0      1
#define TOV0      0



/*TCCR0 Bits*/
#define FOC0      7
#define WGM00     6
#define COM01     5
#define COM00     4
#define WGM01     3
#define CS02      2
#define CS01      1
#define CS00      0


/*TCCR1A Bits*/
#define COM1A1     7
#define COM1A0     6
#define COM1B1     5
#define COM1B0     4
#define FOC1A      3
#define FOC1B      2
#define WGM11      1
#define WGM10      0


/*TCCR1B Bits*/
#define ICNC1     7
#define ICES1     6
/*Bit 5 is Reserved*/
#define WGM13     4
#define WGM12     3
#define CS12      2
#define CS11      1
#define CS10      0

/*TCCR2 Bits*/
#define FOC2      7
#define WGM20     6
#define COM21     5
#define COM20     4
#define WGM21     3
#define CS22      2
#define CS21      1
#define CS20      0



/*WDTCR Bits*/
/*Bit 7-->5 is Reserved*/
#define WDTOE     4
#define WDE       3
#define WDP2      2
#define WDP1      1
#define WDP0      0



#endif /* Timer_REG_H_ */