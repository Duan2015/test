
// ifsView.cpp : CifsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ifs.h"
#endif

#include "ifsDoc.h"
#include "ifsView.h"

#include <cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CifsView

IMPLEMENT_DYNCREATE(CifsView, CView)

BEGIN_MESSAGE_MAP(CifsView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ifs1, &CifsView::Onifs1)
	ON_COMMAND(ID_ifs2, &CifsView::Onifs2)
	ON_COMMAND(ID_ifs3, &CifsView::Onifs3)
END_MESSAGE_MAP()

// CifsView 构造/析构

CifsView::CifsView()
{
	// TODO: 在此处添加构造代码
	/*初始化*/
	InputCmd = onifs1;
}

CifsView::~CifsView()
{
}

BOOL CifsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CifsView 绘制

void CifsView::OnDraw(CDC* pDC /*pDC*/)
{
	CifsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	
	CRect r;
	GetClientRect(&r);//得到视图矩形边长
	double Left, Right, Top, Bottom;
	 double ViewWidth, ViewHeight, WinWidth, WinHeight;
	double x, y;//视图坐标
	int n;//循环标志
	double newx, newy;//变换得到的新坐标
	 int winx, winy;//变换得到的窗口坐标
	if (InputCmd == onifs1)
	{
		Left = -2;
		Bottom = 0;
		Right = 2;
		Top = 6;
		ViewWidth = Right - Left;//视图宽
		ViewHeight = Top - Bottom;//视图长
		WinWidth = r.Width();//窗口宽
		WinHeight = r.Height();//窗口长

		//
		double A[4] = { 0,0.85,0.09,- 0.09};
		double B[4] = { 0,0.02,- 0.28,0.25};
		double C[4] = { 0,- 0.02,0.3,0.3};
		double D[4] = { 0.25,0.83,0.11,0.09};
		double E[4] = { 0,0,0,0};
		double F[4] = { -0.14,1,0.6,0.7};
		//函数系数

		x = y = newx = newy = winx = winy= 0;
		n = 0;
		while (n < 100000)//循环打印100000个点
		{
			n++;
			//根据概率选择变换函数
			unsigned int p = rand() % 100;
			if(p < 2)//0.02
			{
				newx = A[0]*x + B[0]*y + E[0];
				newy = C[0]*x + D[0]*y + F[0];
			}
			else if(p < 86)//0.84
			{
				newx = A[1] * x + B[1] * y + E[1];
				newy = C[1] * x + D[1] * y + F[1];
			}
			else if(p < 93)//0.07
			{
				newx = A[2] * x + B[2] * y + E[2];
				newy = C[2] * x + D[2] * y + F[2];
			}
			else //0.07
			{
				newx = A[3] * x + B[3] * y + E[3];
				newy = C[3] * x + D[3] * y + F[3];
			}
			
			//得到一个视图点坐标
			x = newx;
			y = newy;
			//变换为窗口点坐标
			

			winx = floor((x - Left) / ViewWidth*WinWidth);
			winy = floor((y - Bottom) / ViewHeight*WinHeight);

			//打印到窗口
			if(winx>=0 && winx <= WinWidth && winy >= 0 && winy <= WinHeight)
			pDC->SetPixel(winx, winy, RGB(20, 200, 0));

		}
	}
	else if (InputCmd == onifs2)
	{
		Left = -5;
		Bottom = 0;
		Right = 1;
		Top = 10;
		ViewWidth = Right - Left;
		ViewHeight = Top - Bottom;
		WinWidth = r.Width();
		WinHeight = r.Height();

		double A[3] = { 0.787879,- 0.121212,0.181818};
		double B[3] = { -0.424242,0.257576,- 0.136364};
		double C[3] = { 0.242424,0.05303,0.090909};
		double D[3] = { 0.859848,0.05303,0.181818};
		double E[3] = { 1.758647,- 6.721654,6.086107};
		double F[3] = { 1.408065,1.377236,1.568035};

		x = y = newx = newy = winx = winy = 0;
		n = 0;
		while (n < 100000)
		{
			n++;
			//根据概率选择变换函数
			unsigned int p = rand() % 100;
			if (p < 90)//0.90
			{
				newx = A[0] * x + B[0] * y + E[0];
				newy = C[0] * x + D[0] * y + F[0];
			}
			else if (p < 95)//0.05
			{
				newx = A[1] * x + B[1] * y + E[1];
				newy = C[1] * x + D[1] * y + F[1];
			}
			else //0.05
			{
				newx = A[2] * x + B[2] * y + E[2];
				newy = C[2] * x + D[2] * y + F[2];
			}
			
			

			//得到一个视图点坐标
			x = newx;
			y = newy;
			//变换为窗口点坐标

			winx = floor((x - Left) / ViewWidth*WinWidth);
			winy = floor((y - Bottom) / ViewHeight*WinHeight);

			//打印到窗口
			if (winx >= 0 && winx <= WinWidth && winy >= 0 && winy <= WinHeight)
				pDC->SetPixel(winx, winy, RGB(0, 20, 150));
		}
	}
	else if (InputCmd == onifs3)
	{
		Left = -0.25;
		Bottom = -0.14;
		Right = 2;
		Top = 0.8;
		ViewWidth = Right - Left;
		ViewHeight = Top - Bottom;
		WinWidth = r.Width();
		WinHeight = r.Height();

		double A[2] = { 0.8,0.4};
		double B[2] = { 0,- 0.2};
		double C[2] = { 0,0.2};
		double D[2] = { -0.8,0.4};
		double E[2] = { 0,1.1};
		double F[2] = { 0,0};

		x = y = newx = newy = winx = winy = 0;
		n = 0;
		while (n < 100000)
		{
			n++;
			//根据概率选择变换函数
			unsigned int p = rand() % 100;
			if (p < 50)//0.5
			{
				newx = A[0] * x + B[0] * y + E[0];
				newy = C[0] * x + D[0] * y + F[0];
			}
			else //0.5
			{
				newx = A[1] * x + B[1] * y + E[1];
				newy = C[1] * x + D[1] * y + F[1];
			}
			

			//得到一个视图点坐标
			x = newx;
			y = newy;
			//变换为窗口点坐标

			winx = floor((x - Left) / ViewWidth*WinWidth);
			winy = floor((y - Bottom) / ViewHeight*WinHeight);
			//打印到窗口
			if (winx >= 0 && winx <= WinWidth && winy >= 0 && winy <= WinHeight)
				pDC->SetPixel(winx, winy, RGB(0, 150, 20));
		}
	}
	else
	{
		//do nothing
	}
	
	


}


// CifsView 打印

BOOL CifsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CifsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CifsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
} 


// CifsView 诊断

#ifdef _DEBUG
void CifsView::AssertValid() const
{
	CView::AssertValid();
}

void CifsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CifsDoc* CifsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CifsDoc)));
	return (CifsDoc*)m_pDocument;
}
#endif //_DEBUG


// CifsView 消息处理程序


void CifsView::Onifs1()
{
	// TODO: 在此添加命令处理程序代码
	InputCmd = onifs1;
	Invalidate();

}


void CifsView::Onifs2()
{
	// TODO: 在此添加命令处理程序代码
	InputCmd = onifs2;
	Invalidate();
}


void CifsView::Onifs3()
{
	// TODO: 在此添加命令处理程序代码
	InputCmd = onifs3;
	Invalidate();
}
