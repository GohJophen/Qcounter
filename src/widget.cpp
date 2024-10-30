#include "widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent), count(0),settings("GohJophen", "Qcounter") {

    // 读取默认值
    defaultCount= settings.value("count", 0).toUInt();

    // 创建标签和按钮
    lblCount = new QLabel(this);
    btnIncrease = new QPushButton("加一", this);
    btnDecrease = new QPushButton("减一", this);
    btnReset = new QPushButton("清零", this);

    //lblCount默认值
    count=defaultCount;
    lblCount->setText(QString::number(defaultCount));

    // 设置布局
    hlayout1 = new QHBoxLayout;
    hlayout1->addStretch();
    hlayout1->addWidget(lblCount);
    hlayout1->addStretch();

    hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(btnReset);
    hlayout2->addWidget(btnDecrease);
    hlayout2->addWidget(btnIncrease);

    vlayout = new QVBoxLayout(this);
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
    setLayout(vlayout);

    // 连接信号槽
    connect(btnIncrease, &QPushButton::clicked, this, &Widget::increaseCount);
    connect(btnDecrease, &QPushButton::clicked, this, &Widget::decreaseCount);
    connect(btnReset, &QPushButton::clicked, this, &Widget::resetCount);
}

Widget::~Widget() {}

void Widget::increaseCount() {
    count++;
    lblCount->setText(QString::number(count));
}

void Widget::decreaseCount() {
    if (count > 0) {
        count--;
    }
    lblCount->setText(QString::number(count));
}

void Widget::resetCount() {
    count = 0;
    lblCount->setText(QString::number(count));
}

void Widget::showEvent(QShowEvent* event) {
    //调用基类 QWidget 的 showEvent 方法;重写事件处理函数（如 showEvent）时，通常需要在自定义实现的开头或结尾调用基类的实现，以确保基类的默认行为能够正常执行
    QWidget::showEvent(event);

    // 获取屏幕的尺寸
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    // 获取窗口的尺寸
    int windowWidth = this->width();
    int windowHeight = this->height();

    // 计算窗口应该显示的位置
    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;

    // 设置窗口的初始位置
    this->move(x, y);

    //this->activateWindow();
}

void Widget::closeEvent(QCloseEvent *event)
{
    // 保存当前的间隔值defaulCount
    settings.setValue("Count", QString::number(count));

    // 调用基类的 closeEvent 以确保正常关闭
    QWidget::closeEvent(event);
}
