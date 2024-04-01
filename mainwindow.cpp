#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLineEdit* inputNodeEdit = new QLineEdit(this);
    QPushButton* addNodeBtn= new QPushButton("Добавить",this);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addStretch();
    layout->addWidget(inputNodeEdit);
    layout->addWidget(addNodeBtn);

    QWidget* addNodeWidget = new QWidget(this);
    addNodeWidget->setLayout(layout);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(addNodeWidget);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
