#include<stdio.h>
#include<stdlib.h>


struct data
{
	int *p;
	int length;//���鳤��
	int status;//״̬0������1������2�ǽ���
};

struct findarr
{
	int **p;  // ָ������
	int n;  // �ҵ��Ľ������
};
typedef struct findarr findaddr;

//���ӣ�ɾ�����޸ģ���ѯ����ʼ��

void addOneElement(struct data *pdata, int num);  // ����һ��Ԫ��
void addOneArray(struct data *pdata, int *array, int len);  // ����һ������
void init(struct data *pdata);  // ��һ�γ�ʼ��
void reinit(struct data *pdata);  // ���³�ʼ��
void deleteone(struct data *pdata, int num);  // ɾ���ҵ��ĵ�һ��Ԫ��
void deleteall(struct data *pdata, int num);  // ɾ���ҵ�������Ԫ��
int * find(struct data *pdata, int num);  // �����ҵ��ĵ�һ��Ԫ�صĵ�ַ
findaddr  findall(struct data *pdata, int num);  // ���������ҵ�Ԫ�صĵ�ַ
void  printfall(struct data *pdata);  // ��ӡ���е�����
void sort(struct data *pdata, int type);  // ����type=1��С����;type=2�Ӵ�С
void update(struct data *pdata, int oldnum, int newnum);  // �޸��ҵ��ĵ�һ��Ԫ��
int insert(struct data *pdata, int pos_num, int num, int behindOrFront);  // behindOrFrontΪ0��pos_num֮ǰ�壬1�ں��
int max(struct data *pdata);  // return the maximum value
int min(struct data *pdata);  // return the minimum value
