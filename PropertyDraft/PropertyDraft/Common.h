#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <Vector>
#include <NXOpen/NXString.hxx>

typedef std::vector<NXOpen::NXString> StlNXStringVector;
typedef std::vector<StlNXStringVector> StlNXStringVectorVector;
void WriteBOM( char *srcspc, char* desspc, StlNXStringVectorVector bomStrs);
#endif