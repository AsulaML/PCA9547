#ifndef PCA9547_h
#define PCA9547_h

    #include "main.h"
    #include <stdint.h>
    
// Adresse de base du PCA9547 en écriture et lecture
#define PCA9547_ADDR_WRITE 0xE0 // 0b1110_0000
#define PCA9547_ADDR_READ  0xE1 // 0b1110_0001

void PCA9547_Set_Channel(uint8_t canal);
uint8_t PCA9547_Read_Channel(void);

#endif