#include "Common.h"
#include "Excel/Excel.h"


void WriteBOM( char *srcspc, char* desspc, StlNXStringVectorVector bomStrs)
{
    Excel::CExcelUtil xls;
    xls.OpenExcel(srcspc);
    //xls.SaveAs(desspc);
    xls.SetVisible(true);
    xls.SetActiveSheet(1);
    //CString str;
    for (int i = 0; i < bomStrs.size(); i++)
    {
        //str.Format(L"%d", i+1);
        StlNXStringVector rowStr = bomStrs[i];
        for (int j = 0; j < rowStr.size(); j++)
        {
            xls.SetCellValue(i+7, j, rowStr[j].GetLocaleText());
        }
    }
    xls.SaveAs(desspc);
    xls.CloseExcel();
}
