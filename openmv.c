#include "openmv.h"
#include "usart.h"
int openmv[5];//stm32接收数据数组
int8_t OpenMV_X;          /*OPENMV X 轴反馈坐标*/
int8_t OpenMV_Y;          /*OPENMV X 轴反馈坐标*/


int i=0;

void Openmv_Receive_Data(uint16_t data)//接收Openmv传过来的数据
{
    static uint8_t state = 0;
    if(state==0&&data==0xB3)
    {
        state=1;
        openmv[0]=data;
    }
    else if(state==1&&data==0xB3)
    {
        state=2;
        openmv[1]=data;
    }
    else if(state==2)
    {
        state=3;
        openmv[2]=data;
    }
    else if(state==3)
    {
        state = 4;
        openmv[3]=data;
    }

    else if(state==4)       //检测是否接受到结束标志
    {
        if(data == 0x5B)
        {
            state = 0;
            openmv[4]=data;
            Openmv_Data();
        }
        else if(data != 0x5B)
        {
            state = 0;
            for(i=0;i<5;i++)
            {
                openmv[i]=0x00;
            }
        }
    }
    else
        {
            state = 0;
            for(i=0;i<5;i++)
            {
                openmv[i]=0x00;
            }
        }
}

void Openmv_Data(void)
{
    OpenMV_X=openmv[2];
    OpenMV_Y=openmv[3];
}


