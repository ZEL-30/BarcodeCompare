#include "outer_box.h"

#include <QDebug>

OuterBox::OuterBox()
    : correct_start_iccid_(0)
    , correct_end_iccid_(0) {}

OuterBox::~OuterBox() {}

bool OuterBox::compare(QString &error, bool &is_end) {

    is_end = false;

    // 数据转换
    if (!dataConvert(error)) {
        return false;
    }

    // 判断目标 ICCID 是否在范围内
    if (target_iccid_ < start_iccid_ || target_iccid_ > end_iccid_) {
        error = QString("内盒不属于该外箱");
        return false;
    }

    // 判断目标 ICCID 是否正确
    if (correct_start_iccid_ != 0 && correct_end_iccid_ != 0) {
        if (target_iccid_ == correct_start_iccid_ || target_iccid_ == correct_end_iccid_) {
            if (end_iccid_ == correct_end_iccid_) {
                is_end = true;
            }
        } else {
            error = QString("内盒 ICCID 顺序不正确");
            return false;
        }
    }

    // 计算正确的起始 ICCID 和结束 ICCID
    if ((target_iccid_ - start_iccid_) % outer_box_info_->card_count == 0) {
        correct_start_iccid_ = target_iccid_ + outer_box_info_->card_count;
        correct_end_iccid_   = target_iccid_ + outer_box_info_->card_count * 2 - 1;
    } else {
        correct_start_iccid_ = target_iccid_ + 1;
        correct_end_iccid_   = target_iccid_ + outer_box_info_->card_count;
    }

    qDebug() << "correct_start_iccid_:" << correct_start_iccid_;
    qDebug() << "correct_end_iccid_:" << correct_end_iccid_;

    return true;
}

bool OuterBox::dataConvert(QString &error) {
    int start_check_num = outer_box_info_->start_check_num - 1;
    int end_check_num   = outer_box_info_->end_check_num;

    // 数据转换
    start_iccid_  = outer_box_info_->start_iccid.mid(start_check_num, end_check_num - start_check_num).toLongLong();
    end_iccid_    = outer_box_info_->end_iccid.mid(start_check_num, end_check_num - start_check_num).toLongLong();
    target_iccid_ = outer_box_info_->target_iccid.mid(start_check_num, end_check_num - start_check_num).toLongLong();

    qDebug() << "start_iccid_:" << start_iccid_;
    qDebug() << "end_iccid_:" << end_iccid_;
    qDebug() << "target_iccid_:" << target_iccid_;

    return true;
}