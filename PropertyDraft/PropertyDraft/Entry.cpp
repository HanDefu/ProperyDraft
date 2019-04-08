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

using namespace NXOpen;

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
		if (!checkuse())
			return;

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
