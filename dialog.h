//
// Powered by tapy.me/weikton
//
 
#pragma once

#define DIALOG_STYLE_MSGBOX		0
#define DIALOG_STYLE_INPUT		1
#define DIALOG_STYLE_LIST		2
#define DIALOG_STYLE_PASSWORD	3
#define DIALOG_STYLE_TABLIST	4
#define DIALOG_STYLE_TABLIST_HEADERS	5

#include <string>

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}

class CDialogWindow
{
public:
	CDialogWindow();
	~CDialogWindow() {};

	void Render();
	void Clear();

	void Show(bool bShow);
	void SetInfo(char* szInfo, int length);
	void MakeList();
	void MakeChildForList();
	void MakeListHeaders();
	void PutListHeadersTitle();
	
	void StyleColorsDialog(float roundSize);

	bool IsShowing() { return m_bIsActive; };

public:
	bool		m_bIsActive;
	uint8_t 	m_byteDialogStyle;
	uint16_t	m_wDialogID;
	char		m_utf8Title[64*3 + 1];
	char*		m_putf8Info;
	char* 		m_pszInfo;
	char		m_utf8Button1[64*3 + 1];
	char		m_utf8Button2[64*3 + 1];

	float		m_fSizeX;
	float 		m_fSizeY;

	int m_bSL;
	
	uint8_t m_iSelectedItem;
	std::string m_strSelectedItemText;

	int m_selectedItem;
	
	int m_iNumberOfTaps;
	uint32_t m_lastTimeTap;
	uint32_t m_touchDownTime;
	bool m_bSplitted;
};