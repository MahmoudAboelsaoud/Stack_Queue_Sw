/*
 * stack_mine.c
 *
 *  Created on: Jul 3, 2018
 *      Author: Aboelsaoud ^_^
 */

#include "stack_mine.h"
#include<stdlib.h>

typedef struct stacknode{

	data_entry entry;
	struct stacknode *next;

}StackNode;



bool_t ecore_memcpy(char*src , char*des,stk_u8 size)
{

   bool_t ret_val = E_TRUE;
   if(src!=NULL && des!=NULL && size>0)
   {
	   while(size--)
	   {
		   *des=*src;
		   des++;
		   src++;

	   }
   }
   else
   	   {
   		   ret_val = E_FALSE;
   	   }


   return ret_val;
}

bool_t inial_stack (stack *ps , stk_u8  max_num_node)
{
	bool_t ret_val= E_TRUE;

	if(ps->stk_ptr != NULL && max_num_node > 0)
	{
		        ps->stk_ptr=NULL;
				ps->stk_ptr_current=0;
			  *(ps->stk_ptr_count)= max_num_node;

	}

	else
	{

		ret_val= E_FALSE;


	}

  return ret_val;
}


stk_error_t push( stack *ps , data_entry *pe)
{
	stk_error_t ret_val = NO_ERROE;


	if( (ps->stk_ptr != NULL) && (pe != NULL))
	{
		if(ps->stk_ptr_count > ps->stk_ptr_current )
		{
			StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
			bool_t  ecore_memcpy_test=ecore_memcpy((char*)pe , (char*)&pn->entry , sizeof(data_entry));

			if(ecore_memcpy_test == E_TRUE)
			   {
		        	pn->next=(StackNode*)ps->stk_ptr;                                                //(void*)pn->next = ps->stk_ptr;
		            ps->stk_ptr=(void*)pn;                                                        	//(StackNode)ps->stk_ptr = pn;
			        ps->stk_ptr_current++;
			   }
		    else
		    {
				ret_val =INTERNAL_MEMORY_ERROR;
			    }                                                                                  //pn->entry=pe->data1;
		}
		else
		{

			ret_val = STACK_FULL;

		}



	}

	else
	{

		ret_val = INVLAID_ARG;
	}



  return ret_val;
}





stk_error_t pop( stack *ps , data_entry *pe)
{
	stk_error_t ret_val = NO_ERROE;


	if( (ps->stk_ptr != NULL) && (pe != NULL))
	{
		if(ps->stk_ptr_current >0)
		{

			bool_t  ecore_memcpy_test=ecore_memcpy( (char*)&((StackNode*)ps->stk_ptr)->entry , (char*)pe , sizeof(data_entry));
			if( ecore_memcpy_test ==E_TRUE)
			{

				StackNode * pn = (StackNode*)ps->stk_ptr;
				ps->stk_ptr=(void*)pn->next;
				ps->stk_ptr_current--;
				free(pn);

			}
			else
			{

				ret_val =INTERNAL_MEMORY_ERROR;
			}



		}
		else
		{
			ret_val=STACK_EMPTY;
		}


	}
	else
	{

		ret_val = INVLAID_ARG;
	}



  return ret_val;
}
