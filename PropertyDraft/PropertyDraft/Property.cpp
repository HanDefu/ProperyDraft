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
VVecNXStringVector configData;
//StlNXStringVector g_allNames;
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

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
//#include "Excel/Excel.h"
//void Property::ReadExcelConfigData( )
//{
//	if (configData.size() > 0)
//		return;
//
//	Excel::CExcelUtil xls;
//	BasicExcel excel;
//    char regfile[256]="";
//    sprintf(regfile,"%s\\Parameter\\Config.xls",getenv("UGII_USER_DIR"));
//	//bool isOk = excel.Load(regfile);
//	xls.OpenExcel(regfile);
//	xls.SetVisible(false);
//	int num = xls.GetSheetNum();
//
//
//	
//
//	for( int idx = 0; idx < num; ++idx )
//	{
//		//xls.GetSheet();
//
//		xls.SetActiveSheet(idx+1);
//
//		size_t maxRows = 256;
//		size_t maxCols = 9;
//
//		VecNXStringVector sheetData;
//		for(int i = 1; i < maxCols; i++)
//		{
//			StlNXStringVector matNameEtc;
//			for(int j = 2; j < maxRows; ++j)
//			{
//				CString str = xls.GetCellValue(j,i).GetBuffer();
//				if (str.GetLength() > 0)
//				{
//				    matNameEtc.push_back(WCHARTOCHAR(str.GetBuffer()));
//				}
//			}
//			sheetData.push_back(matNameEtc);
//		}
//		configData.push_back(sheetData);
//
//	}
//	xls.CloseExcel();
//	return;
//}
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
}

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
        remark->GetProperties()->SetEnumMembers("Value",temp[7]);
    }

	if (type==0 || type==4)//钢材 铝材
	{
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(false);
		bodyarea->SetShow(false);
	}
	else if (type==1 || type==2 || type == 3|| type == 5||type == 5 ||
		type == 6||type == 7||type == 8||type == 9||type == 10)//铝板 树脂板 石材 玻璃等
	{
		linear_bodyLen->SetShow(true);
		linear_bodyWidth->SetShow(true);
		bodyarea->SetShow(true);
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
    }
    catch(exception& ex)
    {
        //---- Enter your exception handling code here -----
        Property::theUI->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeError, ex.what());
    }
}

static tag_t CreateText( NXString& textStr, char* textHeight,Point3d coordinates2,Vector3d xDirection1, Vector3d yDirection1)
{
	NXOpen::Session *theSession = NXOpen::Session::GetSession();
    NXOpen::Part *workPart(theSession->Parts()->Work());

    NXOpen::Features::Text *nullNXOpen_Features_Text(NULL);
    
	int worklayer = -1;
	int layerStatus = -1;
	UF_LAYER_ask_work_layer(&worklayer);
	UF_LAYER_ask_status(255,&layerStatus);
	UF_LAYER_set_status(255, UF_LAYER_WORK_LAYER);
    
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
	double mtx[9], vx[3]={xDirection1.X,xDirection1.Y,xDirection1.Z},vy[3]={yDirection1.X,yDirection1.Y,yDirection1.Z};
	UF_MTX3_initialize(vx,vy,mtx);
	Matrix3x3 element(mtx[0],mtx[1],mtx[2],mtx[3],mtx[4],mtx[5],mtx[6],mtx[7],mtx[8]);
	NXOpen::NXMatrix * orientation = matrixCollection->Create(element);
	
	//coordinateSystem1 = csysCollectionPtr->CreateCoordinateSystem(coordinates2,xDirection1, yDirection1);
	coordinateSystem1 = csysCollectionPtr->CreateCoordinateSystem(coordinates2,orientation,true);

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
	UF_LAYER_set_status(worklayer, UF_LAYER_WORK_LAYER);
	UF_LAYER_set_status(255,layerStatus);
	return texttag;
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

				double topr = totalPrice->GetProperties()->GetDouble("Value");
				double weig = weight->GetProperties()->GetDouble("Value");
				char toprStr[133]="";
				char weigStr[133]="";
				sprintf(toprStr,"%g",topr);
				sprintf(weigStr,"%g",weig);
				Royal_set_obj_attr(body,"材料类型",type.GetLocaleText());
				Royal_set_obj_attr(body,"材料名称",name.GetLocaleText());
				Royal_set_obj_attr(body,"材料编号",maNO.GetLocaleText());
				Royal_set_obj_attr(body,"规格",size.GetLocaleText());
				Royal_set_obj_attr(body,"材质",mate.GetLocaleText());
				Royal_set_obj_attr(body,"密度",dens.GetLocaleText());
				Royal_set_obj_attr(body,"单价",unpr.GetLocaleText());
				Royal_set_obj_attr(body,"供应商",supp.GetLocaleText());
				Royal_set_obj_attr(body,"重量",weigStr);
				Royal_set_obj_attr(body,"总价",toprStr);
				Royal_set_obj_attr(body,"备注",rema.GetLocaleText());
				Royal_set_obj_attr(body,"已设零件标记","1");
				logical is = toggleoutNO->GetProperties()->GetLogical("Value");
				if(is)
				{
					char textHeight[64]="3";
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
					tag_t textTag = CreateText(maNO,textHeight,originPoint,vecDirX,vecDirY);
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
		UF_MODL_ask_bounding_box_exact( body, csys_tag, min_corner, directions, distances );
		//UF_MODL_ask_bounding_box(objects.at(idx)->GetTag(), box );
		linear_bodyLen->GetProperties()->SetDouble("Value",distances[0]);
		linear_bodyWidth->GetProperties()->SetDouble("Value",distances[1]);
		bodyarea->GetProperties()->SetDouble("Value",distances[2]);
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
