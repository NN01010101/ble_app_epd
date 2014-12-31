/* 
 *  Copyright (c) 2014 Robin Callender. All Rights Reserved.
 */

#ifndef SPI_BUS_H__
#define SPI_BUS_H__

#include <stdint.h>

#include "nrf.h"
#include "spi_master.h"

/*
 *  Function for initializing a SPI master driver.
 *
 *  param[in] instance       An instance of SPI master module.
 *  param[in] event_handler  An event handler for SPI master events.
 *  param[in] config         SPI configuration structure.
 */
uint32_t spi_init(spi_master_hw_instance_t   spi_master_instance, 
                  spi_master_config_t      * spi_config);

/*
 *  Function for decommissioning a SPI master driver.
 *
 *  param[in] instance       An instance of SPI master module.
 */
void spi_close(spi_master_hw_instance_t instance);

/*
 *  Function for sending and receiving data.
 *
 *  param[in]   instance       SPI master instance.
 *  param[in]   p_tx_data      A pointer to a buffer TX.
 *  param[in]   tx_len         A length of the data buffers.
 *  param[out]  p_rx_data      A pointer to a buffer RX.
 *  param[in]   rx_len         A length of the data buffers.
 */
uint32_t spi_send_recv(const spi_master_hw_instance_t spi_master_hw_instance,
                       uint8_t * const p_tx_data, const uint16_t tx_len,
                       uint8_t * const p_rx_data, const uint16_t rx_len);

#endif /* SPI_BUS_H__ */
