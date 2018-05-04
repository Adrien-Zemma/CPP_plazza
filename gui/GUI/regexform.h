#ifndef REGEXFORM_H
#define REGEXFORM_H

#include <QWidget>

namespace Ui {
class RegexForm;
}

class RegexForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegexForm(QWidget *parent = 0);
    ~RegexForm();

private:
    Ui::RegexForm *ui;
};

#endif // REGEXFORM_H
