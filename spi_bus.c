/* 
 *  Copyright (c) 2014 Robin Callender. All Rights Reserved.
 */

#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "common.h"
#include "app_error.h"
#include "app_util_platform.h"
#include "spi_master.h"
#include "pca10001_board.h"

#include "spi_bus.h"

/*
 *  SPI Bus controller interrupt handler.
 */
void spi_event_handler(spi_master_evt_t event)
{
    switch (event.evt_type) {

        case SPI_MASTER_EVT_TRANSFER_COMPLETED:
            break;
        
        default:
            // No implementation needed.
            break;
    }
}

/*
 *  Function for initializing a SPI master driver.
 *
 *  param[in] instance       An instance of SPI master module.
 *  param[in] event_handler  An event handler for SPI master events.
 *  param[in] config         SPI configuration structure.
 */
uint32_t spi_init(spi_master_hw_instance_t    instance, 
                  spi_master_config_t       * config)
{
    uint32_t status = NRF_SUCCESS;
    
    status = spi_master_open(instance, config);
    if (status != NRF_SUCCESS) {
        return status;
    }
    
    // Register event handler for SPI master.
    spi_master_evt_handler_reg(instance, spi_event_handler);

    return status;
}

/*
 *  Function for decommissioning a SPI master driver.
 *
 *  param[in] instance       An instance of SPI master module.
 */
void spi_close(spi_master_hw_instance_t instance)
{
    spi_master_close(instance); 
}

/*
 *  Function for sending and receiving data.
 *
 *  param[in]   instance       SPI master instance.
 *  param[in]   p_tx_data      A pointer to a buffer TX.
 *  param[in]   tx_len         A length of the data buffers.
 *  param[out]  p_rx_data      A pointer to a buffer RX.
 *  param[in]   rx_len         A length of the data buffers.
 */
uint32_t spi_send_recv(const spi_master_hw_instance_t instance,
                       uint8_t * const p_tx_data, const uint16_t tx_len,
                       uint8_t * const p_rx_data, const uint16_t rx_len)
{
    uint32_t status = spi_master_send_recv(instance, 
                                           p_tx_data, tx_len, 
                                           p_rx_data, rx_len);
    return status;
}
