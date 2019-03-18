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
//              Time: 10:23
//
//==============================================================================

#ifndef BOM_H_INCLUDED
#define BOM_H_INCLUDED

//------------------------------------------------------------------------------
//These includes are needed for the following template code
//------------------------------------------------------------------------------
#include <uf_defs.h>
#include <uf_ui_types.h>
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
    
private:
    const char* theDlxFileName;
    NXOpen::BlockStyler::BlockDialog* theDialog;
    NXOpen::BlockStyler::Group* group;// Block type: Group
    NXOpen::BlockStyler::Toggle* toggle011;// Block type: Toggle
    NXOpen::BlockStyler::Enumeration* enum0;// Block type: Enumeration
    NXOpen::BlockStyler::BodyCollector* bodySelect0;// Block type: Body Collector
    NXOpen::BlockStyler::Group* group0;// Block type: Group
    NXOpen::BlockStyler::Toggle* toggle0;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle01;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle02;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle04;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle03;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle05;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle012;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle06;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle07;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle08;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle09;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle010;// Block type: Toggle
    NXOpen::BlockStyler::Toggle* toggle013;// Block type: Toggle
    
};
void GZ_PART_BOM_Main();
#endif //BOM_H_INCLUDED
