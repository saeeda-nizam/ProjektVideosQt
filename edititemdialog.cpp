#include "edititemdialog.h"
#include "ui_edititemdialog.h"

EditItemDialog::EditItemDialog(const FoodItems item, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditItemDialog)
{
    ui->setupUi(this);

    m_item = item;

    ui->nameEdit->setText(item.name());

    QString priceString;
    priceString.sprintf("%.2f", item.price());
    ui->priceEdit->setText(priceString);

    ui->dateTimeEdit->setDateTime(item.orderDateTime());

    ui->needsThermoBox->setChecked(item.needsThermoBoxTransport());
}

EditItemDialog::~EditItemDialog()
{
    delete ui;
}

FoodItems EditItemDialog::item() const
{
    return m_item;
}

void EditItemDialog::on_buttonBox_accepted()
{
    m_item.setName(ui->nameEdit->text());
    m_item.setPrice(ui->priceEdit->text().toDouble());
    m_item.setOrderDateTime(ui->dateTimeEdit->dateTime());
    m_item.setNeedsThermoBoxTransport(ui->needsThermoBox->isChecked());
}
