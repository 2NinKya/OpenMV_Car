/*
 * Car.c
 *
 *  Created on: 2022��7��15��
 *      Author: TANG
 */

#include "driverlib.h"
#include "PWM.h"

void Car_Init(void)
{
    PWMA_Init();
    /*P4.1��PP3.5����һ������*/
    GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN1);
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P3,GPIO_PIN5);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN5);
    /*P4.2��P3.6����һ������*/
    GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN2);
    GPIO_setAsOutputPin(GPIO_PORT_P3,GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN6);
    /*P2.7��P7.0����һ������*/
    GPIO_setAsOutputPin(GPIO_PORT_P2,GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2,GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P7,GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P7,GPIO_PIN0);
    /*P3.2��P6.4����һ������*/
    GPIO_setAsOutputPin(GPIO_PORT_P3,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN2);
    GPIO_setAsOutputPin(GPIO_PORT_P6,GPIO_PIN4);
    GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN4);
    /*ȫ��߱�ʾһ�ϵ�ֹͣ*/
}

void Car_SetSpeed(int8_t Speed)
{
    Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_1,55+Speed);
    Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_2,55-Speed);
    Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_3,55-Speed);
    Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_4,55+Speed);
}

void run(void)
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN1);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN5);
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2,GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7,GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6,GPIO_PIN4);
}

void stop(void)
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN1);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN5);
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2,GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P7,GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN4);
}
void houtui(void)
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P4,GPIO_PIN1);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN5);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2,GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P7,GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN4);


}
void left(void)
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P4,GPIO_PIN1);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN5);
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN6);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2,GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P7,GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6,GPIO_PIN4);
}

void right(void)
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P4,GPIO_PIN1);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN5);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2,GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7,GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN4);
}

