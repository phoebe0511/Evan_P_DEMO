#ifndef IO_H
#define IO_H
#include <qstring.h>

int dev_Open(QString strPort , bool isusb );
int dev_Close( int fd);
int dev_Write( int fd, QString strBuffer);
QString dev_Read(int fd);
int dev_SetSpeed(int fd , int speed );
#endif // PRINTER_H
