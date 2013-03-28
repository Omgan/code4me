#ifndef __SSDATADOMAINSVCSYNCSTUB_H__
#define __SSDATADOMAINSVCSYNCSTUB_H__

#include "SSDataDomain.h"
//#include "SSObjectPool.h"

namespace SSDataDomain {

class SSDataDomainSvcSyncStub : public SSDataDomainSvcSync
{
private:
	SSDataDomainSvc::Stub stub;
	int timeout;

	//static HANDLE event_create_func();
	//static void event_destroy_func(HANDLE evt);
	//SSObjectPool<HANDLE> event_pool;

public:
	SSDataDomainSvcSyncStub(google::protobuf::RpcChannel* channel);
	~SSDataDomainSvcSyncStub();
	void SetTimeout(int ms) { this->timeout = ms; }
	int GetTimeout() { return this->timeout; }

private:
	static void CallCompletion(HANDLE evt);

	template<typename TRequest, typename TResponse>
	TResponse* CallMethod(
		void (SSDataDomainSvc::Stub::*method)(google::protobuf::RpcController*, const TRequest*, TResponse*, google::protobuf::Closure*),
		google::protobuf::RpcController* controller,
		TRequest* request);

	/**
	 * �ʺŽӿ�
	 */
public:
	// �����ʺ�
	CreateAccountResponse* CreateAccount(google::protobuf::RpcController* controller, CreateAccountRequest* request);
	// ��ȡ�ʺ���Ϣ
	GetAccountResponse* GetAccount(google::protobuf::RpcController* controller, GetAccountRequest* request);
	// �޸�����
	ChangePasswordResponse* ChangePassword(google::protobuf::RpcController* controller, ChangePasswordRequest* request);

	/**
	 * �������ýӿ�
	 */
public:
	// �־û���������
	SetProfileResponse* SetProfile(google::protobuf::RpcController* controller, SetProfileRequest* request);
	// ��ȡ��������
	GetProfileResponse* GetProfile(google::protobuf::RpcController* controller, GetProfileRequest* request);

	/**
	 * ��ϵ�ӿ�
	 */
public:
	// ��ע
	FollowResponse* Follow(google::protobuf::RpcController* controller, FollowRequest* request);
	// ȡ����ע
	CancelFollowResponse* CancelFollow(google::protobuf::RpcController* controller, CancelFollowRequest* request);
	// ��ȡ��ע��
	GetFollowingResponse* GetFollowing(google::protobuf::RpcController* controller, GetFollowingRequest* request);
	// ��ȡ����
	//GetFriendResponse* GetFriend(google::protobuf::RpcController* controller, GetFriendRequest* request);
	// ��ȡ����������
	GetFollowerCountResponse* GetFollowerCount(google::protobuf::RpcController* controller, GetFollowerCountRequest* request);
	// ��ȡ������
	GetFollowerResponse* GetFollower(google::protobuf::RpcController* controller, GetFollowerRequest* request);
	// ���������¼
	InviteResponse* Invite(google::protobuf::RpcController* controller, InviteRequest* request);
	// ��ѯ�����¼
	GetInvitingResponse* GetInviting(google::protobuf::RpcController* controller, GetInvitingRequest* request);
	// ��ѯ�������¼
	GetInviterResponse* GetInviter(google::protobuf::RpcController* controller, GetInviterRequest* request);

	/**
	 * �Ự�־ýӿ�
	 */
public:
	// �־ûỰ��Ϣ
	SetSessionInfoResponse* SetSessionInfo(google::protobuf::RpcController* controller, SetSessionInfoRequest* request);
	// ��ȡ�Ự��Ϣ
	GetSessionInfoResponse* GetSessionInfo(google::protobuf::RpcController* controller, GetSessionInfoRequest* request);

	/**
	 * ��Ϣ�ӿ�
	 */
public:
	//�����Ϣ
	//AddMessageResponse* AddMessage(google::protobuf::RpcController* controller, AddMessageRequest* request);
	//ɾ����Ϣ
	//RemoveMessageResponse* RemoveMessage(google::protobuf::RpcController* controller, RemoveMessageRequest* request);
	//��ȡ��Ϣ
	GetMessageResponse* GetMessage(google::protobuf::RpcController* controller, GetMessageRequest* request);
	// ͨ��ʱ�����Ż�ȡ��Ϣ
	GetMessageByTimestampResponse* GetMessageByTimestamp(google::protobuf::RpcController* controller, GetMessageByTimestampRequest* request);
	// ������������Ϣ���浽PUBBOX
	SendPublicMessageResponse* SendPublicMessage(google::protobuf::RpcController* controller, SendPublicMessageRequest* request);
	// ָ����������Ϣ���浽�����ߵ�OUTBOX�ͽ����ߵ�INBOX
	SendMessageResponse* SendMessage(google::protobuf::RpcController* controller, SendMessageRequest* request);
	// �ղأ�����Ϣ���浽FAVBOX
	AddFavoriteMessageResponse* AddFavoriteMessage(google::protobuf::RpcController* controller, AddFavoriteMessageRequest* request);

	/**
	 * ��ϵ�˽ӿ�
	 */
public:
	// ��ӻ��޸���ϵ��
	AddContactResponse* AddContact(google::protobuf::RpcController* controller, AddContactRequest* request);
	// ɾ����ϵ��
	RemoveContactResponse* RemoveContact(google::protobuf::RpcController* controller, RemoveContactRequest* request);
	// ��ȡ������ϵ��
	GetContactResponse* GetContact(google::protobuf::RpcController* controller, GetContactRequest* request);
	// �������Ա
	AddGroupResponse* AddGroup(google::protobuf::RpcController* controller, AddGroupRequest* request);
	// ɾ������Ա
	RemoveGroupResponse* RemoveGroup(google::protobuf::RpcController* controller, RemoveGroupRequest* request);
	// ��ȡ��
	GetGroupResponse* GetGroup(google::protobuf::RpcController* controller, GetGroupRequest* request);
	// ������Ա
	AddMemberResponse* AddMember(google::protobuf::RpcController* controller, AddMemberRequest* request);
	// ɾ�����Ա
	RemoveMemberResponse* RemoveMember(google::protobuf::RpcController* controller, RemoveMemberRequest* request);
	// ��ȡ���Ա
	GetMemberResponse* GetMember(google::protobuf::RpcController* controller, GetMemberRequest* request);

	/**
	 * �����ӿ�
	 */
public:
	//��key���ڣ��򷵻ظ�key��Ӧ��value��������isUpdate���и���
	//��key�����ڣ��򷵻��µ�value����һ������
	QueryAndUpdateResponse* QueryAndUpdate(google::protobuf::RpcController* controller, QueryAndUpdateRequest* request);

	//��key���ڣ��򷵻ظ�key��Ӧ��value����ɾ����������
	//��key�����ڣ��򷵻�null
	QueryAndDeleteResponse* QueryAndDelete(google::protobuf::RpcController* controller, QueryAndDeleteRequest* request);

	// ����߼��ڵ㶩����Ϣ
	AddLogicNodeSubscribeInfoResponse* AddLogicNodeSubscribeInfo(google::protobuf::RpcController* controller, AddLogicNodeSubscribeInfoRequest* request);
	// ɾ���߼��ڵ㶩����Ϣ
	RemoveLogicNodeSubscribeInfoResponse* RemoveLogicNodeSubscribeInfo(google::protobuf::RpcController* controller, RemoveLogicNodeSubscribeInfoRequest* request);
	// ��ȡ�߼��ڵ㶩����Ϣ
	GetLogicNodeSubscribeInfoResponse* GetLogicNodeSubscribeInfo(google::protobuf::RpcController* controller, GetLogicNodeSubscribeInfoRequest* request);

	/**
	 * ���ϻ��ֽӿ�
	 */
public:
	GetFollowingWithProfileResponse* GetFollowingWithProfile(google::protobuf::RpcController* controller, GetFollowingWithProfileRequest* request);
	GetFollowerWithProfileResponse* GetFollowerWithProfile(google::protobuf::RpcController* controller, GetFollowerWithProfileRequest* request);
	GetContactExResponse* GetContactEx(google::protobuf::RpcController* controller, GetContactExRequest* request);
};

} // namespace

#endif