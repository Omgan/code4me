#ifndef _ISESSIONDOMAINCLIENT_H_
#define _ISESSIONDOMAINCLIENT_H_

#pragma once

#include <string.h>

#define __SD_CLIENT_DLL_LIB_NAME__ "BusinessStub"

#ifdef __SD_CLIENT_DLL_INTERNAL_USE__

#define SD_CLIENT_DLL_API __declspec(dllexport)
#define SD_CLIENT_DLL_CLASS __declspec(dllexport)

#else

#define SD_CLIENT_DLL_API __declspec(dllimport)
#define SD_CLIENT_DLL_CLASS __declspec(dllimport)

#ifndef SD_CLIENT_DLL_NO_LIB
#pragma comment(lib, __SD_CLIENT_DLL_LIB_NAME__".lib")
#pragma message( "�Զ����� "__SD_CLIENT_DLL_LIB_NAME__".lib")
#endif

#endif

#pragma pack(push)
#pragma pack(1)

#define SD_CLIENT_NAMESPACE_BEGIN namespace GOUMANG{ namespace ShareSpirit { namespace SessionDomain{
#define SD_CLIENT_NAMESPACE_END };};};


//SD_CLIENT_NAMESPACE_BEGIN;
enum CallBackCMDID
{
	ID_RegistResp		= 1,	//ע��ɹ��ص�
	ID_LoginResp		= 2,	//��¼�ɹ�

	ID_ProfileResp,			//�û�profile��Ϣ�ص�
	ID_ContactsResp,			//�û���ϵ�˻ص�
	ID_GroupResp,               //�û�����Ϣ�ص�
	ID_GroupMembersResp,

	ID_IconResp,
	
	ID_SetContactResp,
	ID_AddContactsResp,
	ID_RemoveContactsResp,

	ID_SetGroupResp,
	ID_AddGroupResp,
	ID_RemoveGroupResp,

	ID_AddMembersResp,
	ID_RemoveMembersResp,

	ID_FollowCountResp,        //��ȡ�����˹�ע�Լ��Ļص�
	ID_FollowListResp,

	ID_FollowingCountResp,		//��ȡ�ҹ�ע������
	ID_FollowingListResp,		//��ȡ�ҹ�ע���б�

	ID_OtherFollowCountResp,
	ID_OtherFollowListResp,

	ID_OtherFollowingCountResp,
	ID_OtherFollowingListResp,

	ID_InviteResp,
	ID_InviterListMsg,

	ID_GetLastTimeResp,
	ID_SetLastTimeResp,
	ID_OtherUserProfileResp,    //�����û���profile��Ϣ�ص�
	ID_LastPubShareSeqNumMsg,		//�ص��ϴι��������������
	ID_GetPublicShareOutBoxResp,		//�ص������û������������Ϣ
    ID_GetProtectShareOutBoxResp,
	ID_GetPrivateBoxResp,
	ID_GetInBoxResp,
	ID_GetOtherPublicShareResp,
	ID_OnShareMsg,                            //�����û������������Ϣ
    ID_ForgetPwdResp,
	ID_VerifyActiveCodeResp,
	ID_ChangePwdResp,
    ID_UserExistResp,
	ID_FollowUserResp,
    ID_UnFollowUserResp,
	ID_ShareMsgResp,
	ID_OnLogOutMsg,
	ID_InitResult,
	ID_ResetPWD,
	ID_NULL,
};

enum SSResultCode
{
	Result_Success						= 0,
	Result_ParameterWrong				= 30000,	//�������󣬱��紫����һ��NULLָ�룬�������һ�����������ص�
	Result_FunctionNoImplement,			//�ù���û��ʵ��	
	Result_InternalFail,				//�����ڲ������ڲ�bug���µ�

	Result_SendFail,					//��������
	Result_SendTimeOut,					//�������ݳ�ʱ
	Result_ReceiveFail,					//�������ݴ���
	Result_ReceiveTimeOut,				//�������ݳ�ʱ
	Result_ConnectFail,					//����ʧ��

	Result_InitFail,					//��ʼ������
	Result_UserIsRegisted,				//���û��Ѿ�ע��
	Result_UserNotExist,				//�û�������
	Result_PasswordError,				//�������
	Result_SendEmailError,				//����Email����
	Result_VerifyActiveCode,			//У�������
	Result_VerifyActiveCodeTimeOut,		//У���벻����
	Result_HaveFollowed,				//�Ѿ�������
	Result_HaveNotFollowed,				//��δ����
    Result_UserNotLogin,                //δ��¼

	//Result_ResetPasswordError,			//�����������
	//Result_ChangePasswordError,			//�޸��������
	//Result_HasInit					    = 30000,
	//Result_InitCallBackFunIsNuLL		,
	//Result_HasNotInit					,
	//Result_RegisterNickOrEmailIsNULL	,
	//Result_RegisterActiveCodeIsNULL		,
	//Result_ResetPWVerifyCodeIsNULL		,
	//Result_NetError,//�����쳣
	//Result_GetMsgEndSeqNumIsError		,
	//Result_GetMsgCountIsError			,
	//Result_EmailError,//����Email����
	//Result_RegistCheckCode,	//У�������
	//Result_ConnectServerFail,
	//Regist_OK				= 40000,	//ע��OK���뵽����ȥУ��
	//Result_Regist_User_Has_Exist	,	//ע���Ѿ����ڸ��û�
	//Result_Regist_Send_Email_Error	,	//ע��ʱ���ͼ����ʼ�ʧ��
	//Regist_Success			,	//ע��ɹ��ˡ�֪ͨ���¼
	//SS_Login_OK				,
	//Result_SS_Login_User_Not_Exist ,
	//Result_SS_Login_Password_Error	,
	//RegistCheck_SUCCESS		,	//У��ɹ�
	//Result_RegistCheck_Not_Exist	,	//У����Ϣ������
	
	//Result_RegistCheck_User_HasRegist	,	//�û��Ѿ�ע����
	
	//Result_ServerSomeFail,
	
	//Result_Unserialize_Fail,
	//Result_Serialize_Fail,
};

#define USER_ID_LENGTH 32
#define USER_ID_SIZE USER_ID_LENGTH+1
#define MAX_STR_LENGTH 256
#define MAX_ICON_LENGTH 16*1024

struct FollowCountRespT
{
	//char userID;
	char userID[USER_ID_SIZE];
	int count;
};

struct PublicShareLastSequenceNumber
{
//	char				m_UserId;
	int						m_seqNum;
};

struct SSGroupT
{
	char	groupid[USER_ID_SIZE];
	char	name[MAX_STR_LENGTH];
	int	    proprety ; // ��ϵͳ�黹���û��Զ�����,0:ϵͳ��,1:�Զ�����
	//char	extend; // ��չ�ֶΣ����Է��κζ���
	char *extend;
	unsigned int LengthEx;
    SSGroupT() { memset(this, 0, sizeof(SSGroupT)); proprety = -1;}
    ~SSGroupT() { if (extend != NULL) delete extend; }
};

struct SSContactsT
{
	char	contactid[USER_ID_SIZE]; 
	char	userid[USER_ID_SIZE];	// ϵͳ�û�����
	char	user[MAX_STR_LENGTH];   //email���ֻ���
	char	nickname[MAX_STR_LENGTH];
	char	nickalias[MAX_STR_LENGTH]; //��ע����
	char	iconname[MAX_STR_LENGTH];
	char	remark[MAX_STR_LENGTH];
	int      age;
	int      sex;
	bool	Issystem;
	int		IsFollowing; //0����,1��ʾ�Ǹ�����
	int		IsFollower;
	int		IsInvite;
	char* 	extend;
	unsigned int LengthEx;
    SSContactsT() { memset(this, 0, sizeof(SSContactsT)); sex = -1;}
    ~SSContactsT() { if (extend != NULL) delete extend; }
};


struct SSContactsExT
{
	char contactid[USER_ID_SIZE]; // ϵͳ�û�����
	char userid[USER_ID_SIZE];	// ϵͳ�û�����
	char user[MAX_STR_LENGTH];   //email���ֻ���
	char nickalias[MAX_STR_LENGTH]; //��ע����
    SSContactsExT() { memset(this, 0, sizeof(SSContactsExT));}
    ~SSContactsExT() { }
};

struct SSIconT
{
	char userid[USER_ID_SIZE];
	char iconname[MAX_STR_LENGTH];
	char icon[MAX_ICON_LENGTH];
	unsigned int LengthIcon;
    SSIconT() { memset(this, 0, sizeof(SSIconT));}
    ~SSIconT() { }
};

struct SSProfileT
{
  char		userid[USER_ID_SIZE];
  int		age;
  int		sex;
  char		nickname[MAX_STR_LENGTH];
  char		remark[MAX_STR_LENGTH];			//���� haoxq change at 2010-10-09
  char		iconname[MAX_STR_LENGTH];
  char		icon[MAX_ICON_LENGTH];
  unsigned int LengthIcon;
  char* 	extend;
  unsigned int LengthEx;
  SSProfileT() { memset(this, 0, sizeof(SSProfileT)); sex = -1;}
  ~SSProfileT() { if (extend != NULL) delete extend; }
};

struct SSLastTimeT
{
	char last_user_time[MAX_STR_LENGTH];
	char last_group_time[MAX_STR_LENGTH];
	char last_contact_time[MAX_STR_LENGTH];
	char last_member_time[MAX_STR_LENGTH];
	char last_follow_time[MAX_STR_LENGTH];
	char last_send_time[MAX_STR_LENGTH];
	char last_recv_time[MAX_STR_LENGTH];
	char last_favo_time[MAX_STR_LENGTH];
    SSLastTimeT() { memset(this, 0, sizeof(SSLastTimeT)); }
    ~SSLastTimeT() { }
};

struct SSUserExistT
{
	char userId[USER_ID_SIZE];
	bool		isSystem;
    SSUserExistT() { memset(this, 0, sizeof(SSUserExistT));}
    ~SSUserExistT() { }
};
//���groupid
struct SSGroupMembersT
{
	char groupid[USER_ID_SIZE];
	char contactid[USER_ID_SIZE];
    SSGroupMembersT() { memset(this, 0, sizeof(SSGroupMembersT));}
    ~SSGroupMembersT() { }
};

//vector<SSGroupMembersT> 
struct FollowListRespT
{
	char userID[USER_ID_SIZE];  //��עĿ���userid
	SSProfileT * userInfo;
	unsigned int Length;
	FollowListRespT() { memset(this, 0, sizeof(FollowListRespT));}
	~FollowListRespT() { if (userInfo != NULL) delete userInfo; }
};

struct LastPubShareSeqNumRespT
{
     int seqNum;
};
// ��Ϣ����
//enum  ShareType{
//	SEND_PUBLIC = 0,	// �����������Ϣ
//	SEND_PROTECT = 1,	// ָ�������͵���Ϣ
//	RECIEVE_FROM = 2,	// ָ��������յ���Ϣ
//	FAVORITE = 3,		//��ӵ��ղؼе���Ϣ
//};
enum  ShareType{
	PUBLIC_SHARE = 1,	// �����������Ϣ
	PROTECT_SHARE = 2,	// ָ�������͵���Ϣ
	PRIVATE_SHARE = 3,	// ��ӵ��ղؼе���Ϣ
//	RECIEVE_SHARE = 4,	//ָ��������յ���Ϣ
};
// ��������
enum  SSMessageType{	//haoxq change at 2010-10-09
	SM_NORMAL = 0,		// ��ͨ����
	SM_PROFILE = 100,	// ����Ϊ����
	SM_ICON = 101,		// ����Ϊ����
};
#define MSG_ID_LENGTH 48
#define MSG_ID_SIZE MSG_ID_LENGTH+1

struct ShareMsg
{ 
	char					msgid[MSG_ID_SIZE]; // ��8�ֽڵ�ʱ��������+16�ֽڵ�uuid
	// ʱ���������л�8�ֽ�ʱӦ�ò���Big Endian����.
	//��������ǰ��8�ֽ�Ϊ��ţ�ָ������Ϊʱ��
	char					parentMsgid[MSG_ID_SIZE];//ת����ʱ����һ����msgid
	char					rootMsgid[MSG_ID_SIZE];  //ԭʼ�����ߵ�msgid 
	ShareType				type;
	int						seqNum;
	__int64					timestamp; // ���ֶο�ѡ��Ҳ����msgidǰ���8�ֽ�
	char					sender[USER_ID_SIZE];
	char*					recievers;					//һ����userid�ĳ��ȣ�32*����
	unsigned int			LengthRecv;					//��ʾrecievers�����ݳ��ȣ��̶�Ϊ32*��������������β0�ĳ���
	char					subject[MAX_STR_LENGTH]; // ��Ϣ���⣬��ҳΪ���⣬һ�仰��ȫ����������
	SSMessageType			Msgtype;
	char					*body;
	unsigned int			LengthBody;
    ShareMsg() { memset(this, 0, sizeof(ShareMsg));}
    ~ShareMsg() { if (body != NULL) delete body; if (recievers != NULL) delete recievers; }
};

typedef void (*OnSessionDomainCallBack)(unsigned int index, CallBackCMDID id, SSResultCode result, void * pData, unsigned int param);

class IUserInterface;

/**
* ���� ��ʼ��
*
* @param callBackFun			[IN] �ص�����ָ��
*
* @return	    ����״̬��
*/

SD_CLIENT_DLL_API SSResultCode SDInit(unsigned int index, OnSessionDomainCallBack callBackFun);
/**
* ���� ����
*
*
* @return	    ����״̬��
*/
SD_CLIENT_DLL_API SSResultCode SDDestroy();

/**
* ���� ע�ᣬ���øýӿ����ע�Ṧ�ܣ��첽������ֵ������������ע��ɹ���
*
* @param userID				[IN] ע����û�ID
* @param password			[IN] ע������롣
* @param pszUser			[IN] ע�������,���ֻ���
* @param pszNick			[IN] ע����ǳ�
* @param pPrivateInfo		[IN] ע��ʱ������˽����Ϣָ�룬Ϊҵ����ṩ����չ��
* @param PrivateInfoLen		[IN] ע��ʱ������˽����Ϣ���ȡ�
* @param pUser			[OUT]�����û��Ĳ���ʵ�塣

*
* @return	    ����״̬��
*/
SD_CLIENT_DLL_API SSResultCode SDRegister(unsigned int index, const char * userID, 
						const char * pszUser,
						const char * pszPwd,
						const char * psznick,
						const char * pExtendInfo,
						unsigned int ExtendLen);
/**
* ���� ��¼���û������������Ҫ��¼����ʹ��
*
* @param userID			[IN] ��¼���û���
* @param pszPassword	[IN] ��¼�����롣
* @param pUser			[OUT]�����û��Ĳ���ʵ
*
* @return	    ����״̬��
*/
SD_CLIENT_DLL_API SSResultCode SDLogIn(unsigned int index, const char * userID, 
					 const char * md5Pwd,
					IUserInterface ** pIUser);

/**
* ���� ���ߣ��û��˳���¼
*
* @param pUser			[IN]ĳ���û����ߴ��������ʵ��
 * @return	    ����״̬��
*/
SD_CLIENT_DLL_API SSResultCode SDLogOut(unsigned int index, IUserInterface * pIUser);

/**
* ���� �������� 
*
* @param userID			[IN] �û����û���
* @param pUser			[OUT]�����û��Ĳ���ʵ
*
* @return	    ����״̬��
*/
SD_CLIENT_DLL_API SSResultCode SDForgetPassword(unsigned int index, const char * userID);
SD_CLIENT_DLL_API SSResultCode SDVerifyActiveCode(unsigned int index, const char * userID, const char * pszVerifyCode);
SD_CLIENT_DLL_API SSResultCode SDChangePassword(unsigned int index, const char * userID, const char * newPwd);
/**
* ���� �ж�ĳ���û��Ƿ�Ϊϵͳע���û�,ͨ��GetAccountʵ�֡�
*
* @param checkUserID	[IN] �жϵ��û���,ÿ��id���ȹ̶�ΪMAX_ID_LENGTH����0��β
*
* @return	    ����״̬��
һ��һ������
*/
SD_CLIENT_DLL_API SSResultCode SDUserIsExist(unsigned int index, const char* userIDs); 

class SD_CLIENT_DLL_CLASS IUserInterface
{
public:
	virtual SSResultCode VerifyActiveCode(unsigned int index, const char * pszVerifyCode) = 0;

	virtual SSResultCode ChangePassword(unsigned int index,const char * newPwd) = 0;

	//������¼����
	virtual SSResultCode GetProfile(unsigned int index) = 0;
	
	virtual SSResultCode SetProfile(unsigned int index, const ::SSProfileT& userProfile) = 0;
	//idʹ�÷ָ���','�ָ�
	//������¼����
	virtual SSResultCode GetOtherProfile(unsigned int index, const char* userIDs) = 0;
	//�����ύ��������η���
	virtual SSResultCode GetIcons(unsigned int index, const char* userIDs) = 0;

	virtual SSResultCode SetIcon(unsigned int index, const ::SSIconT& userIcon) = 0;	//haoxq change at 2010-10-09

	virtual SSResultCode GetFollowCount(unsigned int index) = 0;

	virtual SSResultCode GetFollowingCount(unsigned int index) = 0;
	//��������
	virtual SSResultCode GetFollowList(unsigned int index, const char * lastID, int getCount) = 0;
	//��������
	virtual SSResultCode GetFollowingList(unsigned int index) = 0;


    virtual SSResultCode GetOtherFollowCount(unsigned int index, const char * otherUserID) = 0;

	virtual SSResultCode GetOtherFollowingCount(unsigned int index, const char * otherUserID) = 0;

	//��������
	virtual SSResultCode GetOtherFollowList(unsigned int index, const char * lastID, int getCount, const char * userID) = 0;

	//��������
	virtual SSResultCode GetOtherFollowingList(unsigned int index, const char * userID) = 0;

	//��������
	virtual SSResultCode GetContacts (unsigned int index) = 0;//SSContactsT,�������أ��ڲ���Ҫ��β

	virtual SSResultCode SetContact(unsigned int index, const ::SSContactsExT & contact) = 0;			//�޸���ϵ����Ϣ

	virtual SSResultCode AddContacts(unsigned int index, const ::SSContactsExT* contacts, unsigned int length) = 0; //���۳ɹ����ÿ�������ؽ����һ��������
	//idʹ�÷ָ���','�ָ�
	virtual SSResultCode RemoveContacts(unsigned int index, const char* contactIDs) = 0;	//���۳ɹ����ÿ�������ؽ����һ��������

	//��������
	virtual SSResultCode GetGroups(unsigned int index) = 0;//�������أ��ڲ���Ҫ��β

	virtual SSResultCode SetGroup(unsigned int index, const ::SSGroupT &) = 0;

	virtual SSResultCode AddGroup(unsigned int index, const ::SSGroupT &) = 0;
	
	//idʹ�÷ָ���','�ָ�
	virtual SSResultCode RemoveGroup(unsigned int index, const char* groupIDs) = 0;

	//��������
	virtual SSResultCode GetLastTime(unsigned int index) = 0;

	virtual SSResultCode SetLastTime(unsigned int index, const ::SSLastTimeT& lasttime) = 0; 

	//��������
	virtual SSResultCode GetGroupMembers(unsigned int index) = 0;//�������أ��ڲ���Ҫ��β

	virtual SSResultCode AddGroupMembers(unsigned int index, const ::SSGroupMembersT* members, unsigned int length ) = 0;

	virtual SSResultCode RemoveGroupMembers(unsigned int index, const ::SSGroupMembersT* members, unsigned int length ) = 0;

	virtual SSResultCode PublicShare(unsigned int index, const ::ShareMsg &shareContent) = 0;

	virtual SSResultCode ProtectShare(unsigned int index, const ::ShareMsg &shareContent) = 0;

	virtual SSResultCode PrivateShare(unsigned int index, const ::ShareMsg & shareContent) = 0;

	//��������
	virtual SSResultCode GetMsgFromInBox(unsigned int index, const char* msgid, int      getCount) = 0; //ÿ��ֻ����һ��

	//idʹ�÷ָ���','�ָ�
	//��������
	virtual SSResultCode GetProtectShareMsgFromOutBox(unsigned int index, const char* msgid,
											          int      getCount) = 0;

	//idʹ�÷ָ���','�ָ�
	//��������
	virtual SSResultCode GetPublicShareMsgFromOutBox(unsigned int index,  const char* msgid,
													  int    getCount) = 0;

	//��������
	virtual SSResultCode GetOtherUserPublicShareMsg(unsigned int index, const char* otherUserID,  
													int	   seqNumCursor,
													int    getCount) = 0;
	//��Ӧ���ݽṹ
	//userid result,cmd,
	//idʹ�÷ָ���','�ָ�
	virtual SSResultCode FollowUser(unsigned int index,  const char* users) = 0;
	//
	virtual SSResultCode UnFollowUser(unsigned int index, const  char* users) = 0;

    // �����û��������¼
    //     char* users�����������ߵ�userid�б��á�,���ָ���
    // �ص���
    //     SSResultCode result��Result_Success�ɹ�������ʧ��
    //     void * pData������NULL��
    //     unsigned int param������0��
    // 
    // ע�����ڱ������ߵ�ǰ������ϵͳ�û������������userid����email���ɣ�
    // ��������ϵͳ��ǰ��������û���
    // 
    virtual SSResultCode Invite(unsigned int index, const char* users) = 0;

    // ��ȡ�û��������ˣ�˭������ң�
    //     
    // �ص���
    //     SSResultCode result��Result_Success�ɹ�������ʧ��
    //     void * pData�������˵�SSProfileT���飻
    //     unsigned int param��������SSProfileT������
    // 
    //virtual SSResultCode GetInviterList(unsigned int index) = 0;
};

#pragma pack(pop)
//SD_CLIENT_NAMESPACE_END;

#endif //_ISESSIONDOMAINCLIENT_H_