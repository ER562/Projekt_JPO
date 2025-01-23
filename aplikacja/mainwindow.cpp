#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zapisz_pressed()
{
    person x;
    x.name = ui->name->text().toStdString();
    x.surname = ui->surname->text().toStdString();
    x.street = ui->street->text().toStdString();
    x.city = ui->city->text().toStdString();
    x.country = ui->country->text().toStdString();
    x.email = ui->email->text().toStdString();
    x.year_of_birth = ui->date->date().year();
    x.month_of_birth = ui->date->date().month();
    x.day_of_birth = ui->date->date().day();
    x.street_number = ui->street_number->text().toInt();
    x.phone_number = ui->phone_number->text().toInt();

    string error = "";

    if (x.phone_number < 111111111 || x.phone_number>999999999) {
        error += "Wpisz poprawny numer telefony!\n";
    }

    if (x.name == "" || x.surname == "" || x.street == "" || x.city == "" || x.country == "" || x.email == "") {
        error += "Wypełnij wszystkie pozycje!\n";
    }

    if(error=="") {
        base.put_record(x);
        ui->spinBox->setRange(0,base.size());
        ui->rekordy->setText(QString::fromStdString("Ilość rekordów: " + std::to_string(base.size())));
        QMessageBox::warning(this,"informacja","Wpisano poprawnie do bazy!");
    }
    else {
        QString g = QString::fromStdString(error);
        QMessageBox::warning(this,"błąd",g);
    }
}


void MainWindow::on_wyczysc_pressed()
{
    ui->name->setText("");
    ui->surname->setText("");
    ui->street->setText("");
    ui->city->setText("");
    ui->country->setText("");
    ui->email->setText("");
    ui->street_number->setText("");
    ui->phone_number->setText("");
}


void MainWindow::on_wyszukaj_pressed()
{
    vector <bool> z(11, 0);
    z[0] = ui->namebox->isChecked();
    z[1] = ui->surnamebox->isChecked();
    z[2] = ui->dzienbox->isChecked();
    z[3] = ui->miesiacbox->isChecked();
    z[4] = ui->rokbox->isChecked();
    z[5] = ui->streetbox->isChecked();
    z[6] = ui->street_numberbox->isChecked();
    z[7] = ui->citybox->isChecked();
    z[8] = ui->countrybox->isChecked();
    z[9] = ui->phone_numberbox->isChecked();
    z[10] = ui->emailbox->isChecked();



    //almost the same code as in adding record
    person x;
    x.name = ui->name->text().toStdString();
    x.surname = ui->surname->text().toStdString();
    x.street = ui->street->text().toStdString();
    x.city = ui->city->text().toStdString();
    x.country = ui->country->text().toStdString();
    x.email = ui->email->text().toStdString();
    x.year_of_birth = ui->date->date().year();
    x.month_of_birth = ui->date->date().month();
    x.day_of_birth = ui->date->date().day();
    x.street_number = ui->street_number->text().toInt();
    x.phone_number = ui->phone_number->text().toInt();

    string error = "";

    if ((x.phone_number < 111111111 || x.phone_number>999999999)&&ui->phone_numberbox->isChecked()) {
        error += "Wpisz poprawny numer telefony!\n";
    }

    if ((x.name == ""&& ui->namebox->isChecked()) ||  (x.surname == ""&& ui->surnamebox->isChecked()) || (x.street == ""&&ui->streetbox->isChecked()) || (x.city == ""&&ui->citybox->isChecked())
        || (x.country == ""&&ui->countrybox->isChecked()) || (x.email == "" && ui->emailbox->isChecked())) {
        error += "Wypełnij wszystkie pozycje!\n";
    }

    int h {0};
    for (int i=0;i<z.size();i++){
        if(z[i]){
            h=1;
        }
    }

    if (error == ""&& h == 1){
        vector <int> resoult = base.find_record(x, z[0], z[1], z[2], z[3], z[4], z[5], z[6], z[7], z[8], z[9], z[10]);
        string text{""};
        for (int i : resoult) {
            if (text != "") {
                text += ", ";
            }
            text += std::to_string(i+1);
        }
        QMessageBox::warning(this,"informacja",QString::fromStdString("znaleziono następujące rekordy:\n"+text));
        ui->textBrowser->setText(QString::fromStdString(text));
    }
    else if(h==0){
        QMessageBox::warning(this,"błąd","Nie wybrano żadnego kryterium");
    }else{
        QString g = QString::fromStdString(error);
        QMessageBox::warning(this,"błąd",g);
    }
}


void MainWindow::on_Ok_pressed()
{
    person j1{ "Eryk", "Wicher",21,2,2005,"bławadkowska",52,"Bibice","Polska",111222333,"eryk@gmail.com"};
    base.put_record(j1);
    person j2{ "Mateusz", "Kowalczyk",12,5,2001,"stefana okrzei",4,"Słomniki","Polska",222333444,"mateusz@wp.pl" };
    base.put_record(j2);
    person j3{ "Iwona", "Wiśniewska",28,7,1996,"łąkowa",25,"Modlniczka","Polska",333444555,"iwona@interia.pl" };
    base.put_record(j3);
    person j4{ "Ula", "Nowak",30,9,1986,"balicka",87,"Mydlniki","Polska",444555666,"ula@hotmail.com" };
    base.put_record(j4);
    person j5{ "Kacper", "Kowalski",1,1,2001,"prosta",13,"Kryspinów","Polska",555666777,"kacper@student.agh.edu.pl" };
    base.put_record(j5);
    ui->spinBox->setRange(0,base.size());
    ui->rekordy->setText(QString::fromStdString("Ilość rekordów: " + std::to_string(base.size())));
    QMessageBox::warning(this,"Informacja","Dodano przykładowe rekordy");
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    int number{};
    number = ui->spinBox->value();
    person x;
    string text{};

    if (number == 0) {
        ui->textBrowser_2->setText("wybierz rekord do wyświetlenia");
    }
    else if (number <= base.size()) {
        base.get_record(number-1,x);
        text += "Imię: " + x.name + "\nNazwisko: " + x.surname + "\n";
        text += "Data urodzenia: " + std::to_string(x.day_of_birth) + "." + std::to_string(x.month_of_birth) + "." + to_string(x.year_of_birth) + "\n";
        text += "Miejsce zamieszkania: " + x.street + "/" + std::to_string(x.street_number) + "    " + x.city + "    " + x.country + "\n";
        text += "Dane kontaktowe:\nNumer telefonu: " + std::to_string(x.phone_number) + "    Adres e-mail: " + x.email;
        QString g = QString::fromStdString(text);
        ui->textBrowser_2->setText(g);
    }
}


void MainWindow::on_delete_2_pressed()
{
    int i = ui->spinBox->value();
    if (i<=0 || i > base.size()) {
        QMessageBox::warning(this,"błąd","Nie ma takiego rekordu!");
    }else {
        base.delete_record(i - 1);
        ui->spinBox->setValue(0);
        ui->rekordy->setText(QString::fromStdString("Ilość rekordów: " + std::to_string(base.size())));
        ui->spinBox->setRange(0,base.size());
        QMessageBox::warning(this,"informacja",QString::fromStdString("Usunięto rekord: " + std::to_string(i)));
    }
}


void MainWindow::on_pushButton_pressed()
{
    QString plik = QFileDialog::getOpenFileName(this,tr("Otwórz"), "/home", tr("*.txt"));
    if(plik==nullptr){
        QMessageBox::warning(this,"błąd","nie udało się odczytać pliku");
    }else{
        string y{};
        std::ifstream p(plik.toStdString());
        std::getline(p,y);
        try {
            person h = base.load_record(y);
            base.put_record(h);
            ui->spinBox->setRange(0,base.size());
            QMessageBox::warning(this,"informacja","odczytano plik");
        }
        catch (...) {
            QMessageBox::warning(this,"błąd","Nie udało sie odczytać danych z pliku!");
        };
    }
}


void MainWindow::on_pushButton_2_pressed()
{
    if(ui->spinBox->value()>=0||ui->spinBox->value()<=base.size()){
    QString plik = QFileDialog::getSaveFileName(this, tr("Save File"), "/home", tr("(*.txt)"));
        if(plik==nullptr){
            QMessageBox::warning(this,"błąd","nie udało się zapisać pliku");
        }else{
            string y{};
            std::ofstream p(plik.toStdString());
            try {
                y = base.save_record(ui->spinBox->value());
                p << y;
                 QMessageBox::warning(this,"informacja","zapisano dane do pliku");
            }
            catch (...) {
                QMessageBox::warning(this,"błąd","Nie udało sie zapisać danych do pliku!");
            };
        }
    }
}

