/**
  ******************************************************************************
  * @file service_master.h 
  * @author leon.xie
  * @version v1.0.0
  * @date 2019-8-10 21:38:04
  * @brief This file contains all the functions prototypes for the BOARD 
  *  service_master 
  ******************************************************************************
  * @attention
  *
  * File For Yunin Software Team Only
  *
  * Copyright (C), 2017-2027, Yunin Software Team
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __SERVICE_MASTER_H
#define __SERVICE_MASTER_H

/* Includes ------------------------------------------------------------------*/


#ifdef  __cplusplus
extern "C" {
#endif

/* Exported typedef ----------------------------------------------------------*/
typedef struct srv_master_info_s {
    int cnt;
}srv_master_info_t;

/* Exported variables --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
int service_master_init(void);
int service_master_queue_push(srv_master_info_t *info);
int service_master_queue_pop(srv_master_info_t *info);

#ifdef  __cplusplus
}
#endif

#endif  /* __SERVICE_MASTER_H */


