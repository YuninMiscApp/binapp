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
#include <strings.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "glib.h"

#include "service_master.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static GAsyncQueue *masterAsyncQueue = NULL;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static gpointer
service_master_thread (gpointer data)
{
	printf("service_master task running ...\n");
	srv_master_info_t info;
	while(1)
	{
		bzero(&info,sizeof(info));
		//service_master_queue_pop,该线程会进入"睡眠/阻塞"状态,等待事件唤醒.
		service_master_queue_pop(&info);
		printf("++++++ service_master_queue_pop %d ...\n",info.cnt);
		
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
	//在线程建立之前初始化异步队列
	masterAsyncQueue = g_async_queue_new ();
	assert(masterAsyncQueue);
	g_thread_new ("service_master", service_master_thread, NULL);
    return 0;
}


int service_master_queue_push(srv_master_info_t *info)
{
	assert(info);
	assert(masterAsyncQueue);
	srv_master_info_t *tmp = (srv_master_info_t *)malloc(sizeof(srv_master_info_t));
	assert(tmp);
	memcpy(tmp,info,sizeof(srv_master_info_t));
	g_async_queue_push(masterAsyncQueue,(gpointer)tmp);
    return 0;
}

int service_master_queue_pop(srv_master_info_t *info)
{
	assert(info);
	assert(masterAsyncQueue);
	srv_master_info_t *tmp = NULL;
	tmp = g_async_queue_pop(masterAsyncQueue);
	memcpy(info,tmp,sizeof(srv_master_info_t));
	if (tmp) free(tmp);
    return 0;
}


#ifdef  __cplusplus
}
#endif


