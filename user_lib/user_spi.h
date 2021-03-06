/**
 * @file user_spi.h
 * @author tuanhd2 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef USER_SPI_H
#define USER_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "common.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***         Exported global functions                                     ***/
/****************************************************************************/
bool user_spi_driver_init(void);

bool user_spi_send_data(uint8_t * cmd, uint16_t length);

void spi_gpio_set_dc(void);
void spi_gpio_clear_dc(void);

void spi_gpio_clear_res(void);
void spi_gpio_set_res(void);

#ifdef __cplusplus
}
#endif


#endif //USER_SPI_H