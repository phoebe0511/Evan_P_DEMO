#include "portutility.h"
#include <stdio.h>
#include <printer.h>

PortUtility::PortUtility(QString str_printer , int baudrate , bool isusb)
{
    if (baudrate != 0 && isusb!=true)
    {
        printf ("device open at RS232");
       // myprint = new printer();

        printer_name = str_printer;
        Baudrate = baudrate;
        isusb_flag=isusb;
    }
    else
    {
        printf("devcie open at USB");
        printer_name = str_printer;
        Baudrate = 0;
        isusb_flag=isusb;
    }
}


QString PortUtility::read()
{
    return myprint.printerRead();
}

int PortUtility::open()
{
    int rtn = 0 ;
    rtn=myprint.printerOpen(printer_name,isusb_flag);
    if (Baudrate != 0)
    {
        printf("Set baudrate\n");
        myprint.printerSetSpeed(Baudrate);
    }
    printf("open port rtn = %d \n", rtn);

    return rtn ;

}

bool PortUtility::init()
{
    int rtn =0;
    //const char strbuf [] = {ESC,AT};
    QString strbuf ;
    strbuf+=ESC; strbuf+=AT;
    //strbuf += CODE_A;
    rtn=myprint.printerWrite(strbuf); //x1b x40

            printf("init bytes = %d \n " , rtn);

            if (rtn == 2)
            {
                printf("Printer init success\n" );
                  return true;
            }else
            {
                 printf("Printer init fail \n" );
                return false;
            }


}
void PortUtility::close()
{
    myprint.printerClose();

}

void PortUtility::select10CPI() { //10 characters per inch (condensed available)
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC; strbuf+=P;
    rtn=myprint.printerWrite( strbuf); //x1b x40
    printf("open port rtn = %d \n", rtn);


}

void PortUtility::select15CPI() { //15 characters per inch (condensend not available)
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC; strbuf+=g;
    rtn=myprint.printerWrite( strbuf);
    printf("open port rtn = %d \n", rtn);

}

void PortUtility::selectDraftPrinting() { //set draft quality printing
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC; strbuf+=g; strbuf+= (char)48 ;
    rtn=myprint.printerWrite( strbuf);
    printf("open port rtn = %d \n", rtn);
}


void PortUtility::lineFeed() {
    //post: performs new line
    int rtn = 0;
    QString strbuf ;
    strbuf+=LINE_FEED;
    rtn=myprint.printerWrite(strbuf);
    printf("open port rtn = %d \n", rtn);

}

void PortUtility::print_and_return ()
{
     int rtn = 0;
     QString strbuf ;
     strbuf+=CR; strbuf+=LINE_FEED;
     rtn=myprint.printerWrite(strbuf);
     printf("open port rtn = %d \n", rtn);


}

void PortUtility::formFeed() {
    //post: ejects single sheet
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC; strbuf+= (char)100 ; strbuf+= (char)1;
    rtn=myprint.printerWrite(strbuf);
    printf("open port rtn = %d \n", rtn);

}

void PortUtility::bold(bool bold) {
     int rtn = 0;
     QString strbuf ;
    if (bold)
    {
        strbuf+=ESC; strbuf+=E;
        rtn=myprint.printerWrite(strbuf);
    }
    else
    {
        strbuf+=ESC; strbuf+=F;
        rtn=myprint.printerWrite(strbuf);
    }
    printf("open port rtn = %d \n", rtn);

}
void PortUtility::Normal() {
   int rtn = 0;
   QString strbuf ;
   strbuf+=ESC; strbuf+=I; strbuf+=(char)0;
   rtn=myprint.printerWrite(strbuf);
   printf("normal rtn bytes = %d \n" , rtn);
}
void PortUtility::Elite() {
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC; strbuf+=I ; strbuf+= (char)1;
    rtn=myprint.printerWrite(strbuf);
     printf("Elite rtn bytes = %d \n" , rtn);
}

void PortUtility::Condensed() {
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)4;
    rtn=myprint.printerWrite(strbuf);
    printf("Condensed rtn bytes = %d \n" , rtn);
}
void PortUtility::Emphasized() {
    int rtn = 0;
    QString strbuf ;
     strbuf+=ESC;strbuf+=I;strbuf+=(char)8;
    rtn=myprint.printerWrite(strbuf);
    printf("Emphasized rtn bytes = %d \n" , rtn);
}
void PortUtility::DoubleStrike_Normal() {
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)16;
    rtn=myprint.printerWrite(strbuf);
    printf("DoubleStrike_Normal rtn bytes = %d \n" , rtn);
}
void PortUtility::DoubleStrike_Elite() {
    int rtn = 0;
    QString strbuf ;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)17;
    rtn=myprint.printerWrite(strbuf);
    printf("DoubleStrike_Elite rtn bytes = %d \n" , rtn);
}
void PortUtility::DoubleStrike_Condensed() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)20;
    rtn=myprint.printerWrite(strbuf);
    printf("DoubleStrike_Condensed rtn bytes = %d \n" , rtn);
}
void PortUtility::DoubleStrike_Emphasized() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)24;
    rtn=myprint.printerWrite(strbuf);

    printf("DoubleStrike_Emphasized rtn bytes = %d \n" , rtn);
}
void PortUtility::Enlarged_Normal() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)32;
    rtn=myprint.printerWrite(strbuf);
     printf("Enlarged_Normal rtn bytes = %d \n" ,  rtn);
}
void PortUtility::Enlarged_Elite() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)33;
    rtn=myprint.printerWrite(strbuf);
    printf("Enlarged_Elite rtn bytes = %d \n" , rtn);
}
void PortUtility::Enlarged_Condensed() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)36;
    rtn=myprint.printerWrite(strbuf);
    printf("Condensed rtn bytes = %d \n" ,  rtn);
}
void PortUtility::Enlarged_Emphasized() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=I;strbuf+=(char)40;
    rtn=myprint.printerWrite(strbuf);
    printf("Enlarged_Emphasized rtn bytes = %d \n" , rtn);
}
void PortUtility::Underline_Mode() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=(char)45;strbuf+=(char)49 ;
    rtn=myprint.printerWrite(strbuf);
    printf("Underline_mode rtn bytes = %d \n" , rtn);
}
void PortUtility::Underline_Cancle() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=(char)45;strbuf+=(char)48 ;
    rtn=myprint.printerWrite(strbuf);
   printf("Underline_Cancle rtn bytes = %d \n" , rtn);
}

void PortUtility::Set_1_8_inch() {
    int rtn = 0;
     QString strbuf;
     strbuf+=ESC;strbuf+=(char)48 ;
     rtn=myprint.printerWrite(strbuf);
     printf("Set_1_8_inch rtn bytes = %d \n" , rtn);
}
void PortUtility::Set_7_72_inch() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=(char)49 ;
    rtn=myprint.printerWrite(strbuf);
    printf("Set_7_72_inch rtn bytes =  %d \n" , rtn);
}
void PortUtility::Set_1_6_inch() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=(char)50 ;
    rtn=myprint.printerWrite(strbuf);
    printf("Set_1_6_inch rtn bytes = %d \n" , rtn);
}
void PortUtility::Disables_paper_end_signal() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=(char)59 ;
    rtn=myprint.printerWrite(strbuf);
   printf("Disables_paper_end_signal rtn bytes = %d \n" , rtn);
}

void PortUtility::Enables_paper_end_signal() {
    int rtn = 0;
    QString strbuf;
    strbuf+=ESC;strbuf+=(char)57 ;
    rtn=myprint.printerWrite(strbuf);
    printf("Enables_paper_end_signal rtn bytes = %d \n" , rtn);
}

void PortUtility::Set_white_black() { // 0~255
    int rtn = 0;
    QString strbuf;
    strbuf+=GS;strbuf+=B;strbuf+=(char)1 ;
    rtn=myprint.printerWrite(strbuf);
    printf("Setwhite_black rtn bytes = %d \n" , rtn);
}

void PortUtility::Cancle_white_black() { // 0~255
    int rtn = 0;
    QString strbuf;
    strbuf+=GS;strbuf+=B;strbuf+=(char)0 ;
    rtn=myprint.printerWrite(strbuf);
    printf("Cancle white_black rtn bytes = %d \n" , rtn);
}



//Mark here 11.11
void PortUtility::BarCodePrint128(int strBytes, QString str , QString num) {
    int rtn = 0;
    QString number = num ;
    QString strbuf = str;
    QString strout_cmd ="";
    QString numout ="";

    QByteArray byteArray_1=strbuf.toLocal8Bit ();
    char *word=byteArray_1.data();

    QByteArray byteArray_2=number.toLocal8Bit ();
    char *num_word=byteArray_2.data();

    printf ("BarCode 128 %x %x %x %x %x %x \n ",word[0],word[1],word[2],word[3],word[4],word[5]);

    printf ("BarCode 128 %x %x %x %x %x %x \n ",num_word[0],num_word[1],num_word[2],num_word[3],num_word[4],num_word[5]);

    int out =0;

    printf("number .ength = %d \n" , number.length() );

    for (int i =0 ; i<=(number.length()-1) ; i++) // 6~ 1
    {
        //x = number.charAt(i);
        //tmp = Character.getNumericValue(x);
        if ( (i+1) % 2 == 0)
        {
            printf("2 . byte array[%d] = %x \n" , i , num_word[i]);
            out  += (num_word[i] - 0x30) ;
            numout+= out ;
            printf("test here  %d \n", out);
        }
        else
        {
            out = (num_word[i] - 0x30) * 10 ;
            printf("1 . byte array[%d] = %x \n" , i , num_word[i]);
        }
    }
    strout_cmd+= GS;  strout_cmd+=k ; strout_cmd+=CODE128 ; strout_cmd+=(char)strBytes; strout_cmd+=CODE_B;
    strout_cmd+=strbuf ;strout_cmd+=CODE_C;strout_cmd+=numout;strout_cmd+=LINE_FEED;

    rtn=myprint.printerWrite(strout_cmd);
  //    rtn=myprint.write( "" + GS + k + CODE128 + (char)strBytes + CODE_B +
  //          str +  CODE_C + strout_cmd  + LINE_FEED);
    //'\x1d\x6b\x49\x0b\x7b\x42\x52\x52\x2e\x7b\x43\x0c\x22\x38\x0a

    printf("arcode  type CODE128  rtn bytes = %d \n" , rtn);
}

//\x1D\x6B\x43\x0C\x31\x32\x33\x34\x35\x36\x37\x38\x39\x30\x31\x32\x0A
void PortUtility::BarCodePrintEAN13(int strBytes,  QString num) {
    int rtn = 0 ;
    QString strout_cmd= "";
    strout_cmd+=GS ; strout_cmd+=k ; strout_cmd+=CODE_EAN13 ; strout_cmd+= (char)strBytes ;
    strout_cmd+= num ; strout_cmd+= LINE_FEED;

//    rtn=myprint.write( "" + GS + k + CODE_EAN13 + (char)strBytes +
 //           num + LINE_FEED);
    myprint.printerWrite(strout_cmd);
    printf("arcode  type EAN13  rtn bytes = %d \n" , rtn);

}

void PortUtility::PrintLogo (int logo_num)
{
    int rtn = 0;
    QString strbuf;
    strbuf+=FS;strbuf+=p;strbuf+=(char)logo_num;strbuf+=m;

    rtn=myprint.printerWrite(strbuf);
    printf("PringLogo NUMBER: %d\n",logo_num);

}
void PortUtility::SetBarCodeHSize(int scale ) {  //Horizontal  SIZE 0~ 6
    int rtn = 0;
    QString strbuf;
    strbuf+=GS;strbuf+=w;strbuf+=(char)scale;
    rtn=myprint.printerWrite(strbuf);
    printf("SetBarCodeHSize rtn bytes = %d \n" , rtn);
}
void PortUtility::SetBarCodeHeight(int scale ) {  // 1~ 255 default 162
    int rtn = 0;
    QString strbuf;
    strbuf+=GS;strbuf+=h;strbuf+=(char)scale;
    rtn=myprint.printerWrite(strbuf);
    printf("SetBarCodeHeight rtn bytes = %d \n",+ rtn);
}
void PortUtility::Cutter ( ) {  //'\x1d\x56\x42\x00
    int rtn = 0;
     QString strbuf;
    strbuf+=GS;strbuf+=V;strbuf+=m;
    rtn=myprint.printerWrite(strbuf);
    printf("Cutter rtn bytes = %d \n" , rtn);
}

void PortUtility::print(QString text) {
    int rtn = 0;
    QString strbuf;
    strbuf=text;
    rtn=myprint.printerWrite(strbuf);
    printf("print rtn bytes = %d \n" , rtn);
}


