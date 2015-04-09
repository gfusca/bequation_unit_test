#include "expressiontest.h"

int main(int argc, char** argv) {
   ExpressionTest sts;
   Test::TextOutput output(Test::TextOutput::Verbose);
   return sts.run(output, false);
}
