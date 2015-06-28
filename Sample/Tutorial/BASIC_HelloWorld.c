/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2013  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.22 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : WIDGET_SimpleListBox.c
Purpose     : Example demonstrating the LISTBOX widget
----------------------------------------------------------------------
*/

#include "GUI.h"
#include "LISTBOX.h"
#include <stddef.h>

/*******************************************************************
*
*       Static data
*
********************************************************************
*/
static const GUI_ConstString g_stListBox[] = {
	"zhouchang", "mianji", NULL
};

LISTBOX_Handle GListBox_Init()
{
	int Entries = GUI_COUNTOF(g_stListBox) - 1;
	LISTBOX_Handle hListBox;

	int xSize = LCD_GetXSize();
	//int ySize = GUI_GetYDistOfFont(&GUI_Font13B_1) * Entries;
	int ySize = LCD_GetYSize();
	/* Create the listbox */
	hListBox = LISTBOX_Create(g_stListBox, 0, 0, xSize, ySize, WM_CF_SHOW);
	return hListBox;
}
/*******************************************************************
*
*       Static code
*
********************************************************************
*/
/*******************************************************************
*
*       _DemoListBox
*/
void _DemoListBox(LISTBOX_Handle hListBox) {
	int i;
	
	/* Change current selection of the listbox */
	for (i = 0; i < Entries-1; i++) {
		GUI_Delay(500);
		LISTBOX_IncSel(hListBox);
		WM_ExecIdle();
	}
	GUI_Delay(75000);
	for (i = 0; i < Entries-1; i++) {
		GUI_Delay(500);
		LISTBOX_DecSel(hListBox);
		WM_ExecIdle();
	}
	GUI_Delay(7500);
	/* Delete listbox widget */
	LISTBOX_Delete(hListBox);
	GUI_ClearRect(0, 50, 319, 239);
	GUI_Delay(750);
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
	LISTBOX_Handle hListBox;
	int iCharKey;

	GUI_Init();
	GUI_SetBkColor(GUI_BLUE);
	GUI_Clear();
	GUI_SetColor(GUI_WHITE);
	GUI_SetFont(&GUI_Font32_ASCII);
	//GUI_DispStringHCenterAt("WIDGET_SimpleListBox - Sample", 160, 5);
	hListBox = GListBox_Init();
	if (NULL == hListBox)
	{
		return;
	}

	while(1)
	{
		iCharKey = GUI_GetKey();
		switch (iCharKey)
		{
			case 0://进入测试面积
				break;
			case 1://进入测量周长
				break;
			default:
				break;
		}
	}

	while(1) {
		_DemoListBox(hListBox);
	}
}

/*************************** End of file ****************************/

