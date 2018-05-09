#include "stdio.h"
#include "math.h"
#include <iostream>
#include <time.h>

#define SUPPORT_SIZE	2		// 高斯滤波窗口半径
#define IM_WIDTH		1920	// 输入图像宽和高
#define IM_HEIGHT		1080


// 计算高斯系数
void calGaussCoef(double *pGaussCoef)
{
	int		i, j, k;
	
	int		wlen = (SUPPORT_SIZE<<1) + 1;
	double	sum = 0;

	
	double a[5][5]={{0.72614904,0.81873075,0.85214379,0.81873075,0.72614904},
	{0.81873075,0.92311635,0.96078944,0.92311635,0.81873075},
	{0.85214379,0.96078944,1,0.96078944,0.81873075},
	{0.81873075,0.92311635,0.96078944,0.92311635,0.81873075},
	{0.72614904,0.81873075,0.85214379,0.81873075,0.72614904}
	}; 
	

	




	
	if(pGaussCoef)
	{
		
		for(i = -SUPPORT_SIZE; i <= SUPPORT_SIZE; i++)
		{
			for(j = -SUPPORT_SIZE; j <= SUPPORT_SIZE; j++)
			{
				//计算高斯系数，2.71828为自然数e
			//	pGaussCoef[ (i+SUPPORT_SIZE)*wlen + j+SUPPORT_SIZE ] = pow( 2.71828, (-double(i*i + j*j)/25) );
				pGaussCoef[ (i+SUPPORT_SIZE)*wlen + j+SUPPORT_SIZE ] = a[i+2][j+2];

			}
		}
	

	//double pGaussCoef[25]={0.72614904,0.81873075,0.85214379,0.81873075,0.72614904,0.81873075,0.92311635,0.96078944,0.92311635,0.81873075,
		//0.85214379,0.96078944,1,0.96078944,0.81873075,0.81873075,0.92311635,0.96078944,0.92311635,0.81873075,0.72614904,0.81873075,0.85214379,0.81873075,0.72614904};

		for(k = 0; k < 25; k++)
		{
			sum += *(pGaussCoef+k);
		}
		
		for(k = 0; k < 25; k++)	//进行归一化处理
		{
			*(pGaussCoef+k) /= sum;
		}
	}
}

// 2维卷积函数，实现2维图像高斯滤波
// pGaussCoef为高斯系数
// pSrcImg为原始图像
// pDstImg为滤波后图像
// height：图像高度
// width：图像宽度
// supportSize：高斯滤波窗口半径，直径为2*supportSize + 1
void conv2D(double *pGaussCoef, unsigned char *pSrcImg, unsigned char *pDstImg, int height, int width, int supportSize)
{
	int i, j;
	int m, n;
	int indexI, indexG;
	int sw = supportSize;
	int slen = sw*2 + 1;
	double sum;
	double *pTemp = NULL;

	int iI;
	//iI=i*width+j;
	int sws=sw+sw*slen;
	

	int hs=height-sw;
	int ws=width-sw;

	int temp=height*width;
	pTemp = new double[temp];
	for(i = 0; i < temp; i++)
	{
		pTemp[i] = (double)pSrcImg[i];
	}

	for(i = sw; i < hs; i++)
	{
		calGaussCoef(pGaussCoef);//======================================================
		
		for(j = sw; j < ws; j++)
		{
			sum = 0;
			iI=i*width+j;

			for(m = -sw; m <= sw; m++)
			{
				for(n = -sw; n <= sw; n++)
				{
					indexI = iI+m*width+n;
					indexG = sws+m*slen + n;
					sum += pSrcImg[indexI] * pGaussCoef[indexG];
				}
			}
			pDstImg[i*width + j] = (unsigned char)(sum);
		}
	}
}

void main()
{
	int wlen, imLen;
	time_t start, end;
	double *pGaussCoef = NULL;
	unsigned char *pSrc = NULL, *pDst = NULL;
	unsigned char buffer[1078];	//定义BMP图像文件头部缓冲区
	FILE *fin, *fout;

	if( !(fin=fopen("in.bmp","rb")) )	//打开原始输入图像
	{
        printf("Open file %s error!\n","in.bmp");
        exit(1);
	}
	if( !(fout=fopen("out.bmp","wb")) )	//创建滤波后输出图像
	{	
        printf("Open file %s error!\n","out.bmp");
        exit(1);
	}
	
	wlen	= SUPPORT_SIZE * 2 + 1;
	imLen	= IM_WIDTH * IM_HEIGHT;

	pGaussCoef = new double[wlen*wlen];
	pSrc = new unsigned char[imLen];
	pDst = new unsigned char[imLen];

	fread(buffer, 1, 1078, fin);	//读取1078字节BMP图像文件头信息
	fread(pSrc, sizeof(unsigned char), imLen, fin);	//从输入文件读入图像数据


	start = clock();
	conv2D(pGaussCoef, pSrc, pDst, IM_HEIGHT, IM_WIDTH, SUPPORT_SIZE);	//执行滤波
	end = clock();
	printf("running time is %d\n", end - start);

	fwrite(buffer, sizeof(unsigned char), 1078, fout);	
	fwrite(pDst, sizeof(unsigned char), imLen, fout);	//将滤波结果写到新文件
	
	delete[] pGaussCoef;
	delete[] pSrc;
	delete[] pDst;
	fclose(fin);
	fclose(fout);
}
