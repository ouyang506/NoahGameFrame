// -------------------------------------------------------------------------
//    @FileName				:    NFCCreateRoleModule.cpp
//    @Author               :    LvSheng.Huang
//    @Date                 :    2013-03-29
//    @Module               :    NFCCreateRoleModule
//    @Desc                 :
// -------------------------------------------------------------------------

#include "NFCCreateRoleModule.h"
#include "NFComm/NFMessageDefine/NFProtocolDefine.hpp"

bool NFCCreateRoleModule::Init()
{
    return true;
}

bool NFCCreateRoleModule::AfterInit()
{
	m_pKernelModule = pPluginManager->FindModule<NFIKernelModule>();
	m_pGameLogicModule = pPluginManager->FindModule<NFIGameLogicModule>();
	m_pNoSqlModule = pPluginManager->FindModule<NFINoSqlModule>();
	m_pGameServerNet_ServerModule = pPluginManager->FindModule<NFIGameServerNet_ServerModule>();

	return true;
}

void NFCCreateRoleModule::OnReqiureRoleListProcess(const int nSockIndex, const int nMsgID, const char * msg, const uint32_t nLen)
{
	NFGUID nClientID;
	NFMsg::ReqRoleList xMsg;
	if (!m_pGameServerNet_ServerModule->GetNetModule()->ReceivePB(nSockIndex, nMsgID, msg, nLen, xMsg, nClientID))
	{
		return;
	}

	const std::string& strAccount = xMsg.account();

	NFGUID xPlayerID;
	if (!m_pPlayerRedisModule->GetAccountRoleID(strAccount, xPlayerID))
	{
		return;
	}

	NF_SHARE_PTR<NFIPropertyManager> xPlayerProperty = m_pPlayerRedisModule->GetPlayerCacheProperty(xPlayerID);

	if (xPlayerProperty && xPlayerID != NULL_OBJECT)
	{
		NFMsg::AckRoleLiteInfoList xAckRoleLiteInfoList;
		NFMsg::RoleLiteInfo* pData = xAckRoleLiteInfoList.add_char_data();
		pData->mutable_id()->CopyFrom(NFINetModule::NFToPB(xPlayerID));
		pData->set_game_id(pPluginManager->GetAppID());
		pData->set_career(0);
		pData->set_sex(0);
		pData->set_race(0);
		pData->set_noob_name(xPlayerProperty->GetPropertyString(NFrame::Player::Name()));
		pData->set_role_level(0);
		pData->set_delete_time(0);
		pData->set_reg_time(0);
		pData->set_last_offline_time(0);
		pData->set_last_offline_ip(0);
		pData->set_view_record("");

		m_pGameServerNet_ServerModule->SendMsgPBToGate(NFMsg::EGMI_ACK_ROLE_LIST, xAckRoleLiteInfoList, nClientID);
	}
	else
	{
		NFMsg::AckRoleLiteInfoList xAckRoleLiteInfoList;
		m_pGameServerNet_ServerModule->SendMsgPBToGate(NFMsg::EGMI_ACK_ROLE_LIST, xAckRoleLiteInfoList, nClientID);
	}
}

void NFCCreateRoleModule::OnCreateRoleGameProcess(const int nSockIndex, const int nMsgID, const char * msg, const uint32_t nLen)
{
	NFGUID nClientID;
	NFMsg::ReqCreateRole xMsg;
	if (!m_pGameServerNet_ServerModule->GetNetModule()->ReceivePB(nSockIndex, nMsgID, msg, nLen, xMsg, nClientID))
	{
		return;
	}

	const std::string& strAccount = xMsg.account();
	const std::string& strName = xMsg.noob_name();

	NFGUID xID = m_pPlayerRedisModule->CreateRole(strAccount, strName);
	if (xID != NULL_OBJECT)
	{
		NFMsg::AckRoleLiteInfoList xAckRoleLiteInfoList;
		NFMsg::RoleLiteInfo* pData = xAckRoleLiteInfoList.add_char_data();
		pData->mutable_id()->CopyFrom(NFINetModule::NFToPB(xID));
		pData->set_career(xMsg.career());
		pData->set_game_id(pPluginManager->GetAppID());
		pData->set_sex(xMsg.sex());
		pData->set_race(xMsg.race());
		pData->set_noob_name(xMsg.noob_name());
		pData->set_role_level(1);
		pData->set_delete_time(0);
		pData->set_reg_time(0);
		pData->set_last_offline_time(0);
		pData->set_last_offline_ip(0);
		pData->set_view_record("");

		m_pGameServerNet_ServerModule->GetNetModule()->SendMsgPB(NFMsg::EGMI_ACK_ROLE_LIST, xAckRoleLiteInfoList, nSockIndex, nClientID);
	}
}

void NFCCreateRoleModule::OnDeleteRoleGameProcess(const int nSockIndex, const int nMsgID, const char * msg, const uint32_t nLen)
{
	NFGUID nClientID;
	NFMsg::ReqRoleList xMsg;
	if (!m_pGameServerNet_ServerModule->GetNetModule()->ReceivePB(nSockIndex, nMsgID, msg, nLen, xMsg, nClientID))
	{
		return;
	}
		
	NFMsg::AckRoleLiteInfoList xAckRoleLiteInfoList;
	m_pGameServerNet_ServerModule->SendMsgPBToGate(NFMsg::EGMI_ACK_ROLE_LIST, xAckRoleLiteInfoList, nClientID);
}

bool NFCCreateRoleModule::ReadyExecute()
{
	m_pGameServerNet_ServerModule->GetNetModule()->RemoveReceiveCallBack(NFMsg::EGMI_REQ_ROLE_LIST);
	m_pGameServerNet_ServerModule->GetNetModule()->RemoveReceiveCallBack(NFMsg::EGMI_REQ_CREATE_ROLE);
	m_pGameServerNet_ServerModule->GetNetModule()->RemoveReceiveCallBack(NFMsg::EGMI_REQ_DELETE_ROLE);

	m_pGameServerNet_ServerModule->GetNetModule()->AddReceiveCallBack(NFMsg::EGMI_REQ_ROLE_LIST, this, &NFCCreateRoleModule::OnReqiureRoleListProcess);
	m_pGameServerNet_ServerModule->GetNetModule()->AddReceiveCallBack(NFMsg::EGMI_REQ_CREATE_ROLE, this, &NFCCreateRoleModule::OnCreateRoleGameProcess);
	m_pGameServerNet_ServerModule->GetNetModule()->AddReceiveCallBack(NFMsg::EGMI_REQ_DELETE_ROLE, this, &NFCCreateRoleModule::OnDeleteRoleGameProcess);

	return true;
}

bool NFCCreateRoleModule::Shut()
{
    return true;
}

bool NFCCreateRoleModule::Execute()
{
    return true;
}