#ifndef __CSV_CSV_FORMAT_H__
#define __CSV_CSV_FORMAT_H__

#include "../imu/ImuData.h"

namespace csv {

class CsvFormater {
public:
    explicit CsvFormater();
    bool toCsv(const imu::ImuData& imuData, const char* format, char result[]);
private:
    bool createTimeStr(long timestamp);
    bool createAccStr(const float* acc);
    bool createGyroStr(const float* gyro);
    bool createQuatStr(const float* quat);
    const char* timeChar = "t";
    const char* accChar = "a";
    const char* gyroChar = "g";
    const char* quatChar = "q";
    const char* timeAccStr = "ta";
    const char* timeGyroStr = "tg";
    const char* timeQuatStr = "tq";
    const char* timeAccGyroQuatStr = "tagq";
    char timeBuf[8] = {0};
    char accBuf[32] = {0};
    char gyroBuf[32] = {0};
    char quatBuf[32] = {0};
}; // CsvFormat

} // csv

#endif // __CSV_CSV_FORMAT_H__
