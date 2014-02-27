#include "printer.h"
#include <IO.h>
#define debug
//com.example.test1

printer::printer()
{
    fd = 0;
}
int printer::printerOpen(QString strPort , bool isusb )
{
    fd = dev_Open(strPort , isusb);
}

int printer::printerClose()
{
    return dev_Close(fd);
}

int printer::printerWrite(QString strBuffer)
{
   return dev_Write(fd,strBuffer);
}
QString printer::printerRead()
{
    return dev_Read(fd);
}
int printer::printerSetSpeed(int speed)
{
    return dev_SetSpeed(fd,speed);
}
