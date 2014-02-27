#ifndef PRINTER_H
#define PRINTER_H
#include <qstring.h>
class printer
{
private:
    int fd ;
public:
    printer();
    int printerOpen(QString strPort , bool isusb );

    int printerClose();
    int printerWrite(QString strBuffer);
    QString printerRead();
    int printerSetSpeed(int speed);
};

#endif // DEVICE_UTILITY_H
