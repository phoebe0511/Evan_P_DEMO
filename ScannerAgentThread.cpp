#ifndef SCANNERAGENTTHREAD_CPP
#define SCANNERAGENTTHREAD_CPP
#include <ScannerAgentThread.h>
#include <stdio.h>
#include <portutility.h>
ScannerAgentThread::ScannerAgentThread(const QString &scanner_name ,const QString &baudrate ) {
     SCANNER =scanner_name;
     BAUDRATE=baudrate;

}

void ScannerAgentThread::run() {
    PortUtility scanner = PortUtility(SCANNER ,BAUDRATE.toInt() ,false );
    if (scanner.open() != -1)
    {
        while (1)
        {
            QThread::sleep(2);
            message_str=scanner.read();
            emit send(message_str);
            //printf("get scanner data = %s \n", message_str);
        }
    }
}

void ScannerAgentThread::stop() {
     printf("thread stop \n ");
}

QString ScannerAgentThread:: GetScannerStr()
{
    return message_str;
}








#endif
