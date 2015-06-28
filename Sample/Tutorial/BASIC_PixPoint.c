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
File        : BASIC_PixPoint.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/

#include "GUI.h"
#include "BUTTON.h"

typedef struct tagPoint
{
	float x;
	float y;
}POINT_S;

static POINT_S g_astPointArray[] = {
	{0, 0}, 
	{10, 10},
	{20, 15},
	{30, 30},
	{40, 50},
	{70, 50},
	{70, 30},
	{70, 0}
};

#define ARRAYSIZE(array) (sizeof(array) / sizeof(array[0]))
/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*******************************************************************
*
*       MainTask
*/
void MainTask(void) {
  BUTTON_Handle hHandle;
  GUI_MEMDEV_Handle hMemHdl;
  GUI_MEMDEV_Handle hMemOld;
  GUI_MEMDEV_Handle hMemHdl2;
  GUI_MEMDEV_Handle hTemHdl;
  int iIndex;

	GUI_Init();
	GUI_Clear();
	GUI_SetColor(GUI_RED);
	GUI_SetBkColor(GUI_WHITE);

	//设置字体大小
	GUI_SetFont(&GUI_Font24_ASCII);
	//显示经度纬度
	GUI_DispStringAt("jingdu:", 10,20);
	GUI_DispStringAt("weidu:",180,20);

	//显示面积
	GUI_DispStringAt("mianji:", 10, 180);

	//创建memdev
	//获取lcd的size
	//LCD_GetXSize
	
	hMemHdl = GUI_MEMDEV_Create(50, 50, 150, 100);
	//hMemHdl2 = GUI_MEMDEV_Create(50, 50, 150, 100);
	if (NULL != hMemHdl)
	{
		hMemOld = GUI_MEMDEV_Select(hMemHdl);
		for (iIndex = 0; iIndex < ARRAYSIZE(g_astPointArray) - 1; iIndex++)
		{
			
			GUI_DrawPixel(g_astPointArray[iIndex].x, g_astPointArray[iIndex].y);
			//GUI_DrawLine(g_astPointArray[iIndex].x, g_astPointArray[iIndex].y,
				//         g_astPointArray[iIndex + 1].x, g_astPointArray[iIndex + 1].y);
			GUI_MEMDEV_CopyToLCD(hMemHdl);
			GUI_MEMDEV_Select(hMemOld);
		}
		
	}
	GUI_MEMDEV_Select(hMemOld);
	GUI_MEMDEV_Delete(hMemHdl);
  //hHandle = BUTTON_Create(110, 110, 100, 40, GUI_ID_OK, WM_CF_SHOW);
  
  //BUTTON_SetText(hHandle, "Click me...");
  //WM_SetFocus(hHandle);
  //while (GUI_WaitKey() != GUI_ID_OK);
//	GUI_MEMDEV_Select(hMemHdl2);
	

	//GUI_MEMDEV_Rotate(hMemHdl, hMemHdl2, 10, 10, 90, 1);
	//GUI_MEMDEV_CopyToLCD(hMemHdl2);
	GUI_Delay(1000);
	while(1);
}

/*************************** End of file ****************************/

