

/**
 * @file timer_service.c
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
#include "timer_service.h"
#include "app_timer.h"
/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/
#define USER_TIMER_MEAS_INTERVAL APP_TIMER_TICKS(1000)
APP_TIMER_DEF(m_user_timer_id);
/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/
static void user_timer_timeout_handler(void *p_context);
timer_callback timeout_handler;
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
void user_timer_service_init(void)
{
    ret_code_t err_code;
    err_code = app_timer_create(&m_user_timer_id,
                                APP_TIMER_MODE_REPEATED,
                                timeout_handler);
    // Start battery timer
    err_code = app_timer_start(m_user_timer_id, USER_TIMER_MEAS_INTERVAL, NULL);
}

/**
 * @brief call back function regered timer timer out
 * 
 * @param cb 
 */
void user_timer_callback(timer_callback cb)
{
    timeout_handler = cb;
}
/***********************************************************************************************************************
* static functions
***********************************************************************************************************************/
static void user_timer_timeout_handler(void *p_context)
{
    NRF_LOG_DEBUG("user_timer_timeout_handler call");
}
/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/