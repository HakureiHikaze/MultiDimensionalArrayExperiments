//
// Created by Administrator on 2021/9/7.
//

#include "Tensor.hpp"

Hikaze::Tensor::Tensor(const double * pIn, const Hikaze::DimInfo & info) {
    pArray = new double[info.getVolume()];
    dimInfo = info;
}

double Hikaze::Tensor::GetElement(...) {
    size_t index = 0;
    auto* p = new size_t[dimInfo.order];
    va_list paraList;
    va_start(paraList,0);
    for(int i = 0; i<dimInfo.order;i++){
        p[i] = va_arg(paraList,size_t);
    }
    va_end(paraList);
    for(int i = 0; i<dimInfo.order; i++){
        for(int j = i+1; j<dimInfo.order; j++){
        }
    }
    return 0;
}

void Hikaze::Tensor::SetElement(double, ...) {

}
