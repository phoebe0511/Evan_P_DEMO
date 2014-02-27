#include "admindialog.h"
#include "ui_admindialog.h"
#include <portutility.h>

#define STRIP(netIp) GeneralUtils::inet_ntop_(netIp).c_str()

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    ui->label_msr2->clear();
    ui->label_msr3->clear();
    ui->label_msr1->clear();
   // ui->label_msr1->setText("User Name :");
    usbPortSetting();
    wait_flag1=false;
    wait_flag2=false;
    wait_flag3=false;
    flag1=false;
    flag2=false;
    flag3=false;
    track1=false;
    track2=false; 
    track3=false;	
    key_count=0;
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::closeEvent(QCloseEvent *event)
{
    process.terminate();
}

void AdminDialog::usbPortSetting()
{
    ui->comboBox_vfd->setEditable(false);
    ui->comboBox_vfd->insertItem(0,  "/dev/ttymxc3");
    ui->comboBox_vfd->insertItem(1,  "/dev/ttymxc4");
    //ui->comboBox_vfd->insertItem(2,  "");
    //ui->comboBox_vfd->insertItem(3,  "/dev/ttyUSB3");

    ui->comboBox_printer->setEditable(false);
    ui->comboBox_printer->insertItem(0,  "/dev/ttyUSB0");
    ui->comboBox_printer->insertItem(1,  "/dev/ttyUSB1");
    ui->comboBox_printer->insertItem(2,  "/dev/ttyUSB2");
    ui->comboBox_printer->insertItem(3,  "/dev/ttyUSB3");

    ui->comboBox_printer_2->setEditable(false);
    ui->comboBox_printer_2->insertItem(0,  "/dev/ttyUSB0");
    ui->comboBox_printer_2->insertItem(1,  "/dev/ttyUSB1");
    ui->comboBox_printer_2->insertItem(2,  "/dev/ttyUSB2");
    ui->comboBox_printer_2->insertItem(3,  "/dev/ttyUSB3");

}

//----get string from ibutton and msr function
void AdminDialog::keyPressEvent(QKeyEvent* event)
{
 

 //   if(event->text()=="+"){
 //       bliButton=true;
 //       iButton_input_str.clear();
 //      ui->lineEdit_iButton->clear();
 //   }
   //  printf("got event \n ");
	/*if(event->key() == Qt::Key_Escape)	
	{
		printf("ESC got \n");
	}	
	  

	if(event->key() == Qt::Key_Enter)	
	{
		printf("Enter got \n");
	}*/	
	if(event->key() == Qt::Key_Percent)
	{
		printf("Got Percent line1 start \n");
		 ui->label_msr1->clear();
		 ui->label_msr2->clear();
		 ui->label_msr3->clear();
		 //ui->label_msr4->clear();
		msr_input_str.clear();
		if (track1==true)
		{
			printf("1 Get Track1 again\n");
			msr_input_str="";
			track1=false;
			//track2=false;
			 ui->label_msr1->clear();
			 ui->label_msr2->clear();
			 ui->label_msr3->clear();
			// ui->label_msr4->clear();
			//usleep(10000);
		
		}
		if (track2==true)
		{
			printf("2 Get Track1 again\n");
			msr_input_str="";
			track1=false;
			track2=false;
			 ui->label_msr1->clear();
			 ui->label_msr2->clear();
			 ui->label_msr3->clear();
			 //ui->label_msr4->clear();
			
		}
		flag1=true;
	}  
	if(event->key() == Qt::Key_Question)
	{
		printf("Got Question flag1 =%d  flag2=%d\n" , flag1 ,flag2);
		if(flag1==true)
		{
			//printf("Got Question line1 end\n");			
			flag1=false;
			track1=true;
			printf("Track1 %s -\n" , msr_input_str.toStdString().c_str()  );
			//string_filter=msr_input_str;
			
			ui->label_msr1->setText(msr_input_str);
			msr_input_str.clear();
			//
          			 
		}
		if(flag2==true)
		{
			printf("Got Question Line2 end\n");	
			 			
			flag2=false;
			printf("Track2 %s -\n" , msr_input_str.toStdString().c_str()  );
			//string_filter=msr_input_str;
			/*if(ui->lineEdit_msr_track2->text().isEmpty()   )
			{
				 ui->lineEdit_msr_track2->setText(string_filter);			
			}*/
			ui->label_msr2->setText(msr_input_str);	
			msr_input_str.clear();
			track2=true;
			 
			
		}
		
		if(flag3==true)
		{
			//printf("Got Question Line3 end\n");			
			flag3=false;
			 
			printf("Track3 %s -\n" , msr_input_str.toStdString().c_str()  );
			//string_filter=msr_input_str;
			/*if(ui->lineEdit_msr_track3->text().isEmpty()   )
          		{	  ui->lineEdit_msr_track3->setText(string_filter);
		 	} */          
      			ui->label_msr3->setText(msr_input_str);
			msr_input_str.clear();
			 
		}			
	}  
	if (event->key() == Qt::Key_Semicolon)
	{
		msr_input_str.clear();
		if (track1==true)
		{	//printf("Got Semicolon ,Line 2 Start \n");
			flag2=true;
			track1=false;
		
		}
		if (track2==true)
		{	//printf("Got Semicolon ,Line 3 Start \n");
			track2=false;			
			flag3=true;
		
		}
		
	}	
	
 
 msr_input_str+=event->text();
	 
	if (msr_input_str.contains ("34000014FAEB7701") )
	{
		ui->label_iButton->setText(msr_input_str);
		if (msr_input_str.contains ("00000000"))
		{
			msr_input_str.clear();
		}
			
	} 
//    printf(" %s-" ,event->text().toStdString().c_str());
  //  usleep(1000);
    /*if(event->text()=="%" &  wait_flag2 == false){
        bliButton=false;
        wait_flag1=true;
        msr_input_str.clear();
        ui->lineEdit_msr_track1->clear();
        ui->lineEdit_msr_track2->clear();
        ui->lineEdit_msr_track3->clear();
	printf("get start track1 \n");
    } */
/*	
        if(event->text()=="%" &  wait_flag2 ==true){
        bliButton=false;
        wait_flag1=true;
	wait_flag2=false;
	wait_flag3=false;  
      msr_input_str.clear();
        ui->lineEdit_msr_track1->clear();
        ui->lineEdit_msr_track2->clear();
        ui->lineEdit_msr_track3->clear();
	printf("get track1 again\n");
	
    } 
*/

  //  if(event->text()==";"){
  //      msr_input_str.clear();
  //  }
//  msr_input_str+=event->text();
   // ibutton_input_str +=  msr_input_str ;
/*	if (msr_input_str.contains ("34000014FAEB7701") )
	{	
		ui->lineEdit_iButton->setText("");
		usleep(10000);
		printf("evant %s \n",msr_input_str.toStdString().c_str()) ;
		ui->lineEdit_iButton->setText(msr_input_str);
		msr_input_str.clear();
		
	}
*/
/*
	if (ibutton_input_str.contains ("00000000")  && ibutton_input_str.length()  <= 12)
	{
		
		//printf("evant %s \n",msr_input_str.toStdString().c_str()) ;
		ui->lineEdit_iButton->setText("");
		ibutton_input_str.clear();
	}
 */	
   /* if(event->text()=="?" & wait_flag1 == true){
       // if(bliButton){
           // ui->lineEdit_iButton->setText(msr_input_str);
          //  msr_input_str.clear();
         //   bliButton=false;
         //   return;
        //}
	printf("ready print track1 \n");
        if(ui->lineEdit_msr_track1->text().isEmpty()){
            ui->lineEdit_msr_track1->setText(msr_input_str);
	    printf("evant %s \n",msr_input_str.toStdString().c_str()) ;
	    wait_flag2=true;
	     msr_input_str.clear();
            return;
        }

        if(ui->lineEdit_msr_track2->text().isEmpty()){
            ui->lineEdit_msr_track2->setText(msr_input_str);
	    wait_flag3=true;
	    msr_input_str.clear();
            return;
        }

        if(ui->lineEdit_msr_track3->text().isEmpty() & wait_flag2 == true ){
            ui->lineEdit_msr_track3->setText(msr_input_str);
		wait_flag1=false;
		wait_flag2=false;
	        wait_flag3=false;
		msr_input_str.clear();
            return;
        }
	  //msr_input_str.clear();
    }
	usleep(200);
    /*
    msr_input_str+=event->text();
    ui->lineEdit_msr_track3->setText(msr_input_str);;
    */
}

void AdminDialog::on_pushButton_FingerPrint_start_clicked()
{
    //this->close();

    //system("fprint_demo");

    process.start("fprint_demo");

    // 可以放在Proc所在的類的析構函數中， 用於等待子進程結束
    //process.waitForFinished();

}


void AdminDialog::on_pushButton_vfd_test_clicked()
{
    QString command;
    printer1_port_str=ui->comboBox_vfd->currentText();
    printf("printer1_port_str=%s\n",printer1_port_str.toStdString().c_str());
    command.clear();
    command.sprintf("stty -F %s  38400 ; echo -e  '\x1b\x40' > %s ;echo -e  '\x1c' > %s; echo %s > %s "
                    ,printer1_port_str.toStdString().c_str()
                    ,printer1_port_str.toStdString().c_str()
                    ,printer1_port_str.toStdString().c_str()
                    ,"Line1:12345678901234Line2:12345678901234"
                    ,printer1_port_str.toStdString().c_str());
    system(command.toStdString().c_str());

}

void AdminDialog::on_pushButton_usb_printer_test_clicked()
{
    /*
    QString command;

    printer1_port_str=ui->comboBox_printer->currentText();
    command.clear();
    command.sprintf("stty -F %s 19200 ;echo ./testpage/1.dat > %s"
                    ,printer1_port_str.toStdString().c_str()
                    ,printer1_port_str.toStdString().c_str());
    system(command.toStdString().c_str());
*/
    printer1_port_str=ui->comboBox_printer->currentText();
    printer_test(printer1_port_str,0);
}

void AdminDialog::on_pushButton_usb_printer_test_2_clicked()
{/*
    QString command;
    printer1_port_str=ui->comboBox_printer_2->currentText();

    command.clear();
    command.sprintf("stty -F %s 19200 ;echo ./testpage/1.dat > %s"
                    ,printer1_port_str.toStdString().c_str()
                    ,printer1_port_str.toStdString().c_str());
    system(command.toStdString().c_str());
    */

    printer1_port_str=ui->comboBox_printer_2->currentText();
    printer_test(printer1_port_str,19200);
}


void AdminDialog::printer_test (QString printer_port , int baudrate)
{

  QString strbuf_pinfo;
  bool isusb=true;
  strbuf_pinfo+="   Item id:"; strbuf_pinfo+="0x1234";
  strbuf_pinfo+=" " ; strbuf_pinfo +="Test_item 1";
  strbuf_pinfo+= " - price " ; strbuf_pinfo+="999999";
  strbuf_pinfo+=" * " ; strbuf_pinfo+="9999999";
  QString strbuf_ptotal;


  strbuf_ptotal+="        $"; strbuf_ptotal+="999999999";
  if (baudrate != 0)
  {
       isusb = false;
  }

     //if (printer_vendor== "epson")
   //  {
         PortUtility myprinter = PortUtility(printer_port ,baudrate ,isusb );

        printf("printer_vendor== epson \n") ;

        if (myprinter.open() == -1)
         {
             printf("usb printer port open fail \n");

         }
         myprinter.init();

         myprinter.print("*****EPSON Test START*****");

         myprinter.print_and_return();

         myprinter.PrintLogo(1); // Printer number 1


         myprinter.formFeed();
         myprinter.init();
         myprinter.Enlarged_Normal();
         myprinter.print("Tweverlight Corp ");
         myprinter.print_and_return();
         myprinter.lineFeed();
         myprinter.init();
         myprinter.DoubleStrike_Normal();
         myprinter.print("    Test Serial No:12345678 ");
         myprinter.lineFeed();
         myprinter.init();
         myprinter.print("      ");
         myprinter.DoubleStrike_Emphasized();
         myprinter.Set_white_black();

         myprinter.print("Evan Agency Receipt");
         myprinter.lineFeed();
         //sleep(1);
         myprinter.lineFeed();

         myprinter.init();
         myprinter.formFeed();
         myprinter.Emphasized();

         myprinter.print( strbuf_pinfo  ); //print product info


         myprinter.print_and_return();
         myprinter.lineFeed();
         sleep(1);
         myprinter.lineFeed();

         myprinter.init();
         myprinter.Enlarged_Normal();
         myprinter.print("Total :");
         myprinter.Underline_Mode();

         myprinter.print(strbuf_ptotal);  //print product total price

         myprinter.lineFeed();

         myprinter.init();

         myprinter.SetBarCodeHeight(32);
         myprinter.SetBarCodeHSize(2);  //Horizontal  SIZE 0~ 6
         myprinter.BarCodePrintEAN13(12,"123465789012");

         myprinter.init();

         myprinter.DoubleStrike_Emphasized();
         myprinter.print("     Service (FAX) : 02-123456789");
         myprinter.print_and_return();
         myprinter.lineFeed();
         myprinter.print("     Service (TEL) : 02-987654321");
         myprinter.print_and_return();
         myprinter.init();
         myprinter.formFeed();
         myprinter.formFeed();


         myprinter.print("*****Test Receipt END*****");
         myprinter.print_and_return();

       //  escprinter.Cutter();
         myprinter.close();
  //  }
}
