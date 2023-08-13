/*
 * cqueue_program.c
 *
 * Created: 25/5/2023 2:32:31 AM
*  Author: hossam Elwahsh - https://github.com/HossamElwahsh
 */ 

#include "cqueue_interface.h"


/**
 * @brief                                       :   initializes circular queue
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  QUEUE_OK                            :   Success
 *          QUEUE_ERROR                         :   Failed
*/
enu_queue_error_t_ cqueue_initializeQueue(str_circular_queue_t_* ptr_str_circular_queue) {
    enu_queue_error_t_ enu_queue_error = QUEUE_OK;

    if(NULL_PTR != ptr_str_circular_queue)
    {
        ptr_str_circular_queue->uint16_front = 0;
        ptr_str_circular_queue->uint16_rear = -1;
        ptr_str_circular_queue->uint16_count = 0;
    }else{
        enu_queue_error = QUEUE_ERROR;
    }

    return enu_queue_error;
}

/**
 * @brief                                       :   checks if queue is empty
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  QUEUE_EMPTY                         :   Queue is empty
 *          QUEUE_NOT_EMPTY                     :   Queue not empty
 *          QUEUE_ERROR                         :   Failed
 */
enu_queue_error_t_ cqueue_isQueueEmpty(const str_circular_queue_t_ * ptr_str_circular_queue) {

    enu_queue_error_t_ enu_queue_retval = QUEUE_EMPTY;

    if(NULL_PTR != ptr_str_circular_queue)
    {
        if(ptr_str_circular_queue->uint16_count == 0)
        {
            enu_queue_retval = QUEUE_EMPTY;
        }
        else
        {
            enu_queue_retval = QUEUE_NOT_EMPTY;
        }
    }else{
        enu_queue_retval = QUEUE_ERROR;
    }

    return enu_queue_retval;
}


/**
 * @brief                                       :   checks if queue is full
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  QUEUE_FULL                          :   Queue full
 *          QUEUE_NOT_FULL                      :   Queue not full
 *          QUEUE_ERROR                         :   Failed
 */
enu_queue_error_t_ cqueue_isQueueFull(const str_circular_queue_t_* ptr_str_circular_queue)
{
    enu_queue_error_t_ enu_queue_retval = QUEUE_OK;

    if(NULL_PTR != ptr_str_circular_queue)
    {
        enu_queue_retval = (ptr_str_circular_queue->uint16_count == QUEUE_SIZE) ? QUEUE_FULL : QUEUE_NOT_FULL;
    }
    else
    {
        enu_queue_retval = QUEUE_ERROR;
    }

    return enu_queue_retval;
}


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
enu_queue_error_t_ cqueue_enqueue(str_circular_queue_t_* ptr_str_circular_queue, void * data)
{
    enu_queue_error_t_ enu_queue_error = QUEUE_OK;

    if(NULL_PTR != ptr_str_circular_queue)
    {
        if(QUEUE_FULL == cqueue_isQueueFull(ptr_str_circular_queue))
        {
            enu_queue_error = QUEUE_FULL;
        }
        else
        {
            ptr_str_circular_queue->uint16_rear = (ptr_str_circular_queue->uint16_rear + 1) % QUEUE_SIZE;
            ptr_str_circular_queue->uint8_cq_buffer[ptr_str_circular_queue->uint16_rear] = data;
            ptr_str_circular_queue->uint16_count++;
        }
    }else{
        enu_queue_error = QUEUE_ERROR;
    }

    return enu_queue_error;
}


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
enu_queue_error_t_ cqueue_dequeue(str_circular_queue_t_* ptr_str_circular_queue, void ** vdptr_data) {

    enu_queue_error_t_ enu_queue_error = QUEUE_OK;

    if(NULL_PTR != ptr_str_circular_queue)
    {
        if (cqueue_isQueueEmpty(ptr_str_circular_queue) == QUEUE_EMPTY) {
            return QUEUE_EMPTY;
        }
        else
        {
            void * data = ptr_str_circular_queue->uint8_cq_buffer[ptr_str_circular_queue->uint16_front];
            ptr_str_circular_queue->uint16_front = (ptr_str_circular_queue->uint16_front + 1) % QUEUE_SIZE;
            ptr_str_circular_queue->uint16_count--;

            *vdptr_data = data;
        }
    }else{
        enu_queue_error = QUEUE_ERROR;
    }

    return enu_queue_error;
}


/**
 * @brief                                       :   get current count of data in queue
 *
 * @param[in]       ptr_str_circular_queue      :   pointer to circular queue
 *
 * @return  uint16                              :   Count
 */
uint16_t_ cqueue_getCount(str_circular_queue_t_* ptr_str_circular_queue)
{
    if(NULL_PTR != ptr_str_circular_queue)
    {
        return ptr_str_circular_queue->uint16_count;
    }
    else
    {
        return 0;
    }
}
