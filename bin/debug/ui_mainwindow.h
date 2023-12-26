/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QCheckBox *checkBox;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *backward;
    QPushButton *forward;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QDoubleSpinBox *bg;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *diffuse;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *reflect;
    QPushButton *pushButton_2;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QDoubleSpinBox *x_light;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QDoubleSpinBox *y_light;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QDoubleSpinBox *z_light;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QDoubleSpinBox *light_intens;
    QPushButton *pushButton_4;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton;
    QPushButton *stop;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 810);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Serif"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("/*\n"
"font: 12pt \"DejaVu Serif\";\n"
"ElegantDark Style Sheet for QT Applications\n"
"Author: Jaime A. Quiroga P.\n"
"Company: GTRONICK\n"
"Last updated: 17/04/2018\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/ElegantDark.qss\n"
"*/\n"
"QMainWindow {\n"
"	background-color:rgb(82, 82, 82);\n"
"}\n"
"QTextEdit {\n"
"	background-color:rgb(42, 42, 42);\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"QPushButton{\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"	border-style: outset;\n"
"	colo"
                        "r: rgb(255, 255, 255);\n"
"	padding: 6px;\n"
"	border-radius: 10px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(77, 77, 77, 255), stop:1 rgba(97, 97, 97, 255));\n"
"}\n"
"QPushButton:hover{\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(110, 110, 110, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(110, 110, 110, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(110, 110, 110, 255));\n"
"	border-bottom-color: rgb(115, 115, 115);\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(107, 107, 107, 255), stop:1 rgba(157, 1"
                        "57, 157, 255));\n"
"}\n"
"QPushButton:pressed{\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(62, 62, 62, 255), stop:1 rgba(22, 22, 22, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(77, 77, 77, 255), stop:1 rgba(97, 97, 97, 255));\n"
"}\n"
"QPushButton:disabled{\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 25"
                        "5), stop:1 rgba(62, 62, 62, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: rgb(0, 0, 0);\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(57, 57, 57, 255), stop:1 rgba(77, 77, 77, 255));\n"
"}\n"
"QLineEdit {\n"
"	border-width: 1px; border-radius: 4px;\n"
"	border-color: rgb(58, 58, 58);\n"
"	border-style: inset;\n"
"	padding: 0 8px;\n"
"	color: rgb(255, 255, 255);\n"
"	background:rgb(100, 100, 100);\n"
"	selection-background-color: rgb(187, 187, 187);\n"
"	selection-color: rgb(60, 63, 65);\n"
"}\n"
"QLabel {\n"
"	color:rgb(255,255,255);	\n"
"}\n"
"QProgressBar {\n"
"	text-align: center;\n"
""
                        "	color: rgb(240, 240, 240);\n"
"	border-width: 1px; \n"
"	border-radius: 10px;\n"
"	border-color: rgb(58, 58, 58);\n"
"	border-style: inset;\n"
"	background-color:rgb(77,77,77);\n"
"}\n"
"QProgressBar::chunk {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0.7, x2:0.5, y2:0.3, stop:0 rgba(87, 97, 106, 255), stop:1 rgba(93, 103, 113, 255));\n"
"	border-radius: 5px;\n"
"}\n"
"QMenuBar {\n"
"	background:rgb(82, 82, 82);\n"
"}\n"
"QMenuBar::item {\n"
"	color:rgb(223,219,210);\n"
"	spacing: 3px;\n"
"	padding: 1px 4px;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"	background:rgb(115, 115, 115);\n"
"}\n"
"QMenu::item:selected {\n"
"	color:rgb(255,255,255);\n"
"	border-width:2px;\n"
"	border-style:solid;\n"
"	padding-left:18px;\n"
"	padding-right:8px;\n"
"	padding-top:2px;\n"
"	padding-bottom:3px;\n"
"	background:qlineargradient(spread:pad, x1:0.5, y1:0.7, x2:0.5, y2:0.3, stop:0 rgba(87, 97, 106, 255), stop:1 rgba(93, 103, 113, 255));\n"
"	border-top-color: qlineargradient("
                        "spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"}\n"
"QMenu::item {\n"
"	color:rgb(223,219,210);\n"
"	background-color:rgb(78,78,78);\n"
"	padding-left:20px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:10px;\n"
"}\n"
"QMenu{\n"
"	background-color:rgb(78,78,78);\n"
"}\n"
"QTabWidget {\n"
"	color:rgb(0,0,0);\n"
"	background-color:rgb(247,246,246);\n"
"}\n"
"QTabWidget::pane {\n"
"		border-color: rgb(77,77,77);\n"
"		background-color:rgb(101,101,101);\n"
"		border-style: solid;\n"
"		border-width: 1px;\n"
"    	border-radius: 6px;\n"
"}\n"
"QTabBar::tab {\n"
"	padd"
                        "ing:2px;\n"
"	color:rgb(250,250,250);\n"
"  	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(77, 77, 77, 255), stop:1 rgba(97, 97, 97, 255));\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"  	border-top-right-radius:4px;\n"
"   border-top-left-radius:4px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(95, 92, 93, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(95, 92, 93, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(95, 92, 93, 255));\n"
"	border-bottom-color: rgb(101,101,101);\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:last:selected, QTabBar::tab:hover {\n"
"  	background-color:rgb(101,101,101);\n"
"  	margin-left: 0px;\n"
"  	margin-right: 1px;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"    	margin-top: 1px;\n"
""
                        "		margin-right: 1px;\n"
"}\n"
"QCheckBox {\n"
"	color:rgb(223,219,210);\n"
"	padding: 2px;\n"
"}\n"
"QCheckBox:hover {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	padding-left: 1px;\n"
"	padding-right: 1px;\n"
"	padding-bottom: 1px;\n"
"	padding-top: 1px;\n"
"	border-width:1px;\n"
"	border-color: rgb(87, 97, 106);\n"
"	background-color:qlineargradient(spread:pad, x1:0.5, y1:0.7, x2:0.5, y2:0.3, stop:0 rgba(87, 97, 106, 150), stop:1 rgba(93, 103, 113, 150));\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	border-color: rgb(180,180,180);\n"
"  	background-color:qlineargradient(spread:pad, x1:0.5, y1:0.7, x2:0.5, y2:0.3, stop:0 rgba(87, 97, 106, 255), stop:1 rgba(93, 103, 113, 255));\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	border-color: rgb(87, 97, 106);\n"
"  	background-color:rgb(255,255,255);\n"
"}\n"
"QStatusBar {\n"
"	color:rgb(240,240,240);\n"
"}\n"
""
                        "\n"
"QDoubleSpinBox {\n"
"	color: #a9b7c6;	\n"
"	background-color: rgb(42, 42, 42);\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 1281, 791));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 105, 105);"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(1150, 20, 131, 23));
        checkBox->setFont(font);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(1290, 140, 231, 111));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        backward = new QPushButton(widget_2);
        backward->setObjectName(QString::fromUtf8("backward"));
        backward->setFont(font);

        verticalLayout->addWidget(backward);

        forward = new QPushButton(widget_2);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setFont(font);

        verticalLayout->addWidget(forward);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1290, 250, 241, 241));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        bg = new QDoubleSpinBox(widget_5);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setFont(font);
        bg->setDecimals(3);
        bg->setMinimum(0.001000000000000);
        bg->setMaximum(0.999000000000000);
        bg->setSingleStep(0.001000000000000);

        horizontalLayout_3->addWidget(bg);


        verticalLayout_2->addWidget(widget_5);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        diffuse = new QDoubleSpinBox(widget_3);
        diffuse->setObjectName(QString::fromUtf8("diffuse"));
        diffuse->setFont(font);
        diffuse->setDecimals(3);
        diffuse->setMinimum(0.001000000000000);
        diffuse->setMaximum(0.999000000000000);
        diffuse->setSingleStep(0.001000000000000);

        horizontalLayout->addWidget(diffuse);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        reflect = new QDoubleSpinBox(widget_4);
        reflect->setObjectName(QString::fromUtf8("reflect"));
        reflect->setFont(font);
        reflect->setDecimals(3);
        reflect->setMinimum(0.001000000000000);
        reflect->setMaximum(0.999000000000000);
        reflect->setSingleStep(0.001000000000000);

        horizontalLayout_2->addWidget(reflect);


        verticalLayout_2->addWidget(widget_4);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        verticalLayout_2->addWidget(pushButton_2);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(1290, 490, 231, 316));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_3->addWidget(label_6);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_4 = new QVBoxLayout(widget_7);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_11 = new QWidget(widget_7);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_12 = new QHBoxLayout(widget_11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_13 = new QLabel(widget_11);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        horizontalLayout_12->addWidget(label_13);

        x_light = new QDoubleSpinBox(widget_11);
        x_light->setObjectName(QString::fromUtf8("x_light"));
        x_light->setMinimum(-99999.000000000000000);
        x_light->setMaximum(99999.000000000000000);
        x_light->setValue(0.000000000000000);

        horizontalLayout_12->addWidget(x_light);


        verticalLayout_4->addWidget(widget_11);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_10 = new QHBoxLayout(widget_9);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(widget_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        horizontalLayout_10->addWidget(label_11);

        y_light = new QDoubleSpinBox(widget_9);
        y_light->setObjectName(QString::fromUtf8("y_light"));
        y_light->setMinimum(-99999.000000000000000);
        y_light->setMaximum(99999.000000000000000);

        horizontalLayout_10->addWidget(y_light);


        verticalLayout_4->addWidget(widget_9);

        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_9 = new QHBoxLayout(widget_8);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(widget_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_9->addWidget(label_8);

        z_light = new QDoubleSpinBox(widget_8);
        z_light->setObjectName(QString::fromUtf8("z_light"));
        z_light->setMinimum(-99999.000000000000000);
        z_light->setMaximum(99999.000000000000000);

        horizontalLayout_9->addWidget(z_light);


        verticalLayout_4->addWidget(widget_8);


        verticalLayout_3->addWidget(widget_7);

        widget_10 = new QWidget(widget_6);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        verticalLayout_5 = new QVBoxLayout(widget_10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_12 = new QLabel(widget_10);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        verticalLayout_5->addWidget(label_12);

        light_intens = new QDoubleSpinBox(widget_10);
        light_intens->setObjectName(QString::fromUtf8("light_intens"));
        light_intens->setMinimum(-99999.000000000000000);
        light_intens->setMaximum(999999.000000000000000);

        verticalLayout_5->addWidget(light_intens);


        verticalLayout_3->addWidget(widget_10);

        pushButton_4 = new QPushButton(widget_6);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);

        verticalLayout_3->addWidget(pushButton_4);

        widget_12 = new QWidget(centralwidget);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setGeometry(QRect(1290, 10, 241, 132));
        verticalLayout_6 = new QVBoxLayout(widget_12);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        pushButton = new QPushButton(widget_12);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout_6->addWidget(pushButton);

        stop = new QPushButton(widget_12);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setFont(font);

        verticalLayout_6->addWidget(stop);

        pushButton_3 = new QPushButton(widget_12);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        verticalLayout_6->addWidget(pushButton_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        backward->setText(QCoreApplication::translate("MainWindow", "\320\276\321\202\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        forward->setText(QCoreApplication::translate("MainWindow", "\320\277\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\320\275\320\276\320\262\320\276\320\265      ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\321\203\320\267\320\275\320\276\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\227\320\265\321\200\320\272\320\260\320\273\321\214\320\275\320\276\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\260\320\275\320\270\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        stop->setText(QCoreApplication::translate("MainWindow", "\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\321\201\320\261\321\200\320\276\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
