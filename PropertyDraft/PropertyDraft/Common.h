#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <Vector>
#include <NXOpen/NXString.hxx>
using namespace NXOpen;
typedef std::vector<NXOpen::NXString> StlNXStringVector;
typedef std::vector<StlNXStringVector> StlNXStringVectorVector;
void WriteBOM( char *srcspc, char* desspc, StlNXStringVectorVector bomStrs, NXString pName, NXString pNumber);

bool isSame(NXString &str1, NXString &str2);
void StrAdd1(NXString &str);//×Ö·û´®¼Ó1
NXString StrMu(NXString &str1, NXString &str2, int xiaoShuDian = 1);//×Ö·û´®Ïà³Ë

NXString StrMu(NXString &str1, double value2, int xiaoShuDian = 1);
#endif