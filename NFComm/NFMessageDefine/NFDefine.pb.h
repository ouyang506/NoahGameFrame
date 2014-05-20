// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NFDefine.proto

#ifndef PROTOBUF_NFDefine_2eproto__INCLUDED
#define PROTOBUF_NFDefine_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace NFMsg {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_NFDefine_2eproto();
void protobuf_AssignDesc_NFDefine_2eproto();
void protobuf_ShutdownFile_NFDefine_2eproto();


enum EGameEventCode {
  EGEC_UNKOWN_ERROR = 0,
  EGEC_SUCCESS = 1,
  EGEC_ACCOUNT_EXIST = 2,
  EGEC_ACCOUNTPWD_INVALID = 3,
  EGEC_ACCOUNT_USING = 4,
  EGEC_ACCOUNT_LOCKED = 5,
  EGEC_ACCOUNT_SUCCESS = 6,
  EGEC_CHARACTER_EXIST = 10,
  EGEC_SVRZONEID_INVALID = 11,
  EGEC_CHARACTER_NUMOUT = 12,
  EGEC_CHARACTER_INVALID = 13,
  EGEC_CHARACTER_NOTEXIST = 14,
  EGEC_CHARACTER_USING = 15,
  EGEC_CHARACTER_LOCKED = 16,
  EGEC_ZONE_OVERLOAD = 17,
  EGEC_NOT_ONLINE = 18,
  EGEC_ALREAY_IN_TEAM = 19,
  EGEC_INVALID_TEAM_INVITE = 20,
  EGEC_TEAM_FULL = 21,
  EGEC_MAIL_UPDATE_ERROR = 22,
  EGEC_MAIL_TONAME_INVALID = 23,
  EGEC_MAIL_DELETE_ERROR = 24,
  EGEC_MAIL_TOWNAME_EQUAL = 25,
  EGEC_LACK_MONEY = 26,
  EGEC_FULL_PACKAGE = 27,
  EGEC_INVALID_ITEM = 28,
  EGEC_INVALID_CONSIGNMENT = 29,
  EGEC_NOT_ENOUGH_VIP = 30,
  EGEC_NEED_LEVEL = 31,
  EGEC_MAX_FRIEND_LIST = 32,
  EGEC_MAX_ENEMY_LIST = 33,
  EGEC_MAX_GANGS_LSIT = 34,
  EGEC_LIMITS_TO_RIGHTS = 35,
  EGEC_INVALID_GANGS_NAME = 36,
  EGEC_REPEAT_ENTER_GANGS = 37,
  EGEC_INVALID_GANGSMEMBER = 38,
  EGEC_MASTER_LEAVE_GANGS = 39,
  EGEC_GANGS_TITLE_OUTOF = 40,
  EGEC_ENTER_GATEWAY_FAILD = 41,
  EGEC_NO_SERVER4ZONE = 42,
  EGEC_INVALID_SKILL = 43
};
bool EGameEventCode_IsValid(int value);
const EGameEventCode EGameEventCode_MIN = EGEC_UNKOWN_ERROR;
const EGameEventCode EGameEventCode_MAX = EGEC_INVALID_SKILL;
const int EGameEventCode_ARRAYSIZE = EGameEventCode_MAX + 1;

const ::google::protobuf::EnumDescriptor* EGameEventCode_descriptor();
inline const ::std::string& EGameEventCode_Name(EGameEventCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameEventCode_descriptor(), value);
}
inline bool EGameEventCode_Parse(
    const ::std::string& name, EGameEventCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameEventCode>(
    EGameEventCode_descriptor(), name, value);
}
enum EGameMsgID {
  EGMI_UNKNOW = 0,
  EGMI_EVENT_RESULT = 1,
  EGMI_EVENT_TRANSPOND = 2,
  EGMI_CLOSE_SOCKET = 3,
  EGMI_MTL_WORLD_REGISTERED = 10,
  EGMI_MTL_WORLD_UNREGISTERED = 11,
  EGMI_MTL_WORLD_REFRESH = 12,
  EGMI_LTM_LOGIN_REGISTERED = 20,
  EGMI_LTM_LOGIN_UNREGISTERED = 21,
  EGMI_LTM_LOGIN_REFRESH = 22,
  EGMI_PTWG_PROXY_REGISTERED = 30,
  EGMI_PTWG_PROXY_UNREGISTERED = 31,
  EGMI_PTWG_PROXY_REFRESH = 32,
  EGMI_GTW_GAME_REGISTERED = 40,
  EGMI_GTW_GAME_UNREGISTERED = 41,
  EGMI_GTW_GAME_REFRESH = 42,
  EGMI_STS_NET_INFO = 50,
  EGMI_REQ_LOGIN = 101,
  EGMI_ACK_LOGIN = 102,
  EGMI_REQ_LOGOUT = 103,
  EGMI_REQ_WORLD_LIST = 110,
  EGMI_ACK_WORLS_LIST = 111,
  EGMI_REQ_CONNECT_WORLD = 112,
  EGMI_ACK_CONNECT_WORLD = 113,
  EGMI_REQ_KICK_CLIENT_INWORLD = 114,
  EGMI_REQ_CONNECT_KEY = 120,
  EGMI_ACK_CONNECT_KEY = 122,
  EGMI_REQ_SELECT_SERVER = 130,
  EGMI_REQ_ROLE_LIST = 131,
  EGMI_ACK_ROLE_LIST = 132,
  EGMI_REQ_CREATE_ROLE = 133,
  EGMI_REQ_DELETE_ROLE = 134,
  EGMI_REQ_RECOVER_ROLE = 135,
  EGMI_REQ_COMMAND = 140,
  EGMI_REQ_ENTER_GAME = 150,
  EGMI_REQ_LEAVE_GAME = 151,
  EGMI_REQ_SWAP_GAME = 152,
  EGMI_REQ_SWAP_SCENE = 153,
  EGMI_ACK_OBJECT_ENTRY = 200,
  EGMI_ACK_OBJECT_LEAVE = 201,
  EGMI_ACK_PROPERTY_INT = 210,
  EGMI_ACK_PROPERTY_FLOAT = 211,
  EGMI_ACK_PROPERTY_STRING = 212,
  EGMI_ACK_PROPERTY_DOUBLE = 213,
  EGMI_ACK_PROPERTY_OBJECT = 214,
  EGMI_ACK_ADD_ROW = 220,
  EGMI_ACK_REMOVE_ROW = 221,
  EGMI_ACK_SWAP_ROW = 222,
  EGMI_ACK_RECORD_INT = 223,
  EGMI_ACK_RECORD_FLOAT = 224,
  EGMI_ACK_RECORD_DOUBLE = 225,
  EGMI_ACK_RECORD_STRING = 226,
  EGMI_ACK_RECORD_OBJECT = 227,
  EGMI_REQ_MOVE = 230,
  EGMI_ACK_MOVE = 231,
  EGMI_REQ_MOVE_IMMUNE = 232,
  EGMI_ACK_MOVE_IMMUNE = 233,
  EGMI_REQ_SKILL_OBJECTX = 240,
  EGMI_ACK_SKILL_OBJECTX = 241,
  EGMI_REQ_SKILL_POS = 242,
  EGMI_ACK_SKILL_POS = 243,
  EGMI_REQ_ITEM_OBJECT = 244,
  EGMI_ACK_ITEM_OBJECT = 245,
  EGMI_REQ_ITEM_POS = 246,
  EGMI_ACK_ITEM_POS = 247,
  EGMI_REQ_CHAT = 250,
  EGMI_ACK_CHAT = 251,
  EGMI_REQ_SALE_ITEM = 252,
  EGMI_REQ_SPLIT_ITEM = 253,
  EGMI_REQ_PRODUCE_ITEM = 254,
  EGMI_REQ_PICK_ITEM = 255,
  EGMI_REQ_ACCEPT_TASK = 256,
  EGMI_REQ_PULLDOWNCUSTOM = 257
};
bool EGameMsgID_IsValid(int value);
const EGameMsgID EGameMsgID_MIN = EGMI_UNKNOW;
const EGameMsgID EGameMsgID_MAX = EGMI_REQ_PULLDOWNCUSTOM;
const int EGameMsgID_ARRAYSIZE = EGameMsgID_MAX + 1;

const ::google::protobuf::EnumDescriptor* EGameMsgID_descriptor();
inline const ::std::string& EGameMsgID_Name(EGameMsgID value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameMsgID_descriptor(), value);
}
inline bool EGameMsgID_Parse(
    const ::std::string& name, EGameMsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameMsgID>(
    EGameMsgID_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace NFMsg

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameEventCode>() {
  return ::NFMsg::EGameEventCode_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameMsgID>() {
  return ::NFMsg::EGameMsgID_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_NFDefine_2eproto__INCLUDED