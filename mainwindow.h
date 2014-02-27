#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>

#include "admindialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    AdminDialog admindialog;
//evan modified start
    void getProductDetail(QString price , QString product_name , QString product_id);
    void clearProductDetail();
    void setCalculateResult(QString quantity, QString total);
    void makeReceipt();
    void printReceipt();
    int  print_VFD();
    void printer_fun(QString printer_vendor);
    void prepare_product_data();
    void processBarcodeData(QString data);
    void openScanner();
    void configureIODevice();

//evan modified end

    void showSelectImage(QString image_name);
    void showPrice(int price);
    void showQuantity(QString Quantity);
    int showTotal(QString Total);
    
	int current_total; 

signals:
    void itemSelect(int select);
    void numSelect(int num);

private slots:
    void doitemSelect(int select);
    void donumSelect(int num);

    void on_pushButton_item1_clicked();
    void on_pushButton_item2_clicked();
    void on_pushButton_item3_clicked();
    void on_pushButton_item4_clicked();
    void on_pushButton_item5_clicked();
    void on_pushButton_item6_clicked();
    void on_pushButton_item7_clicked();
    void on_pushButton_item8_clicked();
    void on_pushButton_item9_clicked();
    void on_pushButton_item10_clicked();
    void on_pushButton_item11_clicked();
    void on_pushButton_item12_clicked();

    void on_pushButton_num0_clicked();
    void on_pushButton_num00_clicked();
    void on_pushButton_num000_clicked();
    void on_pushButton_num1_clicked();
    void on_pushButton_num2_clicked();
    void on_pushButton_num3_clicked();
    void on_pushButton_num4_clicked();
    void on_pushButton_num5_clicked();
    void on_pushButton_num6_clicked();
    void on_pushButton_num7_clicked();
    void on_pushButton_num8_clicked();
    void on_pushButton_num9_clicked();
    void on_pushButton_enter_clicked();
    void on_pushButton_admin_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_print_clicked();

    void receiveslot(QString s);  //Evan modified
};

#endif // MAINWINDOW_H
