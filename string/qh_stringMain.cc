#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "qh_string.h"
#include"assert.h"
#include<iostream>

void String_test1()
{
	qh::string s;
    if(strcmp(s.data(),"")!=0)
		assert(false);
	
	if(strcmp(s.c_str(),"")!=0)
		assert(false);
	if(s.size()!=0)assert(false);;
	//std::cout<<"string();测试1完成"<<std::endl;
}
void String_test2()
{
	qh::string s("1234");
	if(strcmp(s.data(),"1234")!=0)
		assert(false);
	
	if(strcmp(s.c_str(),"1234")!=0)
		assert(false);

	if(s.size()!=4)assert(false);

	int i=0;
	for(char a='1';a<'5';++a)
	{
		if(a!=s[i])
			assert(false);
		++i;
	}
	
	//std::cout<<"string(const char* s)测试2完成"<<std::endl;
}
void String_test3()
{
	qh::string s("1234",3);
	if(strcmp(s.data(),"123")!=0)
		assert(false);
	
	if(strcmp(s.c_str(),"123")!=0)
		assert(false);

	if(s.size()!=3)assert(false);

	int i=0;
	for(char a='1';a<'4';++a)
	{
		if(a!=s[i])
			assert(false);
		++i;
	}
	
	//std::cout<<"string(const char* s, size_t len)测试3完成"<<std::endl;
}
void String_test4()
{
	qh::string s1("45678");
	qh::string s(s1);

	if(strcmp(s.data(),"45678")!=0)
		assert(false);
	
	if(strcmp(s.c_str(),"45678")!=0)
		assert(false);

	if(s.size()!=5)assert(false);

	int i=0;
	for(char a='4';a<'9';++a)
	{
		if(a!=s[i])
			assert(false);
		++i;
	}
	
	//std::cout<<"string(const string& rhs);测试4完成"<<std::endl;
}

void String_test5()
{
	qh::string s1("45678");
	qh::string s;
	s=s1;
	if(strcmp(s.data(),"45678")!=0)
		assert(false);
	
	if(strcmp(s.c_str(),"45678")!=0)
		assert(false);

	int i=0;
	for(char a='4';a<'9';++a)
	{
		if(a!=s[i])
			assert(false);
		++i;
	}
	
	//std::cout<<"string& operator=(const string& rhs)测试5完成"<<std::endl;
}
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
   //测试单元1
	String_test1();
	//测试单元2
	String_test2();
	//测试单元3
	String_test3();
	//测试单元4
	String_test4();
	//测试单元5
    String_test5();
   std::cout<<"string Test is OK"<<std::endl;
#ifdef WIN32
    system("pause");
#endif

	return 0;
}
