#include "ini_parser.h"
#include<iostream>
#include <string.h>
#include <assert.h>

void ini_test1()
{
    const char* ini_text= "a=1\nb=2\n"; 
    qh::INIParser parser;
	
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }
    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void ini_test2()
{
    const char* ini_text= "a=1||b=2||c=3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");

    

}

void ini_test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void ini_test4()
{
	const char* ini_text= "||a::1||b::2||c::3||"; 
    qh::INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", "::")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");

	 const std::string& a1 = parser.Get("a=1\nb=2\nc=3\n","a", NULL);
    assert(a1 == "1");

    std::string b1 = parser.Get("a=1\nb=2\nc=3\n","b", NULL);
    assert(b1 == "2");

    const std::string& c1 = parser.Get("a=1\nb=2\nc=3\n","c", NULL);
    assert(c1 == "3");
}
int main(int argc, char* argv[])
{
   //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好

    ini_test1();
    ini_test2();
    ini_test3();
    ini_test4();
    std::cout<<"INIParser Test is Ok"<<std::endl;
    return 0;
}
