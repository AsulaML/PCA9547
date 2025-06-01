
/**
 * @file PCA9547.h
 * @brief Interface pour le contrôle du multiplexeur I2C PCA9547.
 *
 * Fournit les définitions et déclarations nécessaires pour sélectionner
 * ou lire le canal actif du composant PCA9547 via le bus I2C.
 */

#ifndef PCA9547_h
#define PCA9547_h

    #include "main.h"
    #include <stdint.h>
    
#define PCA9547_ADDR_WRITE 0xE0 // 0b1110_0000
#define PCA9547_ADDR_READ  0xE1 // 0b1110_0001

void PCA9547_Set_Channel(uint8_t canal);
uint8_t PCA9547_Read_Channel(void);

#endif