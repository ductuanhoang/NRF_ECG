
#ifndef APP_CONFIG_H
#define APP_CONFIG_H


// <e> NRFX_SPIM_ENABLED - nrfx_spim - SPIM peripheral driver
//==========================================================
#ifndef NRFX_SPIM_ENABLED
#define NRFX_SPIM_ENABLED 1
#endif
// <q> NRFX_SPIM0_ENABLED  - Enable SPIM0 instance
 

#ifndef NRFX_SPIM0_ENABLED
#define NRFX_SPIM0_ENABLED 1
#endif

// <e> NRFX_SPI_ENABLED - nrfx_spi - SPI peripheral driver
//==========================================================
#ifndef NRFX_SPI_ENABLED
#define NRFX_SPI_ENABLED 1
#endif

// <e> SPI_ENABLED - nrf_drv_spi - SPI/SPIM peripheral driver - legacy layer
//==========================================================
#ifndef SPI_ENABLED
#define SPI_ENABLED 1
#endif


// <e> SPI0_ENABLED - Enable SPI0 instance
//==========================================================
#ifndef SPI0_ENABLED
#define SPI0_ENABLED 1
#endif

#endif //APP_CONFIG_H

