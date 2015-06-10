#include "ini_parser.h"

#include<fstream>

#include<vector>

namespace qh
{
	bool INIParser::Parse(const std::string &ini_file_path)
	{
		std::fstream iniFile;
		std::string str;
		iniFile.open(ini_file_path.c_str());
		std::getline(iniFile,str,'\0');
		Parse(str.c_str(),str.size());
		return true;
	}

	bool INIParser::Parse(const char *ini_data, size_t ini_data_len, const std::string &line_seperator , const std::string &key_value_seperator )
	{
		 std::string::size_type pos;   
		 std::vector<std::string> result;   
		 std::string  str(ini_data);
		 str+=line_seperator;//扩展字符串以方便操作   
		 int size=str.size();     
		 
		 for(int i=0; i<size; i++)   
		 {   
			 
			 pos=str.find(line_seperator,i);     
			 if(pos<size)     
			 {      
				 std::string s=str.substr(i,pos-i);  
				 if(!s.empty())
				 {
					 result.push_back(s);   

					 std::string::size_type keyPos = s.find(key_value_seperator);

					 if ( keyPos != std::string::npos)
					 {
						 //cout<<strline<<endl;
						 std::string strKey = s.substr(0,keyPos);;
						 std::string strValue = s.substr(keyPos+key_value_seperator.size(),s.size()-keyPos);
						 // strKey = strSection + strKey;
						 dict.insert(make_pair(strKey,strValue));

					 }
				 }
				 i=pos+line_seperator.size()-1;    
			 }  
		 }  
		 return true;
	}

	

	const std::string& INIParser::Get(const std::string &key, bool *found)
	{
		if(dict.find(key)!=dict.end())
		return dict.find(key)->second;
		else
			return em;
	}
	const std::string& INIParser::Get(const std::string &section, const std::string &key, bool *found)
	{
         std::string::size_type pos;   
		 std::vector<std::string> result;   
		 std::string  str(section);
		 str+="\n";//扩展字符串以方便操作   
		 int size=str.size();     
		 
		 for(int i=0; i<size; i++)   
		 {   
			 
			 pos=str.find("\n",i);     
			 if(pos<size)     
			 {      
				 std::string s=str.substr(i,pos-i);  
				 if(!s.empty())
				 {
					 result.push_back(s);   

					 std::string::size_type keyPos = s.find("=");

					 if ( keyPos != std::string::npos)
					 {
						 //cout<<strline<<endl;
						 std::string strKey = s.substr(0,keyPos);;
						 std::string strValue = s.substr(keyPos+1,s.size()-keyPos);
						 if(strKey==key)
						 {
							 temp=strValue;
							 return temp;
						 }
						 // strKey = strSection + strKey;
						 //dict.insert(make_pair(strKey,strValue));

					 }
				 }
				 i=pos;    
			 }  
		 }  
        return em;
	}

}