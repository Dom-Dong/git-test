#include "canfestival.h"

unsigned int TimeCNT=0;//ʱ�����
unsigned int NextTime=0;//��һ�δ���ʱ�����
unsigned int TIMER_MAX_COUNT=70000;//���ʱ�����
static TIMEVAL last_time_set = TIMEVAL_MAX;//��һ�ε�ʱ�����


//Set the next alarm //
void setTimer(TIMEVAL value)
{
        NextTime=(TimeCNT+value)%TIMER_MAX_COUNT;
}

//Get the elapsed time since the last occured alarm //
TIMEVAL getElapsedTime(void)
{
        int ret=0;
        ret = TimeCNT> last_time_set ? TimeCNT - last_time_set : TimeCNT + TIMER_MAX_COUNT - last_time_set;
        last_time_set = TimeCNT;
        return ret;
}

void timerForCan(void)//ÿ����˺�����Ӧ������
{
        TimeCNT++;
        if (TimeCNT>=TIMER_MAX_COUNT)
        {
                TimeCNT=0;
        }
        if (TimeCNT==NextTime)
        {
                TimeDispatch();
        }
}

unsigned char canSend(CAN_PORT notused, Message *m)
{
        return 1;
}
