#ifndef PORTUTILITY_H
#define PORTUTILITY_H
#include <qstring.h>
#include <printer.h>
#define ESC 0x1b
#define AT 0x40
#define LINE_FEED 0x0a
#define PARENTHESIS_LEFT  40
#define BACKSLASH  92;
#define CAN  0x18
#define CR 0x0d
#define TAB 0x09
#define FF 0x0c
#define SP 0x20
#define FS 0x1c


#define vfd_cmd1 0x0b
#define vfd_return 0x0d
#define vfd_0a 0x0a
#define vfd_clear 0x1c
#define LF 0x0a
#define GS 0x1d
#define I 0x21
#define B 0x42
#define g 103 //15cpi pitch
#define p 112 //used for choosing proportional mode or fixed-pitch
#define t 116 //used for character set assignment/selection
#define l 0x4c //used for setting left margin
#define x 120 //used for setting draft or letter quality (LQ) printing
#define E 69 //bold font on
#define F 70 //bold font off
#define J 74 //used for advancing paper vertically
#define P 80 //10cpi pitch
#define Q 81 //used for setting right margin
#define $ 36 //used for absolute horizontal positioning
#define w 0x77
#define h 0x68
#define V 0x56
#define m 0x30
#define ARGUMENT_0 0
#define ARGUMENT_1 1
#define ARGUMENT_2 2
#define ARGUMENT_3 3
#define ARGUMENT_4 4
#define ARGUMENT_5 5
#define ARGUMENT_6 6
#define ARGUMENT_7 7
#define ARGUMENT_25 0x25
#define k 0x6b
#define UPC_A_1 0
#define UPC_E_1 1
#define JAN13_1 2
#define AN8_1 3
#define CODE39_1 4
#define ITF_1 5
#define CODABAR_1 6

#define UPC_A_2 65
#define UPC_E_2 66
#define JAN13_2 67
#define AN8_2 68
#define CODE39_2 69
#define ITF_2 70
#define CODABAR_2 71
#define CODE93 72
#define CODE128 73
#define CODE_EAN13 67

#define CODE_A "{A"
#define CODE_B "{B"
#define CODE_C "{C"
#define VFDClear 28



class PortUtility
{

private:
    printer myprint;
    QString printer_name;
    int Baudrate;
    bool isusb_flag;
public:
    PortUtility(QString str_printer , int baudrate , bool isusb);
    QString read();
    int open();
    void close();
    bool init();
    void select10CPI();
    void select15CPI();
    void selectDraftPrinting();
    void lineFeed() ;
    void print_and_return ();
    void formFeed() ;
    void bold(bool bold) ;
    void Normal();
    void Elite();
    void Condensed();
    void Emphasized();
    void DoubleStrike_Normal() ;
    void DoubleStrike_Elite() ;
    void DoubleStrike_Condensed() ;
    void DoubleStrike_Emphasized();
    void Enlarged_Normal() ;
    void Enlarged_Elite();
    void Enlarged_Condensed();
    void Enlarged_Emphasized();
    void Underline_Mode();
    void Underline_Cancle();
    void Set_1_8_inch() ;
    void Set_7_72_inch() ;
    void Set_1_6_inch() ;
    void Disables_paper_end_signal() ;
    void Enables_paper_end_signal() ;
    void Set_white_black() ;
    void Cancle_white_black()  ;
   //Mark here 11.11
    void BarCodePrint128(int strBytes, QString str , QString num) ;
    void BarCodePrintEAN13(int strBytes,  QString num);
    void PrintLogo (int logo_num);
    void SetBarCodeHSize(int scale ) ;
    void SetBarCodeHeight(int scale );
    void Cutter ( );
    void print(QString text);

};



#endif // PORTUTILITY_H
