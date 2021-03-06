#include "basicClientUserAgent.hxx"
#include "taskSchedual.h"
#include "myfifo.h"
#include "messageDefine.h"

void* CTaskSchedual::real_paly_thread_proc(void*)
{
	while(true)
	{
		PLAY_MESSAGE_T message = CMyFifo<PLAY_MESSAGE_T>::get_instance()->pop();
		if (strlen(message.user_id) > 0)
		{
			printf("TaskSchedual receive start real play command from fifo\n");
			printf("message.device_id = %s\n", message.device_id);
			printf("message.realm = %s\n", message.realm);
			printf("message.receive_ip = %s\n", message.receive_ip);
			printf("message.receive_port = %d\n", message.receive_port);
			printf("message.user_id = %s\n", message.user_id);
			
			if(real_time_paly == message.play_action)
			{
					resip::BasicClientUserAgent::getInstance()->doInvite(message.user_id, message.device_id, message.realm,
								message.receive_ip, message.receive_port);
					printf("TaskSchedual use sipua send invite sip message\n");
			}
			else if(real_time_stop == message.play_action)
			{
					resip::BasicClientUserAgent::getInstance()->doBye(message.user_id);
					printf("TaskSchedual use sipua send bye sip message\n");
			}
		}
		sleep(1);
	}
}
void* CTaskSchedual::review_thread_proc(void*)
{

}
void* CTaskSchedual::ptz_control_thread_proc(void*)
{

}
void* CTaskSchedual::deal_directory_info_thread_proc(void*)
{

}

int CTaskSchedual::start()
{
    pthread_attr_t attr; //线程属性结构体，创建线程时加入的参数
    pthread_attr_init(&attr); //初始化

    //create real_paly_thread
    int ret = pthread_create(&m_real_paly_thread_id, &attr, real_paly_thread_proc, NULL);
    if (ret < 0)
    {
        //create real_paly_thread_proc failure
    }

    //create review_thread
    ret = pthread_create(&m_review_thread_id, &attr, review_thread_proc, NULL);
    if (ret < 0)
    {
        //create review_thread_proc failure
    }

    //create ptz_control_thread
    ret = pthread_create(&m_ptz_control_thread_id, &attr, ptz_control_thread_proc, NULL);
    if (ret < 0)
    {
        //create review_thread_proc failure
    }

    //create deal_directory_info_thread
    ret = pthread_create(&m_deal_directory_info_thread_id, &attr, deal_directory_info_thread_proc, NULL);
    if (ret < 0)
    {
        //create review_thread_proc failure
    }
}
