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
#include "qudot/quworld.h"
#include "qudot/components/feynmanunit.h"

namespace qudot {
    class KratosVM : public QuDot {
        private:
            int ip;
            int fp;
            char* code;
            std::vector<std::shared_ptr<GateAsmSymbol>> const_pool_gates;
            std::stack<GateStackFrame> calls;
            std::shared_ptr<GateAsmSymbol> main_gate;
            unsigned int num_qubits;
            unsigned int ensemble;
            int qudotc_fp;
            int bytecode_length;

            QuWorld* qu_world;
            FeynmanUnit feynmanUnit;

            void feynmanProcessor();
            void printQuReg(const QuReg&);
            void applyGateToQuMvN(QuGate&);
            void applyGateToQuMvN(QuGate&, QuReg*);

        public:
            KratosVM(const std::string filename, const QuDotConfig& qudot_config);
            virtual ~KratosVM();
            KratosVM(const KratosVM&);
            KratosVM & operator=(KratosVM&);

            void bohr() override;
            void getResults(QuFrequency&) override;
            unsigned int getEnsemble() const override;
    };
}

#endif