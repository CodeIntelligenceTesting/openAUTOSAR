#include <assert.h>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

extern "C" {
#include "Std_Types.h"
#include "Crc.h"
}


FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
  // FuzzedDataProvider provides convenience methods that turn the raw fuzzer
  // data into common types. Use it to generate parameters for the function you
  // want to fuzz:

  FuzzedDataProvider fuzzed_data(data, size);
  uint32 startVal = fuzzed_data.ConsumeIntegral<uint32>();
  std::vector<uint8> data_input = fuzzed_data.ConsumeRemainingBytes<uint8>();

  Crc_CalculateCRC32(data_input.data(), data_input.size(), startVal);

  // If you want to know more about writing fuzz tests you can checkout the
  // example projects at https://github.com/CodeIntelligenceTesting/cifuzz/tree/main/examples
  // or have a look at our tutorial:
  // https://github.com/CodeIntelligenceTesting/cifuzz/blob/main/docs/How-To-Write-A-Fuzz-Test.md
}
