#include "canfestival.h"

unsigned int TimeCNT=0;//时间计数
unsigned int NextTime=0;//下一次触发时间计数
unsigned int TIMER_MAX_COUNT=70000;//最大时间计数
static TIMEVAL last_time_set = TIMEVAL_MAX;//上一次的时间计数


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

void timerForCan(void)//每毫秒此函数都应被调用
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
