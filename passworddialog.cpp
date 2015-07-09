#include "passworddialog.h"
#include "ui_passworddialog.h"

PasswordDialog::PasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}

void PasswordDialog::on_checkBoxShow_stateChanged(int arg1)
{
    if (arg1) {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}

void PasswordDialog::on_createPasswordButton_clicked()
{
    // TODO
    ui->lineEditPassword->setText("generated");
}

void PasswordDialog::setPassword(QString password)
{
    QStringList tokens =  password.split("\n");
    ui->lineEditPassword->setText(tokens[0]);
    tokens.pop_front();
    ui->plainTextEdit->insertPlainText(tokens.join("\n"));
}

QString PasswordDialog::getPassword()
{
    return ui->lineEditPassword->text() + "\n" + ui->plainTextEdit->toPlainText();
}
