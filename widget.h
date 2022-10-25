#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_ButtonClear_clicked();

    void on_ButtonAdd_clicked();

    void on_ButtonSub_clicked();

    void on_ButtonDel_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_ButtonMul_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_ButtonDiv_clicked();

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_ButtonL_clicked();

    void on_Button0_clicked();

    void on_ButtonR_clicked();

    void on_ButtonEquel_clicked();

    void on_pushButton1_clicked();

    void on_ButtonPoint_clicked();

    void on_ButtonSin_clicked();

    void on_ButtonCos_clicked();

    void on_ButtonDao_clicked();

    void on_ButtonPower_clicked();

private:
    Ui::Widget *ui;
    QString expression;
    QString expression2;
};
#endif // WIDGET_H
