#ifndef CMESSAGEBOX_H
#define CMESSAGEBOX_H

#include <QDialog>
class WalletModel;
namespace Ui {
class CMessageBox;
}

class CMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit CMessageBox(QWidget *parent = 0);
    ~CMessageBox();
    void setMessage(QString msg);
    void setCacelVisible(bool isVisible);
    void setMessage(int msg);
    bool getIsClose(){return m_isShutDown;}
    void setIsClose(bool isShutDown){m_isShutDown = isShutDown;}
    int m_answertype;
    void setWalletModel(WalletModel *model_);
private Q_SLOTS:
    void on_pushButton_ok_pressed();

    void on_pushButton__cancle_pressed();
    void updateTimer();

private:
    Ui::CMessageBox *ui;
    bool m_isShutDown;
    QTimer *pollTimer;
    int m_msg;

    WalletModel *model;
};

#endif // CMESSAGEBOX_H
