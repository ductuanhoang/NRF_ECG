

/**
 * @file process_read_ecg.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
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
#include "common.h"
#include "process_read_ecg.h"
#include "timer_service.h"
#include "user_spi.h"
#include "user_uart.h"
#include "nrf_delay.h"
/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/
/**
 * ADS129X_INTF_RET_TYPE is the read/write interface return type which can be overwritten by the build system.
 * The default is set to int8_t.
 */
#ifndef ADS129X_INTF_RET_TYPE
#define ADS129X_INTF_RET_TYPE bool
#endif

/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/
typedef ADS129X_INTF_RET_TYPE (*ads129x_read_fptr_t)(uint8_t reg_addr, uint8_t *reg_data, uint32_t length,
                                                    void *intf_ptr, uint32_t delay);

typedef ADS129X_INTF_RET_TYPE (*ads129x_write_fptr_t)(uint8_t *cmd, uint16_t length);

typedef void (*ads129x_delay_ms_fptr_t)(uint32_t period);

typedef struct
{
    /*! Read function pointer */
    ads129x_read_fptr_t read;

    /*! Write function pointer */
    ads129x_write_fptr_t write;

    /*! Delay function pointer */
    ads129x_delay_ms_fptr_t delay_us;
} ads1292_sensor_t;

ads1292_sensor_t ads1292_sensor;
/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/
/**
 * @brief process_read_ecg read and print signal ecg
 * call in loop or event timeout of timer
 * 
 */
static void process_read_ecg(void *p);

/***********************************************************************************************************************
* Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Imported global variables and functions (from other files)
***********************************************************************************************************************/

void process_read_ecg_init(void)
{
    user_uart_init();
    user_timer_callback(process_read_ecg);
    user_timer_service_init();

    // ads1292_sensor.read = user_spi_recive
    ads1292_sensor.write = user_spi_send_data;
    ads1292_sensor.delay_us = nrf_delay_ms;
}

/**
 * @brief process_read_ecg read and print signal ecg
 * call in loop or event timeout of timer
 * 
 */
static void process_read_ecg(void *p)
{
    USER_UART_PRINT("tesst\r\n");
}
/***********************************************************************************************************************
* static functions
***********************************************************************************************************************/
static void ads1292_sensor_read_id(void *p)
{
    ads1292_sensor.read();
}
/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/
