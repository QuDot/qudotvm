#ifndef __QUDOT_KRATOSVM_H
#define __QUDOT_KRATOSVM_H

#include <cstddef>
#include <memory>
#include <stack>
#include <string>
#include <vector>

#include "qudot/bytecodes.h"
#include "qudot/gatestackframe.h"
#include "qudot/qudot.h"
#include "qudot/qudotconfig.h"

namespace qudot {
    class KratosVM : public QuDot {
        private:
            int ip;
            int fp;
            char* code;
            std::vector<GateAsmSymbol> const_pool_gates;
            std::stack<GateStackFrame> calls;
            std::shared_ptr<GateAsmSymbol> main_gate;
            unsigned int num_qubits;
            unsigned int ensemble;
            int qudotc_fp;
            int bytecode_length;

            void feynmanProcessor();
            void printQuReg(const QuReg&);

        public:
            KratosVM(const std::string filename, const QuDotConfig& qudot_config);
            virtual ~KratosVM();

            void bohr();
            void getResults();
    };
}

#endif