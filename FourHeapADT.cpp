#include "FourHeapADT.h"

//private

void FourHeapADT::fix_move()
{
    if ((total_min.getHeapSize() - total_max.getHeapSize()) > 1)   {
        total_max.insert(median_min.deleteMin());

    }
    else if ((total_max.getHeapSize() - total_min.getHeapSize()) > 1)  {
        total_min.insert(median_max.deleteMax());
    }
}

//public

void FourHeapADT::CreateEmpty() {
    total_max.init(SIZE);
    median_max.init(SIZE);
    total_min.init(SIZE);
    median_min.init(SIZE);
}
dataType FourHeapADT::deleteMax() {
    dataType max=Max();
    total_max.deleteMax();
    median_min.deleteLeaf(max.getTwin());
    fix_move();
    return max;
}
dataType FourHeapADT::deleteMin() {
    dataType min=Min();
    total_min.deleteMin();
    median_max.deleteLeaf(min.getTwin());
    fix_move();
    return min;
}
void FourHeapADT::insert(int priority, std::string value) {
    /*creates data and twin*/
    dataType data = dataType(priority, value);
    dataType data_twin = data;
    data.setTwin(&data_twin);
    data_twin.setTwin(&data);
    if (data.getPriority() > median().getPriority()) {
        total_max.insert(data);
        median_max.insert(data_twin);//TODO-YARDEN
    }
    else {
        total_min.insert(data);
        median_min.insert(data_twin);//TODO-YARDEN
    }
    fix_move();
}
