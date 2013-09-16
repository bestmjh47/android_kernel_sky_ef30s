/*
 lived 2009.11.05
 FEATURE define
*/

#ifndef SKY_FRAMEWORK_FEATURE
#define SKY_FRAMEWORK_FEATURE

/* Debug Msg */
#if defined(FEATURE_AARM_RELEASE_MODE)
#define TEST_MSG(...)
#else
#define TEST_MSG(...)   ((void)LOG(LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#define SKY_LOG_DEBUG
#endif

#define SKY_LCD_LOADBAR_ANDROID  // 20100422, kkcho, aArm���� ���� �α׹� ��� 
#define SKY_EF18K_LCD

#define CONFIG_SKY_FB_24BPP_RGB888 // 20100609, kkcho, for boot_image via MSMFB_FRAMEBUF_32 

#define SKY_OVERLAY_SURFACEVIEW_ROTATION // 20101029, kkcho, for only TDMB_180_Rotation!!!

/*#define DIM_WITH_TEXTURE*/
#define SKY_ADD_SURFACE_BUFFER_HEAP_270

/* 20100902, kkcho, ������ȭ�� overlay�� 2�� �����ϸ�, ȭ�� play�� �ȵǴ� ������ ���� RGB_PIPE�� ����ϵ��� ����.*/
#define SKY_MDP4_VT_CALL_SCREEN

/* 20100905, kkcho, ������ȭ�� ��ȭ�� �¿� ���� */  
#ifdef SKY_ADD_SURFACE_BUFFER_HEAP_270
#define SKY_VT_CALL_VGA_LR_CHANGE
#endif

/* 2011.11.12, lived, Surface View size 1x1�� �߸� setting�Ǵ� ��� ���� */
#define F_SKYDISP_GBUG_INVALID_SURFACE_SIZE

/* 2011.12.06, lived, Surface View�� (x,y) ��ǥ�� �߸��Ǵ� ��� ����
 * LCD WxH�� SurfaceView�� W Ȥ�� H �� ���� ��쿡�� x �Ǵ� y�� 0���� ġȯ�Ѵ�.
 */
#define F_SKYDISP_GBUG_INVALID_SURFACE_POSITION

/* 20100916, kkcho, MDP�ʱ�ȭ�� noiseȭ�����Ÿ� ���� lcd�� off�Ѵ�. */ 
#define SKY_REMOVE_NOISE_MDP_INIT

/* 20101112, kkcho, LCD_OFF->LCD_ON �� stanby_mode�� ��� �Ͽ� on/off���� : Not yet availble*/
/*#define SKY_FAST_LCD_ON */

/* 20101112, kkcho, Overlay-view play�� hole-key�� ���� Holdȭ�� ON/OFF��, videoȭ�� ��� ��Ÿ���� ����. : Not yet availble */
/*#define SKY_MDP_VG_CLEAR_HOLD_CHANGE*/
/* 2011.01.14 code by EffectiveSKY
 * Description : SKY_FEATURE_ALLOW_FASTBOOT_MODE allow access to fastboot-mode.
 *               If SKY_FEATURE_ALLOW_FASTBOOT_MODE is not defined, fastboot is not allowed access from user. 
 */
/* #define	SKY_FEATURE_ALLOW_FASTBOOT_MODE*/
#ifdef FEATURE_SW_RESET_RELEASE_MODE
/* 20110121, kkcho, mArm���� 16bit�� display�ǹǷ� ���Ϸ�Ʈ ������ ������ �������� 32bit->16bit�� ��ȯ*/
#define F_SKYDISP_LAST_FB_CONVERT_xRGB8888_TO_RGB565
#endif
#endif  /* SKY_FRAMEWORK_FEATURE */
