/*************************************************************************
	> File Name: filenameio.h
	> Author: lcmf
	> Mail: mrhlingchen@163.com 
	> Created Time: 2018��03��12�� ����һ 14ʱ31��22��
 ************************************************************************/
#ifndef _FILE_NAME_IO_H__
#define _FILE_NAME_IO_H__

#include<iostream>
#include <stdio.h>
#include <vector>

#ifndef _WIN32
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/time.h>
#else
#include <iconv.h>
#endif
using namespace std;

/*
	�������ƣ�GetFileLastModifyTime(char *strPath, int *size, long *modify_time)
	�������ã���ȡ�ļ�������޸�ʱ��
	���������char * strPath ��Ҫ���ļ�
	����������ļ���С
	�������������޸ĵ�ʱ��
*/
void GetFileLastModifyTime(char *strPath,int *size,long *modify_time);

string ReplaceStr(string strSrc, const char * chBar);


string LongToStr(uint64_t num);


//����ʱ����ĳ���ļ����´����ļ���,�������ļ�������
char* CreateDirectoryByTime(char *chPath);


//�����ļ����ƴ����ļ���,����ֵΪ0��ʾ�����ɹ�������1��ʾ�ļ����Ѵ��ڣ�����-1��ʾ����ʧ��λ��ԭ��
int createDirectory(const char* strPath);

int gb2312toutf8(const char *sourcebuf, size_t sourcelen, char *destbuf, size_t destlen);

int utf8togb2312(const char *sourcebuf, size_t sourcelen, char *destbuf, size_t destlen);

//��������ļ���
int safeCreateDirectory(char* strPath);


#ifndef _WIN32
//��ȡ��ǰϵͳʱ����嵽����
int GetCurrentTime();
#endif

//��ȡ��ǰʱ����嵽Сʱ
int GetCurrentHour(char* strCurrnet);

//�����ļ���
void ReverseDirctory(const char* strPath, std::vector<std::string> & arrJsonFilePath);

/*
	�������ƣ�scanDir
	�������ã������ļ�������
	���������const char* dir ,�����ļ���
	���������vector<string>& �������
	���������int depth �������
	���������bool bDirOrFile ������ļ������ļ��У�true��ʾֻ�����ļ��У�false��ʾֻ�����ļ�
	����ֵ����
*/
void scanDir(const char *dir, std::vector<std::string>& arrJsonPath, int depth, bool bDirOrFile);

/*
	��������:IntToStr(int num)
	�������ã�����ת�ַ���
	���������int num ��Ҫ���������
	����ֵ��������ַ���
*/
std::string IntToStr(int num);

/*
	�������ƣ�
	�������ã���ȡ��ǰִ�г���·��
	���������
*/
size_t GetCurrentExePath( char* processdir,char* processname, size_t len);


//�����ļ�
bool CutFile(std::string strSrc, std::string strDis);


//ɾ�������ļ�
bool removeAllFile(char *strDir);


//substring
std::string substr(char* str, unsigned int start, unsigned int end);

/*
	�������ƣ�SplitWords(char* strSrc, std::vector<std::string> & arrWords);
	��������:�ָ��ַ���
*/
int SplitWords(char* strSrc, std::vector<std::string> & arrStr, char chStr = '_');
#endif  //FILENAMEIO__
