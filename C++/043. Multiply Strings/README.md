# Solution
main1.cpp中采用的是标准的乘法运算过程。runtime 54ms。
main2.cpp中采用的是改进过的乘法过程，依次计算每一位的结果并存储在对应位置的数组中，不考虑进位，最后整合成结果字符串。runtime 10ms。