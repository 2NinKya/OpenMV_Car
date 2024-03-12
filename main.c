#include <driverlib.h>
#include "sys.h"
#include "delay.h"
#include "Car.h"
#include "IR.h"
#include "Back.h"
#include "usart.h"

#define D1      GPIO_getInputPinValue(GPIO_PORT_P1,GPIO_PIN6)
#define D2      GPIO_getInputPinValue(GPIO_PORT_P6,GPIO_PIN2)
#define D3      GPIO_getInputPinValue(GPIO_PORT_P6,GPIO_PIN0)
#define D4      GPIO_getInputPinValue(GPIO_PORT_P6,GPIO_PIN1)

extern uint8_t Number;
uint8_t k=0,room=0;
int main(void)
{



    SystemClock_Init();
    Back_Init();
    Car_Init();
    UART_Init(USCI_A1_BASE,9600);
    //Number=4;
    GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
    //room=4;
    Car_SetSpeed(65);

    while(1)
    {

        IR_Room(1);
//        Back(k);
       // IR_StraightLine();

    }


}
#pragma vector=PORT2_VECTOR     // P2���ж�Դ
__interrupt
void Port_2 (void)              // ����һ���жϷ��������ΪPort_2()
{
    //uint8_t temp,backflag;
    if(GPIO_getInterruptStatus(GPIO_PORT_P2, GPIO_PIN1))
    {
       // temp=IR_StraightLine(void); //  temp���ں���IR_Room���ص�ֵ   ���ﺯ����IR_Room�Ĳ���Number������ͷ��ȡ������ģ
       // backflag=temp;        //�ٰ�temp��ֵ��������Back�����س�   ����������������ú���Back(backflag);
//       i=Number;
//       Number=0;
        k=4;
        //i=room;
        room=0;
        GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN1);
    }
}


