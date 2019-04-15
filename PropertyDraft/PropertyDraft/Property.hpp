﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  C:\codeguangzhou\install\application\Property.hpp
//
//        This file was generated by the NX Block Styler
//        Created by: Administrator
//              Version: NX 10
//              Date: 03-18-2019  (Format: mm-dd-yyyy)
//              Time: 19:52
//
//==============================================================================

#ifndef PROPERTY_H_INCLUDED
#define PROPERTY_H_INCLUDED

//------------------------------------------------------------------------------
//These includes are needed for the following template code
//------------------------------------------------------------------------------
#include <uf_defs.h>
#include <uf_ui_types.h>
#include <uf_modl.h>
#include <uf_obj.h>
#include <uf.h>
#include <uf_part.h>
#include <uf_so.h>
#include <uf_vec.h>
#include <uf_assem.h>
#include <uf_mtx.h>
#include <uf_layer.h>
#include <uf_csys.h>
#include <iostream>
#include <NXOpen/Session.hxx>
#include <NXOpen/UI.hxx>
#include <NXOpen/NXMessageBox.hxx>
#include <NXOpen/Callback.hxx>
#include <NXOpen/NXException.hxx>
#include <NXOpen/BlockStyler_UIBlock.hxx>
#include <NXOpen/BlockStyler_BlockDialog.hxx>
#include <NXOpen/BlockStyler_PropertyList.hxx>
#include <NXOpen/BlockStyler_Group.hxx>
#include <NXOpen/BlockStyler_MultilineString.hxx>
#include <NXOpen/BlockStyler_Enumeration.hxx>
#include <NXOpen/BlockStyler_BodyCollector.hxx>
#include <NXOpen/BlockStyler_SpecifyCSYS.hxx>
#include <NXOpen/BlockStyler_Button.hxx>
#include <NXOpen/BlockStyler_DoubleBlock.hxx>
#include <NXOpen/BlockStyler_LinearDimension.hxx>
#include <NXOpen/BlockStyler_Toggle.hxx>
#include <NXOpen/BlockStyler_FaceCollector.hxx>

#include <NXOpen/CoordinateSystemCollection.hxx>
#include <NXOpen/NXMatrixCollection.hxx>
#include <NXOpen/CartesianCoordinateSystem.hxx>
#include <NXOpen/CoordinateSystem.hxx>
#include <NXOpen/BasePart.hxx>
#include <NXOpen/Builder.hxx>
#include <NXOpen/CoordinateSystem.hxx>
#include <NXOpen/Direction.hxx>
#include <NXOpen/Expression.hxx>
#include <NXOpen/ExpressionCollection.hxx>
#include <NXOpen/Features_FeatureCollection.hxx>
#include <NXOpen/Features_TextBuilder.hxx>
#include <NXOpen/GeometricUtilities_FrameOnPathBuilder.hxx>
#include <NXOpen/GeometricUtilities_OnPathDimensionBuilder.hxx>
#include <NXOpen/GeometricUtilities_RectangularFrameBuilder.hxx>
#include <NXOpen/ModelingView.hxx>
#include <NXOpen/ModelingViewCollection.hxx>
#include <NXOpen/NXObject.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/Plane.hxx>
#include <NXOpen/PlaneCollection.hxx>
#include <NXOpen/Point.hxx>
#include <NXOpen/PointCollection.hxx>
#include <NXOpen/Preferences_PartModeling.hxx>
#include <NXOpen/Preferences_PartPreferences.hxx>
#include <NXOpen/ScCollector.hxx>
#include <NXOpen/Section.hxx>
#include <NXOpen/SelectObject.hxx>
#include <NXOpen/SelectSmartObject.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/SmartObject.hxx>
#include <NXOpen/TaggedObject.hxx>

#include <NXOpen/BasePart.hxx>
#include <NXOpen/Body.hxx>
#include <NXOpen/BodyCollection.hxx>
#include <NXOpen/Builder.hxx>
#include <NXOpen/CurveFeatureRule.hxx>
#include <NXOpen/Direction.hxx>
#include <NXOpen/DirectionCollection.hxx>
#include <NXOpen/DisplayableObject.hxx>
#include <NXOpen/Expression.hxx>
#include <NXOpen/ExpressionCollection.hxx>
#include <NXOpen/Features_ExtrudeBuilder.hxx>
#include <NXOpen/Features_Feature.hxx>
#include <NXOpen/Features_FeatureBuilder.hxx>
#include <NXOpen/Features_FeatureCollection.hxx>
#include <NXOpen/Features_Text.hxx>
#include <NXOpen/GeometricUtilities_BooleanOperation.hxx>
#include <NXOpen/GeometricUtilities_Extend.hxx>
#include <NXOpen/GeometricUtilities_FeatureOffset.hxx>
#include <NXOpen/GeometricUtilities_FeatureOptions.hxx>
#include <NXOpen/GeometricUtilities_Limits.hxx>
#include <NXOpen/GeometricUtilities_MultiDraft.hxx>
#include <NXOpen/GeometricUtilities_SimpleDraft.hxx>
#include <NXOpen/GeometricUtilities_SmartVolumeProfileBuilder.hxx>
#include <NXOpen/NXObjectManager.hxx>
#include <NXOpen/Preferences_PartModeling.hxx>
#include <NXOpen/Preferences_PartPreferences.hxx>
#include <NXOpen/ScRuleFactory.hxx>
#include <NXOpen/Section.hxx>
#include <NXOpen/SectionCollection.hxx>
#include <NXOpen/SelectionIntentRule.hxx>
#include <NXOpen/Unit.hxx>
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
using namespace YExcel;

typedef std::vector<tag_t> StlTagVector;
typedef std::vector<NXString> StlNXStringVector;
typedef std::vector<StlNXStringVector> VecNXStringVector;
typedef std::vector<VecNXStringVector> VVecNXStringVector;
//------------------------------------------------------------------------------
//Bit Option for Property: EntityType
//------------------------------------------------------------------------------
#define                         EntityType_AllowBodies (1 << 6);
//------------------------------------------------------------------------------
//Bit Option for Property: BodyRules
//------------------------------------------------------------------------------
#define                           BodyRules_SingleBody (1 << 0);
#define                        BodyRules_FeatureBodies (1 << 1);
#define                        BodyRules_BodiesinGroup (1 << 2);
//------------------------------------------------------------------------------
//Bit Option for Property: SnapPointTypesOnByDefault
//------------------------------------------------------------------------------
#define          SnapPointTypesOnByDefault_UserDefined (1 << 0);
#define             SnapPointTypesOnByDefault_Inferred (1 << 1);
#define       SnapPointTypesOnByDefault_ScreenPosition (1 << 2);
#define             SnapPointTypesOnByDefault_EndPoint (1 << 3);
#define             SnapPointTypesOnByDefault_MidPoint (1 << 4);
#define         SnapPointTypesOnByDefault_ControlPoint (1 << 5);
#define         SnapPointTypesOnByDefault_Intersection (1 << 6);
#define            SnapPointTypesOnByDefault_ArcCenter (1 << 7);
#define        SnapPointTypesOnByDefault_QuadrantPoint (1 << 8);
#define        SnapPointTypesOnByDefault_ExistingPoint (1 << 9);
#define         SnapPointTypesOnByDefault_PointonCurve (1 <<10);
#define       SnapPointTypesOnByDefault_PointonSurface (1 <<11);
#define     SnapPointTypesOnByDefault_PointConstructor (1 <<12);
#define SnapPointTypesOnByDefault_TwocurveIntersection (1 <<13);
#define         SnapPointTypesOnByDefault_TangentPoint (1 <<14);
#define                SnapPointTypesOnByDefault_Poles (1 <<15);
#define     SnapPointTypesOnByDefault_BoundedGridPoint (1 <<16);
#define     SnapPointTypesOnByDefault_FacetVertexPoint (1 <<17);
//------------------------------------------------------------------------------
// Namespaces needed for following template
//------------------------------------------------------------------------------
using namespace std;
using namespace NXOpen;
using namespace NXOpen::BlockStyler;

typedef struct MulBodies
{
	tag_t bodyId;
	NXString projectName;
	NXString projectNo;
	NXString tuMing;
	NXString tuHao;
	NXString riQi;
	NXString leiXing;
	NXString jiShuYaoQiu;

	int tuKuang;


}SMulBodies;

class DllExport Property
{
    // class members
public:
    static Session *theSession;
    static UI *theUI;
    Property();
    ~Property();
    int Show();
    
    //----------------------- BlockStyler Callback Prototypes ---------------------
    // The following member function prototypes define the callbacks 
    // specified in your BlockStyler dialog.  The empty implementation
    // of these prototypes is provided in the Property.cpp file. 
    // You are REQUIRED to write the implementation for these functions.
    //------------------------------------------------------------------------------
    void initialize_cb();
    void dialogShown_cb();
    int apply_cb();
    int ok_cb();
    int update_cb(NXOpen::BlockStyler::UIBlock* block);
    int filter_cb(NXOpen::BlockStyler::UIBlock*  block, NXOpen::TaggedObject* selectObject);
    void focusNotify_cb(NXOpen::BlockStyler::UIBlock* block, bool focus);
    PropertyList* GetBlockProperties(const char *blockID);
    
private:
	const char* theDlxFileName;
	NXOpen::BlockStyler::BlockDialog* theDialog;
	NXOpen::BlockStyler::Group* group;// Block type: Group
	NXOpen::BlockStyler::MultilineString* str_techReq;// Block type: Multiline String
	NXOpen::BlockStyler::Group* group3;// Block type: Group
	NXOpen::BlockStyler::Enumeration* enumType;// Block type: Enumeration
	NXOpen::BlockStyler::BodyCollector* bodySelect0;// Block type: Body Collector
	NXOpen::BlockStyler::Group* group1;// Block type: Group
	NXOpen::BlockStyler::Enumeration* enum09;// Block type: Enumeration
	NXOpen::BlockStyler::Enumeration* enum08;// Block type: Enumeration
    NXOpen::BlockStyler::FaceCollector* face_select0;// Block type: Face Collector
	NXOpen::BlockStyler::SpecifyCSYS* coord_system0;// Block type: Specify Csys
	NXOpen::BlockStyler::Button* buttonCalculate;// Block type: Button
	NXOpen::BlockStyler::DoubleBlock* bodyLen;// Block type: Double
    NXOpen::BlockStyler::LinearDimension* linear_bodyLen;// Block type: Linear Dim
    NXOpen::BlockStyler::LinearDimension* linear_bodyWidth;// Block type: Linear Dim
	NXOpen::BlockStyler::DoubleBlock* bodyWidth;// Block type: Double
	NXOpen::BlockStyler::DoubleBlock* bodyarea;// Block type: Double
	NXOpen::BlockStyler::Group* group0;// Block type: Group
	NXOpen::BlockStyler::Enumeration* matName;// Block type: Enumeration
	NXOpen::BlockStyler::Enumeration* matNO;// Block type: Enumeration
	NXOpen::BlockStyler::Enumeration* matSize;// Block type: Enumeration
	NXOpen::BlockStyler::Enumeration* material;// Block type: Enumeration
	NXOpen::BlockStyler::Enumeration* matDensity;// Block type: Enumeration
	NXOpen::BlockStyler::Enumeration* unitPrice;// Block type: Enumeration
	NXOpen::BlockStyler::Enumeration* supplier;// Block type: Enumeration
	NXOpen::BlockStyler::DoubleBlock* weight;// Block type: Double
	NXOpen::BlockStyler::DoubleBlock* totalPrice;// Block type: Double
	NXOpen::BlockStyler::Enumeration* remark;// Block type: Enumeration
	NXOpen::BlockStyler::Group* group4;// Block type: Group
	NXOpen::BlockStyler::Toggle* toggleoutNO;// Block type: Toggle
	NXOpen::BlockStyler::SpecifyCSYS* coord_system01;// Block type: Specify Csys
    NXOpen::BlockStyler::DoubleBlock* textHeight;// Block type: Double
	NXOpen::BlockStyler::Group* group2;// Block type: Group
	NXOpen::BlockStyler::Toggle* hideBody;// Block type: Toggle
	NXOpen::BlockStyler::Enumeration* enum011;// Block type: Enumeration
	NXOpen::BlockStyler::Toggle* inheriteFrombody;// Block type: Toggle
	NXOpen::BlockStyler::BodyCollector* selectFrombody;// Block type: Body Collector
	NXOpen::BlockStyler::Button* buttonHideBody;// Block type: Button
    int SetBodyBoundingBoxSize( );
    void SetUIConfigData( );
    void ReadExcelConfigData();
    StlNXStringVector sheetNames;
};

void GZ_PART_ATTR_Main();
#endif //PROPERTY_H_INCLUDED
