#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "ImageConverter.h"
#include "ImageProcess.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	//����һ�����̣�չʾ��GUI��û�а���OpenCVͷ�ļ�����µ�ʹ�÷�����
	//��ע��image�Ǳ��ر����������Ҫʹ��QImageCopyToMat�������
	//����ú�������ʱ��image��data����������
	//Ϊʲô�����԰�QImageCopyToMat�ĳ�QImageToMat�ᷢ��ʲô�أ�
	auto image = QImage("2chtex.png");
	Image = ImageConverter::MatToQImage(
		ImageProcess::generate3ChannelsNormalTexture(
			ImageConverter::QImageCopyToMat(image)));
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawImage(QRect{0,0,this->width(),this->height()},Image);

}


