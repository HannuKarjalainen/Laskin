#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void numberClickHandler();
    void commandClickHandler();
    void calcClickHandler();
    void clear();
private:
    Ui::MainWindow *ui;
    QString number1, number2;
    float result;
    short operand = -1;
    bool isInputLocked = false;
};
#endif // MAINWINDOW_H
