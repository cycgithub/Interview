#include <stdlib.h>
#include<iostream>
#include "qh_vector.h"
#include"assert.h"
#include<string>
void Vector_test1()
{
	qh::vector<int> num_vect;
    num_vect.push_back(1);
	num_vect.push_back(2);

	assert(num_vect[1]==2);

	num_vect.pop_back();
	num_vect.pop_back();

	assert(num_vect.size()==0);
}

void Vector_test2()
{
	qh::vector<int> num_vect;
    num_vect.push_back(3);
	num_vect.push_back(4);

	qh::vector<int> num_vect1;
	num_vect1=num_vect;

	assert(num_vect1[1]==4);

	num_vect1.pop_back();
	num_vect1.pop_back();

	assert(num_vect1.size()==0);

}

void Vector_test3()
{
	qh::vector<std::string> num_vect;
    num_vect.push_back("234");
	num_vect.push_back("liming");

	qh::vector<std::string> num_vect1;
	num_vect1=num_vect;

	assert(num_vect1[1]=="liming");

	num_vect1.pop_back();
	num_vect1.pop_back();
	//std::cout<<num_vect1.size()<<std::endl;
	assert(num_vect1.size()==0);

}

void Vector_test4()
{
	qh::vector<std::string> num_vect;
    num_vect.push_back("234");
	num_vect.push_back("liming");

	qh::vector<std::string> num_vect1;
	num_vect1=num_vect;

	assert(num_vect1[1]=="liming");

	num_vect1.pop_back();
	num_vect1.pop_back();

	assert(num_vect1.size()==0);
	num_vect1.resize(3);

	assert(num_vect1.size()==3);

	num_vect1.reserve(6);
	assert(num_vect1.size()==3);


}
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
   //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

   Vector_test1();
   Vector_test2();
   Vector_test3();
   Vector_test4();
   std::cout<<"Vector Test is ok"<<std::endl;
#ifdef WIN32
    system("pause");
#endif

	return 0;
}