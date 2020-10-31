#include "Common.h"
#include "Excel/Excel.h"

int WriteBomPost(NXString bodyType, Excel::CExcelUtil &xls, int row, StlNXStringVectorVector &BOMStr)
{
	if (strcmp(bodyType.GetLocaleText(), "钢材") == 0)
	{
		NXString shuLiang("0.0"),zongMianJi("0.0");

		//排除重复的
		for (int i = 0; i < BOMStr.size(); i++)
		{
			//插入总重
			shuLiang = StrAdd(shuLiang, BOMStr[i][8], 0);
			zongMianJi = StrAdd(zongMianJi, BOMStr[i][10], 2);
		}

		xls.SetCellValue(row, 9, shuLiang.getLocaleText());
		xls.SetCellValue(row, 11, zongMianJi.getLocaleText());
	}

	return 0;
}

void WriteBOM(NXString bodyType, char *srcspc, char* desspc, StlNXStringVectorVector bomStrs, NXString pName, NXString pNumber, NXString caiLiaoDanHao)
{
    Excel::CExcelUtil xls;
    xls.OpenExcel(srcspc);
    //xls.SaveAs(desspc);
    xls.SetVisible(false);
    xls.SetActiveSheet(1);

	xls.SetCellValue(2,3,pName.getLocaleText());
	xls.SetCellValue(2,6,pNumber.getLocaleText());
	xls.SetCellValue(3,7, caiLiaoDanHao.getLocaleText());


    //CString str;
    for (int i = 0; i < bomStrs.size(); i++)
    {
        //str.Format(L"%d", i+1);
        StlNXStringVector rowStr = bomStrs[i];
        for (int j = 0; j < rowStr.size(); j++)
        {
            //char *temp = (char*)rowStr[j].GetLocaleText();
            CString str(rowStr[j].GetLocaleText());
            xls.SetCellValue(i+5, j+1,str );
        }
    }

	//处理最后一行的合计
	WriteBomPost(bodyType, xls, bomStrs.size() + 5, bomStrs);

    xls.SaveAs(desspc);
    xls.CloseExcel();
}

bool isSame(NXString &str1, NXString &str2)//比较字符串
{
	if (strcmp(str1.GetLocaleText(), str2.GetLocaleText()) == 0)
	{
		return true;
	}
	return false;
}

void StrAdd1(NXString &str)//字符串加1
{
	int value = atoi(str.GetLocaleText());
	value+=1;
	char cstr[32] = "";
	sprintf(cstr, "%d", value);
	str = cstr;
	return ;
}

NXString StrAdd(NXString &str1, NXString &str2, int xiaoShuDian)//字符串相加
{
	double value1 = atof(str1.GetLocaleText());
	double value2 = atof(str2.GetLocaleText());
	value1 += value2;
	char cstr[32] = "";
	if (xiaoShuDian == 0)
		sprintf(cstr, "d%", (int)value1);
	if (xiaoShuDian == 1)
		sprintf(cstr, "%.1f", value1);
	else if (xiaoShuDian == 2)
		sprintf(cstr, "%.2f", value1);
	else if (xiaoShuDian == 3)
		sprintf(cstr, "%.3f", value1);
	else
		sprintf(cstr, "%.4f", value1);
	NXString str = cstr;
	return str;
}


NXString StrMu(NXString &str1, NXString &str2, int xiaoShuDian)//字符串相乘
{
	double value1 = atof(str1.GetLocaleText());
	double value2 = atof(str2.GetLocaleText());
	value1*=value2;
	char cstr[32] = "";
	if (xiaoShuDian == 1)
	    sprintf(cstr, "%.1f", value1);
	else if(xiaoShuDian == 2)
		sprintf(cstr, "%.2f", value1);
	else if(xiaoShuDian == 3)
		sprintf(cstr, "%.3f", value1);
	else
		sprintf(cstr, "%.4f", value1);
	NXString str = cstr;
	return str;
}

NXString StrMu(NXString &str1, double value2, int xiaoShuDian)//字符串相乘
{
	double value1 = atof(str1.GetLocaleText());
	value1*=value2;
	char cstr[32] = "";
	if (xiaoShuDian == 1)
		sprintf(cstr, "%.1f", value1);
	if (xiaoShuDian == 2)
		sprintf(cstr, "%.2f", value1);
	if (xiaoShuDian == 3)
		sprintf(cstr, "%.3f", value1);
	else
		sprintf(cstr, "%.4f", value1);
	NXString str = cstr;
	return str;
}
