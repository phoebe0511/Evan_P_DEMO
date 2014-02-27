#ifndef SCANNER_AGENT_THREAD_H
#define SCANNER_AGENT_THREAD_H
#include <qthread.h>
#include <qmutex.h>
/*
class ScannerAgentThread : public QThread {
    Q_OBJECT

public:

ScannerAgentThread(const QString &mes);
void setMessage1(const QString &message);
void setMessage2(const QString &message);
void printMessage(const QString &t);
void stop();

protected:
void run();

private:
QString message_str;
QMutex mutex;
};*/
class Thread : public QThread {
Q_OBJECT

public:
Thread(const QString &mes);
void setMessage1(const QString &message);
void setMessage2(const QString &message);
void printMessage(const QString &t);
void stop();

protected:
void run();

private:
QString message_str;
QMutex mutex;
};

class ThreadDialog : public QDialog {
Q_OBJECT

public:
ThreadDialog(QWidget *parent = 0);

};



#endif // SCANNER_AGENT_THREAD_H
