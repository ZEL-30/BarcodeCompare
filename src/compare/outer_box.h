#pragma once

#include <QString>

class OuterBox {

  public:
    struct OuterBoxInfo {
        QString start_iccid;     // 外箱起始 ICCID
        QString end_iccid;       // 外箱结束 ICCID
        QString target_iccid;    // 目标 ICCID
        int     start_check_num; // 外箱起始校验位
        int     end_check_num;   // 外箱结束校验位
        int     card_count;      // 卡片数量
    };

    OuterBox();
    ~OuterBox();

    inline void outerBoxInfo(OuterBoxInfo *outer_box_info) { outer_box_info_ = outer_box_info; }

    /// @brief 比对
    /// @param error 传出参数，错误信息
    /// @param is_end 传出参数，是否结束
    bool compare(QString &error, bool &is_end);

  private:
    /// @brief 数据转换
    /// @param error 传出参数，错误信息
    bool dataConvert(QString &error);

  private:
    OuterBoxInfo *outer_box_info_;
    qlonglong     start_iccid_;
    qlonglong     end_iccid_;
    qlonglong     correct_start_iccid_; // 正确起始 ICCID
    qlonglong     correct_end_iccid_;   // 正确结束 ICCID
    qlonglong     target_iccid_;
};