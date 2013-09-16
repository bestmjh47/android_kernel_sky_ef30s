#ifndef __CUST_SKY_CP_H__
#define __CUST_SKY_CP_H__
/*****************************************************
    SKY Android 모델 공통 적용사항
    Feature Name : T_SKY_MODEL_TARGET_COMMON
******************************************************/
#ifdef T_SKY_MODEL_TARGET_COMMON

/*
    DDMS Log에 radio log 를 볼수있도록 함. 
    Test 편의를 위해 사용하는 것이기 때문에
    envsetup.mk 의 TARGET_BUILD_VARIANT 가 user ( user mode compile )
    일때 만 FEATURE_AARM_RELEASE_MODE 가 define됨.
     (PS1팀 작업 필수: cust_sky.h 에 사용여부 확인.)
    android/system/core/liblog/logd_write.c
*/
#ifndef FEATURE_AARM_RELEASE_MODE
#define FEATURE_SKY_CP_RADIO_LOG_DDMS
#endif/* FEATURE_AARM_RELEASE_MODE */

/*
   Qualcomm OEM Hook 기능을 이용한 확장.  ( NV access, SIM access etc..)
*/
#define FEATURE_SKY_CP_QCRILHOOK_INTERFACE

#ifdef FEATURE_SKY_CP_QCRILHOOK_INTERFACE
/* oemhook및 qcril에서 error exception처리를 위한 선언. */
#define FEATURE_SKY_CP_EXCEPTION_DEFINITION

#define FEATURE_SKY_QCRILHOOK_EVENT_PROCESSED_BY_SUB_THREAD

/* OEM Hook 기반으로 SIM access를 GSDI를 이용할때 sync방식으로 access하기 위한 I/F */
#define FEATURE_SKY_CP_GSDI_SYNC_ACCESS_BY_REMOTE_PROCESSOR
#endif/* FEATURE_SKY_CP_QCRILHOOK_INTERFACE */

/* 
   SkyTelephonyInterfaceManager.java, Service_Manager.c, ISkyTelephony.aidl 
*/
#define FEATURE_SKY_CP_TELEPHONYMANAGER
#ifdef FEATURE_SKY_CP_TELEPHONYMANAGER
/* Java에서 Modem API 호출을 위한 Daemon ( NV access, 자동응답, VE 기능, etc.. ) */
#define FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE
#ifdef FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE
/* Voice Call connection sound event */
#define FEATURE_SKY_CP_CS_CALL_CONNECTION_SND_START

/* SKY 자동응답기능 Interface */
#define FEATURE_SKY_CP_AUTOANSWER_INTERFACE
#endif/* FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE */
#endif/* FEATURE_SKY_CP_TELEPHONYMANAGER */

/*
   Qualcomm Feature [FEATURE_QCRIL_UIM_QMI] 사용
*/
#define FEATURE_SKY_CP_SUPPORT_FEATURE_QCRIL_UIM_QMI
#ifdef FEATURE_SKY_CP_SUPPORT_FEATURE_QCRIL_UIM_QMI
/* qcril 에서 mmgsdi 및 gsdi function 사용시 RPC callback 이 필요함. */
#define FEATURE_SKY_CP_GSDI_RPC_CALLBACK_SUPPORT
#endif/* FEATURE_SKY_CP_SUPPORT_FEATURE_QCRIL_UIM_QMI */


/* UMTS PS/CS Domain setting menu support */
#define FEATURE_SKY_CP_SERVICE_DOMAIN_CHANGE_CMD

/* UMTS SMS MO PS/CS Domain setting menu support */
#define FEATURE_SKY_CP_SMS_CFG_SET_GW_DOMAIN

/* Phone Operation Mode setting (lpm, offline, online .. ) */
#define FEATURE_SKY_CP_PHONE_OPERATION_MODE

/* RIL state 에 상관없이 항상 ril socket open상태에서는 RIL_REQUEST_XXX 가 동작하도록 함. */
#define FEATURE_SKY_CP_FORCE_ALLOW_RIL_REQUEST

/* SKT 영상 컬러링 지원 Interface */
#define FEATURE_SKT_CP_VE_SUPPORT

/*
    network 등록이 완료된 후 10초후에 property를 설정하여 lcd on/off 에 대해서 cm event reg/dereg 를 
    가능하도록 한다.  시간 업데이트 문제....
*/
#define FEATURE_SKY_CP_TIME_UPDATE_ABSOLUTELY_ON_BOOT

#endif/* T_SKY_MODEL_TARGET_COMMON */


/* ######################################################################### */



/*****************************************************
    SKT/KT 공통 적용사항
    Feature Name : T_SKY_MODEL_TARGET_WCDMA
******************************************************/
#ifdef T_SKY_MODEL_TARGET_WCDMA

/* OEM RAPI 를 이용하기 위한 Protocol Feature */
#define FEATURE_SKY_RPC_OEM_RAPI_NEW_INTERFACE

#define FEATURE_SKY_CP_ADDITIONAL_NV_ITEMS
#define FEATURE_SKY_CP_RPC_XDR_NV_ACCESS

#define FEATURE_SKY_CP_LOCAL_DB

#define FEATURE_SKT_CP_SUBSCRIPTION_MODE
#define FEATURE_SKY_CP_OTA_KT_SUBSCRIPTION

#define FEATURE_SKY_USIM_CARD_TYPE

#define FEATURE_SKY_CP_ACQ_DB_DELETE

#define FEATURE_SKY_CP_END_DUN_INTERFACE

#ifdef FEATURE_SKY_CP_QCRILHOOK_INTERFACE
/* OEM Hook 기반으로 NV access */
#define FEATURE_SKY_CP_NV_ACCESS_OEMHOOK

#ifdef FEATURE_SKY_CP_LOCAL_DB
/* OEM Hook 기반으로 Local DB access */
#define FEATURE_SKY_CP_LOCAL_DB_ACCESS_OEMHOOK
#endif/* FEATURE_SKY_CP_LOCAL_DB */
#endif/* FEATURE_SKY_CP_QCRILHOOK_INTERFACE */

#ifdef FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE
/* cpmgrif.c daemon을 통한 NV Access */
#define FEATURE_SKY_CP_NV_ACCESS_CPMGRIF

#ifdef FEATURE_SKY_CP_LOCAL_DB
/* cpmgrif.c daemon을 통한 Local DB Access */
#define FEATURE_SKY_CP_LOCAL_DB_ACCESS_CPMGRIF
#endif/* FEATURE_SKY_CP_LOCAL_DB */
#endif/* FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE */

/*
    SKT/KT 공통 Me Personalization ( With QMI interface )
*/
#define FEATURE_SKY_USIM_ME_PERSONALIZATION

/* 
   1. qcril 에서 default voice tech.를 3GPP2가 이닌 3GPP로 설정.
     --> 부팅 초기에 3GPP2로 radio technology가 천이되었다가 3GPP로 바뀌어서 3GPP2인 CDMA SIM 에서 SIM ready가 
            발생하여 PUK및 PIN 설정이 제대로 안되거나 SIM Record함수들이 CDMA용으로 동작하는 경우가 발생함.
   2. java class에서 Phone type이 GSMPhone으로 create 되도록 설정함.
*/
#define FEATURE_SKY_CP_DEFAULT_NETWORK_UMTS_IN_RIL


/*
    -. WMS Link control을 사용하며 MMS app.로 부터 발신 총 개수를 넘겨받아 WMS에서 처리하도록 RIL I/F 수정
*/
#define FEATURE_SKY_CP_MULTI_SMS_REQUIREMENT

/* CNAP 지원을 위한 RIL 및 framework 수정. */
#define FEATURE_SKY_CP_CNAP_SUPPORT
#ifdef FEATURE_SKY_CP_CNAP_SUPPORT
/* CNAP 수신 후 call state가 변경되면 수신 call에 대한 응답을 할수 없는 상태로 된다. */
#define FEATURE_SKY_CP_CNAP_STATE_BUG_FIX
#endif

/* 국내 사업자 (SKT, KT) 망에서 KSC5601 format의 USSD msg.와 CNAP 지원을 위한 수정. */
#define FEATURE_SKY_CP_USSD_CNAP_8BIT_CHAR_SUPPORT

/* WCDMA, GSM 의 RSSI level 기준 변경,  H/W 요청에 의한 변경 */
#define FEATURE_SKY_CP_GW_RSSI_LEVEL

/* 
    RSSI report 가 편차없이 이루어 질 수 있도록 delta threadhold 값을 수정
    modem코드에서 cmph.h 와 동일 적용.
 */
#define FEATURE_SKY_CP_RSSI_REPORT_VARIATION_FIX

/*
- Limited Service상태에서는 RSSI Bar의 개수를 0으로 표시하도록 수정.
- SIM없이 부팅되거나 부팅초기 reject없이 limited service가 유지되면 no service로 인식되기 때문에 
   qcril_cm.c 에서 qcril_cm_util_srv_sys_info_to_reg_state() 함수내 limited service 를 전달해주는 조건 수정이 필요함.
*/
#define FEATURE_SKY_CP_RSSI_BAR_ZERO_DISPLAY

/*
   서비스 상태 에서만 MCC/MNC 가 update 되던 부분을 Limited service상태에서도 update가 가능하도록 수정함.
*/
#define FEATURE_SKY_CP_GET_MCCMNC_UPDATE_IN_LIMITED_SRV

/* 단말 PS ONLY 모드로 설정시 android단에서 Reg state를 No Service로 처리하는 오류를 수정 */
#define FEATURE_SKY_CP_SUPPORT_PS_ONLY_MODE

/* qcril 에서 ui 로 올라가는 reg_status에 오류가 있어 이를 수정함 */
#define FEATURE_SKY_CP_REG_STATUS_UPDATE_CORRECTION

/*
   -. 단말의 service status가 SYS_SRV_STATUS_PWR_SAVE 일때 QCRIL_CM_SCREEN_STATE_ON 상태가 될때 즉
      Key interrup 발생으로 LCD가 on될때 단말이 power save상태라면 modem을 wakeup시키도록 되나, 
      qualcomm bug로 동작 안되는 현상 수정 
*/
#define FEATURE_SKY_CP_MODEM_PWR_SAVE_WAKEUP_FIX

/*
   -. card power down 커맨드 처리하지 않도록 함.
      < 미 수정시 발생하는 주요 문제점 >
      1. 비행중 모드 진입시 USIM card access되지 않는 문제
      2. 비행중 모드 진입시 SIM card가 인식되지 않는다는 문구 표시됨.
      3. on chip sim mode로 동작중 비행중 모드 들어가면 card가 없는 상태에서 UIM으로 card power down커맨드가 전달되어
*/
#define FEATURE_SKY_CP_CARD_POWER_DOWN_NOT_SUPPORT

/*
   통화중 대기음 설정을 위해 Setup ind. 에서 signal value를 설정함.
   AMSS에서 FEATURE_SKY_CP_SETUP_IND_SIGNAL_VALUE 와 반드시 연동되어야 함.
*/   
#define FEATURE_SKY_CP_SETUP_IND_SIGNAL_VALUE

/*
   ETC(상대방연결) 서비스 수행시 call end에 의해서 CM_EVENT_CALL_MNG_CALLS_CONF 가 처리되지 못하고 
   pending되어 있는경우 call end화면 처리를 하지 못하고 연결 실패 팝업이 발생하는 문제 수정.
*/
#define FEATURE_SKY_CP_ETC_BUG_FIX

/*
    망에서 release를 수신받지 못하는 상황에서 Call END 시도시 call 화면이 계속해서 in call상태를 유지하는 현상 수정.
    기존 피쳐폰에서도 적용된 사항으로 호종료시 call end를 기다리지 않고 call_end_req 커맨드 이벤트 발생시 call 화면을 정리할 수 있도록 함.
    A + B ( active ) , B + C ( hold ) 상태에서 A가 호종료 하는 시점에서 B가 호를 종료하면 android 쪽 call state와 ril쪽 call state가 
    꼬이는 경우가 발생함.
    Disconnect 이후 release procedure가 LG망과 삼성망에 차이가 있어서 KT의 경우 추풍령, 익산 등 삼성망에서 시험해야 됨.
*/
#define FEATURE_SKY_CP_CALL_END_REQ_FOR_UI_CLEAN

/* 
  Network preferred mode 설정 Menu
  Automatic, WCDMA only, GSM only
  국내에서는 메뉴 진입 못하도록 설정.
*/
#define FEATURE_SKY_CP_PREFERRED_NETWORK_MODE_SELECTION

/** GPS Feature **/
#define FEATURE_SKY_CP_GPS_TEST_SUPPORT

/* SIM 에 대한 인식 여부와 상태를 알아보기위한 테스트 코드 */
#define FEATURE_SKY_USIM_CARD_STATUS_PROPERTY
#endif/* T_SKY_MODEL_TARGET_WCDMA */


/* ######################################################################### */


/*****************************************************
    SKT 모델 적용사항
    Feature Name : T_SKY_MODEL_TARGET_SKT
******************************************************/
#ifdef T_SKY_MODEL_TARGET_SKT
#ifdef T_SKY_MODEL_TARGET_KT
#error Occured !!  This section is SKT only !!
#endif

#ifdef FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE

/* USIM card removed event */
#define FEATURE_SKY_CP_USIM_CARD_REMOVED_EVENT

#endif/* FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE */

/*
   GPS requirement ( hidden Menu, SUPL, android Provider, Etc... )
*/
#define FEATURE_SKT_CP_GPS_REQUIREMENT_ANDROID
#ifdef FEATURE_SKT_CP_GPS_REQUIREMENT_ANDROID
/* gps.conf 파일에 SUPL. host설정을 google로 변경. */
#define FEATURE_SKT_CP_GOOGLE_SUPL_SUPPORT
#endif/* FEATURE_SKT_CP_GPS_REQUIREMENT_ANDROID */

/* Network 자동선택,수동선택 항목 아래에 현재 망정보 ( RAT, PLMN, name ) 을 표시함 */
#define FEATURE_SKT_CP_NETWOTK_INFO_DISPLAY

/* SKT 사업자용 PLMN Table */
#define FEATURE_SKT_CP_PLMN_TABLE_LIST_SEARCH

/* SKT IOT Problem fix.
    PLMN과 network name 이 property에 저장되어 RTS 시험중 
    MM info.에 network name 포함 / 미포함 시험에서 fail되는 현상.
*/
#define FEATURE_SKT_CP_INIT_NITZ_INFO_PROPERTY

/* SKT 넘버플러스 서비스 지원 */
#define FEATURE_SKT_CP_NUMBER_PLUS_SUPPORT

/*
  reg reject 내용 표시 가능하도록 system property 값 적용함.
  reg reject 내용이 keyguard 화면에 표시되도록 함.
  AMSS관련 feature : FEATURE_SKY_CP_REJECT_CAUSE_DISPLAY
  reject cause관리를 ServiceState 에서 하도록 수정.
*/
#define FEATURE_SKT_CP_REJECT_CAUSE_DISPLAY

/*
   SKT향 PLMN Selection(자동/수동) 관련 구현사항.
*/
#define FEATURE_SKT_CP_NETWORK_PLMN_MANUAL_SELECTION

/* 
   IMEI mismatch Lock applet 만으로는 폰의 Lock 이 걸리지 않기 때문에
   USIM Lock을 위해서 추가 
 */
#define FEATURE_SKT_USIM_IMEI_LOCK

#endif/* T_SKY_MODEL_TARGET_SKT */


/* ######################################################################### */


/*****************************************************
    KT 모델 적용사항
    Feature Name : T_SKY_MODEL_TARGET_KT
******************************************************/
#ifdef T_SKY_MODEL_TARGET_KT

#ifdef T_SKY_MODEL_TARGET_SKT
#error Occured !!  This section is KT only !!
#endif


#endif/* T_SKY_MODEL_TARGET_KT */





/***********************************************************
   JAVA code에만 적용된 Feature 및 code 확인용...
   실제로 C/C++ 코드에는 적용되지 않는 사항으로 
   코드 검색및 확인용도로 사용하기 위함.
************************************************************/

/* import 문이나 여러 기능에 공통으로 들어가는 코드 표시 */
#define FEATURE_SKY_CP_COMMON_JAVA_DECLARATION

/* EF File 접근을 Path 를 이용하기 위해서 사용된 코드 */
#define FEATURE_SKY_USIM_EF_FILE_ACCESS_BY_PATH

/* USIM Card 제거시 재부팅 noti. */
#define FEATURE_SKY_CP_CARD_REMOVED

/* 로밍상태에서 UI동작 점검을 위한 fake roaming setting */
#define FEATURE_SKY_CP_ANDROID_FAKE_ROAMING_SETTING

/* Hidden Code 설정. 및 불필요한 code접근 막음. */
#define FEATURE_SKY_CP_HIDDEN_CODE_CONTROL

/* SKT USIM에서 UA Field생성에 필요한 MIN/IRM 추출. */
#define FEATURE_SKT_CP_CDMA_MIN_EF_ACCESS

/* GCF mode 설정 여부 */
#define FEATURE_SKT_CP_CHECK_GCF_MODE

/* 
   android Settings.DEVICE_PROVISIONED 가 항상 1로 설정되어있도록 함. 
   개발 초기에 GSM 음성 착신시 착신 거부되어 테스트 진행에 문제를 야기 시킴..
*/
#define FEATURE_SKY_CP_DISABLE_CHECK_DEVICE_PROVISIONED

/* Limited service상태를 구분하기 위해서 ServiceState 설정. */
#define FEATURE_SKY_CP_SERVICE_STATUS_DETAIL_SUBSTATE

/* Qualcomm Auto Answer 설정 오류 수정. ( SKY 자동응답기능 아님 !!) */
#define FEATURE_SKY_CP_AUTO_ANSWER_BUG_FIX

/* SKT Emergency Call requirement. */
#define FEATURE_SKT_CP_CHECK_EMERGENCY_CALL

/* 네트웍네임 표시 방법 - Short Name 표시 우선. */
#define FEATURE_SKT_CP_DISPLAY_NETWORK_NAME

/* 비행중 모드 설정 후 단말 재부팅 시 비행중 모드가 해제 되도록 함. */
#define FEATURE_SKY_CP_AIRPLANE_MODE_RELEASE_AFTER_BOOT

/* Roming indicator표시 오류 보완. */
#define FEATURE_SKY_CP_UPDATING_ROAMING_INDICATOR


/* Lock Screen에 표시되는 network name on-off 기능  */
#define FEATURE_SKT_CP_NETWORK_NAME_DISPLAY_ONOFF

/* SIM state check 오류 수정. patch시 해당 코드 확인요망. */
#define FEATURE_SKY_USIM_GET_SIM_STATE

/* 
   Power off 수행중 PS가 release되기 전에 android power off sequence가 완료되어 
   망으로 Detach를 올리지 못하는 경우가 있어 동작을 1초 정도 delay시킴.
*/
#define FEATURE_SKY_CP_DELAYED_POWER_OFF

/* 안드로이드 메뉴상에서 IMEI 를 확인할수 없도록 함.  */
#define FEATURE_SKY_CP_DEVICE_ID_NO_DISPLAY

/* KT SIM MSISDN표시 및 SKT SIM MSISDN 표시형식 수정. */
#define FEATURE_SKY_CP_DISPLAY_PHONE_NUMBER_WITH_TOA

/* Android Setting 메뉴에서 통화설정 메뉴 삭제.  */
#define FEATURE_SKY_CP_REMOVE_ANDROID_CALL_FEATURE_SETTING_MENU

/*
    framework/base/core/res/res/config.xml
    network location provider 설정변경 
    초기값이 null 로 되어있어 wifi, cell 기반 위치측위가 안됨.
*/
#define FEATURE_SKY_CP_NETWORK_LOCATION_PROVIDER_SETTING

/*
   SKT requirement. ( 국내 발신용. )
   *23# 과 같은 feature code를 사용한 호발신이 sups. service로 인식되지 않도록 함.
*/
#define FEATURE_SKT_CP_SUPS_SERVICE_REQUEST

/* Roaming Dual Clock 과 RAD 설정을 위한 이벤트 발생. */
#define FEATURE_SKT_CP_EVENT_TIME_AND_RAD

/* lockscreen에서 긴급호 버튼, 문구 등의 표시및 위치 조정을 위한 구성. */
#define FEATURE_SKT_CP_EMERGENCY_BUTTON_LOCKSCREEN

/* 
   블루투스 인증관련 수정사항.
   A와 B가 통화중 C에서 전화가 왔을때 A와 B의 통화를 중단하면 C가 자동으로 연결되어 
   문제가 됨.  Alert상태를 유지하도록 수정.
*/
#define FEATURE_SKY_CP_BLUEBOOTH_CERTIFICATION

/* USIM PUK permanent block 처리를 위한 추가사항  */
#define FEATURE_SKY_CP_ADD_PERM_BLOCKED_CARD_STATUS

/*
    Absend, Ready, Error 등의 card state를 return받기 위한 interface
    망으로부터 ilegal MS: Reject (3)을 받는 USIM인 경우 원본소스는 SIM_STATE UNKNOWN이지만 STATE를 READY로 수정.
*/
#define FEATURE_SKY_CP_GET_ICC_CARD_STATE

/* 위치및 보안 메뉴 설정에서 AGPS( GPS 도우미 사용 ) 설정시 경고팝업 */
#define FEATURE_SKT_CP_ALERT_FOR_USING_AGPS

/*  
   Airplane mode 진입시 network mode menu 진입이 순간적으로 진입이 가능해지는 문제 발생  
   이전 EF30S의 이전 버전의 경우 service state를 보고서 airplane mode check box를 
   disable 시키도록 하는 부분이   존재..하지만 현재 버전에는 해당 부분 없음...
   EF30S 소스기반으로 해당 함수 수정 이후 6140도 해당 부분이  존재 하지 않음..
*/
#define FEATURE_SKY_CP_AIRPLANE_MODE_CHECK_BOX_CONTROL

/*
  PLMN Selection 설정 상태가 Manual 상태에서 FPLMN에 있는 망 ( KT망 선택)
  을 선택해서 reject을 받고 단말을 재부팅하면 RPLMN(SKT) 으로 등록을 한후
  곧바로 이전에 reject 받았던 망으로 재등록을 시도하는것을 방지.
*/
#define FEATURE_SKY_CP_BLOCK_RESTORING_NETWORK_SELECTION

#endif/* __CUST_SKY_CP_H__ */
