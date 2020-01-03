#include "mandalorian.h"

Mandalorian::Mandalorian(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	InitParam();
}



Mandalorian::~Mandalorian()
{
	if (m_sInputPath.size())
	{
		QFile fw("path.txt");
		fw.open(QIODevice::WriteOnly);
		QTextStream out(&fw);
		out << m_sInputPath << "\r\n";
		for (int k = 0;k < 3;k++)
			out << m_vlineRect[k]->text() << ",";
		out << m_vlineRect[3]->text() << endl;
		fw.close();
	}
}

void Mandalorian::InitParam()
{
	m_vlineRect.push_back(ui.m_lineX1);
	m_vlineRect.push_back(ui.m_lineY1);
	m_vlineRect.push_back(ui.m_lineX2);
	m_vlineRect.push_back(ui.m_lineY2);

	QString txtname = "path.txt";
	QDir dir;
	if (!dir.exists(txtname))
	{
		m_sInputPath = QDir::currentPath() + "/pic/";
		if(!dir.exists(m_sInputPath))
			dir.mkdir(m_sInputPath);
	}
	else
	{
		QFile fr(txtname);
		int flag = fr.open(QIODevice::ReadOnly | QIODevice::Text);
		QTextStream in(&fr);
		m_sInputPath = in.readLine();
		QStringList rectList = in.readLine().split(",");
		for (int k = 0;k < rectList.size();k++)
		{
			m_vlineRect[k]->setText(rectList[k]);
		}
		fr.close();

	}
	ui.m_linePathName->setText(m_sInputPath);
	screen = QGuiApplication::primaryScreen();
	m_showTimer = new QTimer(this);
	m_showTimer->setInterval(10);
	connect(m_showTimer, SIGNAL(timeout()), this, SLOT(onShowTimerOut()));
	m_showTimer->start();
}

int Mandalorian::getFileCount()
{
	QDir *dir = new QDir(m_sInputPath);
	QStringList filter;
	filter << "autosave*.png" << "autosave*.bmp" << "autosave*.jpg";
	dir->setNameFilters(filter);
	QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
	return fileInfo->count();
}
void Mandalorian::on_m_pbtnScreenShot_clicked()
{
	int img_x, img_y, img_w, img_h;
	QString picname,suffix, name;
	int filenum = getFileCount();
	img_x = ui.m_lineX1->text().toInt();
	img_y = ui.m_lineY1->text().toInt();
	img_w = ui.m_lineX2->text().toInt() - img_x;
	img_h = ui.m_lineY2->text().toInt() - img_y;
	suffix = ui.m_comboBoxSuffix->currentText();
	if (!ui.m_lineFilename->text().isEmpty())
		name = ui.m_lineFilename->text();
	else
		name = "autosave" + QString::number(filenum + 1);
	picname = tr("%1/%2.%3").arg(m_sInputPath).arg(name).arg(suffix);
	m_pixImage = screen->grabWindow(0, img_x, img_y, img_w, img_h);
	ui.m_ImageLabel->setPixmap(m_pixImage.scaled(ui.m_ImageLabel->width(), ui.m_ImageLabel->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	m_pixImage.save(picname,suffix.toStdString().c_str(),90);
}

void Mandalorian::on_m_pbtnChangeFolder_clicked()
{
	m_sInputPath = QFileDialog::getExistingDirectory(this, "更改路径", "./");
	ui.m_linePathName->setText(m_sInputPath);
}

void Mandalorian::on_m_pbtnDelImage_clicked()
{
	int choose = QMessageBox::question(this, tr("删除确认"),
		QString(tr("这将删除目录下的所有图片，确定继续?")),
		QMessageBox::Yes | QMessageBox::No);
	if (choose == QMessageBox::No)
		return;
	QDir* dir = new QDir(m_sInputPath);
	QStringList filter;
	filter << "*.png" << "*.jpg" << "*.bmp";
	dir->setNameFilters(filter);                    
	QList<QFileInfo>* fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));

	for (int k = 0; k < fileInfo->count(); k++)
	{
		QFileInfo file = fileInfo->at(k);
		file.dir().remove(file.fileName());
	}

}

void Mandalorian::onShowTimerOut()
{
	QPoint pos = QCursor::pos();
	ui.m_lineMouseX->setText(QString::number(pos.x()));
	ui.m_lineMouseY->setText(QString::number(pos.y()));
}