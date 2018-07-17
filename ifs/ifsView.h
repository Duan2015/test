
// ifsView.h : CifsView ��Ľӿ�
//

#pragma once


class CifsView : public CView
{
protected: // �������л�����
	CifsView();
	DECLARE_DYNCREATE(CifsView)
	/*���һ��ö�٣���Ϊ������*/
private: //�����������ͼ��
	enum cmd{onifs1, onifs2, onifs3};
	enum cmd  InputCmd; 
	/*������*/
// ����
public:
	CifsDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CifsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onifs1();
	afx_msg void Onifs2();
	afx_msg void Onifs3();
};

#ifndef _DEBUG  // ifsView.cpp �еĵ��԰汾
inline CifsDoc* CifsView::GetDocument() const
   { return reinterpret_cast<CifsDoc*>(m_pDocument); }
#endif

