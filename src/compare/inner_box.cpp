#include "inner_box.h"

#include <QDebug>

InnerBox::InnerBox(InnerBoxInfo *inner_box_info)
    : inner_box_info_(inner_box_info) {}

InnerBox::~InnerBox() {}

bool InnerBox::compare(QString &error) {

    // 数据转换
    if (!dataConvert(error)) {
        return false;
    }

    // 判断首卡 ICCID 是否等于内盒起始 ICCID
    if (start_iccid_ != start_card_iccid_) {
        error = "内盒起始ICCID与首卡ICCID不相等";
        return false;
    }

    // 判断尾卡 ICCID 是否等于内盒结束 ICCID
    if (end_iccid_ != end_card_iccid_) {
        error = "内盒结束ICCID与尾卡ICCID不相等";
        return false;
    }

    return true;
}

void InnerBox::show() {
    qDebug() << "start_iccid: " << start_iccid_;
    qDebug() << "end_iccid: " << end_iccid_;
    qDebug() << "start_card_iccid: " << start_card_iccid_;
    qDebug() << "end_card_iccid: " << end_card_iccid_;
}

bool InnerBox::dataConvert(QString &error) {

    int inner_box_start_check_num = inner_box_info_->inner_box_start_check_num - 1;
    int inner_box_end_check_num   = inner_box_info_->inner_box_end_check_num;
    int card_start_check_num      = inner_box_info_->card_start_check_num - 1;
    int card_end_check_num        = inner_box_info_->card_end_check_num;

    // 判断 check_num 是否大于 start_iccid位数
    if (inner_box_end_check_num > inner_box_info_->start_iccid.size() || inner_box_start_check_num > inner_box_end_check_num) {
        error = "校验位数大于起始ICCID位数";
        return false;
    }

    // 数据转换
    start_iccid_ =
        inner_box_info_->start_iccid.mid(inner_box_start_check_num, inner_box_end_check_num - inner_box_start_check_num).toLongLong();
    end_iccid_ =
        inner_box_info_->end_iccid.mid(inner_box_start_check_num, inner_box_end_check_num - inner_box_start_check_num).toLongLong();
    start_card_iccid_ = inner_box_info_->start_card_iccid.mid(card_start_check_num, card_end_check_num - card_start_check_num).toLongLong();
    end_card_iccid_   = inner_box_info_->end_card_iccid.mid(card_start_check_num, card_end_check_num - card_start_check_num).toLongLong();

    return true;
}