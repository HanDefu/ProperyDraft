#pragma once
#include "..\\Excel\CApplication.h"
#include "..\\Excel\CFont0.h"
#include "..\\Excel\CRange.h"
#include "..\\Excel\CRanges.h"
#include "..\\Excel\CWorkbook.h"
#include "..\\Excel\CWorkbooks.h"
#include "..\\Excel\CWorksheet.h"
#include "..\\Excel\CWorksheets.h"
#include "..\\Excel\CBorders.h"
#include "..\\Excel\CBorder.h"
#include "..\\Excel\Cnterior.h"
#include <io.h>

namespace Excel 
{
    class  CExcelUtil
    {
    private:
        CString out_file_name;
    public:
        CString GetOutFileName() { return out_file_name; };
        void SetOutFileName(CString new_file_name) 
        { if (new_file_name.GetLength()>0) out_file_name = new_file_name; }

    public:
        CApplication m_excelApp;
        CWorkbooks    m_excelBooks;
        CWorkbook    m_excelBook;
        CWorksheets     m_excelSheets;
        CWorksheet   m_excelSheet;
        CRange        m_excelRange;

    public:
        void CreateExcel();
        void OpenExcel(CString fileName);
        bool SaveExcel();
        void CloseExcel();
		void SetVisible(bool bvi);
        // <summary>
        // ȡ���ض���Worksheet
        //</summary>
        // <param name="SheetName">worksheet������</param>
        //<returns></returns>
        CWorksheet GetSheet(CString SheetName);

        /// <summary>
        /// ȡ���ض���Worksheet
        /// </summary>
        /// <param name="index">worksheet����������1��ʼ</param>
        /// <returns></returns>
        CWorksheet GetSheet(int index);

        /// <summary>
        /// ����ض���Worksheet
        /// </summary>
        /// <param name="SheetName">����ӵ�worksheet������</param>
        /// <returns>�ɹ����ش�����worksheet���������̨��ӡ��Ӧ�ĳ�����Ϣ</returns>
        CWorksheet AddSheet(CString SheetName);

        /// <summary>
        /// ȡ��sheet������
        /// </summary>
        /// <returns>sheet������</returns>
        int GetSheetNum();

        //������Ԫ��/�ϲ���Ԫ��
        /// <summary>
        /// �����ض��ĵ�Ԫ��
        /// </summary>
        /// <param name="ColNum">�к�,��1��ʼ,������255</param>
        /// <param name="RowNum">�к�,��1��ʼ,������255</param>
        /// <returns></returns>
        CString GetCell(int ColNum, int RowNum);

        //ȡ��һ����Ԫ��
        void SetRange(int ColNum, int RowNum);

        //ȡ��һ����Ԫ������
        void SetRange(int StartColNum, int StartRowNum, int EndColNum, int EndRowNum);

        //�ϲ�һ����Ԫ������
        void Merge(int startRowIndex, int startColIndex, int endRowIndex, int endColIndex);

        //��Ԫ��ֵ/��Ԫ������ֵ
        void SetCellValue(CString value);
        void SetCellValue(int row, int col, CString value);
		void SetCellFormula(int row, int col, CString value);
        void SetCellStringFormat();
        void SetCellValue( int startRow,int startCol, int endRow, int endCol, CString value );
        CString GetCellValue( int row, int col );

		void SetCellActive(int row, int col);

        //���õ�Ԫ����ʽ
        void SetBoldFontAndSize( int size );
		void SetTxtColor(int color);
		void SetTxtColor(int row, int col, int color);

        //���ñ�����Ϊ����Ӧ���
        //���ñ�����Ϊ����Ӧ���
        void SetAutoFitColumns( int startRow, int startCol, int endRow, int endCol );
        void SetCenterAlign();
        void SetBorder();


		//����������ӵ�201108 ר��ΪMD ��׼ȷ��
		int SetActiveSheet(long iSheetName);
		int SetSheetCellValue(long iSheetName, long irow, long icol,VARIANT &vt);
		int GetSheetCellValue(long iSheetName, long irow, long icol,VARIANT &vt);
		int GetSheetCellValue(long irow, long icol,VARIANT &vt);
		//int GetSheetValues(long maxCol,vvCString &strs);
		BOOL SaveAs(char* pFileSavePath);
		BOOL IsFileExist(char* pFilename, BOOL bDir);

    };
}
