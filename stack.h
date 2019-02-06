/*
 * stack_mine.h
 *
 *  Created on: Jul 3, 2018
 *      Author: Aboelsaoud ^_^
 */

#ifndef STACK_MINE_H_
#define STACK_MINE_H_

#include "commen.h"

typedef enum{

	NO_ERROE,
	STACK_FULL,
	STACK_EMPTY,
	INVLAID_ARG,
	INTERNAL_MEMORY_ERROR,


}stk_error_t;

typedef struct {
  /* user define */
 stk_u8 data1;

}data_entry;



typedef struct {
      void * stk_ptr;
	stk_u8 * stk_ptr_current;
	stk_u8 * stk_ptr_count;
}stack;


bool_t inial_stack (stack *ps , stk_u8 max_num_node);
stk_error_t push( stack *ps , data_entry *pe);
stk_error_t pop( stack *ps , data_entry *pe);




#endif /* STACK_MINE_H_ */
