﻿//==============================================================================
//  WARNING!!  This file is overwritten by the Block Styler while generating
//  the automation code. Any modifications to this file will be lost after
//  generating the code again.
//
//       Filename:  C:\codeRoyal\Royal_code\install\application\Bom.hpp
//
//        This file was generated by the NX Block Styler
//        Created by: Administrator
//              Version: NX 10
//              Date: 03-18-2019  (Format: mm-dd-yyyy)
//              Time: 20:19
//
//==============================================================================

#ifndef BOM_H_INCLUDED
#define BOM_H_INCLUDED

//------------------------------------------------------------------------------
//These includes are needed for the following template code
//------------------------------------------------------------------------------
#include <uf_defs.h>
#include <uf_ui_types.h>
#include <uf.h>
#include <uf_ui.h>
#include <uf_part.h>
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
#include <NXOpen/BlockStyler_Toggle.hxx>
#include <NXOpen/BlockStyler_Enumeration.hxx>
#include <NXOpen/BlockStyler_BodyCollector.hxx>
#include <NXOpen/BlockStyler_StringBlock.hxx>
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
// Namespaces needed for following template
//------------------------------------------------------------------------------
using namespace std;
using namespace NXOpen;
using namespace NXOpen::BlockStyler;
#include "Excel/BasicExcel.hpp"
#include "Common_Function.h"
#include "Common.h"

using namespace YExcel;
class DllExport Bom
{
    // class members
public:
    static Session *theSession;
    static UI *theUI;
    Bom();
    ~Bom();
    int Show();
    
    //----------------------- BlockStyler Callback Prototypes ---------------------
    // The following member function prototypes define the callbacks 
    // specified in your BlockStyler dialog.  The empty implementation
    // of these prototypes is provided in the Bom.cpp file. 
    // You are REQUIRED to write the implementation for these functions.
    //------------------------------------------------------------------------------
    void initialize_cb();
    void dialogShown_cb();
    int apply_cb();
    int ok_cb();
    int update_cb(NXOpen::BlockStyler::UIBlock* block);
    PropertyList* GetBlockProperties(const char *blockID);
    void GetBOMInformation(vtag_t bombodies,int type,StlNXStringVectorVector& BOMStr );
private:
    const char* theDlxFileName;
    NXOpen::BlockStyler::BlockDialog* theDialog;
    NXOpen::BlockStyler::Group* group;// Block type: Group
    NXOpen::BlockStyler::Toggle* toggleOutAll;// Block type: Toggle
    NXOpen::BlockStyler::Enumeration* enumType;// Block type: Enumeration
	NXOpen::BlockStyler::Group* group1;// Block type: Group
	NXOpen::BlockStyler::StringBlock* projectName;// Block type: String
	NXOpen::BlockStyler::StringBlock* projectNumber;// Block type: String
    NXOpen::BlockStyler::BodyCollector* bodySelect;// Block type: Body Collector
    NXOpen::BlockStyler::Group* group0;// Block type: Group
    NXOpen::BlockStyler::Toggle* matName;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* MatNO;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* matSize;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* material;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* desnity;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* length;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* togglearea;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* togglequantity;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggleWeight;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* unitPrice;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* totalPrice;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* supplier;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggleRemark;// Block type: Toggle
    StlNXStringVector gangcaiAttri;
    StlNXStringVector lvbanAttri;
    StlNXStringVector shuzhibanAttri;
    StlNXStringVector shicaiAttri;
    StlNXStringVector lvcaiAttri;
    StlNXStringVector boliAttri;
    StlNXStringVector wujinAttri;
    StlNXStringVector mudiaoAttri;
    StlNXStringVector wumianwaAttri;
    StlNXStringVector tongshiAttri;
    StlNXStringVector fucaiAttri;
};
void GZ_PART_BOM_Main();
#endif //BOM_H_INCLUDED
