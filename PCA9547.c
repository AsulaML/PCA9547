#include "PCA9547.h"
#include "I2C.h"


void PCA9547_Set_Channel(uint8_t canal)
{
    // On s'assure de ne garder que les 3 bits de poids faible (0–7)
    canal &= 0x07;

    I2C2_start();
    I2C2_write(PCA9547_ADDR_WRITE);        // Envoi de l'adresse esclave avec bit d'écriture
    I2C2_write(0x08 | canal);              // Bit d'activation (B3 = 1) + canal (B2–B0)
    I2C2_stop();
}


uint8_t PCA9547_Read_Channel(void)
{
    uint8_t canal;

    I2C2_start();
    I2C2_write(PCA9547_ADDR_READ);         // Envoi de l'adresse esclave avec bit de lecture
    I2C2_ACK();                            // Accusé de réception

    canal = I2C2_read();                   // Lecture du registre
    I2C2_NACK();                           // Fin de lecture
    I2C2_stop();

    return canal & 0x07;                   // On renvoie seulement les bits canal (B2–B0)
}