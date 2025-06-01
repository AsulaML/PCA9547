#include "Mux.h"
#include "I2C.h"


void PCA9547_Set_Channel(uint8_t canal)
{
    canal &= 0x07;
    // D7| D6| D5| D4|
    // X | X | X | X | B3 | B2 | B1 | B0 |
    // B3 : enable bit
    
    I2C2_start();
    I2C2_write(0b11100000);

    switch(canal)
    {
        case(0):
            I2C2_write(0b11111000);
            break;
        case(1):
            I2C2_write(0b11111001);
            break;
        case(2):
            I2C2_write(0b11111010);
            break;  
        case(3):
            I2C2_write(0b11111011);
            break; 
        case(4):
            I2C2_write(0b11111100);
            break;    
        case(5):
            I2C2_write(0b11111101);
            break;    
        case(6):
            I2C2_write(0b11111110);
            break;    
        case(7):
            I2C2_write(0b11111111);
            break;    
    }

    I2C2_stop();
}


uint8_t PCA9547_Read_Channel(void)
{
    uint8_t canal = 0;
    
    I2C2_start();
    I2C2_write(0b11100001); 
    I2C2_ACK();            
    
    canal = I2C2_read();
    I2C2_NACK();            
    I2C2_stop();    
    
    canal &= 0x07;
    return(canal);
}