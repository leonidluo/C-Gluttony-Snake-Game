#include "bmp.hpp"
#include "lcd.hpp"

//默认左上角显示
void BmpClass::Display(std::string pathname,int x0,int y0)
{
	FILE * fp = ::fopen(pathname.c_str(),"r");
	if(NULL == fp)
		throw std::runtime_error("fopen bmp picture error");
	
	
	int size = 0;
	int width,height,depth = 0;
	::fseek(fp,0x02,SEEK_SET);
	::fread(&size,4,1,fp);
	::fseek(fp,0x12,SEEK_SET);
	::fread(&width,4,1,fp);
	::fread(&height,4,1,fp);
	::fseek(fp,0x1c,SEEK_SET);
	::fread(&depth,2,1,fp);
	
	
	
	int n = (4 - (width * depth / 8) % 4) % 4;
	/*
	std::cout << size << " ";
	std::cout << width << " ";
	std::cout << height << " ";
	std::cout << depth << " ";
	std::cout << n << "\n";*/
	
	unsigned char * bmpPtr = new unsigned char[size - 54];
	
	::fread(bmpPtr,size - 54,1,fp);//读取像素数组
	
	unsigned char ca,cr,cg,cb;
	int i = 0;
	unsigned int color;
	for(int y = height - 1;y >= 0;y--)
	{
		for(int x = 0;x < width;x++)
		{
			cb = bmpPtr[i++];
			cg = bmpPtr[i++];
			cr = bmpPtr[i++];
			if(depth == 32)
				ca = bmpPtr[i++];
			color = ca << 24| cr << 16 | cg << 8 | cb;
			Lcd::GetLcd().Display(x + x0,y + y0,color);
		}
		i += n;
	}
	
	delete[] bmpPtr;
	fclose(fp);
	
	
}








