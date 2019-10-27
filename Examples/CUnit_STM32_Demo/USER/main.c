/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ������1(USART1)����Եĳ����ն���1sΪ�����ӡ��ǰADC1��ת����ѹֵ         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Basic.h"
#include "ExampleTests.h"      
// �����ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

static void test_case1(void) 
{ 
	CU_ASSERT(1); 
}
static void test_case2(void) 
{ 
	CU_ASSERT_EQUAL(1, 2); 
}
static void test_case3(void) 
{ 
	CU_ASSERT_STRING_EQUAL("abc", "edf"); 
}

/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */

int main(void)
{
	CU_ErrorAction error_action = CUEA_IGNORE;
	CU_pSuite pSuite;
	int test_return = 0;
	USART1_Config();
	/*1.��ʼ��ע���*/
	if (CU_initialize_registry()) {
		printf("\nInitialization of Test Registry failed.");
		return -1;
	}
	/*2.��Ӳ��Լ�*/
	pSuite = CU_add_suite("suite_for_test", NULL, NULL);
	if (NULL == pSuite) {
		return -1;
	}
	/*3.��Ӳ�������*/
	CU_add_test(pSuite, "test_case1", test_case1);
	CU_add_test(pSuite, "test_case2", test_case2);
	CU_add_test(pSuite, "test_case3", test_case3);
	/*4.���ò���ģʽ������ѡ������ģʽ�������̶ȵ��������ϸ��*/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	/*5.���÷���������action������ѡ������ܲ���**/
	CU_set_error_action(error_action);
	/*6.��ʼ����*/
	test_return = CU_basic_run_tests();
	printf("\nTests completed with return value %d.\n", test_return);
	/*7.����ע��㣬�ͷ��ڴ�*/
	CU_cleanup_registry();

	return 0;
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
