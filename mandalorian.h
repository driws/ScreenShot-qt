#ifndef MANDALORIAN_H
#define MANDALORIAN_H
#pragma execution_character_set("utf-8") 
#include <QtWidgets/QMainWindow>
#include "ui_mine.h"
//#include "ui_mandalorian.h"
#include <QGuiApplication>
#include <QtGui/QScreen>
#include <QDir>
#include <QPixmap>
#include <QClipboard>
#include <QDebug>
#include <QFileDialog>
#include <QTimer>
#include <QMessageBox>
class Mandalorian : public QMainWindow
{
	Q_OBJECT

public:
	Mandalorian(QWidget *parent = 0);
	~Mandalorian();
	void InitParam();
	int getFileCount();
private:
	Ui::MandalorianClass ui;
	QString m_sInputPath;
	QPixmap m_pixImage;
	QVector<QLineEdit * > m_vlineRect;
	QScreen * screen;
	QTimer * m_showTimer;
	private slots:
	void onShowTimerOut();
	void on_m_pbtnScreenShot_clicked();
	void on_m_pbtnChangeFolder_clicked();
	void on_m_pbtnDelImage_clicked();
};

#endif // MANDALORIAN_H
