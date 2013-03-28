#ifndef __SSDATADOMAIN_H__
#define __SSDATADOMAIN_H__

#include <google/protobuf/service.h>
#include "ssdatadomain.pb.h"

namespace SSDataDomain
{

class SSDataDomainSvcSync
{
	/**
	 * �ʺŽӿ�
	 */
public:
	// �����ʺ�
	virtual CreateAccountResponse* CreateAccount(google::protobuf::RpcController* controller, CreateAccountRequest* request) = 0;
	// ��ȡ�ʺ���Ϣ
	virtual GetAccountResponse* GetAccount(google::protobuf::RpcController* controller, GetAccountRequest* request) =  0;
	// �޸�����
	virtual ChangePasswordResponse* ChangePassword(google::protobuf::RpcController* controller, ChangePasswordRequest* request) = 0;

	/**
	 * �������ýӿ�
	 */
public:
	// �־û���������
	virtual SetProfileResponse* SetProfile(google::protobuf::RpcController* controller, SetProfileRequest* request) = 0;
	// ��ȡ��������
	virtual GetProfileResponse* GetProfile(google::protobuf::RpcController* controller, GetProfileRequest* request) = 0;

	/**
	 * ��ϵ�ӿ�
	 */
public:
	// ��ע
	virtual FollowResponse* Follow(google::protobuf::RpcController* controller, FollowRequest* request) = 0;
	// ȡ����ע
	virtual CancelFollowResponse* CancelFollow(google::protobuf::RpcController* controller, CancelFollowRequest* request) = 0;
	// ��ȡ��ע��
	virtual GetFollowingResponse* GetFollowing(google::protobuf::RpcController* controller, GetFollowingRequest* request) = 0;
	// ��ȡ����
	//virtual GetFriendResponse* GetFriend(google::protobuf::RpcController* controller, GetFriendRequest* request) = 0;
	// ��ȡ����������
	virtual GetFollowerCountResponse* GetFollowerCount(google::protobuf::RpcController* controller, GetFollowerCountRequest* request) = 0;
	// ��ȡ������
	virtual GetFollowerResponse* GetFollower(google::protobuf::RpcController* controller, GetFollowerRequest* request) = 0;
	// ���������¼
	virtual InviteResponse* Invite(google::protobuf::RpcController* controller, InviteRequest* request) = 0;
	// ��ѯ�����¼
	virtual GetInvitingResponse* GetInviting(google::protobuf::RpcController* controller, GetInvitingRequest* request) = 0;
	// ��ѯ�������¼
	virtual GetInviterResponse* GetInviter(google::protobuf::RpcController* controller, GetInviterRequest* request) = 0;

	/**
	 * �Ự�־ýӿ�
	 */
public:
	// �־ûỰ��Ϣ
	virtual SetSessionInfoResponse* SetSessionInfo(google::protobuf::RpcController* controller, SetSessionInfoRequest* request) = 0;
	// ��ȡ�Ự��Ϣ
	virtual GetSessionInfoResponse* GetSessionInfo(google::protobuf::RpcController* controller, GetSessionInfoRequest* request) = 0;

	/**
	 * ��Ϣ�ӿ�
	 */
public:
	//�����Ϣ
	//virtual AddMessageResponse* AddMessage(google::protobuf::RpcController* controller, AddMessageRequest* request) = 0;
	//ɾ����Ϣ
	//virtual RemoveMessageResponse* RemoveMessage(google::protobuf::RpcController* controller, RemoveMessageRequest* request) = 0;
	//��ȡ��Ϣ
	virtual GetMessageResponse* GetMessage(google::protobuf::RpcController* controller, GetMessageRequest* request) = 0;
	// ͨ��ʱ�����Ż�ȡ��Ϣ
	virtual GetMessageByTimestampResponse* GetMessageByTimestamp(google::protobuf::RpcController* controller, GetMessageByTimestampRequest* request) = 0;
	// ������������Ϣ���浽PUBBOX
	virtual SendPublicMessageResponse* SendPublicMessage(google::protobuf::RpcController* controller, SendPublicMessageRequest* request) = 0;
	// ָ����������Ϣ���浽�����ߵ�OUTBOX�ͽ����ߵ�INBOX
	virtual SendMessageResponse* SendMessage(google::protobuf::RpcController* controller, SendMessageRequest* request) = 0;
	// �ղأ�����Ϣ���浽FAVBOX
	virtual AddFavoriteMessageResponse* AddFavoriteMessage(google::protobuf::RpcController* controller, AddFavoriteMessageRequest* request) = 0;

	/**
	 * ��ϵ�˽ӿ�
	 */
public:
	// ��ӻ��޸���ϵ��
	virtual AddContactResponse* AddContact(google::protobuf::RpcController* controller, AddContactRequest* request) = 0;
	// ɾ����ϵ�ˣ�Ӧ���Ȱ���ϵ���Ƴ����е����ٵ��ô˷���
	virtual RemoveContactResponse* RemoveContact(google::protobuf::RpcController* controller, RemoveContactRequest* request) = 0;
	// ��ȡ������ϵ��
	virtual GetContactResponse* GetContact(google::protobuf::RpcController* controller, GetContactRequest* request) = 0;
	// ��ӻ��޸���
	virtual AddGroupResponse* AddGroup(google::protobuf::RpcController* controller, AddGroupRequest* request) = 0;
	// ɾ���飬Ӧ���Ȱ���������г�Ա�Ƴ��ٵ��ô˷���
	virtual RemoveGroupResponse* RemoveGroup(google::protobuf::RpcController* controller, RemoveGroupRequest* request) = 0;
	// ��ȡ��
	virtual GetGroupResponse* GetGroup(google::protobuf::RpcController* controller, GetGroupRequest* request) = 0;
	// ������Ա
	virtual AddMemberResponse* AddMember(google::protobuf::RpcController* controller, AddMemberRequest* request) = 0;
	// ɾ�����Ա
	virtual RemoveMemberResponse* RemoveMember(google::protobuf::RpcController* controller, RemoveMemberRequest* request) = 0;
	// ��ȡ���Ա
	virtual GetMemberResponse* GetMember(google::protobuf::RpcController* controller, GetMemberRequest* request) = 0;

	/**
	 * �����ӿ�
	 */
public:
	//��key���ڣ��򷵻ظ�key��Ӧ��value��������isUpdate���и���
	//��key�����ڣ��򷵻��µ�value����һ������
	virtual QueryAndUpdateResponse* QueryAndUpdate(google::protobuf::RpcController* controller, QueryAndUpdateRequest* request) = 0;

	//��key���ڣ��򷵻ظ�key��Ӧ��value����ɾ����������
	//��key�����ڣ��򷵻�null
	virtual QueryAndDeleteResponse* QueryAndDelete(google::protobuf::RpcController* controller, QueryAndDeleteRequest* request) = 0;

	// ����߼��ڵ㶩����Ϣ
	virtual AddLogicNodeSubscribeInfoResponse* AddLogicNodeSubscribeInfo(google::protobuf::RpcController* controller, AddLogicNodeSubscribeInfoRequest* request) = 0;
	// ɾ���߼��ڵ㶩����Ϣ
	virtual RemoveLogicNodeSubscribeInfoResponse* RemoveLogicNodeSubscribeInfo(google::protobuf::RpcController* controller, RemoveLogicNodeSubscribeInfoRequest* request) = 0;
	// ��ȡ�߼��ڵ㶩����Ϣ
	virtual GetLogicNodeSubscribeInfoResponse* GetLogicNodeSubscribeInfo(google::protobuf::RpcController* controller, GetLogicNodeSubscribeInfoRequest* request) = 0;

	/**
	 * ���ϻ��ֽӿ�
	 */
public:
	virtual GetFollowingWithProfileResponse* GetFollowingWithProfile(google::protobuf::RpcController* controller, GetFollowingWithProfileRequest* request) = 0;
	virtual GetFollowerWithProfileResponse* GetFollowerWithProfile(google::protobuf::RpcController* controller, GetFollowerWithProfileRequest* request) = 0;
	virtual GetContactExResponse* GetContactEx(google::protobuf::RpcController* controller, GetContactExRequest* request) = 0;
};

}

#endif