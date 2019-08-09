#ifndef __QUDOT_COMPONENTS_THANOSUNIT_H
#define __QUDOT_COMPONENTS_THANOSUNIT_H

#include "qudot/components/feynmanunit.h"
#include "qudot/quworld.h"

namespace qudot {

    class ThanosUnit {
        private:
            FeynmanUnit feynmanUnit;

        public:
            QuWorld* createWorld(const size_t num_qubits, const size_t world_id, const size_t val);            
    };

}

#endif