#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSettings>
#include <QScreen>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    // 创建标签和按钮
    QLabel* lblCount;
    QPushButton* btnIncrease;
    QPushButton* btnDecrease;
    QPushButton* btnReset;

    // 设置布局
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QVBoxLayout *vlayout;

    //重写事件函数
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent* event) override;

public slots:
    void increaseCount();
    void decreaseCount();
    void resetCount();

private:
    unsigned int count;
    QSettings settings;
    unsigned int defaultCount;
};
#endif // WIDGET_H
