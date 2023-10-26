#include <QString>

QString add(QString a, QString b) {
    int     len_a = a.length();
    int     len_b = b.length();
    int     len   = len_a > len_b ? len_a : len_b;
    QString result;
    int     carry = 0;
    for (int i = 0; i < len; i++) {
        int temp = 0;
        if (i < len_a) {
            temp += a[len_a - i - 1].toLatin1() - '0';
        }
        if (i < len_b) {
            temp += b[len_b - i - 1].toLatin1() - '0';
        }
        temp += carry;
        carry  = temp / 10;
        temp   = temp % 10;
        result = QString::number(temp) + result;
    }
    if (carry != 0) {
        result = QString::number(carry) + result;
    }
    return result;
}

int main() {
    QString a = "1234567890123456789000000000000000000";
    QString b = "12345678901234567890000000000000000000";
    QString c = add(a, b);
    printf("%s\n", c.toStdString().c_str());
    return 0;
}