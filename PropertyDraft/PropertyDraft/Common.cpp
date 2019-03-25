#include "Common.h"
#include "Excel/Excel.h"


void test( char *srcspc, char* desspc)
{
    Excel::CExcelUtil xls;
    xls.OpenExcel(srcspc);
    //xls.SaveAs(desspc);
    xls.SetVisible(true);
    xls.SetActiveSheet(1);
    CString str;
    for (int i = 0; i < 10; i++)
    {
        //str.Format(L"%d", i+1);
        xls.SetCellValue(i+5, 2, "xxcx");
        //xls.SetCellValue(i+5, 3, str1.GetText());
    }
    xls.SaveAs(desspc);
    xls.CloseExcel();
}
