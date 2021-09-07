//
// Created by Administrator on 2021/9/7.
//

#ifndef MULTIDIMENSIONALARRAYEXPERIMENTS_TENSOR_HPP
#define MULTIDIMENSIONALARRAYEXPERIMENTS_TENSOR_HPP
#include <cstdlib>
#include <cstdarg>
#include <algorithm>
typedef unsigned long size_o;
namespace Hikaze{
    struct DimInfo{
        size_t* pWidth;
        size_o order;
        DimInfo():pWidth(new size_t[1]), order(1){}
        DimInfo(const DimInfo& info){
            order = info.order;
            pWidth = new size_t[order];
            std::copy(info.pWidth,info.pWidth+order, pWidth);
        }
        explicit DimInfo(size_o _order, ...):pWidth(new size_t[_order]), order(_order){
            va_list paraList;
            va_start(paraList, _order);
            for(int i = 0; i<_order;i++){
                pWidth[i] = va_arg(paraList, size_t);
            }
            va_end(paraList);
        }
        size_t getVolume() const{
            size_t rtn = 1;
            for(int i=0;i<order;i++) {
                rtn = rtn * pWidth[i];
            }
            return rtn;
        }
        ~DimInfo(){delete[] pWidth;}
    };

    class Tensor {
    public:
        Tensor(): pArray(nullptr), dimInfo(){}
        Tensor(const double*, const DimInfo&);
        ~Tensor(){delete pArray;}
        double GetElement(...);
        void SetElement(double,...);
    private:
        double* pArray;
        DimInfo dimInfo;
    };
}
#endif //MULTIDIMENSIONALARRAYEXPERIMENTS_TENSOR_HPP
