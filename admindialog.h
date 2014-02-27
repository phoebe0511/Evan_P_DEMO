#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include <QProcess>
#include <QCloseEvent>

#include <stdlib.h>
#include <sys/signal.h>
#include<stdio.h>

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog  
{
    Q_OBJECT
    
public:
    explicit AdminDialog(QWidget *parent = 0);
    ~AdminDialog();

    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent* event);
    void usbPortSetting();
    void printer_test (QString printer_port , int baudrate);
    
private slots:

    void on_pushButton_FingerPrint_start_clicked();

    void on_pushButton_vfd_test_clicked();

    void on_pushButton_usb_printer_test_clicked();

    void on_pushButton_usb_printer_test_2_clicked();

private:
    Ui::AdminDialog *ui;
    QProcess process;
    QString msr_input_str;
    QString ibutton_input_str;
    QString iButton_input_str;
    QString printer1_port_str;
    QString printer2_port_str;
    QString vfd_port_str;
    bool wait_flag1;
    bool wait_flag2;
    bool wait_flag3;
    bool flag1;
    bool flag2;
    bool flag3;
    bool    bliButton;
    int key_count;
    bool track1;
    bool track2;
    bool track3;
    QString string_filter;
};

#endif // ADMINDIALOG_H
