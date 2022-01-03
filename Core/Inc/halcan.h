/**
  ******************************************************************************
  * @file    halcan.h
  * @brief   This file contains all the function prototypes for
  *          the can.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HALCAN_H__
#define __HALCAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
/* USER CODE BEGIN Includes */
//#include "applicfg.h"
//#define Message_Initializer {0,0,0,{0,0,0,0,0,0,0,0}}
typedef struct
{
	uint8_t Data[8];
}CAN_RecvMsg;

//typedef struct {
//  UNS16 cob_id;	/**< message's ID */
//  UNS8 rtr;		/**< remote transmission request. (0 if not rtr message, 1 if rtr message) */
//  UNS8 len;		/**< message's length (0 to 8) */
//  UNS8 data[8]; /**< message's datas */
//} Message;

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_CAN1_Init(void);
void MX_CAN2_Init(void);

/* USER CODE BEGIN Prototypes */
void CAN_TRANSMIT1(Message *m);
void CAN_TRANSMIT2(Message *m);
//void CAN_TR(Message *m);
//typedef UNS8 (*canSend_t)(Message *);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __HALCAN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
