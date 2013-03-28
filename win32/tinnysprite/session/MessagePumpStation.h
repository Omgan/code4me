/*--------------------------------------------------------------------------------*\

     �ļ���  MessagePumpStation.h
     ���ߣ�  Ҧ����
     ���ڣ�  2010��10��20��
     ˵����  ��Ϣ��

     �û���¼��������Ϣ�ã����û��յ�����Ϣ���û��Ĺ�ע���󷢲�����������Ϣ����Ϣ�ý�
     ��Ϣ��ȡ���ͻ��ˣ�Ȼ��֪ͨ�û���

\*--------------------------------------------------------------------------------*/

#ifndef MESSAGE_PUMP_STATION_H
#define MESSAGE_PUMP_STATION_H

#define __SD_CLIENT_DLL_INTERNAL_USE__
#include <ISessionDomainClient.h>

#include <string>

#include "SSDataDomain.api.h"

class MessagePumpStation {
public:
    virtual void start() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;

    virtual void set_userid(std::string userid) = 0;
    virtual void set_call_back(OnSessionDomainCallBack pCallback) = 0;
    virtual void set_data_svc(SSDataDomainClient::SSDataDomainSvc* pDataSvc) = 0;

    virtual void notify_following_changed() = 0; // ֪ͨ��Ϣ�ã��û��Ĺ�ע�б��и��¡�
    //void add_following(std::string following);
    //void remove_following(std::string following);
};

extern MessagePumpStation* g_message_pump_station;

#endif //MESSAGE_PUMP_STATION_H