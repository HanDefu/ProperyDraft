﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block UI Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  C:\codeRoyal\Royal_code\install\application\Bom.cpp
//
//        This file was generated by the NX Block UI Styler
//        Created by: Administrator
//              Version: NX 10
//              Date: 03-18-2019  (Format: mm-dd-yyyy)
//              Time: 20:19 (Format: hh-mm)
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
//  1.  Help on how to load and display your Block UI Styler dialog in NX
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
#include "Bom.hpp"
#include "Common.h"
#include "Common_UI.h"
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

static NXString s_projectName, s_projectNumber, s_caiLiaoDanHao;


void ReadExcelConfigData( StlNXStringVector& types )
{
	BasicExcel excel;
    char regfile[256]="";
    sprintf_s(regfile,"%s\\Parameter\\Config.xls",getenv("UGII_USER_DIR"));
	bool isOk = excel.Load(regfile);
	if( isOk )
	{
        int num = excel.GetTotalWorkSheets();
        for( int idx = 0; idx < num; ++idx )
        {
            const wchar_t* sheetName = excel.GetUnicodeSheetName(idx);
			types.push_back(WCHARTOCHAR(sheetName));
        }
	}
	return;
}
//------------------------------------------------------------------------------
// Initialize static variables
//------------------------------------------------------------------------------
Session *(Bom::theSession) = NULL;
UI *(Bom::theUI) = NULL;
//------------------------------------------------------------------------------
// Constructor for NX Styler class
//------------------------------------------------------------------------------
Bom::Bom()
{
    try
    {
        // Initialize the NX Open C++ API environment
        Bom::theSession = NXOpen::Session::GetSession();
        Bom::theUI = UI::GetUI();
        theDlxFileName = "Bom.dlx";
        theDialog = Bom::theUI->CreateDialog(theDlxFileName);
        // Registration of callback functions
        theDialog->AddApplyHandler(make_callback(this, &Bom::apply_cb));
        theDialog->AddOkHandler(make_callback(this, &Bom::ok_cb));
        theDialog->AddUpdateHandler(make_callback(this, &Bom::update_cb));
        theDialog->AddInitializeHandler(make_callback(this, &Bom::initialize_cb));
        theDialog->AddDialogShownHandler(make_callback(this, &Bom::dialogShown_cb));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        throw;
    }
}

//------------------------------------------------------------------------------
// Destructor for NX Styler class
//------------------------------------------------------------------------------
Bom::~Bom()
{
    if (theDialog != NULL)
    {
        delete theDialog;
        theDialog = NULL;
    }
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
//        1) Create the Shared Library -- Refer "Block UI Styler programmer's guide"
//        2) Invoke the Shared Library through File->Execute->NX Open menu.
//
//------------------------------------------------------------------------------
void GZ_PART_BOM_Main()
{
    Bom *theBom = NULL;
    try
    {
        theBom = new Bom();
        // The following method shows the dialog immediately
        theBom->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Bom::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    if(theBom != NULL)
    {
        delete theBom;
        theBom = NULL;
    }
}



int Bom::Show()
{
    try
    {
        theDialog->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Bom::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//---------------------Block UI Styler Callback Functions--------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Callback Name: initialize_cb
//------------------------------------------------------------------------------
void Bom::initialize_cb()
{
    try
    {
        group = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group"));
        toggleOutAll = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("toggleOutAll"));
        enumType = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("enumType"));
        bodySelect = dynamic_cast<NXOpen::BlockStyler::BodyCollector*>(theDialog->TopBlock()->FindBlock("bodySelect"));
        group0 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group0"));
        matName = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("matName"));
        MatNO = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("MatNO"));
        matSize = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("matSize"));
        material = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("material"));
        desnity = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("desnity"));
        length = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("length"));
        togglearea = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("togglearea"));
        togglequantity = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("togglequantity"));
        toggleWeight = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("toggleWeight"));
        unitPrice = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("unitPrice"));
        totalPrice = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("totalPrice"));
        supplier = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("supplier"));
        toggleRemark = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("toggleRemark"));
		group1 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group1"));
		projectName = dynamic_cast<NXOpen::BlockStyler::StringBlock*>(theDialog->TopBlock()->FindBlock("projectName"));
		projectNumber = dynamic_cast<NXOpen::BlockStyler::StringBlock*>(theDialog->TopBlock()->FindBlock("projectNumber"));
		stringCaiLiaoDanHao = dynamic_cast<NXOpen::BlockStyler::StringBlock*>(theDialog->TopBlock()->FindBlock("stringCaiLiaoDanHao"));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Bom::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Callback Name: dialogShown_cb
//This callback is executed just before the dialog launch. Thus any value set 
//here will take precedence and dialog will be launched showing that value. 
//------------------------------------------------------------------------------
void Bom::dialogShown_cb()
{
    try
    {
        //---- Enter your callback code here -----
        //StlNXStringVector types;
        //types.push_back("全部");
        //ReadExcelConfigData( types );
        //enumType->GetProperties()->SetEnumMembers("Value",types);
		UI_StringSetValue(projectName, s_projectName);
		UI_StringSetValue(projectNumber, s_projectNumber);
		UI_StringSetValue(stringCaiLiaoDanHao, s_caiLiaoDanHao);
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Bom::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

static logical CheckBodyType(tag_t body, NXString& type)
{
	logical is = false;
    char attriValue2[133] = "";
    int has = USER_ask_obj_string_attr( body , "材料类型" , attriValue2 );
    if( has && 0 == strcmp(attriValue2,type.GetLocaleText()))
    {
        is = true;
    }
	return is;
}

NXString GetBodyType(tag_t body)
{
	logical is = false;
	char attriValue2[133] = "";
	int has = USER_ask_obj_string_attr( body , "材料类型" , attriValue2 );
	return NXString(attriValue2);
}
	

//序号	材料名称	材料编号	规格	材质	密度	长度（mm)	宽度（mm)	      数量	单重   总重量	单价	总价	供应商	备注                钢材1//20201031插入单
//序号	材料名称	材料编号	规格	材质	密度	长度（mm)	宽度（mm)	      数量	重量   总重量   单价	总价	供应商	备注                铝材5//20201031插入单

//序号	材料名称	材料编号	规格	材质	长度（mm)	宽度（mm)	面积	      数量	总面积	单价	 总价	供应商	备注	        铝板2
//序号	材料名称	材料编号	规格	材质	长度（mm)	宽度（mm)	面积	      数量	总面积	单价	总价	供应商	备注            树脂板3
//序号	材料名称	材料编号	规格	材质	长度（mm)	宽度（mm)	面积	      数量	总面积	单价	总价	供应商	备注            石材4

//序号	材料名称	材料编号	规格	        长度（mm)	宽度（mm)	面积	      数量	总面积	单价	总价	供应商	备注                玻璃6
//序号	材料名称	材料编号	规格	        长度（mm)	宽度（mm)	面积	      数量	总面积	单价	总价	供应商	备注                屋面瓦9
//序号	材料名称	材料编号	规格	        长度（mm)	宽度（mm)	面积	      数量	总面积	单价	总价	供应商	备注	            铜饰10

//序号	材料名称	材料编号	规格  	        长度（mm)	宽度（mm)	密度	      数量	        单价	总价	供应商	备注                木雕8
//序号	材料名称	材料编号	规格   材质     长度（mm)	宽度（mm)	密度	面积  数量	总面积	单价	总价	供应商	备注                辅材11  //20201031插入面积

//序号	材料名称	材料编号	规格   材质	    长度	数量	单价	总价	供应商	备注                                                五金件7

void Bom::GetBOMInformation(vtag_t bombodies,int type,StlNXStringVectorVector& BOMStr )
{
    StlNXStringVector attriName;
    BOMStr.clear();
    logical logicalmatName = matName->GetProperties()->GetLogical("Value");
    logical logicalMatNO = MatNO->GetProperties()->GetLogical("Value");
    logical logicalmatSize = matSize->GetProperties()->GetLogical("Value");
    logical logicalmaterial = material->GetProperties()->GetLogical("Value");
    logical logicaldesnity = desnity->GetProperties()->GetLogical("Value");
    logical logicallength = length->GetProperties()->GetLogical("Value");
    logical logicalarea = togglearea->GetProperties()->GetLogical("Value");
    logical logicalquantity = togglequantity->GetProperties()->GetLogical("Value");
    logical logicalWeight = toggleWeight->GetProperties()->GetLogical("Value");
    logical logicalunitPrice = unitPrice->GetProperties()->GetLogical("Value");
    logical logicaltotalPrice = totalPrice->GetProperties()->GetLogical("Value");
    logical logicalsupplier = supplier->GetProperties()->GetLogical("Value");
    logical logicalRemark = toggleRemark->GetProperties()->GetLogical("Value");
    //attriName.push_back("序号");
    if(logicalmatName)
        attriName.push_back("材料名称");
    else
        attriName.push_back("空");
    if(logicalMatNO)
        attriName.push_back("材料编号");
    else
        attriName.push_back("空");
    if(logicalmatSize)
        attriName.push_back("规格");
    else
        attriName.push_back("空");

    if( type < 6 )
    {
        if(logicalmaterial)
            attriName.push_back("材质");
        else
            attriName.push_back("空");
    }


    if( 1 == type || 5 == type )
    {
        if(logicaldesnity)
            attriName.push_back("密度");
        else
            attriName.push_back("空");
    }
	if(logicallength)
            attriName.push_back("长度");
	attriName.push_back("宽度");//??????

    if( 1 != type && 5 != type )
    {
		if( 8 == type || 11 == type )
		{
			if(logicaldesnity)
				attriName.push_back("密度");
			else
				attriName.push_back("空");
		}
		else
		{
			if(logicalarea)
				attriName.push_back("面积");
			else
				attriName.push_back("空");
		}
	}
	if(logicalquantity)
		attriName.push_back("数量");
	else
		attriName.push_back("空");

	if( 1 == type || 5 == type )
    {
        if(logicalWeight)
            attriName.push_back("重量");
        else
            attriName.push_back("空");
    }
	else
	{
		if( 8 != type )
			attriName.push_back("总面积"); //???
	}
    if(logicalunitPrice)
        attriName.push_back("单价");
    else
        attriName.push_back("空");

    if(logicaltotalPrice)
        attriName.push_back("总价");
    else
        attriName.push_back("空");

    if(logicalsupplier)
        attriName.push_back("供应商");
    else
        attriName.push_back("空");
    if(logicalRemark)
        attriName.push_back("备注");
    else
        attriName.push_back("空");


	if( type == 7 )//五金件特殊处理
	{
		if (logicalmaterial)
		{
			attriName[3] = NXString("材质");
		}
		attriName.erase(attriName.begin() + 5);
		attriName.erase(attriName.begin() + 6);
		attriName.erase(attriName.begin() + 8);

		attriName[4] = "长度";
		attriName.insert(attriName.begin() + 8, NXString("供应商"));
	}

	if (type == 8)//木雕
	{
		attriName[2] = "材质";
	}

	if( type == 11 )//辅材
	{
		attriName.insert(attriName.begin() + 3, NXString("材质"));
		attriName[8] = NXString("面积");//辅材的总面积当做面积计算--20200615
		//attriName[4] = NXString("空");
		//attriName[5] = NXString("空");
		//attriName[6] = NXString("空");
	}


    for(int idx = 0; idx < bombodies.size(); ++idx )
    {
        char num[32]="";
        StlNXStringVector rowStr;
        tag_t body = bombodies[idx];
        sprintf_s(num,"%d",idx+1);
        rowStr.push_back(num);
        for(int jdx = 0; jdx < attriName.size(); ++jdx )
        {
            if(0 == strcmp(attriName[jdx].GetText(),"空"))
            {
                rowStr.push_back("");
            }
            else
            {
                char attriValue2[133] = "";
                USER_ask_obj_string_attr( body ,(char*)attriName[jdx].GetText() , attriValue2 );
                rowStr.push_back(attriValue2);
            }
        }
        BOMStr.push_back(rowStr);
    }
}

int FindSame(NXString type, StlNXStringVectorVector &exsit, StlNXStringVector &newone)
{
	if (strcmp(type.GetLocaleText(), "钢材")==0 ||
		strcmp(type.GetLocaleText(), "铝材")==0)
	{
		for (int i = 0; i < exsit.size();i++)
		{
			if (isSame(newone[1], exsit[i][1])  && 
				isSame(newone[2] , exsit[i][2]) && 
				isSame(newone[3] , exsit[i][3]) && 
				isSame(newone[4] , exsit[i][4]) &&
				isSame(newone[5] , exsit[i][5]) &&
				isSame(newone[6] , exsit[i][6]) &&
				isSame(newone[7] , exsit[i][7])&&
				isSame(newone[10] , exsit[i][10]) &&
				isSame(newone[12] , exsit[i][12]))
			{
				return i;
			}
		}
	}


	else if (strcmp(type.GetLocaleText(), "铝板")==0 ||
		strcmp(type.GetLocaleText(), "树脂板")==0||
		strcmp(type.GetLocaleText(), "石材")==0

		)
	{
		for (int i = 0; i < exsit.size();i++)
		{
			if (isSame(newone[1], exsit[i][1])  && 
				isSame(newone[2] , exsit[i][2]) && 
				isSame(newone[3] , exsit[i][3]) && 
				isSame(newone[4] , exsit[i][4]) &&
				isSame(newone[5] , exsit[i][5]) &&
				isSame(newone[6] , exsit[i][6]) &&
				isSame(newone[7] , exsit[i][7])&&
				isSame(newone[10] , exsit[i][10]) &&
				isSame(newone[12] , exsit[i][12])
				)
			{
				return i;
			}
		}
	}

	else if (strcmp(type.GetLocaleText(), "玻璃")==0 ||
		strcmp(type.GetLocaleText(), "屋面瓦")==0||
		strcmp(type.GetLocaleText(), "铜饰")==0

		)
	{
		for (int i = 0; i < exsit.size();i++)
		{
			if (isSame(newone[1], exsit[i][1])  && 
				isSame(newone[2] , exsit[i][2]) && 
				isSame(newone[3] , exsit[i][3]) && 
				isSame(newone[4] , exsit[i][4]) &&
				isSame(newone[5] , exsit[i][5]) &&
				isSame(newone[6] , exsit[i][6]) &&
				isSame(newone[9] , exsit[i][9]) &&
				isSame(newone[11] , exsit[i][11])
				)
			{
				return i;
			}
		}
	}



	else if (strcmp(type.GetLocaleText(), "木雕")==0)
	{
		for (int i = 0; i < exsit.size();i++)
		{
			if (isSame(newone[1], exsit[i][1])  && 
				isSame(newone[2] , exsit[i][2]) && 
				isSame(newone[3] , exsit[i][3]) && 
				//isSame(newone[4] , exsit[i][4]) &&
				//isSame(newone[5] , exsit[i][5]) &&
				//isSame(newone[6] , exsit[i][6])&&
				isSame(newone[8] , exsit[i][8])&&
				isSame(newone[10] , exsit[i][10])
				)
			{
				return i;
			}
		}
	}

	else if (strcmp(type.GetLocaleText(), "五金件")==0)
	{
		for (int i = 0; i < exsit.size();i++)
		{
			if (isSame(newone[1], exsit[i][1])  && 
				isSame(newone[2] , exsit[i][2]) && 
				isSame(newone[3] , exsit[i][3]) && 
				isSame(newone[4] , exsit[i][4])&&
				isSame(newone[5] , exsit[i][5])&&
				isSame(newone[7] , exsit[i][7])
				)
			{
				return i;
			}
		}
	}


	else if (strcmp(type.GetLocaleText(), "辅材")==0)
	{
		for (int i = 0; i < exsit.size();i++)
		{
			if (isSame(newone[1], exsit[i][1])  && 
				isSame(newone[2] , exsit[i][2]) && 
				isSame(newone[3] , exsit[i][3]) && 
				isSame(newone[4] , exsit[i][4]) &&
				isSame(newone[5] , exsit[i][5]) &&
				isSame(newone[6] , exsit[i][6]) &&
				isSame(newone[7] , exsit[i][7]) &&
				isSame(newone[10] , exsit[i][10])
				)
			{
				return i;
			}
		}
	}

	return -1;
}

void PostProcess(NXString type, StlNXStringVectorVector &BOMStr)
{
	StlNXStringVectorVector heJi;
	if (strcmp(type.GetLocaleText(), "钢材")==0 ||
		strcmp(type.GetLocaleText(), "铝材")==0)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][8] = "1";//数量
				//BOMStr[i][11] = BOMStr[i][10];//总价=单价
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][8]);//数量+1

				NXString zongJia = StrMu(heJi[index][9], heJi[index][10], 2);//总价计算
				zongJia = StrMu(zongJia, heJi[index][8],2);

				heJi[index][11] = zongJia;
			}
		}
	}
	//
	else if (strcmp(type.GetLocaleText(), "铝板")==0||
		strcmp(type.GetLocaleText(), "树脂板")==0
		)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][8] = "1";//数量
				//BOMStr[i][11] = BOMStr[i][10];//总价=单价
				BOMStr[i][9] = BOMStr[i][7];//总面积=面积
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][8]);//数量+1
				
				NXString zongmianji = StrMu(heJi[index][7], heJi[index][8],2);//总面积计算
				heJi[index][9] = zongmianji;

				NXString zongJia = StrMu(zongmianji, heJi[index][10],2);//总价计算
				heJi[index][11] = zongJia;
			}
		}
	}
	else if (strcmp(type.GetLocaleText(), "玻璃")==0
		)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][7] = "1";//数量
				//BOMStr[i][10] = BOMStr[i][9];//总价=单价
				BOMStr[i][8] = BOMStr[i][6];//总面积=面积
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][7]);//数量+1

				NXString zongmianji = StrMu(heJi[index][6], heJi[index][7],2);//总面积计算
				heJi[index][8] = zongmianji;

				NXString zongJia = StrMu(zongmianji, heJi[index][9],2);//总价计算
				heJi[index][10] = zongJia;
			}
		}
	}
	else if (
		strcmp(type.GetLocaleText(), "石材") == 0//同屋面瓦
		)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][8] = "1";//数量
								   //BOMStr[i][10] = BOMStr[i][9];//总价=单价
				BOMStr[i][9] = BOMStr[i][7];//总面积=面积
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][8]);//数量+1
				NXString zongmianji = StrMu(heJi[index][7], heJi[index][8],2);//总面积计算
				heJi[index][9] = zongmianji;

				if (atof(heJi[index][9].getLocaleText()) > 0)
				{
					NXString zongJia = StrMu(heJi[index][10], heJi[index][9], 2);//总价计算
					heJi[index][11] = zongJia;
				}
				else
				{
					NXString zongJia = StrMu(heJi[index][10], heJi[index][8], 2);//总价计算
					heJi[index][11] = zongJia;
				}
			}
		}
	}
	else if (
		strcmp(type.GetLocaleText(), "铜饰") == 0//同屋面瓦
		)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][7] = "1";//数量
								   //BOMStr[i][10] = BOMStr[i][9];//总价=单价
				BOMStr[i][8] = BOMStr[i][6];//总面积=面积
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][7]);//数量+1
				NXString zongmianji = StrMu(heJi[index][6], heJi[index][7],2);//总面积计算
				heJi[index][8] = zongmianji;

				if (atof(heJi[index][8].getLocaleText()) > 0)
				{
					NXString zongJia = StrMu(heJi[index][9], heJi[index][8], 2);//总价计算
					heJi[index][10] = zongJia;
				}
				else
				{
					NXString zongJia = StrMu(heJi[index][9], heJi[index][7], 2);//总价计算
					heJi[index][10] = zongJia;
				}
			}
		}
	}
	else if (
		strcmp(type.GetLocaleText(), "屋面瓦")==0
		)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][7] = "1";//数量
				//BOMStr[i][10] = BOMStr[i][9];//总价=单价
				BOMStr[i][8] = BOMStr[i][6];//总面积=面积
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				/*

				

				NXString zongJia = StrMu(zongmianji, heJi[index][9]);//总价计算
				heJi[index][10] = zongJia;*/

				StrAdd1(heJi[index][7]);//数量+1
				NXString zongmianji = StrMu(heJi[index][6], heJi[index][7],2);//总面积计算
				heJi[index][8] = zongmianji;

				if(atof(heJi[index][8].getLocaleText()) > 0)
				{
					NXString zongJia = StrMu(heJi[index][9], heJi[index][8], 2);//总价计算
					heJi[index][10] = zongJia;
				}
				else
				{
					NXString zongJia = StrMu(heJi[index][9], heJi[index][7], 2);//总价计算
					heJi[index][10] = zongJia;
				}
				
			}
		}
	}
	else if (strcmp(type.GetLocaleText(), "木雕")==0)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][7] = "1";//数量
				//BOMStr[i][9] = BOMStr[i][8];//总价=单价
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][7]);//数量+1
				NXString zongJia = StrMu(heJi[index][8], heJi[index][7],2);//总价计算
				heJi[index][9] = zongJia;
			}
		}
	}


	else if (strcmp(type.GetLocaleText(), "五金件")==0)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][6] = "1";//数量
				//BOMStr[i][7] = BOMStr[i][6];//总价=单价
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][6]);//数量+1
				NXString zongJia = StrMu(heJi[index][7], heJi[index][6],2);//总价计算
				heJi[index][8] = zongJia;
			}
		}
	}


	else if (strcmp(type.GetLocaleText(), "辅材")==0)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			int index = FindSame(type, heJi, BOMStr[i]);
			if (index == -1)
			{
				BOMStr[i][8] = "1";//数量
				//BOMStr[i][10] = BOMStr[i][9];//总价=单价
				heJi.push_back(BOMStr[i]);
			}
			else
			{
				StrAdd1(heJi[index][8]);//数量+1
				if (atof(heJi[index][5].getLocaleText()) > 0)
				{
					NXString zongJia = StrMu(heJi[index][5], heJi[index][8], 2);//总价计算
					zongJia = StrMu(heJi[index][10], zongJia, 2);//总价计算
					zongJia = StrMu(NXString("0.001"), zongJia, 2);//总价计算
					heJi[index][11] = zongJia;
				}
				else
				{
					NXString zongJia = StrMu(heJi[index][10], heJi[index][8], 2);//总价计算
					heJi[index][11] = zongJia;
				}
				
			}
		}
	}


	//////////////////////////////////////////////////////
    
	for (int i = 0; i < heJi.size(); i++)
	{
		char cstr[16] = "";
		sprintf(cstr, "%d", i+1);
		heJi[i][0] = NXString(cstr);
	}
	BOMStr = heJi;
}

void PostProcess2(NXString type, StlNXStringVectorVector &BOMStr)
{
	if (strcmp(type.GetLocaleText(), "钢材") == 0)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			//插入总重
			NXString zongZhongLiang = StrMu(BOMStr[i][8], BOMStr[i][9], 2);//总重量计算
			BOMStr[i].insert(BOMStr[i].begin()+10,zongZhongLiang);
		}
	}
	if (strcmp(type.GetLocaleText(), "铝材") == 0)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			//插入总重
			NXString zongZhongLiang = StrMu(BOMStr[i][8], BOMStr[i][9], 2);//总重量计算
			BOMStr[i].insert(BOMStr[i].begin() + 10, zongZhongLiang);
		}
	}

	if (strcmp(type.GetLocaleText(), "辅材") == 0)
	{
		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			//插入总重
			NXString mianJi = BOMStr[i][10];
			BOMStr[i].insert(BOMStr[i].begin() + 8, mianJi);
			BOMStr[i][10] = StrMu(BOMStr[i][8], BOMStr[i][9], 2);//总重量计算
		}
	}
}

bool comp(StlNXStringVector &strs1, StlNXStringVector &strs2)
{
     if (strcmp(strs1[2].getLocaleText(), strs2[2].getLocaleText()) > 0)
     {
		 return false;
     }
	 return true;
}

void SortStrss(StlNXStringVectorVector &strss)
{
   std::sort(strss.begin(), strss.end(), comp);

   char cstr[32] = "";
   for (int i = 0; i < strss.size(); i++)
   {
	   sprintf(cstr,"%d",i+1);
	   strss[i][0] = NXString(cstr);
   }
}

int Bom::apply_cb()
{
    int errorCode = 0;
    try
    {
        //---- Enter your callback code here -----
		std::vector<tag_t> bombodies;
        logical isAll = false;
		tag_t part = UF_ASSEM_ask_work_part();
        StlNXStringVector alltypes = enumType->GetEnumMembers();
		std::vector<NXOpen::TaggedObject* > objects = bodySelect->GetProperties()->GetTaggedObjectVector("SelectedObjects");
		//NXString typeStr = enumType->GetProperties()->GetEnumAsString("Value").GetText();
        int type = enumType->GetProperties()->GetEnum("Value");
        NXString typeStr= alltypes[type];
        NXString projName = projectName->GetProperties()->GetString("Value");
        NXString projNO = projectNumber->GetProperties()->GetString("Value");
        Royal_set_obj_attr(part,"工程名称",projName.GetLocaleText());
		Royal_set_obj_attr(part,"工程编号",projNO.GetLocaleText());
        /*if( 0 == strcmp("全部",typeStr.GetLocaleText()))
        {
            isAll = true;
        }*/
		if(objects.size()>0)
		{
			for(int idx = 0; idx < objects.size(); ++idx)
			{
				if( 0 == type )
				{
					bombodies.push_back(objects[idx]->Tag());
				}
				else if(CheckBodyType(objects[idx]->Tag(),typeStr))
				{
					bombodies.push_back(objects[idx]->Tag());
				}
			}
		}


		UI_StringGetValue(projectName, s_projectName);
		UI_StringGetValue(projectNumber, s_projectNumber);
		UI_StringGetValue(stringCaiLiaoDanHao, s_caiLiaoDanHao);

		if(bombodies.size()>0)
		{
			char file_name[UF_CFI_MAX_PATH_NAME_SIZE]="";
			char fname[_MAX_FNAME]="";
			char sFilePath[_MAX_FNAME]="";
			int status = 0;
            StlNXStringVectorVector BOMStr;
			tag_t disPart = UF_PART_ask_display_part();
			UF_PART_ask_part_name (disPart, file_name );
            uc4576 (file_name, 2, sFilePath, fname );
			char *p = strstr(file_name,".prt");
			if( p != NULL )
			{
				*p='\0';
			}
			char *p_env = getenv("UGII_USER_DIR");
			char srcspc[MAX_FSPEC_SIZE]="";
			char desspc[MAX_FSPEC_SIZE]="";
            if( 0 == type ) //all 
            {
                for( int idx = 1; idx < alltypes.size(); ++idx )
                {
                    type = idx;
                    typeStr = alltypes[idx];
                    vtag_t tempbodies;
                    for( int jdx = 0;jdx < bombodies.size(); ++jdx )
                    {
                        if(CheckBodyType(bombodies[jdx],typeStr))
                            tempbodies.push_back(bombodies[jdx]);
                    }
                    if(tempbodies.size() > 0)
                    {
                        sprintf_s(srcspc,"%s\\templates\\%s.xls",p_env,typeStr.GetLocaleText());
                        UF_CFI_ask_file_exist(srcspc,&status);
                        if( 0 != status )
                        {
                            uc1601("没有找到模板文件",1);
                            //return 1;
                            continue;
                        }
                        sprintf_s(desspc,"%s_%s_%s.xls",file_name,typeStr.GetLocaleText(), s_caiLiaoDanHao.GetLocaleText());
                        //sprintf_s(desspc,"%s_BOM.xls",file_name);
                        UF_CFI_ask_file_exist(desspc,&status);
                        if( 0 == status )
                        {
                            uc4561(desspc,-1); 
                        }
                        GetBOMInformation(tempbodies,type,BOMStr );

						//同样的东西数量合并
						PostProcess(GetBodyType(tempbodies[0]), BOMStr);

						//主要处理单面积和总面积，单重量和总重量的关系---20201031
						PostProcess2(GetBodyType(tempbodies[0]), BOMStr);
						SortStrss(BOMStr);
                        WriteBOM(GetBodyType(tempbodies[0]), srcspc,desspc,BOMStr,s_projectName,s_projectNumber,s_caiLiaoDanHao);
                    }
                }
            }
            else
            {
                sprintf_s(srcspc,"%s\\templates\\%s.xls",p_env,typeStr.GetLocaleText(), s_caiLiaoDanHao.GetLocaleText());
                UF_CFI_ask_file_exist(srcspc,&status);
                if( 0 != status )
                {
                    uc1601("没有找到模板文件",1);
                    return 1;
                }
                sprintf_s(desspc,"%s_%s_%s.xls",file_name,typeStr.GetLocaleText(), s_caiLiaoDanHao.GetLocaleText());
                //sprintf_s(desspc,"%s_BOM.xls",file_name);
                UF_CFI_ask_file_exist(desspc,&status);
                if( 0 == status )
                {
                    uc4561(desspc,-1); 
                }
                GetBOMInformation(bombodies,type,BOMStr );

				//同样的东西数量合并
				PostProcess(GetBodyType(bombodies[0]), BOMStr);

				//主要处理单面积和总面积，单重量和总重量的关系---20201031
				PostProcess2(GetBodyType(bombodies[0]), BOMStr);
				SortStrss(BOMStr);
                WriteBOM(GetBodyType(bombodies[0]), srcspc,desspc,BOMStr,s_projectName,s_projectNumber, s_caiLiaoDanHao);
            }
            char cmd[512]="";
			sprintf_s(cmd,"start %s",sFilePath);
			system(cmd);
		}
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        errorCode = 1;
        Bom::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Callback Name: update_cb
//------------------------------------------------------------------------------
int Bom::update_cb(NXOpen::BlockStyler::UIBlock* block)
{
    try
    {
        if(block == toggleOutAll)
        {
        //---------Enter your code here-----------
        }
        else if(block == enumType)
        {
        //---------Enter your code here-----------
        }
        else if(block == bodySelect)
        {
        //---------Enter your code here-----------
        }
        else if(block == matName)
        {
        //---------Enter your code here-----------
        }
        else if(block == MatNO)
        {
        //---------Enter your code here-----------
        }
        else if(block == matSize)
        {
        //---------Enter your code here-----------
        }
        else if(block == material)
        {
        //---------Enter your code here-----------
        }
        else if(block == desnity)
        {
        //---------Enter your code here-----------
        }
        else if(block == length)
        {
        //---------Enter your code here-----------
        }
        else if(block == togglearea)
        {
        //---------Enter your code here-----------
        }
        else if(block == togglequantity)
        {
        //---------Enter your code here-----------
        }
        else if(block == toggleWeight)
        {
        //---------Enter your code here-----------
        }
        else if(block == unitPrice)
        {
        //---------Enter your code here-----------
        }
        else if(block == totalPrice)
        {
        //---------Enter your code here-----------
        }
        else if(block == supplier)
        {
        //---------Enter your code here-----------
        }
        else if(block == toggleRemark)
        {
        //---------Enter your code here-----------
        }
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Bom::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//Callback Name: ok_cb
//------------------------------------------------------------------------------
int Bom::ok_cb()
{
    int errorCode = 0;
    try
    {
        errorCode = apply_cb();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        errorCode = 1;
        Bom::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Function Name: GetBlockProperties
//Description: Returns the propertylist of the specified BlockID
//------------------------------------------------------------------------------
PropertyList* Bom::GetBlockProperties(const char *blockID)
{
    return theDialog->GetBlockProperties(blockID);
}
