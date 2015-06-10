#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))


 

int resolve(const char* input)
{
    int n=0;
	char a=input[1];
	int i=0,j=0;
	int *start=NULL;
	int *end=NULL;
    int *height=NULL;
    while(input[i]!='\0')
	{
		while(input[i]!='\n'){++i;++j;}
		char *len=(char*)malloc(j*sizeof(char));
		strncpy(len,input,j);
        n=atoi(len);

		if(n<=0)return 0;
        free(len);

		start=(int*)malloc(sizeof(int)*n);
		end=(int*)malloc(sizeof(int)*n);
		height=(int*)malloc(sizeof(int)*n);
        
		for(int k=0;k<n;++k)
		{
			++i;
			j=0;
			while(input[i]!=','){++i;++j;}
			len=(char*)malloc(j*sizeof(char));
			strncpy(len,input+i-j,j);
			start[k]=atoi(len);
			free(len);

            j=0;++i;
			while(input[i]!=','){++i;++j;}
			len=(char*)malloc(j*sizeof(char));
			strncpy(len,input+i-j,j);
			end[k]=atoi(len);
			free(len);

			j=0;++i;
			while(input[i]!='\n'&&input[i]!='\0'){++i;++j;}
			len=(char*)malloc(j*sizeof(char));
			strncpy(len,input+i-j,j);
			height[k]=atoi(len);
			free(len);
		}
		break;
		
	}
	int temps=start[0];
	int tempe=end[0];
	int temph=height[0];
	int result=0;
	int hk=0;
	for(i=0;i<n-1;++i)
	{
		if(end[i]>=start[i+1])
		{
			if(end[i]<end[i+1])
			{
				tempe=end[i+1];
			}
			if(temph>height[i]&&height[i]<height[i+1])
			{
				result+=start[i+1]-temps+2*temph-height[i]*2;
				temps=start[i+1];
				tempe=end[i+1];
				temph=height[i+1];
			}
			else if(temph<height[i+1])
			{
				temph=height[i+1];hk=i+1;
			}
		}
		else
		{
			result+=tempe-temps+2*temph+start[i+1]-end[i];
			temps=start[i+1];
			tempe=end[i+1];
			temph=height[i+1];
		}
	}
	result+=tempe-temps+2*temph;
	result+=start[0];
	//std::cout<<result<<std::endl;
	free(start);
	free(end);
	free(height);

	return result;
}

int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
		"7\n1,2,1\n2,3,2\n3,4,1\n4,5,3\n8,9,10\n9,10,2\n10,11,9",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20,53};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
		
    }
	std::cout<<"Climber Test is OK"<<std::endl;
    return 0;
}
