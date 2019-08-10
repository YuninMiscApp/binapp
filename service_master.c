/**
  ******************************************************************************
  * @file service_master.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2019-8-10 21:36:54
  * @brief  This file provides all the service_master functions. 
  ******************************************************************************
  * @attention
  *
  * File For Yunin Software Team Only
  *
  * Copyright (C), 2017-2027, Yunin Software Team
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>

#include "glib.h"

#include "service_master.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static gpointer
service_master_thread (gpointer data)
{
	printf("service_master task running ...\n");
	
	while(1)
	{
		sleep(1);
	}
	printf("service_master task Exit ...\n");
	return NULL;
}


/***************************************************
 * Function : service_master_init
 * Author : leon.xie
 * Creat Date : 2019/08/10  22:21:0
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int service_master_init(void)
{
	g_thread_new ("service_master", service_master_thread, NULL);
    return 0;
}


#ifdef  __cplusplus
}
#endif


