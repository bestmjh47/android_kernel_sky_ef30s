#ifndef __CUST_SKYCAM_H__
#define __CUST_SKYCAM_H__

/*
Modified files which have "SKYCAM" tag:
	android/build/core/Makefile
	android/kernel/arch/arm/configs/qsd8650_defconfig
	android/kernel/drivers/media/video/msm/Kconfig
	android/kernel/drivers/media/video/msm/Makefile
	android/vendor/qcom/android-open/libcamera2/Android.mk
	android/vendor/qcom-proprietary/mm-camera/Android.mk
	android/vendor/qcom-proprietary/mm-camera/camera.mk
	android/vendor/qcom-proprietary/mm-camera/targets/Android.mk

Modified files which don't have "SKYCAM" tag:
	android/kernel/drivers/media/video/msm/mt9p111.h
	android/kernel/drivers/media/video/msm/mt9p111_reg.c
	android/vendor/qcom-proprietary/mm-camera/targets/tgtcommon/sensor/mt9p111/mt9p111.h
	android/kernel/drivers/media/video/msm/yacbac1sddas.h
	android/kernel/drivers/media/video/msm/yacbac1sddas_reg.c
	android/vendor/qcom-proprietary/mm-camera/targets/tgtcommon/sensor/yacbac1sddas/yacbac1sddas.h

Local features:
	CONFIG_MSM_CAMERA_DEBUG (MSM_CAMERA_DEBUG)
	CONFIG_SKYCAM_MT9P111 (SKYCAM_MT9P111)
	F_SKYCAM_SENSOR_MT9P111
	CONFIG_SKYCAM_YACBAC1SDDAS (SKYCAM_YACBAC1SDDAS)
	F_SKYCAM_SENSOR_YACBAC1SDDAS
	F_SKYCAM_LOG_VERBOSE (enable LOGV/LOGD/LOGI in userspace)
	F_SKYCAM_LOG_CDBG (enable CDBG in userspace)
	F_SKYCAM_LOG_OEM (enable SKYCDBG/SKYCERR in userspace)

How to turn off all camera logs (kernel/userspace):
	android/kernel/arch/arm/config/qsd8650-defconfig
		- CONFIG_MSM_CAMERA_DEBUG -> no (default)
	Disable F_SKYCAM_LOG_PRINTK (default enabled)
	Find all F_SKYCAM_LOG_OEM,
		- comment out (default)
	Find all F_SKYCAM_LOG_CDBG
		- comment out (default)
	Find all F_SKYCAM_LOG_VERBOSE
		- comment out (default)

How to exclude module "MT9P111":
	android/kernel/arch/arm/config/msm7630_defconfig
		- disable CONFIG_MT9P111
	android/vendor/qcom-proprietary/mm-camera/Android.mk
	android/vendor/qcom-proprietary/mm-camera/camera.mk
		- CONFIG_MT9P111=no (default yes)

How to exclude module "OLAWORKS":



(2)  ī�޶� ���� ��� kernel/userspace/android �α׸� ����

kernel/arch/arm/config/qsd8650-perf_defconfig �� �����Ѵ�.

	# CONFIG_MSM_CAMERA_DEBUG is not set (default)

CUST_SKYCAM.h ���� F_SKYCAM_LOG_PRINTK �� #undef �Ѵ�.

	#define F_SKYCAM_LOG_PRINTK (default)

��� �ҽ� ���Ͽ��� F_SKYCAM_LOG_OEM �� ã�� �ּ� ó���Ѵ�.
	���� �� ���, �ش� ���Ͽ� ���� SKYCDBG/SKYCERR ��ũ�θ� �̿���
	�޽������� Ȱ��ȭ ��Ų��. (user-space only)

��� �ҽ� ���Ͽ��� F_SKYCAM_LOG_CDBG �� ã�� �ּ� ó���Ѵ�.
	���� �� ���, �ش� ���Ͽ� ���� CDBG ��ũ�θ� �̿��� �޽�������
	Ȱ��ȭ ��Ų��. (user-space only)

��� �ҽ� ���Ͽ��� F_SKYCAM_LOG_VERBOSE �� ã�� �ּ� ó���Ѵ�.
	���� �� ���, �ش� ���Ͽ� ���� LOGV/LOGD/LOGI ��ũ�θ� �̿���
	�޽������� Ȱ��ȭ ��Ų��. (user-space only)


(4)  �ȸ��ν� ���� ��� ���� ȯ��

vendor/qcom/android-open/libcamera2/Android.mk �� �����Ѵ�.
	3rd PARTY �ַ�� ��� ���θ� �����Ѵ�.

	SKYCAM_FD_ENGINE := 0		������
	SKYCAM_FD_ENGINE := 1		�ö���� �ַ�� ���
	SKYCAM_FD_ENGINE := 2		��Ÿ �ַ�� ���

CUST_SKYCAM.h ���� F_SKYCAM_ADD_CFG_FACE_FILTER �� #undef �Ѵ�.
	�ȸ��ν� ��� ���� �������̽� ���� ���θ� �����Ѵ�.

libOlaEngine.so �� ���� libcamera.so �� ��ũ�ϹǷ� ���� ��� libcamera.so ��
ũ�Ⱑ �����Ͽ� ��ũ ������ �߻� �����ϸ�, �� ��� �Ʒ� ���ϵ鿡��
liboemcamera.so �� ������ �ٿ� libcamera.so �� ������ Ȯ���� �� �ִ�.

build/core/prelink-linux-arm-2G.map (for 2G/2G)
build/core/prelink-linux-arm.map (for 1G/3G)

2010-10-04  �ö���� ���̺귯�� �� �ҽ��ڵ� ������Ʈ

*/


/* ���� CS �μ������� �Һ��� �÷� �м��� ���� ���� PC ���α׷��� ����Ͽ�
 * ī�޶� ���� �ð� ������ PC �� �����Ѵ�.
 *
 * ���� ����� ���� Ŀ�ǵ� ��缭�� ��õǾ� �����Ƿ� ���� �ڵ���� ���� Ŀ�ǵ�
 * ���� ��⿡ ���ԵǾ� ������, ���� Ŀ�ǵ� �� PC ���α׷��� ������� �ʰ� ����
 * ���α׷��� ����Ͽ�, �÷��� DIAG ��Ʈ�κ��� ���� �ð� ������ Ȯ���� �� �ִ�.
 *
 * ���� Ŀ�ǵ� ��缭 v10.35 ��� ����
 * PhoneInfoDisplay v4.0 ���α׷����� Ȯ��
 * ��缭�� ���α׷��� DS2�� �ڰ�ȣ ���ӿ��� ���� */
#define F_SKYCAM_FACTORY_PROC_CMD

/*========================================================
 * SKYCAM Lee Jitae 2010-11-09
 * ī�޶� ANR�߻��̳� Device�̻����� open fail�� �Ͼ� �� ��� �������� �������� ����
 * cameraservice connectó�� �� vfe reset�ڵ� �۾�
 *F_SKYCAM_INVALIDATE_CAMERA_CLIENT feature�� �̹� �� �־���
======================================================== */
/* ī�޶� ��ġ ���� OPEN �� ������ ��� (�ܼ� I2C ���� R/W ����, ī�޶� ������)
 * ���� ó���� ���� �����Ѵ�.
 *
 * ��ġ ������ OPEN �ϴ� �������� VFE �ʱ�ȭ ���� ī�޶� HW �ʱ�ȭ�� �̷��
 * ���µ�, HW �ʱ�ȭ�� ������ ��� VFE �� �ʱ�ȭ �� ���·� ���Եǰ� ����
 * OPEN �õ� �� HW �ʱ�ȭ�� �����Ѵ� �ϴ��� �̹� VFE �� �ʱ�ȭ�� �����̹Ƿ�
 * VFE �ʱ�ȭ �� ������ �߻��Ѵ�.
 *
 * ȣ����� : vfefn.vfe_init() -> sctrl.s_init()
 *
 * HW �ʱ�ȭ�� ������ ���, �̹� �ʱ�ȭ�� VFE �� RELEASE (vfe_release) ����
 * ���� ���� �õ� �� ���� �����ϵ��� �����Ѵ�.
 *
 * ECLAIR ���������� ���� ���� ���� ó������ �ұ��ϰ� ������ ����Ǿ� ����
 * �ʰų� ���� �ϵ��� �̻��� �߻��� ��� ī�޶� ������ ANR ������ ����
 * ������ ����ǰ� ���� ����� �������� �����Ͽ� �������� �Ұ����ϴ�.
 *
 * ������ �� ������ ���, ISP �ʱ�ȭ �� ISP �� ������ ������ ���� �����ϴ�
 * �������� 3�� �� POLLING �����ϸ�, �̷� ���� Ÿ�Ӿƿ� �߻��ϰ� ANR ������
 * �̾�����. �� ���� ���� ���� ī�޶� ������ �� ������ �����̶� �ϴ��� ANR
 * ���� ���� ������ �� ���������� ����Ǿ����Ƿ� FRAMEWORK ���δ� �� ������
 * ���·� �����ǰ�, �̷� ���� ����� �������� ī�޶� ���� ���� �� "Unable to
 * connect camera device" �˾��� �Բ� ������ ���Կ� �����Ѵ�.
 *
 * ISP �ʱ�ȭ �� ������ ��� ���� ������, ISP �� ���� ������ Ư�� �������͸�
 * 1ȸ READ �ϰ� �� ������ ���, �̸� FRAMWORK �� ���� �������� �����Ͽ�
 * ���������� ����ǵ��� �����Ѵ�.
 *
 * ���� ISP ��ü�� �̻��� �߻��� ��쿡��, PROBE �ÿ� ���� �߻��Ͽ� �ش�
 * ����̽� ���ϵ��� ������ �� �����Ƿ� FRAMWORK ���ο��� �Բ� ó�� �����ϴ�. */
#define F_SKYCAM_INVALIDATE_CAMERA_CLIENT


/* SKYCAM Lee Jitae 2010-11-12
 *  Antina sensor Mt9p111���� ��ȭ ���� �߻�
 * OTP����̵� ���� 1�̶�� �ν��ϴ� ���۷��� ��Ƽ���� �����ϴ� ��������
 * ��Ȯ�� ���� Antina���� ������ ���� ����
 * ���� ���� ������ ��ȭ ������ �߻��ϴ� ����� ���´� (EF13S���� ���� ������) EF18K������ �Ѱ� �߰��ؼ� ���� ������ ��
 */
#define F_SKYCAM_SENSOR_BUG

/* SKYCAM Lee Jitae 2010-11-12
 * MSM7X30, MSM8x55���� 2030��ġ ���� �������� ������ �ؿ� ���� ���� ��Ÿ����.
 * �̰��� ��ġ�ϴ� ����. ������, Assemble�����̱� ������ ���⼭ ���Ǹ� �س���
 * ���������δ� �ּ����� �����ִ�. �˻����� ã�� ��, ��ġ��
 * LINUX\android\external\libpng\contrib\pngneon\png_read_filter_row_neon.s  �̴�.
 */
#define F_SKYCAM_LIBPNG_ERROR

#define F_SKYCAM_LOG_DEBUG

#define F_SKYCAM_EF18K

/* ī�޶� ���� GPIO ���� �����Ѵ�. 
 *
 * �� 12 ������ ������ �������� ���� 8��Ʈ�� ����Ѵ�. 
 *
 * ī�޶� HW ���� ������ SLEEP ���� ���� �浹 �� HW �̻� ������ �����ϱ� ����
 * SLEEP_CONFIGS[] ���� ī�޶� ���� GPIO ���� ��� ���ܽ�Ų��.
 *
 * VCM/FLUID ���� GPIO ���� ������� �����Ƿ� ���� �κ��� �����Ѵ�.
 *
 * ���� ���� ����
 * AMSS/products/7x30/core/systemdrivers/tlmm/src/bsp/7x30/TLMMBsp.c
 * AMSS/products/7x30/core/systemdrivers/tlmm/src/bsp/7x30/TLMMBspMsm.h */
#define F_SKYCAM_HW_GPIO

/* HW I2C ������ Ŭ���� �����Ѵ�. 
 *
 * MT9P111 �� ���, �ʱ�ȭ �� ���� ���� ���� �� WRITE �ؾ� �� ���������� ���� 
 * �����Ƿ� ���� ����� ���� �ִ� Ŭ���� ����Ѵ�. */
#define F_SKYCAM_CUST_I2C_CLK_FREQ

/*----------------------------------------------------------------------------*/
/*  MODEL-SPECIFIC                                                            */
/*  EF18K ���� ����Ǵ� �Ǵ� EF18K ������ ������ FEATURE ���                 */
/*----------------------------------------------------------------------------*/

#if defined(T_EF18K)	
#define F_SKYCAM_TARGET_EF18K
#endif
#if defined(T_EF30S)
#define F_SKYCAM_TARGET_EF30S
#endif

/*
 * ���� VREG ������� ���԰� i2c�� ���õǾ� ����
 *  F_SKYCAM_VREG�� F_SKYCAM_I2C_INIT�� �ٲ� ����
 */

#define F_SKYCAM

/* SKYCAM Lee Jitae 2010-10-06
 * ���ī�޶� ������ �κп��� VT ���õ� �κ��� �۾��� ���� �߰��ߴ�
 * ��� ī�޶� �������� QualcommCameraHardware���� CamID�� ������ �ϴµ� �� �κп���
 * 3,4���� VTī�޶�� �̿��ߴ�. DUAL CAM���� VT���� �κ��� �и�
 */
#define F_SKYCAM_ADD_VT_CAM

/* "ro.product.device" ���� �� �������� ���� �ڵ� �������� ���� ���� ī�޶�
 * ���� �ڵ�鿡���� �� ���� ���� �ʰų� 'TARGET_QSD8250' ���� �����Ѵ�.
 * �ý��� ���� "ro.product.device" �� ������ ������ ��� "qsd8250_surf" �̰�,
 * EF18K �� ��� "ef18k" ���� �����Ǿ� �ִ�. */
#define F_SKYCAM_CUST_TARGET_TYPE_7X30

/* SKYCAM Lee Jitae 2010-09-25
 * VPE�ǻ������ ���ؼ� ���� �������� �ö���� �ʴ� �������� �߻�
 * mDisEnabled�� �̻������ ���� �ذ�
 * mDisEnabled�� ��쿡�� BayerSensor�� ��쿡�� Enable�Ѵ�.
 * mDisEnabled �� DIS(Digital Image Stabilization) ����� ON- OFF�ϴ� ���̴�.
 */
 #define F_SKYCAM_VIDEO_FRAME_VPE

/* SKYCAM Lee Jitae 2010-12-11
 * ���� ������ LOGV/LOGD/LOGI �޼��� on off
*/
#define F_SKYCAM_LOG_VERBOSE


#define F_SKYCAM_LOG_PRINTK	//Ŀ�� ������ SKYCDBG/SKYCERR �޼��� on off
#define F_SKYCAM_LOG_OEM		//���� ������ SKYCDBG/SKYCERR �޼��� on off


/* ��ȭ ����/���� ��, ȿ������ �ش� ������ ���Ͽ� ��ȭ�Ǵ� ������ �ӽ� �����Ѵ�.
 *
 * ��ȭ ���� �ÿ��� ȿ���� ��� �Ϸ� �ñ��� POLLING �� ��ȭ�� �����ϰ�,
 * �Ϸ� �ÿ��� ��ȭ �Ϸ� ���� 800ms ���� DELAY ���� �� ȿ������ ����Ѵ�.
 *
 * R4070 ������ ��ȭ ���� �� ����� Ŭ���� �ʱ�ȭ�Ǵ� �ð��� ���� �ɷ�
 * �ټ��� �������� DROP �Ǹ鼭 ��ȭ �������� ���� �� ���ɼ��� ���������,
 * R4075 ���� �� �̽��� �����Ǹ鼭 ��ȭ ���� �� ȿ������ 100% Ȯ���� �����ǰ�,
 * ���� �� 80% �̻� Ȯ���� �����ȴ�.
 *
 * F_SKYCAM_TODO, QUALCOMM ���� Ȯ�� �� �����ؾ� �Ѵ�. (SR#307114) */
#define F_SKYCAM_QBUG_REC_BEEP_IS_RECORDED


/* �ٿ� ����� �ϱ� ���� �Լ��� ����ϱ� ���ؼ�,  ĸ�� ȭ���� �����ִ� ���� ĸ�� ȭ����  Ʋ�� ���� �����ϱ� ���ؼ�
 * ������� ������ �����������並 �����.
 * IPL ���̺귯���� �ִ� downsize�� �̿��ؼ� ���δ�.
 * ���� SR���� �� -> ���� ��ġ�� ���� �� �� �ֵ��� ���� �ޱ� ���ؼ� ���� ��
 */

/* #define F_SKYCAM_SNAPSHOT_PREVIEW  */


/* SKYCAM_PSJ_100513
 * ���� ī�޶��� �����並 90�� ȸ����Ű�� ���� �۾�
 * Surface�� ������ ����
 * cameraservice.cpp�� handlesutter�Լ��� ������ �� post view rotation�� ����� ��
 * MDP 3.1 ���Ͽ����� ���ȴ�.
 * MSM7230���ĺ��ʹ� MDP4.0�� ���Ǳ� ������ �ǹ̴� ���� �ʴ´�.
 */
/* #define F_SKYCAM_PREVIEW_ROTATION_FOR_SUBCAM */

/*
 * ���� ī�޶��� JPEG ���ڵ��� Rotation����
 */
#define F_SKYCAM_JPEG_ENCODE_ROTATION_FOR_SUBCAM

/*
 * �Ϲ� ī�޶� ����, ���� �� VTī�޶� ����� start preview fail���� ��Ȳ ����
 * picture size������ �ȵǸ� mDimension�� ������ ��� 0���� ���� set dimension fail���� ����
 */
/* SKYCAM Lee Jitae 2010-09-01
 *  VTī�޶� ������ �� ����Ʈ preview����� 800*480�� �ȴ�.
 *  �̰��� 176*144�� �����ϱ� ���� �۾�
 */
#define F_SKYCAM_VT_FIX_CAMERA_START_ERROR

/*
 * VT ����ī�޶� ����� preview size�� 176, 176���� �����ϹǷ� ����
 * �� ȭ�� 176, 144�� �������� ���� ����
 * preview size�� 176, 176���� �ϳ� receivePreviewFrame�Լ����� 176, 144�� crop�Ͽ� 90 rotate�ϰ� ���� �Ǿ���
 ******
 *  - SKYCAM Lee Jitae 2010-08-30 �߰�����MSM7x30,8x55 �迭 ����-
 * MDP4.0 �� ����ϸ鼭 ������ �߻��ϱ� �����Ѵ�.
 * EF13���� ���� ���̸� ������ ������ ����
 * ���� �׽�Ʈ�� ���� ����(2010-09-01) �׽�Ʈ �ʿ�
 */
 #define F_SKYCAM_VT_FIX_MAIN_CAM_PREVIEW_SIZE

 /*
 * pantech VT�� ȣ�� ����Ǹ� ���� ���۸� video ���۷κ��� ��� ���� start recording
 * �� �����ϸ� ���� connect/disconnect �ÿ� �Կ����� �߻��Ѵ�.
 * pantech VT���� �Կ����� �߻��ϴ� ���� ���� ���� CameraService�� 
 * CAMERA_CMD_SET_SHUTTER_DISABLE commad�� �߰� �Ͽ���.
*/
 #define F_SKYCAM_VT_SHUTTER_DISABLE

/*
 * VTī�޶� On/Off ����
*/
 #define F_SKYCAM_CFG_VT

 /* 
 * MEDIA_RECORDER_INFO_FILESIZE_PROGRESS CallBack, Only Use KT Phone 
 * KT�������� ���� ���� ����� ����ϴµ� ���� ����� APP�� �˷��ֱ� ���ؼ�
 * �߰� 
 */
#define F_SKYCAM_ADD_EVT_RECSIZE

 /* SKYCAM Lee Jitae 2010-08-30
 *  Main ī�޶� VT ������� 176 *176�� �����Ǿ� �ִ�.
 *  VT Overlay�� 176*144�� �������� ����. �̷��� ������ IPL ���̺귯����
 *  �̿��ؼ� ������� 90�� �����̼��� �ϰ� VT������ �÷� ������.
 *  receivePreview���� EF18K VTȭ���� ����Ѵ�. overlay�� setCrop�� �̿��ؼ�
 *  ȭ���� 176*144ȭ���� ������ش�. 144*176�� ������ 90�� ȸ���ϱ� �����̴�.
 *  runVideoThread������ IPL�� �̿��ؼ� 90�� ȸ�� �� memcpy�� �̿��ؼ� Y�� ������ CbCr���� ���Ŀ� �����Ѵ�.
 *  vframe�� ���� ���� �̹��� ������ �̹�������,  new�� �̿��ؼ� �޸� �Ҵ� �� 90��
 *  ���ư� �̹����� �־��ش�.
 *  2010-09-30 Froyo Update
 *  record-size �� �߰� �Ǿ���. initPreview���� Record size�� �����ϴ� �κ���  �ִ�.
 *  VT���� �ʿ��� ������� 176*144�̰� ���� �������� ���;��ϴ� ������� 176*176�ε�
 *  initPreview�� �߰� ���� �ڵ�� record size�� 176*144�� �����ؼ� ȭ���� ����� ������ �ʴ´�.
 *  �� �κ��� �ٽ� 176*176�� �� �� �ְ� ���ִ� �ڵ� �߰�
 */
#define F_SKYCAM_MAINCAM_VT_PREVIEW

/* SKYCAM Lee Jitae 2010-10-05
 * VGAī�޶󿡼� �������� �ʴ� Paramter�̴�.
 * ���� Paramter���ÿ� �Լ�����NO_ERROR�� ���������μ� �Ķ���� ������ ����.
 */
#define F_SKYCAM_VGA_NOT_SUPPORT_PARAMTER

/* SKYCAM Lee Jitae 2010-10-05
 * VT�� ��쿡�� YCrCb Inpu ���ڴ��� ����ϰ� ķ�ڴ��� ���� YCbCr Input ���ڴ��� ����Ѵ�.
 * MSM7227�� �����ϰ� VT������ �ϱ� ���ؼ� encoder input format�� �ٲپ� �ش�.
 */
#define F_SKYCAM_VT_ENCOER_FORMAT

/* EF18K ���� ���Ǵ� ī�޶� ���� ���̺� (�ִ� ��� ���� �ػ�, �ִ� ������
 * �ػ�, AF ���� ����) �� �����Ѵ�. */
#define F_SKYCAM_CUST_SENSOR_TYPE

/* Service�ܿ��� ���� connect�� ��������  ��� ���� ���ִ� �κ� �߰� */
#define F_SKYCAM_DEVICE_CONNECT_FAIL_FIXED

/* MSM�ܿ��� ���� control, config�� ��������  ��� ���� ���ִ� �κ� �߰� */
#define F_SKYCAM_FIX_MSM_OPEN_FAIL

/*
*camera id���� �˻��Ͽ� ���� app���� �ĸ� ī�޶�, ���� ī�޶� ���� ���۽� ���� �����ϰ� �Ǿ�
*���Խ� open�� ����� �ñ⿡ �ǰų�(ȨŰ long Ű, ��ȯ), setparameter�� ���õǴ� ������� �߻��Ͽ�,
*���� �ǵ����� ���� ���� ���� ������ �ϴ� ������
*froyo�� ���������� �� �ĸ� ��� ī�޶� ���� ī�޶� release �������� ���� �Ұ��ϵ��� ����
*
*HW, QCH ��� ������ ī�޶� ������ �����Ѵٸ� �Ʒ��� ������ �� �׽�Ʈ �� ��.
*/
#define F_SKYCAM_GB_ORIGIN_CONNECT

/* ī�޶� IOCTL Ŀ�ǵ� MSM_CAM_IOCTL_SENSOR_IO_CFG �� Ȯ���Ѵ�.
 *
 * EF10S ���� �߰��� ��� �� SOC ī�޶� �������� �ʰ� �̱����� �κе���
 * ���� �� �߰� �����Ѵ�. */
#define F_SKYCAM_CUST_MSM_CAMERA_CFG

/* SKYķ�ڴ� ��ȭ������ Qparser�� Ȯ�ν� �����߻�.(deocde thumnail�Ҽ�����)
 * ķ�ڴ� ���ڵ��� ����ķ�ڴ��� SKYķ�ڴ��� ������ �ϳ��� 
 * app���� �������� stagefrightrecorder�� mMaxFileDurationUs ���̴�.
 * (SKYķ�ڴ�: 3600000000(us)=1�ð� / ����ķ�ڴ�: 600000000(us)=10��.)
 * mMaxFileDurationUs�� ���̷����� Mpeg4write���� 
 * SKYķ�ڴ��� 64bitfileoffset / ����ķ�ڴ��� 32bitfileoffset�� ����ϰ� �ȴ�.
 * �̸� 32bitfileoffset���� �����ϰ� �����ϱ� ���ؼ� �ش�κ��� �����Ѵ�.
 * �ӽ÷� �����Ǵ� �κ��̹Ƿ� �߰� ���� �� �������� ����͸��� �ʿ���.
*/
#define F_SKYCAM_VIDEO_REC_FILEOFFSET

/*
 * ī�޶� ����̹��� ������ ������� �ʾ��� ��, suspend �Ǵ� ���� ���´�.
 * power control �� ���� Ŀ�� ����̹��� suspend �Ǵ� ���� ���´�.
 * �Ϲ����� ��� ī�޶� ������ ī�޶� ����̹��� ���� ��Ű��, �� �� Ŀ�� ����̹��� ��������.
 * HD ������ȭ�� ��� ���� ������ control�� �Ұ����� LCD�� OFF �Ǵ� ��Ȳ���� suspend�� �߻��Ѵ�.
 * �� �� Ŀ�� ����̹��� suspend ���� �ʵ��� �Ѵ�.
*/
#define F_SKYCAM_FIX_SUSPENDLOCK_ADD

/* ZOOM LEVEL �� 51 �̻��ΰ�� wide size ���� preview frame �� width/height ratio�� �޶�����.
 * zoom level 0~50 : 1.6666
 * zoom level 51 �̻� : width �� Ȯ�� ��.
 * zoom level 60 : 1.3333
 * R5040���� Qualcomm SBA �޾Ƽ� patch ����. ���� release�� ���� ���� Ȯ�� �� ���� �Ѵ�.
 */
#define F_SKYCAM_QBUG_ZOOM_MORE51

/* SKYCAM Lee Jitae 2010-10-05
 * QualcommCameraHardware.cpp���� setParameters�� VT�� ī�޶� ���õ� ������ �ȴ�. VT���� �ʿ���� ������ ���ϱ� ���ؼ�
 * ī�޶��϶��� �Ķ���� ������ �ϱ� ���ؼ� ������ �κ�
 * EF18K�ǰ�� �ʿ����� ���� ������ ifndef�� ���� �ξ���.
 */
#define F_SKYCAM_CAMERA_SETTING_ONLY

/* SKYCAM_PSJ_0100331 : ī�޶� Ʃ�� ���� �ε带 ����... */
/* #define F_SKYCAM_SENSOR_TUNEUP */
#ifdef F_SKYCAM_SENSOR_TUNEUP
#define F_SKYCAM_TUP_LOAD_FILE
#define MT9P111_TUP_FNAME       "/sdcard/DCIM/Camera/camsensor_mt9p111_tuneup_ef18k.txt"
#define YACBAC1SDDAS_TUP_FNAME "/sdcard/DCIM/Camera/camsensor_yacbac1sddas_tuneup_ef18k.txt"
#endif

/* SKYCAM 2010-10-21
 * 2010-10-26 Qualcomm���� ���� �ڵ带 �޾Ƽ� ����
 * GPS, JPEG THUMBNAIL, JPEG_EXIF ���� fail�� �߻��Ѵ�.
 * ���� MT9P111�������� ������ ���� ��쿡�� checkpreview�� failed�� �߻�.
 * Timeout Error�� �߻��Ѵ�. �̷��� ������WAIT_FOR_COMMAND_TO_COMPLETE�� 1.5�ʷ� �����Ǿ�̴�.
 * WAIT_FOR_COMMAND_TO_COMPLETE�� ��� EF13S, EF13L�� ���� 5�ʷ� �����Ǿ�  �ִ�.
 * ������� �������δ� ������������ ���� ����ȭ ������ �ð��� ���� �ɸ��� �����̶�� �ľ��ϰ� �ִ�.
 */
#define F_SKYCAM_QBUG_CTS

/* SKYCAM Lee Jitae 2010-11-27
 * �Կ��� ������� ���� ��Ȳ���� Stop preview�� �Ͽ� �޸𸮰� �����Ǵ� ��Ȳ�� �߻�, NULL POINTER REFERENCE������ ���ؼ� ���� ��������
 * �װ� ���Ŀ��� �̻� ȭ�� ǥ��, ���� �ȳ� ���� ������ �߻��մϴ�.
 */
#define F_SKYCAM_QBUG_SNAPSHOT_RELEASE_INTERRUPT

#ifdef F_SKYCAM_TARGET_EF18K
/* SKYCAM_PSJ_110531
 *  stagefright�� ���ڵ� �� �������� KT���� ������ �ȵǴ� ����
 *  ������ Ʈ�� ����� "pasp" �κ��� KT�������� �Ľ��� ���ϴ� ������ �������� SKT�� LG�⿡���� ���������� ������ �Ǿ���
 *  KT���� ��� ���� ������ �Ұ��� ��Ȳ�� ����Ͽ� ����� �ش� �κ��� ���� �ʵ��� ��. �� �� KT���� ���� �� �� �ִ� ����
 */
#define F_SKYCAM_FIX_MMS_CAMCORDER_FOR_KT
#endif

 /* SKYCAM_PSJ_110607
 *  VTī�޶� ���۽� setPreviewDisplay���Ŀ� preview size�� �Ķ���� ������ �Ͽ� 
 *  setPreviewDisplay���� ��������� overlay0�� free�ǰ� �ٽ� ��������� ������ ����
 *  �ٽ� ���������� ��������� �ϳ� destroy(free)�� create���̿� ������ delay�� ������ overlay1�� ����� overlay0�� free�Ǵ� ��찡 ����
 *  �̷� ��Ȳ�� �����ϱ� ���Ͽ� setPreviewDisplay�� �Ķ���� ���� ���ķ� ����
 */
#define F_SKYCAM_FIX_VT_OVERLAY_FAIL

/* SKYCAM_PSJ_110802
 * GB ���׷��̵� �۾� ���� ���� ����� ���� �Կ��� Halt���� ������ ����
 * sound��Ʈ���� ������ delay�� �ʿ��ϴٰ� �Ͽ� stop�ð� �ƴϴ��� üũ�Ͽ�
 * delay�� ����� �� �ֵ��� ���� */
#define F_SKYCAM_FIX_CONTINUOUS_CAMERA_SOUND_ERROR

/* SKYCAM_PSJ_110812
 * takepicture�� �Ǵ� ���� ���� ��ư�� ��巶�?��� snapshot thread�� mLock�� deadlock�� �ɷ�
 �������� ���ϴ� case �߻�. mLock�� ������ ��ġ�� �ʴ� ������ release�ÿ� snapshot thread�� ���Ḧ
 ��ٷ� �ִ� �κ� ��ġ ����
 ���� preview frame sync feature�� ����� �ű�
 */
#define F_SKYCAM_SYNC_SNAPSHOT_THREAD_N_CONTROL_THREAD
#define F_SKYCAM_SYNC_FRAME_THREAD_N_CONTROL_THREAD

 /* SKYCAM_PSJ_110818
 * ���� ����������� ����� ����ī�޶� ���� ����������� �ִ°� ó�� ī�޶��� ������ ������
 * Preview, Capture, Postview, Recording �� LCD�� ȭ�� ��ü�� �� ������ crop, scale, orientation���� �۾��� �Ǿ�����
 * 8255������ Overlay�� ���ʿ� ���� EF31S�� ���� 7227���� �۾��� �����ϰ� ���ݾ� ���̰� ����
 * Capture�� ��� image crop, scale�ÿ� �츮�� �ʿ��� ������ ��ȯ�� bottom, right�� 3�� ������ ©���� ������ ����(IPL ����)
 * �����δ� 336*448���� 328*440���� crop�Ͽ� �����
 */
#define F_SKYCAM_FAKE_FRONT_CAMERA

 /* SKYCAM_PSJ_110818
 * IPL�� �̿��Ͽ� Image crop, scale�ÿ� 3�� ���� ©���� ������ ���ϰ��� MDP�� C2D composition���� 
 * Image Processing�� �ϱ����� �׽�Ʈ �� �ڵ�
 * ���� ������ ���� ������ ������ �۾��� �� ����� �ϴ� �κ���
 */
/*#define F_SKYCAM_TEST_C2D_COMPOSITION */

/*----------------------------------------------------------------------------*/
/*  SENSOR CONFIGURATION                                                      */
/*  �� �� ��� ����(ISP)�� ���� ����/�߰��� FEATURE ���                    */
/*----------------------------------------------------------------------------*/
/* If you use YUV sensor only, define this feature. If you use two cameras,
 * and one is YUV and another is BAYER, don't define this. If you define this,
 * some BAYER-codes will not be processed.
 */
#define F_SKYCAM_YUV_SENSOR_ONLY

#if defined(F_SKYCAM_TARGET_EF18K) || defined(F_SKYCAM_TARGET_EF30S)
/* EF18K, EF30S�������Ǵ� ����*/
#define F_SKYCAM_MT9P111
#define F_SKYCAM_YACBAC1SDDAS
#endif


#ifdef F_SKYCAM_YUV_SENSOR_ONLY
#define F_SKYCAM_ADD_CFG_ANTISHAKE
#define F_SKYCAM_FIX_CFG_EXPOSURE
#define F_SKYCAM_FIX_CFG_SCENE_MODE
#define F_SKYCAM_FIX_CFG_FOCUS_RECT
#define F_SKYCAM_FIX_CFG_REFLECT
#define F_SKYCAM_FIX_CFG_FOCUS_STEP
#define F_SKYCAM_FIX_CFG_ROTATION
#define F_SKYCAM_ADD_CFG_MULTISHOT
#define F_SKYCAM_CUST_PICTURE_SIZES
#define F_SKYCAM_FIX_CFG_BRIGHTNESS
#define F_SKYCAM_FIX_CFG_EFFECT
#define F_SKYCAM_FIX_CFG_PREVIEW_FPS
#define F_SKYCAM_FIX_CFG_ANTIBANDING
#define F_SKYCAM_FIX_CFG_AF
#define F_SKYCAM_CUST_PREVIEW_SIZES
#define F_SKYCAM_FIX_CFG_WB
/* F_SKYCAM Lee Jitae 2010-11-15
 *  Camcoder�� ��� CAF�� ON, OFF�� �� �� �ִ�
 * EF18K�� ��� �ػ�� ������ �߻��ؼ� ����
 * ==> GB���׷��̵忡�� �׽�Ʈ �� ���� ������ 18K���� ���� ��
 */
#define F_SKYCAM_FIX_CFG_CAF
#endif


#ifndef F_SKYCAM_YUV_SENSOR_ONLY
/*
 *  DIS(Digital Image Stabilization)��� ON
 */
#define F_SKYCAM_VIDEO_FRAME_VPE
#endif

/*
 * �ö���� �� �ν� �ַ�� ����ϱ� ���� FEATURE
 * 2010-10-04  �ö���� ���̺귯�� �� �ҽ��ڵ� ������Ʈ
 */
#define F_SKYCAM_ADD_CFG_FACE_FILTER

#ifdef F_SKYCAM_ADD_CFG_FACE_FILTER
#define F_SKYCAM_ADD_CFG_FACE_FILTER_RECT

/* SKYCAM Lee Jitae 2010-11-23
 *[������] �����Կ� Ư���Կ�/�󱼲ٹ̱�/��ī�Կ��϶� ������ȭ���Ž� ������mp3�� ��µǴ��߿� �⺻���� ����Ǽ� �����
 * Call event ���Ž�, stop-preveiw ��(or ��)  olaworks process �������� ���� media-serve kill
 * mutex ó���� stop-preview ��(or ��) olaworks process ���� ���� �ʵ��� �߰�.
*/
#define F_SKYCAM_OLAWORKS_LOCK
#endif


/* �÷��� LED ������ ���� �������̽��� �����Ѵ�.
 *
 * QUALCOMM ������ ������ IOCTL (MSM_CAM_IOCTL_FLASH_LED_CFG) Ŀ�ǵ带
 * ����Ͽ� �����Ǿ� ������, PMIC ������ ����ϴ� LED ����̹��� �����Ѵ�.
 * EF10S ������ �̸� ������� ������, MSM_CAM_IOCTL_SENSOR_IO_CFG �� Ȯ���Ͽ�
 * �����Ѵ�.
 *
 * AUTO ���� ������ ���, ������ �� ��쿡�� AF ���� �� AF/AE �� ����
 * ��� ON �ǰ�, ���� ������ �������� �� �� �� ON �ȴ�. */
#define F_SKYCAM_FIX_CFG_LED_MODE


/* SKYCAM Lee Jitae 2010-09-25
 * OTP����� �ҷ����� ���̱� ���� �޸� zone�� 2���� detecting�Ͽ�
 * ���� ����ؾ� �� zone�� ã�Ƴ� �� �ش� zone�� �޸𸮸� ��� �� �� �ֵ��� �߰�
 * WS02������ ���� ����
*/
#define F_SKYCAM_ADD_CFG_OTP_MODULE



/* 2010-10-06
 *Continous AF �� �׽�Ʈ �ϱ� ���� �۾� �� ����
 */
/* #define F_SKYCAM_CAF
*/

/* oen exif tag ���� */
#define F_SKYCAM_OEM_EXIF_TAG

/*
 * 800*480, 640*480 �� ������ �ٸ� �̹��� ������� ���� ���(90��)�� �ؼ� ���ؼ� ���� �Կ��� �� ��� �̹����� ����
 * �̹��� ���� ������ ��������. ���� �⺻ ī�޶󿡼��� 3M 1.4�迡�� ������ �����ϴ� ���� Ȯ����
 * �̷��� �̹����� ������ ��츦 �۾��� ��
 */
#define F_SKYCAM_QBUG_ROTATION_ZOOM

/* ES01 ���� ���̳ʸ� ���� Feature  Lee Jitae 2010-10-13 */
/* EF18K��WS02�� �÷� H/W ������ power sequence�� ����  �ʾ���
 *  �׷��� Power sequence���� �ذ��� ���� Feature
 * EF18K WS02�� �÷�� ���ĸ� ���� ES1�� ���Ĵ� �����ش�.
 */
#define F_SKYCAM_EF18K_ES01

  /* SKYCAM_PSJ_100622
 * BGM�� Ʋ����� ���¿��� ī�޶� �����Կ��� �Կ��� ������ ������ ������
 * get_duration�Լ��� �̿��Ͽ� ������ ���̸� ���� �� �׸�ŭ usleep�� �ָ�
 * ������ ������ �������� �Կ����� �� ���� �Ŀ� ���� ������ ������
 * ������ ������ ������ ���ɻ��� �����̹Ƿ� �ϴ� �츮�� �������� �ʴ� �ɷ� �Ѵ�
*/

/* SKYCAM Lee Jitae 2010-10-22
 * VGA�� ������̵带 ���� �� ���尡 �������� ������ �Ͼ��. EF13���� ���� �Կ����� ������ ���⳪
 * EF18K������ ���� �߻��� ������ �ʾҴ�. �ణ ������ ���� ���� ����.
 * �ϴ� EF13S�� ���� ���� ��⿡ ǥ���Ѵ�.
 */
#define F_SKYCAM_FIX_SNAPSHOT_BEEP_SPLIT


/* SKYCAM Lee Jita3 2010-11-23
 * 720P���� �����䰡 1280*720�� ���� �ʴ´�.
 * ǥ�� �� �� �ִ� ������ ������� �������ش�.
 */
#define F_SKYCAM_720P_PREVIEW

/* SKYCAM Lee Jitae 2010-12-10
 * MARKET CAMERA APP�� I'M IN APP�� POSTVIEW�� ������.
 * ������ Set_demension�� �ϸ� POSTVIEW����� ���ϴ� ���õ��� �ִ�.
 * �̷�  ���õ��� CAMERA_SET_PARM_DIMENSION ���� ���� ����ȴ�.
 * SKYCAM������ 1.3333���� ������ ��ȭ�� ���� ������ ������ ��������.
 */
#define F_SKYCAM_QBUG_MARKET_APP


 /* SKYCAM Lee JItae 2010-11-23
  * WVGA�� ��� ���� �ϸ� POSTVIEW�� Ŀ����.
  * Qualcomm���� ���� ��ġ ���� �ڵ�
  */
#define F_SKYCAM_QBUG_WVGA_ZOOM

/* CAMERA������ ��� Sensor Driver�� ���ǵǾ��� �ִ�.
 * Surf Board�� ���� msm_camera.c�� __msm_open(), msm_camio_sensor_clk_on�� ȣ���� ���
 * Power�� On��Ű��  �ִ�. �̹� Sensor Driver���� ������ ���� �� �־��� ������ ���⼭�� Power On
 * �� ���� �ʴ´�. ���ʿ��� ������ On ��Ű��  �ִ�.
*/
#define F_SKYCAM_POWER


/* iPhone���� MMS�� ������� �ʴ� ������ �߻�
   SID��Ŷ ������� Qualcomm������ SR�� �亯����
   ��ġ��
 */
#define F_SKYCAM_IPHONE_MMS

/* 
 * Gingerbread�� CameraService���� lockIfMessageWanted(int32_t msgType) �Լ��� �߰� �Ǿ���.
 * CameraService�� callback ó�� �Լ����� mLock�� check�Ͽ� LOCK �����̸�, UNLOCK���� waiting �Ѵ�.
 * capture ���� ���� UI �κ��� command�� �������� callback �Լ����� �̷� ���� ������ �߻��Ѵ�.
 * capture ���� �� ī�޶� ����� �̷� ���� CameraHAL���� UI�� ���� ���� �Ǵ� ��찡 �߻��Ѵ�.
 * UI�� ���� ����ǰ� CameraHAL �������� �ٽ� Camera�� ����Ǹ� ���������� Open ���� ���Ѵ�.
 * lockIfMessageWanted �Լ��� ��� ���� �ʵ��� �����Ͽ���.
*/
#define F_SKYCAM_FIX_CS_TRYLOCK

/* ������ ��ȭ ����/���Ḧ ������ �ݺ��ϰų�, �̾����� ������ ���¿��� �����Կ�
 * ���� �Կ��� ���, MediaPlayer �� �������ϸ鼭 HALT �߻��Ѵ�.
 *
 * MediaPlayer �� ���, ������ ������ ��� �߿� �� �ٽ� ��� �õ��� ��� 100%
 * �������ϹǷ� ���� ������ �����Ͽ� ����ؾ� �� ���, �ݵ�� ���� ����� �Ϸ�
 * �Ǿ����� ���θ� Ȯ�� �� ����ؾ� �Ѵ�. */
#define F_SKYCAM_QBUG_SKIP_CAMERA_SOUND

/*
 * ���� ���ڵ� ���۰� ���� ���� ����� ���� ���� �����
 * ȿ���� ��� �� �ý��� ���Ϸ� ���� �Ҹ��� ����� ��� �߻�
 * ���ڵ� ������ start �� �� ������ ���� �� ������ wating
 * EF31S/EF32K ������ Sound�� kernel message�� ������ ��� �Ҹ��� �����,
 * kernel message�� ���ų� release build������ ���� �߻� ����.
*/
#define F_SKYCAM_QBUG_REC_BEEP_SOUND

/* �Կ���/��ȭ�� ��� �߿� ������ ����� ���, CLIENT �Ҹ� �ÿ� �ش� �Կ���/
 * ��ȭ�� ������Ʈ�� ������ disconnect/clear �Ǹ鼭 MEDIA SERVER �� �״� ����
 * �����Ѵ�. */
#define F_SKYCAM_QBUG_STOP_CAMERA_SOUND
/*----------------------------------------------------------------------------*/
/*  MODEL-SPECIFIC CONSTANTS                                                  */
/*  �� ���� ��� ����                                       */
/*----------------------------------------------------------------------------*/

#ifdef F_SKYCAM_FACTORY_PROC_CMD
#define C_SKYCAM_FNAME_FACTORY_PROC_CMD	"/data/.factorycamera.dat"
#endif


/* ���� ������ �ּ�/�ִ� ��Ŀ�� �����̴�. */
#ifdef F_SKYCAM_FIX_CFG_FOCUS_STEP
#define C_SKYCAM_MIN_FOCUS_STEP 0	/* ���Ѵ� (default) */
#define C_SKYCAM_MAX_FOCUS_STEP 9	/* ��ũ�� */
#endif

/*  FPS ����*/
#ifdef F_SKYCAM_FIX_CFG_PREVIEW_FPS
#define C_SKYCAM_MIN_PREVIEW_FPS	5
#define C_SKYCAM_MAX_PREVIEW_FPS	31
#define C_SKYCAM_VT_PREVIEW_FPS		7
#endif

/* Brightness ���� */
#ifdef F_SKYCAM_FIX_CFG_BRIGHTNESS
#define C_SKYCAM_MIN_BRIGHTNESS 0
#define C_SKYCAM_MAX_BRIGHTNESS 8
#endif

#define C_SKYCAM_SELECT_MAIN_CAM 		0
#define C_SKYCAM_SELECT_SUB_CAM 		1
#ifdef F_SKYCAM_ADD_VT_CAM
#define C_SKYCAM_SELECT_VT_SUB_CAM 		2
#define C_SKYCAM_SELECT_VT_MAIN_CAM		3
/* VT camera preview size */
#define VT_CAMERA_PREVIEW_WIDTH		176
#define VT_CAMERA_PREVIEW_HEIGHT 	144
#endif
#ifdef F_SKYCAM_FAKE_FRONT_CAMERA
#define FAKE_CAMERA_PREVIEW_WIDTH			336
#define FAKE_CAMERA_PREVIEW_HEIGHT 			448
#define FAKE_CAMERA_CAPTURE_CROP_WIDTH		328
#define FAKE_CAMERA_CAPTURE_CROP_HEIGHT 	440
#define FAKE_CAMERA_OUT_IMAGE_WIDTH			640
#define FAKE_CAMERA_OUT_IMAGE_HEIGHT 		480
#endif

#ifdef F_SKYCAM_OEM_EXIF_TAG
#define C_SKYCAM_EXIF_MAKE		"PANTECH"
#define C_SKYCAM_EXIF_MAKE_LEN		8		/* including NULL */
#define C_SKYCAM_EXIF_MODEL		"IM-A710K"
#define C_SKYCAM_EXIF_MODEL_LEN		9		/* including NULL */
#endif

#endif /* CUST_SKYCAM.h */
