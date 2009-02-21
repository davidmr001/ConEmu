#pragma once
#include "kl_parts.h"

struct VirtualConsole
{
	bool IsForceUpdate;
	uint TextWidth, TextHeight;
	uint Width, Height;

	struct
	{
		bool isVisible;
		bool isVisiblePrev;
		bool isVisiblePrevFromInfo;
		short x;
		short y;
		COLORREF foreColor;
		COLORREF bgColor;
		BYTE foreColorNum, bgColorNum;
		TCHAR ch[2];
	} Cursor;

	HANDLE  hConOut_;
    HANDLE  hConOut();
	HDC     hDC, hBgDc;
	HBITMAP hBitmap, hBgBitmap;
	HBRUSH  hBrush0, hOldBrush, hSelectedBrush;
	SIZE	bgBmp;
	HFONT   hFont, hFont2, hSelectedFont, hOldFont;

	bool isEditor;
	BYTE attrBackLast;

	TCHAR *ConChar;
	WORD  *ConAttr;
	CONSOLE_SELECTION_INFO SelectionInfo;

	VirtualConsole(/*HANDLE hConsoleOutput = NULL*/);
	~VirtualConsole();

	bool InitFont(void);
	bool InitDC(BOOL abFull=TRUE);
	void Free(bool bFreeFont = true);
	bool Update(bool isForce = false, HDC *ahDc=NULL);
	void SelectFont(HFONT hNew);
	void SelectBrush(HBRUSH hNew);
	HFONT CreateFontIndirectMy(LOGFONT *inFont);
	bool isCharUnicode(WCHAR inChar);
	void BlitPictureTo(VirtualConsole *vc, int inX, int inY, int inWidth, int inHeight);
	bool CheckSelection(const CONSOLE_SELECTION_INFO& select, SHORT row, SHORT col);
	bool GetCharAttr(TCHAR ch, WORD atr, TCHAR& rch, BYTE& foreColorNum, BYTE& backColorNum);
};
