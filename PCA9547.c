#include "Mux.h"
#include "I2C.h"

// Disposition des capteurs mag
// 
// CH6 : U11        CH0 : U8 
//
//          CH1 : U9
//
// CH7 : U12        CH2 : U10


void switch_canal(uint8_t canal)
{
    canal &= 0x07;
    // D7| D6| D5| D4|
    // X | X | X | X | B3 | B2 | B1 | B0 |
    // B3 : enable bit
    
    //CTRL = 0xF8; // Forçage à 1 de D7 à B3
    //CTRL |= canal;
    
    //CTRL = canal;
    //CTRL |=0xF8;
    I2C2_start();
    I2C2_write(0b11100000); // Write
    //I2C2_ACK();             // test
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

    //I2C2_write(CTRL);
    //I2C2_ACK();             // test
    I2C2_stop();
}


uint8_t read_canal(void)
{
    uint8_t canal = 0;
    
    I2C2_start();
    I2C2_write(0b11100001); // Write
    I2C2_ACK();             // test
    
    canal = I2C2_read();
    I2C2_NACK();             // test
    I2C2_stop();    
    
    canal &= 0x07;
    return(canal);
}