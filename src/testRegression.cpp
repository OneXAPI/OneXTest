#include "../include/testRegression.hpp"

static void printResult(testDataType& td, bool testResult){
    std::cout << "[" << td.testCaseId << "] [" << td.testSubject << "] - ";
    if(testResult){
        std::cout << "Pass" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
    std::cout << "Expected Result : " << td.expectedResult << std::endl;
    std::cout << "Actual Result : " << td.actualResult << std::endl << std::endl;
}

void regression(){
    uint64_t pass = 0;
    uint64_t fail = 0;
    bool result;
    testDataType td;

    /* OneXAPI */
    result = TC_OneXAPI_1_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_1_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_1_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_1_4(td);
    result?(pass++):(fail++);
    printResult(td, result);

    /* UpbitSpot */
    result = TC_UpbitSpot_1_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_1_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_1_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_1_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_1_5(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_1_6(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_1_7(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_2_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_2_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_2_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_2_4(td);
    result?(pass++):(fail++);
    printResult(td, result);

    std::cout << "Test Executed : " << pass+fail << "   Pass : " << pass << "   Fail : " << fail << std::endl;
}