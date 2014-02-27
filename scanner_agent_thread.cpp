#include <scanner_agent_thread.h>
#include <qdebug.h>
#include <qthread.h>

Thread::Thread(const QString &mes) {
message_str = mes;
}

void Thread::run() {
//mutex.lock();
//QThread::msleep(1000);
//printMessage("START");
//mutex.unlock();
}

void Thread::stop() {
//mutex.lock();
//printMessage("STOP");
//mutex.unlock();
}

void Thread::setMessage1(const QString &message) {
//mutex.lock();
printMessage("START");
message_str = message;
QThread::msleep(2000);
printMessage("STOP");
//mutex.unlock();
}

void Thread::setMessage2(const QString &message) {
//mutex.lock();
printMessage("START");
message_str = message;
QThread::msleep(2000);
printMessage("STOP");
//mutex.unlock();
}

void Thread::printMessage(const QString &t) {
qDebug() << t << ": " << message_str << flush;
}
ThreadDialog::ThreadDialog(QWidget *parent) : QDialog(parent) {
Thread threadA("A");
Thread threadB("B");
threadA.start();
threadB.start();
threadA.setMessage1("A");
threadB.setMessage2("B");


//threadB.stop();
//threadA.stop();
}
