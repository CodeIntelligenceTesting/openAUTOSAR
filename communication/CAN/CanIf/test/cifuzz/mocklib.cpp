#include <vector>
#include <cstdint>
#include <iostream>
#include <iomanip>

#include <fuzzer/FuzzedDataProvider.h>


extern "C" {
    #include "Can.h"
    #include "Can_Cfg.h"
    #include "Com.h"
    #include "Com_Types.h"
    #include "Det.h"
}


static FuzzedDataProvider *fuzzed_data;

// Wrapper function for FuzzedDataProvider.h
// Writes |num_bytes| of input data to the given destination pointer. If there
// is not enough data left, writes all remaining bytes and fills the rest with zeros.
// Return value is the number of bytes written.
void ConsumeDataAndFillRestWithZeros(void *destination, size_t num_bytes, FuzzedDataProvider *fuzzed_data) {
  if (destination != nullptr) {
    size_t num_bytes_with_fuzzed_data = fuzzed_data->ConsumeData(destination, num_bytes);
    if (num_bytes > num_bytes_with_fuzzed_data) {
      size_t num_bytes_with_zeros = num_bytes - num_bytes_with_fuzzed_data;
      std::memset((char*)destination+num_bytes_with_fuzzed_data, 0, num_bytes_with_zeros);
    }
  }
}

// This function received the fuzzer generated data from the fuzz target.
// It needs to be called at the beginning of the LLVMFuzzerTestOneInput function.
void mocklib_set_data(void *fuzzed_data_provider) {
    fuzzed_data = (FuzzedDataProvider *) fuzzed_data_provider;
}

//extern "C" {
//const Can_ControllerConfigType CanControllerConfigData[1];
//const Can_ConfigSetType CanConfigSetData;
//
//void Can_InitController(uint8 controller, const Can_ControllerConfigType *config) {}
//
//Can_ReturnType Can_SetControllerMode(uint8 Controller, Can_StateTransitionType transition) {
//    return CAN_OK;
//}
//
//Can_ReturnType Can_Write(Can_Arc_HTHType hth, Can_PduType *pduInfo) {
//    return CAN_OK;
//}
//
//void Com_RxIndication(PduIdType ComRxPduId, const PduInfoType *PduInfoPtr) {}
//
//void Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {}
//
//}