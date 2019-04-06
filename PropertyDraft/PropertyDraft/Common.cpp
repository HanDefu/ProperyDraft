#include "Common.h"
#include "Excel/Excel.h"

void WriteBOM( char *srcspc, char* desspc, StlNXStringVectorVector bomStrs, NXString pName, NXString pNumber)
{
    Excel::CExcelUtil xls;
    xls.OpenExcel(srcspc);
    //xls.SaveAs(desspc);
    xls.SetVisible(false);
    xls.SetActiveSheet(1);

	xls.SetCellValue(3,3,pName.getLocaleText());
	xls.SetCellValue(3,6,pNumber.getLocaleText());

	

    //CString str;
    for (int i = 0; i < bomStrs.size(); i++)
    {
        //str.Format(L"%d", i+1);
        StlNXStringVector rowStr = bomStrs[i];
        for (int j = 0; j < rowStr.size(); j++)
        {
            //char *temp = (char*)rowStr[j].GetLocaleText();
            CString str(rowStr[j].GetLocaleText());
            xls.SetCellValue(i+7, j+1,str );
        }
    }
    xls.SaveAs(desspc);
    xls.CloseExcel();
}


bool isSame(NXString &str1, NXString &str2)//±È½Ï×Ö·û´®
{
	if (strcmp(str1.GetLocaleText(), str2.GetLocaleText()) == 0)
	{
		return true;
	}
	return false;
}

void StrAdd1(NXString &str)//×Ö·û´®¼Ó1
{
	int value = atoi(str.GetLocaleText());
	value+=1;
	char cstr[32] = "";
	sprintf(cstr, "%d", value);
	str = cstr;
	return ;
}

NXString StrMu(NXString &str1, NXString &str2, int xiaoShuDian)//×Ö·û´®Ïà³Ë
{
	double value1 = atof(str1.GetLocaleText());
	int value2 = atof(str2.GetLocaleText());
	value1*=value2;
	char cstr[32] = "";
	if (xiaoShuDian == 1)
	    sprintf(cstr, "%.1f", value1);
	else
		sprintf(cstr, "%.2f", value1);
	NXString str = cstr;
	return str;
}

NXString StrMu(NXString &str1, double value2, int xiaoShuDian)//×Ö·û´®Ïà³Ë
{
	double value1 = atof(str1.GetLocaleText());
	value1*=value2;
	char cstr[32] = "";
	if (xiaoShuDian == 1)
		sprintf(cstr, "%.1f", value1);
	else
		sprintf(cstr, "%.2f", value1);
	NXString str = cstr;
	return str;
}