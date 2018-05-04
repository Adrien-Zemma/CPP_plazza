#include "regexform.h"
#include "ui_regexform.h"

RegexForm::RegexForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegexForm)
{
    ui->setupUi(this);
}

RegexForm::~RegexForm()
{
    delete ui;
}
