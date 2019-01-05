#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QString>
#include <string>
//#include <ImageProcess.h>

//ImageProcess newProcessor;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addLayer_clicked() {
    static int k = 1;
    QString title;
    title.setNum(k);//int to QString
    QByteArray ba = title.toLatin1();
    const char* ch = ba.data();//QString to char*

    Layer L;//后端需要创建一个空的Layer,id为k

    addLayerAsBottom(L);
    k++;
    ui->toolBox->addItem(new QLabel(ch), tr(ch));
}

void MainWindow::on_layerUp_clicked() {

}

void MainWindow::paintEvent(QPaintEvent *)
{
//	QPainter painter(this);
//	for (auto it = newProcessor.Layers.rbegin(); it != newProcessor.Layers.rend(); ++it)
//	{
//		QPoint topLeft(it->getTopLeftPoint().first, it->getTopLeftPoint().second);
//		QPoint bottomRight(it->getBottomRightPoint().first, it->getBottomRightPoint().second);
//		if (bottomRight.x() == 0 && bottomRight.y() == 0)
//		{
//			bottomRight.setX(this->width());
//			bottomRight.setY(this->height());
//		}
//
//		QRect drawArea(topLeft, bottomRight);
//      if (it->checkProperty(ImageProcess::DRAW)) {
//          painter.drawImage(drawArea, ImageConverter::MatToQImage(it->getMat()));
//      }
//	}
}

void MainWindow::on_deleteLayer_clicked()
{
    int index = ui->toolBox->currentIndex();
    QString dt = ui->toolBox->itemText(index);
    if (index != -1)
    {
        deleteLayer(dt.toInt());
        ui->toolBox->removeItem(index);
    }
}
