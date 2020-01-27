#include "CsvFormater.h"

namespace csv {
    CsvFormater::CsvFormater() { 
    }

    bool CsvFormater::toCsv(const imu::ImuData& imuData, const char* format, char result[]) {
        int len = strlen(format);
        if (len < 1 || 4 < len) {
            return false;
        }
        if (strstr(format, timeChar) != NULL) {
            createTimeStr(imuData.timestamp);
        }
        if (strstr(format, accChar) != NULL) {
            createAccStr(imuData.acc);
        }
        if (strstr(format, gyroChar) != NULL) {
            createGyroStr(imuData.gyro);
        }
        if (strstr(format, quatChar) != NULL) {
            createQuatStr(imuData.quat);
        }
        if (strcmp(timeChar, format) == 0) {
            sprintf(result, "%s", timeBuf);
        } else if  (strcmp(accChar, format) == 0) {
            sprintf(result, "%s", accBuf);
        } else if  (strcmp(gyroChar, format) == 0) {
            sprintf(result, "%s", gyroBuf);
        } else if  (strcmp(quatChar, format) == 0) {
            sprintf(result, "%s", quatBuf);
        } else if  (strcmp(timeAccStr, format) == 0) {
            sprintf(result, "%s,%s", timeBuf, accBuf);
        } else if  (strcmp(timeGyroStr, format) == 0) {
            sprintf(result, "%s,%s", timeBuf, gyroBuf);
        } else if  (strcmp(timeQuatStr, format) == 0) {
            sprintf(result, "%s,%s", timeBuf, quatBuf);
        } else if  (strcmp(timeAccGyroQuatStr, format) == 0) {
            sprintf(result, "%s,%s,%s,%s", timeBuf, accBuf, gyroBuf, quatBuf);
        } else {
            return false;
        }
        return true;
    }
    bool CsvFormater::createTimeStr(long timestamp) {
        sprintf(timeBuf, "%7ld", timestamp);
        return true;
    }
    bool CsvFormater::createAccStr(const float* acc) {
        sprintf(accBuf, "%9.4f,%9.4f,%9.4f", acc[0], acc[1], acc[2]);
        return true;
    }
    bool CsvFormater::createGyroStr(const float* gyro) {
        sprintf(gyroBuf, "%9.4f,%9.4f,%9.4f", gyro[0], gyro[1], gyro[2]);
        return true;
    }
    bool CsvFormater::createQuatStr(const float* quat) {
        sprintf(quatBuf, "%7.4f,%7.4f,%7.4f,%7.4f", quat[0], quat[1], quat[2], quat[3]);
        return true;
    }
}
