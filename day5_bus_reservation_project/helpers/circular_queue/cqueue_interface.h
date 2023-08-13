/*
 * cqueue_interface.h
 *
 * Created: 25/5/2023 2:32:23 AM
*  Author: hossam Elwahsh - https://github.com/HossamElwahsh
 */ 


#ifndef CQUEUE_INTERFACE_H_
#define CQUEUE_INTERFACE_H_

/* Self includes */
#include "cqueue_preconfig.h"

/* Utils */
#include "../std.h"

typedef struct {
	void * uint8_cq_buffer[QUEUE_SIZE];
	uint16_t_ uint16_front;
    uint16_t_ uint16_rear;
    uint16_t_ uint16_count;
} str_circular_queue_t_;

typedef enum{
    QUEUE_OK        =   0,
    QUEUE_EMPTY,
    QUEUE_NOT_EMPTY,
    QUEUE_FULL,
    QUEUE_NOT_FULL,
    QUEUE_ERROR
}enu_queue_error_t_;


 /**
 * @brief                                       :   initializes circular queue
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  QUEUE_OK                            :   Success
 *          QUEUE_ERROR                         :   Failed
 */
enu_queue_error_t_      cqueue_initializeQueue      (str_circular_queue_t_* ptr_str_circular_queue);

/**
 * @brief                                       :   checks if queue is empty
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  QUEUE_EMPTY                         :   Queue is empty
 *          QUEUE_NOT_EMPTY                     :   Queue not empty
 *          QUEUE_ERROR                         :   Failed
 */
enu_queue_error_t_      cqueue_isQueueEmpty         (const str_circular_queue_t_* ptr_str_circular_queue);

/**
 * @brief                                       :   checks if queue is full
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  QUEUE_FULL                          :   Queue full
 *          QUEUE_NOT_FULL                      :   Queue not full
 *          QUEUE_ERROR                         :   Failed
 */
enu_queue_error_t_      cqueue_isQueueFull          (const str_circular_queue_t_* ptr_str_circular_queue);

/**
 * @brief                                       :   enqueue a byte to queue
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 * @param[in]       uint8_data                  :   byte to enqueue
 *
 * @return  QUEUE_OK                            :   Success
 *          QUEUE_FULL                          :   Queue full
 *          QUEUE_ERROR                         :   Failed
 */
enu_queue_error_t_      cqueue_enqueue              (str_circular_queue_t_* ptr_str_circular_queue, void * data);

/**
 * @brief                                       :   dequeue a byte to queue
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 * @param[in,out]   ptr_uint8_data              :   pointer to dequeue byte into
 *
 * @return  QUEUE_OK                            :   Success
 *          QUEUE_EMPTY                         :   Queue empty
 *          QUEUE_ERROR                         :   Failed
 */
enu_queue_error_t_      cqueue_dequeue              (str_circular_queue_t_* ptr_str_circular_queue, void ** vdptr_data);

/**
 * @brief                                       :   get current count of data in queue
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  uint16                              :   Count
 */
uint16_t_               cqueue_getCount             (str_circular_queue_t_* ptr_str_circular_queue);

#endif /* CQUEUE_INTERFACE_H_ */