/*******************************************************************************
  Copyright (C), 2010-2014, GOSUNCN 
  File name   : GSSTREAMCODEID.H      
  Author      : ��ʢ��      
  Version     : 1.0.0        
  DateTime    : 2015/4/2 9:49
  Description : ý�������붨��
*******************************************************************************/

#ifndef GSSTREAMCODEID_DEF_H
#define GSSTREAMCODEID_DEF_H


/*
****************************************
brief : �����������
****************************************
*/
typedef enum
{
    GS_CODEID_NONE = 0, //�ޱ�������
    GS_CODEID_BINARY,   //�����Ʊ���

	GS_CODEID_GS_PS,	// GOSUN PS ��̬����


    //��׼��Ƶ���� 
    GS_CODEID_ST_MP4        = 0x00000010,       //��׼�� MP4 ����
    GS_CODEID_ST_H264,                          //��׼�� H264 ����
	GS_CODEID_ST_SVAC,                          //��׼�� SVAC ����
	GS_CODEID_ST_H265,                          //��׼�� H265 ����
	GS_CODEID_ST_H263,                          //��׼�� H263 ����
	GS_CODEID_ST_MPEG2,
	GS_CODEID_ST_MPEG1,	
	GS_CODEID_ST_MJPG,
	GS_CODEID_FCC_MPEG4,
	GS_CODEID_MS_MPEG4,
	GS_CODEID_ST_FLV1,
	GS_CODEID_ST_WMV1,
	GS_CODEID_ST_WMV2,
	GS_CODEID_ST_WMV3,
 
    //��׼��Ƶ����
    GS_CODEID_ST_MP3        = 0x00000300,       //��׼MP4
	GS_CODEID_AUDIO_ST_PCM,	
	GS_CODEID_AUDIO_ST_G711A,
	GS_CODEID_AUDIO_ST_G711U,
	GS_CODEID_AUDIO_ST_G721,
	GS_CODEID_AUDIO_ST_G722,
	GS_CODEID_AUDIO_ST_G723,
	GS_CODEID_AUDIO_ST_G726,					//Ĭ��G726_16
	GS_CODEID_AUDIO_ST_G729,
	GS_CODEID_AUDIO_ST_H263,
	GS_CODEID_AUDIO_ST_SVAC,
	GS_CODEID_AUDIO_ST_AAC,
	GS_CODEID_AUDIO_ST_G726_16,
	GS_CODEID_AUDIO_ST_G726_24,
	GS_CODEID_AUDIO_ST_G726_32,
	GS_CODEID_AUDIO_ST_G726_40,
	GS_CODEID_AUDIO_ST_OGGVORBIS,
	GS_CODEID_AUDIO_ST_AMR,
	GS_CODEID_AUDIO_ST_WMA1,
	GS_CODEID_AUDIO_ST_WMA2,
	GS_CODEID_AUDIO_ST_G722_1,

	GS_CODEID_PS = 0x00000400,


    //��׼ͼ�����
    GS_CODEID_ST_JPEG       = 0x00000600,         //��׼JPG
    GS_CODEID_ST_BMP,                             //��׼JPG
    GS_CODEID_ST_YUV420P,                         //��׼YUV420P
    GS_CODEID_ST_NV12,                            //��׼NV12
    GS_CODEID_ST_RGB24,
	GS_CODEID_ST_ARGB,
	GS_CODEID_ST_RGBA,
	GS_CODEID_ST_BGR24,

    //�����̽��е��������



    //=====��������
    GS_CODEID_GS_V2160I     = 0x00001000,       // GOSUN 2160I ��Ƶ����
    GS_CODEID_GS_A2160I,                        // GOSUN 2160I ��Ƶ����
    GS_CODEID_GS_V462C,                         //GOSUN BASS462C ��Ƶ����
    GS_CODEID_GS_A462C,                         //GOSUN BASS462C ��Ƶ����
    GS_CODEID_GS_V461C,                         //GOSUN BASS461C ��Ƶ����
    GS_CODEID_GS_A461C,                         //GOSUN BASS461C ��Ƶ����
	GS_CODEID_GS_V461A,                         //GOSUN BASS461A ��Ƶ����
	GS_CODEID_GS_V2160IV,						// GOSUN 2160I_V ��Ƶ����
	GS_CODEID_GS_A2160IV,                       // GOSUN 2160I_V ��Ƶ����
	GS_CODEID_GS_VIPC,							// GOSUN IPC	 ��Ƶ����
	GS_CODEID_GS_AIPC,							// GOSUN IPC	 ��Ƶ����
	
	//======����======
	GS_CODEID_GS_GUOMAI_VIPC,					// ����4Gִ������Ƶ����
	GS_CODEID_GS_GUOMAI_AIPC,					// ����4Gִ������Ƶ����

    //===== ��ʨ 
    GS_CODEID_HI_VDEFAULT   = 0x00001200,        //��ʨ����Ƶͨ�ñ���
    GS_CODEID_HI_ADEFAULT,                      //��ʨ����Ƶͨ�ñ���
    GS_CODEID_HI_VH264,                         //��ʨ H264
    GS_CODEID_HI_VMP4,                          //��ʨ H264
    GS_CODEID_HI_COMPLEX,                          //��ʨ����ͨ�ñ���


    //===== ����
    GS_CODEID_HK_VDEFAULT    = 0x00001300,      //��������Ƶͨ�ñ���
    GS_CODEID_HK_ADEFAULT,                      //��������Ƶͨ�ñ���
    GS_CODEID_HK_VMP4,                          //���� MP4
    GS_CODEID_HK_VH264,                         //���� H264
	GS_CODEID_HK_COMPLEX,                       //��������ͨ�ñ���
	GS_CODEID_HK_PRIVATE,                       //����˽�и�ʽ����




    //===== ��
    GS_CODEID_DH_VDEFAULT    = 0x00001400,      //�󻪵���Ƶͨ�ñ���
    GS_CODEID_DH_ADEFAULT ,                     //�󻪵���Ƶͨ�ñ���
    GS_CODEID_DH_VMP4,                          //�� MP4
    GS_CODEID_DH_VH264,                         //�� H264
    GS_CODEID_DH_COMPLEX,                       //�󻪸���ͨ�ñ���
	GS_CODEID_DH_PRIVATE,								//��˽�и�ʽ����

    //===== ����
    GS_CODEID_HY_VDEFAULT   = 0x00001500,       //�������Ƶͨ�ñ���
    GS_CODEID_HY_ADEFAULT,                      //�������Ƶͨ�ñ���
    GS_CODEID_HY_VMP4,                          //���� MP4
    GS_CODEID_HY_VH264,                         //���� H264
    GS_CODEID_HY_COMPLEX,                       //���渴��ͨ�ñ���


	//=====�ֻ�
	GS_CODEID_WM_XVID		= 0x00001600,		//�ֻ��ͻ��˽���1,̷־��Ӳ���

	// ===== �ƺ�
	GS_COIDEID_HH_VDEFULT   = 0x00001700,       //�ƺӵ���Ƶͨ�ñ���

	// ===== �б�
	GS_CODEID_ZBEN_VDEFULT  = 0x00001800,       //�б�����Ƶ����
	GS_CODEID_ZBEN_ADEFULT,                     //�б�����Ƶ����

	// ===== �߿���
	GS_CODEID_CALSYS_VDEFULT = 0x00001900,         //�߿��ӵ���Ƶͨ�ñ��� 
	GS_CODEID_CALSYS_ADEFULT,                      //�߿��ӵ���Ƶͨ�ñ���

    // ==== ��������
	GS_COIDEID_ALRS_VDEFULT   = 0x00002000,       //�������ӵ���Ƶͨ�ñ���

	// ====  Ѷ��
    GS_CODEID_XM_VDEFULT   = 0x00002100,          //Ѷ����Ƶͨ�ñ���

   // ====  �߿���GS76xxϵ��
    GS_CODEID_CALSYSGS76XX_VDEFULT = 0x00002200,         //�߿���GS76XX����Ƶͨ�ñ��� 
	
	//
	GS_CODEID_MEDIA = 0x00002300,
	// === FFmpeg�������
	GS_CODEID_GSVIDEO = 0x00002400,
	
	// ====  �ݸ�
	GS_CODEID_JG_VDEFULT = 0x00002500,              //�ݸ��豸ͨ�ñ���
	GS_CODEID_JG_ADEFULT = 0x00002600,

	//=====�ؿ�=======
	GS_CODEID_PACOM_VDEFULT = 0x00002700,
	GS_CODEID_PACOM_ADEFULT = 0x00002800,		    //�ؿ��豸

	//======ϣ��======
	GS_CODEID_XIHUA_VDEFULT = 0x00002900,			//ϣ����Ƶ����
	GS_CODEID_XIHUA_ADEFULT = 0x00003000,			//ϣ����Ƶ����

	//======����======
	GS_CODEID_UVNVR_AR_VDEFULT = 0x00003100,        //����NVR AR����Ƶͨ�ñ��� 
	GS_CODEID_UVNVR_AR_ADEFULT = 0x00003200,	    //����NVR��Ƶ����

	//======����IPC======
	GS_CODEID_UNIVIEW_IPC_VDEFULT = 0x00003300,		//����ipc�������Ƶ����
	GS_CODEID_UNIVIEW_IPC_ADEFULT = 0x00003400,		//����ipc�������Ƶ����

	GS_CODEID_VSR = 0x00003500,				        //�ṹ������֡

	//======�޿�ʿNVR======
	GS_CODEID_ROCOS_VDEFULT = 0x00003600,			//ROCOSNVR��Ƶ����
    GS_CODEID_ROCOS_ADEFULT = 0x00003700,			//ROCOSNVR��Ƶ����

	//======ͼ��======
	GS_CODEID_TM_VDEFULT = 0x00003800,			//ͼ����Ƶ����
    GS_CODEID_TM_ADEFULT = 0x00003900,			     //ͼ����Ƶ����
    
    //======����======
	GS_CODEID_QIY_VDEFULT = 0x00004000,			     //������Ƶ����
	GS_CODEID_QIY_ADEFULT = 0x00004100,			     //������Ƶ����
    
   	//======����======
	GS_CODEID_SUNELL_VDEFULT = 0x00004200,			 //������Ƶ����
	GS_CODEID_SUNELL_ADEFULT = 0x00004300,			 //������Ƶ����
	
	//======��Ϊ======
	GS_CODEID_HUAWEI_VDEFULT = 0x00004400,			 //��Ϊ��Ƶ����
	GS_CODEID_HUAWEI_ADEFULT = 0x00004500,			 //��Ϊ��Ƶ����
	GS_CODEID_HUAWEI_COMPLEX,
	
	//======���ΰҵ======
	GS_CODEID_TDWY_VDEFULT = 0x00004600,			 //���ΰҵ��Ƶ����
	GS_CODEID_TDWY_ADEFULT = 0x00004700,			 //���ΰҵ��Ƶ����
	GS_CODEID_TDWY_COMPLEX,

	//======����======
	GS_CODEID_BOSCH_VDEFULT = 0x00004800,			 //������Ƶ����
	GS_CODEID_BOSCH_ADEFULT,						 //������Ƶ����
	GS_CODEID_BOSCH_COMPLEX,

	//======����======
	GS_CODEID_HAOYUN_VDEFULT = 0x00004900,			 //������Ƶ����
	GS_CODEID_HAOYUN_ADEFULT,						 //������Ƶ����
	GS_CODEID_HAOYUN_COMPLEX,

	//======�廪ͬ��======
	GS_CODEID_TONGFANG_VDEFULT = 0x00005000,		 //�廪ͬ����Ƶ����
	GS_CODEID_TONGFANG_ADEFULT,						 //�廪ͬ����Ƶ����
	GS_CODEID_TONGFANG_COMPLEX,

	//======��Ծ�Ƽ�======
	GS_CODEID_TYKJ_VDEFULT = 0x00005100,			 //��Ծ�Ƽ���Ƶ����
	GS_CODEID_TYKJ_ADEFULT,							 //��Ծ�Ƽ���Ƶ����
	GS_CODEID_TYKJ_COMPLEX,

	//======��ɫ�Ǽ�======
	GS_CODEID_BLUESTAR_VDEFULT = 0x00005200,		 //��ɫ�Ǽ���Ƶ����
	GS_CODEID_BLUESTAR_ADEFULT,						 //��ɫ�Ǽ���Ƶ����
	GS_CODEID_BLUESTAR_COMPLEX,

	//======����߿�======
	GS_CODEID_HANBANG_VDEFULT = 0x00005300,			 //����߿���Ƶ����
	GS_CODEID_HANBANG_ADEFULT,						 //����߿���Ƶ����
	GS_CODEID_HANBANG_COMPLEX,

	//======�������豸======
	GS_CODEID_UV2017_VDEFULT  = 0x00005400,			 //�������豸������Ƶ����

	//======��;�豸======
	GS_CODEID_NSDPANO_VDEFULT  = 0x00005500,			 //NsdPano ��;�豸�豸������Ƶ����

    GS_CODEID_END,   //���ڽ�β 


}EnumGSCodeID;

#endif // GSSTREAMCODEID_DEF_H
