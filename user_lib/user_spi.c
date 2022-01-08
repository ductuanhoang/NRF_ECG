/**
 * @file user_spi.c
 * @author tuanhd2 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/***********************************************************************************************************************
* Pragma directive
***********************************************************************************************************************/

/***********************************************************************************************************************
* Includes <System Includes>
***********************************************************************************************************************/
#include "user_spi.h"
#include "nrf_drv_spi.h"
#include "app_util_platform.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/

/**< Transfer length. */
#define PAPER_RST_PIN 13
#define PAPER_DC_PIN  14

#define PAPER_SPI_INSTANCE 0

#define PAPER_SPI_SS_PIN   29
#define PAPER_SPI_MOSI_PIN 4
#define PAPER_SPI_SCK_PIN  3

/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/
static const nrf_drv_spi_t user_spi = NRF_DRV_SPI_INSTANCE(PAPER_SPI_INSTANCE);  /**< SPI instance. */
static volatile bool spi_xfer_done;  /**< Flag used to indicate that SPI instance completed the transfer. */

void spi_event_handler(nrf_drv_spi_evt_t const * p_event,
                       void *                    p_context);
/***********************************************************************************************************************
* Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/


/***********************************************************************************************************************
* Imported global variables and functions (from other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: user_spi_driver_init
* Description  : user driver init spi
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
bool user_spi_driver_init(void)
{
  bool status = true;

  ret_code_t ret;

  nrf_drv_spi_config_t spi_config = NRF_DRV_SPI_DEFAULT_CONFIG;
  spi_config.ss_pin   = PAPER_SPI_SS_PIN;
  spi_config.mosi_pin = PAPER_SPI_MOSI_PIN;
  spi_config.sck_pin  = PAPER_SPI_SCK_PIN;

  ret = nrf_drv_spi_init(&user_spi, &spi_config, NULL, NULL);
  if (ret != NRF_SUCCESS)
  {
     NRF_LOG_INFO("user_spi_driver_init error.");
    return false;
  }
  // init gpio
  nrf_gpio_cfg_output(PAPER_RST_PIN);
  nrf_gpio_cfg_output(PAPER_DC_PIN);

  NRF_LOG_INFO("user_spi_driver_init done.");

  return status;
}
/***********************************************************************************************************************
* Function Name: user_spi_send_data
* Description  : user spi send data
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
bool user_spi_send_data(uint8_t * cmd, uint16_t length)
{
//    bool status = true;
//    ret_code_t ret;
//    ret = nrf_drv_spi_transfer(&user_spi, cmd, 1, NULL, 0);
//    if (ret != NRF_SUCCESS) return true;
//
//    return status;
    
  ret_code_t ret;
  
  ret = nrf_drv_spi_transfer(&user_spi, cmd, 1, NULL, 0);
  if (ret != NRF_SUCCESS) return ret;

  if (length - 1 > 0) {
      ret = nrf_drv_spi_transfer(&user_spi, cmd + 1, length - 1, NULL, 0);
      if (ret != NRF_SUCCESS) return false;
  }

  return true;
}

/***********************************************************************************************************************
* Function Name: spi_gpio_set_dc
* Description  : user
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void spi_gpio_set_dc(void)
{
    nrf_gpio_pin_set(PAPER_DC_PIN);;
}

void spi_gpio_clear_dc(void)
{
    nrf_gpio_pin_clear(PAPER_DC_PIN);
}

/***********************************************************************************************************************
* Function Name: spi_gpio_clear_res
* Description  : user
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void spi_gpio_clear_res(void)
{
     nrf_gpio_pin_clear(PAPER_RST_PIN);
}

void spi_gpio_set_res(void)
{
    nrf_gpio_pin_set(PAPER_RST_PIN);
}
/***********************************************************************************************************************
* static functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/

