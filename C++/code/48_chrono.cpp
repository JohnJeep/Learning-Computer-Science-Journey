/*
 * @Author: your name
 * @Date: 2020-12-10 11:48:06
 * @LastEditTime: 2020-12-11 14:54:16
 * @LastEditors: Please set LastEditors
 * @Description: 

 * @FilePath: \Learning-Computer-Journey\test.cpp
 */
#include <iostream>
#include <ratio>
#include <chrono>

// time_point有一个函数time_from_eproch()用来获得1970年1月1日到time_point时间经过的duration。
// 举个例子，如果timepoint以天为单位，函数返回的duration就以天为单位。
// 由于各种time_point表示方式不同，chrono也提供了相应的转换函数 time_point_cast。

int main()
{
    using namespace std::chrono;

    typedef duration<int, std::ratio<60 * 60 * 24>> days_type;

    time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());

    std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

    return 0;
}