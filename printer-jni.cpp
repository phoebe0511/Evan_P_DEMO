#include <assert.h>
#include <string.h>

#include <termio.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <android/log.h>
#include <stdbool.h>
#include <jni.h>
#define debug
//com.example.test1


JNIEXPORT jint JNICALL
Java_com_austin_arm_1demo_printer_printerOpen( JNIEnv* env, jobject thiz, jstring strPort , jboolean isusb )
{
    struct termio tio;
    int tty_fd;
    const char *port;
    char *c_msg = NULL ;
    bool isusb_flag;
    isusb_flag = isusb;

    if (isusb_flag)
    {
    	__android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"usb flag = true \n");
    }
    if (strPort == NULL)
        return -1;

    port = (*env)->GetStringUTFChars(env, strPort, NULL);

    c_msg = (char *) (*env) -> GetStringUTFChars(env,strPort,0);
#ifdef debug
    __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"printer test here -> %s \n" ,c_msg);
#endif
 //   tty_fd = open(port, O_RDWR );
    if (!isusb_flag)
    {
    	 __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"is OPENING RS232 DEVICE\n" );
    	tty_fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    }else
    {
    	tty_fd = open(port, O_RDWR );
    }
    (*env)->ReleaseStringUTFChars(env, strPort, port);

    if (tty_fd == -1 )
    {
    	 __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"open port fail -> rtn = %d \n" ,tty_fd);
    	 return -1;
    }else
    {
    	 __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"open port  pass\n" );
    }

    if (!isusb_flag)
    {
    	 __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"is RS232 DEVICE\n" );
    if (ioctl(tty_fd, TCGETA, &tio)){
        	close(tty_fd);
        	return -1;
        }

        tio.c_iflag &= ~( INLCR | ICRNL | IUCLC | ISTRIP | BRKINT);
        tio.c_iflag = tio.c_iflag | IGNBRK | IGNPAR;
        tio.c_oflag &= ~( OPOST );
        tio.c_lflag &= ~( ECHO | ISIG | ICANON);
        tio.c_cflag |= (CLOCAL | CREAD);
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B2400;
        tio.c_cflag &= ~(PARENB | PARODD); // no parity
        tio.c_cflag = (tio.c_cflag & ~CSIZE) | CS8;
        tio.c_cflag &= ~CSTOPB; // 1 stop bit; If CSTOPB is set, two stop bits are used.

        tio.c_cc[VMIN]=1;
        tio.c_cc[VTIME]=0;


        if (ioctl(tty_fd, TCSETA, &tio)){
        	close(tty_fd);
        	return -1;
        }
    }

    return tty_fd;
}

JNIEXPORT jint JNICALL
Java_com_austin_arm_1demo_printer_printerClose( JNIEnv* env, jobject thiz, jint fd)
{
	int rtn=0 ;
	if (fd == -1)
	{
		return -1;
	}
#ifdef debug

	rtn = close(fd);
	 __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"close port -> rtn = %d \n" ,rtn);
	return rtn;
#else
	 __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"port closed\n");
	return close(fd);
#endif
}

JNIEXPORT jint JNICALL
Java_com_austin_arm_1demo_printer_printerWrite( JNIEnv* env, jobject thiz, jint fd, jstring strBuffer)
{
    const char *buffer;
    int total_bytes = 0;
    int buffer_len;
    int i =0;
#ifdef debug
    if (fd == -1)
    {
    	 __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"write port fail-> fd = -1 \n");
        	return -1;
    }
    if (strBuffer == NULL)
    {
    	__android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"write port fail-> strBuffer = null \n");
    	return -1;
    }
        buffer = (*env)->GetStringUTFChars(env, strBuffer, NULL);
        if (buffer == NULL)
            return -1;
        buffer_len = (*env)->GetStringLength(env, strBuffer);
        if (buffer_len <=0 )
        	return 0;
        total_bytes = write(fd, buffer, buffer_len);

        __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"write length return -> total_bytes = %d \n show data in below \n " ,total_bytes);

        for (i =0 ; i < buffer_len ; i++)
        {

        	__android_log_print (ANDROID_LOG_DEBUG ,"printer" ," %x " ,buffer[i]);
        }
        __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"\n" );
        (*env)->ReleaseStringUTFChars(env, strBuffer, buffer);
#else
    if (fd == -1)
    	return -1;
    if (strBuffer == NULL)
        return -1;

    buffer = (*env)->GetStringUTFChars(env, strBuffer, NULL);
    if (buffer == NULL)
        return -1;
    buffer_len = (*env)->GetStringLength(env, strBuffer);
    if (buffer_len <=0 )
    	return 0;
    total_bytes = write(fd, buffer, buffer_len);
    (*env)->ReleaseStringUTFChars(env, strBuffer, buffer);
#endif
    return total_bytes;
}


#define MAX_BUFFER_LEN 64
JNIEXPORT jstring JNICALL
Java_com_austin_arm_1demo_printer_printerRead( JNIEnv* env, jobject thiz, jint fd)
{

    char buffer[MAX_BUFFER_LEN];
    int bytes;
    int i = 0 ;
	if (fd == -1)
		return NULL;

	bytes = read(fd,(char *) buffer, MAX_BUFFER_LEN-1);
    if (bytes == -1)
    {
    	memset(buffer,0x00,sizeof(buffer));
    	buffer[0] = '\0';

    }else if (bytes >0)
    {
    	buffer[bytes-1] = 0x00;
    	__android_log_print (ANDROID_LOG_DEBUG ,"JNIprinter" ,"ReadByte ->counts = %d  , buffer = %s \n" ,bytes ,buffer);
    }
/*

    for (i= 0 ; i < bytes ; i ++)
    {
      	   __android_log_print (ANDROID_LOG_DEBUG ,"JNIprinter" ,"Read Byte -> %d ibytes = %x \n" ,i,buffer[i]);

    }*/

    return (*env)->NewStringUTF(env, buffer);

}

JNIEXPORT jint JNICALL
Java_com_austin_arm_1demo_printer_printerSetSpeed( JNIEnv* env, jobject thiz, jint fd, jint speed)
{
    struct termio tio;

    if (fd == -1)
		return -1;

    if (ioctl(fd, TCGETA, &tio))
    	return -1;

    switch (speed) {
    case 1200:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B1200;
    	break;
    case 2400:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B2400;
    	break;
    case 4800:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B4800;
    	break;
    case 9600:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B9600;
    	break;
    case 19200:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B19200;
    	break;
    case 38400:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B38400;
    	break;
    case 57600:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B57600;
    	break;
    case 115200:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B115200;
        __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"baydrate = %d \n" ,speed);
    	break;
    case 230400:
        tio.c_cflag = (tio.c_cflag & ~CBAUD) | B230400;
    	break;
    }
    __android_log_print (ANDROID_LOG_DEBUG ,"printer" ,"Set Speed -> rate = %d \n" ,speed);
    if (ioctl(fd, TCSETA, &tio))
    	return -1;

    return 0;
}




