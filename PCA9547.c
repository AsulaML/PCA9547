/**
 * @file PCA9547.c
 * @brief Contrôle d'un multiplexeur I2C PCA9547 via le bus I2C.
 * 
 * Ce fichier contient les fonctions permettant de sélectionner un canal
 * sur le multiplexeur PCA9547 et de lire le canal actuellement sélectionné.
 */
#include "PCA9547.h"
#include "I2C.h"

/**
 * @brief Sélectionne un canal sur le multiplexeur PCA9547.
 *
 * Cette fonction configure le PCA9547 pour qu’il connecte un de ses 8 canaux (0–7) 
 * à la ligne I2C principale. Le canal est activé via un octet d’instruction 
 * où le bit 3 (enable) est à 1, suivi du numéro du canal sur les bits 2:0.
 *
 * @param canal Le numéro du canal à activer (valeurs acceptées : 0 à 7).
 */
void PCA9547_Set_Channel(uint8_t canal)
{
    // On s'assure de ne garder que les 3 bits de poids faible (0–7)
    canal &= 0x07;

    I2C2_start();
    I2C2_write(PCA9547_ADDR_WRITE);        // Envoi de l'adresse esclave avec bit d'écriture
    I2C2_write(0x08 | canal);              // Bit d'activation (B3 = 1) + canal (B2–B0)
    I2C2_stop();
}

/**
 * @brief Lit le canal actuellement activé sur le multiplexeur PCA9547.
 *
 * Cette fonction interroge le registre de contrôle du PCA9547 afin 
 * de déterminer quel canal est actuellement sélectionné.
 *
 * @return uint8_t Le numéro du canal activé (0 à 7).
 */
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