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

	if(pGaussCoef)
	{
		for(i = -SUPPORT_SIZE; i <= SUPPORT_SIZE; i++)
		{
			for(j = -SUPPORT_SIZE; j <= SUPPORT_SIZE; j++)
			{
				//�����˹ϵ����2.71828Ϊ��Ȼ��e
				pGaussCoef[ (i+SUPPORT_SIZE)*wlen + j+SUPPORT_SIZE ] = pow( 2.71828, (-double(i*i + j*j)/25) );
			}
		}

		for(k = 0; k < wlen*wlen; k++)
		{
			sum += pGaussCoef[k];
		}
		
		for(k = 0; k < wlen*wlen; k++)	//���й�һ������
		{
			pGaussCoef[k] /= sum;
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


	pTemp = new double[height*width];
	for(i = 0; i < height*width; i++)
	{
		pTemp[i] = (double)pSrcImg[i];
	}

	for(i = sw; i < height - sw; i++)
	{
		for(j = sw; j < width - sw; j++)
		{
			sum = 0;
			calGaussCoef(pGaussCoef);

			for(m = -sw; m <= sw; m++)
			{
				for(n = -sw; n <= sw; n++)
				{
					indexI = (i+m)*width + j+n;
					indexG = (m+sw)*slen + n+sw;
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
	pSrc = new unsigned char[IM_WIDTH*IM_HEIGHT];
	pDst = new unsigned char[IM_WIDTH*IM_HEIGHT];

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
