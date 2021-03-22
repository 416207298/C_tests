#ifndef LOCAL_STAV_FILE_INTERFACE_H_H_
#define LOCAL_STAV_FILE_INTERFACE_H_H_

#include "AVFileInterface.h"
#include "GMFDefs.h"
#include <string>
#include <vector>

using namespace std;

#ifdef __cplusplus
extern "C"{
#endif

#include "stdint.h"
#include "inttypes.h" 
#include "libavutil/opt.h"
#include "libavutil/mathematics.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"

#ifdef __cplusplus
};
#endif


typedef vector<StruIFrameIndex> IFrameIndexList;
typedef vector<StruIFrameIndexV2> IFrameIndexListV2;

class CLocalSTAVFileReadInterface : public GSAVFileReadInterface
{
public:
	CLocalSTAVFileReadInterface();
	virtual ~CLocalSTAVFileReadInterface();

public:
	//���еĽӿ� ����֤
	//�ͷŶ���
	virtual void Release(void) ;

	//����ý����������
	virtual int GetMediaDescriCounts(void);

	//���� ý�������� iIndex �� 0 ��ʼ < GetMediaDescriCounts ����ֵ
	virtual const StruGSMediaDescri *GetMediaDescri( int iIndex);

	//�����ļ���Ϣ
	virtual EnumGSAVFileRetCode GetInfo( StruGSAVFileInfo* pstInfo );

	//�ر��ļ�
	virtual EnumGSAVFileRetCode Close(void);

	//���ö�ȡ����, bForward ����ȡ�� Ĭ�� ������ȡ 
	virtual EnumGSAVFileRetCode SetReadDirection( bool bForward = true);

	//�ļ���ȡ
	//��ȡ��һ֡, bOnlyVideoKey ֻ����Ƶ�ؼ�֡
	//bForward ����ȡ 
	virtual EnumGSAVFileRetCode ReadFrame(StruGSAVFrame* pstFrame,bool bOnlyVideoKey = false);

	//��ȡ��ͣ
	virtual void ReadPause(void);

	//�϶�
	// iTimestamp ��� �ļ���ͷ��ʱ��ƫ�ƣ� ��λ ��,
	// bSeekVideoKey ���Ϊ�棬 ��λǰһ������� ��Ƶ�ؼ�֡ 
	virtual EnumGSAVFileRetCode SeekTime(UInt64 iTimestamp, bool bSeekToVideoKey=true, UInt32* pRealTimeStamp=NULL,Int32 iDirect = 0);
	
	// ��λ�ö�λ
	EnumGSAVFileRetCode SeekPos(UInt64 iPos);

	// ��λ����ǰλ���������һ��I֡
	virtual EnumGSAVFileRetCode SeekPreviousIFrame();

	// ��λ�����һ��I֡
	virtual EnumGSAVFileRetCode SeekLastIFrame();	

	// ��ȡ��ǰ����λ��
	Int64 GetCurrentPos();

	//�޸��ļ�
	virtual EnumGSAVFileRetCode Repair(void) ;

	virtual EnumGSAVFileRetCode RepairGetLastTime(Int64 &tv);

	EnumGSAVFileRetCode OpenFile(char* szFullName,EnumGSAVFileOpenMode eMode);

private:
	EnumGSCodeID	AVCodecID2GSCodeID(AVCodecID codeID);

	Int32	GetIFrameIndex(Int32 iFrameIndex);

	AVFormatContext* m_pAvFormat;
	AVStream*		 m_pVideoStream; 
	AVStream*		 m_pAudioStream;
	Int32			 m_nVideoIndex;
	Int32			 m_nAudioIndex;

	StruGSMediaDescri* m_pMediaDescriArry;
	Int32			 m_iMediaDesNum;
	string			 m_strFileFullName;
	Int32			 m_iFrameInterval;

	IFrameIndexList  m_iFrameIndexList;
	Int32			 m_iVideoSeq;	//��¼��ǰ���ŵ���Ƶ֡��,��1��ʼ

	Int32			 m_iAudioBitRate;//��Ƶ�ı�����

	bool			 m_bHadReadFrame;//�Ѿ���ȡ�����ݣ������ж��Ƿ���Ҫ�ͷ�AVPacket;
	AVPacket		 m_avPakcet;//
};


class CLocalSTAVFileWriteInterface : public GSAVFileWriteInterface
{
public:
	CLocalSTAVFileWriteInterface();
	~CLocalSTAVFileWriteInterface();
	//�ͷŶ���
	virtual void Release(void) ;

	//�ر��ļ�
	virtual EnumGSAVFileRetCode Close(void);

	//д����
	virtual EnumGSAVFileRetCode WriteFrame(const StruGSAVFrame* pstFrame);

	//�����ļ�
	EnumGSAVFileRetCode	CreateFile(const char* czFullFilename,const char *czShortFilename,  const StruGSMediaDescri *vMediaDescri, int nMediaDescriNumber);

	//��������Ŀ¼��
	virtual const char *GetFullFilename(void);

	//�������Ŀ¼��
	virtual const char *GetShortFilename(void);



	//�����ļ���С
	virtual EnumGSAVFileRetCode GetSize( UInt64 &iFileSize );

private:
	EnumGSAVFileRetCode WriteHeadInfo(char* szFullName,const StruGSMediaDescri *vMediaDescri, int nMediaDescriNumber);
	AVCodecID	GSCodeID2AVCodecID(EnumGSCodeID codeID);
	

	AVFormatContext* m_pAvFormat;
	AVStream*		 m_pVideoStream; 
	AVStream*		 m_pAudioStream;
	Int32			 m_nVideoIndex;
	Int32			 m_nAudioIndex;
	string			 m_strFileFullName;
	string			 m_strShortFilename;
	Int64			 m_videopts;
	Int64			 m_audioopts;
};
#endif