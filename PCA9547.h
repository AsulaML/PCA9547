#ifndef PCA9547_h
#define PCA9547_h

    #include "main.h"
    #include <stdint.h>
    
void PCA9547_Set_Channel(uint8_t canal);
uint8_t PCA9547_Read_Channel(void);

#endif