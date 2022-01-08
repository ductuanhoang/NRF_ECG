/**
 * @file user_uart.c
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
#include "user_uart.h"
#include "app_timer.h"
#include "ble_nus.h"
#include "app_uart.h"
#include "nrf_uart.h"
/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/
#define USER_RX_PIN_NUMBER  6
#define USER_TX_PIN_NUMBER  5
/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Imported global variables and functions (from other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: 
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
bool user_uart_init(void)
{
    //uint32_t err_code;
    //app_uart_comm_params_t const comm_params = {
    //    .rx_pin_no = USER_RX_PIN_NUMBER,
    //    .tx_pin_no = USER_TX_PIN_NUMBER,
    //    .flow_control = APP_UART_FLOW_CONTROL_DISABLED,
    //    .use_parity = false,
    //    .baud_rate = NRF_UARTE_BAUDRATE_115200};

    //APP_UART_FIFO_INIT(&comm_params,
    //                   UART_RX_BUF_SIZE,
    //                   UART_TX_BUF_SIZE,
    //                   uart_event_handle,
    //                   APP_IRQ_PRIORITY_LOWEST,
    //                   err_code);
    //APP_ERROR_CHECK(err_code);
    //return (err_code == NRF_SUCCESS) ? 1 : 0;
}

/**
 * @brief user_uart_send send data via UART interface
 * 
 * @param data 
 * @param len 
 */
void user_uart_send(uint8_t *data, uint16_t len)
{

}
/***********************************************************************************************************************
* Static Functions
***********************************************************************************************************************/
/***********************************************************************************************************************
* Function Name:
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/

/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/