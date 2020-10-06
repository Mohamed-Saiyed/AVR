#ifndef SPI_REG_H_
#define SPI_REG_H_


#define     SPCR_REG          (*(volatile uint8*)(0x2D))
#define     SPSR_REG          (*(volatile uint8*)(0x2E))
#define     SPDR_REG          (*(volatile uint8*)(0x2F))


/*SPCR BITS*/
#define SPIE     7
#define SPE      6
#define DORD     5
#define MSTR     4
#define CPOL     3
#define CPHA     2
#define SPR1     1
#define SPR0     0

/*SPSR BITS*/
#define SPIF     7
#define WCOL     6
/*bit 1-->5 Reserved Bits*/
#define SPI2X    0


/*SPDR is a data rigster*/
#endif  /*SPI_REG_H_*/