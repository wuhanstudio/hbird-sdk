/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 * Copyright (c) 2019 Nuclei Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*******************************************************************************
 * @file     system_hbird.h
 * @brief    NMSIS HummingBird RISC-V Device Peripheral Access Layer Header File
 * @version  V1.00
 * @date     14. Jul 2020
 ******************************************************************************/

#ifndef __SYSTEM_HBIRD_H__   /* ToDo: replace '<Device>' with your device name */
#define __SYSTEM_HBIRD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */

/**
 * \brief Setup the microcontroller system.
 * \details
 * Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * \brief  Update SystemCoreClock variable.
 * \details
 * Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

/**
 * \brief Register an exception handler for exception code EXCn
 */
extern void Exception_Register_EXC(uint32_t EXCn, unsigned long exc_handler);

/**
 * \brief Register an core interrupt handler
 */
extern void Interrupt_Register_CoreIRQ(uint32_t irqn, unsigned long int_handler);

/**
 * \brief Register an plic external interrupt handler
 */
extern void Interrupt_Register_ExtIRQ(uint32_t irqn, unsigned long int_handler);

/**
 * \brief Get current exception handler for exception code EXCn
 */
extern unsigned long Exception_Get_EXC(uint32_t EXCn);

/**
 * \brief Common trap entry
 */
extern uint32_t core_trap_handler(unsigned long mcause, unsigned long sp);

/**
 * \brief Register a riscv core interrupt and register the handler
 */
extern int32_t Core_Register_IRQ(uint32_t irqn, void *handler);

/**
 * \brief  Register a specific plic interrupt and register the handler
 */
extern int32_t PLIC_Register_IRQ(uint32_t source, uint8_t priority, void *handler);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_HBIRD_H__ */
