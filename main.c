/**
  ******************************************************************************
  * @file main.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2019-8-10 21:35:31
  * @brief  This file provides all the main functions. 
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
#include "glib.h"

#include "service_idle.h"
#include "service_master.h"
#include "service_sys.h"


#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/* 首先在main主程序中实现事件循环 */
void main_event_loop(void)
{
	GMainLoop *loop;
	loop = g_main_loop_new (NULL, FALSE);
	g_main_loop_run (loop);
	g_main_loop_unref (loop);
}

int main(int argc,char *argv[])
{
	printf("hello BinApp!!!\n");
	main_event_loop();
	return 0;
}


#ifdef  __cplusplus
}
#endif


