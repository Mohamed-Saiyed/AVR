#ifndef Keybad_H
#define Keybad_H


#define KEYBAD_PORT      PORTC
#define N_COL 4
#define N_ROW 4

#include "DIO_INIT.h"

uint8 Keybad_Get_pressed_key(void);

#endif /*Keybad_H*/
