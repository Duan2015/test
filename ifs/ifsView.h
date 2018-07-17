
// ifsView.h : CifsView 类的接口
//

#pragma once


class CifsView : public CView
{
protected: // 仅从序列化创建
	CifsView();
	DECLARE_DYNCREATE(CifsView)
	/*添加一个枚举，作为命令行*/
private: //根据命令绘制图形
	enum cmd{onifs1, onifs2, onifs3};
	enum cmd  InputCmd; 
	/*添加完成*/
// 特性
public:
	CifsDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CifsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onifs1();
	afx_msg void Onifs2();
	afx_msg void Onifs3();
};

#ifndef _DEBUG  // ifsView.cpp 中的调试版本
inline CifsDoc* CifsView::GetDocument() const
   { return reinterpret_cast<CifsDoc*>(m_pDocument); }
#endif

