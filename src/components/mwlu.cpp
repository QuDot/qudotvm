#include "qudot/components/mwlu.h"

#include <cmath>
#include <vector>

#include "tbb/parallel_for.h"

#include "qudot/common.h"

namespace qudot {

void ManyWorldsLogicUnit::addModN(QuMvN* qumvn, const int val, const int N) {
    addModN(qumvn, val, N, 1, qumvn->getNumQubits());
}

void ManyWorldsLogicUnit::addModN(QuMvN* qumvn, const int val, const int N, const int start_q, const int end_q) {
    int Na = N - val;
    int mod_val = std::pow(2, end_q - start_q + 1) + val - N;

    qumvn->splitAllWorlds();
    
    tbb::parallel_for(size_t(0), size_t(qumvn->size()), [&] (size_t i) {
        QuWorld* quworld = qumvn->getQuWorld(i);
        comparator.compare(quworld, Na, start_q, end_q);
        full_adder.addClassicalInt(quworld, val, start_q, end_q, ONE);
        full_adder.addClassicalInt(quworld, mod_val, start_q, end_q, ZERO);
    });
}

void ManyWorldsLogicUnit::ctrlAddModN(QuMvN* qumvn, const int val, const int N, const int start_q, const int end_q, const std::vector<int>& ctrls) {
    qumvn->splitWorlds(ctrls);
    tbb::parallel_for(size_t(0), size_t(qumvn->size()), [&] (size_t i) {
        QuWorld* quworld = qumvn->getQuWorld(i);
        ctrlAddModN(quworld, val, N, start_q, end_q, ctrls);
    });
}

//**************** PRIVATE METHODS **********************8
void ManyWorldsLogicUnit::addModN(QuWorld* quworld, const int val, const int N, const int start_q, const int end_q) {
    int Na = N - val;
    int mod_val = std::pow(2, end_q - start_q + 1) + val - N;
    comparator.compare(quworld, Na, start_q, end_q);
    full_adder.addClassicalInt(quworld, val, start_q, end_q, ONE);
    full_adder.addClassicalInt(quworld, mod_val, start_q, end_q, ZERO);
}

void ManyWorldsLogicUnit::ctrlAddModN(QuWorld* quworld, const int val, const int N, const int start_q, const int end_q, const std::vector<int>& ctrls) {
    if (quworld->areActive(ctrls, ONE)) {
        addModN(quworld, val, N, start_q, end_q);
    }
}

}