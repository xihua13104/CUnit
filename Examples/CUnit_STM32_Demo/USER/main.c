/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：串口1(USART1)向电脑的超级终端以1s为间隔打印当前ADC1的转换电压值         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Basic.h"
#include "ExampleTests.h"      
// 软件延时
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
	/*1.初始化注册点*/
	if (CU_initialize_registry()) {
		printf("\nInitialization of Test Registry failed.");
		return -1;
	}
	/*2.添加测试集*/
	pSuite = CU_add_suite("suite_for_test", NULL, NULL);
	if (NULL == pSuite) {
		return -1;
	}
	/*3.添加测试用例*/
	CU_add_test(pSuite, "test_case1", test_case1);
	CU_add_test(pSuite, "test_case2", test_case2);
	CU_add_test(pSuite, "test_case3", test_case3);
	/*4.设置测试模式，这里选择冗余模式，即最大程度的输出测试细节*/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	/*5.设置发生错误后的action，这里选择继续跑测试**/
	CU_set_error_action(error_action);
	/*6.开始测试*/
	test_return = CU_basic_run_tests();
	printf("\nTests completed with return value %d.\n", test_return);
	/*7.清理注册点，释放内存*/
	CU_cleanup_registry();

	return 0;
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
