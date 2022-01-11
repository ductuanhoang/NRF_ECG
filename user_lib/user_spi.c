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
#define USER_SPI_INSTANCE 0
/**
 * @brief define pin for SPI
 * 
 */
#define USER_SPI_SS_PIN 20
#define USER_SPI_MOSI_PIN 19
#define USER_SPI_MISO_PIN 17
#define USER_SPI_SCK_PIN 18
/**
 * @brief define max length recive
 * 
 */
#define USER_SPI_MAX_LENGTH 30
/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/
static const nrf_drv_spi_t user_spi = NRF_DRV_SPI_INSTANCE(USER_SPI_INSTANCE); /**< SPI instance. */
static volatile bool spi_xfer_done;                                            /**< Flag used to indicate that SPI instance completed the transfer. */

void spi_event_handler(nrf_drv_spi_evt_t const *p_event,
                       void *p_context);

static volatile bool m_transfer_completed = true; /**< A flag to inform about completed transfer. */
/***********************************************************************************************************************
* Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Imported global variables and functions (from other files)
***********************************************************************************************************************/
static uint8_t m_rx_buf[USER_SPI_MAX_LENGTH];
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
    spi_config.ss_pin = USER_SPI_SS_PIN;
    spi_config.miso_pin = USER_SPI_MISO_PIN;
    spi_config.mosi_pin = USER_SPI_MOSI_PIN;
    spi_config.sck_pin = USER_SPI_SCK_PIN;

    APP_ERROR_CHECK(nrf_drv_spi_init(&user_spi, &spi_config, spi_event_handler, NULL));
    if (ret != NRF_SUCCESS)
    {
        NRF_LOG_INFO("user_spi_driver_init error.");
        return false;
    }
    // init gpio
    // nrf_gpio_cfg_output(PAPER_RST_PIN);
    // nrf_gpio_cfg_output(PAPER_DC_PIN);

    NRF_LOG_INFO("user_spi_driver_init done.");

    return status;
}
/***********************************************************************************************************************
* Function Name: user_spi_send_data
* Description  : user spi send data
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
bool user_spi_send_data(uint8_t *cmd, uint16_t length)
{
    ret_code_t ret;

    ret = nrf_drv_spi_transfer(&user_spi, cmd, 1, NULL, 0);
    if (ret != NRF_SUCCESS)
        return ret;

    if (length - 1 > 0)
    {
        ret = nrf_drv_spi_transfer(&user_spi, cmd + 1, length - 1, NULL, 0);
        if (ret != NRF_SUCCESS)
            return false;
    }

    return true;
}


/**@brief Functions prepares buffers and starts data transfer.
 *
 * @param[in] p_tx_data     A pointer to a buffer TX.
 * @param[in] p_rx_data     A pointer to a buffer RX.
 * @param[in] len           A length of the data buffers.
 */
void spi_send_recv(uint8_t * const p_tx_data,
                   uint8_t * const p_rx_data,
                   const uint16_t len)
{
    m_transfer_completed = false;
    // Start transfer.
    nrf_drv_spi_transfer(&m_spi_master,
                         p_tx_data, len, p_rx_data, len);
    while (!m_transfer_completed);
}


uint8_t* spi_transfer(uint8_t * message, const uint16_t len)
{
    memcpy((void*)m_tx_data, (void*)message, len);
    spi_send_recv(m_tx_data, m_rx_data, len);
    return m_rx_data;
}

/**
 * @brief SPI user event handler.
 * @param event
 */
void spi_event_handler(nrf_drv_spi_evt_t const *p_event,
                       void *p_context)
{
    spi_xfer_done = true;
    NRF_LOG_INFO("Transfer completed.");
    if (m_rx_buf[0] != 0)
    {
        NRF_LOG_INFO(" Received:");
        NRF_LOG_HEXDUMP_INFO(m_rx_buf, strlen((const char *)m_rx_buf));
    }

    switch (event) {
    case NRF_DRV_SPI_EVENT_DONE:
        // Inform application that transfer is completed.
        m_transfer_completed = true;
        break;

    default:
        // No implementation needed.
        break;
    }

}

/***********************************************************************************************************************
* static functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/
