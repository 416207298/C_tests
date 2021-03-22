/*
******************************************
Copyright (C): GOSUN
Filename : AVFILEINTERFACE.H
Author :  zouyx
Description: ý���ļ� ��д�ӿڶ���
********************************************
*/

#ifndef _GS_H_AVFILEINTERFACE_H_
#define _GS_H_AVFILEINTERFACE_H_

#include "CommonDef.h"

class GSAVFileReadInterface
{
public :	
	//���еĽӿ� ����֤
	//�ͷŶ���
	virtual void Release(void) = 0;

	//����ý����������
	virtual int GetMediaDescriCounts(void) = 0;
	//���� ý�������� iIndex �� 0 ��ʼ < GetMediaDescriCounts ����ֵ
	virtual const StruGSMediaDescri *GetMediaDescri( int iIndex) = 0;

	//�����ļ���Ϣ
	virtual EnumGSAVFileRetCode GetInfo( StruGSAVFileInfo* pstInfo ) = 0;

	//�ر��ļ�
	virtual EnumGSAVFileRetCode Close(void) = 0;

	//���ö�ȡ����, bForward=true��ǰ��ȡ�� Ĭ�� ����ǰ��ȡ 
	virtual EnumGSAVFileRetCode SetReadDirection( bool bForward = true) = 0;

	//�ļ���ȡ
	//��ȡ��һ֡, bOnlyVideoKey ֻ����Ƶ�ؼ�֡
	virtual EnumGSAVFileRetCode ReadFrame(StruGSAVFrame* pstFrame,
		bool bOnlyVideoKey = false) = 0;
	
	//��ȡ��ͣ
	virtual void ReadPause(void) = 0;

	//�϶�
	// iTimestamp ��� �ļ���ͷ��ʱ��ƫ�ƣ� ��λ ��,
	// bSeekVideoKey ���Ϊ�棬 ��λǰһ������� ��Ƶ�ؼ�֡ 
	virtual EnumGSAVFileRetCode SeekTime(UInt64 iTimestamp, bool bSeekToVideoKey=true, UInt32* pRealTimeStamp=NULL,Int32 iDirect = 0) = 0;
	
	// ��λ�ö�λ
	virtual EnumGSAVFileRetCode SeekPos(UInt64 iPos) = 0 ;

	// ��ȡ��ǰ����λ��
	virtual Int64 GetCurrentPos() = 0;

	// ��λ����ǰλ���������һ��I֡
	virtual EnumGSAVFileRetCode SeekPreviousIFrame() = 0 ;
	
	// ��λ�����һ��I֡
	virtual EnumGSAVFileRetCode SeekLastIFrame() = 0 ;

	//�޸��ļ�
	virtual EnumGSAVFileRetCode Repair(void) = 0;


	//�޸��ļ�, ��ȡ���ʱ��
	virtual EnumGSAVFileRetCode RepairGetLastTime(Int64 &tv) = 0;
};


class GSAVFileWriteInterface
{
public:
	//�ͷŶ���
	virtual void Release(void) = 0;

	//�ر��ļ�
	virtual EnumGSAVFileRetCode Close(void) = 0;

	//д����
	virtual EnumGSAVFileRetCode WriteFrame(const StruGSAVFrame* pstFrame) = 0;
	
	

	//��������Ŀ¼��
	virtual const char *GetFullFilename(void) = 0;

	//�������Ŀ¼��
	virtual const char *GetShortFilename(void) = 0;

	//�����ļ���С, Release ǰ�����Ե��ã� ��λ���ֽ�
	//Close ǰ���÷��ص�ǰд��ý���С�� 
	//Close ����÷��������ļ��Ĵ�С
	virtual EnumGSAVFileRetCode GetSize( UInt64 &iFileSize ) = 0;

};


//��ͨ�ļ�
class GSNormalFile
{
public :
	virtual void Release(void) = 0;

	//˳��д
	virtual EnumGSAVFileRetCode Write(const void *data,  int size) = 0;

	//������β���� eAVF_READ_END, ˳���
	virtual EnumGSAVFileRetCode Read(const void *data,  int size) = 0;

	//�ر��ļ�
	virtual EnumGSAVFileRetCode Close(void) = 0;
};


typedef struct _StruNameInfo
{
	bool isDir;
	char *szFullFilename; //ȫ·��
	_StruNameInfo(void) : isDir(false),szFullFilename(NULL)
	{

	}
}StruNameInfo;


class GSAVFileSystemInterface
{
public :
	// czRootPath ·�����ƣ� ��Ŀ¼:  disk_label/
	//					��:  E:/   192.168.0.1:8000/cluster1
	// czShortFilename ���Ŀ¼�� 

	//�½�¼���ļ�, czFilename ������ Ϊ�ο��ļ���, czFormat �ο��ļ���ʽ�� �� "avi", "gmf" ��
	//�������ļ� �� ����  GSAVFileInterface::GetShortFilename ����
	// vMediaDescri  ý����������
	// nMediaDescriNumber vMediaDescri �ĸ���

	// CMCC�ƴ洢˵��
	// �ļ�����·��	bucketName/foldername/filename, ����foldername��Ϊ��
	// czRootPath			bucketName/
	// czShortFilename		foldername/filename

	//dah �ƴ洢 
	// �ļ�����·�� ip:port/ducket|/foldername|/filename
	// czRootPath			bucketName/
	// czShortFilename		foldername/filename
	virtual EnumGSAVFileRetCode CreateFile( const char *czRootPath,
											const char *czShortFilename,	
											const StruGSMediaDescri *vMediaDescri, int nMediaDescriNumber,
											GSAVFileWriteInterface **ppAVFile ) = 0;

	//�򿪴��ڵ�¼���ļ�
	// czFilename �ļ��� ��   GSAVFileInterface::GetShortFilename ���� ���ļ���
	virtual EnumGSAVFileRetCode OpenFile( const char *czRootPath,
										  const char *czFilename,
										  EnumGSAVFileOpenMode eMode, 
										  GSAVFileReadInterface **ppAVFile ) = 0;

	virtual EnumGSAVFileRetCode OpenNormalFile(const char *czFullFilename
		, EnumGSAVFileOpenMode e, GSNormalFile **ppFile) = 0;

	//�����ļ�ϵͳ����
	virtual EnumFileSystemType GetMediumType(void) = 0;

	//ɾ���ļ�
	virtual EnumGSAVFileRetCode RemoveFile(const char *czFullFilename) = 0;

	//��ȡ�ļ���Ϣ
	virtual EnumGSAVFileRetCode GetFileInfo( const char *czFullFilename,
											 StruGSAVFileInfo* pstInfo ) = 0;

	//���ش洢�豸�Ŀռ��С, czStorageDevLabel �洢�豸��ǩ(�̷�),  ��λ Byte
	virtual EnumGSAVFileRetCode GetStorageDevSpace(const char *czStorageDevLabel,
					UInt64* pTotal,UInt64* pFree  ) = 0;

	// ��ȡ�����б�
	virtual EnumGSAVFileRetCode GetDiskList(StruDisk** pstDisk, int *iNums) = 0;
	virtual void FreeDiskList(StruDisk* pstDisk) = 0;

	// ����UUID
	virtual EnumGSAVFileRetCode CreateUUID(const char *szDir, const char *szUUID) = 0;

	// ��ȡUUID,szUUID�ڴ������洫�룬���Ȳ�С��64�ֽ�
	virtual EnumGSAVFileRetCode ReadUUID(const char *szDir, char *szUUID) = 0;

	// ����Ŀ¼
	virtual EnumGSAVFileRetCode MakeDir( const char *szDir ) = 0;

	// ɾ��Ŀ¼
	virtual EnumGSAVFileRetCode RemoveDir( const char *szDir ) = 0;

	//Ŀ�Ƿ�Ϊ�� 0 ��ʾ��
	virtual EnumGSAVFileRetCode IsDirEmpty( const char *szDir ) = 0;

	//����szDirĿ¼�µ��ļ����ļ�����Ϣ (��������Ŀ¼�ļ������ļ���)
	virtual EnumGSAVFileRetCode List(const char *szDir,
							StruNameInfo **vNameInfo, int *iNums) = 0;
	virtual void FreeNameList(StruNameInfo* pstDisk) = 0;
};


#endif //end _GS_H_AVFILEINTERFACE_H_
