#ifndef QIHOO_STRING_H_
#define QIHOO_STRING_H_

#include <stdlib.h>
#include <string.h>
namespace qh
{
    class string {
    public:
        //ctor
        string();
        string(const char* s);
        string(const char* s, size_t len);
        string(const string& rhs);

        string& operator=(const string& rhs);

        //dtor
        ~string();

        //get
        size_t size() const;
        const char* data() const;
        const char* c_str() const;

        // set & get
        char operator[](size_t index);

    private:
        char*  data_;
        size_t len_;
    };
     string::string()
        : data_(NULL), len_(0)
    {
		data_=new char[1];
		data_[0]='\0';
    }
    //cyc edit
    string::string( const char* s )
    {
		if(s==NULL)
		{
			data_=new char[1];
			data_[0]='\0';
			len_=0;
		}
		else
		{
			int len=strlen(s);
			data_=new char[len+1];
			len_=len;
			strcpy(data_,s);
		}
    }
    //cyc edit
    string::string( const char* s, size_t len )
    {
		if(len==NULL)
		{
			data_=new char[1];
			data_[0]='\0';
			len_=0;
		}
		else
		{

			data_=new char[len+1];
			len_=len;
			strncpy(data_,s,len);
			data_[len]='\0';
		}
    }
     //cyc edit
    string::string( const string& rhs )
    {
		int len=strlen(rhs.data_);
		data_=new char[len+1];
		len_=len;
		strcpy(data_,rhs.data_);
    }
    //cyc edit
    string& string::operator=( const string& rhs )
    {
		if(this!=&rhs)
		{
			delete[] data_;
			data_=new char[strlen(rhs.data_)+1];
			len_=strlen(rhs.data_);
			strcpy(data_,rhs.data_);
		}
        return *this;
    }
    //cyc edit
    string::~string()
    {
       delete[] data_;
	   len_=0;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return c_str();
    }

    const char* string::c_str() const
    {
        return data_;
    }
    //cyc edit
    char string::operator[]( size_t index )
    {
        return data_[index];
    }
}

#endif
