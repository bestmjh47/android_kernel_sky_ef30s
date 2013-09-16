#ifndef __CUST_SKY_CP_H__
#define __CUST_SKY_CP_H__
/*****************************************************
    SKY Android �� ���� �������
    Feature Name : T_SKY_MODEL_TARGET_COMMON
******************************************************/
#ifdef T_SKY_MODEL_TARGET_COMMON

/*
    DDMS Log�� radio log �� �����ֵ��� ��. 
    Test ���Ǹ� ���� ����ϴ� ���̱� ������
    envsetup.mk �� TARGET_BUILD_VARIANT �� user ( user mode compile )
    �϶� �� FEATURE_AARM_RELEASE_MODE �� define��.
     (PS1�� �۾� �ʼ�: cust_sky.h �� ��뿩�� Ȯ��.)
    android/system/core/liblog/logd_write.c
*/
#ifndef FEATURE_AARM_RELEASE_MODE
#define FEATURE_SKY_CP_RADIO_LOG_DDMS
#endif/* FEATURE_AARM_RELEASE_MODE */

/*
   Qualcomm OEM Hook ����� �̿��� Ȯ��.  ( NV access, SIM access etc..)
*/
#define FEATURE_SKY_CP_QCRILHOOK_INTERFACE

#ifdef FEATURE_SKY_CP_QCRILHOOK_INTERFACE
/* oemhook�� qcril���� error exceptionó���� ���� ����. */
#define FEATURE_SKY_CP_EXCEPTION_DEFINITION

#define FEATURE_SKY_QCRILHOOK_EVENT_PROCESSED_BY_SUB_THREAD

/* OEM Hook ������� SIM access�� GSDI�� �̿��Ҷ� sync������� access�ϱ� ���� I/F */
#define FEATURE_SKY_CP_GSDI_SYNC_ACCESS_BY_REMOTE_PROCESSOR
#endif/* FEATURE_SKY_CP_QCRILHOOK_INTERFACE */

/* 
   SkyTelephonyInterfaceManager.java, Service_Manager.c, ISkyTelephony.aidl 
*/
#define FEATURE_SKY_CP_TELEPHONYMANAGER
#ifdef FEATURE_SKY_CP_TELEPHONYMANAGER
/* Java���� Modem API ȣ���� ���� Daemon ( NV access, �ڵ�����, VE ���, etc.. ) */
#define FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE
#ifdef FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE
/* Voice Call connection sound event */
#define FEATURE_SKY_CP_CS_CALL_CONNECTION_SND_START

/* SKY �ڵ������� Interface */
#define FEATURE_SKY_CP_AUTOANSWER_INTERFACE
#endif/* FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE */
#endif/* FEATURE_SKY_CP_TELEPHONYMANAGER */

/*
   Qualcomm Feature [FEATURE_QCRIL_UIM_QMI] ���
*/
#define FEATURE_SKY_CP_SUPPORT_FEATURE_QCRIL_UIM_QMI
#ifdef FEATURE_SKY_CP_SUPPORT_FEATURE_QCRIL_UIM_QMI
/* qcril ���� mmgsdi �� gsdi function ���� RPC callback �� �ʿ���. */
#define FEATURE_SKY_CP_GSDI_RPC_CALLBACK_SUPPORT
#endif/* FEATURE_SKY_CP_SUPPORT_FEATURE_QCRIL_UIM_QMI */


/* UMTS PS/CS Domain setting menu support */
#define FEATURE_SKY_CP_SERVICE_DOMAIN_CHANGE_CMD

/* UMTS SMS MO PS/CS Domain setting menu support */
#define FEATURE_SKY_CP_SMS_CFG_SET_GW_DOMAIN

/* Phone Operation Mode setting (lpm, offline, online .. ) */
#define FEATURE_SKY_CP_PHONE_OPERATION_MODE

/* RIL state �� ������� �׻� ril socket open���¿����� RIL_REQUEST_XXX �� �����ϵ��� ��. */
#define FEATURE_SKY_CP_FORCE_ALLOW_RIL_REQUEST

/* SKT ���� �÷��� ���� Interface */
#define FEATURE_SKT_CP_VE_SUPPORT

/*
    network ����� �Ϸ�� �� 10���Ŀ� property�� �����Ͽ� lcd on/off �� ���ؼ� cm event reg/dereg �� 
    �����ϵ��� �Ѵ�.  �ð� ������Ʈ ����....
*/
#define FEATURE_SKY_CP_TIME_UPDATE_ABSOLUTELY_ON_BOOT

#endif/* T_SKY_MODEL_TARGET_COMMON */


/* ######################################################################### */



/*****************************************************
    SKT/KT ���� �������
    Feature Name : T_SKY_MODEL_TARGET_WCDMA
******************************************************/
#ifdef T_SKY_MODEL_TARGET_WCDMA

/* OEM RAPI �� �̿��ϱ� ���� Protocol Feature */
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
/* OEM Hook ������� NV access */
#define FEATURE_SKY_CP_NV_ACCESS_OEMHOOK

#ifdef FEATURE_SKY_CP_LOCAL_DB
/* OEM Hook ������� Local DB access */
#define FEATURE_SKY_CP_LOCAL_DB_ACCESS_OEMHOOK
#endif/* FEATURE_SKY_CP_LOCAL_DB */
#endif/* FEATURE_SKY_CP_QCRILHOOK_INTERFACE */

#ifdef FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE
/* cpmgrif.c daemon�� ���� NV Access */
#define FEATURE_SKY_CP_NV_ACCESS_CPMGRIF

#ifdef FEATURE_SKY_CP_LOCAL_DB
/* cpmgrif.c daemon�� ���� Local DB Access */
#define FEATURE_SKY_CP_LOCAL_DB_ACCESS_CPMGRIF
#endif/* FEATURE_SKY_CP_LOCAL_DB */
#endif/* FEATURE_SKY_CP_MANAGER_DAEMON_INTERFACE */

/*
    SKT/KT ���� Me Personalization ( With QMI interface )
*/
#define FEATURE_SKY_USIM_ME_PERSONALIZATION

/* 
   1. qcril ���� default voice tech.�� 3GPP2�� �̴� 3GPP�� ����.
     --> ���� �ʱ⿡ 3GPP2�� radio technology�� õ�̵Ǿ��ٰ� 3GPP�� �ٲ� 3GPP2�� CDMA SIM ���� SIM ready�� 
            �߻��Ͽ� PUK�� PIN ������ ����� �ȵǰų� SIM Record�Լ����� CDMA������ �����ϴ� ��찡 �߻���.
   2. java class���� Phone type�� GSMPhone���� create �ǵ��� ������.
*/
#define FEATURE_SKY_CP_DEFAULT_NETWORK_UMTS_IN_RIL


/*
    -. WMS Link control�� ����ϸ� MMS app.�� ���� �߽� �� ������ �Ѱܹ޾� WMS���� ó���ϵ��� RIL I/F ����
*/
#define FEATURE_SKY_CP_MULTI_SMS_REQUIREMENT

/* CNAP ������ ���� RIL �� framework ����. */
#define FEATURE_SKY_CP_CNAP_SUPPORT
#ifdef FEATURE_SKY_CP_CNAP_SUPPORT
/* CNAP ���� �� call state�� ����Ǹ� ���� call�� ���� ������ �Ҽ� ���� ���·� �ȴ�. */
#define FEATURE_SKY_CP_CNAP_STATE_BUG_FIX
#endif

/* ���� ����� (SKT, KT) ������ KSC5601 format�� USSD msg.�� CNAP ������ ���� ����. */
#define FEATURE_SKY_CP_USSD_CNAP_8BIT_CHAR_SUPPORT

/* WCDMA, GSM �� RSSI level ���� ����,  H/W ��û�� ���� ���� */
#define FEATURE_SKY_CP_GW_RSSI_LEVEL

/* 
    RSSI report �� �������� �̷�� �� �� �ֵ��� delta threadhold ���� ����
    modem�ڵ忡�� cmph.h �� ���� ����.
 */
#define FEATURE_SKY_CP_RSSI_REPORT_VARIATION_FIX

/*
- Limited Service���¿����� RSSI Bar�� ������ 0���� ǥ���ϵ��� ����.
- SIM���� ���õǰų� �����ʱ� reject���� limited service�� �����Ǹ� no service�� �νĵǱ� ������ 
   qcril_cm.c ���� qcril_cm_util_srv_sys_info_to_reg_state() �Լ��� limited service �� �������ִ� ���� ������ �ʿ���.
*/
#define FEATURE_SKY_CP_RSSI_BAR_ZERO_DISPLAY

/*
   ���� ���� ������ MCC/MNC �� update �Ǵ� �κ��� Limited service���¿����� update�� �����ϵ��� ������.
*/
#define FEATURE_SKY_CP_GET_MCCMNC_UPDATE_IN_LIMITED_SRV

/* �ܸ� PS ONLY ���� ������ android�ܿ��� Reg state�� No Service�� ó���ϴ� ������ ���� */
#define FEATURE_SKY_CP_SUPPORT_PS_ONLY_MODE

/* qcril ���� ui �� �ö󰡴� reg_status�� ������ �־� �̸� ������ */
#define FEATURE_SKY_CP_REG_STATUS_UPDATE_CORRECTION

/*
   -. �ܸ��� service status�� SYS_SRV_STATUS_PWR_SAVE �϶� QCRIL_CM_SCREEN_STATE_ON ���°� �ɶ� ��
      Key interrup �߻����� LCD�� on�ɶ� �ܸ��� power save���¶�� modem�� wakeup��Ű���� �ǳ�, 
      qualcomm bug�� ���� �ȵǴ� ���� ���� 
*/
#define FEATURE_SKY_CP_MODEM_PWR_SAVE_WAKEUP_FIX

/*
   -. card power down Ŀ�ǵ� ó������ �ʵ��� ��.
      < �� ������ �߻��ϴ� �ֿ� ������ >
      1. ������ ��� ���Խ� USIM card access���� �ʴ� ����
      2. ������ ��� ���Խ� SIM card�� �νĵ��� �ʴ´ٴ� ���� ǥ�õ�.
      3. on chip sim mode�� ������ ������ ��� ���� card�� ���� ���¿��� UIM���� card power downĿ�ǵ尡 ���޵Ǿ�
*/
#define FEATURE_SKY_CP_CARD_POWER_DOWN_NOT_SUPPORT

/*
   ��ȭ�� ����� ������ ���� Setup ind. ���� signal value�� ������.
   AMSS���� FEATURE_SKY_CP_SETUP_IND_SIGNAL_VALUE �� �ݵ�� �����Ǿ�� ��.
*/   
#define FEATURE_SKY_CP_SETUP_IND_SIGNAL_VALUE

/*
   ETC(���濬��) ���� ����� call end�� ���ؼ� CM_EVENT_CALL_MNG_CALLS_CONF �� ó������ ���ϰ� 
   pending�Ǿ� �ִ°�� call endȭ�� ó���� ���� ���ϰ� ���� ���� �˾��� �߻��ϴ� ���� ����.
*/
#define FEATURE_SKY_CP_ETC_BUG_FIX

/*
    ������ release�� ���Ź��� ���ϴ� ��Ȳ���� Call END �õ��� call ȭ���� ����ؼ� in call���¸� �����ϴ� ���� ����.
    ���� ������������ ����� �������� ȣ����� call end�� ��ٸ��� �ʰ� call_end_req Ŀ�ǵ� �̺�Ʈ �߻��� call ȭ���� ������ �� �ֵ��� ��.
    A + B ( active ) , B + C ( hold ) ���¿��� A�� ȣ���� �ϴ� �������� B�� ȣ�� �����ϸ� android �� call state�� ril�� call state�� 
    ���̴� ��찡 �߻���.
    Disconnect ���� release procedure�� LG���� �Ｚ���� ���̰� �־ KT�� ��� ��ǳ��, �ͻ� �� �Ｚ������ �����ؾ� ��.
*/
#define FEATURE_SKY_CP_CALL_END_REQ_FOR_UI_CLEAN

/* 
  Network preferred mode ���� Menu
  Automatic, WCDMA only, GSM only
  ���������� �޴� ���� ���ϵ��� ����.
*/
#define FEATURE_SKY_CP_PREFERRED_NETWORK_MODE_SELECTION

/** GPS Feature **/
#define FEATURE_SKY_CP_GPS_TEST_SUPPORT

/* SIM �� ���� �ν� ���ο� ���¸� �˾ƺ������� �׽�Ʈ �ڵ� */
#define FEATURE_SKY_USIM_CARD_STATUS_PROPERTY
#endif/* T_SKY_MODEL_TARGET_WCDMA */


/* ######################################################################### */


/*****************************************************
    SKT �� �������
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
/* gps.conf ���Ͽ� SUPL. host������ google�� ����. */
#define FEATURE_SKT_CP_GOOGLE_SUPL_SUPPORT
#endif/* FEATURE_SKT_CP_GPS_REQUIREMENT_ANDROID */

/* Network �ڵ�����,�������� �׸� �Ʒ��� ���� ������ ( RAT, PLMN, name ) �� ǥ���� */
#define FEATURE_SKT_CP_NETWOTK_INFO_DISPLAY

/* SKT ����ڿ� PLMN Table */
#define FEATURE_SKT_CP_PLMN_TABLE_LIST_SEARCH

/* SKT IOT Problem fix.
    PLMN�� network name �� property�� ����Ǿ� RTS ������ 
    MM info.�� network name ���� / ������ ���迡�� fail�Ǵ� ����.
*/
#define FEATURE_SKT_CP_INIT_NITZ_INFO_PROPERTY

/* SKT �ѹ��÷��� ���� ���� */
#define FEATURE_SKT_CP_NUMBER_PLUS_SUPPORT

/*
  reg reject ���� ǥ�� �����ϵ��� system property �� ������.
  reg reject ������ keyguard ȭ�鿡 ǥ�õǵ��� ��.
  AMSS���� feature : FEATURE_SKY_CP_REJECT_CAUSE_DISPLAY
  reject cause������ ServiceState ���� �ϵ��� ����.
*/
#define FEATURE_SKT_CP_REJECT_CAUSE_DISPLAY

/*
   SKT�� PLMN Selection(�ڵ�/����) ���� ��������.
*/
#define FEATURE_SKT_CP_NETWORK_PLMN_MANUAL_SELECTION

/* 
   IMEI mismatch Lock applet �����δ� ���� Lock �� �ɸ��� �ʱ� ������
   USIM Lock�� ���ؼ� �߰� 
 */
#define FEATURE_SKT_USIM_IMEI_LOCK

#endif/* T_SKY_MODEL_TARGET_SKT */


/* ######################################################################### */


/*****************************************************
    KT �� �������
    Feature Name : T_SKY_MODEL_TARGET_KT
******************************************************/
#ifdef T_SKY_MODEL_TARGET_KT

#ifdef T_SKY_MODEL_TARGET_SKT
#error Occured !!  This section is KT only !!
#endif


#endif/* T_SKY_MODEL_TARGET_KT */





/***********************************************************
   JAVA code���� ����� Feature �� code Ȯ�ο�...
   ������ C/C++ �ڵ忡�� ������� �ʴ� �������� 
   �ڵ� �˻��� Ȯ�ο뵵�� ����ϱ� ����.
************************************************************/

/* import ���̳� ���� ��ɿ� �������� ���� �ڵ� ǥ�� */
#define FEATURE_SKY_CP_COMMON_JAVA_DECLARATION

/* EF File ������ Path �� �̿��ϱ� ���ؼ� ���� �ڵ� */
#define FEATURE_SKY_USIM_EF_FILE_ACCESS_BY_PATH

/* USIM Card ���Ž� ����� noti. */
#define FEATURE_SKY_CP_CARD_REMOVED

/* �ιֻ��¿��� UI���� ������ ���� fake roaming setting */
#define FEATURE_SKY_CP_ANDROID_FAKE_ROAMING_SETTING

/* Hidden Code ����. �� ���ʿ��� code���� ����. */
#define FEATURE_SKY_CP_HIDDEN_CODE_CONTROL

/* SKT USIM���� UA Field������ �ʿ��� MIN/IRM ����. */
#define FEATURE_SKT_CP_CDMA_MIN_EF_ACCESS

/* GCF mode ���� ���� */
#define FEATURE_SKT_CP_CHECK_GCF_MODE

/* 
   android Settings.DEVICE_PROVISIONED �� �׻� 1�� �����Ǿ��ֵ��� ��. 
   ���� �ʱ⿡ GSM ���� ���Ž� ���� �źεǾ� �׽�Ʈ ���࿡ ������ �߱� ��Ŵ..
*/
#define FEATURE_SKY_CP_DISABLE_CHECK_DEVICE_PROVISIONED

/* Limited service���¸� �����ϱ� ���ؼ� ServiceState ����. */
#define FEATURE_SKY_CP_SERVICE_STATUS_DETAIL_SUBSTATE

/* Qualcomm Auto Answer ���� ���� ����. ( SKY �ڵ������� �ƴ� !!) */
#define FEATURE_SKY_CP_AUTO_ANSWER_BUG_FIX

/* SKT Emergency Call requirement. */
#define FEATURE_SKT_CP_CHECK_EMERGENCY_CALL

/* ��Ʈ������ ǥ�� ��� - Short Name ǥ�� �켱. */
#define FEATURE_SKT_CP_DISPLAY_NETWORK_NAME

/* ������ ��� ���� �� �ܸ� ����� �� ������ ��尡 ���� �ǵ��� ��. */
#define FEATURE_SKY_CP_AIRPLANE_MODE_RELEASE_AFTER_BOOT

/* Roming indicatorǥ�� ���� ����. */
#define FEATURE_SKY_CP_UPDATING_ROAMING_INDICATOR


/* Lock Screen�� ǥ�õǴ� network name on-off ���  */
#define FEATURE_SKT_CP_NETWORK_NAME_DISPLAY_ONOFF

/* SIM state check ���� ����. patch�� �ش� �ڵ� Ȯ�ο��. */
#define FEATURE_SKY_USIM_GET_SIM_STATE

/* 
   Power off ������ PS�� release�Ǳ� ���� android power off sequence�� �Ϸ�Ǿ� 
   ������ Detach�� �ø��� ���ϴ� ��찡 �־� ������ 1�� ���� delay��Ŵ.
*/
#define FEATURE_SKY_CP_DELAYED_POWER_OFF

/* �ȵ���̵� �޴��󿡼� IMEI �� Ȯ���Ҽ� ������ ��.  */
#define FEATURE_SKY_CP_DEVICE_ID_NO_DISPLAY

/* KT SIM MSISDNǥ�� �� SKT SIM MSISDN ǥ������ ����. */
#define FEATURE_SKY_CP_DISPLAY_PHONE_NUMBER_WITH_TOA

/* Android Setting �޴����� ��ȭ���� �޴� ����.  */
#define FEATURE_SKY_CP_REMOVE_ANDROID_CALL_FEATURE_SETTING_MENU

/*
    framework/base/core/res/res/config.xml
    network location provider �������� 
    �ʱⰪ�� null �� �Ǿ��־� wifi, cell ��� ��ġ������ �ȵ�.
*/
#define FEATURE_SKY_CP_NETWORK_LOCATION_PROVIDER_SETTING

/*
   SKT requirement. ( ���� �߽ſ�. )
   *23# �� ���� feature code�� ����� ȣ�߽��� sups. service�� �νĵ��� �ʵ��� ��.
*/
#define FEATURE_SKT_CP_SUPS_SERVICE_REQUEST

/* Roaming Dual Clock �� RAD ������ ���� �̺�Ʈ �߻�. */
#define FEATURE_SKT_CP_EVENT_TIME_AND_RAD

/* lockscreen���� ���ȣ ��ư, ���� ���� ǥ�ù� ��ġ ������ ���� ����. */
#define FEATURE_SKT_CP_EMERGENCY_BUTTON_LOCKSCREEN

/* 
   ������� �������� ��������.
   A�� B�� ��ȭ�� C���� ��ȭ�� ������ A�� B�� ��ȭ�� �ߴ��ϸ� C�� �ڵ����� ����Ǿ� 
   ������ ��.  Alert���¸� �����ϵ��� ����.
*/
#define FEATURE_SKY_CP_BLUEBOOTH_CERTIFICATION

/* USIM PUK permanent block ó���� ���� �߰�����  */
#define FEATURE_SKY_CP_ADD_PERM_BLOCKED_CARD_STATUS

/*
    Absend, Ready, Error ���� card state�� return�ޱ� ���� interface
    �����κ��� ilegal MS: Reject (3)�� �޴� USIM�� ��� �����ҽ��� SIM_STATE UNKNOWN������ STATE�� READY�� ����.
*/
#define FEATURE_SKY_CP_GET_ICC_CARD_STATE

/* ��ġ�� ���� �޴� �������� AGPS( GPS ����� ��� ) ������ ����˾� */
#define FEATURE_SKT_CP_ALERT_FOR_USING_AGPS

/*  
   Airplane mode ���Խ� network mode menu ������ ���������� ������ ���������� ���� �߻�  
   ���� EF30S�� ���� ������ ��� service state�� ���� airplane mode check box�� 
   disable ��Ű���� �ϴ� �κ���   ����..������ ���� �������� �ش� �κ� ����...
   EF30S �ҽ�������� �ش� �Լ� ���� ���� 6140�� �ش� �κ���  ���� ���� ����..
*/
#define FEATURE_SKY_CP_AIRPLANE_MODE_CHECK_BOX_CONTROL

/*
  PLMN Selection ���� ���°� Manual ���¿��� FPLMN�� �ִ� �� ( KT�� ����)
  �� �����ؼ� reject�� �ް� �ܸ��� ������ϸ� RPLMN(SKT) ���� ����� ����
  ��ٷ� ������ reject �޾Ҵ� ������ ������ �õ��ϴ°��� ����.
*/
#define FEATURE_SKY_CP_BLOCK_RESTORING_NETWORK_SELECTION

#endif/* __CUST_SKY_CP_H__ */
