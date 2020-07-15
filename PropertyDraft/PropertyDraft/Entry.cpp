//==============================================================================
//  WARNING!!  This file is overwritten by the Block Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  D:\study\Mystudy\Pipe2015_NXopen\Src\V20150818\GetPoint.cpp
//
//        This file was generated by the NX Block Styler
//        Created by: hand
//              Version: NX 6
//              Date: 08-18-2015  (Format: mm-dd-yyyy)
//              Time: 14:56 (Format: hh-mm)
//
//==============================================================================

//==============================================================================
//  Purpose:  This TEMPLATE file contains C++ source to guide you in the
//  construction of your Block application dialog. The generation of your
//  dialog file (.dlx extension) is the first step towards dialog construction
//  within NX.  You must now create a NX Open application that
//  utilizes this file (.dlx).
//
//  The information in this file provides you with the following:
//
//  1.  Help on how to load and display your Block Styler dialog in NX
//      using APIs provided in NXOpen.BlockStyler namespace
//  2.  The empty callback methods (stubs) associated with your dialog items
//      have also been placed in this file. These empty methods have been
//      created simply to start you along with your coding requirements.
//      The method name, argument list and possible return values have already
//      been provided for you.
//==============================================================================

//------------------------------------------------------------------------------
//These includes are needed for the following template code
//------------------------------------------------------------------------------
#include "Entry.hpp"
#include <uf.h>
#include <exception>
#include "Excel\BasicExcel.hpp"
#include <NXOpen\Session.hxx>
#include "Property.hpp"
#include "Bom.hpp"
#include "AutoDraft.hpp"
#include "autodrafting.hpp"
#include "inheritProperty.hpp"
#include "HideMatNO.hpp"
//#include "UpdateFile.h"
#include "Excel/Excel.h"
#include "CaoLiaoBianHao.hpp"
#include "DlgRegister.h"

using namespace NXOpen;
bool g_regOK = false;

UINT QueryValue(HKEY rootkey, LPCTSTR SubKey, wchar_t *Name1, double& mmnumber)
{
	int i = 1;//1为成功
	HKEY hKey;
	DWORD dwtype;
	char content[256];
	DWORD cbData = 256;
	if (RegOpenKeyEx(rootkey, SubKey, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
	{
		//JHCOM_Print(34, NULL, 1);
		i = 0;
	}
	if (RegQueryValueEx(hKey, Name1, NULL, &dwtype, (unsigned char *)content, &cbData) != ERROR_SUCCESS)
	{
		//JHCOM_Print(35, Name1, 1); i = 0;
	}
	else
	{
		mmnumber = atof(content);
	}
	RegCloseKey(hKey);
	return i;
}

UINT QueryValue(HKEY rootkey, LPCTSTR SubKey, wchar_t *Name1, int& mmnumber)
{
	int i = 1;//1为成功
	HKEY hKey;
	DWORD dwtype;
	char content[256];
	DWORD cbData = 256;
	if (RegOpenKeyEx(rootkey, SubKey, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
	{
		i = 0;
	}
	if (RegQueryValueEx(hKey, Name1, NULL, &dwtype, (unsigned char *)content, &cbData) != ERROR_SUCCESS)
	{
	}
	else
	{
		mmnumber = atoi(content);
	}
	RegCloseKey(hKey);
	return i;
}

UINT SetValue(HKEY rootkey, LPCTSTR SubKey, wchar_t *Name1, double mmnumber)
{
	int i = 1;//i=1为成功
	HKEY hKey;
	if (RegOpenKeyEx(rootkey, SubKey, 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
	{
		if (ERROR_SUCCESS != RegCreateKey(rootkey, SubKey, &hKey))
		{
			//JHCOM_Print(32, NULL, 1);
			i = 0;
		}
	}
	char data[256] = "";
	sprintf(data, "%f", mmnumber);
	UINT cbLen = (UINT)strlen(data);
	if (RegSetValueEx(hKey, Name1, 0, REG_SZ, (const unsigned char *)data, cbLen) != ERROR_SUCCESS)
	{
		//JHCOM_Print(33, Name1, 1);
		i = 0;
	}
	RegCloseKey(hKey);
	return i;
}

double GetDouble(wchar_t* name)
{
	double msb = 0;
	int rcc = 0;
	LPCTSTR SubKey = L"S-1-5-19\\AutoPipe";

	int ar = QueryValue(HKEY_USERS, SubKey, name, msb);
	if (ar == 1)
		return msb;
	else
		return 0;
}


void SetDouble(wchar_t* name, double value)
{
	LPCTSTR SubKey = L"S-1-5-19\\AutoPipe";
	SetValue(HKEY_USERS, SubKey, name, value);
}

int GetInt(wchar_t* name)
{
	int msb = 0;
	int rcc = 0;
	LPCTSTR SubKey = L"S-1-5-18\\AutoPipe";

	int ar = QueryValue(HKEY_USERS, SubKey, name, msb);
	if (ar == 1)
		return msb;
	else
		return 0;
}

/*-------------------------------------------------------------------------
* Function Name   : SetDouble
* Description     : Set the double value in the subkey SubKey=L"S-1-5-18\\AutoPipe" for the input name.
* Note            : common function.
* Input           : name - Key name to set the related double value.
*                   value - New value for the key name.
* Output          : NULL.
* Return          : Double value for input name.
--------------------------------------------------------------------------*/
void SetInt(wchar_t* name, int value)
{
	LPCTSTR SubKey = L"S-1-5-18\\AutoPipe";
	SetValue(HKEY_USERS, SubKey, name, value);
}
//------------------------------- DIALOG LAUNCHING ---------------------------------
//
//    Before invoking this application one needs to open any part/empty part in NX
//    because of the behavior of the blocks.
//
//    Make sure the dlx file is in one of the following locations:
//        1.) From where NX session is launched
//        2.) $UGII_USER_DIR/application
//        3.) For released applications, using UGII_CUSTOM_DIRECTORY_FILE is highly
//            recommended. This variable is set to a full directory path to a file 
//            containing a list of root directories for all custom applications.
//            e.g., UGII_CUSTOM_DIRECTORY_FILE=$UGII_ROOT_DIR\menus\custom_dirs.dat
//
//    You can create the dialog using one of the following way:
//
//    1. USER EXIT
//
//        1) Remove the following conditional definitions:
//                a) #if USER_EXIT_OR_MENU
//                    #endif//USER_EXIT_OR_MENU
//
//                b) #if USER_EXIT
//                    #endif//USER_EXIT
//        2) Create the Shared Library -- Refer "Block Styler programmer's guide"
//        3) Invoke the Shared Library through File->Execute->NX Open menu.
//
//    2. THROUGH CALLBACK OF ANOTHER DIALOG
//
//        1) Remove the following conditional definition:
//             #if CALLBACK
//             #endif//CALLBACK
//        2) Call the following line of code from where ever you want to lauch this dialog.
//             GetPoint->Show_GetPoint();
//        3) Integrate this file with your main application file.
//
//    3. MENU BAR
//    
//        1) Remove the following conditional definition:
//                a) #if USER_EXIT_OR_MENU
//                   #endif//USER_EXIT_OR_MENU
//        2) Add the following lines to your MenuScript file in order to
//           associate a menu bar button with your dialog.  In this
//           example, a cascade menu will be created and will be
//           located just before the Help button on the main menubar.
//           The button, SAMPLEVB_BTN is set up to launch your dialog and
//           will be positioned as the first button on your pulldown menu.
//           If you wish to add the button to an existing cascade, simply
//           add the 3 lines between MENU LAUNCH_CASCADE and END_OF_MENU
//           to your menuscript file.
//           The MenuScript file requires an extension of ".men".
//           Move the contents between the dashed lines to your Menuscript file.
//        
//           !-----------------------------------------------------------------------------
//           VERSION 120
//        
//           EDIT UG_GATEWAY_MAIN_MENUBAR
//        
//           BEFORE UG_HELP
//           CASCADE_BUTTON BLOCKSTYLER_DLX_CASCADE_BTN
//           LABEL Dialog Launcher
//           END_OF_BEFORE
//        
//           MENU BLOCKSTYLER_DLX_CASCADE_BTN
//           BUTTON SAMPLEVB_BTN
//           LABEL Display SampleVB dialog
//           ACTIONS <path of Shared library> !For example: D:\temp\SampleVB.dll
//           END_OF_MENU
//           !-----------------------------------------------------------------------------
//        
//        3) Make sure the .men file is in one of the following locations:
//        
//           - $UGII_USER_DIR/startup   
//           - For released applications, using UGII_CUSTOM_DIRECTORY_FILE is highly
//             recommended. This variable is set to a full directory path to a file 
//             containing a list of root directories for all custom applications.
//             e.g., UGII_CUSTOM_DIRECTORY_FILE=$UGII_ROOT_DIR\menus\custom_dirs.dat
//    
//------------------------------------------------------------------------------


extern "C" DllExport void  ufusr(char *param, int *retcod, int param_len)
{
	try
	{

		//if (!checkuse())
			//return;


		/*double time = GetDouble(L"BXHH");
		long int curTime = CTime::GetCurrentTime().GetTime();
		if (curTime > time)
		{
			uc1601("软件过期",1);
			return;
		}*/

		EnterDlgRegister();//注册机相关

		if (g_regOK == 0)
		{
			UF_terminate();
			return;
		}


		UF_initialize();

		if(strcmp(param, "CUSTOM_GZ_PART_ATTR") == 0)
		{
			GZ_PART_ATTR_Main();
		}
		else if(strcmp(param, "CUSTOM_GZ_PART_BOM") == 0)
		{
			GZ_PART_BOM_Main();
			//GZ_PART_DRAFT_Main1();
		}
		else if(strcmp(param, "CUSTOM_GZ_PART_DRAFT") == 0)
		{
			GZ_PART_DRAFT_Main();
		}
        else if(strcmp(param, "CUSTOM_GZ_COPY_ATTR") == 0)
		{
			GZ_COPY_ATTR_Main();
			//GZ_PART_DRAFT_Main1();
		}
		else if(strcmp(param, "CUSTOM_GZ_HIDE_NO") == 0)
		{
			GZ_HIDE_NO_Main();
		}
		else if (strcmp(param, "CUSTOM_GZ_EXPORT_NO") == 0)
		{
			GZ_EXPORT_NO_Main();
		}

		UF_terminate();
		//示例代码
		/*Excel::CExcelUtil xls;

		CString xlsName =  L"C:\\mytemplate.xlsx";
		xls.OpenExcel(xlsName);
		xls.SaveAs("D:\\mydata.xlsx");
		xls.SetVisible(true);
		xls.SetActiveSheet(1);

		CString str;
		for (int i = 0; i < 10; i++)
		{
			str.Format(L"%d", i+1);
			xls.SetCellValue(i+2, 1, str);
		}
		xls.CloseExcel();*/

		//示例代码结束


	}
	catch(std::exception& ex)
	{
		//if ( !workPart->Preferences()->Modeling()->GetHistoryMode() )
		//{
			//throw NXException::Create("Create or edit of a Feature was recorded in History Mode but playback is in History-Free Mode.");
		//}

		//RYMirror::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
	}
	
}

//------------------------------------------------------------------------------
// This method specifies how a shared image is unloaded from memory
// within NX. This method gives you the capability to unload an
// internal NX Open application or user  exit from NX. Specify any
// one of the three constants as a return value to determine the type
// of unload to perform:
//
//
//    Immediately : unload the library as soon as the automation program has completed
//    Explicitly  : unload the library from the "Unload Shared Image" dialog
//    AtTermination : unload the library when the NX session terminates
//
//
// NOTE:  A program which associates NX Open applications with the menubar
// MUST NOT use this option since it will UNLOAD your NX Open application image
// from the menubar.
//------------------------------------------------------------------------------
extern "C" DllExport int ufusr_ask_unload()
{
	UF_terminate();
	//return (int)Session::LibraryUnloadOptionExplicitly;
	//return (int)NXOpen::Session::LibraryUnloadOptionImmediately;
	return (int)Session::LibraryUnloadOptionAtTermination;
}

//------------------------------------------------------------------------------
// Following method cleanup any housekeeping chores that may be needed.
// This method is automatically called by NX.
//------------------------------------------------------------------------------
extern "C" DllExport void ufusr_cleanup(void)
{
	try
	{
		//---- Enter your callback code here -----
	}
	catch(std::exception& ex)
	{
		//---- Enter your exception handling code here -----
	}
}
