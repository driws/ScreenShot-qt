#ifndef UI_MANDALORIAN_H
#define UI_MANDALORIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>

QT_BEGIN_NAMESPACE

class Ui_MandalorianClass
{
public:
	QMenuBar *menuBar;
	QToolBar *mainToolBar;
	QWidget *centralWidget;
	QStatusBar *statusBar;

	QLabel * m_ImageLabel;
	QPushButton * m_pbtnScreenShot;
	QPushButton * m_pbtnChangeFolder;
	QPushButton * m_pbtnDelImage;
	QHBoxLayout * m_hbLayout;
	QVBoxLayout * m_vbLayout;
	QGridLayout * m_gridLayout;
	QLabel * m_labelImageInfo;
	QLabel * m_labelX1;
	QLabel * m_labelY1;
	QLabel * m_labelX2;
	QLabel * m_labelY2;
	QLabel * m_labelMouseInfo;
	QLabel * m_labelMouseX;
	QLabel * m_labelMouseY;
	QLineEdit * m_linePathName;
	QLineEdit * m_lineX1;
	QLineEdit * m_lineY1;
	QLineEdit * m_lineX2;
	QLineEdit * m_lineY2;
	QLineEdit * m_lineMouseX;
	QLineEdit * m_lineMouseY;
	QWidget * m_ctrWidget;

	QLabel * m_labelSuffix;
	QComboBox * m_comboBoxSuffix;
	QLineEdit * m_lineFilename;
	QLabel * m_labelFilename;
	void setupUi(QMainWindow * MandalorianClass)
	{
		if (MandalorianClass->objectName().isEmpty())
			MandalorianClass->setObjectName(QStringLiteral("MandalorianClass"));
		MandalorianClass->resize(600, 400);
		menuBar = new QMenuBar(MandalorianClass);
		menuBar->setObjectName(QStringLiteral("menuBar"));
		MandalorianClass->setMenuBar(menuBar);
		mainToolBar = new QToolBar(MandalorianClass);
		mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
		MandalorianClass->addToolBar(mainToolBar);
		centralWidget = new QWidget(MandalorianClass);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		MandalorianClass->setCentralWidget(centralWidget);
		statusBar = new QStatusBar(MandalorianClass);
		statusBar->setObjectName(QStringLiteral("statusBar"));
		MandalorianClass->setStatusBar(statusBar);

		m_ImageLabel = new QLabel(MandalorianClass);
		m_pbtnScreenShot = new QPushButton("截图", MandalorianClass);
		m_pbtnScreenShot->setObjectName(QStringLiteral("m_pbtnScreenShot"));
		m_pbtnChangeFolder = new QPushButton("更改目录", MandalorianClass);
		m_pbtnChangeFolder->setObjectName(QStringLiteral("m_pbtnChangeFolder"));

		m_linePathName = new QLineEdit(MandalorianClass);
		m_hbLayout = new QHBoxLayout();
		m_hbLayout->addWidget(m_linePathName);
		m_hbLayout->addWidget(m_pbtnChangeFolder);

		m_labelImageInfo = new QLabel("图像位置", MandalorianClass);
		m_labelX1 = new QLabel("X1", MandalorianClass);
		m_labelY1 = new QLabel("Y1", MandalorianClass);
		m_labelX2 = new QLabel("X2", MandalorianClass);
		m_labelY2 = new QLabel("Y2", MandalorianClass);
		m_labelX1->setAlignment(Qt::AlignCenter);
		m_labelY1->setAlignment(Qt::AlignCenter);
		m_labelX2->setAlignment(Qt::AlignCenter);
		m_labelY2->setAlignment(Qt::AlignCenter);
		m_lineX1 = new QLineEdit("380",MandalorianClass);
		m_lineY1 = new QLineEdit("145",MandalorianClass);
		m_lineX2 = new QLineEdit("1105",MandalorianClass);
		m_lineY2 = new QLineEdit("823",MandalorianClass);
	
		m_labelMouseInfo = new QLabel("鼠标位置", MandalorianClass);
		m_labelMouseX = new QLabel("mx", MandalorianClass);
		m_labelMouseY = new QLabel("my", MandalorianClass);
		m_labelMouseX->setAlignment(Qt::AlignCenter);
		m_labelMouseY->setAlignment(Qt::AlignCenter);
		m_lineMouseX = new QLineEdit(MandalorianClass);
		m_lineMouseY = new QLineEdit(MandalorianClass);
		m_pbtnDelImage = new QPushButton("删除图片文件");
		m_pbtnDelImage->setObjectName(QStringLiteral("m_pbtnDelImage"));

		m_labelSuffix = new QLabel("图片类型",MandalorianClass);
		m_labelSuffix->setAlignment(Qt::AlignCenter);
		m_comboBoxSuffix = new QComboBox(MandalorianClass);
		m_comboBoxSuffix->addItem("png");
		m_comboBoxSuffix->addItem("jpg");
		m_comboBoxSuffix->addItem("bmp");
		m_labelFilename = new QLabel("保存图片名",MandalorianClass);
		m_labelFilename->setAlignment(Qt::AlignCenter);

		m_lineFilename = new QLineEdit(MandalorianClass);
		m_gridLayout = new QGridLayout(MandalorianClass);
		m_gridLayout->addWidget(m_labelImageInfo,0,0);
		int startIdx = 1;
		m_gridLayout->addWidget(m_labelX1, startIdx + 0, 0);
		m_gridLayout->addWidget(m_lineX1, startIdx + 0, 1);
		m_gridLayout->addWidget(m_labelY1, startIdx + 1, 0);
		m_gridLayout->addWidget(m_lineY1, startIdx + 1, 1);
		m_gridLayout->addWidget(m_labelX2, startIdx + 2, 0);
		m_gridLayout->addWidget(m_lineX2, startIdx + 2, 1);
		m_gridLayout->addWidget(m_labelY2, startIdx + 3, 0);
		m_gridLayout->addWidget(m_lineY2, startIdx + 3, 1);
		startIdx = 5;
		m_gridLayout->addWidget(m_labelMouseInfo, startIdx, 0);
		m_gridLayout->addWidget(m_labelMouseX, startIdx + 1, 0);
		m_gridLayout->addWidget(m_lineMouseX, startIdx + 1, 1);
		m_gridLayout->addWidget(m_labelMouseY, startIdx + 2, 0);
		m_gridLayout->addWidget(m_lineMouseY, startIdx + 2, 1);
		startIdx = 8;
		m_gridLayout->addWidget(m_labelSuffix, startIdx, 0);
		m_gridLayout->addWidget(m_comboBoxSuffix, startIdx, 1);
		m_gridLayout->addWidget(m_labelFilename, startIdx + 1, 0);
		m_gridLayout->addWidget(m_lineFilename, startIdx + 1, 1);
		m_gridLayout->addWidget(m_pbtnScreenShot, startIdx + 2, 0);
		m_gridLayout->addWidget(m_pbtnDelImage, startIdx + 2, 1);
		m_gridLayout->addWidget(m_ImageLabel, 0, 2, 11, 11);
		m_gridLayout->setColumnStretch(0, 1);
		m_gridLayout->setColumnStretch(1, 2);
		m_gridLayout->setColumnStretch(2, 10);

		m_vbLayout = new QVBoxLayout(MandalorianClass);
		m_vbLayout->addLayout(m_gridLayout);
		m_vbLayout->addLayout(m_hbLayout);

		m_ctrWidget = new QWidget(MandalorianClass);
		m_ctrWidget->setLayout(m_vbLayout);
		MandalorianClass->setCentralWidget(m_ctrWidget);

		retranslateUi(MandalorianClass);

		QMetaObject::connectSlotsByName(MandalorianClass);
	} 

	void retranslateUi(QMainWindow *MandalorianClass)
	{
		MandalorianClass->setWindowTitle(QApplication::translate("MandalorianClass", "Mandalorian", Q_NULLPTR));
	}

};

namespace Ui {
	class MandalorianClass : public Ui_MandalorianClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANDALORIAN_H
