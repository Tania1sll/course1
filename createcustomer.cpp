#include "createcustomer.h"
#include "ui_createcustomer.h"
#include "customer.h"
#include <QMessageBox>
CreateCustomer::CreateCustomer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateCustomer)
{
    ui->setupUi(this);
    ui->CBwater->hide();
    ui->CBcave->hide();
    sqlDBM= SQLiteDBManager::getInstance();
    connect(ui->PBnext, &QPushButton::clicked, this, &CreateCustomer::newCustomer);
    connect(ui->CBroute, SIGNAL(currentIndexChanged(int)), this, SLOT(routeChanged(int)));
}
void CreateCustomer::newCustomer()
{
    Customer customer;
    customer.setFirstName(ui->LEfirstName->text().toStdString());
    customer.setLastName(ui->LElastName->text().toStdString());
    customer.setMiddleName(ui->LEmiddleName->text().toStdString());
    customer.setAge(ui->LEage->text().toInt());
    customer.setPhoneNumber(ui->LEnumber->text().toStdString());
    customer.setEmail(ui->LEemail->text().toStdString());
    if(ui->CBroute->currentIndex()==1){
        customer.setRoute("Печера");
    }
    else
        if(ui->CBroute->currentIndex()==2){
            customer.setRoute("Вода");
        }
    if(ui->CBcave->currentIndex()==0){
        customer.setRouteDetails("Екскурсійно-одноманітний_вихід");}
    else
        if(ui->CBcave->currentIndex()==1){
            customer.setRouteDetails("Східне_кільце");}
    else
        if(ui->CBcave->currentIndex()==2){
            customer.setRouteDetails("Західні_лабіринти");}
    else
        if(ui->CBcave->currentIndex()==3){
            customer.setRouteDetails("Сюрприз_під_землею");}
    else
        if(ui->CBcave->currentIndex()==4){
            customer.setRouteDetails("Казка");}
    else
        if(ui->CBcave->currentIndex()==5){
            customer.setRouteDetails("Квест_для_початківців");}

    if(ui->CBwater->currentIndex()==0){
        customer.setRouteDetails("Сплав_порогами_Чорного_Черемоша");}
    else
        if(ui->CBwater->currentIndex()==1){
            customer.setRouteDetails("Рафтинг_на_Білому_Черемоші");}
        else
            if(ui->CBwater->currentIndex()==2){
                customer.setRouteDetails("Пороги_Прута");}
            else
                if(ui->CBwater->currentIndex()==3){
                    customer.setRouteDetails("Інстаграмний_Дністер");}
                else
                    if(ui->CBwater->currentIndex()==4){
                        customer.setRouteDetails("Літній_релакс_на_берегах_Дністра");}
                    else
                        if(ui->CBwater->currentIndex()==5){
                            customer.setRouteDetails("Весняні_пороги_Свічі_і_Мізурки");}

    if(ui->CBinstructor->currentIndex()==1)
    {
        customer.setInstructor("Гора");
    }
    else

    if(ui->CBinstructor->currentIndex()==2){
        customer.setInstructor("Зирянова");
    }        else

    if(ui->CBinstructor->currentIndex()==3){
        customer.setInstructor("Слугоцька");
    }
    else

    if(ui->CBinstructor->currentIndex()==4){
        customer.setInstructor("Зотов");
    }
    else

    if(ui->CBinstructor->currentIndex()==5){
        customer.setInstructor("Білошицький");
    }
    else

    if(ui->CBinstructor->currentIndex()==6){
        customer.setInstructor("Яцків");
    }
    else

    if(ui->CBinstructor->currentIndex()==7){
        customer.setInstructor("Перевізник");
    }
    else

    if(ui->CBinstructor->currentIndex()==8){
        customer.setInstructor("Гаврів");
    }
    else

    if(ui->CBinstructor->currentIndex()==9){
        customer.setInstructor("Зробок");
    }         else

    if(ui->CBinstructor->currentIndex()==10){
        customer.setInstructor("Пивовар");
    } else

    if(ui->CBinstructor->currentIndex()==11){
        customer.setInstructor("Іванів");
    }

    bool add = sqlDBM ->insertIntoTableCustomer(customer);

    if (add) {
        QString reportMessage = "The order was successfull accepted. Wait for the call!\n\n";
        reportMessage += "Surname: " + QString::fromUtf8(customer.getLastName().c_str()) + "\n";
        reportMessage += "Name: " + QString::fromUtf8(customer.getFirstName().c_str()) + "\n";
        reportMessage += "Middle name: " + QString::fromUtf8(customer.getMiddleName().c_str()) + "\n";
        reportMessage += "Age: " + QString::number(customer.getAge()) + "\n";
        reportMessage += "Number: " + QString::fromUtf8(customer.getPhoneNumber().c_str()) + "\n";
        reportMessage += "Email: " + QString::fromUtf8(customer.getEmail().c_str()) + "\n";
        reportMessage += "Type route: " + ui->CBroute->currentText() + "\n";
        if(ui->CBroute->currentIndex()==1){
           reportMessage += "Name route: " + ui->CBcave->currentText() + "\n";
        }
        else
            if(ui->CBroute->currentIndex()==2){
            reportMessage += "Name route: " + ui->CBwater->currentText() + "\n";
            }
        reportMessage += "Instructor: " + ui->CBinstructor->currentText() + "\n";
        double instructorPrice = sqlDBM->getInstructorPrice(ui->CBinstructor->currentText());
        double routePrice;
        if (ui->CBroute->currentIndex()==1) {
            routePrice = sqlDBM->getRoutePrice(ui->CBcave->currentText());
        } else if (ui->CBroute->currentIndex()==2) {
            routePrice = sqlDBM->getRoutePrice(ui->CBwater->currentText());
        }
        qDebug() << "Instructor Price: " << instructorPrice;
        qDebug() << "Route Price: " << routePrice;

        if (instructorPrice == 0.0) {
            QMessageBox::warning(this, "Warning", "Failed to retrieve instructor price.");
            return;
        }

        if (routePrice == 0.0) {
            QMessageBox::warning(this, "Warning", "Failed to retrieve route price.");
            return;
        }

        double totalPrice = instructorPrice + routePrice;
        qDebug() << "Total Price: " << totalPrice;
            reportMessage += "Total Price: " + QString::number(totalPrice) + "\n";
        QMessageBox::information(this, "Order confirmation", reportMessage);

        ui->LEfirstName->clear();
        ui->LElastName->clear();
        ui->LEmiddleName->clear();
        ui->LEage->clear();
        ui->LEnumber->clear();
        ui->LEemail->clear();
        ui->LBprice->clear();

    } else {
        QMessageBox::critical(this, "Error", "Error when placing an order. Pleace try afain!.");
    }
 }
void CreateCustomer::routeChanged(int index)
{
    if (index == 1) {
        ui->CBcave->show();
        ui->CBwater->hide();
    }
    if (index == 2) {
        ui->CBwater->show();
        ui->CBcave->hide();
    }
}
CreateCustomer::~CreateCustomer()
{
    delete ui;
}

void CreateCustomer::on_PBback_clicked()
{
    emit this->goBackCustomer();
}

