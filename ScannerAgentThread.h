#ifndef SCANNERAGENTTHREAD_H
#define SCANNERAGENTTHREAD_H

#include <QThread>


class ScannerAgentThread : public QThread {
Q_OBJECT
public:
ScannerAgentThread(const QString &scanner,const QString &baudrate);
QString GetScannerStr();
void stop();

protected:
void run();

private:
int cnt;
QString SCANNER;
QString BAUDRATE;
QString message_str;
//QMutex mutex;

signals:
    void send(QString s);


};






#endif
