/**
  ******************************************************************************
  * @file service_idle.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2019-8-10 21:36:51
  * @brief  This file provides all the service_idle functions. 
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

#include "service_idle.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static GAsyncQueue *idleAsyncQueue = NULL;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static gpointer
service_idle_thread (gpointer data)
{
	printf("service_idle task running ...\n");
	srv_idle_info_t info;
	static int __cnt = 0;
	while(1)
	{
		bzero(&info,sizeof(info));
		info.cnt = __cnt++;
		service_idle_queue_push(&info);
		sleep(1);
		bzero(&info,sizeof(info));
		//执行到service_idle_queue_pop函数,该线程会进入"睡眠/阻塞"状态,等待事件唤醒.
		service_idle_queue_pop(&info);
		printf("service_idle queue_pop %d ...\n",info.cnt);
	}
	printf("service_idle task Exit ...\n");
	return NULL;
}


/***************************************************
 * Function : service_idle_init
 * Author : leon.xie
 * Creat Date : 2019/08/10  22:20:7
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int service_idle_init(void)
{
	//在线程建立之前初始化异步队列
	idleAsyncQueue = g_async_queue_new ();
	assert(idleAsyncQueue);
	//
	g_thread_new ("service_idle", service_idle_thread, NULL);
    return 0;
}


/***************************************************
 * Function : service_idle_queue_push
 * Author : leon.xie
 * Creat Date : 2019/08/10  22:35:7
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int service_idle_queue_push(srv_idle_info_t *info)
{
	assert(info);
	assert(idleAsyncQueue);
	srv_idle_info_t *tmp = (srv_idle_info_t *)malloc(sizeof(srv_idle_info_t));
	assert(tmp);
	memcpy(tmp,info,sizeof(srv_idle_info_t));
	g_async_queue_push(idleAsyncQueue,(gpointer)tmp);
    return 0;
}

/***************************************************
 * Function : service_idle_queue_pop
 * Author : leon.xie
 * Creat Date : 2019/08/10  22:37:43
 * Description : none
 * In-Parameter : as below
 * Return : as below
 * Modify : none
 **************************************************/
int service_idle_queue_pop(srv_idle_info_t *info)
{
	assert(info);
	assert(idleAsyncQueue);
	srv_idle_info_t *tmp = NULL;
	tmp = g_async_queue_pop(idleAsyncQueue);
	memcpy(info,tmp,sizeof(srv_idle_info_t));
	if (tmp) free(tmp);
    return 0;
}



#ifdef  __cplusplus
}
#endif


