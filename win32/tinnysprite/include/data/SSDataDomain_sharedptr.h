#ifndef __SSDATADOMAIN_H__
#define __SSDATADOMAIN_H__

#include <google/protobuf/service.h>
#include "gen-h/ssdatadomain.pb.h"

using namespace google::protobuf;
namespace SSDataDomain
{

class SSDataDomainSvcSync
{
	/**
	 * �ʺŽӿ�
	 */
public:
	// �����ʺ�
	virtual shared_ptr<CreateAccountResponse> CreateAccount(RpcController* controller, CreateAccountRequest* request) = 0;
	// ��ȡ�ʺ���Ϣ
	virtual shared_ptr<GetAccountResponse> GetAccount(RpcController* controller, GetAccountRequest* request) =  0;
	// �޸�����
	virtual shared_ptr<ChangePasswordResponse> ChangePassword(RpcController* controller, ChangePasswordRequest* request) = 0;

	/**
	 * �������ýӿ�
	 */
public:
	// �־û���������
	virtual shared_ptr<SetProfileResponse> SetProfile(RpcController* controller, SetProfileRequest* request) = 0;
	// ��ȡ��������
	virtual shared_ptr<GetProfileResponse> GetProfile(RpcController* controller, GetProfileRequest* request) = 0;

	/**
	 * ��ϵ�ӿ�
	 */
public:
	// ��ע
	virtual shared_ptr<FollowResponse> Follow(RpcController* controller, FollowRequest* request) = 0;
	// ȡ����ע
	virtual shared_ptr<CancelFollowResponse> CancelFollow(RpcController* controller, CancelFollowRequest* request) = 0;
	// ��ȡ��ע��
	virtual shared_ptr<GetFollowingResponse> GetFollowing(RpcController* controller, GetFollowingRequest* request) = 0;
	// ��ȡ����
	virtual shared_ptr<GetFriendResponse> GetFriend(RpcController* controller, GetFriendRequest* request) = 0;
	// ��ȡ����������
	virtual shared_ptr<GetFollowerCountResponse> GetFollowerCount(RpcController* controller, GetFollowerCountRequest* request) = 0;
	// ���������¼
	virtual shared_ptr<InviteResponse> Invite(RpcController* controller, InviteRequest* request) = 0;
	// ��ѯ�����¼
	virtual shared_ptr<GetInvitingResponse> GetInviting(RpcController* controller, GetInvitingRequest* request) = 0;
	// ��ѯ�������¼
	virtual shared_ptr<GetInviterResponse> GetInviter(RpcController* controller, GetInviterRequest* request) = 0;

	/**
	 * �Ự�־ýӿ�
	 */
public:
	// �־ûỰ��Ϣ
	virtual shared_ptr<SetSessionInfoResponse> SetSessionInfo(RpcController* controller, SetSessionInfoRequest* request) = 0;
	// ��ȡ�Ự��Ϣ
	virtual shared_ptr<GetSessionInfoResponse> GetSessionInfo(RpcController* controller, GetSessionInfoRequest* request) = 0;

	/**
	 * ��Ϣ�ӿ�
	 */
public:
	//�����Ϣ
	virtual shared_ptr<AddMessageResponse> AddMessage(RpcController* controller, AddMessageRequest* request) = 0;
	//ɾ����Ϣ
	virtual shared_ptr<RemoveMessageResponse> RemoveMessage(RpcController* controller, RemoveMessageRequest* request) = 0;
	//��ȡ��Ϣ
	virtual shared_ptr<GetMessageResponse> GetMessage(RpcController* controller, GetMessageRequest* request) = 0;
	// ������������Ϣ����Ϊ�����͵Ĺ���������Ϣ��
	virtual shared_ptr<SendPublicMessageResponse> SendPublicMessage(RpcController* controller, SendPublicMessageRequest* request) = 0;
	// ָ����������Ϣ����Ϊ�����͵�ָ��������Ϣ���ͽ����ߵġ����յ�ָ��������Ϣ��
	virtual shared_ptr<SendProtectedMessageResponse> SendProtectedMessage(RpcController* controller, SendProtectedMessageRequest* request) = 0;
	// �ղأ�����Ϣ����Ϊ���ղص���Ϣ��
	virtual shared_ptr<SendPrivateMessageResponse> SendPrivateMessage(RpcController* controller, SendPrivateMessageRequest* request) = 0;

	/**
	 * ��ϵ�˽ӿ�
	 */
public:
	// ��ӻ��޸���ϵ��
	virtual shared_ptr<AddContactResponse> AddContact(RpcController* controller, AddContactRequest* request) = 0;
	// ɾ����ϵ��
	virtual shared_ptr<RemoveContactResponse> RemoveContact(RpcController* controller, RemoveContactRequest* request) = 0;
	// ��ȡ������ϵ��
	virtual shared_ptr<GetContactResponse> GetContact(RpcController* controller, GetContactRequest* request) = 0;
	// �������Ա
	virtual shared_ptr<AddGroupResponse> AddGroup(RpcController* controller, AddGroupRequest* request) = 0;
	// ɾ������Ա
	virtual shared_ptr<RemoveGroupResponse> RemoveGroup(RpcController* controller, RemoveGroupRequest* request) = 0;
	// ��������
	virtual shared_ptr<RenameGroupResponse> RenameGroup(RpcController* controller, RenameGroupRequest* request) = 0;
	// ��ȡ��
	virtual shared_ptr<GetGroupResponse> GetGroup(RpcController* controller, GetGroupRequest* request) = 0;

	/**
	 * �����ӿ�
	 */
public:
	//��key���ڣ��򷵻ظ�key��Ӧ��value��������isUpdate���и���
	//��key�����ڣ��򷵻��µ�value����һ������
	virtual shared_ptr<QueryAndUpdateResponse> QueryAndUpdate(RpcController* controller, QueryAndUpdateRequest* request) = 0;

	//��key���ڣ��򷵻ظ�key��Ӧ��value����ɾ����������
	//��key�����ڣ��򷵻�null
	virtual shared_ptr<QueryAndDeleteResponse> QueryAndDelete(RpcController* controller, QueryAndDeleteRequest* request) = 0;
};

}

#endif