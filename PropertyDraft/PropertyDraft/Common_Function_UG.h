#ifndef COMMON_FUNCTION_UG_H_INCLUDED
#define COMMON_FUNCTION_UG_H_INCLUDED

#include <uf_defs.h>
#include <uf_ui_types.h>
#include <uf.h>
#include <uf_obj.h>
#include <uf_ui.h>
#include <uf_ui_types.h>
#include <uf_modl.h>
#include <uf_object_types.h>
#include <NXOpen/Face.hxx>
#include <NXOpen/Edge.hxx>
#include <NXOpen/Body.hxx>
#include <NXOpen/Plane.hxx>
#include <uf_eval.h>
#include <NXOpen/ugmath.hxx>
#include <NXOpen/GeometricUtilities_BooleanOperation.hxx>
#include <NXOpen/BlockStyler_UIBlock.hxx>
#include "Common_Function.h"
#include "uf_attr.h"
#include <NXOpen/CartesianCoordinateSystem.hxx>
#include <NXOpen/Xform.hxx>
#include <NXOpen/Xform.hxx>
#include <NXOpen/PrintBuilder.hxx>
#include <NXOpen/PlotManager.hxx>

//This function get the minimum distance of two input objects. And outpur two points.
int CF_AskMinimumDist(tag_t obj1, tag_t obj2, 
	double &dis, double *pnt1 = NULL, double *pnt2 = NULL);

//This function get the minimum distance of input object and input guess point. 
//And return the result point on the input object.
int CF_AskMinimumDist(tag_t obj1, double inutpnt[3], double &dis, double *pnt1 = NULL);

//This function get the max distance of two input objects. And return the two result points.
int CF_AskMaxDist(tag_t obj1, tag_t obj2, double &dis, double *pnt1 = NULL, double *pnt2 = NULL );



////---------------------Curve-----------------------//

//This function get the length of input curve.
int  CF_CurveGetLength(tag_t curve, double &len);

//This function get the start and end points of input curve.
int  CF_CurveGetStartEndPoints(tag_t curve, double start[3], double end[3]);

//This function help to check whether the input curve is closed.
bool CF_CurveIsClosed(tag_t curve);

//This funcion check whether the input point is on the curve.
bool CF_CurveCheckPointOnCurve(tag_t curve, double pnt[3]);

//This function extend a input line by input value.
//You can choose to just extend start or end part of this line.
int  CF_CurveExtendCurve(tag_t line, bool extendStart, bool extendEnd, double value = CF_CURVE_EXTEND_LENGTH);

//This function extend a input line by input value.
//You can choose to just extend start or end part of this line.
NXOpen::Point3d  CF_CurveExtendCurve(NXOpen::Point3d start, NXOpen::Point3d end, double value = CF_CURVE_EXTEND_LENGTH);

//This function get the limits of input curve.
int  CF_CurveGetLimits(tag_t curve, double limit[2]);

//This function get the parm from a input point.
int  CF_CurveGetParmFromPoint(tag_t curve, double pnt[3], double &parm);

//This function get the point from input curve and related parm.
int  CF_CurveGetPointFromParm(tag_t curve, double parm, double pnt[3]);

//This function get the intersection point of input curve and another object.
//If there are more than one points, the input ref point is help to output the closeest intersection to this point.
int  CF_CurveGetObjectIntersectPoint(tag_t curve, tag_t object, double pnt[3], double *ref = NULL);

//This function get the length of input curve between two input parms.
int  CF_CurveGetLengthAccordParms(tag_t curve, double startParm, double endParm, double &len);

//small cycle --- 1, else -1
//This function help to check input checkParm is between parm1 and parm2.
bool CF_CurveIsInParm(double parm1, double parm2, double checkParm);

//This function help the check whether checkParm1 and checkParm2 are contain the zero point of input a closed curve.
bool CF_CurveIsKuaiYue(double parm1, double parm2, double checkParm1, double checkParm2, int isSmall);


int CF_ask_line_endpt( tag_t line_id,  double *start_p, double *end_p );
int CF_is_curve_adjacent( tag_t edge1, tag_t edge2,  int *is_adj , int *start = NULL);


///------------------other-------functions------///
int CF_GetDisplayPartFeatures(vtag_t &feats);
int CF_GetWorkPartFeatures(vtag_t &feats);

int UF_AskFaceArea(tag_t face, double *area );

//This function transform a point along a direction with input distance.
int CF_TransPnt(NXOpen::Point3d &pnt, double dir[3], double dis);

//This function create a plane at the related parm of a curve.
//The plane normal is the tangent of curve.
int CF_CreatePlaneAccordingToParm(tag_t curve,  double parm, tag_t &planeTag);


//This function get the tags from list and put then in a vector.
int CF_AskListItems(uf_list_p_t  &list, vtag_t & listTags);

//This function get the tags from list and put then in a vector.
//Then delete the input list.
int CF_AskListItemsAndDelete(uf_list_p_t  &list, vtag_t & listTags);

//This function get the common edge of two faces.
int CF_AskFaceFaceEdges(tag_t face1, tag_t face2, vtag_t &edges);

//This function get the common face of two edges.
int CF_AskEdgeEdgeFace(tag_t edge1, tag_t edge2, tag_t &face);

//This function trim a solid body, and keep the result body which is near to the input reference object.
int CF_BodyTrimAndReferenceObj(tag_t body, tag_t tool, tag_t &frec, tag_t reference = NULL_TAG);

//This function get the normal of mid point of input face.
int CF_FaceAskMidPointNormal(tag_t face, double normal[3]);
int CF_FaceAskMidPointNormal(tag_t face, double normal[3], double point[3]);

//Check to see whether the edge belong to the face.
bool CF_EdgeCheckOnFace(tag_t edgeToCheck, tag_t face);

//This function delete all input features in vector.
int CF_DeleteFrecs(vtag_t &tags);




int CF_GetCurrentPartSolidBodies(vtag_t &bodies);
int CF_GetCurrentPartSolidBodies2(vtag_t &bodies);
int CF_GetCurrentPartFaces(vtag_t &faces);
int CF_GetCurrentPartEdges(vtag_t &edges);
int CF_GetCurrentPartArcs(vtag_t &arcs);
int CF_GetPartSolidBodies(tag_t part, vtag_t &bodies);

//通过颜色区分的形式 红色为起始 绿色为结束
int CF_GetPlanarFaces(vtag_t &faces, vtag_t &planarFaces, tag_t &planar, tag_t &planarend);
//直接得到所有的平面即可
int CF_GetPlanarFaces(vtag_t &faces, vtag_t &planarFaces);
int CF_RemovePlanarFaces(vtag_t &faces);
int CF_GetAdjFaces(tag_t seedFace, vtag_t & faces);


/*
 type UF_MODL_PLANAR_FACE
      UF_MODL_CYLINDRICAL_FACE
	  UF_MODL_TOROIDAL_FACE
*/
int CF_GetAdjFacesWithType(tag_t seedFace, int facetype, tag_t & face, vtag_t &allfaces);
int CF_GetArcEdge(vtag_t &edges, tag_t &edge);

int GetAllValidCurves(vtag_t &validFaces, tag_t &plan, tag_t &planend, vtag_t &validEdges);

int GetCurveCenter(tag_t curve, NXOpen::Point3d &centerpnt);
int GetCurveRad(tag_t curve, double &rad);
int GetArcRad(tag_t curve, double &rad);
int CF_CreateLineWithExtendTwoSide(NXOpen::Point3d start, NXOpen::Point3d end, tag_t &line);
int CF_GetLineLineClosestPoint(tag_t line1, tag_t line2, double pnt[3]);
tag_t CF_CreateLine( double startpoint[3],double endpoint[3] );
bool isPointEqual(NXOpen::Point3d a, NXOpen::Point3d b, double tol);

int CF_SortArcsByName(vtag_t m_arcs);

bool CF_IsTwoEdgeParall(tag_t edge1, tag_t edge2);
bool CF_IsTwoEdgePerpendicular(tag_t edge1, tag_t edge2);

int CF_SplitBody(tag_t &solid, NXOpen::Plane * plane1, vtag_t &splitBodies);


extern void UF_map_abs2wcs    /* Map point from Work coordinate system  */
                /* to Absolute coordinates                */
(
    double *point        /* IO  I:point in ACS  O:point in WCS */
);


extern void UF_map_wcs2abs    /* Map point from Absolute coordinates to */
                /* Work coordinate system coordinates     */
(
    double *point        /* IO  I:point in WCS  O:point in ACS */
);

int CF_SolidIntersect(tag_t first, tag_t second, tag_t &resolid);

int CF_SolidSubtruct(tag_t first, tag_t second);

int CF_InstanceGeometry(vtag_t &bodies, tag_t plane, bool associate);
int CF_InstanceGeometry2(tag_t body, tag_t plane, bool associate, tag_t &outbody);


int RY_GetGoupBodiesForOneBody(tag_t seedBody, vtag_t& allBodies, vtag_t &groupBodies);
int RY_GetMirrorBodiesForOneBody1(tag_t seedBody, vtag_t& allBodies, vtag_t &mirrorBodies);

int RY_GetMirrorBodiesForOneBody1(tag_t seedBody, vtag_t &mirrorBodies);
int RY_GetMirrorBodiesForOneBody(tag_t seedBody, vtag_t& allBodies, vtag_t &mirrorBodies);

int RY_GetSameBodiesForOneBody(tag_t seedBody, vtag_t &sameBodies);
int RY_GetSameBodiesForOneBody(tag_t seedBody, vtag_t& allBodies, vtag_t &mirrorBodies);

int RY_GetWeldBodiesForOneBody(tag_t seedBody, vtag_t &weldBodies);
int RY_GetWeldBodiesForOneBody(tag_t seedBody, vtag_t& allBodies, vtag_t &weldBodies);

int RY_GetGroupSelIndexs(NXString gruopNumber, vint &selIndexs);
int Royal_set_obj_attr_Long(tag_t body, NXString title, NXString &value);
int Royal_get_obj_attr_Long(tag_t obj, NXString title, NXString &value);
int Roy_ask_obj_string_attr( tag_t obj , const char *title , char *string );
logical Royal_get_obj_attr_Long2(tag_t obj, NXString title, NXString &value);
int Royal_set_obj_attr_Long2(tag_t obj, NXString title, NXString &value);
int Royal_ProjectCurveToFace(tag_t curve, tag_t face, tag_t &proFeature);
int Royal_ExtrudeFromCurveWithOffset(tag_t curve, double height, double width, double normal[3], tag_t &feat);
int Royal_Champher(tag_t edge, double angle, double dist, tag_t &feat);
void AddTagToVector( tag_t objTag,vtag_t &vecList );
int NXFUN_ASSY_clone_set_no_log();

NXOpen::Xform * RY_CreateXForm(NXOpen::Point3d origin1,  NXOpen::Vector3d xDirection1, NXOpen::Vector3d yDirection1);
NXOpen::CartesianCoordinateSystem * RY_CreateCoordinateSystem(NXOpen::Xform *xform);
int RY_ImportPart(NXOpen::CartesianCoordinateSystem *ccs, NXString fileName, NXOpen::Point3d destinationPoint1);

int RY_SetText(tag_t text, NXString str, double height = -1);
double RY_GetBodyVolume(tag_t solbody);

NXOpen::Xform * RY_CreateXFormWithThreePoint(NXOpen::Point3d pnt0, NXOpen::Point3d pnt1, NXOpen::Point3d pnt2);
NXOpen::Xform * RY_CreateXFormWithOriuginXYDirection(NXOpen::Point3d origin10, NXOpen::Vector3d xDirection9, NXOpen::Vector3d yDirection9);

NXOpen::CartesianCoordinateSystem * RY_CreateCSYCAccordingToXform(NXOpen::Xform *xform);
int RY_SetViewToCsys(NXOpen::CartesianCoordinateSystem * csys);
NXOpen::Matrix3x3 RY_MatrixConvert(double matrix[9]);
int RY_GetCSYSOri(tag_t csys, double csys_origin[3]);
int RY_GetCSYSMatrix(tag_t csys, double matrix_values[9]);

int RY_CreateBoxWithCSYS_ForBody(tag_t solidBody, tag_t csys, NXOpen::Point3d pnt0, tag_t &boxFeat);
int RY_askFaceArea(tag_t face, double &area);
int RY_MoveObject_CSYS_CSYS(tag_t body, tag_t fromCsys,  tag_t toCsys);

int RY_GetFalseBodysFromTrueBody(tag_t bodyTag, vtag_t &objlist);
tag_t RY_WaveLinkBodyToWorkPart2( vtag_t& bodies,vtag_t& splines, logical Associative, logical Hideoriginal,logical addlineRef );
void RY_WaveLinkSplinesToWorkPart(vtag_t& splines, logical Associative, logical Hideoriginal,logical addlineRef);
int RY_SubtractInAssembly(tag_t targetBody, tag_t toolBody);
int RY_WaveLinkBodyToWorkPart(tag_t body);

int RY_GetFalseBodysAndWaveLink(tag_t linkbodyTag, tag_t tobodyTag, vtag_t &objlist);
int RY_WaveLinkBody(tag_t bodyToLink, tag_t targetPartBody, tag_t &body_waved);
int RY_WaveLinkCurve(tag_t curveToLink, tag_t targetPartObject, tag_t &Curve_waved);
int RY_WaveLinkDatum(tag_t datumplanetolink, tag_t targetPartObject, tag_t &plane_waved);
int Royal_ExtrudeReplaceCurve2(tag_t extrudeFeature, tag_t curve);
int Royal_ExtrudeReplaceCurve(tag_t extrudeFeature, tag_t newCurve);
int Royal_ExtrudeReplaceCurves(tag_t extrudeFeature, vtag_t newCurves);
int Royal_ExtrudeReplaceCurvesWorkPart(tag_t extrudeFeature, vtag_t newCurves);
int Royal_ExtrudeReplaceCurvesOtherPart(tag_t extrudeFeature, vtag_t newCurves);

int CF_ProjectCurveToPlane(tag_t curve, tag_t plane, tag_t &feat);

int RY_Plot
(
    vtag_t &sheets,
	NXOpen::PrintBuilder::PaperSize ps,//NXOpen::PrintBuilder::PaperSizeA4
	NXOpen::PrintBuilder::OrientationOption orientation,//NXOpen::PrintBuilder::OrientationOptionLandscape
	char * printer//"Canon MG7700 series Printer WS"
);

int RY_Plot_Single
(
    tag_t sheet,
	NXOpen::PrintBuilder::PaperSize ps,//NXOpen::PrintBuilder::PaperSizeA4
	NXOpen::PrintBuilder::OrientationOption orientation,//NXOpen::PrintBuilder::OrientationOptionLandscape
	char * printer//"Canon MG7700 series Printer WS"
);

int NXFUN_PRINT_WIN_get_printers(char***printers);

tag_t RY_GetPartForOccurenceBody(tag_t solidBody);
tag_t RY_Prototype(tag_t intag);
tag_t RY_ask_occ_of_entity( tag_t entity );
int RY_ImportParasolid(NXString fileName);
int RY_AddObjectToReferenceSet(tag_t part, vtag_t objs, NXString refsetname);
int RY_GetAllSplinesInPart( const tag_t partTag, vtag_t & splines );

int RY_CreateDatumPlane(NXOpen::Point3d origin, NXOpen::Vector3d & normal, tag_t &plane);
void CreateReferenceSet(vtag_t bodies,NXString& refsetName);

int RY_DraftingPreferences_SetShowLineWidth(bool show);
bool RY_DraftingPreferences_GetShowLineWidth();

//tag_t CreateText(NXString& textStr, char* textHeight, Point3d coordinates2, Vector3d xDirection1, Vector3d yDirection1);
#endif