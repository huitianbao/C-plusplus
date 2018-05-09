#include "stdio.h"
#include "math.h"
#include <iostream>
#include <time.h>

#define SUPPORT_SIZE	2		// ��˹�˲����ڰ뾶
#define IM_WIDTH		1920	// ����ͼ���͸�
#define IM_HEIGHT		1080


// �����˹ϵ��
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
				//�����˹ϵ����2.71828Ϊ��Ȼ��e
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
		
		for(k = 0; k < 25; k++)	//���й�һ������
		{
			*(pGaussCoef+k) /= sum;
		}
	}
}

// 2ά���������ʵ��2άͼ���˹�˲�
// pGaussCoefΪ��˹ϵ��
// pSrcImgΪԭʼͼ��
// pDstImgΪ�˲���ͼ��
// height��ͼ��߶�
// width��ͼ����
// supportSize����˹�˲����ڰ뾶��ֱ��Ϊ2*supportSize + 1
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
	unsigned char buffer[1078];	//����BMPͼ���ļ�ͷ��������
	FILE *fin, *fout;

	if( !(fin=fopen("in.bmp","rb")) )	//��ԭʼ����ͼ��
	{
        printf("Open file %s error!\n","in.bmp");
        exit(1);
	}
	if( !(fout=fopen("out.bmp","wb")) )	//�����˲������ͼ��
	{	
        printf("Open file %s error!\n","out.bmp");
        exit(1);
	}
	
	wlen	= SUPPORT_SIZE * 2 + 1;
	imLen	= IM_WIDTH * IM_HEIGHT;

	pGaussCoef = new double[wlen*wlen];
	pSrc = new unsigned char[imLen];
	pDst = new unsigned char[imLen];

	fread(buffer, 1, 1078, fin);	//��ȡ1078�ֽ�BMPͼ���ļ�ͷ��Ϣ
	fread(pSrc, sizeof(unsigned char), imLen, fin);	//�������ļ�����ͼ������


	start = clock();
	conv2D(pGaussCoef, pSrc, pDst, IM_HEIGHT, IM_WIDTH, SUPPORT_SIZE);	//ִ���˲�
	end = clock();
	printf("running time is %d\n", end - start);

	fwrite(buffer, sizeof(unsigned char), 1078, fout);	
	fwrite(pDst, sizeof(unsigned char), imLen, fout);	//���˲����д�����ļ�
	
	delete[] pGaussCoef;
	delete[] pSrc;
	delete[] pDst;
	fclose(fin);
	fclose(fout);
}
