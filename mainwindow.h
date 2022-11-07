#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow
    {
    Q_OBJECT

        public:
        MainWindow(QWidget* parent = 0);
        ~MainWindow();

        public slots:
        void updateInterface(int,int,int);

        private slots:
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();

        void on_horizontalSlider_sliderMoved(int position);

        void on_horizontalSlider_2_sliderMoved(int position);

        void on_horizontalSlider_3_sliderMoved(int position);

        void on_horizontalSlider_4_sliderMoved(int position);

        void on_horizontalSlider_5_sliderMoved(int position);

        private:
        Ui::MainWindow* ui;

        //Cria os objetos Trem's
        Trem* trem1;
        Trem* trem2;
        Trem* trem3;
        Trem* trem4;
        Trem* trem5;
    };
#endif // MAINWINDOW_H
