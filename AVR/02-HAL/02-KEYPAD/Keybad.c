/*
 * CFile1.c
 *
 * Created: 5/10/2020 5:55:23 AM
 *  Author: Mohamed-Sayed
 */ 
#include "Keybad.h"

#if (N_COL == 4)
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);
#elif (N_COL == 3)
static uint8 Keybad_4x3_adjust_keynumbers(uint8 button_number);
#endif
uint8 Keybad_Get_pressed_key()
{
	while(1)
	{
		for(uint8 col = 0 ; col < N_COL ; col++ )
		{
			
			DIO_Vid_Set_PORT_DIRICTION(KEYBAD_PORT ,(0b00010000 << col) );
			DIO_Vid_Set_PORT_VALUE( KEYBAD_PORT , (~(0b00010000 << col)));
			
			
			for (uint8 row = 0 ; row < N_ROW ; row++)
			{
				uint8 status = DIO_U8Get_Pin_Value(row , KEYBAD_PORT);
				if (status == 0)
				{
					#if (N_COL == 3)
					return Keybad_4x3_adjust_keynumbers((row*N_COL)+col+1);
					#elif (N_COL == 4)
					return KeyPad_4x4_adjustKeyNumber((row*N_COL)+col+1);
					#endif
				}
			}
			
		}
	}
	
}
#if (N_COL == 3)
static uint8 Keybad_4x3_adjust_keynumbers(uint8 button_number)
{
	switch(button_number)
	{
		case 10 : return '*';
		break;
		case 11 : return 0;
		break;
		case 12 : return '#';
		break;
		default: return button_number ;
		break;
	}
}
#elif (N_COL == 4)
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
		case 1: return 7;
		break;
		case 2: return 8;
		break;
		case 3: return 9;
		break;
		case 4: return '%'; // ASCII Code of %
		break;
		case 5: return 4;
		break;
		case 6: return 5;
		break;
		case 7: return 6;
		break;
		case 8: return '*'; /* ASCII Code of '*' */
		break;
		case 9: return 1;
		break;
		case 10: return 2;
		break;
		case 11: return 3;
		break;
		case 12: return '-'; /* ASCII Code of '-' */
		break;
		case 13: return 13;  /* ASCII of Enter */
		break;
		case 14: return 0;
		break;
		case 15: return '='; /* ASCII Code of '=' */
		break;
		case 16: return '+'; /* ASCII Code of '+' */
		break;
		default: return button_number;
	}
}
#endif