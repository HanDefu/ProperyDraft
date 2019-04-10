﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block UI Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  C:\codeguangzhou\install\application\Property.cpp
//
//        This file was generated by the NX Block UI Styler
//        Created by: Administrator
//              Version: NX 10
//              Date: 03-18-2019  (Format: mm-dd-yyyy)
//              Time: 19:52 (Format: hh-mm)
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
#include "Property.hpp"
#include "Common.h"
#include "Common_UI.h"
#include <NXOpen/Body.hxx>
#include <NXOpen/BodyCollection.hxx>
#include <NXOpen/NXMatrix.hxx>
#include <NXOpen/NXMatrixCollection.hxx>
#include <NXOpen/CoordinateSystem.hxx>
#include <NXOpen/CoordinateSystemCollection.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/Measure.hxx>
#include <NXOpen/MeasureBuilder.hxx>
#include <NXOpen/MeasureFaces.hxx>
#include <NXOpen/MeasureFaceBuilder.hxx>
#include <NXOpen/MeasureManager.hxx>
#include <NXOpen/FaceDumbRule.hxx>
#include <NXOpen/ScRuleFactory.hxx>
#include <NXOpen/Unit.hxx>
#include <NXOpen/UnitCollection.hxx>
#include "Common_Function.h"
#include "Common_Function_UG.h"
#include "Excel/BasicExcel.hpp"


static tag_t CreateText(NXString& textStr, char* textHeight, Point3d coordinates2, Vector3d xDirection1, Vector3d yDirection1)
{
	NXOpen::Session *theSession = NXOpen::Session::GetSession();
	NXOpen::Part *workPart(theSession->Parts()->Work());

	NXOpen::Features::Text *nullNXOpen_Features_Text(NULL);

	int worklayer = -1;
	int layerStatus = -1;
	UF_LAYER_ask_work_layer(&worklayer);
	//UF_LAYER_ask_status(255,&layerStatus);
	//UF_LAYER_set_status(255, UF_LAYER_WORK_LAYER);

	NXOpen::Features::TextBuilder *textBuilder1;
	textBuilder1 = workPart->Features()->CreateTextBuilder(nullNXOpen_Features_Text);

	NXOpen::Point3d origin1(0.0, 0.0, 0.0);
	NXOpen::Vector3d normal1(0.0, 0.0, 1.0);
	NXOpen::Plane *plane1;
	plane1 = workPart->Planes()->CreatePlane(origin1, normal1, NXOpen::SmartObject::UpdateOptionWithinModeling);

	textBuilder1->SetSectionPlane(plane1);

	/*NXOpen::Unit *unit1;
	unit1 = textBuilder1->PlanarFrame()->Length()->Units();

	textBuilder1->FrameOnPath()->AnchorPosition()->Expression()->SetRightHandSide("50");*/

	//textBuilder1->SetOnFacePlacementMethod(NXOpen::Features::TextBuilder::OnFacePlacementMethodOptionsSectionPlane);

	textBuilder1->SetScript(NXOpen::Features::TextBuilder::ScriptOptionsWestern);

	textBuilder1->SetCanUseKerningSpaces(false);

	textBuilder1->PlanarFrame()->SetAnchorLocation(NXOpen::GeometricUtilities::RectangularFrameBuilder::AnchorLocationTypeBottomLeft);
	//textBuilder1->PlanarFrame()->Length()->SetRightHandSide("17.6908611782542");2.7*n

	textBuilder1->PlanarFrame()->Height()->SetRightHandSide(textHeight);

	textBuilder1->PlanarFrame()->SetWScale(100);
	textBuilder1->PlanarFrame()->Shear()->SetRightHandSide("0");

	/*textBuilder1->FrameOnPath()->SetAnchorLocation(NXOpen::GeometricUtilities::FrameOnPathBuilder::AnchorLocationTypeLeft);

	textBuilder1->FrameOnPath()->AnchorPosition()->Expression()->SetRightHandSide("30");

	textBuilder1->FrameOnPath()->AnchorPosition()->SetParameterUsed(false);

	textBuilder1->FrameOnPath()->Offset()->SetRightHandSide("4.5");

	textBuilder1->FrameOnPath()->Length()->SetRightHandSide("9.53025449104364");2.7*n*/

	//textBuilder1->FrameOnPath()->Height()->SetRightHandSide("4");

	//textBuilder1->FrameOnPath()->SetWScale(35.4339270372263);

	textBuilder1->SetCanProjectCurves(true);

	textBuilder1->SelectFont("宋体", NXOpen::Features::TextBuilder::ScriptOptionsWestern);//Arial

	textBuilder1->SetTextString(textStr);

	NXOpen::CoordinateSystem *coordinateSystem1;

	CoordinateSystemCollection *csysCollectionPtr = workPart->CoordinateSystems();
	NXMatrixCollection *matrixCollection = workPart->NXMatrices();
	double mtx[9], vx[3] = { xDirection1.X,xDirection1.Y,xDirection1.Z }, vy[3] = { yDirection1.X,yDirection1.Y,yDirection1.Z };
	UF_MTX3_initialize(vx, vy, mtx);
	Matrix3x3 element(mtx[0], mtx[1], mtx[2], mtx[3], mtx[4], mtx[5], mtx[6], mtx[7], mtx[8]);
	NXOpen::NXMatrix * orientation = matrixCollection->Create(element);

	//coordinateSystem1 = csysCollectionPtr->CreateCoordinateSystem(coordinates2,xDirection1, yDirection1);
	coordinateSystem1 = csysCollectionPtr->CreateCoordinateSystem(coordinates2, orientation, true);

	textBuilder1->PlanarFrame()->SetCoordinateSystem(coordinateSystem1);

	textBuilder1->PlanarFrame()->UpdateOnCoordinateSystem();

	NXOpen::Point *point2;
	point2 = workPart->Points()->CreatePoint(coordinates2);

	NXOpen::Point3d point3(coordinates2.X, coordinates2.Y, coordinates2.Z);
	//point2 = workPart->Points()->CreatePoint(point3);
	textBuilder1->PlanarFrame()->AnchorLocator()->SetValue(point2, workPart->ModelingViews()->WorkView(), point3);


	NXOpen::NXObject *nXObject1;
	nXObject1 = textBuilder1->Commit();

	tag_t texttag = nXObject1->Tag();

	textBuilder1->Destroy();

	plane1->DestroyPlane();
	//UF_LAYER_set_status(worklayer, UF_LAYER_WORK_LAYER);
	//UF_LAYER_set_status(255,layerStatus);
	return texttag;
}

VVecNXStringVector configData;
//StlNXStringVector g_allNames;
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

static int 
	s_type = 0,
	s_mingcheng = 0,
	s_bianhao = 0,
	s_guige = 0,
	s_caizhi = 0,
	s_midu = 0,
	s_danjia = 0,
	s_gongyingshang = 0,
	s_beizhu = 0;

//------------------------------------------------------------------------------
// Initialize static variables
//------------------------------------------------------------------------------
Session *(Property::theSession) = NULL;
UI *(Property::theUI) = NULL;
//------------------------------------------------------------------------------
// Constructor for NX Styler class
//------------------------------------------------------------------------------
Property::Property()
{
    try
    {
        // Initialize the NX Open C++ API environment
        Property::theSession = NXOpen::Session::GetSession();
        Property::theUI = UI::GetUI();
        theDlxFileName = "Property.dlx";
        theDialog = Property::theUI->CreateDialog(theDlxFileName);
        // Registration of callback functions
        theDialog->AddApplyHandler(make_callback(this, &Property::apply_cb));
        theDialog->AddOkHandler(make_callback(this, &Property::ok_cb));
        theDialog->AddUpdateHandler(make_callback(this, &Property::update_cb));
        theDialog->AddFilterHandler(make_callback(this, &Property::filter_cb));
        theDialog->AddInitializeHandler(make_callback(this, &Property::initialize_cb));
        theDialog->AddFocusNotifyHandler(make_callback(this, &Property::focusNotify_cb));
        theDialog->AddDialogShownHandler(make_callback(this, &Property::dialogShown_cb));
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
Property::~Property()
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
void GZ_PART_ATTR_Main()
{
    Property *theProperty = NULL;
    try
    {
        theProperty = new Property();
        // The following method shows the dialog immediately
        theProperty->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    if(theProperty != NULL)
    {
        delete theProperty;
        theProperty = NULL;
    }
}

int Property::Show()
{
    try
    {
        theDialog->Show();
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

//------------------------------------------------------------------------------
//---------------------Block UI Styler Callback Functions--------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Callback Name: initialize_cb
//------------------------------------------------------------------------------
void Property::initialize_cb()
{
    try
    {
        group = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group"));
        str_techReq = dynamic_cast<NXOpen::BlockStyler::MultilineString*>(theDialog->TopBlock()->FindBlock("str_techReq"));
        group3 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group3"));
        enumType = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("enumType"));
        bodySelect0 = dynamic_cast<NXOpen::BlockStyler::BodyCollector*>(theDialog->TopBlock()->FindBlock("bodySelect0"));
        group1 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group1"));
        enum09 = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("enum09"));
        enum08 = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("enum08"));
        face_select0 = dynamic_cast<NXOpen::BlockStyler::FaceCollector*>(theDialog->TopBlock()->FindBlock("face_select0"));
        coord_system0 = dynamic_cast<NXOpen::BlockStyler::SpecifyCSYS*>(theDialog->TopBlock()->FindBlock("coord_system0"));
        buttonCalculate = dynamic_cast<NXOpen::BlockStyler::Button*>(theDialog->TopBlock()->FindBlock("buttonCalculate"));
        bodyLen = dynamic_cast<NXOpen::BlockStyler::DoubleBlock*>(theDialog->TopBlock()->FindBlock("bodyLen"));
        linear_bodyLen = dynamic_cast<NXOpen::BlockStyler::LinearDimension*>(theDialog->TopBlock()->FindBlock("linear_bodyLen"));
        linear_bodyWidth = dynamic_cast<NXOpen::BlockStyler::LinearDimension*>(theDialog->TopBlock()->FindBlock("linear_bodyWidth"));
        bodyWidth = dynamic_cast<NXOpen::BlockStyler::DoubleBlock*>(theDialog->TopBlock()->FindBlock("bodyWidth"));
        bodyarea = dynamic_cast<NXOpen::BlockStyler::DoubleBlock*>(theDialog->TopBlock()->FindBlock("bodyarea"));
        group0 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group0"));
        matName = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("matName"));
        matNO = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("matNO"));
        matSize = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("matSize"));
        material = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("material"));
        matDensity = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("matDensity"));
        unitPrice = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("unitPrice"));
        supplier = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("supplier"));
        weight = dynamic_cast<NXOpen::BlockStyler::DoubleBlock*>(theDialog->TopBlock()->FindBlock("weight"));
        totalPrice = dynamic_cast<NXOpen::BlockStyler::DoubleBlock*>(theDialog->TopBlock()->FindBlock("totalPrice"));
        remark = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("remark"));
        group4 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group4"));
        toggleoutNO = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("toggleoutNO"));
        coord_system01 = dynamic_cast<NXOpen::BlockStyler::SpecifyCSYS*>(theDialog->TopBlock()->FindBlock("coord_system01"));
        textHeight = dynamic_cast<NXOpen::BlockStyler::DoubleBlock*>(theDialog->TopBlock()->FindBlock("textHeight"));
        group2 = dynamic_cast<NXOpen::BlockStyler::Group*>(theDialog->TopBlock()->FindBlock("group2"));
        hideBody = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("hideBody"));
        enum011 = dynamic_cast<NXOpen::BlockStyler::Enumeration*>(theDialog->TopBlock()->FindBlock("enum011"));
        inheriteFrombody = dynamic_cast<NXOpen::BlockStyler::Toggle*>(theDialog->TopBlock()->FindBlock("inheriteFrombody"));
        selectFrombody = dynamic_cast<NXOpen::BlockStyler::BodyCollector*>(theDialog->TopBlock()->FindBlock("selectFrombody"));
        buttonHideBody = dynamic_cast<NXOpen::BlockStyler::Button*>(theDialog->TopBlock()->FindBlock("buttonHideBody"));
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

#include "Excel/Excel.h"
//#include "Excel/Excel.h"
void Property::ReadExcelConfigData( )
{
	if (configData.size() > 0)
		return;
	Excel::CExcelUtil xls;
	char regfile[256]="";
	sprintf(regfile,"%s\\Parameter\\Config.xls",getenv("UGII_USER_DIR"));
	//bool isOk = excel.Load(regfile);
	xls.OpenExcel(regfile);
	xls.SetVisible(false);
	int num = xls.GetSheetNum();

	for( int idx = 0; idx < num; ++idx )
	{
		//xls.GetSheet();

		xls.SetActiveSheet(idx+1);

		size_t maxRows = 256;
		size_t maxCols = 9;

		VecNXStringVector sheetData;
		for(int i = 1; i < maxCols; i++)
		{
			StlNXStringVector matNameEtc;
			for(int j = 2; j < maxRows; ++j)
			{
				CString str = xls.GetCellValue(j,i).GetBuffer();
				if (str.GetLength() > 0)
				{
					matNameEtc.push_back(WCHARTOCHAR(str.GetBuffer()));
				}
			}
			sheetData.push_back(matNameEtc);
		}
		configData.push_back(sheetData);

	}
	xls.CloseExcel();
	return;
}

/*
void Property::ReadExcelConfigData( )
{
	BasicExcel excel;
    char regfile[256]="";
    sprintf(regfile,"%s\\Parameter\\Config.xls",getenv("UGII_USER_DIR"));
	bool isOk = excel.Load(regfile);
	if( isOk )
	{
        int num = excel.GetTotalWorkSheets();
        for( int idx = 0; idx < num; ++idx )
        {
            const wchar_t* sheetName = excel.GetUnicodeSheetName(idx);
			sheetNames.push_back(WCHARTOCHAR(sheetName));
            BasicExcelWorksheet* sheet1 = excel.GetWorksheet(sheetName);
            if (sheet1)
            {
                size_t maxRows = sheet1->GetTotalRows();
                size_t maxCols = sheet1->GetTotalCols();
                {
                    VecNXStringVector sheetData;
                    for(int i = 0; i < maxCols; i++)
                    {
                        StlNXStringVector matNameEtc;
                        for(int j = 1; j < maxRows; ++j)
                        {
                            BasicExcelCell *cel = sheet1->Cell(j,i);
                            matNameEtc.push_back(cel->Get());
                        }
                        sheetData.push_back(matNameEtc);
                    }
                    configData.push_back(sheetData);
                }
            }
        }
	}
	return;
}*/

void Property::SetUIConfigData( )
{
    int type = enumType->GetProperties()->GetEnum("Value");
    if( configData.size()-1 < type )
    {
        type = 0;
    }
    if( configData.size() > 0 )
    {
        VecNXStringVector temp = configData[type];
        matName->GetProperties()->SetEnumMembers("Value",temp[0]);
        matNO->GetProperties()->SetEnumMembers("Value",temp[1]);
        matSize->GetProperties()->SetEnumMembers("Value",temp[2]);
        material->GetProperties()->SetEnumMembers("Value",temp[3]);
        matDensity->GetProperties()->SetEnumMembers("Value",temp[4]);
        unitPrice->GetProperties()->SetEnumMembers("Value",temp[5]);
        supplier->GetProperties()->SetEnumMembers("Value",temp[6]);
		if(temp[7].size() > 0)
            remark->GetProperties()->SetEnumMembers("Value",temp[7]);
		else
			remark->SetShow(false);
    }

	weight->SetShow(false);//重量一直不显示
	totalPrice->SetShow(false);//总价一直不显示

	if (type==0 || type==4)//钢材 铝材
	{
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(true);
		bodyarea->SetShow(false);
        face_select0->SetShow(false);
		matSize->SetShow(true);
		matDensity->SetShow(true);//密度显示
		material->SetShow(true);
	}
	else if (type==1 || type==2 || type == 3)//铝板 树脂板 石材
	{
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(true);
		bodyarea->SetShow(true);
        face_select0->SetShow(true);
		
		matSize->SetShow(true);
		matDensity->SetShow(false);//密度去掉
		material->SetShow(true);
	}
	else if (type==5 || type==8 || type == 9)//玻璃 屋面瓦 铜饰
	{
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(true);
		bodyarea->SetShow(true);
		face_select0->SetShow(true);
		
		matSize->SetShow(true);
		matDensity->SetShow(false);//密度去掉
		material->SetShow(false);
	}
	else if (type==7)//木雕
	{
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(true);
		bodyarea->SetShow(false);
		face_select0->SetShow(false);

		matSize->SetShow(false);
		material->SetShow(true);
		matDensity->SetShow(false);//密度去掉
	}
	else if (type==10)//辅材
	{
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(true);
		bodyarea->SetShow(false);
		face_select0->SetShow(false);


		matSize->SetShow(true);
		material->SetShow(true);
		matDensity->SetShow(false);//密度去掉
	}
	else//6五金件
	{
	
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(false);
		bodyarea->SetShow(false);
		face_select0->SetShow(false);

		matSize->SetShow(true);
		matDensity->SetShow(false);//密度显示
		material->SetShow(true);
	}
}
//------------------------------------------------------------------------------
//Callback Name: dialogShown_cb
//This callback is executed just before the dialog launch. Thus any value set 
//here will take precedence and dialog will be launched showing that value. 
//------------------------------------------------------------------------------
void Property::dialogShown_cb()
{
    try
    {
        //---- Enter your callback code here -----
        ReadExcelConfigData();
        logical inheritBody = inheriteFrombody->GetProperties()->GetLogical("Value");
        selectFrombody->GetProperties()->SetLogical("Show",inheritBody);
        logical out  = toggleoutNO->GetProperties()->GetLogical("Value");
        coord_system01->GetProperties()->SetLogical("Show",out);
        textHeight->GetProperties()->SetLogical("Show",out);
        //enumType->GetProperties()->SetEnumMembers("Value",sheetNames);
        SetUIConfigData();

		if (s_type>=0)
		    UI_EnumSetCurrentSel(enumType, s_type);
		if (s_mingcheng>=0)
		    UI_EnumSetCurrentSel(matName, s_mingcheng);
		if (s_bianhao>=0)
		    UI_EnumSetCurrentSel(matNO, s_bianhao);
		if (s_guige>=0)
		    UI_EnumSetCurrentSel(matSize, s_guige);

		std::vector<NXString> strs;
		strs = material->GetEnumMembers();
		if (strs.size() > 1 && s_caizhi>=0)
		{
			UI_EnumSetCurrentSel(material, s_caizhi);
		}

		strs = matDensity->GetProperties()->GetEnumMembers("Value");
		if (strs.size() > 1&& s_midu>=0)
			UI_EnumSetCurrentSel(matDensity, s_midu);

		strs = unitPrice->GetProperties()->GetEnumMembers("Value");
		if (strs.size() > 1&& s_danjia>=0)
			UI_EnumSetCurrentSel(unitPrice, s_danjia);

		strs = supplier->GetProperties()->GetEnumMembers("Value");
		if (strs.size() > 1&& s_gongyingshang>=0)
			UI_EnumSetCurrentSel(supplier, s_gongyingshang);

		strs = remark->GetProperties()->GetEnumMembers("Value");
		if (strs.size() > 1&& s_beizhu>=0)
			UI_EnumSetCurrentSel(remark, s_beizhu);
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}



void Royal_set_obj_attr(tag_t body,char *name , double val)
{
	char toprStr[133]="";
	sprintf(toprStr,"%.1f",val);
	Royal_set_obj_attr(body,name,toprStr);
}

void Royal_set_obj_attr2(tag_t body,char *name , double val)
{
	char toprStr[133]="";
	sprintf(toprStr,"%.2f",val);
	Royal_set_obj_attr(body,name,toprStr);
}
//------------------------------------------------------------------------------
//Callback Name: apply_cb
//------------------------------------------------------------------------------
int Property::apply_cb()
{
    int errorCode = 0;
    try
    {
        //---- Enter your callback code here -----
		std::vector<NXOpen::TaggedObject* > objects = bodySelect0->GetProperties()->GetTaggedObjectVector("SelectedObjects");
		if(objects.size()>0)
		{
			for (int mm = 0; mm < objects.size(); mm++)
			{
				tag_t body = objects[mm]->Tag();

				NXString type = enumType->GetProperties()->GetEnumAsString("Value");
				NXString name = matName->GetProperties()->GetEnumAsString("Value");
				NXString maNO = matNO->GetProperties()->GetEnumAsString("Value");
				NXString size = matSize->GetProperties()->GetEnumAsString("Value");
				NXString mate = material->GetProperties()->GetEnumAsString("Value");
				NXString dens = matDensity->GetProperties()->GetEnumAsString("Value");
				NXString unpr = unitPrice->GetProperties()->GetEnumAsString("Value");
				NXString supp = supplier->GetProperties()->GetEnumAsString("Value");
				NXString rema = remark->GetProperties()->GetEnumAsString("Value");

				//double weig = weight->GetProperties()->GetDouble("Value");
				double area = bodyarea->GetProperties()->GetDouble("Value");
				area = area/1000000;
				double len = linear_bodyLen->GetProperties()->GetDouble("Value");
				double wid = linear_bodyWidth->GetProperties()->GetDouble("Value");

				//重量计算
				double volume = RY_GetBodyVolume(body);
				NXString zhongLiang = StrMu(dens, volume/1000, 3);


				//总价计算
				double topr = 0;
				if (strcmp(type.getLocaleText() , "钢材" ) == 0||
					strcmp(type.getLocaleText() , "铝材") == 0//按照重量算
					)
				{
					NXString zongJia = StrMu(unpr, zhongLiang,2);
					topr = atof(zongJia.getLocaleText());
				}
				else if (strcmp(type.getLocaleText() ,"五金件")==0||
					strcmp(type.getLocaleText() , "木雕") ==0)//按照个数算
				{
					topr = atof(unpr.getLocaleText());
				}
				else if (strcmp(type.getLocaleText() ,"辅材")==0)//如果长度大于0 按照长度m算 如果长度==0按照个数算
				{
					if (len > 0)
					{
						topr = atof(StrMu(unpr, len/1000, 2).getLocaleText());
						char cstr[16] = "";
						sprintf(cstr, "%.3f", topr);
						unpr = NXString(cstr);
					}
					else
						topr = atof(unpr.getLocaleText());
				}
				else if (strcmp(type.getLocaleText() ,"屋面瓦")==0 ||
					strcmp(type.getLocaleText(), "铜饰") == 0)//如果面积大于0 按照面积平方米算 如果面积==0按照个数算
				{
					if (area > 0)
					{
						NXString zongJia = StrMu(unpr, area);
						topr = atof(zongJia.getLocaleText());
					}
					else
						topr = atof(unpr.getLocaleText());
				}
				else//其他按照面积算
				{
					NXString zongJia = StrMu(unpr, area);
					topr = atof(zongJia.getLocaleText());
				}


				Royal_set_obj_attr(body,"材料类型",type.GetLocaleText());
				Royal_set_obj_attr(body,"材料名称",name.GetLocaleText());
				Royal_set_obj_attr(body, "1_材料名称", name.GetLocaleText());
				Royal_set_obj_attr(body,"材料编号",maNO.GetLocaleText());
				Royal_set_obj_attr(body,"规格",size.GetLocaleText());
				Royal_set_obj_attr(body,"材质",mate.GetLocaleText());
				Royal_set_obj_attr2(body,"密度",atof(dens.GetLocaleText()));
				Royal_set_obj_attr2(body,"单价",atof(unpr.GetLocaleText()));
				Royal_set_obj_attr(body,"供应商",supp.GetLocaleText());
				Royal_set_obj_attr2(body,"重量",atof(zhongLiang.getLocaleText()));
				Royal_set_obj_attr2(body,"总价",topr);
				Royal_set_obj_attr(body,"面积",area);
				Royal_set_obj_attr(body,"长度",len);
				Royal_set_obj_attr(body,"宽度",wid);
				Royal_set_obj_attr(body,"备注",rema.GetLocaleText());
				Royal_set_obj_attr(body,"已设零件标记","1");
				logical is = toggleoutNO->GetProperties()->GetLogical("Value");
				if(is)
				{
					char textHei[64]="3";
                    double hei = textHeight->GetProperties()->GetDouble("Value");
                    sprintf(textHei,"%f",hei);
					Royal_set_obj_attr(body,"输出材料编号","1");
					Point3d  originPoint(5,5,0);
					double csysorg[3]={5,5,0};
					double org[3]={0,0,0};
					Vector3d vecDirX(1,0,0);
					Vector3d vecDirY(0,1,0);
					tag_t workcsys = NULL_TAG;
					UF_CSYS_ask_wcs(&workcsys);
					std::vector<NXOpen::TaggedObject* > csysObjects = coord_system01->GetProperties()->GetTaggedObjectVector("SelectedObjects");
					if( csysObjects.size() > 0 )
					{
						tag_t csys_tag = csysObjects[0]->Tag();
						NXOpen::CoordinateSystem *coord_system = (NXOpen::CoordinateSystem *)NXOpen::NXObjectManager::Get(csys_tag);
						originPoint =  coord_system->Origin(); 
						NXOpen::NXMatrix *matrix = coord_system->Orientation();
						Matrix3x3 matrix33 = matrix->Element();
						vecDirX.X = matrix33.Xx;
						vecDirX.Y = matrix33.Xy;
						vecDirX.Z = matrix33.Xz;
						vecDirY.X = matrix33.Yx;
						vecDirY.Y = matrix33.Yy;
						vecDirY.Z = matrix33.Yz;
						tag_t temp = NULL_TAG;
						int irc  = UF_CSYS_set_wcs(csys_tag);
						UF_CSYS_map_point(UF_CSYS_ROOT_WCS_COORDS,csysorg,UF_CSYS_ROOT_COORDS,org);
						UF_CSYS_set_wcs(workcsys);
						originPoint.X = org[0];
						originPoint.Y = org[1];
						originPoint.Z = org[2];
					}
					tag_t textTag = CreateText(maNO,textHei,originPoint,vecDirX,vecDirY);
					char *handle = 0;
					UF_TAG_ask_handle_from_tag(RY_Prototype(textTag), &handle);
					Royal_set_obj_attr( body, ATTR_RY_TEXT_SPLINE_BODY_HANDLE, handle );
					UF_free(handle);
				}
				else
					Royal_set_obj_attr(body,"输出材料编号","0");
				logical blank = hideBody->GetProperties()->GetLogical("Value");
				if(blank)
					UF_OBJ_set_blank_status( body,UF_OBJ_BLANKED);
			}
		}


		UI_EnumGetCurrentSel(enumType, s_type);
		UI_EnumGetCurrentSel(matName, s_mingcheng);
		UI_EnumGetCurrentSel(matNO, s_bianhao);
		UI_EnumGetCurrentSel(matSize, s_guige);
		UI_EnumGetCurrentSel(material, s_caizhi);
		UI_EnumGetCurrentSel(matDensity, s_midu);
		UI_EnumGetCurrentSel(unitPrice, s_danjia);
		UI_EnumGetCurrentSel(supplier, s_gongyingshang);
		UI_EnumGetCurrentSel(remark, s_beizhu);
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        errorCode = 1;
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Callback Name: update_cb
//------------------------------------------------------------------------------
int Property::update_cb(NXOpen::BlockStyler::UIBlock* block)
{
    try
    {
        if(block == str_techReq)
        {
        //---------Enter your code here-----------
        }
        else if(block == enumType)
        {
        //---------Enter your code here-----------
            SetUIConfigData();
        }
        else if(block == bodySelect0)
        {
        //---------Enter your code here-----------
        }
        else if(block == enum09)
        {
        //---------Enter your code here-----------
        }
        else if(block == enum08)
        {
        //---------Enter your code here-----------
        }
        else if(block == coord_system0)
        {
        //---------Enter your code here-----------
        }
        else if(block == buttonCalculate)
        {
        //---------Enter your code here-----------
			SetBodyBoundingBoxSize();
        }
        else if(block == bodyLen)
        {
        //---------Enter your code here-----------
        }
        else if(block == linear_bodyLen)
        {
        //---------Enter your code here-----------
        }
        else if(block == linear_bodyWidth)
        {
        //---------Enter your code here-----------
        }
        else if(block == bodyWidth)
        {
        //---------Enter your code here-----------
        }
        else if(block == bodyarea)
        {
        //---------Enter your code here-----------
        }
        else if(block == matName)
        {
        //---------Enter your code here-----------
        }
        else if(block == matNO)
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
        else if(block == matDensity)
        {
        //---------Enter your code here-----------
        }
        else if(block == unitPrice)
        {
        //---------Enter your code here-----------
        }
        else if(block == supplier)
        {
        //---------Enter your code here-----------
        }
        else if(block == weight)
        {
        //---------Enter your code here-----------
        }
        else if(block == totalPrice)
        {
        //---------Enter your code here-----------
        }
        else if(block == remark)
        {
        //---------Enter your code here-----------
        }
        else if(block == toggleoutNO)
        {
        //---------Enter your code here-----------
            logical out  = toggleoutNO->GetProperties()->GetLogical("Value");
            coord_system01->GetProperties()->SetLogical("Show",out);
            textHeight->GetProperties()->SetLogical("Show",out);
        }
        else if(block == coord_system01)
        {
        //---------Enter your code here-----------
        }
        else if(block == textHeight)
        {
        //---------Enter your code here-----------
        }
        else if(block == hideBody)
        {
        //---------Enter your code here-----------
        }
        else if(block == enum011)
        {
        //---------Enter your code here-----------
        }
        else if(block == inheriteFrombody)
        {
        //---------Enter your code here-----------
			logical inheritBody = inheriteFrombody->GetProperties()->GetLogical("Value");
			selectFrombody->GetProperties()->SetLogical("Show",inheritBody);
        }
        else if(block == selectFrombody)
        {
        //---------Enter your code here-----------
        }
        else if(block == buttonHideBody)
        {
        //---------Enter your code here-----------
            StlTagVector solidboies;
            CF_GetCurrentPartSolidBodies(solidboies);
            for(int idx = 0; idx < solidboies.size(); ++idx )
            {
                if(USER_ask_obj_has_attr(solidboies[idx],"已设零件标记"))
                    UF_OBJ_set_blank_status( solidboies[idx],UF_OBJ_BLANKED);
            }
        }
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return 0;
}

double MeasureFaceArea(std::vector<NXOpen::TaggedObject* > face_tags)
{
    char str[256];
    NXOpen::Session *theSession = NXOpen::Session::GetSession();
    NXOpen::Part *workPart(theSession->Parts()->Work());    
    Unit *unit1(dynamic_cast<Unit *>(workPart->UnitCollection()->FindObject("SquareMilliMeter")));
    Unit *unit2(dynamic_cast<Unit *>(workPart->UnitCollection()->FindObject("MilliMeter")));

    //FaceCollector issue is fixed in NX9
    NXObject *nullNXObject(NULL);
    MeasureFaceBuilder *measureFaceBuilder1;
    measureFaceBuilder1 = workPart->MeasureManager()->CreateMeasureFaceBuilder(nullNXObject);
        
    vector<Face *> faces1;
	for(int idx = 0; idx < face_tags.size(); ++idx )
	{
		Face *face1 = dynamic_cast<Face *>(face_tags[idx]);
		faces1.push_back(face1);
	}
    FaceDumbRule *faceDumbRule1;
    faceDumbRule1 = workPart->ScRuleFactory()->CreateRuleFaceDumb(faces1);
    
    std::vector<SelectionIntentRule *> rules1(1);
    rules1[0] = faceDumbRule1;
    measureFaceBuilder1->FaceCollector()->ReplaceRules(rules1, false);
    NXOpen::NXObject *nxObjct1 = measureFaceBuilder1->Commit();

    NXOpen::ScCollector *scCollector1 = measureFaceBuilder1->FaceCollector();

    MeasureFaces *measureFaces1;
    measureFaces1 = workPart->MeasureManager()->NewFaceProperties(unit1, unit2, 0.99, scCollector1);

    double face_area = measureFaces1->Area();
	face_area = (int((face_area+0.05)*10))/10.0;
    /*double face_perimeter = measureFaces1->Perimeter();
    sprintf_s(str, sizeof(str), "Selected Face Perimeter: = %f",face_perimeter);*/

    delete measureFaces1;   
    delete faceDumbRule1;
    measureFaceBuilder1->Destroy();
    return face_area;
}

int Property::SetBodyBoundingBoxSize( )
{
	int irc = 0;
	std::vector<NXOpen::TaggedObject* > csysObjects = coord_system0->GetProperties()->GetTaggedObjectVector("SelectedObjects");
	std::vector<NXOpen::TaggedObject* > objects = bodySelect0->GetProperties()->GetTaggedObjectVector("SelectedObjects");
	if( objects.size() > 0 )
	{
		tag_t csys_tag = NULL_TAG;
		tag_t body = objects[0]->Tag();
		if(csysObjects.size() > 0 )
		{
			csys_tag = csysObjects[0]->Tag();
		}
		double min_corner[3]={0.0},directions[3][3]={0.0},distances[3] = {0.0};  
		double box[6] = {0.0};
        double area = 0;
		UF_MODL_ask_bounding_box_exact( body, csys_tag, min_corner, directions, distances );
		distances[0] = (int((distances[0]+0.05)*10))/10.0;
		distances[1] = (int((distances[1]+0.05)*10))/10.0;
		//UF_MODL_ask_bounding_box(objects.at(idx)->GetTag(), box );
		linear_bodyLen->GetProperties()->SetDouble("Value",distances[0]);
		linear_bodyWidth->GetProperties()->SetDouble("Value",distances[1]);
        std::vector<NXOpen::TaggedObject* > faceobjs = face_select0->GetProperties()->GetTaggedObjectVector("SelectedObjects");
		if(faceobjs.size() > 0 )
			area = MeasureFaceArea(faceobjs);
   //     for( int idx = 0; idx < faceobjs.size(); ++idx )
   //     {
   //         double temp = 0;
			////UF_WEIGHT_ask_props
			////UF_MODL_ask_mass_props_3d
   //         //UF_AskFaceArea(faceobjs[idx]->Tag(),&temp);
   //         //area+=temp;
   //     }
		bodyarea->GetProperties()->SetDouble("Value",area);
	}
	return irc;
}
//------------------------------------------------------------------------------
//Callback Name: ok_cb
//------------------------------------------------------------------------------
int Property::ok_cb()
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
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
    return errorCode;
}

//------------------------------------------------------------------------------
//Callback Name: filter_cb
//------------------------------------------------------------------------------
int Property::filter_cb(NXOpen::BlockStyler::UIBlock* block, NXOpen::TaggedObject* selectObject)
{
    return(UF_UI_SEL_ACCEPT);
}

//------------------------------------------------------------------------------
//Callback Name: focusNotify_cb
//This callback is executed when any block (except the ones which receive keyboard entry such as Integer block) receives focus.
//------------------------------------------------------------------------------
void Property::focusNotify_cb(NXOpen::BlockStyler::UIBlock* block, bool focus)
{
    try
    {
        //---- Enter your callback code here -----
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

//------------------------------------------------------------------------------
//Function Name: GetBlockProperties
//Description: Returns the propertylist of the specified BlockID
//------------------------------------------------------------------------------
PropertyList* Property::GetBlockProperties(const char *blockID)
{
    return theDialog->GetBlockProperties(blockID);
}
