/*
******************************************
Copyright (C): GOSUN
Filename : GSSYSAPI.H
Author :  zouyx
Description: ƽ̨��غ���
********************************************
*/

#ifndef _GS_H_GSSYSAPI_H_
#define _GS_H_GSSYSAPI_H_

#define _FILE_OFFSET_BITS 64
#ifndef __USE_LARGEFILE64
#define __USE_LARGEFILE64
#endif
#include <stdio.h>

#include "GSFdtDefs.h"




typedef enum 
{
	OS_SUCCESS = 0,
	OS_FAIL = -1,
	OS_E_EXIST = -2, //�Ѿ�����
	OS_NOT_EXIST = -3, //���󲻴���
	OS_NOT_SUPPORT = -4, //��֧�ֵĹ���
	OS_E_BREAK = -5, //�������û��ж�
	OS_E_INVALID = -6, //��������
	OS_E_IO = -7, //IO ����
}EnumGSOSErrno;


#ifdef __cplusplus
#define ARFDT_API  extern "C" 
#endif








/*
*********************************************************************
*
*@brief : 
*
*********************************************************************
*/

// ����
ARFDT_API void GSSleep( int iMilSeconds );

//����ϵͳ���ܺ���
ARFDT_API int GSGetCPUProcessorNumber(void);

//���س���Ŀ¼, ����β /
ARFDT_API const char *GSGetApplicationPath(void);

// ��ȡ��ǰ�����ڴ�״̬, ��λ KByte
ARFDT_API void GSGetAppMemoryStatus( unsigned long& iWorkingSetSize, 
								 unsigned long& iPagefileUsage );


//ԭ�ӱ�������
ARFDT_API void GSAtomicSet(GSAtomic &iAtomic, long iVal);

ARFDT_API long GSAtomicGet(GSAtomic &iAtomic);

// ��*pAtomic ���е��������� �������Ӻ��ֵ
ARFDT_API long GSAtomicInc(GSAtomic &iAtomic);
// ��*pAtomic ���еݼ������� ���صݼ����ֵ
ARFDT_API long GSAtomicDec(GSAtomic &iAtomic);
//�Ƚ�iAtomic �Ƿ��� iOldVal ��ȣ� �����ȣ��� iAtomic �趨Ϊ iNewVal, ������TRUE�� ���򷵻�FALSE
ARFDT_API bool GSAtomicCompareExchange(GSAtomic &iAtomic, 
							const long iOldVal, const long iNewVal);


/*
*********************************************************************
*
*@brief : �ļ���غ���
*
*********************************************************************
*/

// ��ȡ�ռ��С, ��λ Bytes
ARFDT_API EnumGSOSErrno GSGetSpaceSize( const char* szDirName,
									 unsigned long long& lTotal,
									 unsigned long long& lUsed,
									 unsigned long long& lFree );


// ����Ŀ¼ ���� SO_E_EXIST ��ʾĿ¼�Ѿ�����
ARFDT_API EnumGSOSErrno GSMakeDir( const char* szPath );
// �ݹ鴴��Ŀ¼
ARFDT_API EnumGSOSErrno GSRecursiveMakeDir( const char* szPath );

// �Ƴ�Ŀ¼
ARFDT_API EnumGSOSErrno GSRemoveDir( const char* szFileName );
// ǿ���Ƴ�Ŀ¼����ɾ����Ŀ¼�����ļ�,���Ƴ�Ŀ¼��
ARFDT_API EnumGSOSErrno GSForcedRemoveDir( const char* szFileName );

// �ļ����Ƿ��
ARFDT_API bool GSIsFolderEmpty( const char* szDir );

// �Ƿ�Ϊ�ļ���,OS_SUCCESS ��ʾ���ļ��У� OS_FAIL ��ʾ���ļ���, ���� OS_NOT_EXIST ��ʾ�ļ������ڣ�OS_E_IO ϵͳ��⺯��ʧ�� 
ARFDT_API EnumGSOSErrno GSIsFolder( const char* szPathname );

// �Ƿ�Ϊ��ͨ�ļ�
ARFDT_API EnumGSOSErrno GSIsFile( const char* szFilename );


//��������
typedef enum
{
	GS_DISK_UNKNOWN  = 0, //δ֪����
	GS_DISK_FIXED = 1,    //����Ӳ��
	GS_DISK_CDROM = 2,  
	GS_DISK_REMOVEAABLE = 3,  //���Ȳ�δ洢  �� usb
	GS_DISK_REMOTE = 4,   //����Ӳ��
	GS_DISK_NOROOTDIR = 5,  //û�о���ص�Ŀ¼
	GS_DISK_RAMDISK = 6,   //�ڴ���
} GSDiskType;

typedef struct _GSStruDiskInfo
{
	const char *szName;  //��β����Ŀ¼�ָ�� "/��\"
	GSDiskType eType;	
}GSStruDiskInfo;

//���� false ��ʾ�жϼ����� true ��ʾ����, ���� OS_E_BREAK
typedef bool (*GSFunPtrDiskCallback)( const GSStruDiskInfo &info, void *pUserData);


//ö�����д�����Ϣ
ARFDT_API EnumGSOSErrno GSFetchDiskInfo(GSFunPtrDiskCallback fnFetchCallback,
										void *pUserData);




//���� false ��ʾ�жϼ����� true ��ʾ����, ���� OS_E_BREAK
typedef enum
{
	GS_IFOTHER = 0, //�����ļ� 
	GS_IFREG =  1, // ��ͨ�ļ�
	GS_IFDIR = 2, //Ŀ¼�ļ�
	GS_IFDISK = 3, //����	
}GSFileType;

typedef struct _GSStruFileInfo
{
	const char *szName;
	GSFileType eType;	
}GSStruFileInfo;
typedef bool (*GSFunPtrFileCallback)( const GSStruFileInfo &info, void *pUserData);



//����Ŀ¼�ļ�  
ARFDT_API EnumGSOSErrno GSFetchDir( const char* szDir, 
									GSFunPtrFileCallback fnFetchCallback,
									void *pUserData);


// ��ȡ���ļ����б�
ARFDT_API EnumGSOSErrno GSGetEmptyFolderList( const char* szDir, 
											 GSFunPtrFileCallback fnEmptyFolderCallback,
											 void *pUserData);

// ��ȡ�����б�
ARFDT_API EnumGSOSErrno GSGetDiskList( GSFunPtrFileCallback fnDiskCallback,
									  void *pUserData);

// �ļ��Ƿ����, ���� OS_SUCCESS, OS_FAIL, OS_NOT_EXIST
ARFDT_API EnumGSOSErrno GSIsFileExist( const char* szFileName );

// �Ƴ��ļ�
ARFDT_API EnumGSOSErrno GSRemove( const char* szFileName );

// ��ȡ�ļ���С ���� < 0 ��ʾʧ��, ��ʾ����� EnumGSOSErrno
ARFDT_API Int64 GSGetFileSize( const char* szFileName );

// ��ȡ�ļ�����޸�ʱ��, ���� <0  ��ʾʧ��, ��ʾ����� EnumGSOSErrno, 
// �������� Epoch UTC, �� 1970-01-01 00:00:00 ������
ARFDT_API Int64 GSGetLastModifiedTime( const char* szFileName );

//��ȡ�ļ���Ϣ�� ��ͬ�� GSGetFileSize��GSGetLastModifiedTime
ARFDT_API EnumGSOSErrno GSGetFileInfo(const char* szFileName, UInt64 *pLastModifiedTime, UInt64 *pFileSize );


//��ȡ����IP �б�
#define GS_MAX_IP_LEN 128
typedef struct _StruGSIfAddr
{
	bool isIPV6;
	char czIP[GS_MAX_IP_LEN];
	char czSubnetMartk[GS_MAX_IP_LEN];
	char czGateway[GS_MAX_IP_LEN];	
}StruGSIfAddr;

//ʧ�ܷ��� <0�� ������ʾ ppAddr ����, ppAddr���صĽ������ �ɹ������ GSFreeIFAddrLists�ͷ�
ARFDT_API int GSGetIFAddrLists( StruGSIfAddr **ppAddr );
ARFDT_API void GSFreeIFAddrLists( StruGSIfAddr *pAddr);
//�ж��Ƿ���ͬһ������
ARFDT_API bool GSIsSubnet(const char *czIpSrc,const char *czIpDst, const char *czSubnetMark);

//ΪԶ�̿ͻ�IP=czPeerIp �Ļ����ṩ����������IP
// czPeerIp �Զ�IP�� 
// czLocalp ���ر���ʹ�õ�IP
ARFDT_API bool GSGuessLocalIp( const char *czPeerIp, char czLocalp[GS_MAX_IP_LEN]);

//����UUID���û�Ψһʶ���ַ���
ARFDT_API const char *GSGenerateUUID(char (&buffer)[64]);

//�򿪽���,bShowWindow:�Ƿ��ִ̨��    // ʧ�ܷ���-1,�ɹ����ؽ���ID
ARFDT_API long GSOpenProcess( const char* szProcessPath , bool bShowWindow,
							 int argc,const char *argv[] );

//�رս���,millisecond:�ȴ������˳��ĳ�ʱʱ�䣬��λΪ����,Ĭ��-1��ȴ�ֱ�������˳�Ϊֹ
ARFDT_API bool GSCloseProcess( long lProcessID,int millisecond = 3000);

//��ֹ����
ARFDT_API bool GSTerminateProcess( long lProcessID );

//�����Ƿ����
ARFDT_API bool GSIsProcessAlive( long lProcessID );


// ö��ָ��·���Ľ���
//szProcessPath:ָ��·��
//lProcessID:�������ID�����飬�ɺ���д����Ӧ����ID
//iProcessNum:�������ID����Ĵ�С������ִ�к�����ָ��·���½��̵�ʵ�ʸ���
ARFDT_API bool GSGetAliveProcessList( const char* szProcessPath, long *lProcessID, int &iProcessNum );

//��̬�⶯̬����

//���ض�̬�⣬ ʧ�ܷ��� NULL�� �ɹ���Ҫ���� GSFreeLibrary�ͷ�
// czDllFilename  ��̬���ļ���������·����
ARFDT_API void *GSLoadLibrary(const char *czDllFilename);
//�ͷŶ�̬�� pModule GSLoadLibrary����ֵ 
ARFDT_API void GSFreeLibrary(void *pModule);
//��ȡ��̬�⺯��, ʧ�ܷ��� NULL
//pModule ��̬����
//czFounctionName  ������
ARFDT_API void *GSGetProcAddress(void *pModule, const char *czFounctionName);

//��ȡ��ǰ·��
//szPathBuf  ���ص�Ŀ¼����, ����ΪNULL
//nBufSize  szPathBuf �Ĵ�С
//ʧ�ܷ��� NULL�� �ɹ�����ָ�� szPathBuf ��ָ��
ARFDT_API const char * GSGetCurrentDir( char *szPathBuf, int nBufSize );

//���õ�ǰ·��
ARFDT_API bool GSSetCurrentDir( const char *czPath);

//��ȡ��̬��������·��
//szPathBuf  ���ص�Ŀ¼����, ����ΪNULL
//nBufSize  szPathBuf �Ĵ�С
//ʧ�ܷ��� NULL�� �ɹ�����ָ�� szPathBuf ��ָ��
ARFDT_API const char *GSGetDllDir(char *szPathBuf, int nBufSize);

//���ö�̬��������·��
ARFDT_API bool GSSetDllDir( const char *czPath);

// IO ��������  , ֧��64 λ�������÷��ο� c   stream i/o

#define gsfile FILE
#define gsfpos_t  fpos_t
#define gsoff_t Int64

#define GS_FSEEK_CUR SEEK_CUR
#define GS_FSEEK_END SEEK_END
#define GS_FSEEK_SET SEEK_SET


#define gsfopen(filename, mode) fopen(filename,mode)
#define gsfclose(stream) fclose(stream)
#define gsfread(buffer,size,count,stream) fread(buffer,size,count,stream)
#define gsfwrite(buffer,size,count,stream) fwrite(buffer,size,count,stream)
#define gsferror(stream)  ferror(stream)
#define gsfeof(stream) feof(stream)
#define gsrewind(stream) rewind(stream)
#define gsfflush(stream) fflush(stream)
#define gsfgetc(stream)  fgetc(stream)
#define gsfputc(c, stream)	fputc(c, stream)
#define gsfputs(str, stream)	fputs(str, stream)
#define gsfgets(strbuf,bufsize,stream) fgets(strbuf,bufsize,stream)
#define gsfgetpos(stream, posptr) fgetpos( stream, posptr)
#define gsfsetpos(stream, pposptr) fsetpos( stream, pposptr)
#define gsfscanf  fscanf





#ifdef _MSWINDOWS_

#define gsfseek(stream, offset,origin) _fseeki64(stream, offset,origin )
#define gsftell(stream ) _ftelli64(stream)
#define gsclearerr(stream)  clearerr_s(stream)
   
#else

#define gsfseek(stream, offset,origin) fseeko(stream, offset,origin )
#define gsftell(stream ) ftello(stream)
#define gsclearerr(stream)  clearerr(stream)

#endif


#endif //end _GS_H_GSSYSAPI_H_
