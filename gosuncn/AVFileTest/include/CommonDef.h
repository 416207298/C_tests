#ifndef _MAVFS_COMMON_DEF_H_
#define _MAVFS_COMMON_DEF_H_

#include "GSMediaDefs.h"
#include "GSDefs.h"
#include "GSStrUtil.hpp"



#include <errno.h>

#ifdef _WIN32
#include <io.h>
#include <Windows.h>
#include <sys/stat.h>
#include <direct.h>
#else
#include <sys/vfs.h>    // or <sys/statfs.h>
#include <sys/io.h>
#endif
	

#define UUID_FILENAME "uuid.bat"

namespace MAVFS
{

typedef enum
{
	eOPEN_READ = 1,			//ֻ��	
	eOPEN_WRITE = 2,		//ֻд
	eOPEN_REPARE = 3		//�޸�
}EnumGSAVFileOpenMode;

typedef enum
{
	eNULL_SYSTEM = 0,
	eNOMAL_SYSTEM = 1,	// ��ͨ�ļ�ϵͳ
	eAliOSS_SYSTEM = 2, // �����ƴ洢�ļ�ϵͳ
	eONEST_SYSTEM = 3,	// �ƶ��ƴ洢
	eDAHUA_SYSTEM = 4,	// ���ƴ洢ϵͳ
	eHikHCS_SYSTEM = 5,   //�����ƴ洢
}EnumFileSystemType;

const int ACCESS_INTERFACE_C = 1;
const int ACCESS_INTERFACE_FUSE = 2;


typedef enum
{
	eAVF_END_OF_GOP = 1, //��һ֡�ɹ�,�����Ǹ�GOP�����һ֡
	eAVF_SUCCESS = 0, //�ɹ�
	eAVF_EIO = -1, //��дIO ʧ��
	eAVF_EINVALID = -2, //��������
	eAVF_READ_END = -3, //��ȡ����β
	eAVF_ERANGE = -4, //������Χ
	eAVF_ENEXIST =-5, //�ļ�������
	eAVF_EEXIST = -6, //�ļ��Ѿ�����
	eAVF_EOPER = -7,  //��ǰģʽ�²����еĲ���
	eAVF_ENFILESYSTEM = -8, //��֧�ֵ��ļ�ϵͳ
	eAVF_ENOPEN = -9, //�ļ�û�д�
	eAVF_EUNLOAD = -10, //�ļ�ϵͳ�Ѿ�ж��
	eAVF_NOT_IMPELETE = -11, //�ӿ�δʵ��
	eAVF_INIT_ERROR = -12,	//��ʼ��ʧ��
	eAVF_SDK_ERROR	= -13,	//����SDK�ӿ�ʧ��
	eAVF_FILE_ERROR	= -14,		//�ļ���ʽ����
	eAVF_MEMORY_ERROR = -15,	//�ڴ����
	eAVF_BUF_OVERFLOW = -16,	//���������
	eAVF_NO_FRAMEINDEX = -17,	//û��֡����
	eAVF_READ_CLOUDDATA_FAIL = -18,	//��ȡ�ƶ�����ʧ��
	eAVF_CREATE_CLOUDFILE_FAIL = -19, //�����ƴ洢�ļ�ʧ��
	eAVF_DEL_CLOUDFILE_FAIL = -20,	//ɾ���ƶ��ļ�ʧ��
	eAVF_OVERFILE_MAXSIZE = -21,	//�����ļ��������
	eAVF_ERROR = -22,				//�ڲ�����		
	eAVF_IDX_DAMAGED = -23,			//���������
	eAVF_EIDX_FILE = -24,  //�������ļ�
	eAVF_EVERSION = -25, //��֧�ֵİ汾
	eAVF_ENSPACE = -26, //û�ռ�


	//һ�����ڲ�����
#define eAVF_EINNER_MARK -100000
	eAVF_DIR_NEXIST = (eAVF_EINNER_MARK+(int)eAVF_ENEXIST), //Ŀ¼������
	eAVF_DIR_EEXIST = (eAVF_EINNER_MARK+(int)eAVF_EEXIST), //Ŀ¼�Ѿ�����
}EnumGSAVFileRetCode;



//����֡
typedef struct _StruGSAVFrame
{
	EnumGSMediaType eMediaType; //ý������
	Int64 iTimestamp; //����ʱ�� ,UTC �룬���ǵ�ǰ֡��index*֡�����25֡�Ļ��������40ms�������磺��һ֡��stamp����1*40,�ڶ�֡��2*40....��n֡��n*40
	int bKeyFrame; //�Ƿ�ؼ�֡	1���ؼ�֡   0���ǹؼ�֡��Ҳ���ǲ���I֡���Ǿ�Ϊ1�����Ǿ�Ϊ0

	const unsigned char *pMediaData; //ý������
	unsigned int iMediaDataLen; //ý�����ݳ���

	UInt32 iDurationStamp;  //����ʱ��
	bool isValidDurationStamp; //����ʱ���Ƿ���Ч
	_StruGSAVFrame(void) 
		:eMediaType(GS_MEDIA_TYPE_NONE)
		,iTimestamp(-1),bKeyFrame(0)
		,pMediaData(NULL), iMediaDataLen(0)
		,iDurationStamp(0),isValidDurationStamp(false)
	{
			
	}

}StruGSAVFrame;



//�ļ���Ϣ
typedef struct _StruGSAVFileInfo
{
	UInt64 iSize;			//�ļ���С
	UInt64 iTimeLength;		//�����ļ�ʱ�䳤��, ��λ��
	UInt64 iLastModifyTime; //����޸�ʱ�� �� UTC ����
	_StruGSAVFileInfo() : iSize(0),iTimeLength(0),iLastModifyTime(0)
	{

	}
}StruGSAVFileInfo;

#define DISK_LEN 128
#define UUID_LEN 128

typedef struct _StruDisk
{
	char szDisk[DISK_LEN+1];
	char szUUID[UUID_LEN+1];
	bool bActive;
	_StruDisk()
	{
		memset(this,0, sizeof(*this));
	}
} StruDisk, *StruDiskPtr;


} //end namspace MAVFS

//���þɵĶ���
#ifndef _DISABLE_MAVFS_NAMESPACE_
using namespace MAVFS;
#endif



#endif